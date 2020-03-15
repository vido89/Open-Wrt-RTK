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

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <libubox/blobmsg_json.h>

#define CONFIG_FILE	"/etc/boards.json"
#define MODEL_FILE	"/proc/devicetree/model"
#define CPU_INFO	"/proc/cpuinfo"

enum {
	BOARD_ID,
	__BOARD_MAX
};

static struct blob_buf b;

static const struct blobmsg_policy board_policy[__BOARD_MAX] = {
	[BOARD_ID] = { .name = "id", .type = BLOBMSG_TYPE_STRING },
};

static char* detect_mips_machine(void)
{
	FILE *fp;
	static char line[64];
	char *ret = NULL;

	fp = fopen(CPU_INFO, "r");
	if (!fp) {
		perror("fopen");
		return NULL;
	}

	while (fgets(line, sizeof(line), fp)) {
		if (!strncmp(line, "machine", 7)) {
			char *machine = strstr(line, ": ");

			if (!machine)
				continue;

			machine[strlen(machine) - 1] = '\0';

			ret = &machine[2];
			break;
		}
	}

	fclose(fp);

	return ret;
}

static char* detect_devicetree_model(void)
{
	FILE *fp;
	static char line[64];
	char *ret = NULL;
	struct stat s;

	if (stat(MODEL_FILE, &s) || !S_ISREG(s.st_mode))
		return NULL;

	fp = fopen(MODEL_FILE, "r");
	if (!fp) {
		perror("fopen");
		return NULL;
	}

	if (!fgets(line, sizeof(line), fp))
		ret = line;

	fclose(fp);

	return ret;
}

static char* board_id(struct blob_attr *msg)
{
	struct blob_attr *tb[__BOARD_MAX];

	blobmsg_parse(board_policy, __BOARD_MAX, tb, blobmsg_data(msg), blobmsg_data_len(msg));
	if (tb[BOARD_ID])
		return blobmsg_data(tb[BOARD_ID]);

	return NULL;
}

static void write_file(char *file, char *val)
{
	FILE *fp;

	fp = fopen(file, "w");
	if (fp) {
		fprintf(fp, val);
		fclose(fp);
	} else {
		perror("fopen");
	}

}

static int set_board(char *board, char *boardid)
{
	if (!boardid) {
		fprintf(stderr, "failed to detect board %s\n", board);
		return -1;
	}
	printf("detected %s - %s\n", board, boardid);

	mkdir("/tmp/sysinfo", 0755);

	write_file("/tmp/sysinfo/model", board);
	write_file("/tmp/sysinfo/board_name", boardid);

	return 0;
}

static int load_json(char *file)
{
	struct stat s;
	int fd;
	char *buf;

	if (stat(file, &s) || !S_ISREG(s.st_mode)) {
		fprintf(stderr, "failed to open %s\n", file);
		return -1;
	}

	buf = malloc(s.st_size + 1);
	if (!buf) {
		perror("malloc");
		return -1;
	}

	fd = open(file, O_RDONLY);
	if (!fd) {
		perror("open");
		return -1;
	}

	if (read(fd, buf, s.st_size) != s.st_size) {
		fprintf(stderr, "failed to read %s - %d bytes\n", file, (int)s.st_size);
		close(fd);
		return -1;
	}
	close(fd);
	buf[s.st_size] = '\0';

	blob_buf_init(&b, 0);
	if (!blobmsg_add_json_from_string(&b, buf)) {
		fprintf(stderr, "Failed to read json\n");
		return - 1;
	}
	free(buf);

	return 0;
}

int main(int argc, char **argv)
{
	struct blob_attr *cur;
	char *board;
	int rem;

	board = detect_mips_machine();
	if (!board)
		detect_devicetree_model();
	if (!board) {
		fprintf(stderr, "failed to detect board\n");
		return -1;
	}

	if (load_json(CONFIG_FILE))
		return -1;

	blob_for_each_attr(cur, b.head, rem) {
		if (blobmsg_type(cur) != BLOBMSG_TYPE_TABLE)
			continue;
		if (!strcmp(blobmsg_name(cur), board)) {
			char *id = board_id(cur);

			if (id)
				return set_board(board, id);
			}
	}

	fprintf(stderr, "failed to identify %s\n", board);

	return -1;
}
