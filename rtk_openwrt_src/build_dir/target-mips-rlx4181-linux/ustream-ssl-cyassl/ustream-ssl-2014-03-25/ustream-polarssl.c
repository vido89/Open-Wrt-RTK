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

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "ustream-ssl.h"
#include "ustream-internal.h"

static int urandom_fd = -1;

static int s_ustream_read(void *ctx, unsigned char *buf, size_t len)
{
	struct ustream *s = ctx;
	char *sbuf;
	int slen;

	if (s->eof)
		return 0;

	sbuf = ustream_get_read_buf(s, &slen);
	if (slen > len)
		slen = len;

	if (!slen)
		return POLARSSL_ERR_NET_WANT_READ;

	memcpy(buf, sbuf, slen);
	ustream_consume(s, slen);

	return slen;
}

static int s_ustream_write(void *ctx, const unsigned char *buf, size_t len)
{
	struct ustream *s = ctx;
	int ret;

	ret = ustream_write(s, (const char *) buf, len, false);
	if (ret < 0 || s->write_error)
		return POLARSSL_ERR_NET_SEND_FAILED;

	return ret;
}

__hidden void ustream_set_io(struct ustream_ssl_ctx *ctx, void *ssl, struct ustream *conn)
{
	ssl_set_bio(ssl, s_ustream_read, conn, s_ustream_write, conn);
}

static bool urandom_init(void)
{
	if (urandom_fd > -1)
		return true;

	urandom_fd = open("/dev/urandom", O_RDONLY);
	if (urandom_fd < 0)
		return false;

	return true;
}

static int _urandom(void *ctx, unsigned char *out, size_t len)
{
	read(urandom_fd, out, len);
	return 0;
}

__hidden struct ustream_ssl_ctx *
__ustream_ssl_context_new(bool server)
{
	struct ustream_ssl_ctx *ctx;

	if (!urandom_init())
		return NULL;

	ctx = calloc(1, sizeof(*ctx));
	if (!ctx)
		return NULL;

	ctx->server = server;
#ifdef USE_VERSION_1_3
	pk_init(&ctx->key);
#else
	rsa_init(&ctx->key, RSA_PKCS_V15, 0);
#endif

	return ctx;
}

__hidden int __ustream_ssl_add_ca_crt_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

#ifdef USE_VERSION_1_3
	ret = x509_crt_parse_file(&ctx->ca_cert, file);
#else
	ret = x509parse_crtfile(&ctx->ca_cert, file);
#endif
	if (ret)
		return -1;

	return 0;
}

__hidden int __ustream_ssl_set_crt_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

#ifdef USE_VERSION_1_3
	ret = x509_crt_parse_file(&ctx->cert, file);
#else
	ret = x509parse_crtfile(&ctx->cert, file);
#endif
	if (ret)
		return -1;

	return 0;
}

__hidden int __ustream_ssl_set_key_file(struct ustream_ssl_ctx *ctx, const char *file)
{
	int ret;

#ifdef USE_VERSION_1_3
	ret = pk_parse_keyfile(&ctx->key, file, NULL);
#else
	ret = x509parse_keyfile(&ctx->key, file, NULL);
#endif
	if (ret)
		return -1;

	return 0;
}

__hidden void __ustream_ssl_context_free(struct ustream_ssl_ctx *ctx)
{
#ifdef USE_VERSION_1_3
	pk_free(&ctx->key);
	x509_crt_free(&ctx->cert);
#else
	rsa_free(&ctx->key);
	x509_free(&ctx->cert);
#endif
	free(ctx);
}

static void ustream_ssl_error(struct ustream_ssl *us, int ret)
{
	us->error = ret;
	uloop_timeout_set(&us->error_timer, 0);
}

static bool ssl_do_wait(int ret)
{
	switch(ret) {
	case POLARSSL_ERR_NET_WANT_READ:
	case POLARSSL_ERR_NET_WANT_WRITE:
		return true;
	default:
		return false;
	}
}

static void ustream_ssl_verify_cert(struct ustream_ssl *us)
{
	void *ssl = us->ssl;
	const char *msg = NULL;
	bool cn_mismatch;
	int r;

	r = ssl_get_verify_result(ssl);
	cn_mismatch = r & BADCERT_CN_MISMATCH;
	r &= ~BADCERT_CN_MISMATCH;

	if (r & BADCERT_EXPIRED)
		msg = "certificate has expired";
	else if (r & BADCERT_REVOKED)
		msg = "certificate has been revoked";
	else if (r & BADCERT_NOT_TRUSTED)
		msg = "certificate is self-signed or not signed by a trusted CA";
	else
		msg = "unknown error";

	if (r) {
		if (us->notify_verify_error)
			us->notify_verify_error(us, r, msg);
		return;
	}

	if (!cn_mismatch)
		us->valid_cn = true;
}

__hidden enum ssl_conn_status __ustream_ssl_connect(struct ustream_ssl *us)
{
	void *ssl = us->ssl;
	int r;

	r = ssl_handshake(ssl);
	if (r == 0) {
		ustream_ssl_verify_cert(us);
		return U_SSL_OK;
	}

	if (ssl_do_wait(r))
		return U_SSL_PENDING;

	ustream_ssl_error(us, r);
	return U_SSL_ERROR;
}

__hidden int __ustream_ssl_write(struct ustream_ssl *us, const char *buf, int len)
{
	void *ssl = us->ssl;
	int ret = ssl_write(ssl, (const unsigned char *) buf, len);

	if (ret < 0) {
		if (ssl_do_wait(ret))
			return 0;

		ustream_ssl_error(us, ret);
		return -1;
	}

	return ret;
}

__hidden int __ustream_ssl_read(struct ustream_ssl *us, char *buf, int len)
{
	int ret = ssl_read(us->ssl, (unsigned char *) buf, len);

	if (ret < 0) {
		if (ssl_do_wait(ret))
			return U_SSL_PENDING;

		ustream_ssl_error(us, ret);
		return U_SSL_ERROR;
	}

	return ret;
}

static const int default_ciphersuites[] =
{
#if defined(POLARSSL_AES_C)
#if defined(POLARSSL_SHA2_C)
    TLS_RSA_WITH_AES_256_CBC_SHA256,
#endif /* POLARSSL_SHA2_C */
#if defined(POLARSSL_GCM_C) && defined(POLARSSL_SHA4_C)
    TLS_RSA_WITH_AES_256_GCM_SHA384,
#endif /* POLARSSL_SHA2_C */
    TLS_RSA_WITH_AES_256_CBC_SHA,
#endif
#if defined(POLARSSL_CAMELLIA_C)
#if defined(POLARSSL_SHA2_C)
    TLS_RSA_WITH_CAMELLIA_256_CBC_SHA256,
#endif /* POLARSSL_SHA2_C */
    TLS_RSA_WITH_CAMELLIA_256_CBC_SHA,
#endif
#if defined(POLARSSL_AES_C)
#if defined(POLARSSL_SHA2_C)
    TLS_RSA_WITH_AES_128_CBC_SHA256,
#endif /* POLARSSL_SHA2_C */
#if defined(POLARSSL_GCM_C) && defined(POLARSSL_SHA2_C)
    TLS_RSA_WITH_AES_128_GCM_SHA256,
#endif /* POLARSSL_SHA2_C */
    TLS_RSA_WITH_AES_128_CBC_SHA,
#endif
#if defined(POLARSSL_CAMELLIA_C)
#if defined(POLARSSL_SHA2_C)
    TLS_RSA_WITH_CAMELLIA_128_CBC_SHA256,
#endif /* POLARSSL_SHA2_C */
    TLS_RSA_WITH_CAMELLIA_128_CBC_SHA,
#endif
#if defined(POLARSSL_DES_C)
    TLS_RSA_WITH_3DES_EDE_CBC_SHA,
#endif
#if defined(POLARSSL_ARC4_C)
    TLS_RSA_WITH_RC4_128_SHA,
    TLS_RSA_WITH_RC4_128_MD5,
#endif
    0
};

__hidden void *__ustream_ssl_session_new(struct ustream_ssl_ctx *ctx)
{
	ssl_context *ssl;
	int auth;
	int ep;

	ssl = calloc(1, sizeof(ssl_context));
	if (!ssl)
		return NULL;

	if (ssl_init(ssl)) {
		free(ssl);
		return NULL;
	}

	if (ctx->server) {
		ep = SSL_IS_SERVER;
		auth = SSL_VERIFY_NONE;
	} else {
		ep = SSL_IS_CLIENT;
		auth = SSL_VERIFY_OPTIONAL;
	}

	ssl_set_ciphersuites(ssl, default_ciphersuites);
	ssl_set_endpoint(ssl, ep);
	ssl_set_authmode(ssl, auth);
	ssl_set_rng(ssl, _urandom, NULL);

	if (ctx->server) {
		if (ctx->cert.next)
			ssl_set_ca_chain(ssl, ctx->cert.next, NULL, NULL);
		ssl_set_own_cert(ssl, &ctx->cert, &ctx->key);
	} else {
		ssl_set_ca_chain(ssl, &ctx->cert, NULL, NULL);
	}

	ssl_session_reset(ssl);

	return ssl;
}

__hidden void __ustream_ssl_session_free(void *ssl)
{
	ssl_free(ssl);
	free(ssl);
}

__hidden void __ustream_ssl_update_peer_cn(struct ustream_ssl *us)
{
	struct ustream_ssl_ctx *ctx = us->ctx;

	ssl_set_ca_chain(us->ssl, &ctx->ca_cert, NULL, us->peer_cn);
}
