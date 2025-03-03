_Z17manhattanDistanceRK7Point3DS1_:
.LFB2069:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)		// first parameter
	movq	%rdx, 24(%rbp)		// second parameter
	movq	16(%rbp), %rax		// start: x1 - x2
	movl	(%rax), %edx
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -4(%rbp)		// end: x1 - x2
	movq	16(%rbp), %rax		// start: y1 - y2
	movl	4(%rax), %edx
	movq	24(%rbp), %rax
	movl	4(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -8(%rbp)		// end: y1 - y2
	movq	16(%rbp), %rax		// start: z1 - z2
	movl	8(%rax), %edx
	movq	24(%rbp), %rax
	movl	8(%rax), %eax
	subl	%eax, %edx
	movl	%edx, -12(%rbp)		// end: z1 - z2
	movl	-4(%rbp), %eax      // load x1 - x2
	movl	%eax, %edx
	negl	%edx
	cmovs	%eax, %edx          // abs
	movl	-8(%rbp), %eax      // load y1 - y2
	movl	%eax, %ecx
	negl	%ecx
	cmovns	%ecx, %eax          // abs
	addl	%eax, %edx          // add x1 - x2 and y1 - y2
	movl	-12(%rbp), %eax     // load z1 - z2
	movl	%eax, %ecx 
	negl	%ecx
	cmovns	%ecx, %eax          // abs
	addl	%edx, %eax          // add x1 - x2 and y1 - y2 and z1 - z2
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2070:
    pushq	%rbp                // start: function prologue
    .seh_pushreg	%rbp
    pushq	%rbx
    .seh_pushreg	%rbx
    subq	$88, %rsp
    .seh_stackalloc	88
    leaq	80(%rsp), %rbp
    .seh_setframe	%rbp, 80
    .seh_endprologue
    call	__main              // end: function prologue
    leaq	-36(%rbp), %rax     // start: cin >> test_cases
    movq	%rax, %rdx
    movq	.refptr._ZSt3cin(%rip), %rax
    movq	%rax, %rcx
    call	_ZNSirsERi          // end: cin >> test_cases
    movl	$0, -4(%rbp)        // for (int i = 0; i < test_cases; i++) 
    jmp	.L4                     // L4 is the loop condition
.L10:
    movq	%rsp, %rax          // start: cin >> num_of_points;
    movq	%rax, %rbx
    leaq	-40(%rbp), %rax
    movq	%rax, %rdx
    movq	.refptr._ZSt3cin(%rip), %rax
    movq	%rax, %rcx
    call	_ZNSirsERi          // end: cin >> num_of_points;
    movl	-40(%rbp), %ecx     // Point3D points[num_of_points]
    movslq	%ecx, %rax          
    subq	$1, %rax            // subtract because zero-indexed
    movq	%rax, -24(%rbp)
    movslq	%ecx, %rax
    movq	%rax, %r8
    movl	$0, %r9d            // temporary variable = 0
    movq	%r8, %rax
    movq	%r9, %rdx
    addq	%rax, %rax
    adcq	%rdx, %rdx
    addq	%r8, %rax           // multiply by 3 (total: num_of_points * 3)
    adcq	%r9, %rdx
    shldq	$5, %rax, %rdx      // multiply by 32 (total: num_of_points * 96 bytes)
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
    call	___chkstk_ms        // stack space
    subq	%rax, %rsp
    leaq	32(%rsp), %rax
    addq	$3, %rax
    shrq	$2, %rax
    salq	$2, %rax
    movq	%rax, -32(%rbp)
    movl	$0, -8(%rbp)        // i = 0
    jmp	.L5
.L6:
    movl	-8(%rbp), %eax
    movslq	%eax, %rdx          // start: getting byte offset
    movq	%rdx, %rax
    addq	%rax, %rax
    addq	%rdx, %rax
    salq	$2, %rax            //end: getting byte offset
    movq	-32(%rbp), %rdx
    addq	%rdx, %rax
    movq	%rax, %rdx
    movq	.refptr._ZSt3cin(%rip), %rax
    movq	%rax, %rcx
    call	_ZNSirsERi          // cin >> points[i].x
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
    call	_ZNSirsERi          // cin >> points[i].y
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
    call	_ZNSirsERi          // cin >> points[i].z
    addl	$1, -8(%rbp)
.L5:                            // for (int i = 0; i < num_of_points; i++)
    movl	-40(%rbp), %eax
    cmpl	%eax, -8(%rbp)
    jl	.L6                     // jump if i < num_of_points
    movl	$0, -12(%rbp)
    jmp	.L7                     // otherwise, jump to L7
.L8:
    movl	-12(%rbp), %eax     // load i (loop counter)
    addl	$1, %eax            // computation...
    movslq	%eax, %rdx
    movq	%rdx, %rax
    addq	%rax, %rax
    addq	%rdx, %rax
    salq	$2, %rax
    movq	-32(%rbp), %rdx
    leaq	(%rax,%rdx), %rcx   // address to point[i + 1]
    movl	-12(%rbp), %eax     // computation...
    movslq	%eax, %rdx
    movq	%rdx, %rax
    addq	%rax, %rax
    addq	%rdx, %rax
    salq	$2, %rax
    movq	-32(%rbp), %rdx
    addq	%rdx, %rax          // address of point[i]
    movq	%rcx, %rdx
    movq	%rax, %rcx
    call	_Z17manhattanDistanceRK7Point3DS1_      // call manhattanDistance
    movl	%eax, %edx
    movq	.refptr._ZSt4cout(%rip), %rax
    movq	%rax, %rcx
    call	_ZNSolsEi                               // print distance
    movq	%rax, %rcx
    movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
    movq	%rax, %rdx
    call	_ZNSolsEPFRSoS_E                        //print newline
    addl	$1, -12(%rbp)
.L7:
    movl	-40(%rbp), %eax     // load num_of_points
    subl	$1, %eax
    cmpl	%eax, -12(%rbp)     // compare (num_of_points - 1) with loop variable
    jl	.L8                     // jump if i < num_of_points - 1
    movl	-36(%rbp), %eax     // load test_cases
    testl	%eax, %eax          // check if test_cases > 0
    jle	.L9                     // jump if test_cases <= 0
    movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax      // cout << endl
    movq	%rax, %rdx
    movq	.refptr._ZSt4cout(%rip), %rax
    movq	%rax, %rcx
    call	_ZNSolsEPFRSoS_E
.L9:                           
    movq	%rbx, %rsp          // restore stack pointer
    addl	$1, -4(%rbp)        // increment loop counter
.L4:                            // checks if all test cases have been processed
    movl	-36(%rbp), %eax
    cmpl	%eax, -4(%rbp)      // compare test_cases with loop counter
    jl	.L10                    // jump to L10 if i < test_cases
    movl	$0, %               // exiting...
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
       