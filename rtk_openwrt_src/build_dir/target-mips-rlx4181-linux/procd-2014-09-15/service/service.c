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

#include <libubox/blobmsg_json.h>
#include <libubox/avl-cmp.h>

#include "../procd.h"

#include "service.h"
#include "instance.h"

#include "../rcS.h"

struct avl_tree services;
static struct blob_buf b;
static struct ubus_context *ctx;

static void
service_instance_add(struct service *s, struct blob_attr *attr)
{
	struct service_instance *in;

	if (blobmsg_type(attr) != BLOBMSG_TYPE_TABLE)
		return;

	in = calloc(1, sizeof(*in));
	if (!in)
		return;

	instance_init(in, s, attr);
	vlist_add(&s->instances, &in->node, (void *) in->name);
}

static void
service_instance_update(struct vlist_tree *tree, struct vlist_node *node_new,
			struct vlist_node *node_old)
{
	struct service_instance *in_o = NULL, *in_n = NULL;

	if (node_old)
		in_o = container_of(node_old, struct service_instance, node);

	if (node_new)
		in_n = container_of(node_new, struct service_instance, node);

	if (in_o && in_n) {
		DEBUG(2, "Update instance %s::%s\n", in_o->srv->name, in_o->name);
		instance_update(in_o, in_n);
		instance_free(in_n);
	} else if (in_o) {
		DEBUG(2, "Free instance %s::%s\n", in_o->srv->name, in_o->name);
		instance_stop(in_o);
		instance_free(in_o);
	} else if (in_n) {
		DEBUG(2, "Create instance %s::%s\n", in_n->srv->name, in_n->name);
		instance_start(in_n);
	}
	blob_buf_init(&b, 0);
	trigger_event("instance.update", b.head);
}

static struct service *
service_alloc(const char *name)
{
	struct service *s;
	char *new_name;

	s = calloc_a(sizeof(*s), &new_name, strlen(name) + 1);
	strcpy(new_name, name);

	vlist_init(&s->instances, avl_strcmp, service_instance_update);
	s->instances.keep_old = true;
	s->name = new_name;
	s->avl.key = s->name;
	INIT_LIST_HEAD(&s->validators);

	return s;
}

enum {
	SERVICE_SET_NAME,
	SERVICE_SET_SCRIPT,
	SERVICE_SET_INSTANCES,
	SERVICE_SET_TRIGGER,
	SERVICE_SET_VALIDATE,
	__SERVICE_SET_MAX
};

static const struct blobmsg_policy service_set_attrs[__SERVICE_SET_MAX] = {
	[SERVICE_SET_NAME] = { "name", BLOBMSG_TYPE_STRING },
	[SERVICE_SET_SCRIPT] = { "script", BLOBMSG_TYPE_STRING },
	[SERVICE_SET_INSTANCES] = { "instances", BLOBMSG_TYPE_TABLE },
	[SERVICE_SET_TRIGGER] = { "triggers", BLOBMSG_TYPE_ARRAY },
	[SERVICE_SET_VALIDATE] = { "validate", BLOBMSG_TYPE_ARRAY },
};

static int
service_update(struct service *s, struct blob_attr **tb, bool add)
{
	struct blob_attr *cur;
	int rem;

	if (s->trigger) {
		trigger_del(s);
		free(s->trigger);
		s->trigger = NULL;
	}

	service_validate_del(s);

	if (tb[SERVICE_SET_TRIGGER] && blobmsg_data_len(tb[SERVICE_SET_TRIGGER])) {
		s->trigger = blob_memdup(tb[SERVICE_SET_TRIGGER]);
		if (!s->trigger)
			return -1;
		trigger_add(s->trigger, s);
	}

	if (tb[SERVICE_SET_VALIDATE] && blobmsg_data_len(tb[SERVICE_SET_VALIDATE])) {
		blobmsg_for_each_attr(cur, tb[SERVICE_SET_VALIDATE], rem)
			service_validate_add(s, cur);
	}

	if (tb[SERVICE_SET_INSTANCES]) {
		if (!add)
			vlist_update(&s->instances);
		blobmsg_for_each_attr(cur, tb[SERVICE_SET_INSTANCES], rem) {
			service_instance_add(s, cur);
		}
		if (!add)
			vlist_flush(&s->instances);
	}

	rc(s->name, "running");

	return 0;
}

static void
service_delete(struct service *s)
{
	service_event("service.stop", s->name, NULL);
	vlist_flush_all(&s->instances);
	avl_delete(&services, &s->avl);
	trigger_del(s);
	free(s->trigger);
	free(s);
	service_validate_del(s);
}

enum {
	SERVICE_ATTR_NAME,
	__SERVICE_ATTR_MAX,
};

static const struct blobmsg_policy service_attrs[__SERVICE_ATTR_MAX] = {
	[SERVICE_ATTR_NAME] = { "name", BLOBMSG_TYPE_STRING },
};

enum {
	SERVICE_DEL_ATTR_NAME,
	SERVICE_DEL_ATTR_INSTANCE,
	__SERVICE_DEL_ATTR_MAX,
};

static const struct blobmsg_policy service_del_attrs[__SERVICE_DEL_ATTR_MAX] = {
	[SERVICE_DEL_ATTR_NAME] = { "name", BLOBMSG_TYPE_STRING },
	[SERVICE_DEL_ATTR_INSTANCE] = { "instance", BLOBMSG_TYPE_STRING },
};

enum {
	SERVICE_LIST_ATTR_VERBOSE,
	__SERVICE_LIST_ATTR_MAX,
};

static const struct blobmsg_policy service_list_attrs[__SERVICE_LIST_ATTR_MAX] = {
	[SERVICE_LIST_ATTR_VERBOSE] = { "verbose", BLOBMSG_TYPE_BOOL },
};

enum {
	EVENT_TYPE,
	EVENT_DATA,
	__EVENT_MAX
};

static const struct blobmsg_policy event_policy[__EVENT_MAX] = {
	[EVENT_TYPE] = { .name = "type", .type = BLOBMSG_TYPE_STRING },
	[EVENT_DATA] = { .name = "data", .type = BLOBMSG_TYPE_TABLE },
};

enum {
	VALIDATE_PACKAGE,
	VALIDATE_TYPE,
	VALIDATE_SERVICE,
	__VALIDATE_MAX
};

static const struct blobmsg_policy validate_policy[__VALIDATE_MAX] = {
	[VALIDATE_PACKAGE] = { .name = "package", .type = BLOBMSG_TYPE_STRING },
	[VALIDATE_TYPE] = { .name = "type", .type = BLOBMSG_TYPE_STRING },
	[VALIDATE_SERVICE] = { .name = "service", .type = BLOBMSG_TYPE_STRING },
};

static const struct blobmsg_policy get_data_policy[] = {
	{ "type", BLOBMSG_TYPE_STRING }
};

static int
service_handle_set(struct ubus_context *ctx, struct ubus_object *obj,
		   struct ubus_request_data *req, const char *method,
		   struct blob_attr *msg)
{
	struct blob_attr *tb[__SERVICE_SET_MAX], *cur;
	struct service *s = NULL;
	const char *name;
	bool add = !strcmp(method, "add");
	int ret;

	blobmsg_parse(service_set_attrs, __SERVICE_SET_MAX, tb, blob_data(msg), blob_len(msg));
	cur = tb[SERVICE_ATTR_NAME];
	if (!cur)
		return UBUS_STATUS_INVALID_ARGUMENT;

	name = blobmsg_data(cur);

	s = avl_find_element(&services, name, s, avl);
	if (s) {
		DEBUG(2, "Update service %s\n", name);
		return service_update(s, tb, add);
	}

	DEBUG(2, "Create service %s\n", name);
	s = service_alloc(name);
	if (!s)
		return UBUS_STATUS_UNKNOWN_ERROR;

	ret = service_update(s, tb, add);
	if (ret)
		return ret;

	avl_insert(&services, &s->avl);

	service_event("service.start", s->name, NULL);

	return 0;
}

static void
service_dump(struct service *s, int verbose)
{
	struct service_instance *in;
	void *c, *i;

	c = blobmsg_open_table(&b, s->name);

	if (!avl_is_empty(&s->instances.avl)) {
		i = blobmsg_open_table(&b, "instances");
		vlist_for_each_element(&s->instances, in, node)
			instance_dump(&b, in, verbose);
		blobmsg_close_table(&b, i);
	}
	if (verbose && s->trigger)
		blobmsg_add_blob(&b, s->trigger);
	if (verbose && !list_empty(&s->validators))
		service_validate_dump(&b, s);
	blobmsg_close_table(&b, c);
}

static int
service_handle_list(struct ubus_context *ctx, struct ubus_object *obj,
		    struct ubus_request_data *req, const char *method,
		    struct blob_attr *msg)
{
	struct blob_attr *tb[__SERVICE_LIST_ATTR_MAX];
	struct service *s;
	int verbose = 0;

	blobmsg_parse(service_list_attrs, __SERVICE_LIST_ATTR_MAX, tb, blob_data(msg), blob_len(msg));

	if (tb[SERVICE_LIST_ATTR_VERBOSE] && blobmsg_get_bool(tb[SERVICE_LIST_ATTR_VERBOSE]))
		verbose = 1;

	blob_buf_init(&b, 0);
	avl_for_each_element(&services, s, avl)
		service_dump(s, verbose);

	ubus_send_reply(ctx, req, b.head);

	return 0;
}

static int
service_handle_delete(struct ubus_context *ctx, struct ubus_object *obj,
		    struct ubus_request_data *req, const char *method,
		    struct blob_attr *msg)
{
	struct blob_attr *tb[__SERVICE_DEL_ATTR_MAX], *cur;
	struct service *s;
	struct service_instance *in;

	blobmsg_parse(service_del_attrs, __SERVICE_DEL_ATTR_MAX, tb, blob_data(msg), blob_len(msg));

	cur = tb[SERVICE_DEL_ATTR_NAME];
	if (!cur)
		return UBUS_STATUS_NOT_FOUND;

	s = avl_find_element(&services, blobmsg_data(cur), s, avl);
	if (!s)
		return UBUS_STATUS_NOT_FOUND;

	cur = tb[SERVICE_DEL_ATTR_INSTANCE];
	if (!cur) {
		service_delete(s);
		return 0;
	}

	in = vlist_find(&s->instances, blobmsg_data(cur), in, node);
	if (!in) {
		ERROR("instance %s not found\n", (char *) blobmsg_data(cur));
		return UBUS_STATUS_NOT_FOUND;
	}

	vlist_delete(&s->instances, &in->node);

	return 0;
}

static int
service_handle_update(struct ubus_context *ctx, struct ubus_object *obj,
		      struct ubus_request_data *req, const char *method,
		      struct blob_attr *msg)
{
	struct blob_attr *tb[__SERVICE_ATTR_MAX], *cur;
	struct service *s;

	blobmsg_parse(service_attrs, __SERVICE_ATTR_MAX, tb, blob_data(msg), blob_len(msg));

	cur = tb[SERVICE_ATTR_NAME];
	if (!cur)
		return UBUS_STATUS_INVALID_ARGUMENT;

	s = avl_find_element(&services, blobmsg_data(cur), s, avl);
	if (!s)
		return UBUS_STATUS_NOT_FOUND;

	if (!strcmp(method, "update_start"))
		vlist_update(&s->instances);
	else
		vlist_flush(&s->instances);

	return 0;
}

static int
service_handle_event(struct ubus_context *ctx, struct ubus_object *obj,
			struct ubus_request_data *req, const char *method,
			struct blob_attr *msg)
{
	struct blob_attr *tb[__EVENT_MAX];

	if (!msg)
		return UBUS_STATUS_INVALID_ARGUMENT;

	blobmsg_parse(event_policy, __EVENT_MAX, tb, blob_data(msg), blob_len(msg));
	if (!tb[EVENT_TYPE] || !tb[EVENT_DATA])
		return UBUS_STATUS_INVALID_ARGUMENT;

	trigger_event(blobmsg_get_string(tb[EVENT_TYPE]), tb[EVENT_DATA]);

	return 0;
}

static int
service_handle_validate(struct ubus_context *ctx, struct ubus_object *obj,
			struct ubus_request_data *req, const char *method,
			struct blob_attr *msg)
{
	struct blob_attr *tb[__VALIDATE_MAX];
	char *p = NULL, *t = NULL;

	if (!msg)
		return UBUS_STATUS_INVALID_ARGUMENT;

	blobmsg_parse(validate_policy, __VALIDATE_MAX, tb, blob_data(msg), blob_len(msg));
	if (tb[VALIDATE_SERVICE]) {
		return 0;
	}
	if (tb[VALIDATE_PACKAGE])
		p = blobmsg_get_string(tb[VALIDATE_PACKAGE]);

	if (tb[VALIDATE_TYPE])
		t = blobmsg_get_string(tb[VALIDATE_TYPE]);

	blob_buf_init(&b, 0);
	service_validate_dump_all(&b, p, t);
	ubus_send_reply(ctx, req, b.head);

	return 0;
}

static int
service_get_data(struct ubus_context *ctx, struct ubus_object *obj,
		 struct ubus_request_data *req, const char *method,
		 struct blob_attr *msg)
{
	struct service_instance *in;
	struct service *s;
	struct blob_attr *tb;
	const char *type = NULL;

	blobmsg_parse(get_data_policy, 1, &tb, blob_data(msg), blob_len(msg));
	if (tb)
		type = blobmsg_data(tb);

	blob_buf_init(&b, 0);
	avl_for_each_element(&services, s, avl) {
		void *cs = NULL;

		vlist_for_each_element(&s->instances, in, node) {
			struct blobmsg_list_node *var;
			void *ci = NULL;

			blobmsg_list_for_each(&in->data, var) {
				if (type &&
				    strcmp(blobmsg_name(var->data), type) != 0)
					continue;

				if (!cs)
					cs = blobmsg_open_table(&b, s->name);
				if (!ci)
					ci = blobmsg_open_table(&b, in->name);

				blobmsg_add_blob(&b, var->data);
			}

			if (ci)
				blobmsg_close_table(&b, ci);
		}

		if (cs)
			blobmsg_close_table(&b, cs);
	}

	ubus_send_reply(ctx, req, b.head);
	return 0;
}

static struct ubus_method main_object_methods[] = {
	UBUS_METHOD("set", service_handle_set, service_set_attrs),
	UBUS_METHOD("add", service_handle_set, service_set_attrs),
	UBUS_METHOD("list", service_handle_list, service_attrs),
	UBUS_METHOD("delete", service_handle_delete, service_del_attrs),
	UBUS_METHOD("update_start", service_handle_update, service_attrs),
	UBUS_METHOD("update_complete", service_handle_update, service_attrs),
	UBUS_METHOD("event", service_handle_event, event_policy),
	UBUS_METHOD("validate", service_handle_validate, validate_policy),
	UBUS_METHOD("get_data", service_get_data, get_data_policy),
};

static struct ubus_object_type main_object_type =
	UBUS_OBJECT_TYPE("service", main_object_methods);

static struct ubus_object main_object = {
	.name = "service",
	.type = &main_object_type,
	.methods = main_object_methods,
	.n_methods = ARRAY_SIZE(main_object_methods),
};

int
service_start_early(char *name, char *cmdline)
{
	void *instances, *instance, *command, *respawn;
	char *t;

	blob_buf_init(&b, 0);
	blobmsg_add_string(&b, "name", name);
	instances = blobmsg_open_table(&b, "instances");
	instance = blobmsg_open_table(&b, "instance1");
	command = blobmsg_open_array(&b, "command");
	t = strtok(cmdline, " ");
	while (t) {
		blobmsg_add_string(&b, NULL, t);
		t = strtok(NULL, " ");
	}
	blobmsg_close_array(&b, command);
	respawn = blobmsg_open_array(&b, "respawn");
	blobmsg_add_string(&b, NULL, "3600");
	blobmsg_add_string(&b, NULL, "1");
	blobmsg_add_string(&b, NULL, "0");
	blobmsg_close_array(&b, respawn);
	blobmsg_close_table(&b, instance);
	blobmsg_close_table(&b, instances);

	return service_handle_set(NULL, NULL, NULL, "add", b.head);
}

void service_event(const char *type, const char *service, const char *instance)
{
	if (!ctx)
		return;

	blob_buf_init(&b, 0);
	blobmsg_add_string(&b, "service", service);
	if (instance)
		blobmsg_add_string(&b, "instance", instance);
	ubus_notify(ctx, &main_object, type, b.head, -1);
}

void ubus_init_service(struct ubus_context *_ctx)
{
	ctx = _ctx;
	ubus_add_object(ctx, &main_object);
}

void
service_init(void)
{
	avl_init(&services, avl_strcmp, false, NULL);
	service_validate_init();
}

