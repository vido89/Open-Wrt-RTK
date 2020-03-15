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
#include <asm/byteorder.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mtd/mtd-user.h>

#include "libfstools.h"

#include "volume.h"

#define PATH_MAX		256

struct mtd_priv {
	int	fd;
	int	idx;
	char	*chr;
};

static struct driver mtd_driver;

static int mtd_open(const char *mtd, int block)
{
	FILE *fp;
	char dev[PATH_MAX];
	int i, ret, flags = O_RDWR | O_SYNC;

	if ((fp = fopen("/proc/mtd", "r"))) {
		while (fgets(dev, sizeof(dev), fp)) {
			if (sscanf(dev, "mtd%d:", &i) && strstr(dev, mtd)) {
				snprintf(dev, sizeof(dev), "/dev/mtd%s/%d", (block ? "block" : ""), i);
				ret = open(dev, flags);
				if (ret < 0) {
					snprintf(dev, sizeof(dev), "/dev/mtd%s%d", (block ? "block" : ""), i);
					ret = open(dev, flags);
				}
				fclose(fp);
				return ret;
			}
		}
		fclose(fp);
	}

	return open(mtd, flags);
}

static void mtd_volume_close(struct volume *v)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;

	if (!p->fd)
		return;

	close(p->fd);
	p->fd = 0;
}

static int mtd_volume_load(struct volume *v)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;
	struct mtd_info_user mtdInfo;
	struct erase_info_user mtdLockInfo;

	if (p->fd)
		return 0;

	if (!p->chr)
		return -1;

	p->fd = mtd_open(p->chr, 0);
	if (p->fd < 0) {
		p->fd = 0;
		fprintf(stderr, "Could not open mtd device: %s\n", p->chr);
		return -1;
	}

	if (ioctl(p->fd, MEMGETINFO, &mtdInfo)) {
		mtd_volume_close(v);
		fprintf(stderr, "Could not get MTD device info from %s\n", p->chr);
		return -1;
	}

	v->size = mtdInfo.size;
	v->block_size = mtdInfo.erasesize;
	switch (mtdInfo.type) {
	case MTD_NORFLASH:
		v->type = NORFLASH;
		break;
	case MTD_NANDFLASH:
		v->type = NANDFLASH;
		break;
	case MTD_UBIVOLUME:
		v->type = UBIVOLUME;
		break;
	default:
		v->type = UNKNOWN_TYPE;
		break;
	}

	mtdLockInfo.start = 0;
	mtdLockInfo.length = v->size;
	ioctl(p->fd, MEMUNLOCK, &mtdLockInfo);

	return 0;
}

static char* mtd_find_index(char *name)
{
	FILE *fp = fopen("/proc/mtd", "r");
	static char line[256];
	char *index = NULL;

	if(!fp)
		return index;

	while (!index && fgets(line, sizeof(line), fp)) {
		char *ret;

		if ((ret = strstr(line, name)) && (ret[strlen(name)] == '"')) {
			char *eol = strstr(line, ":");

			if (!eol)
				continue;

			*eol = '\0';
			index = &line[3];
		}
	}

	fclose(fp);

	return index;
}

static int mtd_volume_find(struct volume *v, char *name)
{
	char *idx = mtd_find_index(name);
	struct mtd_priv *p;
	char buffer[32];

	if (!idx)
		return -1;

	p = calloc(1, sizeof(struct mtd_priv));
	if (!p)
		return -1;

	v->priv = p;
	v->name = strdup(name);
	v->drv = &mtd_driver;
	p->idx = atoi(idx);

	snprintf(buffer, sizeof(buffer), "/dev/mtdblock%s", idx);
	v->blk = strdup(buffer);

	snprintf(buffer, sizeof(buffer), "/dev/mtd%s", idx);
	p->chr = strdup(buffer);

	if (mtd_volume_load(v)) {
		fprintf(stderr, "reading %s failed\n", v->name);
		return -1;
	}

	return 0;
}

static int mtd_volume_identify(struct volume *v)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;
	__u32 deadc0de;
	__u16 jffs2;
	size_t sz;
	unsigned char oobbuf[64];
    __u16 *ptr = (__u16 *)oobbuf;
	struct mtd_oob_buf oob = {0, 24, oobbuf};
	

	if (mtd_volume_load(v)) {
		fprintf(stderr, "reading %s failed\n", v->name);
		return -1;
	}

	 if(v->type == NANDFLASH){
        memset(oobbuf, 0, sizeof(oobbuf));
        if (ioctl(p->fd, MEMREADOOB, &oob) != 0) {
			fprintf(stderr, "ioctl(MEMREADOOB)");
            return -1;
        }
    }
	sz = read(p->fd, &deadc0de, sizeof(deadc0de));

	if (sz != sizeof(deadc0de)) {
		fprintf(stderr, "reading %s failed: %s\n", v->name, strerror(errno));
		return -1;
	}

	if (deadc0de == __be32_to_cpu(0x4f575254))
		return FS_SNAPSHOT;

	deadc0de = __be32_to_cpu(deadc0de);
	if (deadc0de == 0xdeadc0de) {
		fprintf(stderr, "jffs2 is not ready - marker found\n");
		return FS_DEADCODE;
	}

	if(v->type == NANDFLASH)
        jffs2 = *ptr;
    else
		jffs2 = __be16_to_cpu(deadc0de >> 16);
		
	if (jffs2 == 0x1985) {
		fprintf(stderr, "jffs2 is ready\n");
		return FS_JFFS2;
	}

	if (v->type == UBIVOLUME && deadc0de == 0xffffffff) {
		fprintf(stderr, "jffs2 is ready\n");
		return FS_JFFS2;
	}

	fprintf(stderr, "No jffs2 marker was found\n");

	return FS_NONE;
}

static int mtd_volume_erase(struct volume *v, int offset, int len)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;
	struct erase_info_user eiu;
	int first_block, num_blocks;

	if (mtd_volume_load(v))
		return -1;

	if (offset % v->block_size || len % v->block_size) {
		fprintf(stderr, "mtd erase needs to be block aligned\n");
		return -1;
	}

	first_block = offset / v->block_size;
	num_blocks = len / v->block_size;
	eiu.length = v->block_size;

	for (eiu.start = first_block * v->block_size;
			eiu.start < v->size && eiu.start < (first_block + num_blocks) * v->block_size;
			eiu.start += v->block_size) {
		fprintf(stderr, "erasing %x %x\n", eiu.start, v->block_size);
		ioctl(p->fd, MEMUNLOCK, &eiu);
		if (ioctl(p->fd, MEMERASE, &eiu))
			fprintf(stderr, "Failed to erase block at 0x%x\n", eiu.start);
	}

	mtd_volume_close(v);

	return 0;
}

static int mtd_volume_erase_all(struct volume *v)
{
	mtd_volume_erase(v, 0, v->size);
	mtd_volume_close(v);

	return 0;
}

static int mtd_volume_init(struct volume *v)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;
	struct mtd_info_user mtdinfo;
	int ret;

	if (mtd_volume_load(v))
		return -1;

	ret = ioctl(p->fd, MEMGETINFO, &mtdinfo);
	if (ret) {
		fprintf(stderr, "ioctl(%d, MEMGETINFO) failed: %s\n", p->fd, strerror(errno));
	} else {
		struct erase_info_user mtdlock;

		mtdlock.start = 0;
		mtdlock.length = mtdinfo.size;
		ioctl(p->fd, MEMUNLOCK, &mtdlock);
	}

	return ret;
}

static int mtd_volume_read(struct volume *v, void *buf, int offset, int length)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;

	if (mtd_volume_load(v))
		return -1;

	if (lseek(p->fd, offset, SEEK_SET) == (off_t) -1) {
		fprintf(stderr, "lseek/read failed\n");
		return -1;
	}

	if (read(p->fd, buf, length) == -1) {
		fprintf(stderr, "read failed\n");
		return -1;
	}

	return 0;
}

static int mtd_volume_write(struct volume *v, void *buf, int offset, int length)
{
	struct mtd_priv *p = (struct mtd_priv*) v->priv;

	if (mtd_volume_load(v))
		return -1;

	if (lseek(p->fd, offset, SEEK_SET) == (off_t) -1) {
		fprintf(stderr, "lseek/write failed at offset %d\n", offset);
		perror("lseek");
		return -1;
	}

	if (write(p->fd, buf, length) == -1) {
		fprintf(stderr, "write failed\n");
		return -1;
	}

	return 0;
}

static struct driver mtd_driver = {
	.name = "mtd",
	.find = mtd_volume_find,
	.init = mtd_volume_init,
	.erase = mtd_volume_erase,
	.erase_all = mtd_volume_erase_all,
	.read = mtd_volume_read,
	.write = mtd_volume_write,
	.identify = mtd_volume_identify,
};
DRIVER(mtd_driver);
