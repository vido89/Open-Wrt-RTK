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

#ifndef __PROCD_H
#define __PROCD_H

#include <libubox/uloop.h>
#include <libubox/utils.h>
#include <libubus.h>

#include <stdio.h>
#include <syslog.h>

#include "log.h"

#define __init __attribute__((constructor))

extern char *ubus_socket;
extern int upgrade_running;

void procd_connect_ubus(void);
void procd_reconnect_ubus(int reconnect);
void ubus_init_service(struct ubus_context *ctx);
void ubus_init_system(struct ubus_context *ctx);

void procd_state_next(void);
void procd_shutdown(int event);
void procd_early(void);
void procd_preinit(void);
void procd_coldplug(void);
void procd_signal(void);
void procd_signal_preinit(void);
void procd_inittab(void);
void procd_inittab_run(const char *action);
void procd_bcast_event(char *event, struct blob_attr *msg);

struct trigger;
void trigger_init(void);
void trigger_event(const char *type, struct blob_attr *data);
void trigger_add(struct blob_attr *rule, void *id);
void trigger_del(void *id);

void watch_add(const char *_name, void *id);
void watch_del(void *id);
void watch_ubus(struct ubus_context *ctx);

#endif
