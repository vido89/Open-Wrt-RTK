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
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "libfstools/libfstools.h"
#include "libfstools/volume.h"

static int
handle_rmdir(const char *dir)
{
	struct stat s;
	struct dirent **namelist;
	int n;

	n = scandir(dir, &namelist, NULL, NULL);

	if (n < 1)
		return -1;

	while (n--) {
		char file[256];

		snprintf(file, sizeof(file), "%s%s", dir, namelist[n]->d_name);
		if (!lstat(file, &s) && !S_ISDIR(s.st_mode))
			unlink(file);
		free(namelist[n]);
	}
	free(namelist);

	rmdir(dir);

	return 0;
}

static int
ask_user(int argc, char **argv)
{
	if ((argc < 2) || strcmp(argv[1], "-y")) {
		fprintf(stderr, "This will erase all settings and remove any installed packages. Are you sure? [N/y]\n");
		if (getchar() != 'y')
			return -1;
	}
	return 0;

}

static int
jffs2_reset(int argc, char **argv)
{
	struct volume *v;
	char *mp;

	if (ask_user(argc, argv))
		return -1;

	if (find_filesystem("overlay")) {
		fprintf(stderr, "overlayfs not found\n");
		return -1;
	}

	v = volume_find("rootfs_data");
	if (!v) {
		fprintf(stderr, "no rootfs_data was found\n");
		return -1;
	}

	mp = find_mount_point(v->blk, 1);
	if (mp) {
		fprintf(stderr, "%s is mounted as %s, only erasing files\n", v->blk, mp);
		foreachdir(mp, handle_rmdir);
		mount(mp, "/", NULL, MS_REMOUNT, 0);
	} else {
		fprintf(stderr, "%s is not mounted, erasing it\n", v->blk);
		volume_erase_all(v);
	}

	return 0;
}

static int
jffs2_mark(int argc, char **argv)
{
	__u32 deadc0de = __cpu_to_be32(0xdeadc0de);
	struct volume *v;
	size_t sz;
	int fd;

	if (ask_user(argc, argv))
		return -1;

	v = volume_find("rootfs_data");
	if (!v) {
		fprintf(stderr, "no rootfs_data was found\n");
		return -1;
	}

	fd = open(v->blk, O_WRONLY);
	fprintf(stderr, "%s - marking with deadc0de\n", v->blk);
	if (!fd) {
		fprintf(stderr, "opening %s failed\n", v->blk);
		return -1;
	}

	sz = write(fd, &deadc0de, sizeof(deadc0de));
	close(fd);

	if (sz != 4) {
		fprintf(stderr, "writing %s failed: %s\n", v->blk, strerror(errno));
		return -1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	if (!strcmp(*argv, "jffs2mark"))
		return jffs2_mark(argc, argv);
	return jffs2_reset(argc, argv);
}
