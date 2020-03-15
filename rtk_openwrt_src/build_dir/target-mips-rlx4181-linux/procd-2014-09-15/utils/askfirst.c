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

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static int redirect_output(const char *dev)
{
	pid_t p = setsid();
	int fd;

	chdir("/dev");
	fd = open(dev, O_RDWR);
	chdir("/");

	if (fd < 0)
		return -1;

	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);
	tcsetpgrp(fd, p);
	close(fd);

	return 0;
}

int main(int argc, char **argv)
{
	int c;

	if (redirect_output(argv[1]))
		fprintf(stderr, "%s: Failed to open %s\n", argv[0], argv[1]);

	printf("Please press Enter to activate this console.\n");
	do {
		c = getchar();
		if (c == EOF)
			return -1;
	}
	while (c != 0xA);

	execvp(argv[2], &argv[2]);
	printf("%s: Failed to execute %s\n", argv[0], argv[2]);

	return -1;
}
