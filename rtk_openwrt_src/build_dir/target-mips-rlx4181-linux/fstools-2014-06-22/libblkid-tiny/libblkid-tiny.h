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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <libubox/list.h>

struct blkid_idmag;
struct blkid_idmag;
struct blkid_idinfo;

struct blkid_idmag
{
	const char	*magic;
	unsigned int	len;

	long		kboff;
	unsigned int	sboff;
};


struct blkid_idinfo;

struct blkid_struct_probe
{
	const struct blkid_idinfo	*id;
	struct list_head		list;

	int	fd;
	int	err;
	char	dev[32];
	char	uuid[64];
	char	label[64];
	char	name[64];
	char	version[64];
};

struct blkid_idinfo
{
	const char	*name;
	int		usage;
	int		flags;
	int		minsz;
	int (*probefunc)(struct blkid_struct_probe *pr, const struct blkid_idmag *mag);
	struct blkid_idmag	magics[];
};

extern int probe_block(char *block, struct blkid_struct_probe *pr);
extern int mkblkdev(void);
