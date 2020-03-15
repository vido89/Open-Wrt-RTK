/*
 * Copyright (C) 2013 Felix Fietkau <nbd@openwrt.org>
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

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SYSLOG_NAMES
#include <syslog.h>

#include <libubox/ustream.h>
#include <libubox/blobmsg_json.h>
#include <libubox/usock.h>
#include <libubox/uloop.h>
#include "libubus.h"
#include "syslog.h"

enum {
	LOG_STDOUT,
	LOG_FILE,
	LOG_NET,
};

enum {
	LOG_MSG,
	LOG_ID,
	LOG_PRIO,
	LOG_SOURCE,
	LOG_TIME,
	__LOG_MAX
};

static const struct blobmsg_policy log_policy[] = {
	[LOG_MSG] = { .name = "msg", .type = BLOBMSG_TYPE_STRING },
	[LOG_ID] = { .name = "id", .type = BLOBMSG_TYPE_INT32 },
	[LOG_PRIO] = { .name = "priority", .type = BLOBMSG_TYPE_INT32 },
	[LOG_SOURCE] = { .name = "source", .type = BLOBMSG_TYPE_INT32 },
	[LOG_TIME] = { .name = "time", .type = BLOBMSG_TYPE_INT64 },
};

static struct uloop_timeout retry;
static struct uloop_fd sender;
static const char *log_file, *log_ip, *log_port, *log_prefix, *pid_file, *hostname;
static int log_type = LOG_STDOUT;
static int log_size, log_udp, log_follow = 0;

static const char* getcodetext(int value, CODE *codetable) {
	CODE *i;

	if (value >= 0)
		for (i = codetable; i->c_val != -1; i++)
			if (i->c_val == value)
				return (i->c_name);
	return "<unknown>";
};

static void log_handle_reconnect(struct uloop_timeout *timeout)
{
	sender.fd = usock((log_udp) ? (USOCK_UDP) : (USOCK_TCP), log_ip, log_port);
	if (sender.fd < 0) {
		fprintf(stderr, "failed to connect: %s\n", strerror(errno));
		uloop_timeout_set(&retry, 1000);
	} else {
		uloop_fd_add(&sender, ULOOP_READ);
		syslog(0, "Logread connected to %s:%s\n", log_ip, log_port);
	}
}

static void log_handle_fd(struct uloop_fd *u, unsigned int events)
{
	if (u->eof) {
		uloop_fd_delete(u);
		close(sender.fd);
		sender.fd = -1;
		uloop_timeout_set(&retry, 1000);
	}
}

static int log_notify(struct blob_attr *msg)
{
	struct blob_attr *tb[__LOG_MAX];
	struct stat s;
	char buf[512];
	uint32_t p;
	char *str;
	time_t t;
	char *c, *m;

	if (sender.fd < 0)
		return 0;

	blobmsg_parse(log_policy, ARRAY_SIZE(log_policy), tb, blob_data(msg), blob_len(msg));
	if (!tb[LOG_ID] || !tb[LOG_PRIO] || !tb[LOG_SOURCE] || !tb[LOG_TIME] || !tb[LOG_MSG])
		return 1;

	if ((log_type == LOG_FILE) && log_size && (!stat(log_file, &s)) && (s.st_size > log_size)) {
		char *old = malloc(strlen(log_file) + 5);

		close(sender.fd);
		if (old) {
			sprintf(old, "%s.old", log_file);
			rename(log_file, old);
			free(old);
		}
		sender.fd = open(log_file, O_CREAT | O_WRONLY | O_APPEND, 0600);
		if (sender.fd < 0) {
			fprintf(stderr, "failed to open %s: %s\n", log_file, strerror(errno));
			exit(-1);
		}
	}

	m = blobmsg_get_string(tb[LOG_MSG]);
	t = blobmsg_get_u64(tb[LOG_TIME]) / 1000;
	c = ctime(&t);
	p = blobmsg_get_u32(tb[LOG_PRIO]);
	c[strlen(c) - 1] = '\0';
	str = blobmsg_format_json(msg, true);
	if (log_type == LOG_NET) {
		int err;

		snprintf(buf, sizeof(buf), "<%u>", p);
		strncat(buf, c + 4, 16);
		if (hostname) {
			strncat(buf, hostname, sizeof(buf));
			strncat(buf, " ", sizeof(buf));
		}
		if (log_prefix) {
			strncat(buf, log_prefix, sizeof(buf));
			strncat(buf, ": ", sizeof(buf));
		}
		if (blobmsg_get_u32(tb[LOG_SOURCE]) == SOURCE_KLOG)
			strncat(buf, "kernel: ", sizeof(buf));
		strncat(buf, m, sizeof(buf));
		if (log_udp)
			err = write(sender.fd, buf, strlen(buf));
		else
			err = send(sender.fd, buf, strlen(buf), 0);

		if (err < 0) {
			syslog(0, "failed to send log data to %s:%s via %s\n",
				log_ip, log_port, (log_udp) ? ("udp") : ("tcp"));
			uloop_fd_delete(&sender);
			close(sender.fd);
			sender.fd = -1;
			uloop_timeout_set(&retry, 1000);
		}
	} else {
		snprintf(buf, sizeof(buf), "%s %s.%s%s %s\n",
			c, getcodetext(LOG_FAC(p) << 3, facilitynames), getcodetext(LOG_PRI(p), prioritynames),
			(blobmsg_get_u32(tb[LOG_SOURCE])) ? ("") : (" kernel:"), m);
		write(sender.fd, buf, strlen(buf));
	}

	free(str);
	if (log_type == LOG_FILE)
		fsync(sender.fd);

	return 0;
}

static int usage(const char *prog)
{
	fprintf(stderr, "Usage: %s [options]\n"
		"Options:\n"
		"    -s <path>		Path to ubus socket\n"
		"    -l	<count>		Got only the last 'count' messages\n"
		"    -r	<server> <port>	Stream message to a server\n"
		"    -F	<file>		Log file\n"
		"    -S	<bytes>		Log size\n"
		"    -p	<file>		PID file\n"
		"    -h	<hostname>	Add hostname to the message\n"
		"    -P	<prefix>	Prefix custom text to streamed messages\n"
		"    -f			Follow log messages\n"
		"    -u			Use UDP as the protocol\n"
		"\n", prog);
	return 1;
}

static void logread_fd_data_cb(struct ustream *s, int bytes)
{
	while (true) {
		int len;
		struct blob_attr *a;

		a = (void*) ustream_get_read_buf(s, &len);
		if (len < sizeof(*a) || len < blob_len(a) + sizeof(*a))
			break;
		log_notify(a);
		ustream_consume(s, blob_len(a) + sizeof(*a));
	}
	if (!log_follow)
		uloop_end();
}

static void logread_fd_cb(struct ubus_request *req, int fd)
{
	static struct ustream_fd test_fd;

	test_fd.stream.notify_read = logread_fd_data_cb;
	ustream_fd_init(&test_fd, fd);
}

static void logread_complete_cb(struct ubus_request *req, int ret)
{
}

int main(int argc, char **argv)
{
	static struct ubus_request req;
	struct ubus_context *ctx;
	uint32_t id;
	const char *ubus_socket = NULL;
	int ch, ret, lines = 0;
	static struct blob_buf b;
	int tries = 5;

	signal(SIGPIPE, SIG_IGN);

	while ((ch = getopt(argc, argv, "ufcs:l:r:F:p:S:P:h:")) != -1) {
		switch (ch) {
		case 'u':
			log_udp = 1;
			break;
		case 's':
			ubus_socket = optarg;
			break;
		case 'r':
			log_ip = optarg++;
			log_port = argv[optind++];
			break;
		case 'F':
			log_file = optarg;
			break;
		case 'p':
			pid_file = optarg;
			break;
		case 'P':
			log_prefix = optarg;
			break;
		case 'f':
			log_follow = 1;
			break;
		case 'l':
			lines = atoi(optarg);
			break;
		case 'S':
			log_size = atoi(optarg);
			if (log_size < 1)
				log_size = 1;
			log_size *= 1024;
			break;
		case 'h':
			hostname = optarg;
			break;
		default:
			return usage(*argv);
		}
	}
	uloop_init();

	ctx = ubus_connect(ubus_socket);
	if (!ctx) {
		fprintf(stderr, "Failed to connect to ubus\n");
		return -1;
	}
	ubus_add_uloop(ctx);

	/* ugly ugly ugly ... we need a real reconnect logic */
	do {
		ret = ubus_lookup_id(ctx, "log", &id);
		if (ret) {
			fprintf(stderr, "Failed to find log object: %s\n", ubus_strerror(ret));
			sleep(1);
			continue;
		}

		blob_buf_init(&b, 0);
		if (lines)
			blobmsg_add_u32(&b, "lines", lines);
		else if (log_follow)
			blobmsg_add_u32(&b, "lines", 0);
		if (log_follow) {
			if (pid_file) {
				FILE *fp = fopen(pid_file, "w+");
				if (fp) {
					fprintf(fp, "%d", getpid());
					fclose(fp);
				}
			}
		}

		if (log_ip && log_port) {
			openlog("logread", LOG_PID, LOG_DAEMON);
			log_type = LOG_NET;
			sender.cb = log_handle_fd;
			retry.cb = log_handle_reconnect;
			uloop_timeout_set(&retry, 1000);
		} else if (log_file) {
			log_type = LOG_FILE;
			sender.fd = open(log_file, O_CREAT | O_WRONLY| O_APPEND, 0600);
			if (sender.fd < 0) {
				fprintf(stderr, "failed to open %s: %s\n", log_file, strerror(errno));
				exit(-1);
			}
		} else {
			sender.fd = STDOUT_FILENO;
		}

		ubus_invoke_async(ctx, id, "read", b.head, &req);
		req.fd_cb = logread_fd_cb;
		req.complete_cb = logread_complete_cb;
		ubus_complete_request_async(ctx, &req);

		uloop_run();
		ubus_free(ctx);
		uloop_done();

	} while (ret && tries--);

	return ret;
}
