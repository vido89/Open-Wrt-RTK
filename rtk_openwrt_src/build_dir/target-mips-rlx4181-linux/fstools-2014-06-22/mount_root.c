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

#include <sys/mount.h>
#include <stdio.h>
#include <stdlib.h>

#include "libfstools/libfstools.h"
#include "libfstools/volume.h"

static int
start(int argc, char *argv[1])
{
	struct volume *v = volume_find("rootfs_data");

	if (!getenv("PREINIT"))
		return -1;

	if (!v) {
		v = volume_find("rootfs");
		volume_init(v);
		fprintf(stderr, "mounting /dev/root\n");
		mount("/dev/root", "/", NULL, MS_NOATIME | MS_REMOUNT, 0);
		return 0;
	}

	extroot_prefix = "";
	if (!mount_extroot()) {
		fprintf(stderr, "fs-state: switched to extroot\n");
		return 0;
	}

	switch (volume_identify(v)) {
	case FS_NONE:
	case FS_DEADCODE:
		return ramoverlay();

	case FS_JFFS2:
	case FS_UBIFS:
		mount_overlay();
		break;

	case FS_SNAPSHOT:
		mount_snapshot();
		break;
	}

	return 0;
}

static int
stop(int argc, char *argv[1])
{
	if (!getenv("SHUTDOWN"))
		return -1;

	return 0;
}

static int
done(int argc, char *argv[1])
{
	struct volume *v = volume_find("rootfs_data");

	if (!v)
		return -1;

	switch (volume_identify(v)) {
	case FS_NONE:
	case FS_DEADCODE:
		return jffs2_switch(argc, argv);
	}

	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return start(argc, argv);
	if (!strcmp(argv[1], "stop"))
		return stop(argc, argv);
	if (!strcmp(argv[1], "done"))
		return done(argc, argv);
	return -1;
}
