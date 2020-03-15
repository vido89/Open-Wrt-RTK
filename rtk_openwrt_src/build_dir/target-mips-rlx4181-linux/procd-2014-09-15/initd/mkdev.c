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

#define _BSD_SOURCE

#include <sys/stat.h>
#include <sys/types.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <limits.h>
#include <fnmatch.h>

#include "init.h"

#include "../log.h"

static char **patterns;
static int n_patterns;
static char buf[PATH_MAX];
static char buf2[PATH_MAX];
static unsigned int mode = 0600;

static bool find_pattern(const char *name)
{
	int i;

	for (i = 0; i < n_patterns; i++)
		if (!fnmatch(patterns[i], name, 0))
			return true;

	return false;
}

static void make_dev(const char *path, bool block, int major, int minor)
{
	unsigned int oldumask = umask(0);
	unsigned int _mode = mode | (block ? S_IFBLK : S_IFCHR);

	DEBUG(4, "Creating %s device %s(%d,%d)\n",
		block ? "block" : "character",
		path, major, minor);

	mknod(path, _mode, makedev(major, minor));
	umask(oldumask);
}

static void find_devs(bool block)
{
	char *path = block ? "/sys/dev/block" : "/sys/dev/char";
	struct dirent *dp;
	DIR *dir;

	dir = opendir(path);
	if (!dir)
		return;

	path = buf2 + sprintf(buf2, "%s/", path);
	while ((dp = readdir(dir)) != NULL) {
		char *c;
		int major = 0, minor = 0;
		int len;

		if (dp->d_type != DT_LNK)
			continue;

		if (sscanf(dp->d_name, "%d:%d", &major, &minor) != 2)
			continue;

		strcpy(path, dp->d_name);
		len = readlink(buf2, buf, sizeof(buf));
		if (len <= 0)
			continue;

		buf[len] = 0;
		if (!find_pattern(buf))
			continue;

		c = strrchr(buf, '/');
		if (!c)
			continue;

		c++;
		make_dev(c, block, major, minor);
	}
	closedir(dir);
}

static char *add_pattern(const char *name)
{
	char *str = malloc(strlen(name) + 2);

	str[0] = '*';
	strcpy(str + 1, name);
	return str;
}

int mkdev(const char *name, int _mode)
{
	char *pattern;

	if (chdir("/dev"))
		return 1;

	pattern = add_pattern(name);
	patterns = &pattern;
	mode = _mode;
	n_patterns = 1;
	find_devs(true);
	find_devs(false);
	chdir("/");

	return 0;
}
