cmd_libbb/makedev.o := rsdk-linux-gcc -Wp,-MD,libbb/.makedev.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.22.1)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -Os  -Os -pipe -fno-caller-saves   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(makedev)"  -D"KBUILD_MODNAME=KBUILD_STR(makedev)" -c -o libbb/makedev.o libbb/makedev.c

deps_libbb/makedev.o := \
  libbb/makedev.c \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include-fixed/limits.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include-fixed/syslimits.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/limits.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/features.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_config.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/cdefs.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/posix1_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/local_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/linux/limits.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_local_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/posix2_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/xopen_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/stdio_lim.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/byteswap.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/byteswap.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/byteswap-common.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/endian.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/endian.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include/stdint.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/stdint.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/wchar.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/wordsize.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include/stdbool.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/unistd.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/posix_opt.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_posix_opt.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/environments.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/types.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/typesizes.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include/stddef.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/confname.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/getopt.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/sysmacros.h \

libbb/makedev.o: $(deps_libbb/makedev.o)

$(deps_libbb/makedev.o):
