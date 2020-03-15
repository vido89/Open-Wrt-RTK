#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include <arpa/inet.h>
#include <netinet/ether.h>
#include <sys/stat.h>

#include <uci.h>

#include "libvalidate.h"

static void
print_usage(char *argv)
{
	fprintf(stderr, "%s <datatype> <value>\t- validate a value against a type\n", argv);
	fprintf(stderr, "%s <package> <section_type> <section_name> 'option:datatype:default' 'option:datatype:default' ...\n", argv);
}

static const char *
bool_to_num(const char *val)
{
	if (!strcmp(val, "0") || !strcmp(val, "off") || !strcmp(val, "false") || !strcmp(val, "no") || !strcmp(val, "disabled"))
		return "0";
	if (!strcmp(val, "1") || !strcmp(val, "on") || !strcmp(val, "true") || !strcmp(val, "yes") || !strcmp(val, "enabled"))
		return "1";

	return "";
}

static bool
parse_tuple(char *tuple, char **option, char **expr, char **def)
{
	char *p;
	bool esc;

	for (esc = false, p = *option = tuple, *expr = NULL, *def = NULL; *p; p++)
	{
		if (!esc && *p == '\\')
		{
			esc = true;
			continue;
		}

		if (!esc && *p == ':')
		{
			*p++ = 0;

			if (!*expr)
				*expr = p;
			else if (!*def)
				*def = p;
			else
				break;
		}

		esc = false;
	}

	return (*expr != NULL);
}

static void
escape_value(enum dt_type type, const char *val)
{
	const char *p;

	switch(type)
	{
	case DT_BOOL:
		printf("%s", bool_to_num(val));
		break;

	case DT_STRING:
		printf("'");

		for (p = val; *p; p++)
			if (*p == '\'')
				printf("'\"'\"'");
			else
				printf("%c", *p);

		printf("'");
		break;

	default:
		printf("%s", val);
		break;
	}
}

static void
export_value(enum dt_type type, const char *name, const char *val)
{
	if ((type == DT_INVALID) || !val || !*val)
	{
		printf("unset -v %s; ", name);
		return;
	}

	printf("%s=", name);
	escape_value(type, val);
	printf("; ");
}

static int
validate_value(struct uci_ptr *ptr, const char *expr, const char *def)
{
	int i = 0;
	bool empty = true, first = true;
	enum dt_type type = DT_INVALID;
	struct uci_element *e;
	struct uci_option *opt = ptr->o;

	if (opt->type == UCI_TYPE_LIST)
	{
		uci_foreach_element(&opt->v.list, e)
		{
			if (!e->name || !*e->name)
				continue;

			empty = false;
			break;
		}

		if (empty)
		{
			export_value(DT_STRING, ptr->option, def);
			return 0;
		}

		uci_foreach_element(&opt->v.list, e)
		{
			if (!e->name || !*e->name)
				continue;

			if (first)
				printf("%s=", ptr->option);
			else
				printf("\\ ");

			first = false;
			type = dt_parse(expr, e->name);

			if (type != DT_INVALID)
				escape_value(type, e->name);

			fprintf(stderr, "%s.%s.%s[%u]=%s validates as %s with %s\n",
			        ptr->package, ptr->section, ptr->option, i++, e->name,
			        expr, type ? "true" : "false");
		}

		printf("; ");
	}
	else
	{
		if (!opt->v.string || !*opt->v.string)
		{
			export_value(DT_STRING, ptr->option, def);
			return 0;
		}

		type = dt_parse(expr, opt->v.string);
		export_value(type, ptr->option, opt->v.string);

		fprintf(stderr, "%s.%s.%s=%s validates as %s with %s\n",
				ptr->package, ptr->section, ptr->option, opt->v.string,
		        expr, type ? "true" : "false");
	}
	return type ? 0 : -1;
}

static int
validate_option(struct uci_context *ctx, char *package, char *section, char *option)
{
	char *opt, *expr, *def;
	struct uci_ptr ptr = { 0 };

	if (!parse_tuple(option, &opt, &expr, &def))
	{
		fprintf(stderr, "%s is not a valid option\n", option);
		return -1;
	}

	ptr.package = package;
	ptr.section = section;
	ptr.option = opt;

	if (uci_lookup_ptr(ctx, &ptr, NULL, false) ||
	    !(ptr.flags & UCI_LOOKUP_COMPLETE) ||
	    (ptr.last->type != UCI_TYPE_OPTION))
	{
		export_value(DT_STRING, opt, def);
		return 0;
	}

	return validate_value(&ptr, expr, def);
}

int
main(int argc, char **argv)
{
	struct uci_context *ctx;
	struct uci_package *package;
	char *opt, *expr, *def;
	int len = argc - 4;
	enum dt_type rv;
	int i, rc;

	if (argc == 3) {
		rv = dt_parse(argv[1], argv[2]);
		fprintf(stderr, "%s - %s = %s\n", argv[1], argv[2], rv ? "true" : "false");
		return rv ? 0 : 1;
	} else if (argc < 5) {
		print_usage(*argv);
		return -1;
	}

	if (*argv[3] == '\0') {
		printf("json_add_object; ");
		printf("json_add_string \"package\" \"%s\"; ", argv[1]);
		printf("json_add_string \"type\" \"%s\"; ", argv[2]);
		printf("json_add_object \"data\"; ");

		for (i = 0; i < len; i++) {
			if (!parse_tuple(argv[4 + i], &opt, &expr, &def))
				continue;

			printf("json_add_string \"%s\" \"%s\"; ", opt, expr);
		}

		printf("json_close_object; ");
		printf("json_close_object; ");

		return 0;
	}

	ctx = uci_alloc_context();
	if (!ctx)
		return -1;

	if (uci_load(ctx, argv[1], &package))
		return -1;

	rc = 0;
	for (i = 0; i < len; i++) {
		if (validate_option(ctx, argv[1], argv[3], argv[4 + i])) {
			rc = -1;
		}
	}

	return rc;
}
