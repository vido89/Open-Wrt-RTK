noinst_PROGRAMS = qgen

qgen_SOURCES = common.c common.h file.c file.h first.c ql_y.y ql_l.l qgen.c \
		qgen.h second.c third.c
qgen_LDADD = 

COMPILE = @CC_FOR_BUILD@ @CFLAGS_FOR_BUILD@
LINK = @CC_FOR_BUILD@ @CFLAGS_FOR_BUILD@ -o $@

#TESTS = $(check_PROGRAMS)

EXTRA_DIST = ql_y.h ql_y.c ql_l.c
