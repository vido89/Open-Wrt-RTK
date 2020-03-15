	.file	1 "filter.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 3
	.text
	.align	2
	.set	nomips16
	.ent	dos_pkt_locate
	.type	dos_pkt_locate, @function
dos_pkt_locate:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	lw	$2,12($4)
	lui	$3,%hi(ConnectedIp)
	addiu	$3,$3,%lo(ConnectedIp)
	andi	$4,$2,0xff
	sll	$4,$4,2
	addu	$3,$4,$3
	andi	$4,$2,0x3ff
	lw	$5,0($3)
	sll	$3,$4,2
	sll	$4,$4,5
	addu	$4,$3,$4
	lui	$3,%hi(dos_pkt)
	addiu	$3,$3,%lo(dos_pkt)
	addu	$3,$3,$4
	lw	$4,24($3)
	bne	$2,$5,$L2
	nop

	bne	$2,$4,$L3
	nop

	sb	$0,0($3)
	j	$31
	move	$2,$0

$L2:
	beq	$2,$4,$L5
	nop

$L3:
	lb	$4,0($3)
	nop
	bne	$4,$0,$L6
	nop

	sw	$2,24($3)
	li	$2,1			# 0x1
	sb	$2,0($3)
	lui	$2,%hi(cur_p_pkt)
	sw	$3,%lo(cur_p_pkt)($2)
	j	$31
	li	$2,1			# 0x1

$L5:
	lb	$4,0($3)
	li	$2,1			# 0x1
	bne	$4,$2,$L7
	nop

	lui	$2,%hi(cur_p_pkt)
	sw	$3,%lo(cur_p_pkt)($2)
	j	$31
	li	$2,1			# 0x1

$L6:
	j	$31
	move	$2,$0

$L7:
	j	$31
	move	$2,$0

	.set	macro
	.set	reorder
	.end	dos_pkt_locate
	.size	dos_pkt_locate, .-dos_pkt_locate
	.align	2
	.set	nomips16
	.ent	dos_single_open
	.type	dos_single_open, @function
dos_single_open:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	move	$4,$5
	lui	$25,%hi(single_open)
	lui	$5,%hi(dos_read_proc)
	move	$6,$0
	addiu	$5,$5,%lo(dos_read_proc)
	addiu	$25,$25,%lo(single_open)
	jr	$25
	nop

	.set	macro
	.set	reorder
	.end	dos_single_open
	.size	dos_single_open, .-dos_single_open
	.align	2
	.globl	filter_table_single_open
	.set	nomips16
	.ent	filter_table_single_open
	.type	filter_table_single_open, @function
filter_table_single_open:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	move	$4,$5
	lui	$25,%hi(single_open)
	lui	$5,%hi(filter_table_read_proc)
	move	$6,$0
	addiu	$5,$5,%lo(filter_table_read_proc)
	addiu	$25,$25,%lo(single_open)
	jr	$25
	nop

	.set	macro
	.set	reorder
	.end	filter_table_single_open
	.size	filter_table_single_open, .-filter_table_single_open
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"%s\012\000"
	.text
	.align	2
	.set	nomips16
	.ent	dos_read_proc
	.type	dos_read_proc, @function
dos_read_proc:
	.frame	$sp,24,$31		# vars= 0, regs= 1/0, args= 16, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	lui	$5,%hi($LC0)
	lui	$6,%hi(dos_flag)
	lui	$2,%hi(seq_printf)
	addiu	$5,$5,%lo($LC0)
	addiu	$2,$2,%lo(seq_printf)
	jalr	$2
	addiu	$6,$6,%lo(dos_flag)

	lw	$31,20($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	dos_read_proc
	.size	dos_read_proc, .-dos_read_proc
	.align	2
	.set	nomips16
	.ent	rtl_schedule_filter_fastpath
	.type	rtl_schedule_filter_fastpath, @function
rtl_schedule_filter_fastpath:
	.frame	$sp,32,$31		# vars= 8, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$16,24($sp)
	lui	$2,%hi(do_gettimeofday)
	addiu	$4,$sp,16
	addiu	$2,$2,%lo(do_gettimeofday)
	jalr	$2
	move	$16,$5

	lw	$2,16($sp)
	li	$3,-1037172736			# 0xffffffffc22e0000
	addiu	$3,$3,17671
	mult	$2,$3
	sra	$4,$2,31
	li	$6,-1840709632			# 0xffffffff92490000
	addiu	$6,$6,9363
	lw	$5,8($16)
	mfhi	$3
	addu	$3,$3,$2
	sra	$3,$3,16
	subu	$3,$3,$4
	addiu	$3,$3,4
	mult	$3,$6
	sra	$7,$3,31
	mfhi	$6
	addu	$6,$6,$3
	sra	$6,$6,2
	subu	$6,$6,$7
	sll	$7,$6,3
	subu	$6,$7,$6
	subu	$3,$3,$6
	li	$6,1			# 0x1
	sll	$3,$6,$3
	ori	$3,$3,0x80
	and	$5,$3,$5
	beq	$5,$0,$L18
	li	$3,-1851654144			# 0xffffffff91a20000

	ori	$3,$3,0xb3c5
	mult	$2,$3
	li	$5,-2004353024			# 0xffffffff88880000
	ori	$5,$5,0x8889
	lw	$6,0($16)
	mfhi	$3
	addu	$3,$3,$2
	sra	$3,$3,11
	mult	$2,$5
	subu	$3,$3,$4
	sra	$7,$3,31
	mfhi	$8
	addu	$2,$8,$2
	li	$8,715784192			# 0x2aaa0000
	ori	$8,$8,0xaaab
	mult	$3,$8
	sra	$2,$2,5
	subu	$2,$2,$4
	sra	$4,$2,31
	mfhi	$8
	sra	$8,$8,2
	subu	$7,$8,$7
	mult	$2,$5
	sll	$9,$7,3
	sll	$7,$7,5
	subu	$7,$7,$9
	subu	$3,$3,$7
	sll	$8,$3,2
	sll	$3,$3,6
	subu	$3,$3,$8
	mfhi	$5
	addu	$5,$5,$2
	sra	$5,$5,5
	subu	$4,$5,$4
	sll	$7,$4,2
	sll	$4,$4,6
	subu	$4,$4,$7
	subu	$2,$2,$4
	bne	$6,$0,$L14
	addu	$2,$3,$2

	lw	$3,4($16)
	nop
	bne	$3,$0,$L15
	nop

	j	$L13
	li	$2,1			# 0x1

$L14:
	sltu	$6,$2,$6
	bne	$6,$0,$L18
	nop

	lw	$3,4($16)
	nop
$L15:
	sltu	$2,$3,$2
	j	$L13
	xori	$2,$2,0x1

$L18:
	move	$2,$0
$L13:
	lw	$31,28($sp)
	lw	$16,24($sp)
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	rtl_schedule_filter_fastpath
	.size	rtl_schedule_filter_fastpath, .-rtl_schedule_filter_fastpath
	.align	2
	.set	nomips16
	.ent	rtl_ip_range_filter_fastpath
	.type	rtl_ip_range_filter_fastpath, @function
rtl_ip_range_filter_fastpath:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$2,%hi(rtl_ip_hdr)
	addiu	$2,$2,%lo(rtl_ip_hdr)
	jalr	$2
	move	$16,$5

	lw	$2,12($2)
	lw	$3,0($16)
	nop
	sltu	$3,$2,$3
	bne	$3,$0,$L23
	nop

	lw	$3,4($16)
	nop
	sltu	$2,$3,$2
	j	$L22
	xori	$2,$2,0x1

$L23:
	move	$2,$0
$L22:
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	rtl_ip_range_filter_fastpath
	.size	rtl_ip_range_filter_fastpath, .-rtl_ip_range_filter_fastpath
	.align	2
	.set	nomips16
	.ent	dos_timer_fn
	.type	dos_timer_fn, @function
dos_timer_fn:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	lui	$13,%hi(item)
	lw	$12,%lo(item)($13)
	nop
	beq	$12,$0,$L60
	lui	$2,%hi(none_dos_drop_pkt_cnt)

	lui	$2,%hi(block_count)
	lui	$4,%hi(block_time)
	lw	$3,%lo(block_count)($2)
	lw	$4,%lo(block_time)($4)
	nop
	slt	$4,$3,$4
	beq	$4,$0,$L26
	lui	$4,%hi(block)

	lw	$5,%lo(block)($4)
	li	$4,1			# 0x1
	beq	$5,$4,$L27
	addiu	$3,$3,1

	j	$L58
	andi	$2,$12,0x1e

$L26:
	lui	$3,%hi(block)
	sw	$0,%lo(block)($3)
	j	$L28
	sw	$0,%lo(block_count)($2)

$L27:
	sw	$3,%lo(block_count)($2)
$L28:
	andi	$2,$12,0x1e
$L58:
	bne	$2,$0,$L52
	move	$7,$0

	lui	$2,%hi(dos_pkt)
	lui	$14,%hi(dos_pkt+36864)
	addiu	$2,$2,%lo(dos_pkt)
	addiu	$14,$14,%lo(dos_pkt+36864)
	j	$L29
	lui	$3,%hi(LogFlag)

$L52:
	lui	$2,%hi(dos_pkt)
	addiu	$2,$2,%lo(dos_pkt)
	li	$14,36864			# 0x9000
	addu	$14,$2,$14
	move	$6,$14
	move	$8,$0
	move	$3,$2
	li	$5,1			# 0x1
	andi	$10,$12,0x2
	andi	$9,$12,0x4
$L34:
	lb	$4,0($3)
	nop
	bne	$4,$5,$L30
	nop

	beq	$10,$0,$L31
	nop

	lw	$4,4($3)
	nop
	addu	$11,$8,$4
	slt	$4,$0,$4
	j	$L31
	movn	$8,$11,$4

$L43:
	lw	$4,8($3)
	nop
	addu	$11,$7,$4
	slt	$4,$0,$4
	movn	$7,$11,$4
$L30:
	addiu	$3,$3,36
$L59:
	bne	$3,$6,$L34
	nop

	lui	$3,%hi(whole_syn_threshold)
	lw	$3,%lo(whole_syn_threshold)($3)
	nop
	slt	$8,$3,$8
	beq	$8,$0,$L57
	andi	$12,$12,0x2

	beq	$12,$0,$L57
	nop

	bgtz	$3,$L55
	nop

$L57:
	j	$L35
	lui	$3,%hi(LogFlag)

$L55:
	lui	$3,%hi(LogFlag)
	lw	$4,%lo(LogFlag)($3)
	nop
	ori	$4,$4,0x2
	sw	$4,%lo(LogFlag)($3)
$L35:
	lui	$4,%hi(whole_fin_threshold)
	lw	$4,%lo(whole_fin_threshold)($4)
	nop
	slt	$7,$4,$7
	beq	$7,$0,$L29
	nop

	lw	$5,%lo(item)($13)
	nop
	andi	$5,$5,0x4
	beq	$5,$0,$L29
	nop

	blez	$4,$L29
	nop

	lw	$4,%lo(LogFlag)($3)
	nop
	ori	$4,$4,0x4
	sw	$4,%lo(LogFlag)($3)
$L29:
	sw	$0,%lo(LogFlag)($3)
	move	$3,$14
$L38:
	sb	$0,0($2)
	sw	$0,24($2)
	sw	$0,4($2)
	sw	$0,8($2)
	sw	$0,12($2)
	sw	$0,16($2)
	sw	$0,20($2)
	addiu	$2,$2,36
	bne	$2,$3,$L38
	nop

	lui	$2,%hi(none_dos_drop_pkt_cnt)
$L60:
	lw	$3,%lo(none_dos_drop_pkt_cnt)($2)
	nop
	sltu	$4,$3,3001
	bne	$4,$0,$L39
	lui	$4,%hi(item_backup)

	lw	$3,%lo(item)($13)
	nop
	beq	$3,$0,$L45
	nop

	sw	$3,%lo(item_backup)($4)
	lui	$3,%hi(item)
	j	$L45
	sw	$0,%lo(item)($3)

$L39:
	lw	$5,%lo(item_backup)($4)
	nop
	beq	$5,$0,$L41
	nop

	sw	$5,%lo(item)($13)
	sw	$0,%lo(item_backup)($4)
$L41:
	beq	$3,$0,$L42
	nop

$L45:
	sw	$0,%lo(none_dos_drop_pkt_cnt)($2)
$L42:
	lui	$2,%hi(jiffies)
	lw	$5,%lo(jiffies)($2)
	lui	$4,%hi(dos_timer)
	lui	$25,%hi(mod_timer)
	addiu	$4,$4,%lo(dos_timer)
	addiu	$5,$5,100
	addiu	$25,$25,%lo(mod_timer)
	jr	$25
	nop

$L31:
	bne	$9,$0,$L43
	nop

	j	$L59
	addiu	$3,$3,36

	.set	macro
	.set	reorder
	.end	dos_timer_fn
	.size	dos_timer_fn, .-dos_timer_fn
	.section	.rodata.str1.4
	.align	2
$LC1:
	.ascii	"br-lan\000"
	.text
	.align	2
	.set	nomips16
	.ent	GenerateTCPENDACK
	.type	GenerateTCPENDACK, @function
GenerateTCPENDACK:
	.frame	$sp,112,$31		# vars= 56, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-112
	sw	$31,108($sp)
	sw	$fp,104($sp)
	sw	$23,100($sp)
	sw	$22,96($sp)
	sw	$21,92($sp)
	sw	$20,88($sp)
	sw	$19,84($sp)
	sw	$18,80($sp)
	sw	$17,76($sp)
	sw	$16,72($sp)
	lui	$2,%hi(rtl_get_dev_by_name)
	move	$19,$4
	lui	$4,%hi($LC1)
	addiu	$4,$4,%lo($LC1)
	addiu	$2,$2,%lo(rtl_get_dev_by_name)
	.set	noreorder
	.set	nomacro
	jalr	$2
	lui	$20,%hi(rtl_ip_hdr)
	.set	macro
	.set	reorder

	addiu	$20,$20,%lo(rtl_ip_hdr)
	move	$4,$19
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$18,$2
	.set	macro
	.set	reorder

	lbu	$16,0($2)
	move	$17,$2
	lui	$2,%hi(endStateClientPort)
	andi	$16,$16,0xf
	sll	$16,$16,2
	addu	$16,$17,$16
	lhu	$2,%lo(endStateClientPort)($2)
	lhu	$3,0($16)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$3,$2,$L62
	lui	$2,%hi(endStateClientSeq)
	.set	macro
	.set	reorder

	lw	$3,4($16)
	lw	$2,%lo(endStateClientSeq)($2)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$3,$2,$L62
	lui	$2,%hi(rtl_neigh_lookup)
	.set	macro
	.set	reorder

	move	$5,$18
	addiu	$2,$2,%lo(rtl_neigh_lookup)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$17,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L62
	move	$18,$2
	.set	macro
	.set	reorder

	lui	$22,%hi(rtl_get_hh_from_neigh)
	addiu	$22,$22,%lo(rtl_get_hh_from_neigh)
	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L82
	lui	$2,%hi(skb_copy_expand)
	.set	macro
	.set	reorder

	move	$4,$19
	li	$5,128			# 0x80
	move	$6,$0
	addiu	$2,$2,%lo(skb_copy_expand)
	.set	noreorder
	.set	nomacro
	jalr	$2
	li	$7,32			# 0x20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L65
	move	$21,$2
	.set	macro
	.set	reorder

$L82:
 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$16,20($18)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$16,$16,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$16,20($18)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$16,$0,$L62
	lui	$2,%hi(neigh_destroy)
	.set	macro
	.set	reorder

	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$18
	.set	macro
	.set	reorder

	j	$L62
$L65:
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$4,$2
	.set	macro
	.set	reorder

	lbu	$5,0($2)
	lui	$2,%hi(skb_trim)
	move	$4,$21
	andi	$5,$5,0xf
	addiu	$5,$5,5
	addiu	$2,$2,%lo(skb_trim)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sll	$5,$5,2
	.set	macro
	.set	reorder

	lui	$2,%hi(skb_put)
	move	$5,$0
	addiu	$2,$2,%lo(skb_put)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$21
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$18
	.set	macro
	.set	reorder

	move	$5,$2
	move	$22,$2
	lui	$2,%hi(rtl_get_lock_from_hh)
	addiu	$2,$2,%lo(rtl_get_lock_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$sp,64
	.set	macro
	.set	reorder

	lw	$2,64($sp)
	#nop
	andi	$2,$2,0x1
$L67:
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L67
	lui	$23,%hi(rtl_get_skb_data)
	.set	macro
	.set	reorder

	addiu	$23,$23,%lo(rtl_get_skb_data)
	.set	noreorder
	.set	nomacro
	jalr	$23
	move	$4,$21
	.set	macro
	.set	reorder

	move	$20,$2
	lui	$2,%hi(rtl_get_data_from_hh)
	addiu	$2,$2,%lo(rtl_get_data_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$22
	.set	macro
	.set	reorder

	addiu	$4,$20,-16
	lui	$20,%hi(memcpy)
	move	$5,$2
	addiu	$20,$20,%lo(memcpy)
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,16			# 0x10
	.set	macro
	.set	reorder

	lui	$2,%hi(rtl_get_len_from_hh)
	addiu	$2,$2,%lo(rtl_get_len_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$22
	.set	macro
	.set	reorder

	move	$5,$2
	lui	$2,%hi(skb_push)
	addiu	$2,$2,%lo(skb_push)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$21
	.set	macro
	.set	reorder

 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$22,20($18)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$22,$22,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$22,20($18)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$22,$0,$L84
	lui	$2,%hi(rtl_set_skb_nfct)
	.set	macro
	.set	reorder

	lui	$2,%hi(neigh_destroy)
	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$18
	.set	macro
	.set	reorder

	lui	$2,%hi(rtl_set_skb_nfct)
$L84:
	move	$4,$21
	addiu	$2,$2,%lo(rtl_set_skb_nfct)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$5,$0
	.set	macro
	.set	reorder

	lhu	$3,2($16)
	lw	$4,36($sp)
	li	$2,268369920			# 0xfff0000
	ori	$2,$2,0xffff
	sh	$3,24($sp)
	and	$2,$4,$2
	li	$3,1342177280			# 0x50000000
	or	$2,$2,$3
	lhu	$6,0($16)
	lw	$3,4($16)
	lw	$5,8($16)
	sw	$2,36($sp)
	sb	$0,37($sp)
	lw	$2,36($sp)
	li	$7,-327680			# 0xfffffffffffb0000
	lui	$fp,%hi(url_cache)
	ori	$7,$7,0xffff
	and	$7,$2,$7
	li	$4,1048576			# 0x100000
	addiu	$18,$fp,%lo(url_cache)
	lhu	$2,12($18)
	or	$7,$7,$4
	li	$4,-131072			# 0xfffffffffffe0000
	ori	$4,$4,0xffff
	and	$7,$7,$4
	addiu	$3,$3,1
	sw	$7,36($sp)
	sh	$2,38($sp)
	lui	$2,%hi(rtl_get_skb_len)
	sw	$3,32($sp)
	move	$4,$21
	sh	$6,26($sp)
	sw	$5,28($sp)
	addiu	$2,$2,%lo(rtl_get_skb_len)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sh	$0,42($sp)
	.set	macro
	.set	reorder

	lw	$3,12($16)
	addiu	$22,$2,-34
	li	$16,20			# 0x14
	srl	$3,$3,28
	sll	$3,$3,2
	.set	noreorder
	.set	nomacro
	j	$L79
	li	$7,8			# 0x8
	.set	macro
	.set	reorder

$L74:
	lbu	$4,0($2)
	#nop
	sltu	$5,$4,2
	.set	noreorder
	.set	nomacro
	beq	$5,$0,$L70
	addiu	$6,$16,2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L79
	addiu	$16,$16,1
	.set	macro
	.set	reorder

$L70:
	lbu	$2,1($2)
	.set	noreorder
	.set	nomacro
	bne	$4,$7,$L79
	addu	$16,$16,$2
	.set	macro
	.set	reorder

	subu	$16,$16,$2
	addiu	$2,$sp,24
	addu	$2,$2,$6
	addiu	$4,$sp,20
	sw	$2,68($sp)
	move	$5,$2
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	addiu	$16,$16,6
	addiu	$3,$sp,24
	addu	$16,$3,$16
	addiu	$4,$sp,16
	move	$5,$16
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	lw	$4,68($sp)
	addiu	$5,$sp,16
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	move	$4,$16
	addiu	$5,$sp,20
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L83
	sh	$0,40($sp)
	.set	macro
	.set	reorder

$L79:
	addiu	$4,$sp,24
	addu	$2,$4,$16
	sltu	$4,$16,$3
	bne	$4,$0,$L74
	sh	$0,40($sp)
$L83:
	lw	$2,12($17)
	move	$5,$22
	move	$6,$0
	sw	$2,68($sp)
	lui	$2,%hi(csum_partial)
	addiu	$4,$sp,24
	addiu	$2,$2,%lo(csum_partial)
	lw	$16,16($17)
	.set	noreorder
	.set	nomacro
	jalr	$2
	andi	$22,$22,0xffff
	.set	macro
	.set	reorder

	move	$4,$21
	lw	$3,68($sp)
	addiu	$22,$22,6
 #APP
 # 136 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_tcpudp_nofold
	.set	noat		
	addu	$16, $3		
	sltu	$1, $16, $3	
	addu	$16, $1		
	addu	$16, $22		
	sltu	$1, $16, $22	
	addu	$16, $1		
	addu	$16, $2		
	sltu	$1, $16, $2	
	addu	$16, $1		
	.set	pop
 # 0 "" 2
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $16, 16	
	addu	$16, $1		
	sltu	$1, $16, $1	
	srl	$16, $16, 16	
	addu	$16, $1		
	xori	$16, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	jalr	$23
	sh	$16,40($sp)
	.set	macro
	.set	reorder

	addiu	$4,$2,34
	addiu	$5,$sp,24
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,20			# 0x14
	.set	macro
	.set	reorder

	lw	$3,44($sp)
	li	$2,268369920			# 0xfff0000
	ori	$2,$2,0xffff
	and	$2,$3,$2
	li	$3,1073741824			# 0x40000000
	or	$2,$2,$3
	li	$3,-251723776			# 0xfffffffff0ff0000
	ori	$3,$3,0xffff
	and	$2,$2,$3
	li	$3,83886080			# 0x5000000
	or	$2,$2,$3
	sw	$2,44($sp)
	lw	$3,12($17)
	lbu	$2,14($18)
	li	$6,6			# 0x6
	sw	$3,60($sp)
	lw	$3,16($17)
	sb	$2,52($sp)
	lui	$2,%hi(rtl_set_skb_ip_summed)
	move	$4,$19
	move	$5,$0
	sb	$6,53($sp)
	sw	$3,56($sp)
	addiu	$2,$2,%lo(rtl_set_skb_ip_summed)
	sh	$0,50($sp)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sb	$0,45($sp)
	.set	macro
	.set	reorder

	lhu	$2,%lo(url_cache)($fp)
	li	$3,40			# 0x28
	sh	$3,46($sp)
	addiu	$2,$2,1
	sh	$2,48($sp)
	lw	$5,44($sp)
	lw	$6,48($sp)
	sh	$0,54($sp)
	lw	$3,52($sp)
	addu	$2,$6,$5
	lw	$4,56($sp)
	sltu	$6,$2,$6
	addu	$2,$2,$3
	addu	$6,$2,$6
	sltu	$3,$6,$3
	addu	$6,$6,$4
	addu	$3,$6,$3
	srl	$5,$5,22
	sltu	$2,$3,$4
	andi	$5,$5,0x3c
	addiu	$4,$sp,44
	addu	$2,$2,$3
	addu	$5,$4,$5
	addiu	$3,$sp,60
$L75:
	lw	$4,0($3)
	addiu	$3,$3,4
	addu	$2,$4,$2
	sltu	$4,$2,$4
	.set	noreorder
	.set	nomacro
	bne	$5,$3,$L75
	addu	$2,$4,$2
	.set	macro
	.set	reorder

	move	$4,$21
 #APP
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $2, 16	
	addu	$2, $1		
	sltu	$1, $2, $1	
	srl	$2, $2, 16	
	addu	$2, $1		
	xori	$2, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	jalr	$23
	sh	$2,54($sp)
	.set	macro
	.set	reorder

	addiu	$4,$2,14
	addiu	$5,$sp,44
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,20			# 0x14
	.set	macro
	.set	reorder

	lui	$2,%hi(dev_queue_xmit)
	move	$4,$21
	addiu	$2,$2,%lo(dev_queue_xmit)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sb	$0,16($18)
	.set	macro
	.set	reorder

$L62:
	lw	$31,108($sp)
	lw	$fp,104($sp)
	lw	$23,100($sp)
	lw	$22,96($sp)
	lw	$21,92($sp)
	lw	$20,88($sp)
	lw	$19,84($sp)
	lw	$18,80($sp)
	lw	$17,76($sp)
	lw	$16,72($sp)
	move	$2,$0
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,112
	.set	macro
	.set	reorder

	.end	GenerateTCPENDACK
	.size	GenerateTCPENDACK, .-GenerateTCPENDACK
	.align	2
	.set	nomips16
	.ent	GenerateTCPFINACK
	.type	GenerateTCPFINACK, @function
GenerateTCPFINACK:
	.frame	$sp,112,$31		# vars= 56, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-112
	sw	$31,108($sp)
	sw	$fp,104($sp)
	sw	$23,100($sp)
	sw	$22,96($sp)
	sw	$21,92($sp)
	sw	$20,88($sp)
	sw	$19,84($sp)
	sw	$18,80($sp)
	sw	$17,76($sp)
	sw	$16,72($sp)
	lui	$2,%hi(rtl_get_dev_by_name)
	move	$19,$4
	lui	$4,%hi($LC1)
	addiu	$4,$4,%lo($LC1)
	addiu	$2,$2,%lo(rtl_get_dev_by_name)
	.set	noreorder
	.set	nomacro
	jalr	$2
	lui	$20,%hi(rtl_ip_hdr)
	.set	macro
	.set	reorder

	addiu	$20,$20,%lo(rtl_ip_hdr)
	move	$4,$19
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$18,$2
	.set	macro
	.set	reorder

	lbu	$16,0($2)
	move	$17,$2
	lui	$2,%hi(finStateClientPort)
	andi	$16,$16,0xf
	sll	$16,$16,2
	addu	$16,$17,$16
	lhu	$2,%lo(finStateClientPort)($2)
	lhu	$3,0($16)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$3,$2,$L86
	lui	$2,%hi(finStateClientSeq)
	.set	macro
	.set	reorder

	lw	$3,4($16)
	lw	$2,%lo(finStateClientSeq)($2)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$3,$2,$L86
	lui	$2,%hi(rtl_neigh_lookup)
	.set	macro
	.set	reorder

	move	$5,$18
	addiu	$2,$2,%lo(rtl_neigh_lookup)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$17,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L86
	move	$18,$2
	.set	macro
	.set	reorder

	lui	$22,%hi(rtl_get_hh_from_neigh)
	addiu	$22,$22,%lo(rtl_get_hh_from_neigh)
	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L106
	lui	$2,%hi(skb_copy_expand)
	.set	macro
	.set	reorder

	move	$4,$19
	li	$5,128			# 0x80
	move	$6,$0
	addiu	$2,$2,%lo(skb_copy_expand)
	.set	noreorder
	.set	nomacro
	jalr	$2
	li	$7,32			# 0x20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L89
	move	$21,$2
	.set	macro
	.set	reorder

$L106:
 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$16,20($18)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$16,$16,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$16,20($18)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$16,$0,$L86
	lui	$2,%hi(neigh_destroy)
	.set	macro
	.set	reorder

	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$18
	.set	macro
	.set	reorder

	j	$L86
$L89:
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$4,$2
	.set	macro
	.set	reorder

	lbu	$5,0($2)
	lui	$2,%hi(skb_trim)
	move	$4,$21
	andi	$5,$5,0xf
	addiu	$5,$5,5
	addiu	$2,$2,%lo(skb_trim)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sll	$5,$5,2
	.set	macro
	.set	reorder

	lui	$2,%hi(skb_put)
	move	$5,$0
	addiu	$2,$2,%lo(skb_put)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$21
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$18
	.set	macro
	.set	reorder

	move	$5,$2
	move	$22,$2
	lui	$2,%hi(rtl_get_lock_from_hh)
	addiu	$2,$2,%lo(rtl_get_lock_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$sp,64
	.set	macro
	.set	reorder

	lw	$2,64($sp)
	#nop
	andi	$2,$2,0x1
$L91:
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L91
	lui	$23,%hi(rtl_get_skb_data)
	.set	macro
	.set	reorder

	addiu	$23,$23,%lo(rtl_get_skb_data)
	.set	noreorder
	.set	nomacro
	jalr	$23
	move	$4,$21
	.set	macro
	.set	reorder

	move	$20,$2
	lui	$2,%hi(rtl_get_data_from_hh)
	addiu	$2,$2,%lo(rtl_get_data_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$22
	.set	macro
	.set	reorder

	addiu	$4,$20,-16
	lui	$20,%hi(memcpy)
	move	$5,$2
	addiu	$20,$20,%lo(memcpy)
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,16			# 0x10
	.set	macro
	.set	reorder

	lui	$2,%hi(rtl_get_len_from_hh)
	addiu	$2,$2,%lo(rtl_get_len_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$22
	.set	macro
	.set	reorder

	move	$5,$2
	lui	$2,%hi(skb_push)
	addiu	$2,$2,%lo(skb_push)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$21
	.set	macro
	.set	reorder

 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$22,20($18)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$22,$22,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$22,20($18)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$22,$0,$L108
	lui	$2,%hi(rtl_set_skb_nfct)
	.set	macro
	.set	reorder

	lui	$2,%hi(neigh_destroy)
	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$18
	.set	macro
	.set	reorder

	lui	$2,%hi(rtl_set_skb_nfct)
$L108:
	move	$4,$21
	addiu	$2,$2,%lo(rtl_set_skb_nfct)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$5,$0
	.set	macro
	.set	reorder

	lhu	$3,2($16)
	lw	$4,36($sp)
	li	$2,268369920			# 0xfff0000
	ori	$2,$2,0xffff
	sh	$3,24($sp)
	and	$2,$4,$2
	li	$3,1342177280			# 0x50000000
	or	$2,$2,$3
	lhu	$6,0($16)
	lw	$3,4($16)
	lw	$5,8($16)
	sw	$2,36($sp)
	sb	$0,37($sp)
	lw	$4,36($sp)
	lui	$fp,%hi(url_cache)
	addiu	$18,$fp,%lo(url_cache)
	li	$7,-327680			# 0xfffffffffffb0000
	lhu	$2,12($18)
	ori	$7,$7,0xffff
	and	$7,$4,$7
	li	$4,1114112			# 0x110000
	or	$7,$7,$4
	sw	$7,36($sp)
	sh	$2,38($sp)
	lui	$2,%hi(rtl_get_skb_len)
	sw	$3,32($sp)
	move	$4,$21
	sh	$6,26($sp)
	sw	$5,28($sp)
	addiu	$2,$2,%lo(rtl_get_skb_len)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sh	$0,42($sp)
	.set	macro
	.set	reorder

	lw	$3,12($16)
	addiu	$22,$2,-34
	li	$16,20			# 0x14
	srl	$3,$3,28
	sll	$3,$3,2
	.set	noreorder
	.set	nomacro
	j	$L103
	li	$7,8			# 0x8
	.set	macro
	.set	reorder

$L98:
	lbu	$4,0($2)
	#nop
	sltu	$5,$4,2
	.set	noreorder
	.set	nomacro
	beq	$5,$0,$L94
	addiu	$6,$16,2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L103
	addiu	$16,$16,1
	.set	macro
	.set	reorder

$L94:
	lbu	$2,1($2)
	.set	noreorder
	.set	nomacro
	bne	$4,$7,$L103
	addu	$16,$16,$2
	.set	macro
	.set	reorder

	subu	$16,$16,$2
	addiu	$2,$sp,24
	addu	$2,$2,$6
	addiu	$4,$sp,20
	sw	$2,68($sp)
	move	$5,$2
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	addiu	$16,$16,6
	addiu	$3,$sp,24
	addu	$16,$3,$16
	addiu	$4,$sp,16
	move	$5,$16
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	lw	$4,68($sp)
	addiu	$5,$sp,16
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	move	$4,$16
	addiu	$5,$sp,20
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L107
	sh	$0,40($sp)
	.set	macro
	.set	reorder

$L103:
	addiu	$4,$sp,24
	addu	$2,$4,$16
	sltu	$4,$16,$3
	bne	$4,$0,$L98
	sh	$0,40($sp)
$L107:
	lw	$2,12($17)
	lhu	$3,26($sp)
	move	$5,$22
	sw	$2,68($sp)
	lui	$2,%hi(endStateClientPort)
	sh	$3,%lo(endStateClientPort)($2)
	lw	$3,32($sp)
	lui	$2,%hi(endStateClientSeq)
	move	$6,$0
	sw	$3,%lo(endStateClientSeq)($2)
	lui	$2,%hi(csum_partial)
	addiu	$4,$sp,24
	addiu	$2,$2,%lo(csum_partial)
	lw	$16,16($17)
	.set	noreorder
	.set	nomacro
	jalr	$2
	andi	$22,$22,0xffff
	.set	macro
	.set	reorder

	move	$4,$21
	lw	$3,68($sp)
	addiu	$22,$22,6
 #APP
 # 136 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_tcpudp_nofold
	.set	noat		
	addu	$16, $3		
	sltu	$1, $16, $3	
	addu	$16, $1		
	addu	$16, $22		
	sltu	$1, $16, $22	
	addu	$16, $1		
	addu	$16, $2		
	sltu	$1, $16, $2	
	addu	$16, $1		
	.set	pop
 # 0 "" 2
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $16, 16	
	addu	$16, $1		
	sltu	$1, $16, $1	
	srl	$16, $16, 16	
	addu	$16, $1		
	xori	$16, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	jalr	$23
	sh	$16,40($sp)
	.set	macro
	.set	reorder

	addiu	$4,$2,34
	addiu	$5,$sp,24
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,20			# 0x14
	.set	macro
	.set	reorder

	lw	$3,44($sp)
	li	$2,268369920			# 0xfff0000
	ori	$2,$2,0xffff
	and	$2,$3,$2
	li	$3,1073741824			# 0x40000000
	or	$2,$2,$3
	li	$3,-251723776			# 0xfffffffff0ff0000
	ori	$3,$3,0xffff
	and	$2,$2,$3
	li	$3,83886080			# 0x5000000
	or	$2,$2,$3
	sw	$2,44($sp)
	lw	$3,12($17)
	lbu	$2,14($18)
	li	$6,6			# 0x6
	sw	$3,60($sp)
	lw	$3,16($17)
	sb	$2,52($sp)
	lui	$2,%hi(rtl_set_skb_ip_summed)
	move	$4,$19
	move	$5,$0
	sb	$6,53($sp)
	sw	$3,56($sp)
	addiu	$2,$2,%lo(rtl_set_skb_ip_summed)
	sh	$0,50($sp)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sb	$0,45($sp)
	.set	macro
	.set	reorder

	lhu	$2,%lo(url_cache)($fp)
	li	$3,40			# 0x28
	sh	$3,46($sp)
	addiu	$2,$2,1
	sh	$2,48($sp)
	lw	$5,44($sp)
	lw	$6,48($sp)
	sh	$0,54($sp)
	lw	$3,52($sp)
	addu	$2,$6,$5
	lw	$4,56($sp)
	sltu	$6,$2,$6
	addu	$2,$2,$3
	addu	$6,$2,$6
	sltu	$3,$6,$3
	addu	$6,$6,$4
	addu	$3,$6,$3
	srl	$5,$5,22
	sltu	$2,$3,$4
	andi	$5,$5,0x3c
	addiu	$4,$sp,44
	addu	$2,$2,$3
	addu	$5,$4,$5
	addiu	$3,$sp,60
$L99:
	lw	$4,0($3)
	addiu	$3,$3,4
	addu	$2,$4,$2
	sltu	$4,$2,$4
	.set	noreorder
	.set	nomacro
	bne	$5,$3,$L99
	addu	$2,$4,$2
	.set	macro
	.set	reorder

	move	$4,$21
 #APP
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $2, 16	
	addu	$2, $1		
	sltu	$1, $2, $1	
	srl	$2, $2, 16	
	addu	$2, $1		
	xori	$2, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	jalr	$23
	sh	$2,54($sp)
	.set	macro
	.set	reorder

	addiu	$4,$2,14
	addiu	$5,$sp,44
	.set	noreorder
	.set	nomacro
	jalr	$20
	li	$6,20			# 0x14
	.set	macro
	.set	reorder

	li	$2,1			# 0x1
	sb	$2,16($18)
	lui	$2,%hi(dev_queue_xmit)
	move	$4,$21
	addiu	$2,$2,%lo(dev_queue_xmit)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sb	$0,15($18)
	.set	macro
	.set	reorder

$L86:
	lw	$31,108($sp)
	lw	$fp,104($sp)
	lw	$23,100($sp)
	lw	$22,96($sp)
	lw	$21,92($sp)
	lw	$20,88($sp)
	lw	$19,84($sp)
	lw	$18,80($sp)
	lw	$17,76($sp)
	lw	$16,72($sp)
	move	$2,$0
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,112
	.set	macro
	.set	reorder

	.end	GenerateTCPFINACK
	.size	GenerateTCPFINACK, .-GenerateTCPFINACK
	.section	.rodata.str1.4
	.align	2
$LC2:
	.ascii	"HTTP/1.1 401 The web site is blocked by administrator\015"
	.ascii	"\012Server: Embedded HTTP Server 2.00\015\012Connection:"
	.ascii	" close\015\012\015\012<HTML><HEAD><TITLE>401 The web sit"
	.ascii	"e is blocked by administrator</TITLE></HEAD>\012<BODY BG"
	.ascii	"COLOR=\"#ffffff\"><H4>401 The web site is blocked by adm"
	.ascii	"inistrator</H4></BODY></HTML>\012\000"
	.text
	.align	2
	.globl	GenerateHTTP401
	.set	nomips16
	.ent	GenerateHTTP401
	.type	GenerateHTTP401, @function
GenerateHTTP401:
	.frame	$sp,176,$31		# vars= 120, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-176
	sw	$31,172($sp)
	sw	$fp,168($sp)
	sw	$23,164($sp)
	sw	$22,160($sp)
	sw	$21,156($sp)
	sw	$20,152($sp)
	sw	$19,148($sp)
	sw	$18,144($sp)
	sw	$17,140($sp)
	sw	$16,136($sp)
	lui	$2,%hi(rtl_get_dev_by_name)
	move	$21,$4
	lui	$4,%hi($LC1)
	addiu	$4,$4,%lo($LC1)
	addiu	$2,$2,%lo(rtl_get_dev_by_name)
	.set	noreorder
	.set	nomacro
	jalr	$2
	lui	$17,%hi(rtl_ip_hdr)
	.set	macro
	.set	reorder

	addiu	$17,$17,%lo(rtl_ip_hdr)
	move	$4,$21
	.set	noreorder
	.set	nomacro
	jalr	$17
	move	$16,$2
	.set	macro
	.set	reorder

	addiu	$4,$2,12
	lui	$2,%hi(rtl_neigh_lookup)
	addiu	$2,$2,%lo(rtl_neigh_lookup)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$5,$16
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L110
	move	$16,$2
	.set	macro
	.set	reorder

	lui	$18,%hi(rtl_get_hh_from_neigh)
	addiu	$18,$18,%lo(rtl_get_hh_from_neigh)
	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$4,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L136
	lui	$22,%hi(block_message)
	.set	macro
	.set	reorder

	lw	$4,%lo(block_message)($22)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L132
	lui	$2,%hi(strlen)
	.set	macro
	.set	reorder

	lui	$4,%hi($LC2)
	addiu	$4,$4,%lo($LC2)
$L132:
	addiu	$2,$2,%lo(strlen)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$2,132($sp)
	.set	macro
	.set	reorder

	move	$6,$2
	lui	$2,%hi(skb_copy_expand)
	move	$4,$21
	li	$5,128			# 0x80
	addiu	$2,$2,%lo(skb_copy_expand)
	.set	noreorder
	.set	nomacro
	jalr	$2
	li	$7,32			# 0x20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L115
	move	$20,$2
	.set	macro
	.set	reorder

$L136:
 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$17,20($16)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$17,$17,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$17,20($16)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$17,$0,$L110
	lui	$2,%hi(neigh_destroy)
	.set	macro
	.set	reorder

	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$16
	.set	macro
	.set	reorder

	j	$L110
$L115:
	.set	noreorder
	.set	nomacro
	jalr	$17
	move	$4,$2
	.set	macro
	.set	reorder

	move	$19,$2
	lbu	$2,0($2)
	#nop
	andi	$2,$2,0xf
	sll	$fp,$2,2
	addu	$fp,$19,$fp
	lw	$3,12($fp)
	#nop
	srl	$3,$3,28
	addu	$2,$2,$3
	sll	$5,$2,2
	lui	$2,%hi(skb_trim)
	addiu	$2,$2,%lo(skb_trim)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

	lw	$4,%lo(block_message)($22)
	#nop
	bne	$4,$0,$L133
	lui	$4,%hi($LC2)
	addiu	$4,$4,%lo($LC2)
$L133:
	lw	$3,132($sp)
	#nop
	jalr	$3
	move	$5,$2
	lui	$2,%hi(skb_put)
	addiu	$2,$2,%lo(skb_put)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$4,$16
	.set	macro
	.set	reorder

	move	$5,$2
	move	$17,$2
	lui	$2,%hi(rtl_get_lock_from_hh)
	addiu	$2,$2,%lo(rtl_get_lock_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$sp,128
	.set	macro
	.set	reorder

	lui	$2,%hi(local_bh_disable)
	addiu	$2,$2,%lo(local_bh_disable)
	jalr	$2
	lui	$3,%hi(rtl_get_skb_data)
	addiu	$3,$3,%lo(rtl_get_skb_data)
	.set	noreorder
	.set	nomacro
	jalr	$3
	move	$4,$20
	.set	macro
	.set	reorder

	move	$18,$2
	lui	$2,%hi(rtl_get_data_from_hh)
	addiu	$2,$2,%lo(rtl_get_data_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$17
	.set	macro
	.set	reorder

	lui	$23,%hi(memcpy)
	addiu	$4,$18,-16
	move	$5,$2
	addiu	$23,$23,%lo(memcpy)
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,16			# 0x10
	.set	macro
	.set	reorder

	lui	$2,%hi(local_bh_enable)
	addiu	$2,$2,%lo(local_bh_enable)
	jalr	$2
	lui	$2,%hi(rtl_get_len_from_hh)
	addiu	$2,$2,%lo(rtl_get_len_from_hh)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$17
	.set	macro
	.set	reorder

	move	$5,$2
	lui	$2,%hi(skb_push)
	addiu	$2,$2,%lo(skb_push)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

 #APP
 # 176 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	lui	$2,%hi(arch_local_irq_save)
	addiu	$2,$2,%lo(arch_local_irq_save)
	jalr	$2
	lw	$17,20($16)
	move	$4,$2
	lui	$2,%hi(arch_local_irq_restore)
	addiu	$17,$17,-1
	addiu	$2,$2,%lo(arch_local_irq_restore)
	.set	noreorder
	.set	nomacro
	jalr	$2
	sw	$17,20($16)
	.set	macro
	.set	reorder

 #APP
 # 215 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/atomic.h" 1
			

 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	bne	$17,$0,$L138
	lui	$2,%hi(rtl_set_skb_nfct)
	.set	macro
	.set	reorder

	lui	$2,%hi(neigh_destroy)
	addiu	$2,$2,%lo(neigh_destroy)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$16
	.set	macro
	.set	reorder

	lui	$2,%hi(rtl_set_skb_nfct)
$L138:
	addiu	$2,$2,%lo(rtl_set_skb_nfct)
	move	$4,$20
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$5,$0
	.set	macro
	.set	reorder

	lbu	$18,0($19)
	lw	$2,12($19)
	lw	$3,16($19)
	andi	$18,$18,0xf
	sll	$18,$18,2
	addu	$18,$19,$18
	sw	$3,12($19)
	sw	$2,16($19)
	lw	$16,12($18)
	lhu	$2,0($18)
	lhu	$3,2($18)
	lw	$17,%lo(block_message)($22)
	srl	$16,$16,28
	sll	$16,$16,2
	addu	$16,$18,$16
	sh	$3,0($18)
	.set	noreorder
	.set	nomacro
	beq	$17,$0,$L119
	sh	$2,2($18)
	.set	macro
	.set	reorder

	lw	$3,132($sp)
	#nop
	.set	noreorder
	.set	nomacro
	jalr	$3
	move	$4,$17
	.set	macro
	.set	reorder

	addiu	$6,$2,1
	move	$4,$16
	.set	noreorder
	.set	nomacro
	jalr	$23
	move	$5,$17
	.set	macro
	.set	reorder

	j	$L120
$L119:
	lw	$3,132($sp)
	lui	$17,%hi($LC2)
	.set	noreorder
	.set	nomacro
	jalr	$3
	addiu	$4,$17,%lo($LC2)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$16
	.set	noreorder
	.set	nomacro
	jalr	$23
	addiu	$5,$17,%lo($LC2)
	.set	macro
	.set	reorder

$L120:
	lw	$2,8($18)
	lw	$16,4($18)
	move	$4,$21
	sw	$2,4($18)
	lui	$21,%hi(rtl_get_skb_len)
	lui	$2,%hi(url_cache)
	addiu	$21,$21,%lo(rtl_get_skb_len)
	.set	noreorder
	.set	nomacro
	jalr	$21
	addiu	$17,$2,%lo(url_cache)
	.set	macro
	.set	reorder

	lw	$4,12($fp)
	lbu	$3,0($19)
	lhu	$5,12($17)
	sb	$0,13($18)
	andi	$3,$3,0xf
	sh	$5,14($18)
	srl	$4,$4,28
	lw	$5,12($18)
	addu	$4,$4,$3
	sll	$4,$4,2
	li	$3,-327680			# 0xfffffffffffb0000
	subu	$16,$16,$4
	ori	$3,$3,0xffff
	addu	$16,$16,$2
	and	$3,$5,$3
	li	$4,1572864			# 0x180000
	li	$2,-131072			# 0xfffffffffffe0000
	or	$3,$3,$4
	ori	$2,$2,0xffff
	and	$3,$3,$2
	sw	$16,8($18)
	sw	$3,12($18)
	sh	$0,18($18)
	.set	noreorder
	.set	nomacro
	jalr	$21
	move	$4,$20
	.set	macro
	.set	reorder

	lbu	$22,0($19)
	lw	$3,12($fp)
	li	$16,20			# 0x14
	andi	$22,$22,0xf
	subu	$22,$0,$22
	sll	$22,$22,2
	addiu	$22,$22,-14
	srl	$3,$3,28
	addu	$22,$22,$2
	sll	$3,$3,2
	.set	noreorder
	.set	nomacro
	j	$L131
	li	$6,8			# 0x8
	.set	macro
	.set	reorder

$L126:
	lbu	$4,0($2)
	#nop
	sltu	$5,$4,2
	.set	noreorder
	.set	nomacro
	beq	$5,$0,$L122
	addiu	$fp,$16,2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L131
	addiu	$16,$16,1
	.set	macro
	.set	reorder

$L122:
	lbu	$2,1($2)
	.set	noreorder
	.set	nomacro
	bne	$4,$6,$L131
	addu	$16,$16,$2
	.set	macro
	.set	reorder

	subu	$16,$16,$2
	addu	$fp,$18,$fp
	addiu	$16,$16,6
	addiu	$4,$sp,20
	move	$5,$fp
	addu	$16,$18,$16
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	addiu	$4,$sp,16
	move	$5,$16
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	move	$4,$fp
	addiu	$5,$sp,16
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	move	$4,$16
	addiu	$5,$sp,20
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,4			# 0x4
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L137
	lui	$2,%hi(csum_partial)
	.set	macro
	.set	reorder

$L131:
	sltu	$4,$16,$3
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L126
	addu	$2,$18,$16
	.set	macro
	.set	reorder

	lui	$2,%hi(csum_partial)
$L137:
	move	$5,$22
	sh	$0,16($18)
	move	$6,$0
	move	$4,$18
	addiu	$2,$2,%lo(csum_partial)
	andi	$22,$22,0xffff
	lw	$16,16($19)
	lw	$fp,12($19)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$22,$22,6
	.set	macro
	.set	reorder

	move	$4,$20
 #APP
 # 136 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_tcpudp_nofold
	.set	noat		
	addu	$16, $fp		
	sltu	$1, $16, $fp	
	addu	$16, $1		
	addu	$16, $22		
	sltu	$1, $16, $22	
	addu	$16, $1		
	addu	$16, $2		
	sltu	$1, $16, $2	
	addu	$16, $1		
	.set	pop
 # 0 "" 2
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $16, 16	
	addu	$16, $1		
	sltu	$1, $16, $1	
	srl	$16, $16, 16	
	addu	$16, $1		
	xori	$16, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	.set	noreorder
	.set	nomacro
	jalr	$21
	sh	$16,16($18)
	.set	macro
	.set	reorder

	lui	$3,%hi(url_cache)
	lhu	$4,%lo(url_cache)($3)
	lbu	$3,14($17)
	addiu	$2,$2,-14
	addiu	$4,$4,2
	sh	$2,2($19)
	sh	$4,4($19)
	sh	$0,6($19)
	lw	$5,0($19)
	lw	$6,4($19)
	sb	$3,8($19)
	sh	$0,10($19)
	lw	$3,8($19)
	addu	$2,$6,$5
	lw	$4,12($19)
	sltu	$6,$2,$6
	addu	$2,$2,$3
	addu	$6,$2,$6
	sltu	$3,$6,$3
	addu	$6,$6,$4
	addu	$3,$6,$3
	srl	$5,$5,22
	sltu	$2,$3,$4
	andi	$5,$5,0x3c
	addu	$2,$2,$3
	addu	$5,$19,$5
	addiu	$3,$19,16
$L127:
	lw	$4,0($3)
	addiu	$3,$3,4
	addu	$2,$4,$2
	sltu	$4,$2,$4
	.set	noreorder
	.set	nomacro
	bne	$5,$3,$L127
	addu	$2,$4,$2
	.set	macro
	.set	reorder

 #APP
 # 78 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/checksum.h" 1
		.set	push		# csum_fold
	.set	noat		
	sll	$1, $2, 16	
	addu	$2, $1		
	sltu	$1, $2, $1	
	srl	$2, $2, 16	
	addu	$2, $1		
	xori	$2, 0xffff	
	.set	pop
 # 0 "" 2
 #NO_APP
	lui	$3,%hi(rtl_get_skb_data)
	sh	$2,10($19)
	li	$2,1			# 0x1
	addiu	$3,$3,%lo(rtl_get_skb_data)
	move	$4,$20
	.set	noreorder
	.set	nomacro
	jalr	$3
	sb	$2,15($17)
	.set	macro
	.set	reorder

	move	$5,$2
	addiu	$4,$sp,24
	.set	noreorder
	.set	nomacro
	jalr	$23
	li	$6,54			# 0x36
	.set	macro
	.set	reorder

	lhu	$5,2($18)
	lw	$3,8($18)
	lui	$2,%hi(finStateClientPort)
	sh	$5,%lo(finStateClientPort)($2)
	lui	$2,%hi(finStateClientSeq)
	sw	$3,%lo(finStateClientSeq)($2)
	lui	$2,%hi(dev_queue_xmit)
	addiu	$2,$2,%lo(dev_queue_xmit)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

$L110:
	lw	$31,172($sp)
	lw	$fp,168($sp)
	lw	$23,164($sp)
	lw	$22,160($sp)
	lw	$21,156($sp)
	lw	$20,152($sp)
	lw	$19,148($sp)
	lw	$18,144($sp)
	lw	$17,140($sp)
	lw	$16,136($sp)
	move	$2,$0
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,176
	.set	macro
	.set	reorder

	.end	GenerateHTTP401
	.size	GenerateHTTP401, .-GenerateHTTP401
	.section	.rodata.str1.4
	.align	2
$LC3:
	.ascii	"type=%d num=%d\012\000"
	.align	2
$LC4:
	.ascii	"index=%d\011\000"
	.align	2
$LC5:
	.ascii	"mac=%02x:%02x:%02x:%02x:%02x:%02x\012\000"
	.align	2
$LC6:
	.ascii	"index=%d\011\011\000"
	.align	2
$LC7:
	.ascii	"url=%s\012\000"
	.align	2
$LC8:
	.ascii	"start=%x\011\000"
	.align	2
$LC9:
	.ascii	"end=%x\011\000"
	.align	2
$LC10:
	.ascii	"day=%x\012\000"
	.align	2
$LC11:
	.ascii	"unknow table type\012\000"
	.align	2
$LC12:
	.ascii	"Mode:%d %s\012\000"
	.text
	.align	2
	.set	nomips16
	.ent	filter_table_read_proc
	.type	filter_table_read_proc, @function
filter_table_read_proc:
	.frame	$sp,72,$31		# vars= 0, regs= 10/0, args= 32, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	sw	$23,60($sp)
	sw	$22,56($sp)
	sw	$21,52($sp)
	sw	$20,48($sp)
	sw	$19,44($sp)
	sw	$18,40($sp)
	sw	$17,36($sp)
	sw	$16,32($sp)
	lui	$16,%hi(kmalloc_caches)
	addiu	$16,$16,%lo(kmalloc_caches)
	sw	$4,72($sp)
	lw	$4,36($16)
	lui	$17,%hi(kmem_cache_alloc)
	addiu	$17,$17,%lo(kmem_cache_alloc)
	jalr	$17
	li	$5,208			# 0xd0

	beq	$2,$0,$L140
	move	$18,$2

	lui	$19,%hi(memset)
	move	$4,$2
	move	$5,$0
	addiu	$19,$19,%lo(memset)
	jalr	$19
	li	$6,512			# 0x200

	lw	$4,32($16)
	jalr	$17
	li	$5,208			# 0xd0

	bne	$2,$0,$L141
	move	$17,$2

	lui	$2,%hi(kfree)
	addiu	$2,$2,%lo(kfree)
	jalr	$2
	move	$4,$18

	j	$L140
	nop

$L141:
	move	$4,$2
	move	$5,$0
	jalr	$19
	li	$6,256			# 0x100

	lui	$2,%hi(table_list_head)
	lui	$19,%hi(sprintf)
	lw	$22,%lo(table_list_head)($2)
	addiu	$19,$19,%lo(sprintf)
	j	$L156
	lui	$23,%hi(strcat)

$L154:
	lw	$7,24($22)
	lw	$6,16($22)
	move	$4,$18
	addiu	$5,$2,%lo($LC3)
	jalr	$19
	addiu	$7,$7,-1

	lw	$2,16($22)
	li	$3,3			# 0x3
	beq	$2,$3,$L145
	li	$3,4			# 0x4

	beq	$2,$3,$L146
	li	$3,2			# 0x2

	bne	$2,$3,$L155
	lui	$5,%hi($LC11)

	lui	$fp,%hi($LC4)
	lw	$16,8($22)
	addiu	$21,$22,8
	j	$L147
	addiu	$fp,$fp,%lo($LC4)

$L148:
	lw	$6,20($16)
	jalr	$19
	nop

	move	$4,$18
	jalr	$20
	move	$5,$17

	lbu	$2,30($16)
	lbu	$6,28($16)
	lbu	$7,29($16)
	sw	$2,16($sp)
	lbu	$2,31($16)
	lui	$5,%hi($LC5)
	move	$4,$17
	sw	$2,20($sp)
	lbu	$2,32($16)
	addiu	$5,$5,%lo($LC5)
	sw	$2,24($sp)
	lbu	$2,33($16)
	jalr	$19
	sw	$2,28($sp)

	move	$4,$18
	jalr	$20
	move	$5,$17

	lw	$16,0($16)
$L147:
	move	$4,$17
	move	$5,$fp
	bne	$16,$21,$L148
	addiu	$20,$23,%lo(strcat)

	j	$L149
	nop

$L145:
	lw	$20,8($22)
	j	$L150
	addiu	$21,$22,8

$L151:
	lw	$6,20($20)
	jalr	$19
	nop

	move	$4,$18
	jalr	$16
	move	$5,$17

	lui	$5,%hi($LC7)
	addiu	$6,$20,28
	move	$4,$17
	jalr	$19
	addiu	$5,$5,%lo($LC7)

	move	$4,$18
	jalr	$16
	move	$5,$17

	lw	$20,0($20)
$L150:
	lui	$5,%hi($LC6)
	move	$4,$17
	addiu	$5,$5,%lo($LC6)
	bne	$20,$21,$L151
	addiu	$16,$23,%lo(strcat)

	j	$L149
	nop

$L146:
	lui	$fp,%hi($LC4)
	lw	$20,8($22)
	addiu	$21,$22,8
	j	$L152
	addiu	$fp,$fp,%lo($LC4)

$L153:
	lw	$6,20($20)
	jalr	$19
	nop

	move	$4,$18
	jalr	$16
	move	$5,$17

	lw	$6,28($20)
	lui	$5,%hi($LC8)
	move	$4,$17
	jalr	$19
	addiu	$5,$5,%lo($LC8)

	move	$4,$18
	jalr	$16
	move	$5,$17

	lw	$6,32($20)
	lui	$5,%hi($LC9)
	move	$4,$17
	jalr	$19
	addiu	$5,$5,%lo($LC9)

	move	$4,$18
	jalr	$16
	move	$5,$17

	lw	$6,36($20)
	lui	$2,%hi($LC10)
	move	$4,$17
	jalr	$19
	addiu	$5,$2,%lo($LC10)

	move	$4,$18
	jalr	$16
	move	$5,$17

	lw	$20,0($20)
$L152:
	move	$4,$17
	move	$5,$fp
	bne	$20,$21,$L153
	addiu	$16,$23,%lo(strcat)

	j	$L149
	nop

$L155:
	move	$4,$17
	jalr	$19
	addiu	$5,$5,%lo($LC11)

	move	$4,$18
	addiu	$2,$23,%lo(strcat)
	jalr	$2
	move	$5,$17

$L149:
	lw	$22,0($22)
	lui	$2,%hi(table_list_head)
$L156:
	addiu	$2,$2,%lo(table_list_head)
	bne	$22,$2,$L154
	lui	$2,%hi($LC3)

	lui	$2,%hi(url_filter_mode)
	lw	$6,%lo(url_filter_mode)($2)
	lw	$4,72($sp)
	lui	$5,%hi($LC12)
	lui	$2,%hi(seq_printf)
	addiu	$5,$5,%lo($LC12)
	move	$7,$18
	addiu	$2,$2,%lo(seq_printf)
	jalr	$2
	lui	$16,%hi(kfree)

	addiu	$16,$16,%lo(kfree)
	jalr	$16
	move	$4,$18

	jalr	$16
	move	$4,$17

$L140:
	lw	$31,68($sp)
	lw	$fp,64($sp)
	lw	$23,60($sp)
	lw	$22,56($sp)
	lw	$21,52($sp)
	lw	$20,48($sp)
	lw	$19,44($sp)
	lw	$18,40($sp)
	lw	$17,36($sp)
	lw	$16,32($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,72

	.set	macro
	.set	reorder
	.end	filter_table_read_proc
	.size	filter_table_read_proc, .-filter_table_read_proc
	.align	2
	.globl	rtl_mac_filter_fastpath
	.set	nomips16
	.ent	rtl_mac_filter_fastpath
	.type	rtl_mac_filter_fastpath, @function
rtl_mac_filter_fastpath:
	.frame	$sp,48,$31		# vars= 0, regs= 7/0, args= 16, gp= 0
	.mask	0x803f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-48
	sw	$31,44($sp)
	sw	$21,40($sp)
	sw	$20,36($sp)
	sw	$19,32($sp)
	sw	$18,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$20,%hi(rtl_skb_mac_header)
	move	$18,$4
	move	$19,$5
	li	$16,6			# 0x6
	addiu	$20,$20,%lo(rtl_skb_mac_header)
	li	$21,12			# 0xc
$L159:
	addu	$2,$19,$16
	lbu	$17,-6($2)
	jalr	$20
	move	$4,$18

	addu	$2,$2,$16
	lbu	$2,0($2)
	nop
	bne	$17,$2,$L160
	addiu	$16,$16,1

	bne	$16,$21,$L159
	li	$2,1			# 0x1

	j	$L158
	nop

$L160:
	move	$2,$0
$L158:
	lw	$31,44($sp)
	lw	$21,40($sp)
	lw	$20,36($sp)
	lw	$19,32($sp)
	lw	$18,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	j	$31
	addiu	$sp,$sp,48

	.set	macro
	.set	reorder
	.end	rtl_mac_filter_fastpath
	.size	rtl_mac_filter_fastpath, .-rtl_mac_filter_fastpath
	.align	2
	.set	nomips16
	.ent	find_pattern.constprop.8
	.type	find_pattern.constprop.8, @function
find_pattern.constprop.8:
	.frame	$sp,64,$31		# vars= 8, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-64
	sw	$31,60($sp)
	sw	$fp,56($sp)
	sw	$23,52($sp)
	sw	$22,48($sp)
	sw	$21,44($sp)
	sw	$20,40($sp)
	sw	$19,36($sp)
	sw	$18,32($sp)
	sw	$17,28($sp)
	sw	$16,24($sp)
	lw	$2,84($sp)
	lw	$3,80($sp)
	move	$17,$4
	sw	$0,0($2)
	subu	$2,$5,$7
	move	$16,$5
	move	$19,$7
	move	$23,$6
	sw	$0,0($3)
	move	$18,$4
	move	$20,$0
	move	$21,$0
	li	$22,13			# 0xd
	lui	$fp,%hi(memcmp)
	sw	$2,16($sp)
$L168:
	lb	$2,0($18)
	nop
	bne	$2,$22,$L163
	li	$3,10			# 0xa

	andi	$2,$20,0x1
	bne	$2,$0,$L173
	addiu	$20,$20,1

	j	$L180
	slt	$2,$20,4

$L163:
	bne	$2,$3,$L173
	andi	$2,$20,0x1

	beq	$2,$0,$L173
	addiu	$20,$20,1

	slt	$2,$20,4
$L180:
	bne	$2,$0,$L179
	move	$4,$18

	j	$L166
	move	$2,$0

$L173:
	move	$20,$0
	move	$4,$18
$L179:
	move	$5,$23
	addiu	$2,$fp,%lo(memcmp)
	jalr	$2
	move	$6,$19

	beq	$2,$0,$L167
	move	$3,$0

	lw	$3,16($sp)
	addiu	$21,$21,1
	sltu	$2,$3,$21
	beq	$2,$0,$L168
	addiu	$18,$18,1

	j	$L166
	move	$2,$0

$L167:
	lw	$2,80($sp)
	addu	$19,$21,$19
	sw	$19,0($2)
	j	$L169
	li	$5,13			# 0xd

$L170:
	bne	$4,$0,$L175
	addiu	$3,$3,1

$L169:
	addu	$2,$17,$19
	lb	$2,0($2)
	sltu	$4,$16,$19
	bne	$2,$5,$L170
	addiu	$19,$19,1

	lw	$2,84($sp)
	nop
	sw	$3,0($2)
	j	$L166
	li	$2,1			# 0x1

$L175:
	move	$2,$0
$L166:
	lw	$31,60($sp)
	lw	$fp,56($sp)
	lw	$23,52($sp)
	lw	$22,48($sp)
	lw	$21,44($sp)
	lw	$20,40($sp)
	lw	$19,36($sp)
	lw	$18,32($sp)
	lw	$17,28($sp)
	lw	$16,24($sp)
	j	$31
	addiu	$sp,$sp,64

	.set	macro
	.set	reorder
	.end	find_pattern.constprop.8
	.size	find_pattern.constprop.8, .-find_pattern.constprop.8
	.section	.rodata.str1.4
	.align	2
$LC13:
	.ascii	"GET \000"
	.align	2
$LC14:
	.ascii	"Host: \000"
	.align	2
$LC15:
	.ascii	"%s\000"
	.text
	.align	2
	.globl	rtl_url_filter_fastpath
	.set	nomips16
	.ent	rtl_url_filter_fastpath
	.type	rtl_url_filter_fastpath, @function
rtl_url_filter_fastpath:
	.frame	$sp,80,$31		# vars= 16, regs= 9/0, args= 24, gp= 0
	.mask	0x80ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-80
	sw	$31,76($sp)
	sw	$23,72($sp)
	sw	$22,68($sp)
	sw	$21,64($sp)
	sw	$20,60($sp)
	sw	$19,56($sp)
	sw	$18,52($sp)
	sw	$17,48($sp)
	sw	$16,44($sp)
	lui	$18,%hi(strlen)
	move	$16,$4
	addiu	$18,$18,%lo(strlen)
	move	$4,$5
	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$19,$5
	.set	macro
	.set	reorder

	sltu	$2,$2,2
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L193
	lui	$2,%hi(rtl_ip_hdr)
	.set	macro
	.set	reorder

	addiu	$2,$2,%lo(rtl_ip_hdr)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$16
	.set	macro
	.set	reorder

	lbu	$3,9($2)
	move	$17,$2
	li	$2,6			# 0x6
	.set	noreorder
	.set	nomacro
	bne	$3,$2,$L182
	move	$16,$0
	.set	macro
	.set	reorder

	lbu	$21,0($17)
	lui	$2,%hi(kmalloc_caches+44)
	lw	$4,%lo(kmalloc_caches+44)($2)
	andi	$21,$21,0xf
	sll	$21,$21,2
	addu	$21,$17,$21
	lw	$16,12($21)
	lui	$2,%hi(kmem_cache_alloc)
	addiu	$2,$2,%lo(kmem_cache_alloc)
	.set	noreorder
	.set	nomacro
	jalr	$2
	li	$5,208			# 0xd0
	.set	macro
	.set	reorder

	srl	$16,$16,28
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L193
	move	$20,$2
	.set	macro
	.set	reorder

	sll	$16,$16,2
	lbu	$2,0($17)
	addu	$21,$21,$16
	lui	$22,%hi($LC13)
	lui	$23,%hi(memcmp)
	move	$4,$21
	addiu	$5,$22,%lo($LC13)
	li	$6,4			# 0x4
	addiu	$23,$23,%lo(memcmp)
	lhu	$17,2($17)
	.set	noreorder
	.set	nomacro
	jalr	$23
	andi	$16,$2,0xf
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L187
	addiu	$2,$sp,32
	.set	macro
	.set	reorder

	sll	$16,$16,3
	subu	$16,$17,$16
	lui	$6,%hi($LC14)
	lui	$17,%hi(find_pattern.constprop.8)
	sw	$2,16($sp)
	addiu	$2,$sp,28
	move	$4,$21
	move	$5,$16
	addiu	$6,$6,%lo($LC14)
	li	$7,6			# 0x6
	addiu	$17,$17,%lo(find_pattern.constprop.8)
	.set	noreorder
	.set	nomacro
	jalr	$17
	sw	$2,20($sp)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L202
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

	lw	$2,28($sp)
	lw	$4,32($sp)
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L196
	addu	$4,$21,$4
	.set	macro
	.set	reorder

	move	$3,$20
 #APP
 # 55 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
1:	lbu	$1,($4)
	subu	$2,1
	sb	$1,($3)
	beqz	$1,2f
	addiu	$3,1
	bnez	$2,1b
	addiu	$4,1
2:
	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	lw	$2,28($sp)
	.set	noreorder
	.set	nomacro
	j	$L201
	addu	$2,$20,$2
	.set	macro
	.set	reorder

$L196:
	move	$2,$0
	addu	$2,$20,$2
$L201:
	sb	$0,0($2)
	addiu	$2,$sp,32
	sw	$2,16($sp)
	addiu	$2,$sp,24
	move	$4,$21
	move	$5,$16
	addiu	$6,$22,%lo($LC13)
	li	$7,4			# 0x4
	.set	noreorder
	.set	nomacro
	jalr	$17
	sw	$2,20($sp)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L202
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

	lw	$2,24($sp)
	#nop
	addiu	$2,$2,-9
	.set	noreorder
	.set	nomacro
	bgtz	$2,$L188
	sw	$2,24($sp)
	.set	macro
	.set	reorder

$L187:
	lui	$2,%hi(kfree)
$L202:
	addiu	$2,$2,%lo(kfree)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L182
	move	$16,$0
	.set	macro
	.set	reorder

$L188:
	lw	$3,28($sp)
	lw	$4,32($sp)
	addu	$3,$20,$3
	addu	$21,$21,$4
 #APP
 # 55 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
1:	lbu	$1,($21)
	subu	$2,1
	sb	$1,($3)
	beqz	$1,2f
	addiu	$3,1
	bnez	$2,1b
	addiu	$21,1
2:
	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	lw	$2,24($sp)
	lw	$3,28($sp)
	move	$4,$20
	addu	$2,$20,$2
	addu	$3,$2,$3
	.set	noreorder
	.set	nomacro
	jalr	$18
	sb	$0,0($3)
	.set	macro
	.set	reorder

	move	$4,$19
	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$17,$2
	.set	macro
	.set	reorder

	sltu	$17,$17,$2
	.set	noreorder
	.set	nomacro
	bne	$17,$0,$L197
	move	$16,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L191
	move	$17,$20
	.set	macro
	.set	reorder

$L192:
	.set	noreorder
	.set	nomacro
	jalr	$23
	addiu	$17,$17,1
	.set	macro
	.set	reorder

	beq	$2,$0,$L198
$L191:
	addu	$2,$17,$16
	lb	$2,0($2)
	move	$4,$17
	move	$5,$19
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L192
	move	$6,$16
	.set	macro
	.set	reorder

$L197:
	.set	noreorder
	.set	nomacro
	j	$L190
	move	$16,$0
	.set	macro
	.set	reorder

$L198:
	li	$16,1			# 0x1
$L190:
	lui	$6,%hi($LC15)
	lui	$4,%hi(log_info)
	lui	$2,%hi(snprintf)
	li	$5,32			# 0x20
	addiu	$6,$6,%lo($LC15)
	move	$7,$20
	addiu	$2,$2,%lo(snprintf)
	.set	noreorder
	.set	nomacro
	jalr	$2
	addiu	$4,$4,%lo(log_info)
	.set	macro
	.set	reorder

	lui	$2,%hi(kfree)
	addiu	$2,$2,%lo(kfree)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$20
	.set	macro
	.set	reorder

	lui	$2,%hi(url_filter_mode)
	lw	$2,%lo(url_filter_mode)($2)
	li	$3,1			# 0x1
	bne	$2,$3,$L182
	.set	noreorder
	.set	nomacro
	bne	$16,$0,$L199
	lui	$3,%hi(url_filter_flag)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L182
	sw	$2,%lo(url_filter_flag)($3)
	.set	macro
	.set	reorder

$L199:
	.set	noreorder
	.set	nomacro
	j	$L182
	li	$16,1			# 0x1
	.set	macro
	.set	reorder

$L193:
	move	$16,$0
$L182:
	move	$2,$16
	lw	$31,76($sp)
	lw	$23,72($sp)
	lw	$22,68($sp)
	lw	$21,64($sp)
	lw	$20,60($sp)
	lw	$19,56($sp)
	lw	$18,52($sp)
	lw	$17,48($sp)
	lw	$16,44($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,80
	.set	macro
	.set	reorder

	.end	rtl_url_filter_fastpath
	.size	rtl_url_filter_fastpath, .-rtl_url_filter_fastpath
	.section	.rodata.str1.4
	.align	2
$LC16:
	.ascii	"ppp0\000"
	.align	2
$LC17:
	.ascii	"eth1\000"
	.align	2
$LC18:
	.ascii	"wlan0\000"
	.text
	.align	2
	.globl	need_filter
	.set	nomips16
	.ent	need_filter
	.type	need_filter, @function
need_filter:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, gp= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$18,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	lui	$2,%hi(rtl_ip_hdr)
	addiu	$2,$2,%lo(rtl_ip_hdr)
	lui	$17,%hi($LC1)
	.set	noreorder
	.set	nomacro
	jalr	$2
	lui	$16,%hi(rtl_get_dev_by_name)
	.set	macro
	.set	reorder

	addiu	$16,$16,%lo(rtl_get_dev_by_name)
	addiu	$4,$17,%lo($LC1)
	.set	noreorder
	.set	nomacro
	jalr	$16
	move	$18,$2
	.set	macro
	.set	reorder

	beq	$2,$0,$L204
	lw	$4,372($2)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L204
	addiu	$4,$4,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L205
	addiu	$17,$17,%lo($LC1)
	.set	macro
	.set	reorder

$L207:
 #APP
 # 80 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$5,($2)
1:	lbu	$1,($3)
	addiu	$2,1
	bne	$1,$5,2f
	addiu	$3,1
	bnez	$5,1b
	lbu	$5,($2)
	nop
	move	$5,$1
2:	subu	$5,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	beq	$5,$0,$L206
	addiu	$4,$4,8
$L205:
	lw	$4,0($4)
	move	$2,$17
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L207
	addiu	$3,$4,43
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L225
	lui	$17,%hi($LC16)
	.set	macro
	.set	reorder

$L206:
	lw	$3,16($18)
	lw	$2,28($4)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$3,$2,$L208
	move	$2,$0
	.set	macro
	.set	reorder

$L204:
	lui	$17,%hi($LC16)
$L225:
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$4,$17,%lo($LC16)
	.set	macro
	.set	reorder

	beq	$2,$0,$L209
	lw	$4,372($2)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L224
	addiu	$4,$4,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L210
	addiu	$17,$17,%lo($LC16)
	.set	macro
	.set	reorder

$L212:
 #APP
 # 80 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$5,($2)
1:	lbu	$1,($3)
	addiu	$2,1
	bne	$1,$5,2f
	addiu	$3,1
	bnez	$5,1b
	lbu	$5,($2)
	nop
	move	$5,$1
2:	subu	$5,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	beq	$5,$0,$L211
	addiu	$4,$4,8
$L210:
	lw	$4,0($4)
	move	$2,$17
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L212
	addiu	$3,$4,43
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L208
	li	$2,1			# 0x1
	.set	macro
	.set	reorder

$L211:
	lw	$3,16($18)
	lw	$2,24($4)
	#nop
	xor	$2,$3,$2
	.set	noreorder
	.set	nomacro
	j	$L208
	sltu	$2,$0,$2
	.set	macro
	.set	reorder

$L209:
	lui	$17,%hi($LC17)
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$4,$17,%lo($LC17)
	.set	macro
	.set	reorder

	beq	$2,$0,$L213
	lw	$4,372($2)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L224
	addiu	$4,$4,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L214
	addiu	$17,$17,%lo($LC17)
	.set	macro
	.set	reorder

$L216:
 #APP
 # 80 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$5,($2)
1:	lbu	$1,($3)
	addiu	$2,1
	bne	$1,$5,2f
	addiu	$3,1
	bnez	$5,1b
	lbu	$5,($2)
	nop
	move	$5,$1
2:	subu	$5,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	beq	$5,$0,$L218
	addiu	$4,$4,8
$L214:
	lw	$4,0($4)
	move	$2,$17
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L216
	addiu	$3,$4,43
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L208
	li	$2,1			# 0x1
	.set	macro
	.set	reorder

$L213:
	lui	$17,%hi($LC18)
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$4,$17,%lo($LC18)
	.set	macro
	.set	reorder

	beq	$2,$0,$L224
	lw	$4,372($2)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L224
	addiu	$4,$4,12
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L217
	addiu	$17,$17,%lo($LC18)
	.set	macro
	.set	reorder

$L219:
 #APP
 # 80 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
	lbu	$5,($2)
1:	lbu	$1,($3)
	addiu	$2,1
	bne	$1,$5,2f
	addiu	$3,1
	bnez	$5,1b
	lbu	$5,($2)
	nop
	move	$5,$1
2:	subu	$5,$1
3:	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	beq	$5,$0,$L218
	addiu	$4,$4,8
$L217:
	lw	$4,0($4)
	move	$2,$17
	.set	noreorder
	.set	nomacro
	bne	$4,$0,$L219
	addiu	$3,$4,43
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L208
	li	$2,1			# 0x1
	.set	macro
	.set	reorder

$L218:
	lw	$3,16($18)
	lw	$2,28($4)
	#nop
	xor	$2,$3,$2
	.set	noreorder
	.set	nomacro
	j	$L208
	sltu	$2,$0,$2
	.set	macro
	.set	reorder

$L224:
	li	$2,1			# 0x1
$L208:
	lw	$31,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,32
	.set	macro
	.set	reorder

	.end	need_filter
	.size	need_filter, .-need_filter
	.align	2
	.globl	str2hexnum
	.set	nomips16
	.ent	str2hexnum
	.type	str2hexnum, @function
str2hexnum:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	j	$L227
	move	$2,$0

$L231:
	bne	$7,$0,$L228
	nop

	addiu	$5,$3,-65
	beq	$6,$0,$L229
	sltu	$5,$5,6

	j	$L228
	addiu	$5,$3,-87

$L229:
	beq	$5,$0,$L232
	nop

	addiu	$5,$3,-55
$L228:
	sll	$2,$2,4
	addu	$2,$5,$2
	addiu	$4,$4,1
$L227:
	lbu	$3,0($4)
	nop
	addiu	$5,$3,-48
	addiu	$6,$3,-97
	sltu	$7,$5,10
	bne	$3,$0,$L231
	sltu	$6,$6,6

	j	$31
	nop

$L232:
	j	$31
	li	$2,-1			# 0xffffffffffffffff

	.set	macro
	.set	reorder
	.end	str2hexnum
	.size	str2hexnum, .-str2hexnum
	.align	2
	.globl	filter_table_head_init
	.set	nomips16
	.ent	filter_table_head_init
	.type	filter_table_head_init, @function
filter_table_head_init:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$16,%hi(table_list_head)
	lui	$2,%hi(memset)
	addiu	$4,$16,%lo(table_list_head)
	move	$5,$0
	addiu	$2,$2,%lo(memset)
	jalr	$2
	li	$6,32			# 0x20

	lui	$3,%hi(table_list_head+8)
	addiu	$2,$16,%lo(table_list_head)
	addiu	$3,$3,%lo(table_list_head+8)
	sw	$3,8($2)
	sw	$3,12($2)
	li	$3,1			# 0x1
	sw	$2,4($2)
	sw	$0,16($2)
	sw	$0,20($2)
	sw	$0,28($2)
	sw	$3,24($2)
	sw	$2,%lo(table_list_head)($16)
	lw	$31,20($sp)
	lw	$16,16($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	filter_table_head_init
	.size	filter_table_head_init, .-filter_table_head_init
	.align	2
	.globl	filter_table_regist
	.set	nomips16
	.ent	filter_table_regist
	.type	filter_table_regist, @function
filter_table_regist:
	.frame	$sp,40,$31		# vars= 0, regs= 5/0, args= 16, gp= 0
	.mask	0x800f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$19,32($sp)
	sw	$18,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$17,%hi(table_list_head)
	addiu	$16,$17,%lo(table_list_head)
	lw	$2,24($16)
	move	$18,$4
	bne	$2,$0,$L235
	move	$19,$5

	lui	$2,%hi(filter_table_head_init)
	addiu	$2,$2,%lo(filter_table_head_init)
	jalr	$2
	nop

$L235:
	lui	$2,%hi(kmalloc_caches+20)
	lw	$4,%lo(kmalloc_caches+20)($2)
	lui	$2,%hi(kmem_cache_alloc)
	addiu	$2,$2,%lo(kmem_cache_alloc)
	jalr	$2
	li	$5,208			# 0xd0

	sw	$2,0($2)
	lw	$3,%lo(table_list_head)($17)
	addiu	$4,$2,8
	li	$5,1			# 0x1
	sw	$18,16($2)
	sw	$0,20($2)
	sw	$5,24($2)
	sw	$4,8($2)
	sw	$4,12($2)
	sw	$19,28($2)
	sw	$2,4($3)
	sw	$3,0($2)
	sw	$16,4($2)
	lw	$3,24($16)
	sw	$2,%lo(table_list_head)($17)
	lw	$31,36($sp)
	addiu	$3,$3,1
	sw	$3,24($16)
	lw	$19,32($sp)
	lw	$18,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,40

	.set	macro
	.set	reorder
	.end	filter_table_regist
	.size	filter_table_regist, .-filter_table_regist
	.align	2
	.globl	filter_table_flush
	.set	nomips16
	.ent	filter_table_flush
	.type	filter_table_flush, @function
filter_table_flush:
	.frame	$sp,56,$31		# vars= 0, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	sw	$23,44($sp)
	sw	$22,40($sp)
	sw	$21,36($sp)
	sw	$20,32($sp)
	sw	$19,28($sp)
	sw	$18,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	lui	$22,%hi(table_list_head)
	lw	$16,%lo(table_list_head)($22)
	li	$20,1048576			# 0x100000
	addiu	$22,$22,%lo(table_list_head)
	lw	$23,0($16)
	addiu	$20,$20,256
	j	$L237
	li	$fp,2097152			# 0x200000

$L241:
	lw	$2,8($16)
	addiu	$19,$3,%lo(kfree)
	addiu	$18,$16,8
	lw	$17,0($2)
	j	$L238
	addiu	$21,$fp,512

$L239:
	lw	$3,4($2)
	lw	$5,0($2)
	nop
	sw	$3,4($5)
	sw	$5,0($3)
	sw	$20,0($2)
	jalr	$19
	sw	$21,4($2)

	lw	$3,24($16)
	move	$2,$17
	addiu	$3,$3,-1
	sw	$3,24($16)
	lw	$17,0($17)
$L238:
	bne	$2,$18,$L239
	move	$4,$2

	lw	$3,16($16)
	li	$2,3			# 0x3
	bne	$3,$2,$L240
	li	$2,1			# 0x1

	lw	$3,24($16)
	nop
	bne	$3,$2,$L240
	lui	$3,%hi(Del_Pattern_ACL_For_ContentFilter)

	addiu	$2,$3,%lo(Del_Pattern_ACL_For_ContentFilter)
	jalr	$2
	nop

$L240:
	lw	$2,4($16)
	lw	$3,0($16)
	addiu	$5,$fp,512
	move	$4,$16
	sw	$2,4($3)
	sw	$3,0($2)
	sw	$20,0($16)
	jalr	$19
	sw	$5,4($16)

	lw	$2,24($22)
	move	$16,$23
	addiu	$2,$2,-1
	sw	$2,24($22)
	lw	$23,0($23)
$L237:
	bne	$16,$22,$L241
	lui	$3,%hi(kfree)

	li	$3,1			# 0x1
	lui	$2,%hi(filter_rule_num)
	sw	$3,%lo(filter_rule_num)($2)
	lw	$31,52($sp)
	lui	$2,%hi(log_enable)
	lw	$fp,48($sp)
	lw	$23,44($sp)
	lw	$22,40($sp)
	lw	$21,36($sp)
	lw	$20,32($sp)
	lw	$19,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	sw	$0,%lo(log_enable)($2)
	lui	$2,%hi(url_filter_mode)
	sw	$0,%lo(url_filter_mode)($2)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,56

	.set	macro
	.set	reorder
	.end	filter_table_flush
	.size	filter_table_flush, .-filter_table_flush
	.align	2
	.globl	filter_item_regist
	.set	nomips16
	.ent	filter_item_regist
	.type	filter_item_regist, @function
filter_item_regist:
	.frame	$sp,24,$31		# vars= 0, regs= 1/0, args= 16, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	lui	$2,%hi(table_list_head)
	lw	$3,%lo(table_list_head)($2)
	j	$L243
	addiu	$2,$2,%lo(table_list_head)

$L246:
	lw	$6,16($3)
	nop
	bne	$6,$4,$L244
	addiu	$6,$3,8

	lw	$2,8($3)
	nop
	sw	$5,4($2)
	sw	$2,0($5)
	sw	$6,4($5)
	lw	$2,24($3)
	sw	$5,8($3)
	addiu	$2,$2,1
	sw	$2,24($3)
	li	$3,3			# 0x3
	bne	$4,$3,$L248
	li	$3,2			# 0x2

	bne	$2,$3,$L248
	lui	$2,%hi(Add_Pattern_ACL_For_ContentFilter)

	addiu	$2,$2,%lo(Add_Pattern_ACL_For_ContentFilter)
	jalr	$2
	nop

	j	$L245
	move	$2,$0

$L244:
	lw	$3,0($3)
	nop
$L243:
	bne	$3,$2,$L246
	nop

	j	$L245
	li	$2,-1			# 0xffffffffffffffff

$L248:
	move	$2,$0
$L245:
	lw	$31,20($sp)
	nop
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	filter_item_regist
	.size	filter_item_regist, .-filter_item_regist
	.align	2
	.globl	check_esc_end
	.set	nomips16
	.ent	check_esc_end
	.type	check_esc_end, @function
check_esc_end:
	.frame	$sp,32,$31		# vars= 0, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$2,%hi(strlen)
	addiu	$2,$2,%lo(strlen)
	sll	$17,$5,24
	jalr	$2
	move	$16,$4

	sra	$17,$17,24
	addiu	$2,$2,-1
	j	$L250
	move	$3,$0

$L252:
	lb	$4,0($4)
	nop
	bne	$4,$17,$L251
	addiu	$2,$2,-1

	addiu	$3,$3,1
$L250:
	bgez	$2,$L252
	addu	$4,$16,$2

$L251:
	li	$2,-2147483648			# 0xffffffff80000000
	addiu	$2,$2,1
	and	$2,$3,$2
	bgez	$2,$L253
	li	$3,-2			# 0xfffffffffffffffe

	addiu	$2,$2,-1
	or	$2,$2,$3
	addiu	$2,$2,1
$L253:
	lw	$31,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	check_esc_end
	.size	check_esc_end, .-check_esc_end
	.section	.rodata.str1.4
	.align	2
$LC19:
	.ascii	"init\000"
	.align	2
$LC20:
	.ascii	" \000"
	.align	2
$LC21:
	.ascii	"flush\000"
	.align	2
$LC22:
	.ascii	"enable_log\000"
	.align	2
$LC23:
	.ascii	"white\000"
	.align	2
$LC24:
	.ascii	"black\000"
	.align	2
$LC25:
	.ascii	"add:\000"
	.align	2
$LC26:
	.ascii	"#\000"
	.align	2
$LC27:
	.ascii	";\000"
	.text
	.align	2
	.set	nomips16
	.ent	filter_table_single_write
	.type	filter_table_single_write, @function
filter_table_single_write:
	.frame	$sp,72,$31		# vars= 16, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-72
	sw	$31,68($sp)
	sw	$fp,64($sp)
	sw	$23,60($sp)
	sw	$22,56($sp)
	sw	$21,52($sp)
	sw	$20,48($sp)
	sw	$19,44($sp)
	sw	$18,40($sp)
	sw	$17,36($sp)
	sw	$16,32($sp)
	lui	$2,%hi(kmalloc_caches)
	addiu	$2,$2,%lo(kmalloc_caches)
	lw	$4,40($2)
	lui	$fp,%hi(kmem_cache_alloc)
	move	$16,$5
	addiu	$fp,$fp,%lo(kmem_cache_alloc)
	li	$5,208			# 0xd0
	.set	noreorder
	.set	nomacro
	jalr	$fp
	move	$17,$6
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L281
	move	$19,$2
	.set	macro
	.set	reorder

	lui	$21,%hi(memset)
	move	$5,$0
	li	$6,1024			# 0x400
	move	$4,$2
	lui	$18,%hi(get_info_from_usr_space)
	addiu	$21,$21,%lo(memset)
	.set	noreorder
	.set	nomacro
	jalr	$21
	lui	$20,%hi(strlen)
	.set	macro
	.set	reorder

	addiu	$20,$20,%lo(strlen)
	addiu	$4,$18,%lo(get_info_from_usr_space)
	.set	noreorder
	.set	nomacro
	jalr	$20
	sw	$19,16($sp)
	.set	macro
	.set	reorder

	move	$6,$2
	addiu	$4,$18,%lo(get_info_from_usr_space)
	.set	noreorder
	.set	nomacro
	jalr	$21
	move	$5,$0
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$16,$0,$L256
	or	$3,$16,$17
	.set	macro
	.set	reorder

	addu	$2,$16,$17
	or	$2,$3,$2
	lw	$3,24($28)
	#nop
	and	$2,$2,$3
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L282
	move	$23,$17
	.set	macro
	.set	reorder

	addiu	$4,$18,%lo(get_info_from_usr_space)
	move	$5,$16
	move	$6,$17
 #APP
 # 709 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/fastpath-0.1/filter_v2.c" 1
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
	j	$L257
$L282:
	move	$6,$17
$L257:
	.set	noreorder
	.set	nomacro
	bne	$6,$0,$L291
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$17,$0,$L258
	addiu	$3,$18,%lo(get_info_from_usr_space)
	.set	macro
	.set	reorder

	move	$2,$19
 #APP
 # 55 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
1:	lbu	$1,($3)
	subu	$17,1
	sb	$1,($2)
	beqz	$1,2f
	addiu	$2,1
	bnez	$17,1b
	addiu	$3,1
2:
	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
$L258:
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$18,%lo(get_info_from_usr_space)
	.set	macro
	.set	reorder

	addu	$2,$19,$2
	sb	$0,-1($2)
	lui	$16,%hi($LC19)
	lw	$17,16($sp)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$16,%lo($LC19)
	.set	macro
	.set	reorder

	addiu	$5,$16,%lo($LC19)
	lui	$16,%hi(memcmp)
	move	$4,$17
	addiu	$16,$16,%lo(memcmp)
	.set	noreorder
	.set	nomacro
	jalr	$16
	move	$6,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L259
	lui	$17,%hi($LC21)
	.set	macro
	.set	reorder

	lui	$3,%hi($LC20)
	addiu	$21,$sp,16
	lui	$17,%hi(strsep)
	sw	$3,24($sp)
	move	$4,$21
	addiu	$17,$17,%lo(strsep)
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$3,%lo($LC20)
	.set	macro
	.set	reorder

	lw	$2,16($sp)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L256
	lui	$22,%hi(str2hexnum)
	.set	macro
	.set	reorder

	lw	$4,24($sp)
	lui	$16,%hi(filter_tlb)
	lui	$18,%hi(filter_table_regist)
	addiu	$22,$22,%lo(str2hexnum)
	addiu	$16,$16,%lo(filter_tlb)
	addiu	$18,$18,%lo(filter_table_regist)
	addiu	$20,$4,%lo($LC20)
	move	$5,$20
$L294:
	.set	noreorder
	.set	nomacro
	jalr	$17
	move	$4,$21
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	sll	$3,$2,3
	addu	$3,$16,$3
	lw	$5,4($3)
	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$4,$2
	.set	macro
	.set	reorder

	lw	$2,16($sp)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L294
	move	$5,$20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L290
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

$L259:
	lw	$18,16($sp)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC21)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$18
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$5,$17,%lo($LC21)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L262
	lui	$17,%hi($LC22)
	.set	macro
	.set	reorder

	lui	$2,%hi(filter_table_flush)
	addiu	$2,$2,%lo(filter_table_flush)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$0
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L290
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

$L262:
	lw	$18,16($sp)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC22)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$18
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$5,$17,%lo($LC22)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L263
	li	$3,1			# 0x1
	.set	macro
	.set	reorder

	lui	$2,%hi(log_enable)
	.set	noreorder
	.set	nomacro
	j	$L261
	sw	$3,%lo(log_enable)($2)
	.set	macro
	.set	reorder

$L263:
	lw	$18,16($sp)
	lui	$17,%hi($LC23)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC23)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$18
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$5,$17,%lo($LC23)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L264
	li	$3,1			# 0x1
	.set	macro
	.set	reorder

	lui	$2,%hi(url_filter_mode)
	.set	noreorder
	.set	nomacro
	j	$L261
	sw	$3,%lo(url_filter_mode)($2)
	.set	macro
	.set	reorder

$L264:
	lw	$18,16($sp)
	lui	$17,%hi($LC24)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC24)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$18
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$5,$17,%lo($LC24)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L265
	lui	$2,%hi(url_filter_mode)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L261
	sw	$0,%lo(url_filter_mode)($2)
	.set	macro
	.set	reorder

$L265:
	lw	$18,16($sp)
	lui	$17,%hi($LC25)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC25)
	.set	macro
	.set	reorder

	move	$6,$2
	move	$4,$18
	.set	noreorder
	.set	nomacro
	jalr	$16
	addiu	$5,$17,%lo($LC25)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L290
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

	lw	$16,16($sp)
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$4,$17,%lo($LC25)
	.set	macro
	.set	reorder

	addu	$2,$16,$2
	sw	$2,16($sp)
	lb	$2,0($2)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L256
	addiu	$21,$sp,16
	.set	macro
	.set	reorder

	lui	$17,%hi(strsep)
	lui	$5,%hi($LC26)
	move	$4,$21
	addiu	$17,$17,%lo(strsep)
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$5,%lo($LC26)
	.set	macro
	.set	reorder

	lw	$3,16($sp)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$3,$0,$L256
	lui	$22,%hi(str2hexnum)
	.set	macro
	.set	reorder

	addiu	$22,$22,%lo(str2hexnum)
	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	li	$3,-1			# 0xffffffffffffffff
	.set	noreorder
	.set	nomacro
	beq	$2,$3,$L256
	lui	$2,%hi($LC20)
	.set	macro
	.set	reorder

	sw	$2,24($sp)
	move	$4,$21
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$2,%lo($LC20)
	.set	macro
	.set	reorder

	lw	$3,16($sp)
	#nop
	beq	$3,$0,$L256
	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	li	$16,-1			# 0xffffffffffffffff
	.set	noreorder
	.set	nomacro
	beq	$2,$16,$L256
	move	$4,$21
	.set	macro
	.set	reorder

	lw	$3,24($sp)
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$3,%lo($LC20)
	.set	macro
	.set	reorder

	lw	$3,16($sp)
	#nop
	beq	$3,$0,$L256
	.set	noreorder
	.set	nomacro
	jalr	$22
	move	$4,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$16,$L256
	sw	$2,28($sp)
	.set	macro
	.set	reorder

	lui	$18,%hi(check_esc_end)
	addiu	$18,$18,%lo(check_esc_end)
	lui	$5,%hi($LC27)
$L296:
	move	$4,$21
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$5,%lo($LC27)
	.set	macro
	.set	reorder

	move	$4,$2
	.set	noreorder
	.set	nomacro
	j	$L266
	sw	$2,20($sp)
	.set	macro
	.set	reorder

$L268:
	lw	$16,20($sp)
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$4,$16
	.set	macro
	.set	reorder

	addu	$2,$16,$2
	li	$4,59			# 0x3b
	lui	$5,%hi($LC27)
	sb	$4,0($2)
	addiu	$5,$5,%lo($LC27)
	.set	noreorder
	.set	nomacro
	jalr	$17
	move	$4,$21
	.set	macro
	.set	reorder

	lw	$2,16($sp)
	#nop
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L295
	lui	$5,%hi($LC20)
	.set	macro
	.set	reorder

	lw	$4,20($sp)
$L266:
	.set	noreorder
	.set	nomacro
	jalr	$18
	li	$5,92			# 0x5c
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L268
	lui	$5,%hi($LC20)
	.set	macro
	.set	reorder

$L295:
	addiu	$4,$sp,20
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$5,%lo($LC20)
	.set	macro
	.set	reorder

	move	$16,$2
	lw	$2,20($sp)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L286
	li	$22,32			# 0x20
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L291
	lui	$2,%hi(kfree)
	.set	macro
	.set	reorder

$L270:
	jalr	$20
	addu	$2,$16,$2
	lui	$5,%hi($LC20)
	sb	$22,0($2)
	addiu	$4,$sp,20
	.set	noreorder
	.set	nomacro
	jalr	$17
	addiu	$5,$5,%lo($LC20)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L292
	move	$4,$16
	.set	macro
	.set	reorder

$L286:
	move	$4,$16
$L292:
	.set	noreorder
	.set	nomacro
	jalr	$18
	li	$5,92			# 0x5c
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L270
	move	$4,$16
	.set	macro
	.set	reorder

	move	$5,$16
	move	$6,$0
	.set	noreorder
	.set	nomacro
	j	$L271
	li	$7,92			# 0x5c
	.set	macro
	.set	reorder

$L275:
	.set	noreorder
	.set	nomacro
	bne	$2,$7,$L273
	move	$2,$5
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L289
	move	$4,$6
	.set	macro
	.set	reorder

$L274:
	sb	$3,0($2)
	addiu	$4,$4,1
	addiu	$2,$2,1
$L289:
	lb	$3,1($2)
	#nop
	bne	$3,$0,$L274
	addu	$4,$16,$4
	sb	$0,0($4)
$L273:
	addiu	$6,$6,1
	addiu	$5,$5,1
$L271:
	lb	$2,0($5)
	#nop
	bne	$2,$0,$L275
	lui	$2,%hi(kmalloc_caches)
	addiu	$2,$2,%lo(kmalloc_caches)
	lw	$4,4($2)
	.set	noreorder
	.set	nomacro
	jalr	$fp
	li	$5,208			# 0xd0
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L261
	move	$22,$2
	.set	macro
	.set	reorder

	addiu	$2,$2,8
	lui	$4,%hi(filter_rule_num)
	lw	$3,%lo(filter_rule_num)($4)
	sw	$2,8($22)
	sw	$2,12($22)
	lw	$2,28($sp)
	sw	$22,0($22)
	sw	$22,4($22)
	sw	$0,24($22)
	sw	$3,20($22)
	sw	$2,16($22)
	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$4,$16
	.set	macro
	.set	reorder

	sltu	$2,$2,41
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L277
	addiu	$4,$22,28
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	jalr	$20
	move	$4,$16
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L278
	move	$3,$2
	.set	macro
	.set	reorder

	addiu	$4,$22,28
$L280:
 #APP
 # 55 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
1:	lbu	$1,($16)
	subu	$2,1
	sb	$1,($4)
	beqz	$1,2f
	addiu	$4,1
	bnez	$2,1b
	addiu	$16,1
2:
	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
$L278:
	addu	$3,$22,$3
	sb	$0,28($3)
	lui	$3,%hi(filter_item_regist)
	li	$4,3			# 0x3
	addiu	$2,$3,%lo(filter_item_regist)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$5,$22
	.set	macro
	.set	reorder

	lui	$4,%hi(filter_rule_num)
	lw	$3,%lo(filter_rule_num)($4)
	lw	$2,16($sp)
	addiu	$3,$3,1
	.set	noreorder
	.set	nomacro
	beq	$2,$0,$L261
	sw	$3,%lo(filter_rule_num)($4)
	.set	macro
	.set	reorder

	lb	$2,0($2)
	#nop
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L296
	lui	$5,%hi($LC27)
	.set	macro
	.set	reorder

$L261:
	lui	$2,%hi(kfree)
$L290:
	addiu	$2,$2,%lo(kfree)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$19
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L293
	move	$2,$23
	.set	macro
	.set	reorder

$L256:
	lui	$2,%hi(kfree)
$L291:
	addiu	$2,$2,%lo(kfree)
	.set	noreorder
	.set	nomacro
	jalr	$2
	move	$4,$19
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L255
	li	$23,-14			# 0xfffffffffffffff2
	.set	macro
	.set	reorder

$L281:
	li	$23,-14			# 0xfffffffffffffff2
$L255:
	move	$2,$23
$L293:
	lw	$31,68($sp)
	lw	$fp,64($sp)
	lw	$23,60($sp)
	lw	$22,56($sp)
	lw	$21,52($sp)
	lw	$20,48($sp)
	lw	$19,44($sp)
	lw	$18,40($sp)
	lw	$17,36($sp)
	lw	$16,32($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,72
	.set	macro
	.set	reorder

$L277:
	li	$2,39			# 0x27
	.set	noreorder
	.set	nomacro
	j	$L280
	li	$3,39			# 0x27
	.set	macro
	.set	reorder

	.end	filter_table_single_write
	.size	filter_table_single_write, .-filter_table_single_write
	.align	2
	.globl	scan_table
	.set	nomips16
	.ent	scan_table
	.type	scan_table, @function
scan_table:
	.frame	$sp,56,$31		# vars= 0, regs= 9/0, args= 16, gp= 0
	.mask	0x80ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$23,48($sp)
	sw	$22,44($sp)
	sw	$21,40($sp)
	sw	$20,36($sp)
	sw	$19,32($sp)
	sw	$18,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$22,%hi(url_filter_flag)
	move	$17,$6
	move	$18,$4
	move	$20,$5
	move	$19,$7
	beq	$6,$0,$L315
	sw	$0,%lo(url_filter_flag)($22)

	lw	$2,28($6)
	nop
	beq	$2,$0,$L298
	li	$2,-1			# 0xffffffffffffffff

	lw	$2,24($6)
	nop
	sltu	$2,$2,2
	bne	$2,$0,$L299
	addiu	$21,$6,8

	lw	$16,8($6)
	nop
	bne	$21,$16,$L320
	lui	$23,%hi(scan_table)

	j	$L324
	lui	$2,%hi(url_filter_mode)

$L316:
	move	$16,$2
$L320:
	lw	$2,16($16)
	nop
	andi	$3,$2,0x1
	bne	$3,$0,$L325
	andi	$3,$2,0x200

	lw	$3,20($16)
	nop
	bne	$20,$3,$L301
	andi	$3,$2,0x200

$L325:
	beq	$3,$0,$L302
	nop

	andi	$2,$2,0x2
	lw	$6,0($19)
	beq	$2,$0,$L301
	nop

	beq	$6,$0,$L315
	move	$4,$18

	lw	$5,20($16)
	addiu	$2,$23,%lo(scan_table)
	jalr	$2
	move	$7,$6

	bne	$2,$0,$L298
	li	$2,1			# 0x1

	j	$L301
	nop

$L302:
	andi	$3,$2,0x100
	bne	$3,$0,$L326
	andi	$3,$2,0x2

	lw	$2,28($17)
	move	$4,$18
	jalr	$2
	addiu	$5,$16,28

	beq	$2,$0,$L301
	nop

	lw	$2,16($16)
	nop
	andi	$3,$2,0x2
$L326:
	bne	$3,$0,$L304
	andi	$3,$2,0x1

	beq	$3,$0,$L318
	nop

	andi	$2,$2,0x8
	j	$L298
	sltu	$2,$2,1

$L304:
	lw	$6,0($19)
	nop
	beq	$6,$0,$L315
	move	$4,$18

	lw	$5,20($16)
	addiu	$2,$23,%lo(scan_table)
	jalr	$2
	move	$7,$6

	beq	$2,$0,$L301
	nop

	lw	$2,16($16)
	nop
	andi	$3,$2,0x1
	beq	$3,$0,$L305
	lui	$3,%hi(url_filter_mode)

	lw	$3,%lo(url_filter_mode)($3)
	nop
	beq	$3,$0,$L323
	andi	$2,$2,0x8

	j	$L298
	sltu	$2,$0,$2

$L305:
	lui	$2,%hi(url_filter_mode)
	lw	$2,%lo(url_filter_mode)($2)
$L323:
	j	$L298
	sltu	$2,$2,1

$L301:
	lw	$2,0($16)
	nop
	bne	$21,$2,$L316
	nop

$L308 = .
	bne	$16,$0,$L309
	nop

$L299:
	lui	$2,%hi(url_filter_mode)
$L324:
	lw	$4,%lo(url_filter_mode)($2)
	li	$3,-1			# 0xffffffffffffffff
	li	$2,1			# 0x1
	j	$L298
	movz	$2,$3,$4

$L309:
	lw	$2,%lo(url_filter_flag)($22)
	nop
	bne	$2,$0,$L298
	li	$2,1			# 0x1

	lw	$2,16($16)
	nop
	andi	$3,$2,0x1
	beq	$3,$0,$L319
	andi	$2,$2,0x8

	j	$L298
	sltu	$2,$0,$2

$L315:
	j	$L298
	li	$2,-1			# 0xffffffffffffffff

$L318:
	j	$L298
	li	$2,1			# 0x1

$L319:
	move	$2,$0
$L298:
	lw	$31,52($sp)
	lw	$23,48($sp)
	lw	$22,44($sp)
	lw	$21,40($sp)
	lw	$20,36($sp)
	lw	$19,32($sp)
	lw	$18,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	j	$31
	addiu	$sp,$sp,56

	.set	macro
	.set	reorder
	.end	scan_table
	.size	scan_table, .-scan_table
	.section	.rodata.str1.4
	.align	2
$LC28:
	.ascii	"Unkown Type [Blocked]\012\000"
	.text
	.align	2
	.globl	log_fastFilter
	.set	nomips16
	.ent	log_fastFilter
	.type	log_fastFilter, @function
log_fastFilter:
	.frame	$sp,40,$31		# vars= 8, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-40
	sw	$31,36($sp)
	sw	$17,32($sp)
	sw	$16,28($sp)
	lui	$2,%hi(do_gettimeofday)
	move	$17,$4
	addiu	$2,$2,%lo(do_gettimeofday)
	addiu	$4,$sp,16
	jalr	$2
	move	$16,$5

	lui	$2,%hi(rtl_ip_hdr)
	addiu	$2,$2,%lo(rtl_ip_hdr)
	jalr	$2
	move	$4,$16

	addiu	$17,$17,-1
	lui	$2,%hi(rtl_eth_hdr)
	move	$4,$16
	addiu	$2,$2,%lo(rtl_eth_hdr)
	jalr	$2
	sltu	$17,$17,4

	bne	$17,$0,$L329
	lui	$2,%hi(printk)

	lui	$4,%hi($LC28)
	addiu	$2,$2,%lo(printk)
	jalr	$2
	addiu	$4,$4,%lo($LC28)

$L329:
	lw	$31,36($sp)
	lw	$17,32($sp)
	lw	$16,28($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,40

	.set	macro
	.set	reorder
	.end	log_fastFilter
	.size	log_fastFilter, .-log_fastFilter
	.align	2
	.globl	do_filter
	.set	nomips16
	.ent	do_filter
	.type	do_filter, @function
do_filter:
	.frame	$sp,48,$31		# vars= 0, regs= 7/0, args= 16, gp= 0
	.mask	0x803f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-48
	sw	$31,44($sp)
	sw	$21,40($sp)
	sw	$20,36($sp)
	sw	$19,32($sp)
	sw	$18,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$18,%hi(table_list_head)
	lw	$16,%lo(table_list_head)($18)
	move	$17,$4
	addiu	$18,$18,%lo(table_list_head)
	lui	$19,%hi(scan_table)
	li	$20,-1			# 0xffffffffffffffff
	j	$L331
	li	$21,1			# 0x1

$L334:
	jalr	$2
	nop

	beq	$2,$20,$L335
	nop

	bne	$2,$21,$L333
	lui	$2,%hi(log_enable)

	lw	$2,%lo(log_enable)($2)
	nop
	beq	$2,$0,$L336
	lui	$2,%hi(log_fastFilter)

	lw	$4,16($16)
	addiu	$2,$2,%lo(log_fastFilter)
	jalr	$2
	move	$5,$17

	j	$L332
	li	$2,1			# 0x1

$L333:
	lw	$16,0($16)
	nop
$L331:
	move	$6,$16
	move	$7,$16
	move	$4,$17
	move	$5,$0
	bne	$16,$18,$L334
	addiu	$2,$19,%lo(scan_table)

$L335:
	j	$L332
	move	$2,$0

$L336:
	li	$2,1			# 0x1
$L332:
	lw	$31,44($sp)
	lw	$21,40($sp)
	lw	$20,36($sp)
	lw	$19,32($sp)
	lw	$18,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	j	$31
	addiu	$sp,$sp,48

	.set	macro
	.set	reorder
	.end	do_filter
	.size	do_filter, .-do_filter
	.align	2
	.globl	FilterWeb_v2
	.set	nomips16
	.ent	FilterWeb_v2
	.type	FilterWeb_v2, @function
FilterWeb_v2:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$2,%hi(rtl_ip_hdr)
	addiu	$2,$2,%lo(rtl_ip_hdr)
	jalr	$2
	move	$16,$4

	lui	$2,%hi(need_filter)
	addiu	$2,$2,%lo(need_filter)
	jalr	$2
	move	$4,$16

	beq	$2,$0,$L338
	move	$4,$16

	lw	$31,20($sp)
	lw	$16,16($sp)
	lui	$25,%hi(do_filter)
	addiu	$25,$25,%lo(do_filter)
	jr	$25
	addiu	$sp,$sp,24

$L338:
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	FilterWeb_v2
	.size	FilterWeb_v2, .-FilterWeb_v2
	.section	.rodata.str1.4
	.align	2
$LC29:
	.ascii	"filter_table\000"
	.text
	.align	2
	.globl	filter_table_init
	.set	nomips16
	.ent	filter_table_init
	.type	filter_table_init, @function
filter_table_init:
	.frame	$sp,32,$31		# vars= 0, regs= 1/0, args= 24, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	lui	$2,%hi(filter_table_head_init)
	addiu	$2,$2,%lo(filter_table_head_init)
	jalr	$2
	nop

	lui	$4,%hi($LC29)
	lui	$6,%hi(proc_root)
	lui	$7,%hi(filter_table_proc_fops)
	lui	$2,%hi(proc_create_data)
	addiu	$4,$4,%lo($LC29)
	move	$5,$0
	addiu	$6,$6,%lo(proc_root)
	addiu	$7,$7,%lo(filter_table_proc_fops)
	addiu	$2,$2,%lo(proc_create_data)
	jalr	$2
	sw	$0,16($sp)

	lw	$31,28($sp)
	lui	$3,%hi(res12)
	sw	$2,%lo(res12)($3)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	filter_table_init
	.size	filter_table_init, .-filter_table_init
	.align	2
	.globl	filter_init_fastpath
	.set	nomips16
	.ent	filter_init_fastpath
	.type	filter_init_fastpath, @function
filter_init_fastpath:
	.frame	$sp,24,$31		# vars= 0, regs= 1/0, args= 16, gp= 0
	.mask	0x80000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	li	$3,1			# 0x1
	lui	$2,%hi(filter_rule_num)
	sw	$3,%lo(filter_rule_num)($2)
	lui	$2,%hi(filter_table_init)
	addiu	$2,$2,%lo(filter_table_init)
	jalr	$2
	nop

	lw	$31,20($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	filter_init_fastpath
	.size	filter_init_fastpath, .-filter_init_fastpath
	.align	2
	.globl	filter_exit_fastpath
	.set	nomips16
	.ent	filter_exit_fastpath
	.type	filter_exit_fastpath, @function
filter_exit_fastpath:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$16,%hi(res12)
	lw	$2,%lo(res12)($16)
	nop
	beq	$2,$0,$L342
	lui	$4,%hi($LC29)

	lui	$5,%hi(proc_root)
	lui	$2,%hi(remove_proc_entry)
	addiu	$4,$4,%lo($LC29)
	addiu	$2,$2,%lo(remove_proc_entry)
	jalr	$2
	addiu	$5,$5,%lo(proc_root)

	sw	$0,%lo(res12)($16)
$L342:
	lw	$31,20($sp)
	lw	$16,16($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	filter_exit_fastpath
	.size	filter_exit_fastpath, .-filter_exit_fastpath
	.align	2
	.globl	strtoint
	.set	nomips16
	.ent	strtoint
	.type	strtoint, @function
strtoint:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	j	$L344
	move	$2,$0

$L346:
	beq	$8,$0,$L347
	nop

	addu	$2,$6,$5
	addiu	$4,$4,1
$L344:
	lb	$3,0($4)
	sll	$7,$2,1
	sll	$6,$2,3
	addiu	$5,$3,-48
	sltu	$8,$5,10
	bne	$3,$0,$L346
	addu	$6,$7,$6

$L347:
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	strtoint
	.size	strtoint, .-strtoint
	.align	2
	.globl	strtok
	.set	nomips16
	.ent	strtok
	.type	strtok, @function
strtok:
	.frame	$sp,32,$31		# vars= 0, regs= 4/0, args= 16, gp= 0
	.mask	0x80070000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$18,24($sp)
	sw	$17,20($sp)
	sw	$16,16($sp)
	bne	$4,$0,$L353
	move	$16,$5

	lui	$18,%hi(___strtok)
	lw	$17,%lo(___strtok)($18)
	nop
	bne	$17,$0,$L349
	move	$2,$17

	j	$L354
	nop

$L353:
	move	$17,$4
	lui	$18,%hi(___strtok)
$L349:
	lui	$2,%hi(strspn)
	move	$4,$17
	addiu	$2,$2,%lo(strspn)
	jalr	$2
	move	$5,$16

	addu	$17,$17,$2
	lb	$2,0($17)
	nop
	bne	$2,$0,$L351
	lui	$2,%hi(strpbrk)

	sw	$0,%lo(___strtok)($18)
	j	$L350
	move	$17,$0

$L351:
	move	$4,$17
	addiu	$2,$2,%lo(strpbrk)
	jalr	$2
	move	$5,$16

	beq	$2,$0,$L352
	nop

	lb	$3,0($2)
	nop
	beq	$3,$0,$L352
	nop

	sb	$0,0($2)
	addiu	$2,$2,1
$L352:
	sw	$2,%lo(___strtok)($18)
$L350:
	move	$2,$17
$L354:
	lw	$31,28($sp)
	lw	$18,24($sp)
	lw	$17,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	strtok
	.size	strtok, .-strtok
	.align	2
	.set	nomips16
	.ent	dos_single_write
	.type	dos_single_write, @function
dos_single_write:
	.frame	$sp,136,$31		# vars= 80, regs= 10/0, args= 16, gp= 0
	.mask	0xc0ff0000,-4
	.fmask	0x00000000,0
	addiu	$sp,$sp,-136
	sw	$31,132($sp)
	sw	$fp,128($sp)
	sw	$23,124($sp)
	sw	$22,120($sp)
	sw	$21,116($sp)
	sw	$20,112($sp)
	sw	$19,108($sp)
	sw	$18,104($sp)
	sw	$17,100($sp)
	sw	$16,96($sp)
	sltu	$3,$6,2
	.set	noreorder
	.set	nomacro
	bne	$3,$0,$L377
	move	$23,$6
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	beq	$5,$0,$L377
	addiu	$3,$5,80
	.set	macro
	.set	reorder

	or	$2,$3,$5
	lw	$3,24($28)
	#nop
	and	$2,$2,$3
	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L377
	lui	$2,%hi(dos_flag)
	.set	macro
	.set	reorder

	addiu	$4,$2,%lo(dos_flag)
	li	$6,80			# 0x50
 #APP
 # 3060 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/fastpath-0.1/filter.c" 1
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
	.set	noreorder
	.set	nomacro
	bne	$6,$0,$L377
	addiu	$2,$2,%lo(dos_flag)
	.set	macro
	.set	reorder

	addiu	$3,$sp,16
	li	$4,80			# 0x50
 #APP
 # 55 "/home/extra_home/marklee/rtk_OpenWRT_BB/BB_v1407/0629_co_2.4_pre_release/svn_test/rtk_BarrierBreaker_v14.07.x/build_dir/target-mips-rlx4181-linux/linux-realtek_rtl8196e/linux-3.10.49/arch/rlx/include/asm/string.h" 1
	.set	noreorder
	.set	noat
1:	lbu	$1,($2)
	subu	$4,1
	sb	$1,($3)
	beqz	$1,2f
	addiu	$3,1
	bnez	$4,1b
	addiu	$2,1
2:
	.set	at
	.set	reorder
 # 0 "" 2
 #NO_APP
	lui	$20,%hi(strtok)
	lui	$22,%hi($L372)
	li	$17,1			# 0x1
	addiu	$4,$sp,16
	lui	$19,%hi($LC20)
	addiu	$20,$20,%lo(strtok)
	lui	$21,%hi(simple_strtol)
	addiu	$22,$22,%lo($L372)
	.set	noreorder
	.set	nomacro
	j	$L357
	lui	$fp,%hi(block_time)
	.set	macro
	.set	reorder

$L373:
	move	$4,$16
	move	$5,$0
	addiu	$18,$21,%lo(simple_strtol)
	.set	noreorder
	.set	nomacro
	jalr	$18
	move	$6,$0
	.set	macro
	.set	reorder

	sltu	$3,$17,14
	.set	noreorder
	.set	nomacro
	beq	$3,$0,$L358
	sll	$3,$17,2
	.set	macro
	.set	reorder

	addu	$3,$22,$3
	lw	$3,0($3)
	#nop
	j	$3
	.rdata
	.align	2
	.align	2
$L372:
	.word	$L358
	.word	$L359
	.word	$L360
	.word	$L361
	.word	$L362
	.word	$L363
	.word	$L364
	.word	$L365
	.word	$L366
	.word	$L367
	.word	$L368
	.word	$L369
	.word	$L370
	.word	$L371
	.text
$L359:
	lui	$3,%hi(op_mode)
	.set	noreorder
	.set	nomacro
	j	$L358
	sb	$2,%lo(op_mode)($3)
	.set	macro
	.set	reorder

$L360:
	move	$4,$16
	move	$5,$0
	.set	noreorder
	.set	nomacro
	jalr	$18
	li	$6,16			# 0x10
	.set	macro
	.set	reorder

	lui	$3,%hi(lan_addr)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(lan_addr)($3)
	.set	macro
	.set	reorder

$L361:
	move	$4,$16
	move	$5,$0
	.set	noreorder
	.set	nomacro
	jalr	$18
	li	$6,16			# 0x10
	.set	macro
	.set	reorder

	lui	$3,%hi(lan_mask)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(lan_mask)($3)
	.set	macro
	.set	reorder

$L362:
	lui	$3,%hi(item)
	sw	$2,%lo(item)($3)
	lui	$2,%hi(item_backup)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$0,%lo(item_backup)($2)
	.set	macro
	.set	reorder

$L363:
	lui	$3,%hi(whole_syn_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(whole_syn_threshold)($3)
	.set	macro
	.set	reorder

$L364:
	lui	$3,%hi(whole_fin_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(whole_fin_threshold)($3)
	.set	macro
	.set	reorder

$L365:
	lui	$3,%hi(whole_udp_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(whole_udp_threshold)($3)
	.set	macro
	.set	reorder

$L366:
	lui	$3,%hi(whole_icmp_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(whole_icmp_threshold)($3)
	.set	macro
	.set	reorder

$L367:
	lui	$3,%hi(per_syn_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(per_syn_threshold)($3)
	.set	macro
	.set	reorder

$L368:
	lui	$3,%hi(per_fin_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(per_fin_threshold)($3)
	.set	macro
	.set	reorder

$L369:
	lui	$3,%hi(per_udp_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(per_udp_threshold)($3)
	.set	macro
	.set	reorder

$L370:
	lui	$3,%hi(per_icmp_threshold)
	.set	noreorder
	.set	nomacro
	j	$L358
	sw	$2,%lo(per_icmp_threshold)($3)
	.set	macro
	.set	reorder

$L371:
	sw	$2,%lo(block_time)($fp)
$L358:
	addiu	$17,$17,1
	andi	$17,$17,0x00ff
	move	$4,$0
$L357:
	.set	noreorder
	.set	nomacro
	jalr	$20
	addiu	$5,$19,%lo($LC20)
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	bne	$2,$0,$L373
	move	$16,$2
	.set	macro
	.set	reorder

	.set	noreorder
	.set	nomacro
	j	$L356
	move	$2,$23
	.set	macro
	.set	reorder

$L377:
	li	$2,-14			# 0xfffffffffffffff2
$L356:
	lw	$31,132($sp)
	lw	$fp,128($sp)
	lw	$23,124($sp)
	lw	$22,120($sp)
	lw	$21,116($sp)
	lw	$20,112($sp)
	lw	$19,108($sp)
	lw	$18,104($sp)
	lw	$17,100($sp)
	lw	$16,96($sp)
	.set	noreorder
	.set	nomacro
	j	$31
	addiu	$sp,$sp,136
	.set	macro
	.set	reorder

	.end	dos_single_write
	.size	dos_single_write, .-dos_single_write
	.align	2
	.globl	filter_addconnect
	.set	nomips16
	.ent	filter_addconnect
	.type	filter_addconnect, @function
filter_addconnect:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	andi	$3,$4,0xff
	lui	$2,%hi(ConnectedIp)
	sll	$3,$3,2
	addiu	$2,$2,%lo(ConnectedIp)
	addu	$2,$3,$2
	j	$31
	sw	$4,0($2)

	.set	macro
	.set	reorder
	.end	filter_addconnect
	.size	filter_addconnect, .-filter_addconnect
	.align	2
	.globl	filter_delconnect
	.set	nomips16
	.ent	filter_delconnect
	.type	filter_delconnect, @function
filter_delconnect:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	andi	$4,$4,0x00ff
	lui	$2,%hi(ConnectedIp)
	sll	$4,$4,2
	addiu	$2,$2,%lo(ConnectedIp)
	addu	$4,$4,$2
	j	$31
	sw	$0,0($4)

	.set	macro
	.set	reorder
	.end	filter_delconnect
	.size	filter_delconnect, .-filter_delconnect
	.align	2
	.globl	filter_checkConnect
	.set	nomips16
	.ent	filter_checkConnect
	.type	filter_checkConnect, @function
filter_checkConnect:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	andi	$3,$4,0xff
	lui	$2,%hi(ConnectedIp)
	sll	$3,$3,2
	addiu	$2,$2,%lo(ConnectedIp)
	addu	$2,$3,$2
	lw	$2,0($2)
	nop
	beq	$2,$0,$L382
	nop

	xor	$2,$4,$2
	j	$31
	sltu	$2,$0,$2

$L382:
	j	$31
	li	$2,1			# 0x1

	.set	macro
	.set	reorder
	.end	filter_checkConnect
	.size	filter_checkConnect, .-filter_checkConnect
	.align	2
	.globl	unregister_customRspStr
	.set	nomips16
	.ent	unregister_customRspStr
	.type	unregister_customRspStr, @function
unregister_customRspStr:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$16,%hi(block_message)
	lw	$4,%lo(block_message)($16)
	nop
	beq	$4,$0,$L383
	lui	$2,%hi(kfree)

	addiu	$2,$2,%lo(kfree)
	jalr	$2
	nop

	sw	$0,%lo(block_message)($16)
$L383:
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	unregister_customRspStr
	.size	unregister_customRspStr, .-unregister_customRspStr
	.align	2
	.globl	register_customRspStr
	.set	nomips16
	.ent	register_customRspStr
	.type	register_customRspStr, @function
register_customRspStr:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$2,%hi(unregister_customRspStr)
	addiu	$2,$2,%lo(unregister_customRspStr)
	jalr	$2
	move	$16,$4

	beq	$16,$0,$L386
	lui	$2,%hi(strlen)

	addiu	$2,$2,%lo(strlen)
	jalr	$2
	move	$4,$16

	addiu	$4,$2,1
	lui	$2,%hi(__kmalloc)
	addiu	$2,$2,%lo(__kmalloc)
	jalr	$2
	li	$5,208			# 0xd0

	lui	$3,%hi(block_message)
	beq	$2,$0,$L385
	sw	$2,%lo(block_message)($3)

	lui	$5,%hi($LC15)
	move	$4,$2
	addiu	$5,$5,%lo($LC15)
	j	$L388
	move	$6,$16

$L386:
	lui	$16,%hi($LC2)
	addiu	$2,$2,%lo(strlen)
	jalr	$2
	addiu	$4,$16,%lo($LC2)

	move	$4,$2
	lui	$2,%hi(__kmalloc)
	addiu	$2,$2,%lo(__kmalloc)
	jalr	$2
	li	$5,208			# 0xd0

	lui	$3,%hi(block_message)
	beq	$2,$0,$L385
	sw	$2,%lo(block_message)($3)

	lui	$5,%hi($LC15)
	move	$4,$2
	addiu	$5,$5,%lo($LC15)
	addiu	$6,$16,%lo($LC2)
$L388:
	lw	$31,20($sp)
	lw	$16,16($sp)
	lui	$25,%hi(sprintf)
	addiu	$25,$25,%lo(sprintf)
	jr	$25
	addiu	$sp,$sp,24

$L385:
	lw	$31,20($sp)
	lw	$16,16($sp)
	j	$31
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	register_customRspStr
	.size	register_customRspStr, .-register_customRspStr
	.align	2
	.globl	register_customRspHook
	.set	nomips16
	.ent	register_customRspHook
	.type	register_customRspHook, @function
register_customRspHook:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	beq	$4,$0,$L390
	lui	$2,%hi(fast_path_cusRsp401_func)

	j	$L391
	sw	$4,%lo(fast_path_cusRsp401_func)($2)

$L390:
	lui	$3,%hi(GenerateHTTP401)
	addiu	$3,$3,%lo(GenerateHTTP401)
	sw	$3,%lo(fast_path_cusRsp401_func)($2)
$L391:
	beq	$5,$0,$L392
	lui	$2,%hi(fast_path_cusRspTCPFinAck_func)

	j	$L393
	sw	$5,%lo(fast_path_cusRspTCPFinAck_func)($2)

$L392:
	lui	$3,%hi(GenerateTCPFINACK)
	addiu	$3,$3,%lo(GenerateTCPFINACK)
	sw	$3,%lo(fast_path_cusRspTCPFinAck_func)($2)
$L393:
	beq	$6,$0,$L394
	lui	$2,%hi(fast_path_cusRspTCPEndAck_func)

	j	$31
	sw	$6,%lo(fast_path_cusRspTCPEndAck_func)($2)

$L394:
	lui	$3,%hi(GenerateTCPENDACK)
	addiu	$3,$3,%lo(GenerateTCPENDACK)
	j	$31
	sw	$3,%lo(fast_path_cusRspTCPEndAck_func)($2)

	.set	macro
	.set	reorder
	.end	register_customRspHook
	.size	register_customRspHook, .-register_customRspHook
	.align	2
	.globl	unregister_customRspHook
	.set	nomips16
	.ent	unregister_customRspHook
	.type	unregister_customRspHook, @function
unregister_customRspHook:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	lui	$2,%hi(fast_path_cusRsp401_func)
	sw	$0,%lo(fast_path_cusRsp401_func)($2)
	lui	$2,%hi(fast_path_cusRspTCPFinAck_func)
	sw	$0,%lo(fast_path_cusRspTCPFinAck_func)($2)
	lui	$2,%hi(fast_path_cusRspTCPEndAck_func)
	j	$31
	sw	$0,%lo(fast_path_cusRspTCPEndAck_func)($2)

	.set	macro
	.set	reorder
	.end	unregister_customRspHook
	.size	unregister_customRspHook, .-unregister_customRspHook
	.align	2
	.globl	filter_enter
	.set	nomips16
	.ent	filter_enter
	.type	filter_enter, @function
filter_enter:
	.frame	$sp,56,$31		# vars= 0, regs= 9/0, args= 16, gp= 0
	.mask	0x80ff0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$23,48($sp)
	sw	$22,44($sp)
	sw	$21,40($sp)
	sw	$20,36($sp)
	sw	$19,32($sp)
	sw	$18,28($sp)
	sw	$17,24($sp)
	sw	$16,20($sp)
	lui	$17,%hi(item)
	lw	$2,%lo(item)($17)
	nop
	bne	$2,$0,$L398
	move	$16,$4

	lui	$2,%hi(table_list_head+24)
	lw	$2,%lo(table_list_head+24)($2)
	nop
	sltu	$2,$2,2
	beq	$2,$0,$L398
	lui	$3,%hi(none_dos_drop_pkt_cnt)

	lw	$4,%lo(none_dos_drop_pkt_cnt)($3)
	li	$2,1			# 0x1
	addiu	$4,$4,1
	j	$L399
	sw	$4,%lo(none_dos_drop_pkt_cnt)($3)

$L398:
	lui	$2,%hi(rtl_get_skb_type)
	addiu	$2,$2,%lo(rtl_get_skb_type)
	jalr	$2
	move	$4,$16

	bne	$2,$0,$L399
	li	$2,4			# 0x4

	lui	$2,%hi(rtl_get_skb_protocol)
	addiu	$2,$2,%lo(rtl_get_skb_protocol)
	jalr	$2
	move	$4,$16

	li	$3,2048			# 0x800
	bne	$2,$3,$L399
	li	$2,4			# 0x4

	lui	$2,%hi(table_list_head+24)
	lw	$2,%lo(table_list_head+24)($2)
	nop
	sltu	$2,$2,2
	bne	$2,$0,$L400
	lui	$2,%hi(FilterWeb_v2)

	addiu	$2,$2,%lo(FilterWeb_v2)
	jalr	$2
	move	$4,$16

	beq	$2,$0,$L401
	lui	$2,%hi(fast_path_cusRsp401_func)

	lw	$2,%lo(fast_path_cusRsp401_func)($2)
	nop
	bne	$2,$0,$L514
	nop

	j	$L399
	move	$2,$0

$L401:
	lw	$2,%lo(fast_path_cusRsp401_func)($2)
	nop
	beq	$2,$0,$L400
	lui	$3,%hi(url_cache)

	addiu	$3,$3,%lo(url_cache)
	lbu	$4,15($3)
	li	$2,1			# 0x1
	bne	$4,$2,$L402
	nop

	lui	$2,%hi(fast_path_cusRspTCPFinAck_func)
	lw	$2,%lo(fast_path_cusRspTCPFinAck_func)($2)
	nop
	bne	$2,$0,$L514
	nop

	j	$L399
	move	$2,$0

$L402:
	lbu	$3,16($3)
	nop
	bne	$3,$2,$L400
	lui	$2,%hi(fast_path_cusRspTCPEndAck_func)

	lw	$2,%lo(fast_path_cusRspTCPEndAck_func)($2)
	nop
	beq	$2,$0,$L503
	nop

$L514:
	jalr	$2
	move	$4,$16

	j	$L399
	move	$2,$0

$L400:
	lw	$2,%lo(item)($17)
	nop
	andi	$2,$2,0x1
	bne	$2,$0,$L508
	lui	$20,%hi(rtl_ip_hdr)

	j	$L403
	addiu	$20,$20,%lo(rtl_ip_hdr)

$L508:
	addiu	$20,$20,%lo(rtl_ip_hdr)
	jalr	$20
	move	$4,$16

	lui	$19,%hi(rtl_get_dev_by_name)
	lui	$4,%hi($LC16)
	addiu	$19,$19,%lo(rtl_get_dev_by_name)
	addiu	$4,$4,%lo($LC16)
	lbu	$23,0($2)
	move	$18,$2
	jalr	$19
	lui	$22,%hi(wan_ppp_dev)

	lui	$4,%hi($LC17)
	addiu	$4,$4,%lo($LC17)
	jalr	$19
	sw	$2,%lo(wan_ppp_dev)($22)

	lui	$21,%hi(wan_dev)
	lui	$19,%hi(rtl_get_skb_dev)
	move	$4,$16
	addiu	$19,$19,%lo(rtl_get_skb_dev)
	sw	$2,%lo(wan_dev)($21)
	jalr	$19
	andi	$23,$23,0xf

	beq	$2,$0,$L403
	nop

	jalr	$19
	move	$4,$16

	lw	$3,%lo(wan_dev)($21)
	nop
	beq	$3,$2,$L405
	nop

	jalr	$19
	move	$4,$16

	lw	$3,%lo(wan_ppp_dev)($22)
	nop
	bne	$3,$2,$L403
	nop

$L405:
	lw	$21,%lo(item)($17)
	sll	$22,$23,2
	andi	$2,$21,0x3fe
	beq	$2,$0,$L456
	addu	$22,$18,$22

	lui	$2,%hi(dos_pkt_locate)
	addiu	$2,$2,%lo(dos_pkt_locate)
	jalr	$2
	move	$4,$18

	beq	$2,$0,$L406
	move	$19,$0

	andi	$2,$21,0x22
	beq	$2,$0,$L517
	andi	$2,$21,0x44

	lbu	$3,9($18)
	lui	$2,%hi(cur_p_pkt)
	lw	$5,%lo(cur_p_pkt)($2)
	li	$2,6			# 0x6
	bne	$3,$2,$L517
	andi	$2,$21,0x44

	lbu	$3,13($22)
	li	$2,2			# 0x2
	andi	$3,$3,0x3f
	bne	$3,$2,$L517
	andi	$2,$21,0x44

	lui	$2,%hi(block)
	lw	$4,%lo(block)($2)
	li	$3,1			# 0x1
	bne	$4,$3,$L408
	lui	$3,%hi(attack_saddr+4)

	lw	$4,%lo(attack_saddr+4)($3)
	lw	$3,12($18)
	nop
	beq	$4,$3,$L460
	nop

$L408:
	lw	$4,4($5)
	lui	$3,%hi(per_syn_threshold)
	lw	$3,%lo(per_syn_threshold)($3)
	addiu	$4,$4,1
	sw	$4,4($5)
	slt	$4,$3,$4
	beq	$4,$0,$L463
	andi	$4,$21,0x20

	beq	$4,$0,$L407
	move	$19,$0

	blez	$3,$L407
	lui	$3,%hi(LogFlag)

	lw	$7,12($18)
	lw	$4,%lo(LogFlag)($3)
	lw	$6,16($18)
	lui	$5,%hi(attack_saddr+4)
	sw	$7,%lo(attack_saddr+4)($5)
	lui	$5,%hi(attack_daddr+4)
	ori	$4,$4,0x20
	sw	$6,%lo(attack_daddr+4)($5)
	li	$5,1			# 0x1
	sw	$5,%lo(block)($2)
	j	$L407
	sw	$4,%lo(LogFlag)($3)

$L460:
	j	$L407
	li	$19,-1			# 0xffffffffffffffff

$L463:
	move	$19,$0
$L407:
	andi	$2,$21,0x44
$L517:
	beq	$2,$0,$L409
	lui	$2,%hi(cur_p_pkt)

	lbu	$3,9($18)
	lw	$5,%lo(cur_p_pkt)($2)
	li	$2,6			# 0x6
	bne	$3,$2,$L410
	move	$2,$0

	lbu	$3,13($22)
	li	$2,1			# 0x1
	andi	$3,$3,0x3f
	bne	$3,$2,$L410
	move	$2,$0

	lui	$2,%hi(block)
	lw	$4,%lo(block)($2)
	nop
	bne	$4,$3,$L411
	lui	$3,%hi(attack_saddr+8)

	lw	$4,%lo(attack_saddr+8)($3)
	lw	$3,12($18)
	nop
	beq	$4,$3,$L466
	nop

$L411:
	lw	$4,8($5)
	lui	$3,%hi(per_fin_threshold)
	lw	$3,%lo(per_fin_threshold)($3)
	addiu	$4,$4,1
	sw	$4,8($5)
	slt	$4,$3,$4
	beq	$4,$0,$L469
	andi	$21,$21,0x40

	beq	$21,$0,$L469
	nop

	blez	$3,$L469
	lui	$3,%hi(LogFlag)

	lw	$7,12($18)
	lw	$4,%lo(LogFlag)($3)
	lw	$6,16($18)
	lui	$5,%hi(attack_saddr+8)
	sw	$7,%lo(attack_saddr+8)($5)
	lui	$5,%hi(attack_daddr+8)
	ori	$4,$4,0x40
	sw	$6,%lo(attack_daddr+8)($5)
	li	$5,1			# 0x1
	sw	$5,%lo(block)($2)
	sw	$4,%lo(LogFlag)($3)
	j	$L410
	move	$2,$0

$L466:
	j	$L410
	li	$2,-1			# 0xffffffffffffffff

$L469:
	move	$2,$0
$L410:
	or	$19,$19,$2
$L409:
	lw	$4,%lo(item)($17)
	nop
	andi	$2,$4,0x88
	beq	$2,$0,$L518
	andi	$2,$4,0x110

	lbu	$3,9($18)
	lui	$2,%hi(cur_p_pkt)
	lw	$6,%lo(cur_p_pkt)($2)
	li	$2,17			# 0x11
	bne	$3,$2,$L413
	move	$2,$0

	lui	$2,%hi(block)
	lw	$5,%lo(block)($2)
	li	$3,1			# 0x1
	bne	$5,$3,$L414
	lui	$3,%hi(attack_saddr+12)

	lw	$5,%lo(attack_saddr+12)($3)
	lw	$3,12($18)
	nop
	beq	$5,$3,$L471
	nop

$L414:
	lw	$5,12($6)
	lui	$3,%hi(per_udp_threshold)
	lw	$3,%lo(per_udp_threshold)($3)
	addiu	$5,$5,1
	sw	$5,12($6)
	slt	$5,$3,$5
	beq	$5,$0,$L474
	andi	$4,$4,0x80

	beq	$4,$0,$L474
	nop

	blez	$3,$L474
	lui	$3,%hi(LogFlag)

	lw	$7,12($18)
	lw	$4,%lo(LogFlag)($3)
	lw	$6,16($18)
	lui	$5,%hi(attack_saddr+12)
	sw	$7,%lo(attack_saddr+12)($5)
	lui	$5,%hi(attack_daddr+12)
	ori	$4,$4,0x80
	sw	$6,%lo(attack_daddr+12)($5)
	li	$5,1			# 0x1
	sw	$5,%lo(block)($2)
	sw	$4,%lo(LogFlag)($3)
	j	$L413
	move	$2,$0

$L471:
	j	$L413
	li	$2,-1			# 0xffffffffffffffff

$L474:
	move	$2,$0
$L413:
	or	$19,$19,$2
	lw	$4,%lo(item)($17)
	nop
	andi	$2,$4,0x110
$L518:
	beq	$2,$0,$L415
	lui	$2,%hi(cur_p_pkt)

	lbu	$3,9($18)
	lw	$6,%lo(cur_p_pkt)($2)
	li	$2,1			# 0x1
	bne	$3,$2,$L416
	move	$2,$0

	lui	$2,%hi(block)
	lw	$5,%lo(block)($2)
	nop
	bne	$5,$3,$L417
	lui	$3,%hi(attack_saddr+16)

	lw	$5,%lo(attack_saddr+16)($3)
	lw	$3,12($18)
	nop
	beq	$5,$3,$L476
	nop

$L417:
	lw	$5,16($6)
	lui	$3,%hi(per_icmp_threshold)
	lw	$3,%lo(per_icmp_threshold)($3)
	addiu	$5,$5,1
	sw	$5,16($6)
	slt	$5,$3,$5
	beq	$5,$0,$L479
	andi	$4,$4,0x100

	beq	$4,$0,$L479
	nop

	blez	$3,$L479
	lui	$3,%hi(LogFlag)

	lw	$7,12($18)
	lw	$4,%lo(LogFlag)($3)
	lw	$6,16($18)
	lui	$5,%hi(attack_saddr+16)
	sw	$7,%lo(attack_saddr+16)($5)
	lui	$5,%hi(attack_daddr+16)
	ori	$4,$4,0x100
	sw	$6,%lo(attack_daddr+16)($5)
	li	$5,1			# 0x1
	sw	$5,%lo(block)($2)
	sw	$4,%lo(LogFlag)($3)
	j	$L416
	move	$2,$0

$L476:
	j	$L416
	li	$2,-1			# 0xffffffffffffffff

$L479:
	move	$2,$0
$L416:
	or	$19,$19,$2
$L415:
	lw	$2,%lo(item)($17)
	nop
	andi	$2,$2,0x200
	beq	$2,$0,$L418
	lui	$2,%hi(cur_p_pkt)

	lbu	$4,9($18)
	lw	$3,%lo(cur_p_pkt)($2)
	li	$2,6			# 0x6
	bne	$4,$2,$L511
	nop

	lhu	$2,32($3)
	nop
	beq	$2,$0,$L420
	li	$5,17			# 0x11

	lhu	$5,2($22)
	nop
	bne	$5,$2,$L510
	nop

$L511:
	lw	$2,20($3)
	j	$L515
	li	$5,17			# 0x11

$L510:
	lw	$2,20($3)
	nop
	addiu	$2,$2,1
	sw	$2,20($3)
	lbu	$4,9($18)
	j	$L515
	li	$5,17			# 0x11

$L420:
	lhu	$4,2($22)
	lw	$2,20($3)
	sh	$4,32($3)
	lbu	$4,9($18)
	nop
$L515:
	bne	$4,$5,$L422
	nop

	lhu	$4,32($3)
	nop
	beq	$4,$0,$L423
	nop

	lhu	$5,2($22)
	nop
	beq	$5,$4,$L422
	nop

	addiu	$2,$2,1
	j	$L422
	sw	$2,20($3)

$L423:
	lhu	$4,2($22)
	nop
	sh	$4,32($3)
$L422:
	lw	$3,%lo(item)($17)
	li	$4,8388608			# 0x800000
	and	$3,$4,$3
	beq	$3,$0,$L425
	nop

	slt	$2,$2,11
	bne	$2,$0,$L418
	lui	$2,%hi(LogFlag)

	j	$L516
	nop

$L425:
	slt	$2,$2,201
	bne	$2,$0,$L418
	lui	$2,%hi(LogFlag)

$L516:
	lw	$5,%lo(LogFlag)($2)
	lw	$4,12($18)
	lw	$3,16($18)
	ori	$5,$5,0x200
	sw	$5,%lo(LogFlag)($2)
	lui	$2,%hi(attack_saddr+20)
	sw	$4,%lo(attack_saddr+20)($2)
	lui	$2,%hi(attack_daddr+20)
	sw	$3,%lo(attack_daddr+20)($2)
$L418:
	lw	$21,%lo(item)($17)
	li	$2,4194304			# 0x400000
	and	$2,$21,$2
	j	$L406
	movz	$19,$0,$2

$L456:
	move	$19,$0
$L406:
	andi	$2,$21,0x8000
	beq	$2,$0,$L519
	li	$2,65536			# 0x10000

	lbu	$3,9($18)
	li	$2,6			# 0x6
	bne	$3,$2,$L427
	move	$2,$0

	lbu	$3,13($22)
	lui	$2,%hi(_tcpDosScanBitmap)
	addiu	$2,$2,%lo(_tcpDosScanBitmap)
	andi	$3,$3,0x3f
	addu	$2,$3,$2
	lb	$2,0($2)
	nop
	beq	$2,$0,$L482
	lui	$2,%hi(LogFlag)

	lw	$5,%lo(LogFlag)($2)
	lw	$4,12($18)
	lw	$3,16($18)
	ori	$5,$5,0x8000
	sw	$5,%lo(LogFlag)($2)
	lui	$2,%hi(attack_saddr+44)
	sw	$4,%lo(attack_saddr+44)($2)
	lui	$2,%hi(attack_daddr+44)
	sw	$3,%lo(attack_daddr+44)($2)
	j	$L427
	li	$2,-1			# 0xffffffffffffffff

$L482:
	move	$2,$0
$L427:
	or	$19,$19,$2
	li	$2,65536			# 0x10000
$L519:
	and	$3,$21,$2
	beq	$3,$0,$L428
	li	$3,6			# 0x6

	lbu	$4,9($18)
	nop
	bne	$4,$3,$L485
	li	$3,2			# 0x2

	lbu	$4,13($22)
	nop
	andi	$4,$4,0x3f
	bne	$4,$3,$L485
	nop

	lbu	$4,0($18)
	lw	$3,12($22)
	lhu	$5,2($18)
	andi	$4,$4,0xf
	sll	$4,$4,2
	srl	$3,$3,28
	subu	$4,$5,$4
	sll	$3,$3,2
	bne	$4,$3,$L520
	lui	$3,%hi(LogFlag)

	lhu	$3,6($18)
	nop
	andi	$3,$3,0x2000
	beq	$3,$0,$L485
	lui	$3,%hi(LogFlag)

$L520:
	lw	$6,%lo(LogFlag)($3)
	lw	$5,12($18)
	lw	$4,16($18)
	or	$2,$6,$2
	sw	$2,%lo(LogFlag)($3)
	lui	$2,%hi(attack_saddr+48)
	sw	$5,%lo(attack_saddr+48)($2)
	lui	$2,%hi(attack_daddr+48)
	sw	$4,%lo(attack_daddr+48)($2)
	j	$L429
	li	$2,-1			# 0xffffffffffffffff

$L485:
	move	$2,$0
$L429:
	or	$19,$19,$2
$L428:
	andi	$2,$21,0x800
	beq	$2,$0,$L521
	li	$2,262144			# 0x40000

	lw	$2,12($18)
	lw	$3,16($18)
	nop
	bne	$2,$3,$L486
	lui	$3,%hi(LogFlag)

	lw	$4,%lo(LogFlag)($3)
	nop
	ori	$4,$4,0x800
	sw	$4,%lo(LogFlag)($3)
	lui	$3,%hi(attack_saddr+28)
	sw	$2,%lo(attack_saddr+28)($3)
	lui	$3,%hi(attack_daddr+28)
	sw	$2,%lo(attack_daddr+28)($3)
	j	$L432
	li	$2,-1			# 0xffffffffffffffff

$L486:
	move	$2,$0
$L432:
	or	$19,$19,$2
	li	$2,262144			# 0x40000
$L521:
	and	$2,$21,$2
	beq	$2,$0,$L522
	li	$2,131072			# 0x20000

	lbu	$3,9($18)
	li	$2,17			# 0x11
	bne	$3,$2,$L434
	move	$2,$0

	lhu	$2,2($22)
	li	$5,7			# 0x7
	beq	$2,$5,$L435
	nop

	beq	$2,$3,$L435
	li	$4,19			# 0x13

	beq	$2,$4,$L523
	lui	$2,%hi(LogFlag)

	lhu	$2,0($22)
	nop
	beq	$2,$5,$L435
	nop

	beq	$2,$3,$L435
	nop

	bne	$2,$4,$L488
	nop

$L435:
	lui	$2,%hi(LogFlag)
$L523:
	lw	$6,%lo(LogFlag)($2)
	lw	$4,12($18)
	li	$5,262144			# 0x40000
	lw	$3,16($18)
	or	$5,$6,$5
	sw	$5,%lo(LogFlag)($2)
	lui	$2,%hi(attack_saddr+56)
	sw	$4,%lo(attack_saddr+56)($2)
	lui	$2,%hi(attack_daddr+56)
	sw	$3,%lo(attack_daddr+56)($2)
	j	$L434
	li	$2,-1			# 0xffffffffffffffff

$L488:
	move	$2,$0
$L434:
	or	$19,$19,$2
	li	$2,131072			# 0x20000
$L522:
	and	$3,$21,$2
	beq	$3,$0,$L436
	li	$3,17			# 0x11

	lbu	$4,9($18)
	nop
	bne	$4,$3,$L491
	nop

	lhu	$3,6($18)
	nop
	andi	$3,$3,0x3fff
	bne	$3,$0,$L491
	nop

	lbu	$3,0($18)
	lhu	$5,2($18)
	lhu	$4,4($22)
	andi	$3,$3,0xf
	sll	$3,$3,2
	subu	$3,$5,$3
	slt	$3,$4,$3
	beq	$3,$0,$L491
	lui	$3,%hi(LogFlag)

	lw	$6,%lo(LogFlag)($3)
	lw	$5,12($18)
	lw	$4,16($18)
	or	$2,$6,$2
	sw	$2,%lo(LogFlag)($3)
	lui	$2,%hi(attack_saddr+52)
	sw	$5,%lo(attack_saddr+52)($2)
	lui	$2,%hi(attack_daddr+52)
	sw	$4,%lo(attack_daddr+52)($2)
	j	$L437
	li	$2,-1			# 0xffffffffffffffff

$L491:
	move	$2,$0
$L437:
	or	$19,$19,$2
$L436:
	andi	$2,$21,0x4000
	beq	$2,$0,$L524
	andi	$2,$21,0x400

	lhu	$2,6($18)
	nop
	andi	$3,$2,0x2000
	bne	$3,$0,$L494
	andi	$2,$2,0x1fff

	beq	$2,$0,$L494
	sll	$2,$2,3

	lbu	$3,0($18)
	lhu	$4,2($18)
	andi	$3,$3,0xf
	addu	$2,$2,$4
	sll	$3,$3,2
	subu	$3,$2,$3
	li	$2,65536			# 0x10000
	sltu	$2,$3,$2
	bne	$2,$0,$L494
	lui	$2,%hi(LogFlag)

	lw	$5,%lo(LogFlag)($2)
	lw	$4,12($18)
	lw	$3,16($18)
	ori	$5,$5,0x4000
	sw	$5,%lo(LogFlag)($2)
	lui	$2,%hi(attack_saddr+40)
	sw	$4,%lo(attack_saddr+40)($2)
	lui	$2,%hi(attack_daddr+40)
	sw	$3,%lo(attack_daddr+40)($2)
	j	$L439
	li	$2,-1			# 0xffffffffffffffff

$L494:
	move	$2,$0
$L439:
	or	$19,$19,$2
	andi	$2,$21,0x400
$L524:
	beq	$2,$0,$L440
	li	$3,1			# 0x1

	lbu	$2,0($18)
	lbu	$4,9($18)
	nop
	bne	$4,$3,$L497
	andi	$2,$2,0xf

	sll	$2,$2,2
	addu	$2,$18,$2
	lbu	$3,0($2)
	li	$2,8			# 0x8
	bne	$3,$2,$L441
	move	$2,$0

	lui	$3,%hi(lan_addr)
	lw	$2,12($18)
	lw	$3,%lo(lan_addr)($3)
	lui	$4,%hi(lan_mask)
	lw	$4,%lo(lan_mask)($4)
	xor	$3,$2,$3
	and	$3,$3,$4
	bne	$3,$0,$L497
	lui	$3,%hi(LogFlag)

	lw	$5,%lo(LogFlag)($3)
	lw	$4,16($18)
	ori	$5,$5,0x400
	sw	$5,%lo(LogFlag)($3)
	lui	$3,%hi(attack_saddr+24)
	sw	$2,%lo(attack_saddr+24)($3)
	lui	$2,%hi(attack_daddr+24)
	sw	$4,%lo(attack_daddr+24)($2)
	j	$L441
	li	$2,-1			# 0xffffffffffffffff

$L497:
	move	$2,$0
$L441:
	or	$19,$19,$2
$L440:
	andi	$2,$21,0x1000
	beq	$2,$0,$L442
	lui	$3,%hi(lan_addr)

	lw	$2,12($18)
	lw	$3,%lo(lan_addr)($3)
	lui	$4,%hi(lan_mask)
	lw	$4,%lo(lan_mask)($4)
	xor	$3,$2,$3
	and	$3,$3,$4
	bne	$3,$0,$L499
	li	$3,1			# 0x1

	lbu	$4,9($18)
	nop
	beq	$4,$3,$L499
	lui	$3,%hi(LogFlag)

	lw	$5,%lo(LogFlag)($3)
	lw	$4,16($18)
	ori	$5,$5,0x1000
	sw	$5,%lo(LogFlag)($3)
	lui	$3,%hi(attack_saddr+32)
	sw	$2,%lo(attack_saddr+32)($3)
	lui	$2,%hi(attack_daddr+32)
	sw	$4,%lo(attack_daddr+32)($2)
	j	$L443
	li	$2,-1			# 0xffffffffffffffff

$L499:
	move	$2,$0
$L443:
	or	$19,$19,$2
$L442:
	andi	$21,$21,0x2000
	beq	$21,$0,$L444
	lui	$2,%hi(dos_pkt_locate)

	addiu	$2,$2,%lo(dos_pkt_locate)
	jalr	$2
	move	$4,$18

	beq	$2,$0,$L502
	lui	$2,%hi(cur_p_pkt)

	lw	$3,%lo(cur_p_pkt)($2)
	lhu	$5,4($18)
	lhu	$2,28($3)
	nop
	beq	$5,$2,$L446
	nop

	bne	$2,$0,$L445
	move	$2,$0

$L446:
	lhu	$2,6($18)
	nop
	andi	$4,$2,0x3fff
	beq	$4,$0,$L502
	sll	$6,$2,3

	lhu	$4,30($3)
	andi	$6,$6,0xffff
	slt	$6,$6,$4
	bne	$6,$0,$L447
	nop

	andi	$2,$2,0x2000
	bne	$2,$0,$L448
	nop

	sh	$0,28($3)
	j	$L445
	sh	$0,30($3)

$L448:
	sh	$5,28($3)
	lbu	$5,0($18)
	lhu	$6,2($18)
	move	$2,$0
	andi	$5,$5,0xf
	addu	$4,$4,$6
	sll	$5,$5,2
	subu	$4,$4,$5
	j	$L445
	sh	$4,30($3)

$L447:
	lui	$2,%hi(LogFlag)
	lw	$5,%lo(LogFlag)($2)
	lw	$4,12($18)
	lw	$3,16($18)
	ori	$5,$5,0x2000
	sw	$5,%lo(LogFlag)($2)
	lui	$2,%hi(attack_saddr+36)
	sw	$4,%lo(attack_saddr+36)($2)
	lui	$2,%hi(attack_daddr+36)
	sw	$3,%lo(attack_daddr+36)($2)
	j	$L445
	li	$2,-1			# 0xffffffffffffffff

$L502:
	move	$2,$0
$L445:
	or	$19,$19,$2
$L444:
	bne	$19,$0,$L399
	move	$2,$0

$L403:
	jalr	$20
	move	$4,$16

	lbu	$3,9($2)
	li	$2,1			# 0x1
	beq	$3,$2,$L504
	lui	$3,%hi(none_dos_drop_pkt_cnt)

	lw	$4,%lo(none_dos_drop_pkt_cnt)($3)
	nop
	addiu	$4,$4,1
	j	$L399
	sw	$4,%lo(none_dos_drop_pkt_cnt)($3)

$L503:
	j	$L399
	move	$2,$0

$L504:
	li	$2,4			# 0x4
$L399:
	lw	$31,52($sp)
	lw	$23,48($sp)
	lw	$22,44($sp)
	lw	$21,40($sp)
	lw	$20,36($sp)
	lw	$19,32($sp)
	lw	$18,28($sp)
	lw	$17,24($sp)
	lw	$16,20($sp)
	j	$31
	addiu	$sp,$sp,56

	.set	macro
	.set	reorder
	.end	filter_enter
	.size	filter_enter, .-filter_enter
	.section	.rodata.str1.4
	.align	2
$LC30:
	.ascii	"enable_dos\000"
	.section	.init.text,"ax",@progbits
	.align	2
	.globl	filter_init
	.set	nomips16
	.ent	filter_init
	.type	filter_init, @function
filter_init:
	.frame	$sp,32,$31		# vars= 0, regs= 2/0, args= 24, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$16,24($sp)
	lui	$2,%hi(item)
	sw	$0,%lo(item)($2)
	lui	$2,%hi(none_dos_drop_pkt_cnt)
	sw	$0,%lo(none_dos_drop_pkt_cnt)($2)
	lui	$2,%hi(url_count)
	sb	$0,%lo(url_count)($2)
	lui	$4,%hi($LC30)
	lui	$6,%hi(proc_root)
	lui	$7,%hi(dos_proc_fops)
	lui	$2,%hi(proc_create_data)
	addiu	$4,$4,%lo($LC30)
	move	$5,$0
	addiu	$6,$6,%lo(proc_root)
	addiu	$7,$7,%lo(dos_proc_fops)
	addiu	$2,$2,%lo(proc_create_data)
	jalr	$2
	sw	$0,16($sp)

	lui	$3,%hi(res3)
	lui	$16,%hi(dos_timer)
	sw	$2,%lo(res3)($3)
	lui	$2,%hi(init_timer_key)
	move	$7,$0
	move	$6,$0
	addiu	$4,$16,%lo(dos_timer)
	addiu	$2,$2,%lo(init_timer_key)
	jalr	$2
	move	$5,$0

	lui	$2,%hi(jiffies)
	lw	$3,%lo(jiffies)($2)
	lw	$5,%lo(jiffies)($2)
	addiu	$2,$16,%lo(dos_timer)
	addiu	$3,$3,100
	sw	$3,8($2)
	lui	$3,%hi(dos_timer_fn)
	addiu	$3,$3,%lo(dos_timer_fn)
	sw	$3,16($2)
	move	$4,$2
	sw	$0,20($2)
	lui	$2,%hi(mod_timer)
	addiu	$2,$2,%lo(mod_timer)
	jalr	$2
	addiu	$5,$5,100

	lui	$16,%hi(_tcpDosScanBitmap)
	lui	$2,%hi(memset)
	addiu	$4,$16,%lo(_tcpDosScanBitmap)
	move	$5,$0
	addiu	$2,$2,%lo(memset)
	jalr	$2
	li	$6,64			# 0x40

	addiu	$3,$16,%lo(_tcpDosScanBitmap)
	li	$2,1			# 0x1
	sb	$2,63($3)
	sb	$2,58($3)
	sb	$2,41($3)
	sb	$2,40($3)
	sb	$2,33($3)
	sb	$2,32($3)
	sb	$2,9($3)
	sb	$2,8($3)
	sb	$2,3($3)
	sb	$2,%lo(_tcpDosScanBitmap)($16)
	lui	$2,%hi(filter_init_fastpath)
	addiu	$2,$2,%lo(filter_init_fastpath)
	jalr	$2
	nop

	lui	$2,%hi(igmp_delete_init_netlink)
	addiu	$2,$2,%lo(igmp_delete_init_netlink)
	jalr	$2
	nop

	lw	$31,28($sp)
	lw	$16,24($sp)
	move	$2,$0
	j	$31
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	filter_init
	.size	filter_init, .-filter_init
	.section	.exit.text,"ax",@progbits
	.align	2
	.globl	filter_exit
	.set	nomips16
	.ent	filter_exit
	.type	filter_exit, @function
filter_exit:
	.frame	$sp,24,$31		# vars= 0, regs= 2/0, args= 16, gp= 0
	.mask	0x80010000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$31,20($sp)
	sw	$16,16($sp)
	lui	$16,%hi(res3)
	lw	$5,%lo(res3)($16)
	nop
	beq	$5,$0,$L527
	lui	$4,%hi($LC30)

	lui	$2,%hi(remove_proc_entry)
	addiu	$2,$2,%lo(remove_proc_entry)
	jalr	$2
	addiu	$4,$4,%lo($LC30)

	sw	$0,%lo(res3)($16)
$L527:
	lui	$4,%hi(dos_timer)
	lui	$2,%hi(del_timer)
	addiu	$2,$2,%lo(del_timer)
	jalr	$2
	addiu	$4,$4,%lo(dos_timer)

	lw	$31,20($sp)
	lw	$16,16($sp)
	lui	$25,%hi(filter_exit_fastpath)
	addiu	$25,$25,%lo(filter_exit_fastpath)
	jr	$25
	addiu	$sp,$sp,24

	.set	macro
	.set	reorder
	.end	filter_exit
	.size	filter_exit, .-filter_exit
	.globl	fast_path_cusRspTCPEndAck_func
	.section	.bss,"aw",@nobits
	.align	2
	.type	fast_path_cusRspTCPEndAck_func, @object
	.size	fast_path_cusRspTCPEndAck_func, 4
fast_path_cusRspTCPEndAck_func:
	.space	4
	.globl	fast_path_cusRspTCPFinAck_func
	.align	2
	.type	fast_path_cusRspTCPFinAck_func, @object
	.size	fast_path_cusRspTCPFinAck_func, 4
fast_path_cusRspTCPFinAck_func:
	.space	4
	.globl	fast_path_cusRsp401_func
	.align	2
	.type	fast_path_cusRsp401_func, @object
	.size	fast_path_cusRsp401_func, 4
fast_path_cusRsp401_func:
	.space	4
	.globl	dos_proc_fops
	.data
	.align	2
	.type	dos_proc_fops, @object
	.size	dos_proc_fops, 108
dos_proc_fops:
	.space	4
	.word	seq_lseek
	.word	seq_read
	.word	dos_single_write
	.space	28
	.word	dos_single_open
	.space	4
	.word	single_release
	.space	52
	.globl	___strtok
	.section	.bss
	.align	2
	.type	___strtok, @object
	.size	___strtok, 4
___strtok:
	.space	4
	.globl	wan_ppp_dev
	.align	2
	.type	wan_ppp_dev, @object
	.size	wan_ppp_dev, 4
wan_ppp_dev:
	.space	4
	.globl	wan_dev
	.align	2
	.type	wan_dev, @object
	.size	wan_dev, 4
wan_dev:
	.space	4
	.globl	filter_table_proc_fops
	.data
	.align	2
	.type	filter_table_proc_fops, @object
	.size	filter_table_proc_fops, 108
filter_table_proc_fops:
	.space	4
	.word	seq_lseek
	.word	seq_read
	.word	filter_table_single_write
	.space	28
	.word	filter_table_single_open
	.space	4
	.word	single_release
	.space	52
	.globl	table_list_head
	.section	.bss
	.align	2
	.type	table_list_head, @object
	.size	table_list_head, 32
table_list_head:
	.space	32
	.globl	filter_tlb
	.data
	.align	2
	.type	filter_tlb, @object
	.size	filter_tlb, 40
filter_tlb:
	.word	0
	.word	0
	.word	1
	.word	rtl_ip_range_filter_fastpath
	.word	2
	.word	rtl_mac_filter_fastpath
	.word	3
	.word	rtl_url_filter_fastpath
	.word	4
	.word	rtl_schedule_filter_fastpath
	.local	get_info_from_usr_space
	.comm	get_info_from_usr_space,1024,4
	.local	log_enable
	.comm	log_enable,4,4
	.local	url_filter_mode
	.comm	url_filter_mode,4,4
	.local	filter_rule_num
	.comm	filter_rule_num,4,4
	.local	dos_flag
	.comm	dos_flag,80,4
	.local	op_mode
	.comm	op_mode,1,1
	.local	lan_addr
	.comm	lan_addr,4,4
	.local	lan_mask
	.comm	lan_mask,4,4
	.section	.dram-l34-fwd,"aw",@progbits
	.align	2
	.type	item, @object
	.size	item, 4
item:
	.space	4
	.local	item_backup
	.comm	item_backup,4,4
	.local	whole_syn_threshold
	.comm	whole_syn_threshold,4,4
	.local	whole_fin_threshold
	.comm	whole_fin_threshold,4,4
	.local	whole_udp_threshold
	.comm	whole_udp_threshold,4,4
	.local	whole_icmp_threshold
	.comm	whole_icmp_threshold,4,4
	.local	per_syn_threshold
	.comm	per_syn_threshold,4,4
	.local	per_fin_threshold
	.comm	per_fin_threshold,4,4
	.local	per_udp_threshold
	.comm	per_udp_threshold,4,4
	.local	per_icmp_threshold
	.comm	per_icmp_threshold,4,4
	.local	block_time
	.comm	block_time,4,4
	.local	log_info
	.comm	log_info,32,4
	.local	url_filter_flag
	.comm	url_filter_flag,4,4
	.local	res12
	.comm	res12,4,4
	.local	block_message
	.comm	block_message,4,4
	.local	url_cache
	.comm	url_cache,20,4
	.local	finStateClientPort
	.comm	finStateClientPort,2,2
	.local	finStateClientSeq
	.comm	finStateClientSeq,4,4
	.local	ConnectedIp
	.comm	ConnectedIp,1024,4
	.local	endStateClientPort
	.comm	endStateClientPort,2,2
	.local	endStateClientSeq
	.comm	endStateClientSeq,4,4
	.align	2
	.type	none_dos_drop_pkt_cnt, @object
	.size	none_dos_drop_pkt_cnt, 4
none_dos_drop_pkt_cnt:
	.space	4
	.local	cur_p_pkt
	.comm	cur_p_pkt,4,4
	.local	block
	.comm	block,4,4
	.local	attack_saddr
	.comm	attack_saddr,60,4
	.local	attack_daddr
	.comm	attack_daddr,60,4
	.local	LogFlag
	.comm	LogFlag,4,4
	.local	_tcpDosScanBitmap
	.comm	_tcpDosScanBitmap,64,4
	.local	dos_pkt
	.comm	dos_pkt,36864,4
	.type	url_count, @object
	.size	url_count, 1
url_count:
	.space	1
	.local	res3
	.comm	res3,4,4
	.local	dos_timer
	.comm	dos_timer,28,4
	.local	block_count
	.comm	block_count,4,4
	.ident	"GCC: (Realtek RSDK-4.6.4 Build 424) 4.6.4"
