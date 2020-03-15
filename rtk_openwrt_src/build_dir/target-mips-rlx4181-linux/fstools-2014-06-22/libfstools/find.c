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

#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "libfstools.h"

int
find_overlay_mount(char *overlay)
{
	FILE *fp = fopen("/proc/mounts", "r");
	static char line[256];
	int ret = -1;

	if(!fp)
		return ret;

	while (ret && fgets(line, sizeof(line), fp))
		if (!strncmp(line, overlay, strlen(overlay)))
			ret = 0;

	fclose(fp);

	return ret;
}

char*
find_mount(char *mp)
{
	FILE *fp = fopen("/proc/mounts", "r");
	static char line[256];
	char *point = NULL;

	if(!fp)
		return NULL;

	while (fgets(line, sizeof(line), fp)) {
		char *s, *t = strstr(line, " ");

		if (!t) {
			fclose(fp);
			return NULL;
		}
		t++;
		s = strstr(t, " ");
		if (!s) {
			fclose(fp);
			return NULL;
		}
		*s = '\0';

		if (!strcmp(t, mp)) {
			fclose(fp);
			return t;
		}
	}

	fclose(fp);

	return point;
}

char*
find_mount_point(char *block, int mtd_only)
{
	FILE *fp = fopen("/proc/mounts", "r");
	static char line[256];
	int len = strlen(block);
	char *point = NULL;

	if(!fp)
		return NULL;

	while (fgets(line, sizeof(line), fp)) {
		if (!strncmp(line, block, len)) {
			char *p = &line[len + 1];
			char *t = strstr(p, " ");

			if (!t) {
				fclose(fp);
				return NULL;
			}

			*t = '\0';
			t++;

			if (mtd_only &&
			    strncmp(t, "jffs2", 5) &&
			    strncmp(t, "ubifs", 5)) {
				fclose(fp);
				fprintf(stderr, "block is mounted with wrong fs\n");
				return NULL;
			}
			point = p;

			break;
		}
	}

	fclose(fp);

	return point;
}

int
find_filesystem(char *fs)
{
	FILE *fp = fopen("/proc/filesystems", "r");
	static char line[256];
	int ret = -1;

	if (!fp) {
		fprintf(stderr, "opening /proc/filesystems failed: %s\n", strerror(errno));
		goto out;
	}

	while (ret && fgets(line, sizeof(line), fp))
		if (strstr(line, fs))
			ret = 0;

	fclose(fp);

out:
	return ret;
}
