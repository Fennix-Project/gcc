	.text
	.p2align 4,,15
	.globl _snapshot
_snapshot:
.LFB3:
	movq	%rax, _rax(%rip)
	movq	%rbx, _rbx(%rip)
	movq	%rcx, _rcx(%rip)
	movq	%rdx, _rdx(%rip)
	movq	%rdi, _rdi(%rip)
	movq	%rsi, _rsi(%rip)
	movq	%rbp, _rbp(%rip)
	movq	%rsp, _rsp(%rip)
	movq	%r8, _r8(%rip)
	movq	%r9, _r9(%rip)
	movq	%r10, _r10(%rip)
	movq	%r11, _r11(%rip)
	movq	%r12, _r12(%rip)
	movq	%r13, _r13(%rip)
	movq	%r14, _r14(%rip)
	movq	%r15, _r15(%rip)
	vmovdqu32 %zmm0, _zmm_regs+0(%rip)
	vmovdqu32 %zmm1, _zmm_regs+64(%rip)
	vmovdqu32 %zmm2, _zmm_regs+128(%rip)
	vmovdqu32 %zmm3, _zmm_regs+192(%rip)
	vmovdqu32 %zmm4, _zmm_regs+256(%rip)
	vmovdqu32 %zmm5, _zmm_regs+320(%rip)
	vmovdqu32 %zmm6, _zmm_regs+384(%rip)
	vmovdqu32 %zmm7, _zmm_regs+448(%rip)
	vmovdqu32 %zmm8, _zmm_regs+512(%rip)
	vmovdqu32 %zmm9, _zmm_regs+576(%rip)
	vmovdqu32 %zmm10, _zmm_regs+640(%rip)
	vmovdqu32 %zmm11, _zmm_regs+704(%rip)
	vmovdqu32 %zmm12, _zmm_regs+768(%rip)
	vmovdqu32 %zmm13, _zmm_regs+832(%rip)
	vmovdqu32 %zmm14, _zmm_regs+896(%rip)
	vmovdqu32 %zmm15, _zmm_regs+960(%rip)
	vmovdqu32 %zmm16, _zmm_regs+1024(%rip)
	vmovdqu32 %zmm17, _zmm_regs+1088(%rip)
	vmovdqu32 %zmm18, _zmm_regs+1152(%rip)
	vmovdqu32 %zmm19, _zmm_regs+1216(%rip)
	vmovdqu32 %zmm20, _zmm_regs+1280(%rip)
	vmovdqu32 %zmm21, _zmm_regs+1344(%rip)
	vmovdqu32 %zmm22, _zmm_regs+1408(%rip)
	vmovdqu32 %zmm23, _zmm_regs+1472(%rip)
	vmovdqu32 %zmm24, _zmm_regs+1536(%rip)
	vmovdqu32 %zmm25, _zmm_regs+1600(%rip)
	vmovdqu32 %zmm26, _zmm_regs+1664(%rip)
	vmovdqu32 %zmm27, _zmm_regs+1728(%rip)
	vmovdqu32 %zmm28, _zmm_regs+1792(%rip)
	vmovdqu32 %zmm29, _zmm_regs+1856(%rip)
	vmovdqu32 %zmm30, _zmm_regs+1920(%rip)
	vmovdqu32 %zmm31, _zmm_regs+1984(%rip)
	jmp	*_callthis(%rip)
.LFE3:

	.p2align 4,,15
	.globl _snapshot_ret
_snapshot_ret:
	movq	%rdi, _rdi(%rip)
	subq	$8, %rsp
	call	*_callthis(%rip)
	addq	$8, %rsp
	movq	%rax, _rax(%rip)
	movq	%rdx, _rdx(%rip)
	vmovdqu32	%zmm0, _zmm_regs+0(%rip)
	vmovdqu32	%zmm1, _zmm_regs+64(%rip)
	fstpt	_x87_regs(%rip)
	fstpt	_x87_regs+16(%rip)
	fldt	_x87_regs+16(%rip)
	fldt	_x87_regs(%rip)
	ret

	.globl	_callthis
	.zerofill __DATA,__bss,_callthis,8,3
	.globl	_rax
	.zerofill __DATA,__bss,_rax,8,3
	.globl	_rbx
	.zerofill __DATA,__bss,_rbx,8,3
	.globl	_rcx
	.zerofill __DATA,__bss,_rcx,8,3
	.globl	_rdx
	.zerofill __DATA,__bss,_rdx,8,3
	.globl	_rsi
	.zerofill __DATA,__bss,_rsi,8,3
	.globl	_rdi
	.zerofill __DATA,__bss,_rdi,8,3
	.globl	_rsp
	.zerofill __DATA,__bss,_rsp,8,3
	.globl	_rbp
	.zerofill __DATA,__bss,_rbp,8,3
	.globl	_r8
	.zerofill __DATA,__bss,_r8,8,3
	.globl	_r9
	.zerofill __DATA,__bss,_r9,8,3
	.globl	_r10
	.zerofill __DATA,__bss,_r10,8,3
	.globl	_r11
	.zerofill __DATA,__bss,_r11,8,3
	.globl	_r12
	.zerofill __DATA,__bss,_r12,8,3
	.globl	_r13
	.zerofill __DATA,__bss,_r13,8,3
	.globl	_r14
	.zerofill __DATA,__bss,_r14,8,3
	.globl	_r15
	.zerofill __DATA,__bss,_r15,8,3
	.globl	_zmm_regs
	.zerofill __DATA,__bss,_zmm_regs,2048,6
	.globl	_x87_regs
	.zerofill __DATA,__bss,_x87_regs,128,5
	.globl	_volatile_var
	.zerofill __DATA,__bss,_volatile_var,8,3
