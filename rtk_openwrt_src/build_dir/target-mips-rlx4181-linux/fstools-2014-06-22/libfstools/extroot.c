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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "libfstools.h"

char const *extroot_prefix = NULL;

int mount_extroot(void)
{
	char ldlib_path[32];
	char block_path[32];
	char kmod_loader[64];
	struct stat s;
	pid_t pid;

	if (!extroot_prefix)
		return -1;

	sprintf(ldlib_path, "%s/lib", extroot_prefix);
	sprintf(block_path, "%s/sbin/block", extroot_prefix);

	if (stat(block_path, &s))
		return -1;

	sprintf(kmod_loader, "/sbin/kmodloader %s/etc/modules-boot.d/ %s", extroot_prefix, extroot_prefix);
	system(kmod_loader);

	pid = fork();
	if (!pid) {
		mkdir("/tmp/extroot", 0755);
		setenv("LD_LIBRARY_PATH", ldlib_path, 1);
		execl(block_path, block_path, "extroot", NULL);
		exit(-1);
	} else if (pid > 0) {
		int status;

		waitpid(pid, &status, 0);
		if (!WEXITSTATUS(status)) {
			if (find_mount("/tmp/extroot/mnt")) {
				mount("/dev/root", "/", NULL, MS_NOATIME | MS_REMOUNT | MS_RDONLY, 0);

				mkdir("/tmp/extroot/mnt/proc", 0755);
				mkdir("/tmp/extroot/mnt/dev", 0755);
				mkdir("/tmp/extroot/mnt/sys", 0755);
				mkdir("/tmp/extroot/mnt/tmp", 0755);
				mkdir("/tmp/extroot/mnt/rom", 0755);

				if (mount_move("/tmp/extroot", "", "/mnt")) {
					fprintf(stderr, "moving pivotroot failed - continue normal boot\n");
					umount("/tmp/extroot/mnt");
				} else if (pivot("/mnt", "/rom")) {
					fprintf(stderr, "switching to pivotroot failed - continue normal boot\n");
					umount("/mnt");
				} else {
					umount("/tmp/overlay");
					rmdir("/tmp/overlay");
					rmdir("/tmp/extroot/mnt");
					rmdir("/tmp/extroot");
					return 0;
				}
			} else if (find_mount("/tmp/extroot/overlay")) {
				if (mount_move("/tmp/extroot", "", "/overlay")) {
					fprintf(stderr, "moving extroot failed - continue normal boot\n");
					umount("/tmp/extroot/overlay");
				} else if (fopivot("/overlay", "/rom")) {
					fprintf(stderr, "switching to extroot failed - continue normal boot\n");
					umount("/overlay");
				} else {
					umount("/tmp/overlay");
					rmdir("/tmp/overlay");
					rmdir("/tmp/extroot/overlay");
					rmdir("/tmp/extroot");
					return 0;
				}
			}
		}
	}
	return -1;
}
