/* This is a generated file, don't edit */

#define NUM_APPLETS 118

const char applet_names[] ALIGN1 = ""
"[" "\0"
"[[" "\0"
"arping" "\0"
"ash" "\0"
"awk" "\0"
"basename" "\0"
"brctl" "\0"
"bunzip2" "\0"
"bzcat" "\0"
"cat" "\0"
"chgrp" "\0"
"chmod" "\0"
"chown" "\0"
"chroot" "\0"
"clear" "\0"
"cmp" "\0"
"cp" "\0"
"crond" "\0"
"crontab" "\0"
"cut" "\0"
"date" "\0"
"dd" "\0"
"devmem" "\0"
"df" "\0"
"dirname" "\0"
"dmesg" "\0"
"du" "\0"
"echo" "\0"
"egrep" "\0"
"env" "\0"
"expr" "\0"
"false" "\0"
"fgrep" "\0"
"find" "\0"
"free" "\0"
"fsync" "\0"
"grep" "\0"
"gunzip" "\0"
"gzip" "\0"
"halt" "\0"
"head" "\0"
"hexdump" "\0"
"hostid" "\0"
"hwclock" "\0"
"id" "\0"
"ifconfig" "\0"
"kill" "\0"
"killall" "\0"
"less" "\0"
"ln" "\0"
"lock" "\0"
"logger" "\0"
"ls" "\0"
"md5sum" "\0"
"mkdir" "\0"
"mkfifo" "\0"
"mknod" "\0"
"mkswap" "\0"
"mktemp" "\0"
"mount" "\0"
"mv" "\0"
"nc" "\0"
"netmsg" "\0"
"netstat" "\0"
"nice" "\0"
"nslookup" "\0"
"ntpd" "\0"
"passwd" "\0"
"pgrep" "\0"
"pidof" "\0"
"ping" "\0"
"ping6" "\0"
"pivot_root" "\0"
"poweroff" "\0"
"printf" "\0"
"ps" "\0"
"pwd" "\0"
"readlink" "\0"
"reboot" "\0"
"reset" "\0"
"rm" "\0"
"rmdir" "\0"
"route" "\0"
"sed" "\0"
"seq" "\0"
"sh" "\0"
"sleep" "\0"
"sort" "\0"
"start-stop-daemon" "\0"
"strings" "\0"
"switch_root" "\0"
"sync" "\0"
"sysctl" "\0"
"tail" "\0"
"tar" "\0"
"tee" "\0"
"telnet" "\0"
"telnetd" "\0"
"test" "\0"
"time" "\0"
"top" "\0"
"touch" "\0"
"tr" "\0"
"traceroute" "\0"
"true" "\0"
"udhcpc" "\0"
"umount" "\0"
"uname" "\0"
"uniq" "\0"
"uptime" "\0"
"vconfig" "\0"
"vi" "\0"
"wc" "\0"
"wget" "\0"
"which" "\0"
"xargs" "\0"
"yes" "\0"
"zcat" "\0"
;

#ifndef SKIP_applet_main
int (*const applet_main[])(int argc, char **argv) = {
test_main,
test_main,
arping_main,
ash_main,
awk_main,
basename_main,
brctl_main,
bunzip2_main,
bunzip2_main,
cat_main,
chgrp_main,
chmod_main,
chown_main,
chroot_main,
clear_main,
cmp_main,
cp_main,
crond_main,
crontab_main,
cut_main,
date_main,
dd_main,
devmem_main,
df_main,
dirname_main,
dmesg_main,
du_main,
echo_main,
grep_main,
env_main,
expr_main,
false_main,
grep_main,
find_main,
free_main,
fsync_main,
grep_main,
gunzip_main,
gzip_main,
halt_main,
head_main,
hexdump_main,
hostid_main,
hwclock_main,
id_main,
ifconfig_main,
kill_main,
kill_main,
less_main,
ln_main,
lock_main,
logger_main,
ls_main,
md5_sha1_sum_main,
mkdir_main,
mkfifo_main,
mknod_main,
mkswap_main,
mktemp_main,
mount_main,
mv_main,
nc_main,
netmsg_main,
netstat_main,
nice_main,
nslookup_main,
ntpd_main,
passwd_main,
pgrep_main,
pidof_main,
ping_main,
ping6_main,
pivot_root_main,
halt_main,
printf_main,
ps_main,
pwd_main,
readlink_main,
halt_main,
reset_main,
rm_main,
rmdir_main,
route_main,
sed_main,
seq_main,
ash_main,
sleep_main,
sort_main,
start_stop_daemon_main,
strings_main,
switch_root_main,
sync_main,
sysctl_main,
tail_main,
tar_main,
tee_main,
telnet_main,
telnetd_main,
test_main,
time_main,
top_main,
touch_main,
tr_main,
traceroute_main,
true_main,
udhcpc_main,
umount_main,
uname_main,
uniq_main,
uptime_main,
vconfig_main,
vi_main,
wc_main,
wget_main,
which_main,
xargs_main,
yes_main,
gunzip_main,
};
#endif

const uint16_t applet_nameofs[] ALIGN2 = {
0x3000,
0x3002,
0x0005,
0x000c,
0x2010,
0x3014,
0x001d,
0x0023,
0x002b,
0x3031,
0x2035,
0x203b,
0x2041,
0x0047,
0x004e,
0x0054,
0x2058,
0x005b,
0x8061,
0x2069,
0x006d,
0x2072,
0x0075,
0x007c,
0x307f,
0x0087,
0x008d,
0x3090,
0x0095,
0x209b,
0x009f,
0x30a4,
0x00aa,
0x20b0,
0x00b5,
0x30ba,
0x00c0,
0x00c5,
0x00cc,
0x00d1,
0x20d6,
0x20db,
0x30e3,
0x00ea,
0x20f2,
0x00f5,
0x00fe,
0x0103,
0x010b,
0x2110,
0x0113,
0x0118,
0x211f,
0x2122,
0x3129,
0x212f,
0x2136,
0x013c,
0x0143,
0x014a,
0x0150,
0x0153,
0x8156,
0x015d,
0x0165,
0x016a,
0x0173,
0x8178,
0x017f,
0x0185,
0x418b,
0x4190,
0x0196,
0x01a1,
0x31aa,
0x01b1,
0x31b4,
0x01b8,
0x01c1,
0x01c8,
0x31ce,
0x31d1,
0x01d7,
0x01dd,
0x31e1,
0x01e5,
0x01e8,
0x21ee,
0x01f3,
0x0205,
0x020d,
0x3219,
0x021e,
0x0225,
0x022a,
0x022e,
0x0232,
0x0239,
0x3241,
0x0246,
0x024b,
0x324f,
0x0255,
0x4258,
0x3263,
0x0268,
0x026f,
0x0276,
0x027c,
0x0281,
0x0288,
0x0290,
0x0293,
0x0296,
0x029b,
0x22a1,
0x32a7,
0x02ab,
};

