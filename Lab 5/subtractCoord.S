	.file	"subtractCoord_main.cpp"
	.text
	.globl	_Z13subtractCoord7Point3DS_
	.def	_Z13subtractCoord7Point3DS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z13subtractCoord7Point3DS_
_Z13subtractCoord7Point3DS_:
.LFB2069:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	leaq	(%rsp), %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, %rsi
	movq	%rdx, %rbx
	movl	(%rsi), %edx
	movl	(%rbx), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popq	%rbx
	popq	%rsi
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
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$6, -12(%rbp)
	movl	$2, -8(%rbp)
	movl	$8, -4(%rbp)
	movl	$3, -24(%rbp)
	movl	$6, -20(%rbp)
	movl	$9, -16(%rbp)
	movq	-12(%rbp), %rax
	movq	%rax, -48(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -64(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -56(%rbp)
	leaq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_Z13subtractCoord7Point3DS_
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$96, %rsp
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
