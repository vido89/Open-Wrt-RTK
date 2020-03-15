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

#ifndef __PROCD_WATCHDOG_H
#define __PROCD_WATCHDOG_H

void watchdog_init(int preinit);
char* watchdog_fd(void);
int watchdog_timeout(int timeout);
int watchdog_frequency(int frequency);
void watchdog_set_stopped(bool val);
bool watchdog_get_stopped(void);
void watchdog_no_cloexec(void);

#endif
