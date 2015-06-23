	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_foobar
	.align	4, 0x90
_foobar:                                ## @foobar
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp2:
	.cfi_def_cfa_register rbp
	mov	dword ptr [rbp - 4], edi
	mov	dword ptr [rbp - 8], esi
	mov	dword ptr [rbp - 12], edx
	mov	edx, dword ptr [rbp - 4]
	add	edx, 2
	mov	dword ptr [rbp - 16], edx
	mov	edx, dword ptr [rbp - 8]
	add	edx, 3
	mov	dword ptr [rbp - 20], edx
	mov	edx, dword ptr [rbp - 12]
	add	edx, 4
	mov	dword ptr [rbp - 24], edx
	mov	edx, dword ptr [rbp - 16]
	add	edx, dword ptr [rbp - 20]
	add	edx, dword ptr [rbp - 24]
	mov	dword ptr [rbp - 28], edx
	mov	edx, dword ptr [rbp - 16]
	imul	edx, dword ptr [rbp - 20]
	imul	edx, dword ptr [rbp - 24]
	add	edx, dword ptr [rbp - 28]
	mov	eax, edx
	pop	rbp
	ret
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	push	rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
Ltmp5:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	edi, 77
	mov	esi, 88
	mov	edx, 99
	mov	dword ptr [rbp - 4], 0
	call	_foobar
	add	rsp, 16
	pop	rbp
	ret
	.cfi_endproc


.subsections_via_symbols
