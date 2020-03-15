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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <libubox/uloop.h>

#include "../watchdog.h"

static struct uloop_process upgrade_proc;
unsigned int debug = 2;

static void upgrade_proc_cb(struct uloop_process *proc, int ret)
{
	if (ret)
		fprintf(stderr, "sysupgrade aborted with return code: %d\n", ret);
	uloop_end();
}

static void sysupgarde(char *folder)
{
	char *args[] = { "/sbin/sysupgrade", "nand", NULL, NULL };

	args[2] = folder;
	upgrade_proc.cb = upgrade_proc_cb;
	upgrade_proc.pid = fork();
	if (!upgrade_proc.pid) {
		execvp(args[0], args);
		fprintf(stderr, "Failed to fork sysupgrade\n");
		exit(-1);
	}
	if (upgrade_proc.pid <= 0) {
		fprintf(stderr, "Failed to start sysupgarde\n");
		uloop_end();
	}
}

int main(int argc, char **argv)
{
	pid_t p = getpid();

	chdir("/tmp");

	if (p != 1) {
		fprintf(stderr, "this tool needs to run as pid 1\n");
		return -1;
	}
	if (argc != 2) {
		fprintf(stderr, "sysupgrade stage 2 failed, no folder specified\n");
		return -1;
	}

	uloop_init();
	watchdog_init(0);
	sysupgarde(argv[1]);
	uloop_run();

	reboot(RB_AUTOBOOT);

	return 0;
}
