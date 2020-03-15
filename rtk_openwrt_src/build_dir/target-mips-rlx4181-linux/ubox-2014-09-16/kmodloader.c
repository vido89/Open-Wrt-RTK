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

#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/mman.h>
#include <sys/utsname.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <values.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>
#include <libgen.h>
#include <glob.h>
#include <elf.h>

#include <libubox/avl.h>
#include <libubox/avl-cmp.h>
#include <libubox/utils.h>

#define DEF_MOD_PATH "/lib/modules/%s/"

#define LOG(fmt, ...) do { \
	syslog(LOG_INFO, fmt, ## __VA_ARGS__); \
	printf("kmod: "fmt, ## __VA_ARGS__); \
	} while (0)


enum {
	SCANNED,
	PROBE,
	LOADED,
};

struct module {
	struct avl_node avl;

	char *name;
	char *depends;
	char *opts;

	int size;
	int usage;
	int state;
	int error;
};

static struct avl_tree modules;
static char *prefix = "";

static struct module *find_module(const char *name)
{
	struct module *m;
	return avl_find_element(&modules, name, m, avl);
}

static void free_modules(void)
{
	struct module *m, *tmp;

	avl_remove_all_elements(&modules, m, avl, tmp)
		free(m);
}

static char* get_module_path(char *name)
{
	static char path[256];
	struct utsname ver;
	struct stat s;

	if (!stat(name, &s))
		return name;

	uname(&ver);
	snprintf(path, 256, "%s" DEF_MOD_PATH "%s.ko", prefix, ver.release, name);

	if (!stat(path, &s))
		return path;

	return NULL;
}

static char* get_module_name(char *path)
{
	static char name[32];
	char *t;

	strncpy(name, basename(path), sizeof(name));

	t = strstr(name, ".ko");
	if (t)
		*t = '\0';

	return name;
}

static int elf64_find_section(char *map, const char *section, unsigned int *offset, unsigned int *size)
{
	const char *secnames;
	Elf64_Ehdr *e;
	Elf64_Shdr *sh;
	int i;

	e = (Elf64_Ehdr *) map;
	sh = (Elf64_Shdr *) (map + e->e_shoff);

	secnames = map + sh[e->e_shstrndx].sh_offset;
	for (i = 0; i < e->e_shnum; i++) {
		if (!strcmp(section, secnames + sh[i].sh_name)) {
			*size = sh[i].sh_size;
			*offset = sh[i].sh_offset;
			return 0;
		}
	}

	return -1;
}

static int elf32_find_section(char *map, const char *section, unsigned int *offset, unsigned int *size)
{
	const char *secnames;
	Elf32_Ehdr *e;
	Elf32_Shdr *sh;
	int i;

	e = (Elf32_Ehdr *) map;
	sh = (Elf32_Shdr *) (map + e->e_shoff);

	secnames = map + sh[e->e_shstrndx].sh_offset;
	for (i = 0; i < e->e_shnum; i++) {
		if (!strcmp(section, secnames + sh[i].sh_name)) {
			*size = sh[i].sh_size;
			*offset = sh[i].sh_offset;
			return 0;
		}
	}

	return -1;
}

static int elf_find_section(char *map, const char *section, unsigned int *offset, unsigned int *size)
{
	int clazz = map[EI_CLASS];

	if (clazz == ELFCLASS32)
		return elf32_find_section(map, section, offset, size);
	else if (clazz == ELFCLASS64)
		return elf64_find_section(map, section, offset, size);

	LOG("unknown elf format %d\n", clazz);

	return -1;
}

static struct module *
alloc_module(const char *name, const char *depends, int size)
{
	struct module *m;
	char *_name, *_dep;

	m = calloc_a(sizeof(*m),
		&_name, strlen(name) + 1,
		&_dep, depends ? strlen(depends) + 2 : 0);
	if (!m)
		return NULL;

	m->avl.key = m->name = strcpy(_name, name);
	m->opts = 0;

	if (depends) {
		m->depends = strcpy(_dep, depends);
		while (*_dep) {
			if (*_dep == ',')
				*_dep = '\0';
			_dep++;
		}
	}

	m->size = size;
	avl_insert(&modules, &m->avl);

	return m;
}

static int scan_loaded_modules(void)
{
	size_t buf_len = 0;
	char *buf = NULL;
	FILE *fp;

	fp = fopen("/proc/modules", "r");
	if (!fp) {
		LOG("failed to open /proc/modules\n");
		return -1;
	}

	while (getline(&buf, &buf_len, fp) > 0) {
		struct module m;
		struct module *n;

		m.name = strtok(buf, " ");
		m.size = atoi(strtok(NULL, " "));
		m.usage = atoi(strtok(NULL, " "));
		m.depends = strtok(NULL, " ");

		if (!m.name || !m.depends)
			continue;

		n = alloc_module(m.name, m.depends, m.size);
		n->usage = m.usage;
		n->state = LOADED;
	}
	free(buf);
	fclose(fp);

	return 0;
}

static struct module* get_module_info(const char *module, const char *name)
{
	int fd = open(module, O_RDONLY);
	unsigned int offset, size;
	char *map, *strings, *dep = NULL;
	struct module *m;
	struct stat s;

	if (!fd) {
		LOG("failed to open %s\n", module);
		return NULL;
	}

	if (fstat(fd, &s) == -1) {
		LOG("failed to stat %s\n", module);
		return NULL;
	}

	map = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED) {
		LOG("failed to mmap %s\n", module);
		return NULL;
	}

	if (elf_find_section(map, ".modinfo", &offset, &size)) {
		LOG("failed to load the .modinfo section from %s\n", module);
		return NULL;
	}

	strings = map + offset;
	while (strings && (strings < map + offset + size)) {
		char *sep;
		int len;

		while (!strings[0])
			strings++;
		sep = strstr(strings, "=");
		if (!sep)
			break;
		len = sep - strings;
		sep++;
		if (!strncmp(strings, "depends=", len + 1))
			dep = sep;
		strings = &sep[strlen(sep)];
	}

	m = alloc_module(name, dep, s.st_size);
	if (!m)
		return NULL;

	m->state = SCANNED;

	return m;
}

static int scan_module_folder(void)
{
	int gl_flags = GLOB_NOESCAPE | GLOB_MARK;
	struct utsname ver;
	char *path;
	glob_t gl;
	int j;

	uname(&ver);
	path = alloca(sizeof(DEF_MOD_PATH "*.ko") + strlen(prefix) + strlen(ver.release) + 1);
	sprintf(path, "%s" DEF_MOD_PATH "*.ko", prefix, ver.release);

	if (glob(path, gl_flags, NULL, &gl) < 0)
		return -1;

	for (j = 0; j < gl.gl_pathc; j++) {
		char *name = get_module_name(gl.gl_pathv[j]);
		struct module *m;

		if (!name)
			continue;

		m = find_module(name);
		if (!m)
			get_module_info(gl.gl_pathv[j], name);
	}

	globfree(&gl);

	return 0;
}

static int print_modinfo(char *module)
{
	int fd = open(module, O_RDONLY);
	unsigned int offset, size;
	struct stat s;
	char *map, *strings;

	if (!fd) {
		LOG("failed to open %s\n", module);
		return -1;
	}

	if (fstat(fd, &s) == -1) {
		LOG("failed to stat %s\n", module);
		return -1;
	}

	map = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED) {
		LOG("failed to mmap %s\n", module);
		return -1;
	}

	if (elf_find_section(map, ".modinfo", &offset, &size)) {
		LOG("failed to load the .modinfo section from %s\n", module);
		return -1;
	}

	strings = map + offset;
	printf("module:\t\t%s\n", module);
	while (strings && (strings < map + offset + size)) {
		char *dup = NULL;
		char *sep;

		while (!strings[0])
			strings++;
		sep = strstr(strings, "=");
		if (!sep)
			break;
		dup = strndup(strings, sep - strings);
		sep++;
		if (strncmp(strings, "parm", 4)) {
			if (strlen(dup) < 7)
				printf("%s:\t\t%s\n",  dup, sep);
			else
				printf("%s:\t%s\n",  dup, sep);
		}
		strings = &sep[strlen(sep)];
		if (dup)
			free(dup);
	}

	return 0;
}

static int deps_available(struct module *m, int verbose)
{
	char *dep;
	int err = 0;

	if (!strcmp(m->depends, "-") || !strcmp(m->depends, ""))
		return 0;

	dep = m->depends;

	while (*dep) {
		m = find_module(dep);

		if (verbose && !m)
			LOG("missing dependency %s\n", dep);
		if (verbose && m && (m->state != LOADED))
			LOG("dependency not loaded %s\n", dep);
		if (!m || (m->state != LOADED))
			err++;
		dep += strlen(dep) + 1;
	}

	return err;
}

static int insert_module(char *path, const char *options)
{
	void *data = 0;
	struct stat s;
	int fd, ret = -1;

	if (stat(path, &s)) {
		LOG("missing module %s\n", path);
		return ret;
	}

	fd = open(path, O_RDONLY);
	if (!fd) {
		LOG("cannot open %s\n", path);
		return ret;
	}

	data = malloc(s.st_size);
	if (read(fd, data, s.st_size) == s.st_size)
		ret = syscall(__NR_init_module, data, (unsigned long) s.st_size, options);
	else
		LOG("failed to read full module %s\n", path);

	close(fd);
	free(data);

	return ret;
}

static void load_moddeps(struct module *_m)
{
	char *dep;
	struct module *m;

	if (!strcmp(_m->depends, "-") || !strcmp(_m->depends, ""))
		return;

	dep = _m->depends;

	while (*dep) {
		m = find_module(dep);

		if (!m)
			LOG("failed to find dependency %s\n", dep);
		if (m && (m->state != LOADED)) {
			m->state = PROBE;
			load_moddeps(m);
		}

		dep = dep + strlen(dep) + 1;
	}
}

static int iterations = 0;
static int load_modprobe(void)
{
	int loaded, todo;
	struct module *m;

	avl_for_each_element(&modules, m, avl)
		if (m->state == PROBE)
			load_moddeps(m);

	do {
		loaded = 0;
		todo = 0;
		avl_for_each_element(&modules, m, avl) {
			if ((m->state == PROBE) && (!deps_available(m, 0))) {
				if (!insert_module(get_module_path(m->name), (m->opts) ? (m->opts) : (""))) {
					m->state = LOADED;
					m->error = 0;
					loaded++;
					continue;
				}
				m->error = 1;
			}

			if ((m->state == PROBE) || m->error)
				todo++;
		}
		iterations++;
	} while (loaded);

	return todo;
}

static int print_insmod_usage(void)
{
	LOG("Usage:\n\tinsmod filename [args]\n");

	return -1;
}

static int print_usage(char *arg)
{
	LOG("Usage:\n\t%s module\n", arg);

	return -1;
}

static int main_insmod(int argc, char **argv)
{
	char *name, *cur, *options;
	int i, ret, len;

	if (argc < 2)
		return print_insmod_usage();

	name = get_module_name(argv[1]);
	if (!name) {
		LOG("cannot find module - %s\n", argv[1]);
		return -1;
	}

	if (scan_loaded_modules())
		return -1;

	if (find_module(name)) {
		LOG("module is already loaded - %s\n", name);
		return -1;

	}

	free_modules();

	for (len = 0, i = 2; i < argc; i++)
		len += strlen(argv[i]) + 1;

	options = malloc(len);
	options[0] = 0;
	cur = options;
	for (i = 2; i < argc; i++) {
		if (options[0]) {
			*cur = ' ';
			cur++;
		}
		cur += sprintf(cur, "%s", argv[i]);
	}

	if (get_module_path(argv[1])) {
		name = argv[1];
	} else if (!get_module_path(name)) {
		fprintf(stderr, "Failed to find %s. Maybe it is a built in module ?\n", name);
		return -1;
	}

	ret = insert_module(get_module_path(name), options);
	free(options);

	if (ret)
		LOG("failed to insert %s\n", get_module_path(name));

	return ret;
}

static int main_rmmod(int argc, char **argv)
{
	struct module *m;
	char *name;
	int ret;

	if (argc != 2)
		return print_usage("rmmod");

	if (scan_loaded_modules())
		return -1;

	name = get_module_name(argv[1]);
	m = find_module(name);
	if (!m) {
		LOG("module is not loaded\n");
		return -1;
	}
	ret = syscall(__NR_delete_module, m->name, 0);

	if (ret)
		LOG("unloading the module failed\n");

	free_modules();

	return ret;
}

static int main_lsmod(int argc, char **argv)
{
	struct module *m;

	if (scan_loaded_modules())
		return -1;

	avl_for_each_element(&modules, m, avl)
		if (m->state == LOADED)
			printf("%-20s%8d%3d %s\n",
				m->name, m->size, m->usage,
				(*m->depends == '-') ? ("") : (m->depends));

	free_modules();

	return 0;
}

static int main_modinfo(int argc, char **argv)
{
	struct module *m;
	char *name;

	if (argc != 2)
		return print_usage("modinfo");

	if (scan_module_folder())
		return -1;

	name = get_module_name(argv[1]);
	m = find_module(name);
	if (!m) {
		LOG("cannot find module - %s\n", argv[1]);
		return -1;
	}

	name = get_module_path(m->name);
	if (!name) {
		LOG("cannot find path of module - %s\n", m->name);
		return -1;
	}

	print_modinfo(name);

	return 0;
}

static int main_modprobe(int argc, char **argv)
{
	struct module *m;
	char *name;

	if (argc != 2)
		return print_usage("modprobe");

	if (scan_loaded_modules())
		return -1;

	if (scan_module_folder())
		return -1;

	name = get_module_name(argv[1]);
	m = find_module(name);
	if (m && m->state == LOADED) {
		LOG("%s is already loaded\n", name);
		return -1;
	} else if (!m) {
		LOG("failed to find a module named %s\n", name);
	} else {
		int fail;

		m->state = PROBE;

		fail = load_modprobe();

		if (fail) {
			LOG("%d module%s could not be probed\n",
					fail, (fail == 1) ? ("") : ("s"));

			avl_for_each_element(&modules, m, avl)
				if ((m->state == PROBE) || m->error)
					LOG("- %s\n", m->name);
		}
	}

	free_modules();

	return 0;
}

static int main_loader(int argc, char **argv)
{
	int gl_flags = GLOB_NOESCAPE | GLOB_MARK;
	char *dir = "/etc/modules.d/*";
	struct module *m;
	glob_t gl;
	char *path;
	int fail, j;

	if (argc > 1)
		dir = argv[1];

	if (argc > 2)
		prefix = argv[2];

	path = malloc(strlen(dir) + 2);
	strcpy(path, dir);
	strcat(path, "*");

	if (scan_loaded_modules())
		return -1;

	if (scan_module_folder())
		return -1;

	syslog(0, "kmodloader: loading kernel modules from %s\n", path);

	if (glob(path, gl_flags, NULL, &gl) < 0)
		goto out;

	for (j = 0; j < gl.gl_pathc; j++) {
		FILE *fp = fopen(gl.gl_pathv[j], "r");
		size_t mod_len = 0;
		char *mod = NULL;

		if (!fp) {
			LOG("failed to open %s\n", gl.gl_pathv[j]);
			continue;
		}

		while (getline(&mod, &mod_len, fp) > 0) {
			char *nl = strchr(mod, '\n');
			struct module *m;
			char *opts;

			if (nl)
				*nl = '\0';

			opts = strchr(mod, ' ');
			if (opts)
				*opts++ = '\0';

			m = find_module(get_module_name(mod));
			if (!m || (m->state == LOADED))
				continue;

			if (opts)
				m->opts = strdup(opts);
			m->state = PROBE;
			if (basename(gl.gl_pathv[j])[0] - '0' <= 9)
				load_modprobe();

		}
		free(mod);
		fclose(fp);
	}

	fail = load_modprobe();
	LOG("ran %d iterations\n", iterations);

	if (fail) {
		LOG("%d module%s could not be probed\n",
				fail, (fail == 1) ? ("") : ("s"));

		avl_for_each_element(&modules, m, avl)
			if ((m->state == PROBE) || (m->error))
				LOG("- %s - %d\n", m->name, deps_available(m, 1));
	}

out:
	globfree(&gl);
	free(path);

	return 0;
}

static int avl_modcmp(const void *k1, const void *k2, void *ptr)
{
	const char *s1 = k1;
	const char *s2 = k2;

	while (*s1 && ((*s1 == *s2) ||
	               ((*s1 == '_') && (*s2 == '-')) ||
	               ((*s1 == '-') && (*s2 == '_'))))
	{
		s1++;
		s2++;
	}

	return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int main(int argc, char **argv)
{
	char *exec = basename(*argv);

	avl_init(&modules, avl_modcmp, false, NULL);
	if (!strcmp(exec, "insmod"))
		return main_insmod(argc, argv);

	if (!strcmp(exec, "rmmod"))
		return main_rmmod(argc, argv);

	if (!strcmp(exec, "lsmod"))
		return main_lsmod(argc, argv);

	if (!strcmp(exec, "modinfo"))
		return main_modinfo(argc, argv);

	if (!strcmp(exec, "modprobe"))
		return main_modprobe(argc, argv);

	return main_loader(argc, argv);
}
