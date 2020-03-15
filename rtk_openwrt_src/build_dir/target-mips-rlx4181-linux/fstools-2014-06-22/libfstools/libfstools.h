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

#ifndef _FS_STATE_H__
#define _FS_STATE_H__

#include <libubox/list.h>
#include <libubox/blob.h>

enum {
	FS_NONE,
	FS_SNAPSHOT,
	FS_JFFS2,
	FS_DEADCODE,
	FS_UBIFS,
};

extern char const *extroot_prefix;
extern int mount_extroot(void);
extern int mount_snapshot(void);
extern int mount_overlay(void);

extern int mount_move(char *oldroot, char *newroot, char *dir);
extern int pivot(char *new, char *old);
extern int fopivot(char *rw_root, char *ro_root);
extern int ramoverlay(void);

extern int find_overlay_mount(char *overlay);
extern char* find_mount(char *mp);
extern char* find_mount_point(char *block, int mtd_only);
extern int find_filesystem(char *fs);
extern int find_mtd_block(char *name, char *part, int plen);
extern int find_mtd_char(char *name, char *part, int plen);

extern int jffs2_ready(char *mtd);
extern int jffs2_switch(int argc, char **argv);

extern int handle_whiteout(const char *dir);
extern void foreachdir(const char *dir, int (*cb)(const char*));

#endif
