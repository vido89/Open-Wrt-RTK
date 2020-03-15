/*
 * ustream-ssl - library for SSL over ustream
 *
 * Copyright (C) 2012 Felix Fietkau <nbd@openwrt.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <string.h>
#include <ctype.h>
#include <openssl/x509v3.h>
#include "ustream-ssl.h"
#include "ustream-internal.h"

__hidden struct ustream_ssl_ctx *
__ustream_ssl_context_new(bool server)
{
	static bool _init = false;
	const void *m;
	SSL_CTX *c;

	if (!_init) {
		SSL_load_error_strings();
		SSL_library_init();
		_init = true;
	}

#ifdef CYASSL_OPENSSL_H_
	if (server)
		m = SSLv23_server_method();
	else
		m = SSLv23_client_method();
#else
	if (server)
		m = TLSv1_server_method();
	else
		m = TLSv1_client_method();
#endif

	c = SSL_CTX_new((void *) m);
	if (!c)
		return NULL;

	SSL_CTX_set_verify(c, SSL_VERIFY_NONE, NULL);

	return (void *) c;
}

__hidden int __ustream_ssl_add_ca_crt_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

	ret = SSL_CTX_load_verify_locations((void *) ctx, file, NULL);
	if (ret < 1)
		return -1;

	return 0;
}

__hidden int __ustream_ssl_set_crt_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

	ret = SSL_CTX_use_certificate_chain_file((void *) ctx, file);
	if (ret < 1)
		ret = SSL_CTX_use_certificate_file((void *) ctx, file, SSL_FILETYPE_ASN1);

	if (ret < 1)
		return -1;

	return 0;
}

__hidden int __ustream_ssl_set_key_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

	ret = SSL_CTX_use_PrivateKey_file((void *) ctx, file, SSL_FILETYPE_PEM);
	if (ret < 1)
		ret = SSL_CTX_use_PrivateKey_file((void *) ctx, file, SSL_FILETYPE_ASN1);

	if (ret < 1)
		return -1;

	return 0;
}

__hidden void __ustream_ssl_context_free(struct ustream_ssl_ctx *ctx)
{
	SSL_CTX_free((void *) ctx);
}

static void ustream_ssl_error(struct ustream_ssl *us, int ret)
{
	us->error = ret;
	uloop_timeout_set(&us->error_timer, 0);
}

#ifndef CYASSL_OPENSSL_H_

static bool host_pattern_match(const unsigned char *pattern, const char *cn)
{
	char c;

	for (; (c = tolower(*pattern++)) != 0; cn++) {
		if (c != '*') {
			if (c != *cn)
				return false;
			continue;
		}

		do {
			c = tolower(*pattern++);
		} while (c == '*');

		while (*cn) {
			if (c == tolower(*cn) &&
			    host_pattern_match(pattern, cn))
				return true;
			if (*cn == '.')
				return false;
			cn++;
		}

		return !c;
	}
	return !*cn;
}

static bool host_pattern_match_asn1(ASN1_STRING *asn1, const char *cn)
{
	unsigned char *pattern;
	bool ret = false;

	if (ASN1_STRING_to_UTF8(&pattern, asn1) < 0)
		return false;

	if (!pattern)
		return false;

	if (strlen((char *) pattern) == ASN1_STRING_length(asn1))
		ret = host_pattern_match(pattern, cn);

	OPENSSL_free(pattern);

	return ret;
}

static bool ustream_ssl_verify_cn_alt(struct ustream_ssl *us, X509 *cert)
{
	GENERAL_NAMES *alt_names;
	int i, n_alt;

	alt_names = X509_get_ext_d2i (cert, NID_subject_alt_name, NULL, NULL);
	if (!alt_names)
		return false;

	n_alt = sk_GENERAL_NAME_num(alt_names);
	for (i = 0; i < n_alt; i++) {
		const GENERAL_NAME *name = sk_GENERAL_NAME_value(alt_names, i);

		if (!name)
			continue;

		if (name->type != GEN_DNS)
			continue;

		if (host_pattern_match_asn1(name->d.dNSName, us->peer_cn))
			return true;
	}

	return false;
}

static bool ustream_ssl_verify_cn(struct ustream_ssl *us, X509 *cert)
{
	ASN1_STRING *astr;
	X509_NAME *xname;
	int i, last;

	if (!us->peer_cn)
		return false;

	if (ustream_ssl_verify_cn_alt(us, cert))
		return true;

	xname = X509_get_subject_name(cert);

	last = -1;
	while (1) {
		i = X509_NAME_get_index_by_NID(xname, NID_commonName, last);
		if (i < 0)
			break;

		last = i;
	}

	if (last < 0)
		return false;

	astr = X509_NAME_ENTRY_get_data(X509_NAME_get_entry(xname, last));

	return host_pattern_match_asn1(astr, us->peer_cn);
}


static void ustream_ssl_verify_cert(struct ustream_ssl *us)
{
	void *ssl = us->ssl;
	X509 *cert;
	int res;

	cert = SSL_get_peer_certificate(ssl);
	if (!cert)
		return;

	res = SSL_get_verify_result(ssl);
	if (res != X509_V_OK) {
		if (us->notify_verify_error)
			us->notify_verify_error(us, res, X509_verify_cert_error_string(res));
		return;
	}

	us->valid_cert = true;
	us->valid_cn = ustream_ssl_verify_cn(us, cert);
}

#endif

__hidden enum ssl_conn_status __ustream_ssl_connect(struct ustream_ssl *us)
{
	void *ssl = us->ssl;
	int r;

	if (us->server)
		r = SSL_accept(ssl);
	else
		r = SSL_connect(ssl);

	if (r == 1) {
#ifndef CYASSL_OPENSSL_H_
		ustream_ssl_verify_cert(us);
#endif
		return U_SSL_OK;
	}

	r = SSL_get_error(ssl, r);
	if (r == SSL_ERROR_WANT_READ || r == SSL_ERROR_WANT_WRITE)
		return U_SSL_PENDING;

	ustream_ssl_error(us, r);
	return U_SSL_ERROR;
}

__hidden int __ustream_ssl_write(struct ustream_ssl *us, const char *buf, int len)
{
	void *ssl = us->ssl;
	int ret = SSL_write(ssl, buf, len);

	if (ret < 0) {
		int err = SSL_get_error(ssl, ret);
		if (err == SSL_ERROR_WANT_WRITE)
			return 0;

		ustream_ssl_error(us, err);
		return -1;
	}

	return ret;
}

__hidden int __ustream_ssl_read(struct ustream_ssl *us, char *buf, int len)
{
	int ret = SSL_read(us->ssl, buf, len);

	if (ret < 0) {
		ret = SSL_get_error(us->ssl, ret);
		if (ret == SSL_ERROR_WANT_READ)
			return U_SSL_PENDING;

		ustream_ssl_error(us, ret);
		return U_SSL_ERROR;
	}

	return ret;
}

