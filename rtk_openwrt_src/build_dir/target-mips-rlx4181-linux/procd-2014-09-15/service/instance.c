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

#include <sys/resource.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <pwd.h>

#include <libubox/md5.h>

#include "../procd.h"

#include "service.h"
#include "instance.h"


enum {
	INSTANCE_ATTR_COMMAND,
	INSTANCE_ATTR_ENV,
	INSTANCE_ATTR_DATA,
	INSTANCE_ATTR_NETDEV,
	INSTANCE_ATTR_FILE,
	INSTANCE_ATTR_TRIGGER,
	INSTANCE_ATTR_RESPAWN,
	INSTANCE_ATTR_NICE,
	INSTANCE_ATTR_LIMITS,
	INSTANCE_ATTR_WATCH,
	INSTANCE_ATTR_ERROR,
	INSTANCE_ATTR_USER,
	__INSTANCE_ATTR_MAX
};

static const struct blobmsg_policy instance_attr[__INSTANCE_ATTR_MAX] = {
	[INSTANCE_ATTR_COMMAND] = { "command", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_ENV] = { "env", BLOBMSG_TYPE_TABLE },
	[INSTANCE_ATTR_DATA] = { "data", BLOBMSG_TYPE_TABLE },
	[INSTANCE_ATTR_NETDEV] = { "netdev", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_FILE] = { "file", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_TRIGGER] = { "triggers", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_RESPAWN] = { "respawn", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_NICE] = { "nice", BLOBMSG_TYPE_INT32 },
	[INSTANCE_ATTR_LIMITS] = { "limits", BLOBMSG_TYPE_TABLE },
	[INSTANCE_ATTR_WATCH] = { "watch", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_ERROR] = { "error", BLOBMSG_TYPE_ARRAY },
	[INSTANCE_ATTR_USER] = { "user", BLOBMSG_TYPE_STRING },
};

struct instance_netdev {
	struct blobmsg_list_node node;
	int ifindex;
};

struct instance_file {
	struct blobmsg_list_node node;
	uint32_t md5[4];
};

struct rlimit_name {
	const char *name;
	int resource;
};

static const struct rlimit_name rlimit_names[] = {
	{ "as", RLIMIT_AS },
	{ "core", RLIMIT_CORE },
	{ "cpu", RLIMIT_CPU },
	{ "data", RLIMIT_DATA },
	{ "fsize", RLIMIT_FSIZE },
	{ "memlock", RLIMIT_MEMLOCK },
	{ "msgqueue", RLIMIT_MSGQUEUE },
	{ "nice", RLIMIT_NICE },
	{ "nofile", RLIMIT_NOFILE },
	{ "nproc", RLIMIT_NPROC },
	{ "rss", RLIMIT_RSS },
	{ "rtprio", RLIMIT_RTPRIO },
	{ "sigpending", RLIMIT_SIGPENDING },
	{ "stack", RLIMIT_STACK },
	{ NULL, 0 }
};

static void
instance_limits(const char *limit, const char *value)
{
	int i;
	struct rlimit rlim;
	unsigned long cur, max;

	for (i = 0; rlimit_names[i].name != NULL; i++) {
		if (strcmp(rlimit_names[i].name, limit))
			continue;
		if (!strcmp(value, "unlimited")) {
			rlim.rlim_cur = RLIM_INFINITY;
			rlim.rlim_max = RLIM_INFINITY;
		} else {
			if (getrlimit(rlimit_names[i].resource, &rlim))
				return;

			cur = rlim.rlim_cur;
			max = rlim.rlim_max;

			if (sscanf(value, "%lu %lu", &cur, &max) < 1)
				return;

			rlim.rlim_cur = cur;
			rlim.rlim_max = max;
		}

		setrlimit(rlimit_names[i].resource, &rlim);
		return;
	}
}

static void
instance_run(struct service_instance *in)
{
	struct blobmsg_list_node *var;
	struct blob_attr *cur;
	char **argv;
	int argc = 1; /* NULL terminated */
	int rem, fd;

	if (in->nice)
		setpriority(PRIO_PROCESS, 0, in->nice);

	blobmsg_for_each_attr(cur, in->command, rem)
		argc++;

	blobmsg_list_for_each(&in->env, var)
		setenv(blobmsg_name(var->data), blobmsg_data(var->data), 1);

	blobmsg_list_for_each(&in->limits, var)
		instance_limits(blobmsg_name(var->data), blobmsg_data(var->data));

	argv = alloca(sizeof(char *) * argc);
	argc = 0;

	blobmsg_for_each_attr(cur, in->command, rem)
		argv[argc++] = blobmsg_data(cur);

	argv[argc] = NULL;
	fd = open("/dev/null", O_RDWR);
	if (fd > -1) {
		dup2(fd, STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		if (fd > STDERR_FILENO)
			close(fd);
	}
	if (in->uid || in->gid) {
		setuid(in->uid);
		setgid(in->gid);
	}
	execvp(argv[0], argv);
	exit(127);
}

void
instance_start(struct service_instance *in)
{
	int pid;

	if (!avl_is_empty(&in->errors.avl)) {
		LOG("Not starting instance %s::%s, an error was indicated\n", in->srv->name, in->name);
		return;
	}

	if (in->proc.pending)
		return;

	in->restart = false;
	in->halt = !in->respawn;

	if (!in->valid)
		return;

	pid = fork();
	if (pid < 0)
		return;

	if (!pid) {
		uloop_done();
		instance_run(in);
		return;
	}

	DEBUG(2, "Started instance %s::%s\n", in->srv->name, in->name);
	in->proc.pid = pid;
	clock_gettime(CLOCK_MONOTONIC, &in->start);
	uloop_process_add(&in->proc);
	service_event("instance.start", in->srv->name, in->name);
}

static void
instance_timeout(struct uloop_timeout *t)
{
	struct service_instance *in;

	in = container_of(t, struct service_instance, timeout);

	if (!in->halt && (in->restart || in->respawn))
		instance_start(in);
}

static void
instance_exit(struct uloop_process *p, int ret)
{
	struct service_instance *in;
	struct timespec tp;
	long runtime;

	in = container_of(p, struct service_instance, proc);

	clock_gettime(CLOCK_MONOTONIC, &tp);
	runtime = tp.tv_sec - in->start.tv_sec;

	DEBUG(2, "Instance %s::%s exit with error code %d after %ld seconds\n", in->srv->name, in->name, ret, runtime);
	if (upgrade_running)
		return;

	uloop_timeout_cancel(&in->timeout);
	if (in->halt) {
		/* no action */
	} else if (in->restart) {
		instance_start(in);
	} else if (in->respawn) {
		if (runtime < in->respawn_threshold)
			in->respawn_count++;
		else
			in->respawn_count = 0;
		if (in->respawn_count > in->respawn_retry && in->respawn_retry > 0 ) {
			LOG("Instance %s::%s s in a crash loop %d crashes, %ld seconds since last crash\n",
								in->srv->name, in->name, in->respawn_count, runtime);
			in->restart = in->respawn = 0;
			in->halt = 1;
		} else {
			uloop_timeout_set(&in->timeout, in->respawn_timeout * 1000);
		}
	}
	service_event("instance.stop", in->srv->name, in->name);
}

void
instance_stop(struct service_instance *in)
{
	if (!in->proc.pending)
		return;
	in->halt = true;
	in->restart = in->respawn = false;
	kill(in->proc.pid, SIGTERM);
}

static void
instance_restart(struct service_instance *in)
{
	if (!in->proc.pending)
		return;
	in->halt = false;
	in->restart = true;
	kill(in->proc.pid, SIGTERM);
}

static bool
instance_config_changed(struct service_instance *in, struct service_instance *in_new)
{
	if (!in->valid)
		return true;

	if (!blob_attr_equal(in->command, in_new->command))
		return true;

	if (!blobmsg_list_equal(&in->env, &in_new->env))
		return true;

	if (!blobmsg_list_equal(&in->data, &in_new->data))
		return true;

	if (!blobmsg_list_equal(&in->netdev, &in_new->netdev))
		return true;

	if (!blobmsg_list_equal(&in->file, &in_new->file))
		return true;

	if (in->nice != in_new->nice)
		return true;

	if (in->uid != in_new->uid)
		return true;

	if (in->gid != in_new->gid)
		return true;

	if (!blobmsg_list_equal(&in->limits, &in_new->limits))
		return true;

	if (!blobmsg_list_equal(&in->errors, &in_new->errors))
		return true;

	return false;
}

static bool
instance_netdev_cmp(struct blobmsg_list_node *l1, struct blobmsg_list_node *l2)
{
	struct instance_netdev *n1 = container_of(l1, struct instance_netdev, node);
	struct instance_netdev *n2 = container_of(l2, struct instance_netdev, node);

	return n1->ifindex == n2->ifindex;
}

static void
instance_netdev_update(struct blobmsg_list_node *l)
{
	struct instance_netdev *n = container_of(l, struct instance_netdev, node);

	n->ifindex = if_nametoindex(n->node.avl.key);
}

static bool
instance_file_cmp(struct blobmsg_list_node *l1, struct blobmsg_list_node *l2)
{
	struct instance_file *f1 = container_of(l1, struct instance_file, node);
	struct instance_file *f2 = container_of(l2, struct instance_file, node);

	return !memcmp(f1->md5, f2->md5, sizeof(f1->md5));
}

static void
instance_file_update(struct blobmsg_list_node *l)
{
	struct instance_file *f = container_of(l, struct instance_file, node);
	md5_ctx_t md5;
	char buf[256];
	int len, fd;

	memset(f->md5, 0, sizeof(f->md5));

	fd = open(l->avl.key, O_RDONLY);
	if (fd < 0)
		return;

	md5_begin(&md5);
	do {
		len = read(fd, buf, sizeof(buf));
		if (len < 0) {
			if (errno == EINTR)
				continue;

			break;
		}
		if (!len)
			break;

		md5_hash(buf, len, &md5);
	} while(1);

	md5_end(f->md5, &md5);
	close(fd);
}

static void
instance_fill_any(struct blobmsg_list *l, struct blob_attr *cur)
{
	if (!cur)
		return;

	blobmsg_list_fill(l, blobmsg_data(cur), blobmsg_data_len(cur), false);
}

static bool
instance_fill_array(struct blobmsg_list *l, struct blob_attr *cur, blobmsg_update_cb cb, bool array)
{
	struct blobmsg_list_node *node;

	if (!cur)
		return true;

	if (!blobmsg_check_attr_list(cur, BLOBMSG_TYPE_STRING))
		return false;

	blobmsg_list_fill(l, blobmsg_data(cur), blobmsg_data_len(cur), array);
	if (cb) {
		blobmsg_list_for_each(l, node)
			cb(node);
	}
	return true;
}

static bool
instance_config_parse(struct service_instance *in)
{
	struct blob_attr *tb[__INSTANCE_ATTR_MAX];
	struct blob_attr *cur, *cur2;
	int argc = 0;
	int rem;

	blobmsg_parse(instance_attr, __INSTANCE_ATTR_MAX, tb,
		blobmsg_data(in->config), blobmsg_data_len(in->config));

	cur = tb[INSTANCE_ATTR_COMMAND];
	if (!cur)
		return false;

	if (!blobmsg_check_attr_list(cur, BLOBMSG_TYPE_STRING))
		return false;

	blobmsg_for_each_attr(cur2, cur, rem) {
		argc++;
		break;
	}
	if (!argc)
		return false;

	in->command = cur;

	if (tb[INSTANCE_ATTR_RESPAWN]) {
		int i = 0;
		uint32_t vals[3] = { 3600, 5, 5};

		blobmsg_for_each_attr(cur2, tb[INSTANCE_ATTR_RESPAWN], rem) {
			if ((i >= 3) && (blobmsg_type(cur2) == BLOBMSG_TYPE_STRING))
				continue;
			vals[i] = atoi(blobmsg_get_string(cur2));
			i++;
		}
		in->respawn = true;
		in->respawn_count = 0;
		in->respawn_threshold = vals[0];
		in->respawn_timeout = vals[1];
		in->respawn_retry = vals[2];
	}
	if (tb[INSTANCE_ATTR_TRIGGER]) {
		in->trigger = tb[INSTANCE_ATTR_TRIGGER];
		trigger_add(in->trigger, in);
	}

	if (tb[INSTANCE_ATTR_WATCH]) {
		blobmsg_for_each_attr(cur2, tb[INSTANCE_ATTR_WATCH], rem) {
			if (blobmsg_type(cur2) != BLOBMSG_TYPE_STRING)
				continue;
			DEBUG(3, "watch for %s\n", blobmsg_get_string(cur2));
			watch_add(blobmsg_get_string(cur2), in);
		}
	}

	if ((cur = tb[INSTANCE_ATTR_NICE])) {
		in->nice = (int8_t) blobmsg_get_u32(cur);
		if (in->nice < -20 || in->nice > 20)
			return false;
	}

	if (tb[INSTANCE_ATTR_USER]) {
		struct passwd *p = getpwnam(blobmsg_get_string(tb[INSTANCE_ATTR_USER]));
		if (p) {
			in->uid = p->pw_uid;
			in->gid = p->pw_gid;
		}
	}

	instance_fill_any(&in->data, tb[INSTANCE_ATTR_DATA]);

	if (!instance_fill_array(&in->env, tb[INSTANCE_ATTR_ENV], NULL, false))
		return false;

	if (!instance_fill_array(&in->netdev, tb[INSTANCE_ATTR_NETDEV], instance_netdev_update, true))
		return false;

	if (!instance_fill_array(&in->file, tb[INSTANCE_ATTR_FILE], instance_file_update, true))
		return false;

	if (!instance_fill_array(&in->limits, tb[INSTANCE_ATTR_LIMITS], NULL, false))
		return false;

	if (!instance_fill_array(&in->errors, tb[INSTANCE_ATTR_ERROR], NULL, true))
		return false;

	return true;
}

static void
instance_config_cleanup(struct service_instance *in)
{
	blobmsg_list_free(&in->env);
	blobmsg_list_free(&in->data);
	blobmsg_list_free(&in->netdev);
	blobmsg_list_free(&in->file);
	blobmsg_list_free(&in->limits);
	blobmsg_list_free(&in->errors);
}

static void
instance_config_move(struct service_instance *in, struct service_instance *in_src)
{
	instance_config_cleanup(in);
	blobmsg_list_move(&in->env, &in_src->env);
	blobmsg_list_move(&in->data, &in_src->data);
	blobmsg_list_move(&in->netdev, &in_src->netdev);
	blobmsg_list_move(&in->file, &in_src->file);
	blobmsg_list_move(&in->limits, &in_src->limits);
	blobmsg_list_move(&in->errors, &in_src->errors);
	in->trigger = in_src->trigger;
	in->command = in_src->command;
	in->name = in_src->name;
	in->node.avl.key = in_src->node.avl.key;

	free(in->config);
	in->config = in_src->config;
	in_src->config = NULL;
}

bool
instance_update(struct service_instance *in, struct service_instance *in_new)
{
	bool changed = instance_config_changed(in, in_new);
	bool running = in->proc.pending;

	if (!changed && running)
		return false;

	if (!running) {
		if (changed)
			instance_config_move(in, in_new);
		instance_start(in);
	} else {
		instance_restart(in);
		instance_config_move(in, in_new);
		/* restart happens in the child callback handler */
	}
	return true;
}

void
instance_free(struct service_instance *in)
{
	uloop_process_delete(&in->proc);
	uloop_timeout_cancel(&in->timeout);
	trigger_del(in);
	watch_del(in);
	instance_config_cleanup(in);
	free(in->config);
	free(in);
}

void
instance_init(struct service_instance *in, struct service *s, struct blob_attr *config)
{
	config = blob_memdup(config);
	in->srv = s;
	in->name = blobmsg_name(config);
	in->config = config;
	in->timeout.cb = instance_timeout;
	in->proc.cb = instance_exit;

	blobmsg_list_init(&in->netdev, struct instance_netdev, node, instance_netdev_cmp);
	blobmsg_list_init(&in->file, struct instance_file, node, instance_file_cmp);
	blobmsg_list_simple_init(&in->env);
	blobmsg_list_simple_init(&in->data);
	blobmsg_list_simple_init(&in->limits);
	blobmsg_list_simple_init(&in->errors);
	in->valid = instance_config_parse(in);
}

void instance_dump(struct blob_buf *b, struct service_instance *in, int verbose)
{
	void *i;

	i = blobmsg_open_table(b, in->name);
	blobmsg_add_u8(b, "running", in->proc.pending);
	if (in->proc.pending)
		blobmsg_add_u32(b, "pid", in->proc.pid);
	blobmsg_add_blob(b, in->command);

	if (!avl_is_empty(&in->errors.avl)) {
		struct blobmsg_list_node *var;
		void *e = blobmsg_open_array(b, "errors");
		blobmsg_list_for_each(&in->errors, var)
			blobmsg_add_string(b, NULL, blobmsg_data(var->data));
		blobmsg_close_table(b, e);
	}

	if (!avl_is_empty(&in->env.avl)) {
		struct blobmsg_list_node *var;
		void *e = blobmsg_open_table(b, "env");
		blobmsg_list_for_each(&in->env, var)
			blobmsg_add_string(b, blobmsg_name(var->data), blobmsg_data(var->data));
		blobmsg_close_table(b, e);
	}

	if (!avl_is_empty(&in->data.avl)) {
		struct blobmsg_list_node *var;
		void *e = blobmsg_open_table(b, "data");
		blobmsg_list_for_each(&in->data, var)
			blobmsg_add_blob(b, var->data);
		blobmsg_close_table(b, e);
	}

	if (!avl_is_empty(&in->limits.avl)) {
		struct blobmsg_list_node *var;
		void *e = blobmsg_open_table(b, "limits");
		blobmsg_list_for_each(&in->limits, var)
			blobmsg_add_string(b, blobmsg_name(var->data), blobmsg_data(var->data));
		blobmsg_close_table(b, e);
	}

	if (in->respawn) {
		void *r = blobmsg_open_table(b, "respawn");
		blobmsg_add_u32(b, "timeout", in->respawn_timeout);
		blobmsg_add_u32(b, "threshold", in->respawn_threshold);
		blobmsg_add_u32(b, "retry", in->respawn_retry);
		blobmsg_close_table(b, r);
	}

	if (verbose && in->trigger)
		blobmsg_add_blob(b, in->trigger);

	blobmsg_close_table(b, i);
}
