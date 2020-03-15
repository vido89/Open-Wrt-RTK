	.file	1 "rtkjnl.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 3
	.text
	.align	2
	.globl	bsp_id_check
	.set	nomips16
	.ent	bsp_id_check
	.type	bsp_id_check, @function
bsp_id_check:
	.frame	$sp,0,$31		# vars= 0, regs= 0/0, args= 0, gp= 0
	.mask	0x00000000,0
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	li	$2,-1207959552			# 0xffffffffb8000000
	lw	$3,0($2)
	li	$2,-65536			# 0xffffffffffff0000
	and	$2,$3,$2
	li	$3,2120744960			# 0x7e680000
	addu	$2,$2,$3
	sltu	$2,$0,$2
	j	$31
	subu	$2,$0,$2

	.set	macro
	.set	reorder
	.end	bsp_id_check
	.size	bsp_id_check, .-bsp_id_check
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align	2
$LC0:
	.ascii	"version\000"
	.align	2
$LC1:
	.ascii	"\0015jnl: cannot create /proc/%s\000"
	.align	2
$LC2:
	.ascii	"jnl_revoke_record\000"
	.align	2
$LC3:
	.ascii	"jnl_head\000"
	.align	2
$LC4:
	.ascii	"jnl_handle\000"
	.align	2
$LC5:
	.ascii	"jnl_free_data\000"
	.align	2
$LC6:
	.ascii	"\0015jnl: vendor chip is not supported!\012\000"
	.align	2
$LC7:
	.ascii	"\0015jnl: driver (%s) loaded at %p\012\000"
	.section	.init.text,"ax",@progbits
	.align	2
	.set	nomips16
	.ent	jnl_init
	.type	jnl_init, @function
jnl_init:
	.frame	$sp,48,$31		# vars= 0, regs= 5/0, args= 24, gp= 0
	.mask	0x800f0000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-48
	li	$2,-1207959552			# 0xffffffffb8000000
	sw	$31,44($sp)
	sw	$19,40($sp)
	sw	$18,36($sp)
	sw	$17,32($sp)
	sw	$16,28($sp)
	lw	$3,0($2)
	li	$2,-65536			# 0xffffffffffff0000
	and	$3,$3,$2
	li	$2,-2120744960			# 0xffffffff81980000
	bne	$3,$2,$L25
	lui	$4,%hi($LC6)

	j	$L3
	lui	$2,%hi(__this_module+196)

$L13:
	addiu	$4,$17,%lo(proc_info_root_name)
	jal	proc_mkdir
	move	$5,$0

	beq	$2,$0,$L5
	sw	$2,%lo(proc_info_root)($16)

	lui	$4,%hi($LC0)
	lui	$7,%hi(jnl_proc_version_fops)
	sw	$0,16($sp)
	addiu	$4,$4,%lo($LC0)
	move	$5,$0
	move	$6,$2
	jal	proc_create_data
	addiu	$7,$7,%lo(jnl_proc_version_fops)

	j	$L28
	lui	$2,%hi(size_jnl_revoke_record)

$L5:
	lui	$4,%hi($LC1)
	addiu	$4,$4,%lo($LC1)
	jal	printk
	addiu	$5,$17,%lo(proc_info_root_name)

	lui	$2,%hi(size_jnl_revoke_record)
$L28:
	lw	$5,%lo(size_jnl_revoke_record)($2)
	lui	$4,%hi($LC2)
	li	$7,131072			# 0x20000
	sw	$0,16($sp)
	addiu	$4,$4,%lo($LC2)
	move	$6,$0
	jal	kmem_cache_create
	addiu	$7,$7,8192

	lui	$3,%hi(jnl_revoke_record_cache)
	sw	$2,%lo(jnl_revoke_record_cache)($3)
	bne	$2,$0,$L7
	move	$17,$3

	j	$L21
	li	$2,-12			# 0xfffffffffffffff4

$L7:
	lui	$2,%hi(size_jnl_head)
	lw	$5,%lo(size_jnl_head)($2)
	lui	$4,%hi($LC3)
	addiu	$4,$4,%lo($LC3)
	sw	$0,16($sp)
	move	$6,$0
	jal	kmem_cache_create
	li	$7,131072			# 0x20000

	lui	$4,%hi(jnl_head_cache)
	sw	$2,%lo(jnl_head_cache)($4)
	beq	$2,$0,$L9
	move	$19,$4

	lui	$2,%hi(size_jnl_handle)
	lw	$5,%lo(size_jnl_handle)($2)
	lui	$4,%hi($LC4)
	sw	$0,16($sp)
	addiu	$4,$4,%lo($LC4)
	move	$6,$0
	jal	kmem_cache_create
	li	$7,131072			# 0x20000

	lui	$18,%hi(jnl_handle_cache)
	beq	$2,$0,$L10
	sw	$2,%lo(jnl_handle_cache)($18)

	lui	$2,%hi(size_jnl_free_data)
	lw	$5,%lo(size_jnl_free_data)($2)
	lui	$4,%hi($LC5)
	sw	$0,16($sp)
	addiu	$4,$4,%lo($LC5)
	move	$6,$0
	jal	kmem_cache_create
	li	$7,131072			# 0x20000

	move	$5,$2
	lui	$2,%hi(jnl_free_data_cachep)
	sw	$5,%lo(jnl_free_data_cachep)($2)
	bne	$5,$0,$L21
	move	$2,$0

$L11 = .
	jal	kmem_cache_destroy
	lw	$4,%lo(jnl_handle_cache)($18)

	sw	$0,%lo(jnl_handle_cache)($18)
$L10:
	jal	kmem_cache_destroy
	lw	$4,%lo(jnl_head_cache)($19)

	sw	$0,%lo(jnl_head_cache)($19)
$L9:
	jal	kmem_cache_destroy
	lw	$4,%lo(jnl_revoke_record_cache)($17)

	lw	$5,%lo(proc_info_root)($16)
	beq	$5,$0,$L27
	sw	$0,%lo(jnl_revoke_record_cache)($17)

	lui	$4,%hi($LC0)
	jal	remove_proc_entry
	addiu	$4,$4,%lo($LC0)

	lui	$4,%hi(proc_info_root_name)
	lui	$2,%hi(proc_info_root)
	addiu	$4,$4,%lo(proc_info_root_name)
	move	$5,$0
	jal	remove_proc_entry
	sw	$0,%lo(proc_info_root)($2)

$L27:
	j	$L21
	li	$2,-12			# 0xfffffffffffffff4

$L25:
	jal	printk
	addiu	$4,$4,%lo($LC6)

	j	$L21
	li	$2,-12			# 0xfffffffffffffff4

$L3:
	lw	$6,%lo(__this_module+196)($2)
	lui	$4,%hi($LC7)
	lui	$5,%hi(s_DriverVer)
	addiu	$4,$4,%lo($LC7)
	addiu	$5,$5,%lo(s_DriverVer)
	jal	printk
	lui	$16,%hi(proc_info_root)

	lw	$2,%lo(proc_info_root)($16)
	bne	$2,$0,$L28
	lui	$2,%hi(size_jnl_revoke_record)

	j	$L13
	lui	$17,%hi(proc_info_root_name)

$L21:
	lw	$31,44($sp)
	lw	$19,40($sp)
	lw	$18,36($sp)
	lw	$17,32($sp)
	lw	$16,28($sp)
	j	$31
	addiu	$sp,$sp,48

	.set	macro
	.set	reorder
	.end	jnl_init
	.size	jnl_init, .-jnl_init
	.globl	init_module
	init_module = jnl_init
	.section	.rodata.str1.4
	.align	2
$LC8:
	.ascii	"\0015jnl: driver unloaded\012\000"
	.section	.exit.text,"ax",@progbits
	.align	2
	.set	nomips16
	.ent	jnl_exit
	.type	jnl_exit, @function
jnl_exit:
	.frame	$sp,32,$31		# vars= 0, regs= 3/0, args= 16, gp= 0
	.mask	0x80030000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$16,20($sp)
	lui	$16,%hi(proc_info_root)
	lw	$5,%lo(proc_info_root)($16)
	sw	$31,28($sp)
	beq	$5,$0,$L30
	sw	$17,24($sp)

	lui	$4,%hi($LC0)
	jal	remove_proc_entry
	addiu	$4,$4,%lo($LC0)

	lui	$4,%hi(proc_info_root_name)
	addiu	$4,$4,%lo(proc_info_root_name)
	move	$5,$0
	jal	remove_proc_entry
	sw	$0,%lo(proc_info_root)($16)

$L30:
	lui	$2,%hi(jnl_free_data_cachep)
	lw	$4,%lo(jnl_free_data_cachep)($2)
	beq	$4,$0,$L57
	lui	$2,%hi(jnl_handle_cache)

	jal	kmem_cache_destroy
	nop

	lui	$2,%hi(jnl_handle_cache)
$L57:
	lw	$4,%lo(jnl_handle_cache)($2)
	beq	$4,$0,$L58
	lui	$2,%hi(jnl_head_cache)

	jal	kmem_cache_destroy
	nop

	lui	$2,%hi(jnl_head_cache)
$L58:
	lw	$4,%lo(jnl_head_cache)($2)
	beq	$4,$0,$L59
	lui	$2,%hi(jnl_revoke_record_cache)

	jal	kmem_cache_destroy
	nop

	lui	$2,%hi(jnl_revoke_record_cache)
$L59:
	lw	$4,%lo(jnl_revoke_record_cache)($2)
	beq	$4,$0,$L60
	lui	$16,%hi(jnl_slab)

	jal	kmem_cache_destroy
	nop

$L60:
	addiu	$16,$16,%lo(jnl_slab)
	addiu	$17,$16,36
$L37:
	lw	$2,0($16)
	addiu	$16,$16,4
	beq	$2,$0,$L35
	move	$4,$2

	jal	kmem_cache_destroy
	nop

$L35:
	bne	$16,$17,$L37
	lw	$31,28($sp)

	lw	$17,24($sp)
	lw	$16,20($sp)
	lui	$4,%hi($LC8)
	addiu	$4,$4,%lo($LC8)
	j	printk
	addiu	$sp,$sp,32

	.set	macro
	.set	reorder
	.end	jnl_exit
	.size	jnl_exit, .-jnl_exit
	.globl	cleanup_module
	cleanup_module = jnl_exit
	.section	.modinfo,"a",@progbits
	.type	__UNIQUE_ID_license1, @object
	.size	__UNIQUE_ID_license1, 12
__UNIQUE_ID_license1:
	.ascii	"license=GPL\000"
	.ident	"GCC: (OpenWrt/Linaro GCC 4.8-2014.04 r32620) 4.8.3"
