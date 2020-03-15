/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 2 of the License
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 *   Copyright (C) 2012 John Crispin <blogic@openwrt.org> 
 */

#include <stdio.h>
#include <stdlib.h>
#define __USE_GNU
#include <string.h>
#include <regex.h>
#include <glob.h>

#include <libubox/list.h>
#include <libubox/blobmsg_json.h>
#include "libubus.h"

struct initd {
	struct list_head list;

	char *name;
	char *exec;
	char *desc;
	char *tpl;
	char **deps;
	int start;
	int stop;
};

static LIST_HEAD(initds);
static regex_t pat_provides, pat_require, pat_start, pat_stop, pat_desc, pat_exec, pat_tpl;
static struct ubus_context *ctx;
static struct blob_buf b;
static uint32_t service;

static void initd_free(struct initd *i)
{
	if (i->name)
		free(i->name);
	if (i->exec)
		free(i->exec);
	if (i->desc)
		free(i->desc);
	if (i->tpl)
		free(i->tpl);
}

static int initd_parse(const char *file)
{
	FILE *fp;
	struct initd *i;
	regmatch_t matches[2];
	char buffer[1024];
	ssize_t len;

	fp = fopen(file, "r");
	if (!fp) {
		fprintf(stderr, "failed to open %s\n", file);
		return -1;
	}
	len = fread(buffer, 1, sizeof(buffer) - 1, fp);
	fclose(fp);

	if (len < 1) {
		fprintf(stderr, "failed to read from %s\n", file);
		return -1;
	}
	buffer[len] = '\0';

	i = malloc(sizeof(struct initd));
	if (!i) {
		fprintf(stderr, "failed to alloc initd struct\n");
		return -1;
	}
	memset(i, 0, sizeof(*i));

	if (!regexec(&pat_provides, buffer, 2, matches, 0))
		i->name = strndup(buffer + matches[1].rm_so, (size_t)matches[1].rm_eo - matches[1].rm_so);
	if (!regexec(&pat_exec, buffer, 2, matches, 0))
		i->exec = strndup(buffer + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
	if (!regexec(&pat_desc, buffer, 2, matches, 0))
		i->desc = strndup(buffer + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
	if (!regexec(&pat_tpl, buffer, 2, matches, 0))
		i->tpl = strndup(buffer + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
	if (!regexec(&pat_start, buffer, 2, matches, 0))
		i->start += atoi(buffer + matches[1].rm_so);
	if (!regexec(&pat_stop, buffer, 2, matches, 0))
		i->stop += atoi(buffer + matches[1].rm_so);

	if (i->name && i->exec)
		list_add(&i->list, &initds);
	else
		initd_free(i);

	return 0;
}

static void initd_init(void)
{
	int gl_flags = GLOB_NOESCAPE | GLOB_MARK;
	glob_t gl;

	regcomp(&pat_provides, "# Provides:[ \t]*([a-zA-Z0-9]+)", REG_EXTENDED);
	regcomp(&pat_require, "# Required-Start:[ \t]*([a-zA-Z0-9 ]+)", REG_EXTENDED);
	regcomp(&pat_start, "# Default-Start:[ \t]*([0-9])", REG_EXTENDED);
	regcomp(&pat_stop, "# Default-Stop:[ \t]*([0-9])", REG_EXTENDED);
	regcomp(&pat_desc, "# Description:[ \t]*([a-zA-Z0-9 ]+)", REG_EXTENDED);
	regcomp(&pat_exec, "# X-Exec:[ \t]*([a-zA-Z0-9/ ]+)", REG_EXTENDED);
	regcomp(&pat_tpl, "# X-Template:[ \t]*([a-zA-Z0-9/.]+)", REG_EXTENDED);

	if (glob("/etc/rc.d/P*", gl_flags, NULL, &gl) >= 0) {
		int j;
		for (j = 0; j < gl.gl_pathc; j++)
			initd_parse(gl.gl_pathv[j]);
	}
	globfree(&gl);

	regfree(&pat_provides);
	regfree(&pat_require);
	regfree(&pat_start);
	regfree(&pat_stop);
	regfree(&pat_desc);
	regfree(&pat_exec);
	regfree(&pat_tpl);
}

static int init_services(void)
{
	struct initd *i;
	void *instances, *instance, *command;

	list_for_each_entry(i, &initds, list) {
		char *t;

		blob_buf_init(&b, 0);
		blobmsg_add_string(&b, "name", i->name);
		instances = blobmsg_open_table(&b, "instances");
		instance = blobmsg_open_table(&b, "instance");
		command = blobmsg_open_array(&b, "command");
		t = strtok(i->exec, " ");
		while (t) {
			blobmsg_add_string(&b, NULL, t);
			t = strtok(NULL, " ");
		}
		blobmsg_close_array(&b, command);
		blobmsg_close_table(&b, instance);
		blobmsg_close_table(&b, instances);
		ubus_invoke(ctx, service, "add", b.head, NULL, 0, 1000);
	}

	return 0;
}

int main(int argc, char **argv)
{
	int ret;

	initd_init();

	if (list_empty(&initds))
		return 0;

	ctx = ubus_connect(NULL);
	if (!ctx) {
		fprintf(stderr, "Failed to connect to ubus\n");
		return -1;
	}

	ret = ubus_lookup_id(ctx, "service", &service);
	if (ret) {
		fprintf(stderr, "Failed to find service object: %s\n", ubus_strerror(ret));
		return -1;
	}

	return init_services();
}
