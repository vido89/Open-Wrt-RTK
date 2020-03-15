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

#include <sys/reboot.h>
#include <stdlib.h>
#include <unistd.h>

#include "procd.h"
#include "syslog.h"
#include "plug/hotplug.h"
#include "watchdog.h"
#include "service/service.h"

enum {
	STATE_NONE = 0,
	STATE_EARLY,
	STATE_INIT,
	STATE_RUNNING,
	STATE_SHUTDOWN,
	STATE_HALT,
	__STATE_MAX,
};

static int state = STATE_NONE;
static int reboot_event;

static void state_enter(void)
{
	char ubus_cmd[] = "/sbin/ubusd";

	switch (state) {
	case STATE_EARLY:
		LOG("- early -\n");
		watchdog_init(0);
		hotplug("/etc/hotplug.json");
		procd_coldplug();
		break;

	case STATE_INIT:
		// try to reopen incase the wdt was not available before coldplug
		watchdog_init(0);
		LOG("- ubus -\n");
		procd_connect_ubus();

		LOG("- init -\n");
		service_init();
		service_start_early("ubus", ubus_cmd);

		procd_inittab();
		procd_inittab_run("respawn");
		procd_inittab_run("askconsole");
		procd_inittab_run("askfirst");
		procd_inittab_run("sysinit");
		break;

	case STATE_RUNNING:
		LOG("- init complete -\n");
		break;

	case STATE_SHUTDOWN:
		LOG("- shutdown -\n");
		procd_inittab_run("shutdown");
		sync();
		break;

	case STATE_HALT:
		LOG("- reboot -\n");
		reboot(reboot_event);
		break;

	default:
		ERROR("Unhandled state %d\n", state);
		return;
	};
}

void procd_state_next(void)
{
	DEBUG(4, "Change state %d -> %d\n", state, state + 1);
	state++;
	state_enter();
}

void procd_shutdown(int event)
{
	DEBUG(2, "Shutting down system with event %x\n", event);
	reboot_event = event;
	state = STATE_SHUTDOWN;
	state_enter();
}
