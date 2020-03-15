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

#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include <libubox/ustream.h>
#include <libubox/uloop.h>
#include <libubox/usock.h>
#include "ustream-ssl.h"

static struct ustream_ssl_ctx *ctx;

static struct uloop_fd server;
static const char *port = "10000";
static struct client *next_client = NULL;

struct client {
	struct sockaddr_in sin;

	struct ustream_fd s;
	struct ustream_ssl ssl;
	int ctr;

	int state;
};

enum {
	STATE_INITIAL,
	STATE_HEADERS,
	STATE_DONE,
};

static void client_read_cb(struct ustream *s, int bytes)
{
	struct client *cl = container_of(s, struct client, ssl.stream);
	struct ustream_buf *buf = s->r.head;
	char *newline, *str;

	do {
		str = ustream_get_read_buf(s, NULL);
		if (!str)
			break;

		newline = strchr(buf->data, '\n');
		if (!newline)
			break;

		*newline = 0;
		switch (cl->state) {
		case STATE_INITIAL:
			ustream_printf(s, "HTTP/1.1 200 OK\nContent-Type:text/plain\n\n");
			ustream_printf(s, "Got request header: %s\n", str);
			cl->state++;
			break;
		case STATE_HEADERS:
			switch(str[0]) {
			case '\r':
			case '\n':
				s->eof = true;
				ustream_state_change(s);
				cl->state++;
				break;
			default:
				ustream_printf(s, "%s\n", str);
				break;
			}
			break;
		default:
			break;
		}
		ustream_consume(s, newline + 1 - str);
		cl->ctr += newline + 1 - str;
	} while(1);

	if (s->w.data_bytes > 256 && !ustream_read_blocked(s)) {
		fprintf(stderr, "Block read, bytes: %d\n", s->w.data_bytes);
		ustream_set_read_blocked(s, true);
	}
}

static void client_close(struct client *cl)
{
	fprintf(stderr, "Connection closed\n");
	ustream_free(&cl->ssl.stream);
	ustream_free(&cl->s.stream);
	close(cl->s.fd.fd);
	free(cl);
}

static void client_notify_write(struct ustream *s, int bytes)
{
	fprintf(stderr, "Wrote %d bytes, pending: %d\n", bytes, s->w.data_bytes);

	if (s->w.data_bytes < 128 && ustream_read_blocked(s)) {
		fprintf(stderr, "Unblock read\n");
		ustream_set_read_blocked(s, false);
	}
}

static void client_notify_state(struct ustream *s)
{
	struct client *cl = container_of(s, struct client, ssl.stream);

	if (!s->eof)
		return;

	fprintf(stderr, "eof!, pending: %d, total: %d\n", s->w.data_bytes, cl->ctr);
	if (!s->w.data_bytes)
		return client_close(cl);
}

static void client_notify_connected(struct ustream_ssl *ssl)
{
	fprintf(stderr, "SSL connection established\n");
}

static void client_notify_error(struct ustream_ssl *ssl, int error, const char *str)
{
	struct client *cl = container_of(ssl, struct client, ssl);

	fprintf(stderr, "SSL connection error(%d): %s\n", error, str);
	client_close(cl);
}

static void server_cb(struct uloop_fd *fd, unsigned int events)
{
	struct client *cl;
	unsigned int sl = sizeof(struct sockaddr_in);
	int sfd;

	if (!next_client)
		next_client = calloc(1, sizeof(*next_client));

	cl = next_client;
	sfd = accept(server.fd, (struct sockaddr *) &cl->sin, &sl);
	if (sfd < 0) {
		fprintf(stderr, "Accept failed\n");
		return;
	}

	cl->ssl.stream.string_data = true;
	cl->ssl.stream.notify_read = client_read_cb;
	cl->ssl.stream.notify_state = client_notify_state;
	cl->ssl.stream.notify_write = client_notify_write;
	cl->ssl.notify_connected = client_notify_connected;
	cl->ssl.notify_error = client_notify_error;

	ustream_fd_init(&cl->s, sfd);
	ustream_ssl_init(&cl->ssl, &cl->s.stream, ctx, true);
	next_client = NULL;
	fprintf(stderr, "New connection\n");
}

static int run_server(void)
{

	server.cb = server_cb;
	server.fd = usock(USOCK_TCP | USOCK_SERVER | USOCK_IPV4ONLY | USOCK_NUMERIC, "127.0.0.1", port);
	if (server.fd < 0) {
		perror("usock");
		return 1;
	}

	uloop_init();
	uloop_fd_add(&server, ULOOP_READ);
	uloop_run();

	return 0;
}

static int usage(const char *name)
{
	fprintf(stderr, "Usage: %s -p <port>\n", name);
	return 1;
}

int main(int argc, char **argv)
{
	int ch;

	signal(SIGPIPE, SIG_IGN);
	ctx = ustream_ssl_context_new(true);
	ustream_ssl_context_set_crt_file(ctx, "example.crt");
	ustream_ssl_context_set_key_file(ctx, "example.key");

	while ((ch = getopt(argc, argv, "p:")) != -1) {
		switch(ch) {
		case 'p':
			port = optarg;
			break;
		default:
			return usage(argv[0]);
		}
	}

	return run_server();
}
