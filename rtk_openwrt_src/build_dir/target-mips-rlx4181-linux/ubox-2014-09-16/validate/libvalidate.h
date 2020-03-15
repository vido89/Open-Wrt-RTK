#ifndef _VALIDATE_H__
#define _VALIDATE_H__

enum dt_type {
	DT_INVALID,
	DT_BOOL,
	DT_NUMBER,
	DT_STRING
};

enum dt_type dt_parse(const char *code, const char *value);

#endif
