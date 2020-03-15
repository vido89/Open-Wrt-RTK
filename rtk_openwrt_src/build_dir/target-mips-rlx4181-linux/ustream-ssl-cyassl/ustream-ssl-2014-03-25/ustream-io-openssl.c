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

#include <libubox/ustream.h>

#include "ustream-ssl.h"
#include "ustream-internal.h"

static int
s_ustream_new(BIO *b)
{
	b->init = 1;
	b->num = 0;
	b->ptr = NULL;
	b->flags = 0;
	return 1;
}

static int
s_ustream_free(BIO *b)
{
	if (!b)
		return 0;

	b->ptr = NULL;
	b->init = 0;
	b->flags = 0;
	return 1;
}

static int
s_ustream_read(BIO *b, char *buf, int len)
{
	struct ustream *s;
	char *sbuf;
	int slen;

	if (!buf || len <= 0)
		return 0;

	s = (struct ustream *)b->ptr;
	if (!s)
		return 0;

	sbuf = ustream_get_read_buf(s, &slen);

	BIO_clear_retry_flags(b);
	if (!slen) {
		BIO_set_retry_read(b);
		return -1;
	}

	if (slen > len)
		slen = len;

	memcpy(buf, sbuf, slen);
	ustream_consume(s, slen);

	return slen;
}

static int
s_ustream_write(BIO *b, const char *buf, int len)
{
	struct ustream *s;

	if (!buf || len <= 0)
		return 0;

	s = (struct ustream *)b->ptr;
	if (!s)
		return 0;

	if (s->write_error)
		return len;

	return ustream_write(s, buf, len, false);
}

static int
s_ustream_gets(BIO *b, char *buf, int len)
{
	return -1;
}

static int
s_ustream_puts(BIO *b, const char *str)
{
	return s_ustream_write(b, str, strlen(str));
}

static long s_ustream_ctrl(BIO *b, int cmd, long num, void *ptr)
{
	switch (cmd) {
	case BIO_CTRL_FLUSH:
		return 1;
	default:
		return 0;
	};
}

static BIO_METHOD methods_ustream = {
	100 | BIO_TYPE_SOURCE_SINK,
	"ustream",
	s_ustream_write,
	s_ustream_read,
	s_ustream_puts,
	s_ustream_gets,
	s_ustream_ctrl,
	s_ustream_new,
	s_ustream_free,
	NULL,
};

static BIO *ustream_bio_new(struct ustream *s)
{
	BIO *bio;

	bio = BIO_new(&methods_ustream);
	bio->ptr = s;
	return bio;
}

__hidden void ustream_set_io(struct ustream_ssl_ctx *ctx, void *ssl, struct ustream *conn)
{
	BIO *bio = ustream_bio_new(conn);
	SSL_set_bio(ssl, bio, bio);
}
