	.file	"hw.c"
	.intel_syntax noprefix
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Hex  Dec  Oct   Ch\12\0"
.LC1:
	.ascii "%3x  %3d  %3o   %c\12\0"
.LC2:
	.ascii "pause\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 80
	.seh_stackalloc	80
	.seh_endprologue
	mov	DWORD PTR 16[rbp], ecx
	mov	QWORD PTR 24[rbp], rdx
	call	__main
	lea	rax, .LC0[rip]
	mov	QWORD PTR -16[rbp], rax
	lea	rax, .LC1[rip]
	mov	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -16[rbp]
	mov	rcx, rax
	call	puts
	mov	DWORD PTR -4[rbp], 32
	jmp	.L2
.L3:
	mov	r9d, DWORD PTR -4[rbp]
	mov	r8d, DWORD PTR -4[rbp]
	mov	edx, DWORD PTR -4[rbp]
	mov	rax, QWORD PTR -24[rbp]
	mov	ecx, DWORD PTR -4[rbp]
	mov	DWORD PTR 32[rsp], ecx
	mov	rcx, rax
	call	printf
	add	DWORD PTR -4[rbp], 1
.L2:
	cmp	DWORD PTR -4[rbp], 255
	jle	.L3
	lea	rcx, .LC2[rip]
	call	system
	mov	eax, 0
	add	rsp, 80
	pop	rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	system;	.scl	2;	.type	32;	.endef
