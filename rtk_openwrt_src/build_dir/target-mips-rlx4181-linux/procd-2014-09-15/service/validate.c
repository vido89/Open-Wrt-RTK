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

#include <libubox/blobmsg_json.h>
#include <libubox/avl-cmp.h>
#include <json/json.h>

#include "../procd.h"

#include "service.h"

enum {
	SERVICE_VAL_PACKAGE,
	SERVICE_VAL_TYPE,
	SERVICE_VAL_DATA,
	__SERVICE_VAL_MAX
};

static const struct blobmsg_policy service_validate_attrs[__SERVICE_VAL_MAX] = {
	[SERVICE_VAL_PACKAGE] = { "package", BLOBMSG_TYPE_STRING },
	[SERVICE_VAL_TYPE] = { "type", BLOBMSG_TYPE_STRING },
	[SERVICE_VAL_DATA] = { "data", BLOBMSG_TYPE_TABLE },
};

static struct avl_tree validators;

void
service_validate_dump_all(struct blob_buf *b, char *p, char *s)
{
	struct json_object *r = json_object_new_object();
	struct validate *v;

	if (!r)
		return;

	avl_for_each_element(&validators, v, avl) {
		struct json_object *o, *t;
		struct vrule *vr;

		if (p && strcmp(p, v->package))
			continue;

		if (s && strcmp(s, v->type))
			continue;

		o = json_object_object_get(r, v->package);
		if (!o) {
			o = json_object_new_object();
			json_object_object_add(r, v->package, o);
		}
		t = json_object_object_get(o, v->type);
		if (!t) {
			t = json_object_new_object();
			json_object_object_add(o, v->type, t);
		}
		avl_for_each_element(&v->rules, vr, avl)
			json_object_object_add(t, vr->option, json_object_new_string(vr->rule));
	}
	blobmsg_add_object(b, r);
	json_object_put(r);
}

void
service_validate_dump(struct blob_buf *b, struct service *s)
{
	struct validate *v;
	void *i = blobmsg_open_array(b, "validate");

        list_for_each_entry(v, &s->validators, list) {
		struct vrule *vr;
		void *k, *j = blobmsg_open_table(b, "validate");

		blobmsg_add_string(b, "package", v->package);
                blobmsg_add_string(b, "type", v->type);
		k = blobmsg_open_table(b, "rules");
		avl_for_each_element(&v->rules, vr, avl)
	                blobmsg_add_string(b, vr->option, vr->rule);
		blobmsg_close_table(b, k);
		blobmsg_close_table(b, j);
	}
	blobmsg_close_array(b, i);
}

void
service_validate_del(struct service *s)
{
	struct validate *v, *n;

	if (list_empty(&s->validators))
		return;

        list_for_each_entry_safe(v, n, &s->validators, list) {
		struct vrule *vr, *a;

		avl_remove_all_elements(&v->rules, vr, avl, a)
			free(vr);

		avl_delete(&validators, &v->avl);
		list_del(&v->list);
		free(v);
	}
}

void
service_validate_add(struct service *s, struct blob_attr *msg)
{
	struct blob_attr *tb[__SERVICE_VAL_MAX];
	struct validate *v;
	char *type, *package;
	struct blob_attr *cur;
	int rem;

	blobmsg_parse(service_validate_attrs, __SERVICE_VAL_MAX, tb, blobmsg_data(msg), blobmsg_data_len(msg));
	if (!tb[SERVICE_VAL_PACKAGE] || !tb[SERVICE_VAL_TYPE] || !tb[SERVICE_VAL_DATA])
		return;

	v = calloc_a(sizeof(*v), &package, blobmsg_data_len(tb[SERVICE_VAL_PACKAGE]) + 1,
			 &type, blobmsg_data_len(tb[SERVICE_VAL_TYPE]) + 1);
	if (!v)
		return;

	v->type = type;
	v->avl.key = v->package = package;
	strcpy(v->package, blobmsg_get_string(tb[SERVICE_VAL_PACKAGE]));
	strcpy(v->type, blobmsg_get_string(tb[SERVICE_VAL_TYPE]));

	list_add(&v->list, &s->validators);
	if (avl_insert(&validators, &v->avl)) {
		free(v);
		return;
	}
	avl_init(&v->rules, avl_strcmp, false, NULL);

	blobmsg_for_each_attr(cur, tb[SERVICE_VAL_DATA], rem) {
		char *option;
		char *rule;
		struct vrule *vr = calloc_a(sizeof(*vr), &option, strlen(blobmsg_name(cur)) + 1,
			&rule, strlen(blobmsg_get_string(cur)) + 1);

		vr->avl.key = vr->option = option;
		vr->rule = rule;
		strcpy(vr->option, blobmsg_name(cur));
		strcpy(vr->rule, blobmsg_get_string(cur));
		if (avl_insert(&v->rules, &vr->avl))
			free(vr);
	}
}

void
service_validate_init(void)
{
	avl_init(&validators, avl_strcmp, true, NULL);
}
