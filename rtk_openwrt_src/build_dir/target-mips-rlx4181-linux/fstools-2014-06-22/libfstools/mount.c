/*
 * Copyright (C) 2014 John Crispin <blogic@openwrt.org>
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
#include <sys/mount.h>

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "libfstools.h"

/* this is a raw syscall - man 2 pivot_root */
extern int pivot_root(const char *new_root, const char *put_old);

int
mount_move(char *oldroot, char *newroot, char *dir)
{
#ifndef MS_MOVE
#define MS_MOVE	(1 << 13)
#endif
	struct stat s;
	char olddir[64];
	char newdir[64];
	int ret;

	snprintf(olddir, sizeof(olddir), "%s%s", oldroot, dir);
	snprintf(newdir, sizeof(newdir), "%s%s", newroot, dir);

	if (stat(olddir, &s) || !S_ISDIR(s.st_mode))
		return -1;

	if (stat(newdir, &s) || !S_ISDIR(s.st_mode))
		return -1;

	ret = mount(olddir, newdir, NULL, MS_NOATIME | MS_MOVE, NULL);

/*	if (ret)
		fprintf(stderr, "failed %s %s: %s\n", olddir, newdir, strerror(errno));*/

	return ret;
}

int
pivot(char *new, char *old)
{
	char pivotdir[64];
	int ret;

	if (mount_move("", new, "/proc"))
		return -1;

	snprintf(pivotdir, sizeof(pivotdir), "%s%s", new, old);

	ret = pivot_root(new, pivotdir);

	if (ret < 0) {
		fprintf(stderr, "pivot_root failed %s %s: %s\n", new, pivotdir, strerror(errno));
		return -1;
	}

	mount_move(old, "", "/dev");
	mount_move(old, "", "/tmp");
	mount_move(old, "", "/sys");
	mount_move(old, "", "/overlay");

	return 0;
}

int
fopivot(char *rw_root, char *ro_root)
{
	char overlay[64], lowerdir[64];

	if (find_filesystem("overlay")) {
		fprintf(stderr, "BUG: no suitable fs found\n");
		return -1;
	}

	snprintf(overlay, sizeof(overlay), "overlayfs:%s", rw_root);
	snprintf(lowerdir, sizeof(lowerdir), "lowerdir=/,upperdir=%s", rw_root);

	if (mount(overlay, "/mnt", "overlayfs", MS_NOATIME, lowerdir)) {
		fprintf(stderr, "mount failed: %s\n", strerror(errno));
		return -1;
	}

	return pivot("/mnt", ro_root);
}

int
ramoverlay(void)
{
	mkdir("/tmp/root", 0755);
	mount("tmpfs", "/tmp/root", "tmpfs", MS_NOATIME, "mode=0755");

	return fopivot("/tmp/root", "/rom");
}
