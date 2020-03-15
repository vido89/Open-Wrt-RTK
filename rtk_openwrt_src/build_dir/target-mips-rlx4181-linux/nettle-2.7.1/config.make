# Makefile settings shared between Makefiles.

CC = rsdk-linux-gcc
CXX = rsdk-linux-g++
CFLAGS = -Os -pipe -fno-caller-saves -fpic  -ggdb3 -Wno-pointer-sign -Wall -W   -Wmissing-prototypes -Wmissing-declarations -Wstrict-prototypes   -Wpointer-arith -Wbad-function-cast -Wnested-externs
CXXFLAGS = -Os -pipe -fno-caller-saves -fpic 
CCPIC = -fpic
CCPIC_MAYBE = -fpic
CPPFLAGS = -I/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/target-mips-rlx4181-linux/usr/include -I/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/target-mips-rlx4181-linux/include -I/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001//include 
DEFS = -DHAVE_CONFIG_H
LDFLAGS = -L/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/target-mips-rlx4181-linux/usr/lib -L/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/target-mips-rlx4181-linux/lib -L/home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001//lib 
LIBS = -lgmp 
LIBOBJS =  ${LIBOBJDIR}memxor$U.o
EMULATOR = 
NM = rsdk-linux-nm

OBJEXT = o
EXEEXT = 

CC_FOR_BUILD = cc
EXEEXT_FOR_BUILD = 

DEP_FLAGS = -MT $@ -MD -MP -MF $@.d
DEP_PROCESS = true

PACKAGE_BUGREPORT = nettle-bugs@lists.lysator.liu.se
PACKAGE_NAME = nettle
PACKAGE_STRING = nettle 2.7.1
PACKAGE_TARNAME = nettle
PACKAGE_VERSION = 2.7.1

SHLIBCFLAGS = -fpic

LIBNETTLE_MAJOR = 4
LIBNETTLE_MINOR = 7
LIBNETTLE_SONAME = $(LIBNETTLE_FORLINK).$(LIBNETTLE_MAJOR)
LIBNETTLE_FILE = $(LIBNETTLE_SONAME).$(LIBNETTLE_MINOR)
LIBNETTLE_FILE_SRC = $(LIBNETTLE_FORLINK)
LIBNETTLE_FORLINK = libnettle.so
LIBNETTLE_LIBS = 
LIBNETTLE_LINK = $(CC) $(CFLAGS) $(LDFLAGS) -shared -Wl,-soname=$(LIBNETTLE_SONAME)

LIBHOGWEED_MAJOR = 2
LIBHOGWEED_MINOR = 5
LIBHOGWEED_SONAME = $(LIBHOGWEED_FORLINK).$(LIBHOGWEED_MAJOR)
LIBHOGWEED_FILE = $(LIBHOGWEED_SONAME).$(LIBHOGWEED_MINOR)
LIBHOGWEED_FILE_SRC = $(LIBHOGWEED_FORLINK)
LIBHOGWEED_FORLINK = libhogweed.so
LIBHOGWEED_LIBS = -lnettle $(GMP_LIBS)
LIBHOGWEED_LINK = $(CC) $(CFLAGS) $(LDFLAGS) -L. -shared -Wl,-soname=$(LIBHOGWEED_SONAME)

GMP_NUMB_BITS = 32

AR = rsdk-linux-ar
ARFLAGS = cru
AUTOCONF = autoconf
AUTOHEADER = autoheader
M4 = /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/host/bin/m4
MAKEINFO = makeinfo
RANLIB = rsdk-linux-ranlib
LN_S = ln -s

prefix	=	/usr
exec_prefix =	/usr
datarootdir =	${prefix}/share
bindir =	/usr/bin
libdir =	${exec_prefix}/lib
includedir =	${prefix}/include
infodir =	/usr/info

# PRE_CPPFLAGS and PRE_LDFLAGS lets each Makefile.in prepend its own
# flags before CPPFLAGS and LDFLAGS.

COMPILE = $(CC) $(PRE_CPPFLAGS) $(CPPFLAGS) $(DEFS) $(CFLAGS) $(CCPIC) $(DEP_FLAGS)
COMPILE_CXX = $(CXX) $(PRE_CPPFLAGS) $(CPPFLAGS) $(DEFS) $(CXXFLAGS) $(CCPIC) $(DEP_FLAGS)
LINK = $(CC) $(CFLAGS) $(PRE_LDFLAGS) $(LDFLAGS)
LINK_CXX = $(CXX) $(CXXFLAGS) $(PRE_LDFLAGS) $(LDFLAGS)

# Default rule. Must be here, since config.make is included before the
# usual targets.
default: all

# For some reason the suffixes list must be set before the rules.
# Otherwise BSD make won't build binaries e.g. aesdata. On the other
# hand, AIX make has the opposite idiosyncrasies to BSD, and the AIX
# compile was broken when .SUFFIXES was moved here from Makefile.in.

.SUFFIXES:
.SUFFIXES: .asm .s .c .$(OBJEXT) .p$(OBJEXT) .html .dvi .info .exe .pdf .ps .texinfo

# Disable builtin rule
%$(EXEEXT) : %.c
.c:

# Keep object files
.PRECIOUS: %.o

.PHONY: all check install uninstall clean distclean mostlyclean maintainer-clean distdir \
	all-here check-here install-here clean-here distclean-here mostlyclean-here \
	maintainer-clean-here distdir-here \
	install-shared install-info install-headers \
	uninstall-shared uninstall-info uninstall-headers \
	dist distcleancheck
