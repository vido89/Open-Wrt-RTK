cmd_libbb/ptr_to_globals.o := rsdk-linux-gcc -Wp,-MD,libbb/.ptr_to_globals.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.22.1)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -Os  -Os -pipe -fno-caller-saves   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(ptr_to_globals)"  -D"KBUILD_MODNAME=KBUILD_STR(ptr_to_globals)" -c -o libbb/ptr_to_globals.o libbb/ptr_to_globals.c

deps_libbb/ptr_to_globals.o := \
  libbb/ptr_to_globals.c \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/features.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_config.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/cdefs.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/linux/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm-generic/errno-base.h \

libbb/ptr_to_globals.o: $(deps_libbb/ptr_to_globals.o)

$(deps_libbb/ptr_to_globals.o):
