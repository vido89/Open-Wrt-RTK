	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 3
	.text
$Ltext0:
	.cfi_sections	.debug_frame
	.align	2
$LFB3047 = .
	.file 1 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/fastpath-0.1/fast_l2tp_core.c"
	.loc 1 446 0
	.cfi_startproc
	.set	nomips16
	.ent	get_fast_l2tp_lastxmit
	.type	get_fast_l2tp_lastxmit, @function
get_fast_l2tp_lastxmit:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 447 0
	lui	$3,%hi(l2tpInfo)
	addiu	$3,$3,%lo(l2tpInfo)
	lhu	$5,38($3)
	li	$4,1			# 0x1
	bne	$5,$4,$L5
	move	$2,$0

	.loc 1 448 0
	lw	$2,8($3)
$L5:
	.loc 1 450 0
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	get_fast_l2tp_lastxmit
	.cfi_endproc
$LFE3047:
	.size	get_fast_l2tp_lastxmit, .-get_fast_l2tp_lastxmit
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"ppp0\000"
	.align	2
$LC1:
	.ascii	"eth1\000"
	.text
	.align	2
	.globl	l2tp_tx_id
$LFB3045 = .
	.loc 1 101 0
	.cfi_startproc
	.set	nomips16
	.ent	l2tp_tx_id
	.type	l2tp_tx_id, @function
l2tp_tx_id:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, gp= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	.cfi_def_cfa_offset 32
	sw	$16,16($sp)
	.cfi_offset 16, -16
	move	$16,$4
	sw	$17,20($sp)
	sw	$31,28($sp)
	.cfi_offset 17, -12
	.cfi_offset 31, -4
	.cfi_offset 18, -8
	.loc 1 111 0
	jal	rtl_get_skb_data
	sw	$18,24($sp)

	.loc 1 112 0
	move	$4,$16
	jal	rtl_ip_hdr
	move	$17,$2

	.loc 1 113 0
	beq	$2,$0,$L6
	li	$4,1701			# 0x6a5

	.loc 1 115 0
	lw	$3,0($2)
	ext	$3,$3,24,4
	sll	$3,$3,2
	addu	$3,$2,$3
	.loc 1 117 0
	lhu	$5,0($3)
	bne	$5,$4,$L35
	lw	$31,28($sp)

	.loc 1 117 0 is_stmt 0 discriminator 1
	lhu	$4,2($3)
	bne	$4,$5,$L35
	nop

	lhu	$5,8($3)
	seh	$4,$5
	bgez	$4,$L10
	addiu	$6,$3,10

	.loc 1 119 0 is_stmt 1
	andi	$5,$5,0x4000
	.loc 1 120 0
	addiu	$3,$3,12
	movn	$6,$3,$5
	.loc 1 124 0
	lhu	$3,14($6)
	.loc 1 125 0
	li	$4,4			# 0x4
	bne	$3,$4,$L13
	li	$4,11			# 0xb

	.loc 1 125 0 is_stmt 0 discriminator 1
	lui	$4,%hi(l2tpInfo)
	addiu	$4,$4,%lo(l2tpInfo)
	lhu	$3,20($4)
	lhu	$2,0($6)
	bne	$3,$2,$L36
	lw	$18,24($sp)

$LBB44 = .
	.loc 1 127 0 is_stmt 1
	move	$5,$0
	jal	memset
	li	$6,40			# 0x28

$LBE44 = .
	.loc 1 131 0
	lui	$4,%hi($LC0)
	addiu	$4,$4,%lo($LC0)
	jal	rtl865x_setNetifType
	li	$5,2			# 0x2

	.loc 1 133 0
	lui	$2,%hi(state)
	j	$L6
	sw	$0,%lo(state)($2)

$L13:
	.loc 1 136 0
	bne	$3,$4,$L16
	li	$4,12			# 0xc

	.loc 1 145 0
	lui	$18,%hi(state)
	lw	$2,%lo(state)($18)
	bne	$2,$0,$L35
	lw	$31,28($sp)

	.loc 1 145 0 is_stmt 0 discriminator 1
	jal	rtl_get_skb_dev_name
	move	$4,$16

	lui	$5,%hi($LC1)
	move	$4,$2
	addiu	$5,$5,%lo($LC1)
	jal	memcmp
	li	$6,4			# 0x4

	bne	$2,$0,$L35
	lw	$31,28($sp)

	.loc 1 148 0 is_stmt 1
	jal	rtl_get_skb_dev
	move	$4,$16

	lui	$3,%hi(l2tpInfo)
	sw	$2,%lo(l2tpInfo)($3)
$LBB45 = .
	.loc 1 149 0
	addiu	$3,$17,-8
	lwl	$5,0($3)
	lui	$6,%hi(l2tpInfo+24)
	addiu	$7,$6,%lo(l2tpInfo+24)
	lwr	$5,3($3)
$LBE45 = .
$LBB46 = .
	.loc 1 150 0
	addiu	$2,$17,-14
	lui	$4,%hi(l2tpInfo+30)
$LBE46 = .
$LBB47 = .
	.loc 1 149 0
	sw	$5,%lo(l2tpInfo+24)($6)
	lbu	$8,4($3)
$LBE47 = .
$LBB48 = .
	.loc 1 150 0
	addiu	$5,$4,%lo(l2tpInfo+30)
$LBE48 = .
$LBB49 = .
	.loc 1 151 0
	lui	$6,%hi(l2tpInfo+36)
$LBE49 = .
$LBB50 = .
	.loc 1 149 0
	sb	$8,4($7)
	lbu	$3,5($3)
$LBE50 = .
$LBB51 = .
	.loc 1 151 0
	addiu	$8,$6,%lo(l2tpInfo+36)
$LBE51 = .
$LBB52 = .
	.loc 1 149 0
	sb	$3,5($7)
$LBE52 = .
$LBB53 = .
	.loc 1 150 0
	lwl	$3,0($2)
	lwr	$3,3($2)
	swl	$3,%lo(l2tpInfo+30)($4)
	swr	$3,3($5)
	lbu	$3,4($2)
	sb	$3,4($5)
	lbu	$2,5($2)
$LBE53 = .
	.loc 1 153 0
	li	$3,1			# 0x1
$LBB54 = .
	.loc 1 150 0
	sb	$2,5($5)
$LBE54 = .
$LBB55 = .
	.loc 1 151 0
	lbu	$2,-2($17)
	sb	$2,%lo(l2tpInfo+36)($6)
	lbu	$2,-1($17)
$LBE55 = .
	.loc 1 153 0
	sw	$3,%lo(state)($18)
	.loc 1 151 0
	j	$L6
	sb	$2,1($8)

$L16:
	.loc 1 157 0
	bne	$3,$4,$L35
	lw	$31,28($sp)

	.loc 1 157 0 is_stmt 0 discriminator 1
	lhu	$3,2($6)
	beq	$3,$0,$L35
	lui	$16,%hi(state)

	.loc 1 160 0 is_stmt 1
	lw	$3,%lo(state)($16)
	sltu	$3,$3,2
	beq	$3,$0,$L36
	lw	$18,24($sp)

	.loc 1 162 0
	lhu	$3,0($6)
	lui	$17,%hi(l2tpInfo)
	addiu	$17,$17,%lo(l2tpInfo)
	sh	$3,20($17)
	.loc 1 163 0
	lhu	$3,2($6)
	sh	$3,22($17)
	.loc 1 164 0
	lw	$3,12($2)
	sw	$3,16($17)
	.loc 1 165 0
	lw	$2,16($2)
	.loc 1 167 0
	move	$4,$2
	jal	filter_addconnect
	sw	$2,12($17)

	.loc 1 172 0
	lui	$4,%hi($LC0)
	.loc 1 169 0
	li	$2,1			# 0x1
	.loc 1 172 0
	addiu	$4,$4,%lo($LC0)
	li	$5,4			# 0x4
	jal	rtl865x_setNetifType
	sh	$2,38($17)

	.loc 1 175 0
	li	$2,2			# 0x2
	j	$L6
	sw	$2,%lo(state)($16)

$L34:
	.loc 1 192 0
	jal	filter_addconnect
	lw	$4,12($17)

$L18:
	.loc 1 196 0
	lhu	$3,6($16)
	li	$2,49185			# 0xc021
	bne	$3,$2,$L35
	lw	$31,28($sp)

	.loc 1 199 0
	lbu	$2,8($16)
	li	$3,5			# 0x5
	bne	$2,$3,$L37
	li	$3,6			# 0x6

$LBB56 = .
	.loc 1 201 0
	sw	$0,%lo(l2tpInfo)($18)
	sw	$0,4($17)
	sw	$0,8($17)
	sw	$0,12($17)
	sw	$0,16($17)
	sw	$0,20($17)
	sw	$0,24($17)
	sw	$0,28($17)
	sw	$0,32($17)
	sw	$0,36($17)
	lbu	$2,8($16)
$LBE56 = .
	.loc 1 202 0
	lui	$3,%hi(state)
	sw	$0,%lo(state)($3)
	.loc 1 205 0
	li	$3,6			# 0x6
$L37:
	bne	$2,$3,$L38
	li	$3,1			# 0x1

	.loc 1 207 0
	lhu	$3,20($17)
	lhu	$2,0($16)
	bne	$3,$2,$L35
	lw	$31,28($sp)

	.loc 1 207 0 is_stmt 0 discriminator 1
	lhu	$3,22($17)
	lhu	$2,2($16)
	bne	$3,$2,$L36
	lw	$18,24($sp)

$LBB57 = .
	.loc 1 209 0 is_stmt 1
	move	$4,$17
	move	$5,$0
	jal	memset
	li	$6,40			# 0x28

	lbu	$2,8($16)
$LBE57 = .
	.loc 1 210 0
	lui	$3,%hi(state)
	sw	$0,%lo(state)($3)
	.loc 1 215 0
	li	$3,1			# 0x1
$L38:
	bne	$2,$3,$L6
	addiu	$7,$16,8

	lhu	$6,10($16)
$LBB58 = .
	.loc 1 221 0
	li	$2,4			# 0x4
	.loc 1 222 0
	j	$L21
	li	$8,5			# 0x5

$L23:
	.loc 1 226 0
	lbu	$4,0($3)
	bne	$4,$8,$L22
	lbu	$5,1($3)

	.loc 1 228 0
	lw	$3,2($3)
	lui	$2,%hi(l2tp_ppp_imagic)
	.loc 1 229 0
	j	$L6
	sw	$3,%lo(l2tp_ppp_imagic)($2)

$L22:
	.loc 1 231 0
	addu	$2,$2,$5
$L21:
	.loc 1 222 0 discriminator 1
	slt	$4,$2,$6
	bne	$4,$0,$L23
	addu	$3,$7,$2

$LBE58 = .
	.loc 1 239 0
	j	$L35
	lw	$31,28($sp)

$L10:
	.loc 1 191 0
	lui	$18,%hi(l2tpInfo)
	addiu	$17,$18,%lo(l2tpInfo)
	lw	$4,12($17)
	.loc 1 187 0
	addiu	$16,$3,12
	.loc 1 184 0
	andi	$5,$5,0x4000
	.loc 1 187 0
	addiu	$3,$3,10
	.loc 1 191 0
	jal	filter_checkConnect
	movz	$16,$3,$5

	beq	$2,$0,$L18
	nop

	j	$L34
	nop

$L6:
	.loc 1 239 0
	lw	$31,28($sp)
$L35:
	lw	$18,24($sp)
$L36:
	lw	$17,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,32

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 17
	.cfi_restore 18
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	l2tp_tx_id
	.cfi_endproc
$LFE3045:
	.size	l2tp_tx_id, .-l2tp_tx_id
	.align	2
	.globl	fastpath_l2tp_single_open
$LFB3052 = .
	.loc 1 621 0
	.cfi_startproc
	.set	nomips16
	.ent	fastpath_l2tp_single_open
	.type	fastpath_l2tp_single_open, @function
fastpath_l2tp_single_open:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 622 0
	move	$4,$5
	lui	$5,%hi(l2tp_read_proc)
	move	$6,$0
	j	single_open
	addiu	$5,$5,%lo(l2tp_read_proc)

	.set	macro
	.set	reorder
	.end	fastpath_l2tp_single_open
	.cfi_endproc
$LFE3052:
	.size	fastpath_l2tp_single_open, .-fastpath_l2tp_single_open
	.section	.rodata.str1.4
	.align	2
$LC2:
	.ascii	"%c\012\000"
	.text
	.align	2
$LFB3051 = .
	.loc 1 614 0
	.cfi_startproc
	.set	nomips16
	.ent	l2tp_read_proc
	.type	l2tp_read_proc, @function
l2tp_read_proc:
	.frame	$sp,24,$31		# vars= 0, regs= 1/0, args= 16, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 615 0
	lui	$2,%hi(fast_l2tp_fw)
	lw	$6,%lo(fast_l2tp_fw)($2)
	lui	$5,%hi($LC2)
	.loc 1 614 0
	addiu	$sp,$sp,-24
	.cfi_def_cfa_offset 24
	.loc 1 615 0
	addiu	$5,$5,%lo($LC2)
	.loc 1 614 0
	sw	$31,20($sp)
	.cfi_offset 31, -4
	.loc 1 615 0
	jal	seq_printf
	addiu	$6,$6,48

	.loc 1 618 0
	lw	$31,20($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,24

	.cfi_def_cfa_offset 0
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	l2tp_read_proc
	.cfi_endproc
$LFE3051:
	.size	l2tp_read_proc, .-l2tp_read_proc
	.align	2
$LFB3042 = .
	.loc 1 65 0
	.cfi_startproc
	.set	nomips16
	.ent	is_l2tp_device
	.type	is_l2tp_device, @function
is_l2tp_device:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.loc 1 66 0
	lui	$2,%hi(l2tpInfo+4)
	lw	$2,%lo(l2tpInfo+4)($2)
	beq	$2,$0,$L44
	.loc 1 65 0 discriminator 1
	addiu	$sp,$sp,-24
	.cfi_def_cfa_offset 24
	sw	$16,16($sp)
	.cfi_offset 16, -8
	move	$16,$4
	sw	$31,20($sp)
	.cfi_offset 31, -4
	.loc 1 66 0 discriminator 1
	.set	noreorder
	.set	nomacro
	jal	rtl_get_ppp_dev_name
	move	$4,$2
	.set	macro
	.set	reorder

$LBB59 = .
$LBB60 = .
	.file 2 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/string.h"
	.loc 2 77 0 discriminator 1
	move	$4,$16
#APP
 # 77 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$3,($2)
1:	lbu	$1,($4)
	addiu	$2,1
	bne	$1,$3,2f
	addiu	$4,1
	bnez	$3,1b
	lbu	$3,($2)
	move	$3,$1
2:	subu	$3,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
#NO_APP
$LBE60 = .
$LBE59 = .
	.loc 1 66 0 discriminator 1
	sltu	$2,$3,1
	.loc 1 72 0 discriminator 1
	lw	$31,20($sp)
	lw	$16,16($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,24
	.set	macro
	.set	reorder

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 31
$L44:
	.loc 1 71 0
	.set	noreorder
	.set	nomacro
	j	$31
	move	$2,$0
	.set	macro
	.set	reorder

	.end	is_l2tp_device
	.cfi_endproc
$LFE3042:
	.size	is_l2tp_device, .-is_l2tp_device
	.align	2
$LFB3048 = .
	.loc 1 455 0
	.cfi_startproc
	.set	nomips16
	.ent	check_for_fast_l2tp_to_wan
	.type	check_for_fast_l2tp_to_wan, @function
check_for_fast_l2tp_to_wan:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	.cfi_def_cfa_offset 24
	sw	$16,16($sp)
	sw	$31,20($sp)
	.cfi_offset 16, -8
	.cfi_offset 31, -4
	.loc 1 458 0
	jal	rtl_ip_hdr
	move	$16,$4

	.loc 1 460 0
	lbu	$5,9($2)
	li	$3,1			# 0x1
	beq	$5,$3,$L48
	move	$2,$0

$LBB63 = .
$LBB64 = .
	.loc 1 468 0
	jal	rtl_ip_hdr
	move	$4,$16

	lw	$3,12($2)
	li	$2,-256			# 0xffffffffffffff00
	and	$2,$3,$2
	li	$3,-172032000			# 0xfffffffff5bf0000
	ori	$3,$3,0xc000
	addu	$2,$2,$3
	sltu	$2,$0,$2
$L48:
$LBE64 = .
$LBE63 = .
	.loc 1 472 0
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	check_for_fast_l2tp_to_wan
	.cfi_endproc
$LFE3048:
	.size	check_for_fast_l2tp_to_wan, .-check_for_fast_l2tp_to_wan
	.align	2
$LFB3043 = .
	.loc 1 75 0
	.cfi_startproc
	.set	nomips16
	.ent	set_l2tp_device
	.type	set_l2tp_device, @function
set_l2tp_device:
	.frame	$sp,24,$31		# vars= 0, regs= 1/0, args= 16, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 76 0
	lui	$2,%hi(fast_l2tp_fw)
	lw	$2,%lo(fast_l2tp_fw)($2)
	beq	$2,$0,$L58
	nop

	.loc 1 75 0
	addiu	$sp,$sp,-24
	.cfi_def_cfa_offset 24
	sw	$31,20($sp)
	.cfi_offset 31, -4
$LBB67 = .
$LBB68 = .
	.loc 1 79 0
	jal	rtl_get_dev_by_name
	nop

	lui	$3,%hi(l2tpInfo+4)
$LBE68 = .
$LBE67 = .
	.loc 1 81 0
	lw	$31,20($sp)
$LBB70 = .
$LBB69 = .
	.loc 1 79 0
	sw	$2,%lo(l2tpInfo+4)($3)
$LBE69 = .
$LBE70 = .
	.loc 1 81 0
	addiu	$sp,$sp,24
	.cfi_restore 31
	.cfi_def_cfa_offset 0
$L58:
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	set_l2tp_device
	.cfi_endproc
$LFE3043:
	.size	set_l2tp_device, .-set_l2tp_device
	.align	2
$LFB3053 = .
	.loc 1 627 0
	.cfi_startproc
	.set	nomips16
	.ent	fastpath_l2tp_single_write
	.type	fastpath_l2tp_single_write, @function
fastpath_l2tp_single_write:
	.frame	$sp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
$LBB79 = .
$LBB80 = .
	.loc 1 593 0
	sltu	$4,$6,2
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L60
	move	$2,$6
	.set	macro
	.set	reorder

$LBE80 = .
$LBE79 = .
	.loc 1 594 0
	.set	noreorder
	.set	nomacro
	j	$31
	li	$2,-14			# 0xfffffffffffffff2
	.set	macro
	.set	reorder

$L62:
	.cfi_def_cfa_offset 16
	.cfi_offset 31, -4
	.set	noreorder
	.set	nomacro
	j	$L61
	li	$2,-14			# 0xfffffffffffffff2
	.set	macro
	.set	reorder

$L60:
	.cfi_def_cfa_offset 0
	.cfi_restore 31
$LBB89 = .
$LBB85 = .
	.loc 1 596 0
	.set	noreorder
	.set	nomacro
	beq	$5,$0,$L69
	addiu	$4,$5,1
	.set	macro
	.set	reorder

$LBE85 = .
$LBE89 = .
	.loc 1 627 0
	addiu	$sp,$sp,-16
	.cfi_def_cfa_offset 16
	sw	$31,12($sp)
	.cfi_offset 31, -4
$LBB90 = .
$LBB86 = .
$LBB81 = .
$LBB82 = .
	.loc 1 596 0
	or	$3,$4,$5
	lw	$4,24($28)
	and	$3,$3,$4
$LBE82 = .
	.set	noreorder
	.set	nomacro
	bne	$3,$0,$L62
	move	$4,$sp
	.set	macro
	.set	reorder

$LBB83 = .
	li	$6,1			# 0x1
#APP
 # 596 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/fastpath-0.1/fast_l2tp_core.c" 1
	.set	noreorder
	.set	noat
	la	$1, __copy_user
	jalr	$1
	.set	at
	.set	noat
	addu	$1, $5, $6
	.set	at
	.set	reorder
 # 0 "" 2
#NO_APP
$LBE83 = .
$LBE81 = .
	.set	noreorder
	.set	nomacro
	bne	$6,$0,$L62
	lb	$3,0($sp)
	.set	macro
	.set	reorder

	.loc 1 597 0
	lui	$4,%hi(fast_l2tp_fw)
	addiu	$3,$3,-48
	sw	$3,%lo(fast_l2tp_fw)($4)
	.loc 1 598 0
	li	$4,1			# 0x1
	.set	noreorder
	.set	nomacro
	bne	$3,$4,$L63
	lui	$3,%hi(l2tp_tx_id_hook)
	.set	macro
	.set	reorder

	.loc 1 599 0
	lui	$4,%hi(l2tp_tx_id)
	addiu	$4,$4,%lo(l2tp_tx_id)
$LBE86 = .
$LBE90 = .
	.set	noreorder
	.set	nomacro
	j	$L64
	sw	$4,%lo(l2tp_tx_id_hook)($3)
	.set	macro
	.set	reorder

$L63:
$LBB91 = .
$LBB87 = .
	.loc 1 603 0
	sw	$0,%lo(l2tp_tx_id_hook)($3)
$L64:
$LBB84 = .
	.loc 1 606 0
	lui	$4,%hi(l2tpInfo)
	addiu	$3,$4,%lo(l2tpInfo)
	sw	$0,%lo(l2tpInfo)($4)
	sw	$0,4($3)
	sw	$0,8($3)
	sw	$0,12($3)
	sw	$0,16($3)
	sw	$0,20($3)
	sw	$0,24($3)
	sw	$0,28($3)
	sw	$0,32($3)
	sw	$0,36($3)
$LBE84 = .
	.loc 1 607 0
	lui	$3,%hi(state)
	sw	$0,%lo(state)($3)
$L61:
$LBE87 = .
$LBE91 = .
	.loc 1 629 0
	lw	$31,12($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,16
	.set	macro
	.set	reorder

	.cfi_def_cfa_offset 0
	.cfi_restore 31
$L69:
$LBB92 = .
$LBB88 = .
	.loc 1 594 0
	li	$2,-14			# 0xfffffffffffffff2
$LBE88 = .
$LBE92 = .
	.loc 1 629 0
	j	$31
	.end	fastpath_l2tp_single_write
	.cfi_endproc
$LFE3053:
	.size	fastpath_l2tp_single_write, .-fastpath_l2tp_single_write
	.align	2
$LFB3049 = .
	.loc 1 476 0
	.cfi_startproc
	.set	nomips16
	.ent	fast_l2tp_to_wan
	.type	fast_l2tp_to_wan, @function
fast_l2tp_to_wan:
	.frame	$sp,88,$31		# vars= 40, regs= 8/0, args= 16, gp= 0
	.mask	0x807f0000,-4
	.fmask	0x00000000,0
	.loc 1 484 0
	lui	$2,%hi(fast_l2tp_fw)
	lw	$3,%lo(fast_l2tp_fw)($2)
	.set	noreorder
	.set	nomacro
	beq	$3,$0,$L98
	move	$2,$0
	.set	macro
	.set	reorder

	.loc 1 476 0 discriminator 1
	addiu	$sp,$sp,-88
	.cfi_def_cfa_offset 88
	sw	$17,60($sp)
	.cfi_offset 17, -28
	.loc 1 484 0 discriminator 1
	lui	$17,%hi(l2tpInfo)
	.loc 1 476 0 discriminator 1
	sw	$16,56($sp)
	sw	$31,84($sp)
	sw	$22,80($sp)
	sw	$21,76($sp)
	sw	$20,72($sp)
	sw	$19,68($sp)
	sw	$18,64($sp)
	.cfi_offset 16, -32
	.cfi_offset 31, -4
	.cfi_offset 22, -8
	.cfi_offset 21, -12
	.cfi_offset 20, -16
	.cfi_offset 19, -20
	.cfi_offset 18, -24
	.loc 1 484 0 discriminator 1
	addiu	$16,$17,%lo(l2tpInfo)
	lhu	$3,20($16)
	beq	$3,$0,$L72
	lhu	$3,22($16)
	.set	noreorder
	.set	nomacro
	beq	$3,$0,$L72
	lw	$3,%lo(l2tpInfo)($17)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$3,$0,$L72
	li	$3,1			# 0x1
	.set	macro
	.set	reorder

	.loc 1 487 0
	lhu	$5,38($16)
	.set	noreorder
	.set	nomacro
	bne	$5,$3,$L101
	lw	$31,84($sp)
	.set	macro
	.set	reorder

$LBB105 = .
$LBB106 = .
	.loc 1 490 0
	.set	noreorder
	.set	nomacro
	jal	rtl_ip_hdr
	move	$18,$4
	.set	macro
	.set	reorder

	.loc 1 493 0
	move	$4,$18
	.loc 1 490 0
	move	$20,$2
	.loc 1 493 0
	.set	noreorder
	.set	nomacro
	jal	rtl_skb_headroom
	lhu	$21,2($2)
	.set	macro
	.set	reorder

	sltu	$2,$2,52
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L73
	move	$4,$18
	.set	macro
	.set	reorder

$L100:
$LBB107 = .
	.loc 1 495 0
	.set	noreorder
	.set	nomacro
	jal	skb_realloc_headroom
	li	$5,52			# 0x34
	.set	macro
	.set	reorder

	.loc 1 496 0
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L95
	move	$19,$2
	.set	macro
	.set	reorder

$LBE107 = .
$LBE106 = .
$LBE105 = .
	.loc 1 498 0
	.set	noreorder
	.set	nomacro
	j	$L99
	move	$2,$0
	.set	macro
	.set	reorder

$L73:
$LBB133 = .
$LBB130 = .
	.loc 1 493 0
	.set	noreorder
	.set	nomacro
	jal	rtl_skb_cloned
	move	$4,$18
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L100
	move	$4,$18
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jal	rtl_skb_shared
	move	$4,$18
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L77
	move	$19,$18
	.set	macro
	.set	reorder

$LBE130 = .
$LBE133 = .
	.loc 1 495 0
	.set	noreorder
	.set	nomacro
	j	$L100
	move	$4,$18
	.set	macro
	.set	reorder

$L95:
$LBB134 = .
$LBB131 = .
$LBB108 = .
	.loc 1 500 0
	.set	noreorder
	.set	nomacro
	jal	consume_skb
	move	$4,$18
	.set	macro
	.set	reorder

$L77:
$LBE108 = .
$LBB109 = .
	.loc 1 507 0
	move	$4,$19
	li	$5,52			# 0x34
	.set	noreorder
	.set	nomacro
	jal	skb_push
	lbu	$22,1($20)
	.set	macro
	.set	reorder

	lw	$5,24($16)
	move	$3,$2
	lw	$4,28($16)
	lw	$2,32($16)
	swl	$5,0($3)
	swr	$5,3($3)
	swl	$4,4($3)
	swr	$4,7($3)
	swl	$2,8($3)
	swr	$2,11($3)
	lbu	$4,36($16)
$LBE109 = .
	.loc 1 511 0
	lbu	$2,16($sp)
	li	$5,4			# 0x4
$LBB110 = .
	.loc 1 507 0
	sb	$4,12($3)
	lbu	$4,37($16)
$LBE110 = .
	.loc 1 511 0
	ins	$2,$5,4,4
	.loc 1 520 0
	move	$5,$0
$LBB111 = .
	.loc 1 507 0
	sb	$4,13($3)
$LBE111 = .
	.loc 1 512 0
	li	$3,5			# 0x5
	ins	$2,$3,0,4
	.loc 1 517 0
	lw	$18,12($16)
	.loc 1 518 0
	lw	$20,16($16)
	.loc 1 512 0
	sb	$2,16($sp)
	.loc 1 514 0
	li	$2,16384			# 0x4000
	sh	$2,22($sp)
	.loc 1 515 0
	li	$2,17			# 0x11
	.loc 1 520 0
	move	$4,$19
	.loc 1 515 0
	sb	$2,25($sp)
	.loc 1 519 0
	li	$2,64			# 0x40
	.loc 1 517 0
	sw	$18,32($sp)
	.loc 1 518 0
	sw	$20,28($sp)
	.loc 1 519 0
	sb	$2,24($sp)
	.loc 1 520 0
	.set	noreorder
	.set	nomacro
	jal	rtl_set_skb_ip_summed
	sb	$22,17($sp)
	.set	macro
	.set	reorder

	.loc 1 521 0
	.set	noreorder
	.set	nomacro
	jal	rtl_get_skb_len
	move	$4,$19
	.set	macro
	.set	reorder

	addiu	$2,$2,-14
	sh	$2,18($sp)
	.loc 1 522 0
	sh	$0,20($sp)
$LBB112 = .
$LBB113 = .
	.file 3 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/checksum.h"
	.loc 3 109 0
	lw	$3,20($sp)
$LBE113 = .
$LBE112 = .
	.loc 1 524 0
	sh	$0,26($sp)
$LBB119 = .
$LBB116 = .
	.loc 3 109 0
	lw	$4,16($sp)
	.loc 3 113 0
	lw	$2,24($sp)
$LBE116 = .
$LBE119 = .
	.loc 1 530 0
	addiu	$21,$21,18
$LBB120 = .
$LBB117 = .
	.loc 3 109 0
	addu	$4,$3,$4
	.loc 3 110 0
	sltu	$3,$4,$3
	.loc 3 111 0
	addu	$4,$4,$2
	.loc 3 113 0
	addu	$3,$4,$3
	.loc 3 114 0
	sltu	$2,$3,$2
	.loc 3 115 0
	addu	$3,$3,$20
	.loc 3 117 0
	addu	$2,$3,$2
	.loc 3 118 0
	sltu	$20,$2,$20
	.loc 3 119 0
	addu	$2,$2,$18
	.loc 3 123 0
	addu	$20,$2,$20
$LBE117 = .
$LBE120 = .
$LBB121 = .
	.loc 1 526 0
	move	$4,$19
$LBE121 = .
$LBB122 = .
$LBB118 = .
	.loc 3 124 0
	sltu	$18,$20,$18
	.loc 3 125 0
	addu	$18,$18,$20
$LBB114 = .
$LBB115 = .
	.loc 3 78 0
#APP
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $18, 16	
	addu	$18, $1		
	sltu	$1, $18, $1	
	srl	$18, $18, 16	
	addu	$18, $1		
	xori	$18, 0xffff	
	.set	pop
 # 0 "" 2
#NO_APP
$LBE115 = .
$LBE114 = .
$LBE118 = .
$LBE122 = .
$LBB123 = .
	.loc 1 526 0
	.set	noreorder
	.set	nomacro
	jal	rtl_get_skb_data
	sh	$18,26($sp)
	.set	macro
	.set	reorder

	lw	$5,16($sp)
	lw	$4,20($sp)
	addiu	$3,$2,14
	swl	$5,14($2)
	swr	$5,3($3)
	lw	$5,24($sp)
	swl	$4,4($3)
	swr	$4,7($3)
	lw	$4,28($sp)
	swl	$5,8($3)
	swr	$5,11($3)
	lw	$2,32($sp)
	swl	$4,12($3)
	swr	$4,15($3)
	swl	$2,16($3)
$LBE123 = .
	.loc 1 528 0
	li	$4,1701			# 0x6a5
$LBB124 = .
	.loc 1 526 0
	swr	$2,19($3)
$LBE124 = .
	.loc 1 528 0
	sh	$4,36($sp)
	.loc 1 529 0
	sh	$4,38($sp)
	.loc 1 530 0
	sh	$21,40($sp)
	.loc 1 531 0
	sh	$0,42($sp)
	.loc 1 534 0
	lhu	$2,22($16)
	.loc 1 533 0
	lhu	$3,20($16)
	.loc 1 532 0
	li	$5,2			# 0x2
	.loc 1 534 0
	sh	$2,48($sp)
	.loc 1 535 0
	li	$2,-253			# 0xffffffffffffff03
$LBB125 = .
	.loc 1 537 0
	move	$4,$19
$LBE125 = .
	.loc 1 535 0
	sh	$2,50($sp)
	.loc 1 536 0
	li	$2,33			# 0x21
	.loc 1 533 0
	sh	$3,46($sp)
	.loc 1 532 0
	sh	$5,44($sp)
$LBB126 = .
	.loc 1 537 0
	.set	noreorder
	.set	nomacro
	jal	rtl_get_skb_data
	sh	$2,52($sp)
	.set	macro
	.set	reorder

	lw	$5,36($sp)
	lw	$4,40($sp)
	addiu	$3,$2,34
	swl	$5,34($2)
	swr	$5,3($3)
	lw	$5,44($sp)
	swl	$4,4($3)
	swr	$4,7($3)
	lw	$2,48($sp)
	swl	$5,8($3)
	lbu	$7,52($sp)
	lbu	$6,53($sp)
	swr	$5,11($3)
$LBE126 = .
	.loc 1 539 0
	lw	$5,%lo(l2tpInfo)($17)
$LBB127 = .
	.loc 1 537 0
	swl	$2,12($3)
	swr	$2,15($3)
$LBE127 = .
	.loc 1 539 0
	move	$4,$19
$LBB128 = .
	.loc 1 537 0
	sb	$7,16($3)
$LBE128 = .
	.loc 1 539 0
	.set	noreorder
	.set	nomacro
	jal	rtl_set_skb_dev
	sb	$6,17($3)
	.set	macro
	.set	reorder

	.loc 1 543 0
	.set	noreorder
	.set	nomacro
	jal	rtl_get_skb_data
	move	$4,$19
	.set	macro
	.set	reorder

	.loc 1 545 0
	.set	noreorder
	.set	nomacro
	jal	timeoutCheck_skipp_pkt
	addiu	$4,$2,52
	.set	macro
	.set	reorder

	li	$3,1			# 0x1
	.set	noreorder
	.set	nomacro
	beq	$2,$3,$L78
	lui	$2,%hi(jiffies)
	.set	macro
	.set	reorder

	.loc 1 546 0
	lw	$2,%lo(jiffies)($2)
	sw	$2,8($16)
$L78:
$LBB129 = .
	.loc 1 553 0
	lw	$4,4($16)
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L102
	lui	$2,%hi(gQosEnabled)
	.set	macro
	.set	reorder

	jal	rtl_get_ppp_dev_priv
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L102
	lui	$2,%hi(gQosEnabled)
	.set	macro
	.set	reorder

	.loc 1 554 0
	.set	noreorder
	.set	nomacro
	jal	rtl_get_ppp_dev_priv
	lw	$4,4($16)
	.set	macro
	.set	reorder

	.loc 1 555 0
	move	$4,$19
	.set	noreorder
	.set	nomacro
	jal	rtl_get_skb_len
	move	$16,$2
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$16
	.set	noreorder
	.set	nomacro
	jal	rtl_inc_ppp_stats
	li	$5,1			# 0x1
	.set	macro
	.set	reorder

$LBE129 = .
	.loc 1 563 0
	lui	$2,%hi(gQosEnabled)
$L102:
	lw	$2,%lo(gQosEnabled)($2)
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L82
	move	$4,$19
	.set	macro
	.set	reorder

	.loc 1 566 0
	jal	dev_queue_xmit
$LBE131 = .
$LBE134 = .
	.loc 1 567 0
	.set	noreorder
	.set	nomacro
	j	$L72
	li	$2,1			# 0x1
	.set	macro
	.set	reorder

$L82:
$LBB135 = .
$LBB132 = .
	.loc 1 573 0
	jal	rtl_call_skb_ndo_start_xmit
	li	$2,1			# 0x1
$L99:
$L72:
$LBE132 = .
$LBE135 = .
	.loc 1 575 0
	lw	$31,84($sp)
$L101:
	lw	$22,80($sp)
	lw	$21,76($sp)
	lw	$20,72($sp)
	lw	$19,68($sp)
	lw	$18,64($sp)
	lw	$17,60($sp)
	lw	$16,56($sp)
	addiu	$sp,$sp,88
	.cfi_restore 16
	.cfi_restore 17
	.cfi_restore 18
	.cfi_restore 19
	.cfi_restore 20
	.cfi_restore 21
	.cfi_restore 22
	.cfi_restore 31
	.cfi_def_cfa_offset 0
$L98:
	j	$31
	.end	fast_l2tp_to_wan
	.cfi_endproc
$LFE3049:
	.size	fast_l2tp_to_wan, .-fast_l2tp_to_wan
	.align	2
$LFB3044 = .
	.loc 1 85 0
	.cfi_startproc
	.set	nomips16
	.ent	event_ppp_dev_down
	.type	event_ppp_dev_down, @function
event_ppp_dev_down:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, gp= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-32
	.cfi_def_cfa_offset 32
	sw	$17,20($sp)
	.cfi_offset 17, -12
	.loc 1 86 0
	lui	$17,%hi(l2tpInfo)
	.loc 1 85 0
	sw	$16,16($sp)
	.cfi_offset 16, -16
	.loc 1 86 0
	addiu	$16,$17,%lo(l2tpInfo)
	lhu	$2,38($16)
	.loc 1 85 0
	sw	$31,28($sp)
	.cfi_offset 31, -4
	.loc 1 86 0
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L103
	sw	$18,24($sp)
	.set	macro
	.set	reorder

	.cfi_offset 18, -8
	move	$18,$4
	.loc 1 88 0
	lw	$4,4($16)
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L111
	lw	$31,28($sp)
	.set	macro
	.set	reorder

	.loc 1 88 0 is_stmt 0 discriminator 1
	jal	rtl_get_ppp_dev_name
$LBB143 = .
$LBB144 = .
	.loc 2 77 0 is_stmt 1 discriminator 1
	move	$4,$18
#APP
 # 77 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$3,($2)
1:	lbu	$1,($4)
	addiu	$2,1
	bne	$1,$3,2f
	addiu	$4,1
	bnez	$3,1b
	lbu	$3,($2)
	move	$3,$1
2:	subu	$3,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
#NO_APP
$LBE144 = .
$LBE143 = .
	.loc 1 88 0 discriminator 1
	.set	noreorder
	.set	nomacro
	bne	$3,$0,$L111
	lw	$31,28($sp)
	.set	macro
	.set	reorder

$LBB145 = .
$LBB146 = .
	.loc 1 91 0
	lui	$2,%hi(state)
$LBB147 = .
	.loc 1 90 0
	sw	$0,%lo(l2tpInfo)($17)
$LBE147 = .
	.loc 1 91 0
	sw	$0,%lo(state)($2)
$LBB148 = .
	.loc 1 90 0
	sw	$0,4($16)
	sw	$0,8($16)
	sw	$0,12($16)
	sw	$0,16($16)
	sw	$0,20($16)
	sw	$0,24($16)
	sw	$0,28($16)
	sw	$0,32($16)
	sw	$0,36($16)
$L103:
$LBE148 = .
$LBE146 = .
$LBE145 = .
	.loc 1 94 0
	lw	$31,28($sp)
$L111:
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,32
	.set	macro
	.set	reorder

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 17
	.cfi_restore 18
	.cfi_restore 31
	.end	event_ppp_dev_down
	.cfi_endproc
$LFE3044:
	.size	event_ppp_dev_down, .-event_ppp_dev_down
	.align	2
	.globl	fast_l2tp_rx
$LFB3046 = .
	.loc 1 346 0
	.cfi_startproc
	.set	nomips16
	.ent	fast_l2tp_rx
	.type	fast_l2tp_rx, @function
fast_l2tp_rx:
	.frame	$sp,40,$31		# vars= 0, regs= 6/0, args= 16, gp= 0
	.mask	0x801f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	.cfi_def_cfa_offset 40
	sw	$31,36($sp)
	sw	$19,28($sp)
	sw	$18,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	sw	$20,32($sp)
	.cfi_offset 31, -4
	.cfi_offset 19, -12
	.cfi_offset 18, -16
	.cfi_offset 17, -20
	.cfi_offset 16, -24
	.cfi_offset 20, -8
	.loc 1 347 0
	jal	rtl_ip_hdr
	move	$16,$4

	move	$17,$2
	.loc 1 348 0
	lw	$2,0($2)
	.loc 1 356 0
	move	$4,$16
	jal	rtl_get_skb_data
	ext	$18,$2,24,4

	.loc 1 358 0
	move	$4,$16
	jal	rtl_get_skb_len
	move	$19,$2

	sltu	$2,$2,40
	bne	$2,$0,$L143
	sll	$18,$18,2

	.loc 1 348 0
	addu	$18,$17,$18
	.loc 1 361 0
	lhu	$3,0($18)
	li	$5,1701			# 0x6a5
	bne	$3,$5,$L114
	move	$2,$0

	.loc 1 361 0 is_stmt 0 discriminator 1
	lhu	$2,2($18)
	bne	$2,$3,$L114
	move	$2,$0

	.loc 1 362 0 is_stmt 1
	lui	$20,%hi(l2tpInfo)
	lw	$2,%lo(l2tpInfo)($20)
	bne	$2,$0,$L116
	nop

	.loc 1 363 0
	jal	l2tp_tx_id
	move	$4,$16

$L116:
	.loc 1 372 0
	lbu	$2,28($19)
	.loc 1 349 0
	li	$3,2			# 0x2
	.loc 1 395 0
	move	$4,$19
	.loc 1 372 0
	andi	$18,$2,0x40
	.loc 1 349 0
	movz	$3,$0,$18
	.loc 1 375 0
	andi	$2,$2,0x2
	.loc 1 376 0
	addu	$18,$3,$2
	.loc 1 395 0
	move	$5,$18
	jal	fast_l2tp_tx_lcp_echo_reply
	move	$6,$16

	li	$3,1			# 0x1
	beq	$2,$3,$L114
	addiu	$20,$20,%lo(l2tpInfo)

	.loc 1 397 0
	lhu	$2,20($20)
	beq	$2,$0,$L114
	move	$2,$0

	.loc 1 397 0 is_stmt 0 discriminator 1
	lhu	$2,22($20)
	beq	$2,$0,$L143
	addu	$2,$19,$18

	lbu	$3,36($2)
	bne	$3,$0,$L143
	nop

	lbu	$3,37($2)
	li	$2,33			# 0x21
	bne	$3,$2,$L114
	move	$2,$0

	lui	$2,%hi(l2tpInfo)
	lw	$2,%lo(l2tpInfo)($2)
	beq	$2,$0,$L114
	move	$2,$0

	.loc 1 398 0 is_stmt 1
	lw	$3,16($20)
	lw	$2,16($17)
	bne	$3,$2,$L114
	move	$2,$0

	.loc 1 408 0
	lw	$5,4($20)
	bne	$5,$0,$L144
	addiu	$18,$18,38

	addiu	$18,$18,-38
	.loc 1 410 0
	lui	$4,%hi($LC0)
	jal	rtl_get_dev_by_name
	addiu	$4,$4,%lo($LC0)

	.loc 1 413 0
	beq	$2,$0,$L143
	sw	$2,4($20)

	move	$5,$2
	.loc 1 414 0
	addiu	$18,$18,38
$L144:
	addu	$19,$19,$18
	lbu	$3,9($19)
	li	$4,6			# 0x6
	beq	$3,$4,$L120
	li	$4,17			# 0x11

	.loc 1 414 0 is_stmt 0 discriminator 1
	bne	$3,$4,$L114
	move	$2,$0

$L120:
	.loc 1 417 0 is_stmt 1
	jal	rtl_set_skb_dev
	move	$4,$16

	.loc 1 418 0
	move	$5,$18
	jal	skb_pull
	move	$4,$16

	.loc 1 419 0
	jal	rtl_skb_reset_network_header
	move	$4,$16

	.loc 1 420 0
	jal	rtl_skb_reset_transport_header
	move	$4,$16

$LBB149 = .
	.loc 1 425 0
	lw	$4,4($20)
	beq	$4,$0,$L114
	move	$2,$0

	.loc 1 425 0 is_stmt 0 discriminator 1
	jal	rtl_get_ppp_dev_priv
	nop

	beq	$2,$0,$L114
	move	$2,$0

	.loc 1 426 0 is_stmt 1
	jal	rtl_get_ppp_dev_priv
	lw	$4,4($20)

	.loc 1 427 0
	move	$4,$16
	jal	rtl_get_skb_len
	move	$17,$2

	move	$6,$2
	move	$4,$17
	jal	rtl_inc_ppp_stats
	move	$5,$0

$L143:
$LBE149 = .
	.loc 1 441 0
	move	$2,$0
$L114:
	.loc 1 443 0
	lw	$31,36($sp)
	lw	$20,32($sp)
	lw	$19,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,40

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 17
	.cfi_restore 18
	.cfi_restore 19
	.cfi_restore 20
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	fast_l2tp_rx
	.cfi_endproc
$LFE3046:
	.size	fast_l2tp_rx, .-fast_l2tp_rx
	.section	.rodata.str1.4
	.align	2
$LC3:
	.ascii	"fast_l2tp\000"
	.section	.init.text,"ax",@progbits
	.align	2
	.globl	fast_l2tp_init
$LFB3054 = .
	.loc 1 670 0
	.cfi_startproc
	.set	nomips16
	.ent	fast_l2tp_init
	.type	fast_l2tp_init, @function
fast_l2tp_init:
	.frame	$sp,32,$31		# vars= 0, regs= 1/0, args= 24, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 671 0
	lui	$3,%hi(event_ppp_dev_down)
	addiu	$3,$3,%lo(event_ppp_dev_down)
	lui	$2,%hi(event_ppp_dev_down_fphook)
	sw	$3,%lo(event_ppp_dev_down_fphook)($2)
	.loc 1 672 0
	lui	$3,%hi(set_l2tp_device)
	addiu	$3,$3,%lo(set_l2tp_device)
	lui	$2,%hi(set_l2tp_device_fphook)
	sw	$3,%lo(set_l2tp_device_fphook)($2)
	.loc 1 673 0
	lui	$3,%hi(get_fast_l2tp_lastxmit)
	addiu	$3,$3,%lo(get_fast_l2tp_lastxmit)
	lui	$2,%hi(get_fast_l2tp_lastxmit_fphook)
	sw	$3,%lo(get_fast_l2tp_lastxmit_fphook)($2)
	.loc 1 674 0
	lui	$3,%hi(is_l2tp_device)
	addiu	$3,$3,%lo(is_l2tp_device)
	lui	$2,%hi(is_l2tp_device_fphook)
	sw	$3,%lo(is_l2tp_device_fphook)($2)
	.loc 1 675 0
	lui	$3,%hi(check_for_fast_l2tp_to_wan)
	addiu	$3,$3,%lo(check_for_fast_l2tp_to_wan)
	lui	$2,%hi(check_for_fast_l2tp_to_wan_fphook)
	.loc 1 670 0
	addiu	$sp,$sp,-32
	.cfi_def_cfa_offset 32
	.loc 1 675 0
	sw	$3,%lo(check_for_fast_l2tp_to_wan_fphook)($2)
	.loc 1 680 0
	lui	$4,%hi($LC3)
	lui	$6,%hi(proc_root)
	lui	$7,%hi(fastpath_l2tp_proc_fops)
	.loc 1 676 0
	lui	$3,%hi(fast_l2tp_to_wan)
	addiu	$3,$3,%lo(fast_l2tp_to_wan)
	.loc 1 680 0
	addiu	$4,$4,%lo($LC3)
	move	$5,$0
	addiu	$6,$6,%lo(proc_root)
	addiu	$7,$7,%lo(fastpath_l2tp_proc_fops)
	sw	$0,16($sp)
	.loc 1 676 0
	lui	$2,%hi(fast_l2tp_to_wan_fphook)
	.loc 1 670 0
	sw	$31,28($sp)
	.cfi_offset 31, -4
	.loc 1 680 0
	jal	proc_create_data
	sw	$3,%lo(fast_l2tp_to_wan_fphook)($2)

	lui	$3,%hi(res1)
	sw	$2,%lo(res1)($3)
	.loc 1 691 0
	lui	$2,%hi(l2tp_tx_id_hook)
	sw	$0,%lo(l2tp_tx_id_hook)($2)
$LBB150 = .
	.loc 1 694 0
	lui	$4,%hi(l2tpInfo)
$LBE150 = .
	.loc 1 692 0
	lui	$2,%hi(fast_l2tp_fw)
	sw	$0,%lo(fast_l2tp_fw)($2)
$LBB151 = .
	.loc 1 694 0
	addiu	$4,$4,%lo(l2tpInfo)
$LBE151 = .
	.loc 1 693 0
	lui	$2,%hi(state)
$LBB152 = .
	.loc 1 694 0
	move	$5,$0
	li	$6,40			# 0x28
	jal	memset
	sw	$0,%lo(state)($2)

$LBE152 = .
	.loc 1 696 0
	lw	$31,28($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,32

	.cfi_def_cfa_offset 0
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	fast_l2tp_init
	.cfi_endproc
$LFE3054:
	.size	fast_l2tp_init, .-fast_l2tp_init
	.section	.exit.text,"ax",@progbits
	.align	2
	.globl	fast_l2tp_exit
$LFB3055 = .
	.loc 1 699 0
	.cfi_startproc
	.set	nomips16
	.ent	fast_l2tp_exit
	.type	fast_l2tp_exit, @function
fast_l2tp_exit:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	.loc 1 700 0
	lui	$3,%hi(event_ppp_dev_down_fphook)
	sw	$0,%lo(event_ppp_dev_down_fphook)($3)
	.loc 1 701 0
	lui	$3,%hi(set_l2tp_device_fphook)
	.loc 1 699 0
	addiu	$sp,$sp,-24
	.cfi_def_cfa_offset 24
	.loc 1 701 0
	sw	$0,%lo(set_l2tp_device_fphook)($3)
	.loc 1 702 0
	lui	$3,%hi(get_fast_l2tp_lastxmit_fphook)
	sw	$0,%lo(get_fast_l2tp_lastxmit_fphook)($3)
	.loc 1 699 0
	sw	$16,16($sp)
	.loc 1 703 0
	lui	$3,%hi(is_l2tp_device_fphook)
	.cfi_offset 16, -8
	.loc 1 708 0
	lui	$16,%hi(res1)
	.loc 1 703 0
	sw	$0,%lo(is_l2tp_device_fphook)($3)
	.loc 1 708 0
	lw	$2,%lo(res1)($16)
	.loc 1 704 0
	lui	$3,%hi(check_for_fast_l2tp_to_wan_fphook)
	sw	$0,%lo(check_for_fast_l2tp_to_wan_fphook)($3)
	.loc 1 705 0
	lui	$3,%hi(fast_l2tp_to_wan_fphook)
	sw	$0,%lo(fast_l2tp_to_wan_fphook)($3)
	.loc 1 706 0
	lui	$3,%hi(fast_l2tp_fw)
	.loc 1 699 0
	sw	$31,20($sp)
	.cfi_offset 31, -4
	.loc 1 708 0
	beq	$2,$0,$L147
	sw	$0,%lo(fast_l2tp_fw)($3)

	.loc 1 710 0
	lui	$4,%hi($LC3)
	lui	$5,%hi(proc_root)
	addiu	$4,$4,%lo($LC3)
	jal	remove_proc_entry
	addiu	$5,$5,%lo(proc_root)

	.loc 1 714 0
	sw	$0,%lo(res1)($16)
$L147:
	.loc 1 717 0
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.cfi_def_cfa_offset 0
	.cfi_restore 16
	.cfi_restore 31
	.set	macro
	.set	reorder
	.end	fast_l2tp_exit
	.cfi_endproc
$LFE3055:
	.size	fast_l2tp_exit, .-fast_l2tp_exit
	.local	res1
	.comm	res1,4,4
	.globl	fastpath_l2tp_proc_fops
	.data
	.align	2
	.type	fastpath_l2tp_proc_fops, @object
	.size	fastpath_l2tp_proc_fops, 108
fastpath_l2tp_proc_fops:
	.space	4
	.word	seq_lseek
	.word	seq_read
	.word	fastpath_l2tp_single_write
	.space	28
	.word	fastpath_l2tp_single_open
	.space	4
	.word	single_release
	.space	52
	.globl	l2tp_ppp_imagic
	.section	.bss,"aw",@nobits
	.align	2
	.type	l2tp_ppp_imagic, @object
	.size	l2tp_ppp_imagic, 4
l2tp_ppp_imagic:
	.space	4
	.globl	l2tpInfo
	.align	2
	.type	l2tpInfo, @object
	.size	l2tpInfo, 40
l2tpInfo:
	.space	40
	.globl	l2tp_tx_id_hook
	.align	2
	.type	l2tp_tx_id_hook, @object
	.size	l2tp_tx_id_hook, 4
l2tp_tx_id_hook:
	.space	4
	.text
$Letext0:
	.file 4 "include/uapi/asm-generic/int-ll64.h"
	.file 5 "include/asm-generic/int-ll64.h"
	.file 6 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/include/uapi/asm-generic/posix_types.h"
	.file 7 "include/uapi/linux/types.h"
	.file 8 "include/linux/types.h"
	.file 9 "include/asm-generic/atomic-long.h"
	.file 10 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/page.h"
	.file 11 "include/uapi/linux/in.h"
	.file 12 "include/uapi/linux/if_link.h"
	.file 13 "include/uapi/linux/rtnetlink.h"
	.file 14 "include/net/ndisc.h"
	.file 15 "include/net/rtl/rtl_types.h"
	.file 16 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/thread_info.h"
	.file 17 "include/net/inet_frag.h"
	.file 18 "include/linux/etherdevice.h"
	.file 19 "include/linux/export.h"
	.file 20 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/cpu-info.h"
	.file 21 "include/linux/printk.h"
	.file 22 "include/linux/kernel.h"
	.file 23 "include/linux/cpumask.h"
	.file 24 "include/linux/time.h"
	.file 25 "include/linux/highuid.h"
	.file 26 "include/linux/seq_file.h"
	.file 27 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/io.h"
	.file 28 "include/linux/mm.h"
	.file 29 "include/linux/mmzone.h"
	.file 30 "include/linux/jiffies.h"
	.file 31 "include/linux/workqueue.h"
	.file 32 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/smp.h"
	.file 33 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/smp-ops.h"
	.file 34 "include/asm-generic/percpu.h"
	.file 35 "include/linux/sched.h"
	.file 36 "include/linux/percpu_counter.h"
	.file 37 "include/linux/quota.h"
	.file 38 "include/linux/interrupt.h"
	.file 39 "include/linux/kernel_stat.h"
	.file 40 "include/linux/slab.h"
	.file 41 "include/linux/ioport.h"
	.file 42 "include/linux/debug_locks.h"
	.file 43 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/pgtable-32.h"
	.file 44 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/linux-3.10.49/arch/mips/include/asm/pgtable.h"
	.file 45 "include/asm-generic/pgtable.h"
	.file 46 "include/linux/vmstat.h"
	.file 47 "include/linux/netfilter.h"
	.file 48 "include/net/net_namespace.h"
	.file 49 "include/linux/netdevice.h"
	.file 50 "include/net/sock.h"
	.file 51 "include/net/inet_sock.h"
	.file 52 "include/net/ip.h"
	.file 53 "include/net/inet_connection_sock.h"
	.file 54 "include/net/route.h"
	.file 55 "include/net/arp.h"
	.file 56 "include/net/rtl/fastpath/fastpath_core.h"
	.file 57 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_rtl8198c/fastpath-0.1/fast_l2tp_core.h"
	.section	.debug_info,"",@progbits
$Ldebug_info0:
	.4byte	0x1342
	.2byte	0x4
	.4byte	$Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.4byte	$LASF280
	.byte	0x1
	.4byte	$LASF281
	.4byte	$LASF282
	.4byte	$Ldebug_ranges0+0x1c0
	.4byte	0
	.4byte	$Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	$LASF0
	.uleb128 0x3
	.4byte	$LASF3
	.byte	0x4
	.byte	0x14
	.4byte	0x37
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.4byte	$LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.4byte	$LASF2
	.uleb128 0x3
	.4byte	$LASF4
	.byte	0x4
	.byte	0x17
	.4byte	0x50
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.4byte	$LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.ascii	"int\000"
	.uleb128 0x3
	.4byte	$LASF6
	.byte	0x4
	.byte	0x1a
	.4byte	0x69
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	$LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.4byte	$LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.4byte	$LASF9
	.uleb128 0x5
	.ascii	"u8\000"
	.byte	0x5
	.byte	0x10
	.4byte	0x37
	.uleb128 0x5
	.ascii	"u16\000"
	.byte	0x5
	.byte	0x13
	.4byte	0x50
	.uleb128 0x5
	.ascii	"u32\000"
	.byte	0x5
	.byte	0x16
	.4byte	0x69
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	$LASF10
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.4byte	$LASF11
	.uleb128 0x3
	.4byte	$LASF12
	.byte	0x6
	.byte	0x43
	.4byte	0x69
	.uleb128 0x3
	.4byte	$LASF13
	.byte	0x6
	.byte	0x44
	.4byte	0x57
	.uleb128 0x3
	.4byte	$LASF14
	.byte	0x6
	.byte	0x57
	.4byte	0x70
	.uleb128 0x6
	.byte	0x4
	.4byte	0xd3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.4byte	$LASF15
	.uleb128 0x3
	.4byte	$LASF16
	.byte	0x7
	.byte	0x21
	.4byte	0x45
	.uleb128 0x3
	.4byte	$LASF17
	.byte	0x7
	.byte	0x23
	.4byte	0x5e
	.uleb128 0x3
	.4byte	$LASF18
	.byte	0x7
	.byte	0x27
	.4byte	0x45
	.uleb128 0x3
	.4byte	$LASF19
	.byte	0x7
	.byte	0x28
	.4byte	0x5e
	.uleb128 0x3
	.4byte	$LASF20
	.byte	0x8
	.byte	0x1d
	.4byte	0x111
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.4byte	$LASF21
	.uleb128 0x3
	.4byte	$LASF22
	.byte	0x8
	.byte	0x2d
	.4byte	0xc2
	.uleb128 0x3
	.4byte	$LASF23
	.byte	0x8
	.byte	0x36
	.4byte	0xac
	.uleb128 0x3
	.4byte	$LASF24
	.byte	0x8
	.byte	0x3b
	.4byte	0xb7
	.uleb128 0x3
	.4byte	$LASF25
	.byte	0x8
	.byte	0x61
	.4byte	0x2c
	.uleb128 0x3
	.4byte	$LASF26
	.byte	0x8
	.byte	0x65
	.4byte	0x5e
	.uleb128 0x7
	.uleb128 0x3
	.4byte	$LASF27
	.byte	0x8
	.byte	0xb1
	.4byte	0x14f
	.uleb128 0x8
	.4byte	$LASF28
	.uleb128 0x8
	.4byte	$LASF29
	.uleb128 0x8
	.4byte	$LASF30
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.4byte	$LASF31
	.uleb128 0x8
	.4byte	$LASF32
	.uleb128 0x3
	.4byte	$LASF33
	.byte	0x9
	.byte	0x8d
	.4byte	0x150
	.uleb128 0x9
	.byte	0x4
	.uleb128 0x7
	.uleb128 0x3
	.4byte	$LASF34
	.byte	0xa
	.byte	0x69
	.4byte	0x183
	.uleb128 0x6
	.byte	0x4
	.4byte	0x195
	.uleb128 0x8
	.4byte	$LASF35
	.uleb128 0x8
	.4byte	$LASF36
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1a5
	.uleb128 0xa
	.4byte	0x1b0
	.uleb128 0xb
	.4byte	0x181
	.byte	0
	.uleb128 0x8
	.4byte	$LASF37
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1bb
	.uleb128 0xa
	.4byte	0x1c6
	.uleb128 0xb
	.4byte	0x9e
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x118
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.4byte	$LASF38
	.uleb128 0x8
	.4byte	$LASF39
	.uleb128 0x8
	.4byte	$LASF40
	.uleb128 0xc
	.ascii	"pid\000"
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1e8
	.uleb128 0x8
	.4byte	$LASF41
	.uleb128 0x8
	.4byte	$LASF42
	.uleb128 0x8
	.4byte	$LASF43
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1fd
	.uleb128 0xd
	.4byte	0xd3
	.uleb128 0x8
	.4byte	$LASF44
	.uleb128 0x8
	.4byte	$LASF45
	.uleb128 0x8
	.4byte	$LASF46
	.uleb128 0x8
	.4byte	$LASF47
	.uleb128 0x8
	.4byte	$LASF48
	.uleb128 0x6
	.byte	0x4
	.4byte	0x37
	.uleb128 0x8
	.4byte	$LASF49
	.uleb128 0xe
	.byte	0x4
	.byte	0xb
	.byte	0x19
	.4byte	0x2ba
	.uleb128 0xf
	.4byte	$LASF50
	.sleb128 0
	.uleb128 0xf
	.4byte	$LASF51
	.sleb128 1
	.uleb128 0xf
	.4byte	$LASF52
	.sleb128 2
	.uleb128 0xf
	.4byte	$LASF53
	.sleb128 4
	.uleb128 0xf
	.4byte	$LASF54
	.sleb128 6
	.uleb128 0xf
	.4byte	$LASF55
	.sleb128 8
	.uleb128 0xf
	.4byte	$LASF56
	.sleb128 12
	.uleb128 0xf
	.4byte	$LASF57
	.sleb128 17
	.uleb128 0xf
	.4byte	$LASF58
	.sleb128 22
	.uleb128 0xf
	.4byte	$LASF59
	.sleb128 33
	.uleb128 0xf
	.4byte	$LASF60
	.sleb128 46
	.uleb128 0xf
	.4byte	$LASF61
	.sleb128 47
	.uleb128 0xf
	.4byte	$LASF62
	.sleb128 41
	.uleb128 0xf
	.4byte	$LASF63
	.sleb128 50
	.uleb128 0xf
	.4byte	$LASF64
	.sleb128 51
	.uleb128 0xf
	.4byte	$LASF65
	.sleb128 94
	.uleb128 0xf
	.4byte	$LASF66
	.sleb128 103
	.uleb128 0xf
	.4byte	$LASF67
	.sleb128 108
	.uleb128 0xf
	.4byte	$LASF68
	.sleb128 132
	.uleb128 0xf
	.4byte	$LASF69
	.sleb128 136
	.uleb128 0xf
	.4byte	$LASF70
	.sleb128 255
	.uleb128 0xf
	.4byte	$LASF71
	.sleb128 256
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x221
	.uleb128 0x8
	.4byte	$LASF72
	.uleb128 0x8
	.4byte	$LASF73
	.uleb128 0xc
	.ascii	"net\000"
	.uleb128 0x8
	.4byte	$LASF74
	.uleb128 0xe
	.byte	0x4
	.byte	0xc
	.byte	0x65
	.4byte	0x3af
	.uleb128 0xf
	.4byte	$LASF75
	.sleb128 0
	.uleb128 0xf
	.4byte	$LASF76
	.sleb128 1
	.uleb128 0xf
	.4byte	$LASF77
	.sleb128 2
	.uleb128 0xf
	.4byte	$LASF78
	.sleb128 3
	.uleb128 0xf
	.4byte	$LASF79
	.sleb128 4
	.uleb128 0xf
	.4byte	$LASF80
	.sleb128 5
	.uleb128 0xf
	.4byte	$LASF81
	.sleb128 6
	.uleb128 0xf
	.4byte	$LASF82
	.sleb128 7
	.uleb128 0xf
	.4byte	$LASF83
	.sleb128 8
	.uleb128 0xf
	.4byte	$LASF84
	.sleb128 9
	.uleb128 0xf
	.4byte	$LASF85
	.sleb128 10
	.uleb128 0xf
	.4byte	$LASF86
	.sleb128 11
	.uleb128 0xf
	.4byte	$LASF87
	.sleb128 12
	.uleb128 0xf
	.4byte	$LASF88
	.sleb128 13
	.uleb128 0xf
	.4byte	$LASF89
	.sleb128 14
	.uleb128 0xf
	.4byte	$LASF90
	.sleb128 15
	.uleb128 0xf
	.4byte	$LASF91
	.sleb128 16
	.uleb128 0xf
	.4byte	$LASF92
	.sleb128 17
	.uleb128 0xf
	.4byte	$LASF93
	.sleb128 18
	.uleb128 0xf
	.4byte	$LASF94
	.sleb128 19
	.uleb128 0xf
	.4byte	$LASF95
	.sleb128 20
	.uleb128 0xf
	.4byte	$LASF96
	.sleb128 21
	.uleb128 0xf
	.4byte	$LASF97
	.sleb128 22
	.uleb128 0xf
	.4byte	$LASF98
	.sleb128 23
	.uleb128 0xf
	.4byte	$LASF99
	.sleb128 24
	.uleb128 0xf
	.4byte	$LASF100
	.sleb128 25
	.uleb128 0xf
	.4byte	$LASF101
	.sleb128 26
	.uleb128 0xf
	.4byte	$LASF102
	.sleb128 27
	.uleb128 0xf
	.4byte	$LASF103
	.sleb128 28
	.uleb128 0xf
	.4byte	$LASF104
	.sleb128 29
	.uleb128 0xf
	.4byte	$LASF105
	.sleb128 30
	.uleb128 0xf
	.4byte	$LASF106
	.sleb128 31
	.uleb128 0xf
	.4byte	$LASF107
	.sleb128 32
	.uleb128 0xf
	.4byte	$LASF108
	.sleb128 33
	.uleb128 0xf
	.4byte	$LASF109
	.sleb128 34
	.byte	0
	.uleb128 0x8
	.4byte	$LASF110
	.uleb128 0x8
	.4byte	$LASF111
	.uleb128 0x8
	.4byte	$LASF112
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1f2
	.uleb128 0x10
	.byte	0x4
	.byte	0xd
	.2byte	0x167
	.4byte	0x42e
	.uleb128 0xf
	.4byte	$LASF113
	.sleb128 0
	.uleb128 0xf
	.4byte	$LASF114
	.sleb128 1
	.uleb128 0xf
	.4byte	$LASF115
	.sleb128 2
	.uleb128 0xf
	.4byte	$LASF116
	.sleb128 3
	.uleb128 0xf
	.4byte	$LASF117
	.sleb128 4
	.uleb128 0xf
	.4byte	$LASF118
	.sleb128 5
	.uleb128 0xf
	.4byte	$LASF119
	.sleb128 6
	.uleb128 0xf
	.4byte	$LASF120
	.sleb128 7
	.uleb128 0xf
	.4byte	$LASF121
	.sleb128 8
	.uleb128 0xf
	.4byte	$LASF122
	.sleb128 9
	.uleb128 0xf
	.4byte	$LASF123
	.sleb128 10
	.uleb128 0xf
	.4byte	$LASF124
	.sleb128 11
	.uleb128 0xf
	.4byte	$LASF125
	.sleb128 12
	.uleb128 0xf
	.4byte	$LASF126
	.sleb128 13
	.uleb128 0xf
	.4byte	$LASF127
	.sleb128 14
	.uleb128 0xf
	.4byte	$LASF128
	.sleb128 15
	.byte	0
	.uleb128 0x8
	.4byte	$LASF129
	.uleb128 0x8
	.4byte	$LASF130
	.uleb128 0xe
	.byte	0x4
	.byte	0xe
	.byte	0x1b
	.4byte	0x483
	.uleb128 0xf
	.4byte	$LASF131
	.sleb128 0
	.uleb128 0xf
	.4byte	$LASF132
	.sleb128 1
	.uleb128 0xf
	.4byte	$LASF133
	.sleb128 2
	.uleb128 0xf
	.4byte	$LASF134
	.sleb128 3
	.uleb128 0xf
	.4byte	$LASF135
	.sleb128 4
	.uleb128 0xf
	.4byte	$LASF136
	.sleb128 5
	.uleb128 0xf
	.4byte	$LASF137
	.sleb128 6
	.uleb128 0xf
	.4byte	$LASF138
	.sleb128 24
	.uleb128 0xf
	.4byte	$LASF139
	.sleb128 25
	.uleb128 0xf
	.4byte	$LASF140
	.sleb128 31
	.uleb128 0xf
	.4byte	$LASF141
	.sleb128 32
	.byte	0
	.uleb128 0x11
	.4byte	$LASF142
	.byte	0xf
	.2byte	0x18e
	.4byte	0x69
	.uleb128 0x8
	.4byte	$LASF143
	.uleb128 0x8
	.4byte	$LASF144
	.uleb128 0x8
	.4byte	$LASF145
	.uleb128 0x12
	.4byte	$LASF146
	.byte	0x3
	.byte	0x4c
	.4byte	0xf0
	.byte	0x3
	.4byte	0x4ba
	.uleb128 0x13
	.ascii	"sum\000"
	.byte	0x3
	.byte	0x4c
	.4byte	0xfb
	.byte	0
	.uleb128 0x14
	.4byte	$LASF147
	.byte	0x1
	.2byte	0x1c6
	.4byte	0x57
	.byte	0x1
	.4byte	0x4e4
	.uleb128 0x15
	.ascii	"skb\000"
	.byte	0x1
	.2byte	0x1c6
	.4byte	0x181
	.uleb128 0x16
	.ascii	"iph\000"
	.byte	0x1
	.2byte	0x1c8
	.4byte	0x4e4
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x3b9
	.uleb128 0x17
	.4byte	$LASF187
	.byte	0x1
	.byte	0x4a
	.byte	0x1
	.4byte	0x502
	.uleb128 0x18
	.4byte	$LASF148
	.byte	0x1
	.byte	0x4a
	.4byte	0xcd
	.byte	0
	.uleb128 0x12
	.4byte	$LASF149
	.byte	0x10
	.byte	0x3d
	.4byte	0x51e
	.byte	0x3
	.4byte	0x51e
	.uleb128 0x19
	.4byte	$LASF150
	.byte	0x10
	.byte	0x3f
	.4byte	0x51e
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x171
	.uleb128 0x1a
	.4byte	$LASF283
	.byte	0x16
	.byte	0xc7
	.byte	0x3
	.uleb128 0x14
	.4byte	$LASF151
	.byte	0x1
	.2byte	0x24c
	.4byte	0x57
	.byte	0x1
	.4byte	0x61a
	.uleb128 0x1b
	.4byte	$LASF43
	.byte	0x1
	.2byte	0x24c
	.4byte	0x3be
	.uleb128 0x1b
	.4byte	$LASF152
	.byte	0x1
	.2byte	0x24c
	.4byte	0x1f7
	.uleb128 0x1b
	.4byte	$LASF153
	.byte	0x1
	.2byte	0x24d
	.4byte	0x9e
	.uleb128 0x1b
	.4byte	$LASF154
	.byte	0x1
	.2byte	0x24d
	.4byte	0x181
	.uleb128 0x1c
	.4byte	$LASF155
	.byte	0x1
	.2byte	0x24f
	.4byte	0xd3
	.uleb128 0x1d
	.4byte	0x5ff
	.uleb128 0x1c
	.4byte	$LASF156
	.byte	0x1
	.2byte	0x254
	.4byte	0x181
	.uleb128 0x1c
	.4byte	$LASF157
	.byte	0x1
	.2byte	0x254
	.4byte	0x61a
	.uleb128 0x1c
	.4byte	$LASF158
	.byte	0x1
	.2byte	0x254
	.4byte	0xa5
	.uleb128 0x1d
	.4byte	0x5d8
	.uleb128 0x1c
	.4byte	$LASF159
	.byte	0x1
	.2byte	0x254
	.4byte	0x9e
	.uleb128 0x1c
	.4byte	$LASF160
	.byte	0x1
	.2byte	0x254
	.4byte	0x9e
	.uleb128 0x1c
	.4byte	$LASF161
	.byte	0x1
	.2byte	0x254
	.4byte	0x9e
	.uleb128 0x1c
	.4byte	$LASF162
	.byte	0x1
	.2byte	0x254
	.4byte	0x9e
	.byte	0
	.uleb128 0x1e
	.uleb128 0x1c
	.4byte	$LASF163
	.byte	0x1
	.2byte	0x254
	.4byte	0x181
	.uleb128 0x1c
	.4byte	$LASF164
	.byte	0x1
	.2byte	0x254
	.4byte	0x61a
	.uleb128 0x1c
	.4byte	$LASF165
	.byte	0x1
	.2byte	0x254
	.4byte	0xa5
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x1c
	.4byte	$LASF166
	.byte	0x1
	.2byte	0x25e
	.4byte	0x123
	.uleb128 0x1c
	.4byte	$LASF167
	.byte	0x1
	.2byte	0x25e
	.4byte	0x181
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x620
	.uleb128 0x1f
	.uleb128 0x12
	.4byte	$LASF168
	.byte	0x3
	.byte	0x65
	.4byte	0xf0
	.byte	0x3
	.4byte	0x674
	.uleb128 0x13
	.ascii	"iph\000"
	.byte	0x3
	.byte	0x65
	.4byte	0x61a
	.uleb128 0x13
	.ascii	"ihl\000"
	.byte	0x3
	.byte	0x65
	.4byte	0x69
	.uleb128 0x19
	.4byte	$LASF169
	.byte	0x3
	.byte	0x67
	.4byte	0x674
	.uleb128 0x19
	.4byte	$LASF170
	.byte	0x3
	.byte	0x68
	.4byte	0x674
	.uleb128 0x19
	.4byte	$LASF171
	.byte	0x3
	.byte	0x69
	.4byte	0x69
	.uleb128 0x19
	.4byte	$LASF172
	.byte	0x3
	.byte	0x6a
	.4byte	0x57
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x67a
	.uleb128 0xd
	.4byte	0x69
	.uleb128 0x14
	.4byte	$LASF173
	.byte	0x1
	.2byte	0x1db
	.4byte	0x57
	.byte	0x1
	.4byte	0x79c
	.uleb128 0x15
	.ascii	"skb\000"
	.byte	0x1
	.2byte	0x1db
	.4byte	0x181
	.uleb128 0x1c
	.4byte	$LASF174
	.byte	0x1
	.2byte	0x1dd
	.4byte	0x57
	.uleb128 0x16
	.ascii	"iph\000"
	.byte	0x1
	.2byte	0x1de
	.4byte	0x4e4
	.uleb128 0x1c
	.4byte	$LASF175
	.byte	0x1
	.2byte	0x1de
	.4byte	0x4e4
	.uleb128 0x1c
	.4byte	$LASF176
	.byte	0x1
	.2byte	0x1de
	.4byte	0x3b9
	.uleb128 0x1c
	.4byte	$LASF177
	.byte	0x1
	.2byte	0x1de
	.4byte	0x4e4
	.uleb128 0x1c
	.4byte	$LASF178
	.byte	0x1
	.2byte	0x1df
	.4byte	0x79c
	.uleb128 0x1c
	.4byte	$LASF179
	.byte	0x1
	.2byte	0x1df
	.4byte	0x494
	.uleb128 0x16
	.ascii	"tos\000"
	.byte	0x1
	.2byte	0x1e0
	.4byte	0x37
	.uleb128 0x1c
	.4byte	$LASF180
	.byte	0x1
	.2byte	0x1e1
	.4byte	0x50
	.uleb128 0x1c
	.4byte	$LASF181
	.byte	0x1
	.2byte	0x1e2
	.4byte	0x45
	.uleb128 0x1d
	.4byte	0x726
	.uleb128 0x1c
	.4byte	$LASF182
	.byte	0x1
	.2byte	0x1ef
	.4byte	0x181
	.byte	0
	.uleb128 0x1d
	.4byte	0x744
	.uleb128 0x1c
	.4byte	$LASF166
	.byte	0x1
	.2byte	0x1fb
	.4byte	0x123
	.uleb128 0x1c
	.4byte	$LASF167
	.byte	0x1
	.2byte	0x1fb
	.4byte	0x181
	.byte	0
	.uleb128 0x1d
	.4byte	0x762
	.uleb128 0x1c
	.4byte	$LASF166
	.byte	0x1
	.2byte	0x20e
	.4byte	0x123
	.uleb128 0x1c
	.4byte	$LASF167
	.byte	0x1
	.2byte	0x20e
	.4byte	0x181
	.byte	0
	.uleb128 0x1d
	.4byte	0x780
	.uleb128 0x1c
	.4byte	$LASF166
	.byte	0x1
	.2byte	0x219
	.4byte	0x123
	.uleb128 0x1c
	.4byte	$LASF167
	.byte	0x1
	.2byte	0x219
	.4byte	0x181
	.byte	0
	.uleb128 0x1e
	.uleb128 0x20
	.4byte	$LASF284
	.byte	0x1
	.2byte	0x227
	.4byte	0x7a2
	.byte	0
	.uleb128 0x16
	.ascii	"ppp\000"
	.byte	0x1
	.2byte	0x228
	.4byte	0x181
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x494
	.uleb128 0x6
	.byte	0x4
	.4byte	0x3af
	.uleb128 0x12
	.4byte	$LASF183
	.byte	0x2
	.byte	0x49
	.4byte	0x57
	.byte	0x3
	.4byte	0x7da
	.uleb128 0x18
	.4byte	$LASF184
	.byte	0x2
	.byte	0x49
	.4byte	0x1f7
	.uleb128 0x18
	.4byte	$LASF185
	.byte	0x2
	.byte	0x49
	.4byte	0x1f7
	.uleb128 0x19
	.4byte	$LASF186
	.byte	0x2
	.byte	0x4b
	.4byte	0x57
	.byte	0
	.uleb128 0x17
	.4byte	$LASF188
	.byte	0x1
	.byte	0x54
	.byte	0x1
	.4byte	0x80a
	.uleb128 0x18
	.4byte	$LASF189
	.byte	0x1
	.byte	0x54
	.4byte	0x1f7
	.uleb128 0x1e
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0x5a
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0x5a
	.4byte	0x181
	.byte	0
	.byte	0
	.uleb128 0x21
	.4byte	$LASF285
	.byte	0x1
	.2byte	0x1bd
	.4byte	0x9e
	.4byte	$LFB3047
	.4byte	$LFE3047-$LFB3047
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x22
	.4byte	$LASF199
	.byte	0x1
	.byte	0x64
	.4byte	$LFB3045
	.4byte	$LFE3045-$LFB3045
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x9ab
	.uleb128 0x23
	.ascii	"skb\000"
	.byte	0x1
	.byte	0x64
	.4byte	0x181
	.uleb128 0x1
	.byte	0x60
	.uleb128 0x19
	.4byte	$LASF190
	.byte	0x1
	.byte	0x66
	.4byte	0x9ab
	.uleb128 0x24
	.4byte	$LASF192
	.byte	0x1
	.byte	0x67
	.4byte	0x45
	.uleb128 0x1
	.byte	0x53
	.uleb128 0x19
	.4byte	$LASF191
	.byte	0x1
	.byte	0x68
	.4byte	0x9ab
	.uleb128 0x25
	.ascii	"iph\000"
	.byte	0x1
	.byte	0x69
	.4byte	0x4e4
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x25
	.ascii	"hdr\000"
	.byte	0x1
	.byte	0x6a
	.4byte	0x9b1
	.uleb128 0x1
	.byte	0x53
	.uleb128 0x19
	.4byte	$LASF193
	.byte	0x1
	.byte	0x6b
	.4byte	0x9b7
	.uleb128 0x24
	.4byte	$LASF154
	.byte	0x1
	.byte	0x6c
	.4byte	0x21b
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x26
	.4byte	$LBB44
	.4byte	$LBE44-$LBB44
	.4byte	0x8bb
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0x7f
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0x7f
	.4byte	0x181
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0
	.4byte	0x8db
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0x95
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0x95
	.4byte	0x181
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0x28
	.4byte	0x8fb
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0x96
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0x96
	.4byte	0x181
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0x50
	.4byte	0x91b
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0x97
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0x97
	.4byte	0x181
	.byte	0
	.uleb128 0x26
	.4byte	$LBB56
	.4byte	$LBE56-$LBB56
	.4byte	0x93f
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0xc9
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0xc9
	.4byte	0x181
	.byte	0
	.uleb128 0x26
	.4byte	$LBB57
	.4byte	$LBE57-$LBB57
	.4byte	0x963
	.uleb128 0x19
	.4byte	$LASF166
	.byte	0x1
	.byte	0xd1
	.4byte	0x123
	.uleb128 0x19
	.4byte	$LASF167
	.byte	0x1
	.byte	0xd1
	.4byte	0x181
	.byte	0
	.uleb128 0x28
	.4byte	$LBB58
	.4byte	$LBE58-$LBB58
	.uleb128 0x24
	.4byte	$LASF194
	.byte	0x1
	.byte	0xd9
	.4byte	0x21b
	.uleb128 0x1
	.byte	0x57
	.uleb128 0x19
	.4byte	$LASF195
	.byte	0x1
	.byte	0xda
	.4byte	0x45
	.uleb128 0x19
	.4byte	$LASF196
	.byte	0x1
	.byte	0xdb
	.4byte	0x37
	.uleb128 0x24
	.4byte	$LASF197
	.byte	0x1
	.byte	0xdc
	.4byte	0x57
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x24
	.4byte	$LASF198
	.byte	0x1
	.byte	0xdd
	.4byte	0x57
	.uleb128 0x1
	.byte	0x52
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x45
	.uleb128 0x6
	.byte	0x4
	.4byte	0x433
	.uleb128 0x6
	.byte	0x4
	.4byte	0x499
	.uleb128 0x29
	.4byte	$LASF200
	.byte	0x1
	.2byte	0x26c
	.4byte	0x57
	.4byte	$LFB3052
	.4byte	$LFE3052-$LFB3052
	.uleb128 0x1
	.byte	0x9c
	.4byte	0x9f4
	.uleb128 0x2a
	.4byte	$LASF41
	.byte	0x1
	.2byte	0x26c
	.4byte	0x1e2
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2a
	.4byte	$LASF43
	.byte	0x1
	.2byte	0x26c
	.4byte	0x3be
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x2b
	.4byte	$LASF201
	.byte	0x1
	.2byte	0x265
	.4byte	0x57
	.4byte	$LFB3051
	.4byte	$LFE3051-$LFB3051
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xa27
	.uleb128 0x2c
	.ascii	"s\000"
	.byte	0x1
	.2byte	0x265
	.4byte	0xa27
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2c
	.ascii	"v\000"
	.byte	0x1
	.2byte	0x265
	.4byte	0x181
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x2cf
	.uleb128 0x2d
	.4byte	$LASF202
	.byte	0x1
	.byte	0x40
	.4byte	0x57
	.4byte	$LFB3042
	.4byte	$LFE3042-$LFB3042
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xa7d
	.uleb128 0x2e
	.4byte	$LASF148
	.byte	0x1
	.byte	0x40
	.4byte	0xcd
	.uleb128 0x1
	.byte	0x60
	.uleb128 0x2f
	.4byte	0x7a8
	.4byte	$LBB59
	.4byte	$LBE59-$LBB59
	.byte	0x1
	.byte	0x42
	.uleb128 0x30
	.4byte	0x7c3
	.uleb128 0x30
	.4byte	0x7b8
	.uleb128 0x28
	.4byte	$LBB60
	.4byte	$LBE60-$LBB60
	.uleb128 0x31
	.4byte	0x7ce
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x32
	.4byte	0x4ba
	.4byte	$LFB3048
	.4byte	$LFE3048-$LFB3048
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xabb
	.uleb128 0x33
	.4byte	0x4cb
	.uleb128 0x1
	.byte	0x60
	.uleb128 0x31
	.4byte	0x4d7
	.uleb128 0x28
	.4byte	$LBB63
	.4byte	$LBE63-$LBB63
	.uleb128 0x30
	.4byte	0x4cb
	.uleb128 0x28
	.4byte	$LBB64
	.4byte	$LBE64-$LBB64
	.uleb128 0x31
	.4byte	0x4d7
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x32
	.4byte	0x4ea
	.4byte	$LFB3043
	.4byte	$LFE3043-$LFB3043
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xae1
	.uleb128 0x33
	.4byte	0x4f6
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0x70
	.uleb128 0x30
	.4byte	0x4f6
	.byte	0
	.byte	0
	.uleb128 0x35
	.4byte	$LASF203
	.byte	0x1
	.2byte	0x271
	.4byte	0x12e
	.4byte	$LFB3053
	.4byte	$LFE3053-$LFB3053
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xbd9
	.uleb128 0x2a
	.4byte	$LASF43
	.byte	0x1
	.2byte	0x271
	.4byte	0x3be
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2a
	.4byte	$LASF204
	.byte	0x1
	.2byte	0x271
	.4byte	0x1f7
	.uleb128 0x1
	.byte	0x53
	.uleb128 0x2a
	.4byte	$LASF153
	.byte	0x1
	.2byte	0x272
	.4byte	0x123
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x2c
	.ascii	"off\000"
	.byte	0x1
	.2byte	0x272
	.4byte	0x1c6
	.uleb128 0x1
	.byte	0x57
	.uleb128 0x36
	.4byte	0x52c
	.4byte	$LBB79
	.4byte	$Ldebug_ranges0+0x88
	.byte	0x1
	.2byte	0x274
	.uleb128 0x30
	.4byte	0x53d
	.uleb128 0x30
	.4byte	0x561
	.uleb128 0x30
	.4byte	0x555
	.uleb128 0x30
	.4byte	0x549
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0x88
	.uleb128 0x37
	.4byte	0x56d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x26
	.4byte	$LBB81
	.4byte	$LBE81-$LBB81
	.4byte	0xbc2
	.uleb128 0x31
	.4byte	0x57e
	.uleb128 0x31
	.4byte	0x58a
	.uleb128 0x31
	.4byte	0x596
	.uleb128 0x26
	.4byte	$LBB82
	.4byte	$LBE82-$LBB82
	.4byte	0xba2
	.uleb128 0x31
	.4byte	0x5a7
	.uleb128 0x31
	.4byte	0x5b3
	.uleb128 0x31
	.4byte	0x5bf
	.uleb128 0x31
	.4byte	0x5cb
	.byte	0
	.uleb128 0x28
	.4byte	$LBB83
	.4byte	$LBE83-$LBB83
	.uleb128 0x37
	.4byte	0x5d9
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x37
	.4byte	0x5e5
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x37
	.4byte	0x5f1
	.uleb128 0x1
	.byte	0x56
	.byte	0
	.byte	0
	.uleb128 0x28
	.4byte	$LBB84
	.4byte	$LBE84-$LBB84
	.uleb128 0x31
	.4byte	0x600
	.uleb128 0x31
	.4byte	0x60c
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x32
	.4byte	0x67f
	.4byte	$LFB3049
	.4byte	$LFE3049-$LFB3049
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xd20
	.uleb128 0x33
	.4byte	0x690
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x31
	.4byte	0x69c
	.uleb128 0x31
	.4byte	0x6a8
	.uleb128 0x31
	.4byte	0x6b4
	.uleb128 0x31
	.4byte	0x6c0
	.uleb128 0x31
	.4byte	0x6cc
	.uleb128 0x31
	.4byte	0x6d8
	.uleb128 0x31
	.4byte	0x6e4
	.uleb128 0x31
	.4byte	0x6f0
	.uleb128 0x31
	.4byte	0x6fc
	.uleb128 0x31
	.4byte	0x708
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0xb8
	.uleb128 0x30
	.4byte	0x690
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0xb8
	.uleb128 0x31
	.4byte	0x69c
	.uleb128 0x37
	.4byte	0x6a8
	.uleb128 0x1
	.byte	0x64
	.uleb128 0x31
	.4byte	0x6b4
	.uleb128 0x37
	.4byte	0x6c0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x31
	.4byte	0x6cc
	.uleb128 0x31
	.4byte	0x6d8
	.uleb128 0x37
	.4byte	0x6e4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x37
	.4byte	0x6f0
	.uleb128 0x1
	.byte	0x66
	.uleb128 0x31
	.4byte	0x6fc
	.uleb128 0x37
	.4byte	0x708
	.uleb128 0x1
	.byte	0x65
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0xe0
	.4byte	0xc82
	.uleb128 0x31
	.4byte	0x719
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0xf8
	.4byte	0xc96
	.uleb128 0x31
	.4byte	0x72b
	.uleb128 0x31
	.4byte	0x737
	.byte	0
	.uleb128 0x38
	.4byte	0x621
	.4byte	$LBB112
	.4byte	$Ldebug_ranges0+0x118
	.byte	0x1
	.2byte	0x20d
	.4byte	0xce4
	.uleb128 0x30
	.4byte	0x63c
	.uleb128 0x30
	.4byte	0x631
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0x118
	.uleb128 0x31
	.4byte	0x647
	.uleb128 0x31
	.4byte	0x652
	.uleb128 0x31
	.4byte	0x65d
	.uleb128 0x31
	.4byte	0x668
	.uleb128 0x2f
	.4byte	0x49e
	.4byte	$LBB114
	.4byte	$LBE114-$LBB114
	.byte	0x3
	.byte	0x81
	.uleb128 0x30
	.4byte	0x4ae
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0x140
	.4byte	0xcf8
	.uleb128 0x31
	.4byte	0x749
	.uleb128 0x31
	.4byte	0x755
	.byte	0
	.uleb128 0x27
	.4byte	$Ldebug_ranges0+0x160
	.4byte	0xd0c
	.uleb128 0x31
	.4byte	0x767
	.uleb128 0x31
	.4byte	0x773
	.byte	0
	.uleb128 0x28
	.4byte	$LBB129
	.4byte	$LBE129-$LBB129
	.uleb128 0x37
	.4byte	0x78e
	.uleb128 0x1
	.byte	0x60
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x32
	.4byte	0x7da
	.4byte	$LFB3044
	.4byte	$LFE3044-$LFB3044
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xd87
	.uleb128 0x33
	.4byte	0x7e6
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x39
	.4byte	0x7a8
	.4byte	$LBB143
	.4byte	$LBE143-$LBB143
	.byte	0x1
	.byte	0x58
	.4byte	0xd67
	.uleb128 0x30
	.4byte	0x7c3
	.uleb128 0x30
	.4byte	0x7b8
	.uleb128 0x28
	.4byte	$LBB144
	.4byte	$LBE144-$LBB144
	.uleb128 0x31
	.4byte	0x7ce
	.byte	0
	.byte	0
	.uleb128 0x28
	.4byte	$LBB145
	.4byte	$LBE145-$LBB145
	.uleb128 0x30
	.4byte	0x7e6
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0x188
	.uleb128 0x31
	.4byte	0x7f2
	.uleb128 0x31
	.4byte	0x7fd
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x3a
	.4byte	$LASF206
	.byte	0x1
	.2byte	0x159
	.4byte	0x57
	.4byte	$LFB3046
	.4byte	$LFE3046-$LFB3046
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xe00
	.uleb128 0x2c
	.ascii	"skb\000"
	.byte	0x1
	.2byte	0x159
	.4byte	0x181
	.uleb128 0x1
	.byte	0x60
	.uleb128 0x3b
	.ascii	"iph\000"
	.byte	0x1
	.2byte	0x15b
	.4byte	0x4e4
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x3b
	.ascii	"hdr\000"
	.byte	0x1
	.2byte	0x15c
	.4byte	0x9b1
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x3c
	.4byte	$LASF205
	.byte	0x1
	.2byte	0x15d
	.4byte	0x57
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x3c
	.4byte	$LASF154
	.byte	0x1
	.2byte	0x15e
	.4byte	0x21b
	.uleb128 0x1
	.byte	0x63
	.uleb128 0x28
	.4byte	$LBB149
	.4byte	$LBE149-$LBB149
	.uleb128 0x3b
	.ascii	"ppp\000"
	.byte	0x1
	.2byte	0x1a8
	.4byte	0x181
	.uleb128 0x1
	.byte	0x61
	.byte	0
	.byte	0
	.uleb128 0x3a
	.4byte	$LASF207
	.byte	0x1
	.2byte	0x29d
	.4byte	0x57
	.4byte	$LFB3054
	.4byte	$LFE3054-$LFB3054
	.uleb128 0x1
	.byte	0x9c
	.4byte	0xe39
	.uleb128 0x34
	.4byte	$Ldebug_ranges0+0x1a0
	.uleb128 0x1c
	.4byte	$LASF166
	.byte	0x1
	.2byte	0x2b6
	.4byte	0x123
	.uleb128 0x1c
	.4byte	$LASF167
	.byte	0x1
	.2byte	0x2b6
	.4byte	0x181
	.byte	0
	.byte	0
	.uleb128 0x3d
	.4byte	$LASF286
	.byte	0x1
	.2byte	0x2ba
	.4byte	$LFB3055
	.4byte	$LFE3055-$LFB3055
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x8
	.4byte	$LASF208
	.uleb128 0x8
	.4byte	$LASF209
	.uleb128 0x8
	.4byte	$LASF210
	.uleb128 0x8
	.4byte	$LASF211
	.uleb128 0x3e
	.4byte	$LASF212
	.byte	0x11
	.byte	0x6c
	.4byte	0x69
	.4byte	0x1fbd0
	.uleb128 0x3f
	.4byte	0x7e
	.4byte	0xe7e
	.uleb128 0x40
	.4byte	0x16a
	.byte	0x5
	.byte	0
	.uleb128 0x19
	.4byte	$LASF213
	.byte	0x12
	.byte	0x39
	.4byte	0xe89
	.uleb128 0xd
	.4byte	0xe6e
	.uleb128 0x3c
	.4byte	$LASF214
	.byte	0x1
	.2byte	0x292
	.4byte	0xea0
	.uleb128 0x5
	.byte	0x3
	.4byte	res1
	.uleb128 0x6
	.byte	0x4
	.4byte	0xe5a
	.uleb128 0x41
	.4byte	$LASF215
	.byte	0x13
	.byte	0x21
	.4byte	0x1d8
	.uleb128 0x3f
	.4byte	0x160
	.4byte	0xebc
	.uleb128 0x42
	.byte	0
	.uleb128 0x41
	.4byte	$LASF216
	.byte	0x14
	.byte	0x54
	.4byte	0xeb1
	.uleb128 0x3f
	.4byte	0x57
	.4byte	0xed2
	.uleb128 0x42
	.byte	0
	.uleb128 0x41
	.4byte	$LASF217
	.byte	0x15
	.byte	0x24
	.4byte	0xec7
	.uleb128 0x3f
	.4byte	0xd3
	.4byte	0xee8
	.uleb128 0x42
	.byte	0
	.uleb128 0x43
	.4byte	$LASF218
	.byte	0x16
	.2byte	0x1b2
	.4byte	0xef4
	.uleb128 0xd
	.4byte	0xedd
	.uleb128 0x41
	.4byte	$LASF219
	.byte	0x17
	.byte	0x1c
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF220
	.byte	0x17
	.byte	0x50
	.4byte	0xf0f
	.uleb128 0xd
	.4byte	0xf14
	.uleb128 0x6
	.byte	0x4
	.4byte	0xf1a
	.uleb128 0xd
	.4byte	0x165
	.uleb128 0x3f
	.4byte	0x9e
	.4byte	0xf35
	.uleb128 0x40
	.4byte	0x16a
	.byte	0x20
	.uleb128 0x40
	.4byte	0x16a
	.byte	0
	.byte	0
	.uleb128 0x43
	.4byte	$LASF221
	.byte	0x17
	.2byte	0x2f9
	.4byte	0xf41
	.uleb128 0xd
	.4byte	0xf1f
	.uleb128 0x41
	.4byte	$LASF222
	.byte	0x18
	.byte	0x76
	.4byte	0x106
	.uleb128 0x41
	.4byte	$LASF223
	.byte	0x19
	.byte	0x22
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF224
	.byte	0x19
	.byte	0x23
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF225
	.byte	0x1a
	.byte	0x8d
	.4byte	0xe4b
	.uleb128 0x41
	.4byte	$LASF226
	.byte	0xa
	.byte	0x3f
	.4byte	0x9e
	.uleb128 0x41
	.4byte	$LASF227
	.byte	0xa
	.byte	0x4c
	.4byte	0x1b5
	.uleb128 0x41
	.4byte	$LASF228
	.byte	0x1b
	.byte	0x3f
	.4byte	0xf93
	.uleb128 0xd
	.4byte	0x9e
	.uleb128 0x41
	.4byte	$LASF229
	.byte	0x1c
	.byte	0x1d
	.4byte	0x9e
	.uleb128 0x41
	.4byte	$LASF230
	.byte	0x1d
	.byte	0x4c
	.4byte	0x57
	.uleb128 0x43
	.4byte	$LASF231
	.byte	0x1d
	.2byte	0x2ad
	.4byte	0x18f
	.uleb128 0x41
	.4byte	$LASF232
	.byte	0x1e
	.byte	0x4d
	.4byte	0xfc5
	.uleb128 0x44
	.4byte	0x9e
	.uleb128 0x43
	.4byte	$LASF233
	.byte	0x1f
	.2byte	0x151
	.4byte	0xfd6
	.uleb128 0x6
	.byte	0x4
	.4byte	0xe50
	.uleb128 0x43
	.4byte	$LASF234
	.byte	0x1f
	.2byte	0x154
	.4byte	0xfd6
	.uleb128 0x43
	.4byte	$LASF235
	.byte	0x1d
	.2byte	0x391
	.4byte	0x19a
	.uleb128 0x41
	.4byte	$LASF236
	.byte	0x20
	.byte	0x5b
	.4byte	0xfff
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1b0
	.uleb128 0x41
	.4byte	$LASF237
	.byte	0x21
	.byte	0x4d
	.4byte	0x1b0
	.uleb128 0x3f
	.4byte	0x9e
	.4byte	0x1020
	.uleb128 0x40
	.4byte	0x16a
	.byte	0x1
	.byte	0
	.uleb128 0x41
	.4byte	$LASF238
	.byte	0x22
	.byte	0x12
	.4byte	0x1010
	.uleb128 0x43
	.4byte	$LASF239
	.byte	0x23
	.2byte	0x799
	.4byte	0xe55
	.uleb128 0x41
	.4byte	$LASF240
	.byte	0x24
	.byte	0x1b
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF42
	.byte	0x25
	.byte	0xfd
	.4byte	0x1ed
	.uleb128 0x43
	.4byte	$LASF241
	.byte	0x23
	.2byte	0x61e
	.4byte	0x1059
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1dd
	.uleb128 0x43
	.4byte	$LASF242
	.byte	0x26
	.2byte	0x1f4
	.4byte	0x106b
	.uleb128 0x6
	.byte	0x4
	.4byte	0x207
	.uleb128 0x41
	.4byte	$LASF243
	.byte	0x27
	.byte	0x2e
	.4byte	0x20c
	.uleb128 0x3f
	.4byte	0x108c
	.4byte	0x108c
	.uleb128 0x40
	.4byte	0x16a
	.byte	0xd
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x211
	.uleb128 0x41
	.4byte	$LASF244
	.byte	0x28
	.byte	0xe0
	.4byte	0x107c
	.uleb128 0x41
	.4byte	$LASF245
	.byte	0x29
	.byte	0x8a
	.4byte	0x216
	.uleb128 0x41
	.4byte	$LASF246
	.byte	0x2a
	.byte	0xa
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF247
	.byte	0x1c
	.byte	0x21
	.4byte	0x9e
	.uleb128 0x3f
	.4byte	0x184
	.4byte	0x10cf
	.uleb128 0x45
	.4byte	0x16a
	.2byte	0x3ff
	.byte	0
	.uleb128 0x41
	.4byte	$LASF248
	.byte	0x2b
	.byte	0x48
	.4byte	0x10be
	.uleb128 0x41
	.4byte	$LASF249
	.byte	0x2c
	.byte	0x4d
	.4byte	0x9e
	.uleb128 0x43
	.4byte	$LASF250
	.byte	0x2d
	.2byte	0x1cb
	.4byte	0x9e
	.uleb128 0x3f
	.4byte	0x176
	.4byte	0x1101
	.uleb128 0x40
	.4byte	0x16a
	.byte	0x1b
	.byte	0
	.uleb128 0x41
	.4byte	$LASF251
	.byte	0x2e
	.byte	0x5d
	.4byte	0x10f1
	.uleb128 0x43
	.4byte	$LASF252
	.byte	0x1c
	.2byte	0x555
	.4byte	0xedd
	.uleb128 0x43
	.4byte	$LASF253
	.byte	0x1c
	.2byte	0x555
	.4byte	0xedd
	.uleb128 0x3f
	.4byte	0x15b
	.4byte	0x113a
	.uleb128 0x40
	.4byte	0x16a
	.byte	0xc
	.uleb128 0x40
	.4byte	0x16a
	.byte	0x7
	.byte	0
	.uleb128 0x41
	.4byte	$LASF254
	.byte	0x2f
	.byte	0x62
	.4byte	0x1124
	.uleb128 0x3f
	.4byte	0x1155
	.4byte	0x1155
	.uleb128 0x40
	.4byte	0x16a
	.byte	0xc
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x115b
	.uleb128 0xd
	.4byte	0x2c0
	.uleb128 0x41
	.4byte	$LASF72
	.byte	0x2f
	.byte	0xea
	.4byte	0x1145
	.uleb128 0xa
	.4byte	0x117b
	.uleb128 0xb
	.4byte	0x2ba
	.uleb128 0xb
	.4byte	0x117b
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.4byte	0x2c5
	.uleb128 0x43
	.4byte	$LASF255
	.byte	0x2f
	.2byte	0x114
	.4byte	0x118d
	.uleb128 0x6
	.byte	0x4
	.4byte	0x116b
	.uleb128 0x41
	.4byte	$LASF256
	.byte	0x30
	.byte	0x86
	.4byte	0x2ca
	.uleb128 0x43
	.4byte	$LASF111
	.byte	0x31
	.2byte	0x27b
	.4byte	0x11aa
	.uleb128 0x6
	.byte	0x4
	.4byte	0x3b4
	.uleb128 0x43
	.4byte	$LASF257
	.byte	0x32
	.2byte	0x2b8
	.4byte	0x1d3
	.uleb128 0x41
	.4byte	$LASF258
	.byte	0x33
	.byte	0xcd
	.4byte	0x93
	.uleb128 0x41
	.4byte	$LASF259
	.byte	0x33
	.byte	0xce
	.4byte	0x93
	.uleb128 0x41
	.4byte	$LASF260
	.byte	0x34
	.byte	0xcd
	.4byte	0x11dd
	.uleb128 0x6
	.byte	0x4
	.4byte	0x9e
	.uleb128 0x41
	.4byte	$LASF261
	.byte	0x35
	.byte	0xb9
	.4byte	0x11ee
	.uleb128 0xd
	.4byte	0xedd
	.uleb128 0x41
	.4byte	$LASF262
	.byte	0xe
	.byte	0x3e
	.4byte	0x42e
	.uleb128 0x3f
	.4byte	0x2c
	.4byte	0x120e
	.uleb128 0x40
	.4byte	0x16a
	.byte	0xf
	.byte	0
	.uleb128 0x41
	.4byte	$LASF263
	.byte	0x36
	.byte	0xd4
	.4byte	0x1219
	.uleb128 0xd
	.4byte	0x11fe
	.uleb128 0x43
	.4byte	$LASF264
	.byte	0x36
	.2byte	0x135
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF265
	.byte	0x37
	.byte	0xa
	.4byte	0x42e
	.uleb128 0x41
	.4byte	$LASF266
	.byte	0x38
	.byte	0x17
	.4byte	0xe5a
	.uleb128 0x46
	.4byte	$LASF267
	.byte	0x39
	.byte	0x13
	.4byte	0x19f
	.uleb128 0x5
	.byte	0x3
	.4byte	l2tp_tx_id_hook
	.uleb128 0x41
	.4byte	$LASF268
	.byte	0x39
	.byte	0x15
	.4byte	0x57
	.uleb128 0x41
	.4byte	$LASF269
	.byte	0x1
	.byte	0x30
	.4byte	0x57
	.uleb128 0x46
	.4byte	$LASF270
	.byte	0x1
	.byte	0x36
	.4byte	0x48f
	.uleb128 0x5
	.byte	0x3
	.4byte	l2tpInfo
	.uleb128 0x41
	.4byte	$LASF271
	.byte	0x1
	.byte	0x37
	.4byte	0x483
	.uleb128 0x46
	.4byte	$LASF272
	.byte	0x1
	.byte	0x3d
	.4byte	0x69
	.uleb128 0x5
	.byte	0x3
	.4byte	l2tp_ppp_imagic
	.uleb128 0x47
	.4byte	$LASF273
	.byte	0x1
	.2byte	0x278
	.4byte	0x202
	.uleb128 0x5
	.byte	0x3
	.4byte	fastpath_l2tp_proc_fops
	.uleb128 0xa
	.4byte	0x12b1
	.uleb128 0xb
	.4byte	0x1f7
	.byte	0
	.uleb128 0x43
	.4byte	$LASF274
	.byte	0x1
	.2byte	0x295
	.4byte	0x12bd
	.uleb128 0x6
	.byte	0x4
	.4byte	0x12a6
	.uleb128 0xa
	.4byte	0x12ce
	.uleb128 0xb
	.4byte	0xcd
	.byte	0
	.uleb128 0x43
	.4byte	$LASF275
	.byte	0x1
	.2byte	0x296
	.4byte	0x12da
	.uleb128 0x6
	.byte	0x4
	.4byte	0x12c3
	.uleb128 0x48
	.4byte	0x9e
	.uleb128 0x43
	.4byte	$LASF276
	.byte	0x1
	.2byte	0x297
	.4byte	0x12f1
	.uleb128 0x6
	.byte	0x4
	.4byte	0x12e0
	.uleb128 0x49
	.4byte	0x57
	.4byte	0x1306
	.uleb128 0xb
	.4byte	0xcd
	.byte	0
	.uleb128 0x43
	.4byte	$LASF277
	.byte	0x1
	.2byte	0x298
	.4byte	0x1312
	.uleb128 0x6
	.byte	0x4
	.4byte	0x12f7
	.uleb128 0x49
	.4byte	0x57
	.4byte	0x1327
	.uleb128 0xb
	.4byte	0x181
	.byte	0
	.uleb128 0x43
	.4byte	$LASF278
	.byte	0x1
	.2byte	0x299
	.4byte	0x1333
	.uleb128 0x6
	.byte	0x4
	.4byte	0x1318
	.uleb128 0x43
	.4byte	$LASF279
	.byte	0x1
	.2byte	0x29a
	.4byte	0x1333
	.byte	0
	.section	.debug_abbrev,"",@progbits
$Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x4
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x20
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0xb
	.byte	0x1
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x26
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2e
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2f
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x30
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x31
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x32
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x33
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x34
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x35
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x36
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x37
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x38
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x39
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3a
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3d
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x3e
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x3f
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x40
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x41
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x42
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x43
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x44
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x45
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x46
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x47
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x48
	.uleb128 0x15
	.byte	0
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x49
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.4byte	0x2c
	.2byte	0x2
	.4byte	$Ldebug_info0
	.byte	0x4
	.byte	0
	.2byte	0
	.2byte	0
	.4byte	$Ltext0
	.4byte	$Letext0-$Ltext0
	.4byte	$LFB3054
	.4byte	$LFE3054-$LFB3054
	.4byte	$LFB3055
	.4byte	$LFE3055-$LFB3055
	.4byte	0
	.4byte	0
	.section	.debug_ranges,"",@progbits
$Ldebug_ranges0:
	.4byte	$LBB45
	.4byte	$LBE45
	.4byte	$LBB47
	.4byte	$LBE47
	.4byte	$LBB50
	.4byte	$LBE50
	.4byte	$LBB52
	.4byte	$LBE52
	.4byte	0
	.4byte	0
	.4byte	$LBB46
	.4byte	$LBE46
	.4byte	$LBB48
	.4byte	$LBE48
	.4byte	$LBB53
	.4byte	$LBE53
	.4byte	$LBB54
	.4byte	$LBE54
	.4byte	0
	.4byte	0
	.4byte	$LBB49
	.4byte	$LBE49
	.4byte	$LBB51
	.4byte	$LBE51
	.4byte	$LBB55
	.4byte	$LBE55
	.4byte	0
	.4byte	0
	.4byte	$LBB67
	.4byte	$LBE67
	.4byte	$LBB70
	.4byte	$LBE70
	.4byte	0
	.4byte	0
	.4byte	$LBB79
	.4byte	$LBE79
	.4byte	$LBB89
	.4byte	$LBE89
	.4byte	$LBB90
	.4byte	$LBE90
	.4byte	$LBB91
	.4byte	$LBE91
	.4byte	$LBB92
	.4byte	$LBE92
	.4byte	0
	.4byte	0
	.4byte	$LBB105
	.4byte	$LBE105
	.4byte	$LBB133
	.4byte	$LBE133
	.4byte	$LBB134
	.4byte	$LBE134
	.4byte	$LBB135
	.4byte	$LBE135
	.4byte	0
	.4byte	0
	.4byte	$LBB107
	.4byte	$LBE107
	.4byte	$LBB108
	.4byte	$LBE108
	.4byte	0
	.4byte	0
	.4byte	$LBB109
	.4byte	$LBE109
	.4byte	$LBB110
	.4byte	$LBE110
	.4byte	$LBB111
	.4byte	$LBE111
	.4byte	0
	.4byte	0
	.4byte	$LBB112
	.4byte	$LBE112
	.4byte	$LBB119
	.4byte	$LBE119
	.4byte	$LBB120
	.4byte	$LBE120
	.4byte	$LBB122
	.4byte	$LBE122
	.4byte	0
	.4byte	0
	.4byte	$LBB121
	.4byte	$LBE121
	.4byte	$LBB123
	.4byte	$LBE123
	.4byte	$LBB124
	.4byte	$LBE124
	.4byte	0
	.4byte	0
	.4byte	$LBB125
	.4byte	$LBE125
	.4byte	$LBB126
	.4byte	$LBE126
	.4byte	$LBB127
	.4byte	$LBE127
	.4byte	$LBB128
	.4byte	$LBE128
	.4byte	0
	.4byte	0
	.4byte	$LBB147
	.4byte	$LBE147
	.4byte	$LBB148
	.4byte	$LBE148
	.4byte	0
	.4byte	0
	.4byte	$LBB150
	.4byte	$LBE150
	.4byte	$LBB151
	.4byte	$LBE151
	.4byte	$LBB152
	.4byte	$LBE152
	.4byte	0
	.4byte	0
	.4byte	$Ltext0
	.4byte	$Letext0
	.4byte	$LFB3054
	.4byte	$LFE3054
	.4byte	$LFB3055
	.4byte	$LFE3055
	.4byte	0
	.4byte	0
	.section	.debug_line,"",@progbits
$Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
$LASF137:
	.ascii	"__ND_OPT_ARRAY_MAX\000"
$LASF181:
	.ascii	"old_len\000"
$LASF123:
	.ascii	"RTAX_HOPLIMIT\000"
$LASF242:
	.ascii	"ksoftirqd\000"
$LASF281:
	.ascii	"/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co"
	.ascii	"_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/bu"
	.ascii	"ild_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_"
	.ascii	"rtl8198c/fastpath-0.1/fast_l2tp_core.c\000"
$LASF224:
	.ascii	"overflowgid\000"
$LASF245:
	.ascii	"ioport_resource\000"
$LASF225:
	.ascii	"init_user_ns\000"
$LASF50:
	.ascii	"IPPROTO_IP\000"
$LASF217:
	.ascii	"console_printk\000"
$LASF138:
	.ascii	"ND_OPT_ROUTE_INFO\000"
$LASF131:
	.ascii	"__ND_OPT_PREFIX_INFO_END\000"
$LASF207:
	.ascii	"fast_l2tp_init\000"
$LASF276:
	.ascii	"get_fast_l2tp_lastxmit_fphook\000"
$LASF122:
	.ascii	"RTAX_REORDERING\000"
$LASF85:
	.ascii	"IFLA_MASTER\000"
$LASF7:
	.ascii	"unsigned int\000"
$LASF179:
	.ascii	"l2tphone\000"
$LASF171:
	.ascii	"csum\000"
$LASF36:
	.ascii	"pglist_data\000"
$LASF100:
	.ascii	"IFLA_PORT_SELF\000"
$LASF145:
	.ascii	"l2tp_header\000"
$LASF210:
	.ascii	"pid_namespace\000"
$LASF148:
	.ascii	"ppp_device\000"
$LASF128:
	.ascii	"__RTAX_MAX\000"
$LASF40:
	.ascii	"module\000"
$LASF52:
	.ascii	"IPPROTO_IGMP\000"
$LASF222:
	.ascii	"persistent_clock_exist\000"
$LASF89:
	.ascii	"IFLA_MAP\000"
$LASF133:
	.ascii	"ND_OPT_TARGET_LL_ADDR\000"
$LASF107:
	.ascii	"IFLA_NUM_RX_QUEUES\000"
$LASF264:
	.ascii	"sysctl_ip_default_ttl\000"
$LASF140:
	.ascii	"ND_OPT_DNSSL\000"
$LASF157:
	.ascii	"__cu_from\000"
$LASF204:
	.ascii	"userbuf\000"
$LASF65:
	.ascii	"IPPROTO_BEETPH\000"
$LASF114:
	.ascii	"RTAX_LOCK\000"
$LASF215:
	.ascii	"__this_module\000"
$LASF195:
	.ascii	"Total_length\000"
$LASF159:
	.ascii	"__addr\000"
$LASF231:
	.ascii	"mem_map\000"
$LASF135:
	.ascii	"ND_OPT_REDIRECT_HDR\000"
$LASF104:
	.ascii	"IFLA_EXT_MASK\000"
$LASF63:
	.ascii	"IPPROTO_ESP\000"
$LASF277:
	.ascii	"is_l2tp_device_fphook\000"
$LASF206:
	.ascii	"fast_l2tp_rx\000"
$LASF170:
	.ascii	"stop\000"
$LASF201:
	.ascii	"l2tp_read_proc\000"
$LASF256:
	.ascii	"init_net\000"
$LASF55:
	.ascii	"IPPROTO_EGP\000"
$LASF280:
	.ascii	"GNU C 4.8.3 -fpreprocessed -G 0 -mno-check-zero-division"
	.ascii	" -mabi=32 -mno-abicalls -mno-branch-likely -msoft-float "
	.ascii	"-march=mips32r2 -mno-long-calls -mllsc -mplt -mno-shared"
	.ascii	" -g -O2 -fno-strict-aliasing -fno-common -fno-delete-nul"
	.ascii	"l-pointer-checks -fno-reorder-blocks -fno-tree-ch -fno-c"
	.ascii	"aller-saves -fno-pic -ffreestanding -fno-stack-protector"
	.ascii	" -fomit-frame-pointer -femit-struct-debug-baseonly -fno-"
	.ascii	"var-tracking -fno-strict-overflow -fconserve-stack\000"
$LASF166:
	.ascii	"__len\000"
$LASF99:
	.ascii	"IFLA_VF_PORTS\000"
$LASF172:
	.ascii	"carry\000"
$LASF13:
	.ascii	"__kernel_ssize_t\000"
$LASF279:
	.ascii	"fast_l2tp_to_wan_fphook\000"
$LASF62:
	.ascii	"IPPROTO_IPV6\000"
$LASF9:
	.ascii	"long long unsigned int\000"
$LASF34:
	.ascii	"pte_t\000"
$LASF249:
	.ascii	"zero_page_mask\000"
$LASF273:
	.ascii	"fastpath_l2tp_proc_fops\000"
$LASF32:
	.ascii	"thread_info\000"
$LASF244:
	.ascii	"kmalloc_caches\000"
$LASF29:
	.ascii	"cpuinfo_mips\000"
$LASF234:
	.ascii	"system_freezable_wq\000"
$LASF270:
	.ascii	"l2tpInfo\000"
$LASF92:
	.ascii	"IFLA_LINKMODE\000"
$LASF173:
	.ascii	"fast_l2tp_to_wan\000"
$LASF86:
	.ascii	"IFLA_WIRELESS\000"
$LASF102:
	.ascii	"IFLA_GROUP\000"
$LASF46:
	.ascii	"kernel_stat\000"
$LASF23:
	.ascii	"size_t\000"
$LASF4:
	.ascii	"__u16\000"
$LASF197:
	.ascii	"attribute_len\000"
$LASF97:
	.ascii	"IFLA_VFINFO_LIST\000"
$LASF156:
	.ascii	"__cu_to\000"
$LASF146:
	.ascii	"csum_fold\000"
$LASF21:
	.ascii	"_Bool\000"
$LASF165:
	.ascii	"__cu_len_r\000"
$LASF119:
	.ascii	"RTAX_SSTHRESH\000"
$LASF134:
	.ascii	"ND_OPT_PREFIX_INFO\000"
$LASF48:
	.ascii	"resource\000"
$LASF129:
	.ascii	"neigh_table\000"
$LASF79:
	.ascii	"IFLA_MTU\000"
$LASF57:
	.ascii	"IPPROTO_UDP\000"
$LASF221:
	.ascii	"cpu_bit_bitmap\000"
$LASF228:
	.ascii	"mips_io_port_base\000"
$LASF91:
	.ascii	"IFLA_OPERSTATE\000"
$LASF238:
	.ascii	"__per_cpu_offset\000"
$LASF98:
	.ascii	"IFLA_STATS64\000"
$LASF153:
	.ascii	"count\000"
$LASF202:
	.ascii	"is_l2tp_device\000"
$LASF255:
	.ascii	"nf_nat_decode_session_hook\000"
$LASF192:
	.ascii	"MessageType\000"
$LASF132:
	.ascii	"ND_OPT_SOURCE_LL_ADDR\000"
$LASF26:
	.ascii	"u_int32_t\000"
$LASF176:
	.ascii	"iph_newone\000"
$LASF15:
	.ascii	"char\000"
$LASF283:
	.ascii	"might_fault\000"
$LASF53:
	.ascii	"IPPROTO_IPIP\000"
$LASF188:
	.ascii	"event_ppp_dev_down\000"
$LASF44:
	.ascii	"file_operations\000"
$LASF247:
	.ascii	"totalram_pages\000"
$LASF274:
	.ascii	"event_ppp_dev_down_fphook\000"
$LASF125:
	.ascii	"RTAX_FEATURES\000"
$LASF164:
	.ascii	"__cu_from_r\000"
$LASF196:
	.ascii	"attribute_type\000"
$LASF250:
	.ascii	"zero_pfn\000"
$LASF268:
	.ascii	"fast_l2tp_fw\000"
$LASF78:
	.ascii	"IFLA_IFNAME\000"
$LASF111:
	.ascii	"rps_sock_flow_table\000"
$LASF162:
	.ascii	"__ok\000"
$LASF158:
	.ascii	"__cu_len\000"
$LASF24:
	.ascii	"ssize_t\000"
$LASF43:
	.ascii	"file\000"
$LASF200:
	.ascii	"fastpath_l2tp_single_open\000"
$LASF6:
	.ascii	"__u32\000"
$LASF209:
	.ascii	"workqueue_struct\000"
$LASF47:
	.ascii	"kmem_cache\000"
$LASF266:
	.ascii	"proc_root\000"
$LASF263:
	.ascii	"ip_tos2prio\000"
$LASF45:
	.ascii	"task_struct\000"
$LASF81:
	.ascii	"IFLA_QDISC\000"
$LASF8:
	.ascii	"long long int\000"
$LASF243:
	.ascii	"kstat\000"
$LASF141:
	.ascii	"__ND_OPT_MAX\000"
$LASF118:
	.ascii	"RTAX_RTTVAR\000"
$LASF56:
	.ascii	"IPPROTO_PUP\000"
$LASF272:
	.ascii	"l2tp_ppp_imagic\000"
$LASF74:
	.ascii	"seq_file\000"
$LASF41:
	.ascii	"inode\000"
$LASF95:
	.ascii	"IFLA_IFALIAS\000"
$LASF64:
	.ascii	"IPPROTO_AH\000"
$LASF139:
	.ascii	"ND_OPT_RDNSS\000"
$LASF198:
	.ascii	"cur_offset\000"
$LASF121:
	.ascii	"RTAX_ADVMSS\000"
$LASF269:
	.ascii	"gQosEnabled\000"
$LASF51:
	.ascii	"IPPROTO_ICMP\000"
$LASF20:
	.ascii	"bool\000"
$LASF168:
	.ascii	"ip_fast_csum\000"
$LASF71:
	.ascii	"IPPROTO_MAX\000"
$LASF180:
	.ascii	"frag_off\000"
$LASF191:
	.ascii	"ppp_protocol\000"
$LASF30:
	.ascii	"cpumask\000"
$LASF83:
	.ascii	"IFLA_COST\000"
$LASF237:
	.ascii	"cmp_smp_ops\000"
$LASF226:
	.ascii	"shm_align_mask\000"
$LASF152:
	.ascii	"buffer\000"
$LASF213:
	.ascii	"eth_reserved_addr_base\000"
$LASF260:
	.ascii	"sysctl_local_reserved_ports\000"
$LASF278:
	.ascii	"check_for_fast_l2tp_to_wan_fphook\000"
$LASF142:
	.ascii	"uint32\000"
$LASF143:
	.ascii	"l2tp_info\000"
$LASF223:
	.ascii	"overflowuid\000"
$LASF267:
	.ascii	"l2tp_tx_id_hook\000"
$LASF230:
	.ascii	"page_group_by_mobility_disabled\000"
$LASF101:
	.ascii	"IFLA_AF_SPEC\000"
$LASF124:
	.ascii	"RTAX_INITCWND\000"
$LASF220:
	.ascii	"cpu_online_mask\000"
$LASF205:
	.ascii	"rightShift\000"
$LASF58:
	.ascii	"IPPROTO_IDP\000"
$LASF208:
	.ascii	"user_namespace\000"
$LASF186:
	.ascii	"__res\000"
$LASF167:
	.ascii	"__ret\000"
$LASF154:
	.ascii	"data\000"
$LASF127:
	.ascii	"RTAX_INITRWND\000"
$LASF178:
	.ascii	"l2tph\000"
$LASF251:
	.ascii	"vm_stat\000"
$LASF235:
	.ascii	"contig_page_data\000"
$LASF105:
	.ascii	"IFLA_PROMISCUITY\000"
$LASF261:
	.ascii	"inet_csk_timer_bug_msg\000"
$LASF177:
	.ascii	"iph_tmp\000"
$LASF116:
	.ascii	"RTAX_WINDOW\000"
$LASF96:
	.ascii	"IFLA_NUM_VF\000"
$LASF174:
	.ascii	"header_len\000"
$LASF233:
	.ascii	"system_wq\000"
$LASF262:
	.ascii	"nd_tbl\000"
$LASF248:
	.ascii	"invalid_pte_table\000"
$LASF25:
	.ascii	"u_int8_t\000"
$LASF73:
	.ascii	"flowi\000"
$LASF60:
	.ascii	"IPPROTO_RSVP\000"
$LASF109:
	.ascii	"__IFLA_MAX\000"
$LASF42:
	.ascii	"dqstats\000"
$LASF184:
	.ascii	"__cs\000"
$LASF185:
	.ascii	"__ct\000"
$LASF2:
	.ascii	"short int\000"
$LASF285:
	.ascii	"get_fast_l2tp_lastxmit\000"
$LASF11:
	.ascii	"long int\000"
$LASF117:
	.ascii	"RTAX_RTT\000"
$LASF110:
	.ascii	"net_device_stats\000"
$LASF113:
	.ascii	"RTAX_UNSPEC\000"
$LASF87:
	.ascii	"IFLA_PROTINFO\000"
$LASF199:
	.ascii	"l2tp_tx_id\000"
$LASF35:
	.ascii	"page\000"
$LASF106:
	.ascii	"IFLA_NUM_TX_QUEUES\000"
$LASF257:
	.ascii	"memalloc_socks\000"
$LASF115:
	.ascii	"RTAX_MTU\000"
$LASF66:
	.ascii	"IPPROTO_PIM\000"
$LASF254:
	.ascii	"nf_hooks\000"
$LASF93:
	.ascii	"IFLA_LINKINFO\000"
$LASF169:
	.ascii	"word\000"
$LASF61:
	.ascii	"IPPROTO_GRE\000"
$LASF229:
	.ascii	"max_mapnr\000"
$LASF12:
	.ascii	"__kernel_size_t\000"
$LASF286:
	.ascii	"fast_l2tp_exit\000"
$LASF75:
	.ascii	"IFLA_UNSPEC\000"
$LASF151:
	.ascii	"l2tp_write_proc\000"
$LASF241:
	.ascii	"cad_pid\000"
$LASF218:
	.ascii	"hex_asc\000"
$LASF175:
	.ascii	"iph_new\000"
$LASF259:
	.ascii	"ipv6_hash_secret\000"
$LASF16:
	.ascii	"__be16\000"
$LASF68:
	.ascii	"IPPROTO_SCTP\000"
$LASF80:
	.ascii	"IFLA_LINK\000"
$LASF189:
	.ascii	"name\000"
$LASF246:
	.ascii	"debug_locks\000"
$LASF39:
	.ascii	"static_key\000"
$LASF236:
	.ascii	"mp_ops\000"
$LASF94:
	.ascii	"IFLA_NET_NS_PID\000"
$LASF27:
	.ascii	"atomic_t\000"
$LASF31:
	.ascii	"sizetype\000"
$LASF10:
	.ascii	"long unsigned int\000"
$LASF3:
	.ascii	"__u8\000"
$LASF194:
	.ascii	"pdata\000"
$LASF232:
	.ascii	"jiffies\000"
$LASF282:
	.ascii	"/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co"
	.ascii	"_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/bu"
	.ascii	"ild_dir/target-mips_24kec_uClibc-0.9.33.2/linux-rtkmips_"
	.ascii	"rtl8198c/linux-3.10.49\000"
$LASF252:
	.ascii	"__init_begin\000"
$LASF72:
	.ascii	"nf_afinfo\000"
$LASF211:
	.ascii	"proc_dir_entry\000"
$LASF69:
	.ascii	"IPPROTO_UDPLITE\000"
$LASF216:
	.ascii	"cpu_data\000"
$LASF203:
	.ascii	"fastpath_l2tp_single_write\000"
$LASF155:
	.ascii	"l2tp_tmp\000"
$LASF67:
	.ascii	"IPPROTO_COMP\000"
$LASF103:
	.ascii	"IFLA_NET_NS_FD\000"
$LASF22:
	.ascii	"loff_t\000"
$LASF1:
	.ascii	"unsigned char\000"
$LASF14:
	.ascii	"__kernel_loff_t\000"
$LASF76:
	.ascii	"IFLA_ADDRESS\000"
$LASF258:
	.ascii	"inet_ehash_secret\000"
$LASF187:
	.ascii	"set_l2tp_device\000"
$LASF144:
	.ascii	"l2tp_ext_hdr\000"
$LASF126:
	.ascii	"RTAX_RTO_MIN\000"
$LASF190:
	.ascii	"p_id\000"
$LASF120:
	.ascii	"RTAX_CWND\000"
$LASF193:
	.ascii	"l2tp_ptr\000"
$LASF18:
	.ascii	"__sum16\000"
$LASF212:
	.ascii	"frag_percpu_counter_batch\000"
$LASF253:
	.ascii	"__init_end\000"
$LASF239:
	.ascii	"init_pid_ns\000"
$LASF28:
	.ascii	"list_head\000"
$LASF150:
	.ascii	"__current_thread_info\000"
$LASF271:
	.ascii	"state\000"
$LASF17:
	.ascii	"__be32\000"
$LASF88:
	.ascii	"IFLA_TXQLEN\000"
$LASF265:
	.ascii	"arp_tbl\000"
$LASF214:
	.ascii	"res1\000"
$LASF161:
	.ascii	"__mask\000"
$LASF112:
	.ascii	"iphdr\000"
$LASF54:
	.ascii	"IPPROTO_TCP\000"
$LASF0:
	.ascii	"signed char\000"
$LASF136:
	.ascii	"ND_OPT_MTU\000"
$LASF90:
	.ascii	"IFLA_WEIGHT\000"
$LASF5:
	.ascii	"short unsigned int\000"
$LASF227:
	.ascii	"flush_data_cache_page\000"
$LASF19:
	.ascii	"__wsum\000"
$LASF284:
	.ascii	"get_ppp_stats\000"
$LASF82:
	.ascii	"IFLA_STATS\000"
$LASF219:
	.ascii	"nr_cpu_ids\000"
$LASF108:
	.ascii	"IFLA_CARRIER\000"
$LASF149:
	.ascii	"current_thread_info\000"
$LASF38:
	.ascii	"double\000"
$LASF147:
	.ascii	"check_for_fast_l2tp_to_wan\000"
$LASF84:
	.ascii	"IFLA_PRIORITY\000"
$LASF37:
	.ascii	"plat_smp_ops\000"
$LASF240:
	.ascii	"percpu_counter_batch\000"
$LASF33:
	.ascii	"atomic_long_t\000"
$LASF275:
	.ascii	"set_l2tp_device_fphook\000"
$LASF160:
	.ascii	"__size\000"
$LASF182:
	.ascii	"new_skb\000"
$LASF59:
	.ascii	"IPPROTO_DCCP\000"
$LASF77:
	.ascii	"IFLA_BROADCAST\000"
$LASF130:
	.ascii	"udphdr\000"
$LASF163:
	.ascii	"__cu_to_r\000"
$LASF49:
	.ascii	"sk_buff\000"
$LASF70:
	.ascii	"IPPROTO_RAW\000"
$LASF183:
	.ascii	"strcmp\000"
	.ident	"GCC: (OpenWrt/Linaro GCC 4.8-2014.04 r32620) 4.8.3"
