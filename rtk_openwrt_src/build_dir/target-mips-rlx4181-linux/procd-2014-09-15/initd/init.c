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

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/reboot.h>

#include <libubox/uloop.h>
#include <libubus.h>

#include <stdlib.h>
#include <fcntl.h>
#include <getopt.h>
#include <libgen.h>
#include <regex.h>
#include <unistd.h>
#include <stdio.h>

#include "init.h"
#include "../watchdog.h"

unsigned int debug = 0;

static void
signal_shutdown(int signal, siginfo_t *siginfo, void *data)
{
	fprintf(stderr, "reboot\n");
	fflush(stderr);
	sync();
	sleep(2);
	reboot(RB_AUTOBOOT);
	while (1)
		;
}

static struct sigaction sa_shutdown = {
	.sa_sigaction = signal_shutdown,
	.sa_flags = SA_SIGINFO
};

static void
cmdline(void)
{
	char line[1024];
	int r, fd = open("/proc/cmdline", O_RDONLY);
	regex_t pat_cmdline;
	regmatch_t matches[2];

	if (fd < 0)
		return;

	r = read(fd, line, sizeof(line) - 1);
	line[r] = '\0';
	close(fd);

	regcomp(&pat_cmdline, "init_debug=([0-9]+)", REG_EXTENDED);
	if (!regexec(&pat_cmdline, line, 2, matches, 0)) {
		line[matches[1].rm_eo] = '\0';
		debug = atoi(&line[matches[1].rm_so]);
	}
	regfree(&pat_cmdline);
}

int
main(int argc, char **argv)
{
	pid_t pid;

	sigaction(SIGTERM, &sa_shutdown, NULL);
	sigaction(SIGUSR1, &sa_shutdown, NULL);
	sigaction(SIGUSR2, &sa_shutdown, NULL);

	early();
	cmdline();
	watchdog_init(1);

	pid = fork();
	if (!pid) {
		char *kmod[] = { "/sbin/kmodloader", "/etc/modules-boot.d/", NULL };

		if (debug < 3) {
			int fd = open("/dev/null", O_RDWR);

			if (fd > -1) {
				dup2(fd, STDIN_FILENO);
				dup2(fd, STDOUT_FILENO);
				dup2(fd, STDERR_FILENO);
				if (fd > STDERR_FILENO)
					close(fd);
			}
		}
		execvp(kmod[0], kmod);
		ERROR("Failed to start kmodloader\n");
		exit(-1);
	}
	if (pid <= 0)
		ERROR("Failed to start kmodloader instance\n");
	else
		waitpid(pid, NULL, 0);
	uloop_init();
	preinit();
	uloop_run();

	return 0;
}
