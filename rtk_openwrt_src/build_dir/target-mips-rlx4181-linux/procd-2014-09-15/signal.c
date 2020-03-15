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
#include <sys/types.h>

#include <unistd.h>

#include "procd.h"

static void do_reboot(void)
{
	LOG("reboot\n");
	fflush(stderr);
	sync();
	sleep(2);
	reboot(RB_AUTOBOOT);
	while (1)
	;
}

static void signal_shutdown(int signal, siginfo_t *siginfo, void *data)
{
	int event = 0;
	char *msg = NULL;

	switch(signal) {
	case SIGTERM:
		event = RB_AUTOBOOT;
		msg = "reboot";
		break;
	case SIGUSR1:
	case SIGUSR2:
		event = RB_POWER_OFF;
		msg = "poweroff";
		break;
	}

	DEBUG(1, "Triggering %s\n", msg);
	if (event)
		procd_shutdown(event);
}

struct sigaction sa_shutdown = {
	.sa_sigaction = signal_shutdown,
	.sa_flags = SA_SIGINFO
};

static void signal_crash(int signal, siginfo_t *siginfo, void *data)
{
	ERROR("Rebooting as procd has crashed\n");
	do_reboot();
}

struct sigaction sa_crash = {
	.sa_sigaction = signal_crash,
	.sa_flags = SA_SIGINFO
};

static void signal_dummy(int signal, siginfo_t *siginfo, void *data)
{
	ERROR("Got unexpected signal %d\n", signal);
}

struct sigaction sa_dummy = {
	.sa_sigaction = signal_dummy,
	.sa_flags = SA_SIGINFO
};

void procd_signal(void)
{
	signal(SIGPIPE, SIG_IGN);
	if (getpid() != 1)
		return;
	sigaction(SIGTERM, &sa_shutdown, NULL);
	sigaction(SIGUSR1, &sa_shutdown, NULL);
	sigaction(SIGUSR2, &sa_shutdown, NULL);
	sigaction(SIGSEGV, &sa_crash, NULL);
	sigaction(SIGBUS, &sa_crash, NULL);
	sigaction(SIGHUP, &sa_dummy, NULL);
	sigaction(SIGKILL, &sa_dummy, NULL);
	sigaction(SIGSTOP, &sa_dummy, NULL);
}
