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

#include <stdlib.h>
#include <unistd.h>

#include <libubox/blobmsg_json.h>

#include "../procd.h"

struct watch_object {
	struct list_head list;

	void *id;
	char *name;
};

struct watch_subscribe {
	struct uloop_timeout t;
	uint32_t id;
};

static struct ubus_event_handler watch_event;
static struct ubus_subscriber watch_subscribe;
static LIST_HEAD(watch_objects);

static void watch_subscribe_cb(struct ubus_context *ctx, struct ubus_event_handler *ev,
		const char *type, struct blob_attr *msg)
{
	static const struct blobmsg_policy policy = {
		"path", BLOBMSG_TYPE_STRING
	};
	struct watch_object *o;
	struct blob_attr *attr;
	const char *path;

	DEBUG(3, "ubus event %s\n", type);
	if (strcmp(type, "ubus.object.add") != 0)
		return;

	blobmsg_parse(&policy, 1, &attr, blob_data(msg), blob_len(msg));
	if (!attr)
		return;

	path = blobmsg_data(attr);
	DEBUG(3, "ubus path %s\n", path);

	list_for_each_entry(o, &watch_objects, list) {
		unsigned int id;

		if (strcmp(o->name, path))
			continue;
		if (ubus_lookup_id(ctx, path, &id))
			continue;
		if (!ubus_subscribe(ctx, &watch_subscribe, id))
			return;
		ERROR("failed to subscribe %d\n", id);
	}
}

void
watch_add(const char *_name, void *id)
{
	int len = strlen(_name);
	char *name;
	struct watch_object *o = calloc_a(sizeof(*o), &name, len + 1);

	o->name = name;
	strcpy(name, _name);
	o->id = id;
	list_add(&o->list, &watch_objects);
}

void
watch_del(void *id)
{
	struct watch_object *t, *n;

	list_for_each_entry_safe(t, n, &watch_objects, list) {
		if (t->id != id)
			continue;
		list_del(&t->list);
		free(t);
	}
}

static int
watch_notify_cb(struct ubus_context *ctx, struct ubus_object *obj,
		struct ubus_request_data *req, const char *method,
		struct blob_attr *msg)
{
	if (debug >= 3) {
		char *str;

		str = blobmsg_format_json(msg, true);
		DEBUG(3, "Received ubus notify '%s': %s\n", method, str);
		free(str);
	}

	trigger_event(method, msg);
	return 0;
}

void
watch_ubus(struct ubus_context *ctx)
{
	watch_event.cb = watch_subscribe_cb;
	watch_subscribe.cb = watch_notify_cb;
	if (ubus_register_subscriber(ctx, &watch_subscribe))
		ERROR("failed to register ubus subscriber\n");
	if (ubus_register_event_handler(ctx, &watch_event, "ubus.object.add"))
		ERROR("failed to add ubus event handler\n");
}
