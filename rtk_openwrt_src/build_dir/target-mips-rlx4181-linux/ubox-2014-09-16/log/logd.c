/*
 * Copyright (C) 2013 John Crispin <blogic@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1
 * as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <unistd.h>
#include <syslog.h>
#include <unistd.h>

#include <linux/types.h>

#include <libubox/uloop.h>
#include <libubox/blobmsg.h>
#include <libubox/list.h>
#include <libubox/ustream.h>
#include <libubus.h>

#include "syslog.h"

int debug = 0;
static struct blob_buf b;
static struct ubus_auto_conn conn;
static LIST_HEAD(clients);

static const struct blobmsg_policy read_policy =
	{ .name = "lines", .type = BLOBMSG_TYPE_INT32 };

static const struct blobmsg_policy write_policy =
	{ .name = "event", .type = BLOBMSG_TYPE_STRING };

struct client {
	struct list_head list;

	struct ustream_fd s;
	int fd;
};

static void
client_close(struct ustream *s)
{
	struct client *cl = container_of(s, struct client, s.stream);

	list_del(&cl->list);
	ustream_free(s);
	close(cl->fd);
	free(cl);
}

static void
client_notify_write(struct ustream *s, int bytes)
{
}

static void client_notify_state(struct ustream *s)
{
	client_close(s);
}

static int
read_log(struct ubus_context *ctx, struct ubus_object *obj,
		struct ubus_request_data *req, const char *method,
		struct blob_attr *msg)
{
	struct client *cl;
	struct blob_attr *tb;
	struct log_head *l;
	int count = 0;
	int fds[2];

	if (msg) {
		blobmsg_parse(&read_policy, 1, &tb, blob_data(msg), blob_len(msg));
		if (tb)
			count = blobmsg_get_u32(tb);
	}

	pipe(fds);
	ubus_request_set_fd(ctx, req, fds[0]);
	cl = calloc(1, sizeof(*cl));
	cl->s.stream.notify_write = client_notify_write;
	cl->s.stream.notify_state = client_notify_state;
	cl->fd = fds[1];
	ustream_fd_init(&cl->s, cl->fd);
	list_add(&cl->list, &clients);
	l = log_list(count, NULL);
	while ((!tb || count) && l) {
		blob_buf_init(&b, 0);
		blobmsg_add_string(&b, "msg", l->data);
		blobmsg_add_u32(&b, "id", l->id);
		blobmsg_add_u32(&b, "priority", l->priority);
		blobmsg_add_u32(&b, "source", l->source);
		blobmsg_add_u64(&b, "time", l->ts.tv_sec * 1000LL);
		l = log_list(count, l);
		if (ustream_write(&cl->s.stream, (void *) b.head, blob_len(b.head) + sizeof(struct blob_attr), false) <= 0)
			break;
	}
	return 0;
}

static int
write_log(struct ubus_context *ctx, struct ubus_object *obj,
		struct ubus_request_data *req, const char *method,
		struct blob_attr *msg)
{
	struct blob_attr *tb;
	char *event;

	if (msg) {
		blobmsg_parse(&write_policy, 1, &tb, blob_data(msg), blob_len(msg));
		if (tb) {
			event = blobmsg_get_string(tb);
			log_add(event, strlen(event) + 1, SOURCE_SYSLOG);
		}
	}

	return 0;
}

static const struct ubus_method log_methods[] = {
	{ .name = "read", .handler = read_log, .policy = &read_policy, .n_policy = 1 },
	{ .name = "write", .handler = write_log, .policy = &write_policy, .n_policy = 1 },
};

static struct ubus_object_type log_object_type =
	UBUS_OBJECT_TYPE("log", log_methods);

static struct ubus_object log_object = {
	.name = "log",
	.type = &log_object_type,
	.methods = log_methods,
	.n_methods = ARRAY_SIZE(log_methods),
};

void
ubus_notify_log(struct log_head *l)
{
	struct client *c;

	if (list_empty(&clients))
		return;

	list_for_each_entry(c, &clients, list) {
		blob_buf_init(&b, 0);
		blobmsg_add_string(&b, "msg", l->data);
		blobmsg_add_u32(&b, "id", l->id);
		blobmsg_add_u32(&b, "priority", l->priority);
		blobmsg_add_u32(&b, "source", l->source);
		blobmsg_add_u64(&b, "time", (((__u64) l->ts.tv_sec) * 1000) + (l->ts.tv_nsec / 1000000));
		ustream_write(&c->s.stream, (void *) b.head, blob_len(b.head) + sizeof(struct blob_attr), false);
	}
}

static void
ubus_connect_handler(struct ubus_context *ctx)
{
	int ret;

	ret = ubus_add_object(ctx, &log_object);
	if (ret) {
		fprintf(stderr, "Failed to add object: %s\n", ubus_strerror(ret));
		exit(1);
	}
	fprintf(stderr, "log: connected to ubus\n");
}

int
main(int argc, char **argv)
{
	int ch, log_size = 16;

	signal(SIGPIPE, SIG_IGN);
	while ((ch = getopt(argc, argv, "S:")) != -1) {
		switch (ch) {
		case 'S':
			log_size = atoi(optarg);
			if (log_size < 1)
				log_size = 16;
			break;
		}
	}
	log_size *= 1024;

	uloop_init();
	log_init(log_size);
	conn.cb = ubus_connect_handler;
	ubus_auto_connect(&conn);
	uloop_run();
	log_shutdown();
	uloop_done();

	return 0;
}
