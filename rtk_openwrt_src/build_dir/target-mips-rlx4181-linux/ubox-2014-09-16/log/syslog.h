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

#ifndef __SYSLOG_H
#define __SYSLOG_H

enum {
	SOURCE_KLOG = 0,
	SOURCE_SYSLOG = 1,
	SOURCE_INTERNAL = 2,
	SOURCE_ANY = 0xff,
};

struct log_head {
	unsigned int size;
	unsigned int id;
	int priority;
	int source;
        struct timespec ts;
	char data[];
};

void log_init(int log_size);
void log_shutdown(void);

typedef void (*log_list_cb)(struct log_head *h);
struct log_head* log_list(int count, struct log_head *h);
int log_buffer_init(int size);
void log_add(char *buf, int size, int source);
void ubus_notify_log(struct log_head *l);

#endif
