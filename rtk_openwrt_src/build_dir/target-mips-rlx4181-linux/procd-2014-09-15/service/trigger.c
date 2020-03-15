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

#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <linux/types.h>
#include <linux/netlink.h>

#include <libubox/blobmsg_json.h>
#include <libubox/json_script.h>
#include <libubox/runqueue.h>
#include <libubox/ustream.h>
#include <libubox/uloop.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>

#include "../procd.h"

struct trigger {
	struct list_head list;

	char *type;

	int pending;
	int remove;
	int timeout;

	void *id;

	struct blob_attr *rule;
	struct blob_attr *data;
	struct uloop_timeout delay;

	struct json_script_ctx jctx;
};

struct job;
struct cmd {
	char *name;
	void (*handler)(struct job *job, struct blob_attr *exec, struct blob_attr *env);
};

struct job {
	struct runqueue_process proc;
	struct cmd *cmd;
	struct trigger *trigger;
	struct blob_attr *exec;
	struct blob_attr *env;
};

static LIST_HEAD(triggers);
static struct runqueue q;

static const char* rule_handle_var(struct json_script_ctx *ctx, const char *name, struct blob_attr *vars)
{
	return NULL;
}

static struct json_script_file *
rule_load_script(struct json_script_ctx *ctx, const char *name)
{
	struct trigger *t = container_of(ctx, struct trigger, jctx);

	return json_script_file_from_blobmsg(t->type, t->rule, blob_pad_len(t->rule));
}

static void q_job_run(struct runqueue *q, struct runqueue_task *t)
{
	struct job *j = container_of(t, struct job, proc.task);

	DEBUG(4, "handle event %s\n", j->cmd->name);
	j->cmd->handler(j, j->exec, j->env);
}

static void trigger_free(struct trigger *t)
{
	json_script_free(&t->jctx);
	uloop_timeout_cancel(&t->delay);
	free(t->data);
	list_del(&t->list);
	free(t);
}

static void q_job_complete(struct runqueue *q, struct runqueue_task *p)
{
	struct job *j = container_of(p, struct job, proc.task);

	if (j->trigger->remove) {
		trigger_free(j->trigger);
	} else {
		j->trigger->pending = 0;
	}
	free(j);
}

static void add_job(struct trigger *t, struct cmd *cmd, struct blob_attr *exec, struct blob_attr *data)
{
	static const struct runqueue_task_type job_type = {
		.run = q_job_run,
		.cancel = runqueue_process_cancel_cb,
		.kill = runqueue_process_kill_cb,
	};
	struct blob_attr *d, *e;
	struct job *j = calloc_a(sizeof(*j), &e, blob_pad_len(exec), &d, blob_pad_len(data));

	j->env = d;
	j->exec = e;
	j->cmd = cmd;
	j->trigger = t;
	j->proc.task.type = &job_type;
	j->proc.task.complete = q_job_complete;
	t->pending = 1;

	memcpy(j->exec, exec, blob_pad_len(exec));
	memcpy(j->env, data, blob_pad_len(data));

	runqueue_task_add(&q, &j->proc.task, false);
}

static void _setenv(const char *key, const char *val)
{
	char _key[32];

	snprintf(_key, sizeof(_key), "PARAM_%s", key);
	setenv(_key, val, 1);
}

static void handle_run_script(struct job *j, struct blob_attr *exec, struct blob_attr *env)
{
	char *argv[8];
	struct blob_attr *cur;
	int rem;
	int i = 0;
	pid_t pid;

	pid = fork();
	if (pid < 0)
		return;

	if (pid) {
		runqueue_process_add(&q, &j->proc, pid);
		return;
	}

	if (debug < 3) {
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}

	_setenv("type", j->trigger->type);
	blobmsg_for_each_attr(cur, j->env, rem)
		_setenv(blobmsg_name(cur), blobmsg_data(cur));

	blobmsg_for_each_attr(cur, j->exec, rem) {
		argv[i] = blobmsg_data(cur);
		i++;
		if (i == 7)
			break;
	}

	if (i > 0) {
		argv[i] = NULL;
		execvp(argv[0], &argv[0]);
	}

	exit(1);
}

static struct cmd handlers[] = {
	{
		.name = "run_script",
		.handler = handle_run_script,
	},
};

static void rule_handle_command(struct json_script_ctx *ctx, const char *name,
				struct blob_attr *exec, struct blob_attr *vars)
{
	struct trigger *t = container_of(ctx, struct trigger, jctx);
	int i;

	if (t->pending)
		return;

	for (i = 0; i < ARRAY_SIZE(handlers); i++) {
		if (!strcmp(handlers[i].name, name)) {
			add_job(t, &handlers[i], exec, vars);
			break;
		}
	}
}

static void rule_handle_error(struct json_script_ctx *ctx, const char *msg,
				struct blob_attr *context)
{
	char *s;

	s = blobmsg_format_json(context, false);
	ERROR("ERROR: %s in block: %s\n", msg, s);
	free(s);
}

static void q_empty(struct runqueue *q)
{
}

static void trigger_delay_cb(struct uloop_timeout *tout)
{
	struct trigger *t = container_of(tout, struct trigger, delay);

	json_script_run(&t->jctx, "foo", t->data);
	free(t->data);
	t->data = NULL;
}

static struct trigger* _trigger_add(char *type, struct blob_attr *rule, int timeout, void *id)
{
	char *_t;
	struct blob_attr *_r;
	struct trigger *t = calloc_a(sizeof(*t), &_t, strlen(type) + 1, &_r, blob_pad_len(rule));

	t->type = _t;
	t->rule = _r;
	t->delay.cb = trigger_delay_cb;
	t->timeout = timeout;
	t->pending = 0;
	t->remove = 0;
	t->id = id;
	t->jctx.handle_var = rule_handle_var,
	t->jctx.handle_error = rule_handle_error,
	t->jctx.handle_command = rule_handle_command,
	t->jctx.handle_file = rule_load_script,

	strcpy(t->type, type);
	memcpy(t->rule, rule, blob_pad_len(rule));

	list_add(&t->list, &triggers);
	json_script_init(&t->jctx);

	return t;
}

void trigger_add(struct blob_attr *rule, void *id)
{
	struct blob_attr *cur;
	int rem;

	blobmsg_for_each_attr(cur, rule, rem) {
		struct blob_attr *_cur, *type = NULL, *script = NULL, *timeout = NULL;
		int _rem;
		int i = 0;

		if (blobmsg_type(cur) != BLOBMSG_TYPE_ARRAY)
			continue;

		blobmsg_for_each_attr(_cur, cur, _rem) {
			switch (i++) {
			case 0:
				if (blobmsg_type(_cur) == BLOBMSG_TYPE_STRING)
					type = _cur;
				break;

			case 1:
				if (blobmsg_type(_cur) == BLOBMSG_TYPE_ARRAY)
					script = _cur;
				break;

			case 2:
				if (blobmsg_type(_cur) == BLOBMSG_TYPE_INT32)
					timeout = _cur;
				break;
			}
		}

		if (type && script) {
			int t = 0;

			if (timeout)
				t = blobmsg_get_u32(timeout);
			_trigger_add(blobmsg_get_string(type), script, t, id);
		}
	}
}

void trigger_del(void *id)
{
	struct trigger *t, *n;

	list_for_each_entry_safe(t, n, &triggers, list) {
		if (t->id != id)
			continue;

		if (t->pending) {
			t->remove = 1;
			continue;
		}

		trigger_free(t);
	}
}

void trigger_init(void)
{
	runqueue_init(&q);
	q.empty_cb = q_empty;
	q.max_running_tasks = 1;
}

static int trigger_match(const char *event, const char *match)
{
	char *wildcard = strstr(match, ".*");
	if (wildcard)
		return strncmp(event, match, wildcard - match);
	return strcmp(event, match);
}

void trigger_event(const char *type, struct blob_attr *data)
{
	struct trigger *t;

	list_for_each_entry(t, &triggers, list) {
		if (t->pending || t->remove)
			continue;
		if (!trigger_match(type, t->type)) {
			if (t->timeout) {
				free(t->data);
				t->data = blob_memdup(data);
				uloop_timeout_set(&t->delay, t->timeout);
			} else {
				json_script_run(&t->jctx, "foo", data);
			}
		}
	}
}
