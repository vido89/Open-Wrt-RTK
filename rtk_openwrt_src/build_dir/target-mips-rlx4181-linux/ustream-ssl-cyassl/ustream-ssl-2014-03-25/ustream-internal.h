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

#ifndef __USTREAM_BIO_H
#define __USTREAM_BIO_H

#define __hidden __attribute__((visibility("hidden")))

#ifdef HAVE_POLARSSL
#include "ustream-polarssl.h"
#else
#include "ustream-openssl.h"
#endif

enum ssl_conn_status {
	U_SSL_OK = 0,
	U_SSL_PENDING = -1,
	U_SSL_ERROR = -2,
};

void ustream_set_io(struct ustream_ssl_ctx *ctx, void *ssl, struct ustream *s);
struct ustream_ssl_ctx *__ustream_ssl_context_new(bool server);
int __ustream_ssl_add_ca_crt_file(struct ustream_ssl_ctx *ctx, const char *file);
int __ustream_ssl_set_crt_file(struct ustream_ssl_ctx *ctx, const char *file);
int __ustream_ssl_set_key_file(struct ustream_ssl_ctx *ctx, const char *file);
void __ustream_ssl_context_free(struct ustream_ssl_ctx *ctx);
enum ssl_conn_status __ustream_ssl_connect(struct ustream_ssl *us);
int __ustream_ssl_read(struct ustream_ssl *us, char *buf, int len);
int __ustream_ssl_write(struct ustream_ssl *us, const char *buf, int len);

#endif
