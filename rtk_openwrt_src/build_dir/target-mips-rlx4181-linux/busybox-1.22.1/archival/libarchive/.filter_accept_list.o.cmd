cmd_archival/libarchive/filter_accept_list.o := rsdk-linux-gcc -Wp,-MD,archival/libarchive/.filter_accept_list.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.22.1)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -Os  -Os -pipe -fno-caller-saves   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(filter_accept_list)"  -D"KBUILD_MODNAME=KBUILD_STR(filter_accept_list)" -c -o archival/libarchive/filter_accept_list.o archival/libarchive/filter_accept_list.c

deps_archival/libarchive/filter_accept_list.o := \
  archival/libarchive/filter_accept_list.c \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/seamless/xz.h) \
    $(wildcard include/config/feature/seamless/lzma.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/getopt/long.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/printf.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/kill.h) \
    $(wildcard include/config/chown.h) \
    $(wildcard include/config/ls.h) \
    $(wildcard include/config/xxx.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/desktop.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/feature/adduser/to/group.h) \
    $(wildcard include/config/feature/del/user/from/group.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/editing/save/on/exit.h) \
    $(wildcard include/config/pmap.h) \
    $(wildcard include/config/feature/show/threads.h) \
    $(wildcard include/config/feature/ps/additional/columns.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/unicode/support.h) \
    $(wildcard include/config/feature/mtab/support.h) \
    $(wildcard include/config/feature/clean/up.h) \
    $(wildcard include/config/feature/devfs.h) \
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
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/ctype.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_touplow.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/dirent.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/dirent.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/linux/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/errno.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm-generic/errno-base.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/syscall.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sysnum.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/fcntl.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/fcntl.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sgidefs.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/types.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/time.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/select.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/select.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sigset.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/time.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/sysmacros.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/pthreadtypes.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sched.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uio.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/stat.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/stat.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/inttypes.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/netdb.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/netinet/in.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/socket.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/uio.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/socket.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/socket_type.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sockaddr.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/socket.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/sockios.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/ioctl.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm-generic/ioctl.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/in.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/rpc/netdb.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/siginfo.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/netdb.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/setjmp.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/setjmp.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/signal.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/signum.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sigaction.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sigcontext.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sigstack.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/ucontext.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/sigthread.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/stdio.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_stdio.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/wchar.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/include/stdarg.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/stdlib.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/waitflags.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/waitstatus.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/alloca.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/string.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/libgen.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/poll.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/poll.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/poll.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/ioctl.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/ioctls.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/ioctls.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/ioctl-types.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/ttydefaults.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/mman.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/mman.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/resource.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/resource.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/time.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/wait.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/termios.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/termios.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/uClibc_clk_tck.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/param.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/linux/param.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm/param.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/asm-generic/param.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/pwd.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/grp.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/shadow.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/paths.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/mntent.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/sys/statfs.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/bits/statfs.h \
  /home/slobodan/OLDopenwrt-rtk/rtk_openwrt_src/staging_dir/rsdk-4.6.4-4181-EB-3.10-0.9.33-m32u-20141001/bin/../lib/gcc/mips-linux-uclibc/4.6.4/../../../../mips-linux-uclibc/include/arpa/inet.h \
  include/xatonum.h \
  include/bb_archive.h \
    $(wildcard include/config/feature/tar/uname/gname.h) \
    $(wildcard include/config/tar.h) \
    $(wildcard include/config/dpkg.h) \
    $(wildcard include/config/dpkg/deb.h) \
    $(wildcard include/config/feature/tar/gnu/extensions.h) \
    $(wildcard include/config/feature/tar/to/command.h) \
    $(wildcard include/config/feature/tar/selinux.h) \
    $(wildcard include/config/cpio.h) \
    $(wildcard include/config/rpm2cpio.h) \
    $(wildcard include/config/rpm.h) \
    $(wildcard include/config/feature/ar/create.h) \

archival/libarchive/filter_accept_list.o: $(deps_archival/libarchive/filter_accept_list.o)

$(deps_archival/libarchive/filter_accept_list.o):
