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

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <libubox/ustream.h>

#include "ustream-ssl.h"
#include "ustream-internal.h"

static void ustream_ssl_error_cb(struct uloop_timeout *t)
{
	struct ustream_ssl *us = container_of(t, struct ustream_ssl, error_timer);
	static char buffer[128];
	int error = us->error;

	if (us->notify_error)
		us->notify_error(us, error, __ustream_ssl_strerror(us->error, buffer, sizeof(buffer)));
}

static void ustream_ssl_check_conn(struct ustream_ssl *us)
{
	if (us->connected || us->error)
		return;

	if (__ustream_ssl_connect(us) == U_SSL_OK) {
		us->connected = true;
		if (us->notify_connected)
			us->notify_connected(us);
		ustream_write_pending(&us->stream);
	}
}

static bool __ustream_ssl_poll(struct ustream *s)
{
	struct ustream_ssl *us = container_of(s->next, struct ustream_ssl, stream);
	char *buf;
	int len, ret;
	bool more = false;

	ustream_ssl_check_conn(us);
	if (!us->connected || us->error)
		return false;

	do {
		buf = ustream_reserve(&us->stream, 1, &len);
		if (!len)
			break;

		ret = __ustream_ssl_read(us, buf, len);
		switch (ret) {
		case U_SSL_PENDING:
			return more;
		case U_SSL_ERROR:
			return false;
		case 0:
			us->stream.eof = true;
			ustream_state_change(&us->stream);
			return false;
		default:
			ustream_fill_read(&us->stream, ret);
			more = true;
			continue;
		}
	} while (1);

	return more;
}

static void ustream_ssl_notify_read(struct ustream *s, int bytes)
{
	__ustream_ssl_poll(s);
}

static void ustream_ssl_notify_write(struct ustream *s, int bytes)
{
	struct ustream_ssl *us = container_of(s->next, struct ustream_ssl, stream);

	ustream_ssl_check_conn(us);
	ustream_write_pending(s->next);
}

static void ustream_ssl_notify_state(struct ustream *s)
{
	s->next->write_error = true;
	ustream_state_change(s->next);
}

static int ustream_ssl_write(struct ustream *s, const char *buf, int len, bool more)
{
	struct ustream_ssl *us = container_of(s, struct ustream_ssl, stream);

	if (!us->connected || us->error)
		return 0;

	if (us->conn->w.data_bytes)
		return 0;

	return __ustream_ssl_write(us, buf, len);
}

static void ustream_ssl_set_read_blocked(struct ustream *s)
{
	struct ustream_ssl *us = container_of(s, struct ustream_ssl, stream);

	ustream_set_read_blocked(us->conn, !!s->read_blocked);
}

static void ustream_ssl_free(struct ustream *s)
{
	struct ustream_ssl *us = container_of(s, struct ustream_ssl, stream);

	if (us->conn) {
		us->conn->next = NULL;
		us->conn->notify_read = NULL;
		us->conn->notify_write = NULL;
		us->conn->notify_state = NULL;
	}

	uloop_timeout_cancel(&us->error_timer);
	__ustream_ssl_session_free(us->ssl);
	free(us->peer_cn);

	us->ctx = NULL;
	us->ssl = NULL;
	us->conn = NULL;
	us->peer_cn = NULL;
	us->connected = false;
	us->error = false;
	us->valid_cert = false;
	us->valid_cn = false;
}

static bool ustream_ssl_poll(struct ustream *s)
{
	struct ustream_ssl *us = container_of(s, struct ustream_ssl, stream);
	bool fd_poll;

	fd_poll = ustream_poll(us->conn);
	return __ustream_ssl_poll(s) || fd_poll;
}

static void ustream_ssl_stream_init(struct ustream_ssl *us)
{
	struct ustream *conn = us->conn;
	struct ustream *s = &us->stream;

	conn->notify_read = ustream_ssl_notify_read;
	conn->notify_write = ustream_ssl_notify_write;
	conn->notify_state = ustream_ssl_notify_state;

	s->free = ustream_ssl_free;
	s->write = ustream_ssl_write;
	s->poll = ustream_ssl_poll;
	s->set_read_blocked = ustream_ssl_set_read_blocked;
	ustream_init_defaults(s);
}

static int _ustream_ssl_init(struct ustream_ssl *us, struct ustream *conn, struct ustream_ssl_ctx *ctx, bool server)
{
	us->error_timer.cb = ustream_ssl_error_cb;
	us->server = server;
	us->conn = conn;
	us->ctx = ctx;

	us->ssl = __ustream_ssl_session_new(us->ctx);
	if (!us->ssl)
		return -ENOMEM;

	conn->next = &us->stream;
	ustream_set_io(ctx, us->ssl, conn);
	ustream_ssl_stream_init(us);
	ustream_ssl_check_conn(us);

	return 0;
}

static int _ustream_ssl_set_peer_cn(struct ustream_ssl *us, const char *name)
{
	us->peer_cn = strdup(name);
	__ustream_ssl_update_peer_cn(us);

	return 0;
}

const struct ustream_ssl_ops ustream_ssl_ops = {
	.context_new = __ustream_ssl_context_new,
	.context_set_crt_file = __ustream_ssl_set_crt_file,
	.context_set_key_file = __ustream_ssl_set_key_file,
	.context_add_ca_crt_file = __ustream_ssl_add_ca_crt_file,
	.context_free = __ustream_ssl_context_free,
	.init = _ustream_ssl_init,
	.set_peer_cn = _ustream_ssl_set_peer_cn,
};
