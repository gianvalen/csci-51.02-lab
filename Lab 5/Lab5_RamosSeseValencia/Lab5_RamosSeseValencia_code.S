	.file	"Lab5_RamosSeseValencia_code.cpp"
	.text
	.globl	_Z17manhattanDistanceRK7Point3DS1_
	.def	_Z17manhattanDistanceRK7Point3DS1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z17manhattanDistanceRK7Point3DS1_
_Z17manhattanDistanceRK7Point3DS1_:
.LFB2069:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -4(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %edx
	movq	24(%rbp), %rax
	movl	4(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -8(%rbp)
	movq	16(%rbp), %rax
	movl	8(%rax), %edx
	movq	24(%rbp), %rax
	movl	8(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edx
	negl	%edx
	cmovs	%eax, %edx
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	negl	%ecx
	cmovns	%ecx, %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	movl	%eax, %ecx
	negl	%ecx
	cmovns	%ecx, %eax
	addl	%edx, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2070:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	80(%rsp), %rbp
	.seh_setframe	%rbp, 80
	.seh_endprologue
	call	__main
	leaq	-36(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	$0, -4(%rbp)
	jmp	.L4
.L10:
	movq	%rsp, %rax
	movq	%rax, %rbx
	leaq	-40(%rbp), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	-40(%rbp), %ecx
	movslq	%ecx, %rax
	subq	$1, %rax
	movq	%rax, -24(%rbp)
	movslq	%ecx, %rax
	movq	%rax, %r8
	movl	$0, %r9d
	movq	%r8, %rax
	movq	%r9, %rdx
	addq	%rax, %rax
	adcq	%rdx, %rdx
	addq	%r8, %rax
	adcq	%r9, %rdx
	shldq	$5, %rax, %rdx
	salq	$5, %rax
	movslq	%ecx, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movslq	%ecx, %rax
	movq	%rax, %r8
	movl	$0, %r9d
	movq	%r8, %rax
	movq	%r9, %rdx
	addq	%rax, %rax
	adcq	%rdx, %rdx
	addq	%r8, %rax
	adcq	%r9, %rdx
	shldq	$5, %rax, %rdx
	salq	$5, %rax
	movslq	%ecx, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERi
	movq	%rax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	addq	$4, %rax
	movq	%rax, %rdx
	call	_ZNSirsERi
	movq	%rax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	addq	$8, %rax
	movq	%rax, %rdx
	call	_ZNSirsERi
	addl	$1, -8(%rbp)
.L5:
	movl	-40(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L6
	movl	$0, -12(%rbp)
	jmp	.L7
.L8:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	leaq	(%rax,%rdx), %rcx
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rcx, %rdx
	movq	%rax, %rcx
	call	_Z17manhattanDistanceRK7Point3DS1_
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	addl	$1, -12(%rbp)
.L7:
	movl	-40(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -12(%rbp)
	jl	.L8
	movl	-36(%rbp), %eax
	testl	%eax, %eax
	jle	.L9
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
.L9:
	movq	%rbx, %rsp
	addl	$1, -4(%rbp)
.L4:
	movl	-36(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L10
	movl	$0, %eax
	leaq	8(%rbp), %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
