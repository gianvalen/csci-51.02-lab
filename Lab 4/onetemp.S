	.file	"cppassembly2.cpp"
	.text
	.globl	_Z5dummyii
	.def	_Z5dummyii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5dummyii
_Z5dummyii:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	16(%rbp), %eax
	subl	24(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	16(%rbp), %eax
	imull	24(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	16(%rbp), %eax
	cltd
	idivl	24(%rbp)
	movl	%eax, -16(%rbp)
	movl	16(%rbp), %eax
	cltd
	idivl	24(%rbp)
	movl	%edx, -20(%rbp)
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$3, %edx
	movl	$19, %ecx
	call	_Z5dummyii
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
