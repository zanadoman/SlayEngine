	.file	"player.cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.p2align 4
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB11:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	leaq	88(%rsp), %rsi
	movq	%rdx, 88(%rsp)
	movq	%rcx, %rbx
	movl	$1, %ecx
	movq	%r8, 96(%rsp)
	movq	%r9, 104(%rsp)
	movq	%rsi, 40(%rsp)
	call	*__imp___acrt_iob_func(%rip)
	movq	%rsi, %r8
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "assets/player/player1.png\0"
.LC1:
	.ascii "assets/player/player2.png\0"
.LC2:
	.ascii "assets/player/player3.png\0"
.LC3:
	.ascii "assets/player/player4.png\0"
.LC4:
	.ascii "assets/player/player5.png\0"
.LC5:
	.ascii "assets/player/player6.png\0"
	.align 8
.LC6:
	.ascii "neo::array=: Memory allocation failed\12Params: Elements(type, length): %ld, %ld\12\0"
.LC7:
	.ascii "assets/crazy-pixel.ttf\0"
.LC10:
	.ascii "Player\0"
	.section	.text.unlikely,"x"
	.align 2
.LCOLDB11:
	.text
.LHOTB11:
	.align 2
	.p2align 4
	.globl	_ZN6playerC2ERN4slay6engineE
	.def	_ZN6playerC2ERN4slay6engineE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6playerC2ERN4slay6engineE
_ZN6playerC2ERN4slay6engineE:
.LFB8433:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	.seh_endprologue
	movq	%rdx, (%rcx)
	movq	%rcx, %rbx
	movq	%rdx, %rdi
	movq	$0, 24(%rcx)
	movq	$0, 32(%rcx)
	leaq	560(%rdx), %rcx
	leaq	.LC0(%rip), %rdx
.LEHB0:
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 48(%rsp)
	movq	(%rbx), %rax
	leaq	.LC1(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 56(%rsp)
	movq	(%rbx), %rax
	leaq	.LC2(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 64(%rsp)
	movq	(%rbx), %rax
	leaq	.LC3(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 72(%rsp)
	movq	(%rbx), %rax
	leaq	.LC4(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 80(%rsp)
	movq	(%rbx), %rax
	leaq	.LC5(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets11LoadTextureEPKc
	movq	%rax, 88(%rsp)
	movq	24(%rbx), %rax
	leaq	24(%rbx), %rbp
	cmpq	$6, %rax
	jne	.L10
	movq	32(%rbx), %rdx
.L6:
	leaq	48(%rsp), %rsi
	leaq	0(,%rax,8), %r8
	movq	%rsi, %rcx
	call	_ZN3neo9memCopyToEPKvPvy
	movq	(%rbx), %rax
	movl	$48, %r8d
	leaq	.LC7(%rip), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets8LoadFontEPKch
	movq	%rax, 48(%rbx)
	addq	$528, %rdi
	movl	$1, %edx
	movq	%rdi, %rcx
	call	_ZN4slay6engine6actors3NewEy
	movq	%rax, 8(%rbx)
	movq	%rax, %rdx
	movq	%rdi, %rcx
	call	_ZN4slay6engine6actorsixEy
	leaq	72(%rax), %rcx
	movq	%rbp, %rdx
	call	_ZN4slay6engine6actors5actor9flipbooks3NewEPN3neo5arrayIyEE
	movq	%rax, 16(%rbx)
	movq	8(%rbx), %rdx
	movq	%rdi, %rcx
	call	_ZN4slay6engine6actorsixEy
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5texts3NewEv
	movq	%rax, 40(%rbx)
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movsd	.LC8(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8SetLayerEd
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movsd	.LC9(%rip), %xmm1
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8SetDepthEd
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	16(%rbx), %rdx
	leaq	72(%rax), %rcx
	call	_ZN4slay6engine6actors5actor9flipbooksixEy
	movq	%rax, %rcx
	movl	$100, %edx
	call	_ZN4slay6engine6actors5actor9flipbooks8flipbook8SetDelayEj
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	16(%rbx), %rdx
	leaq	72(%rax), %rcx
	call	_ZN4slay6engine6actors5actor9flipbooksixEy
	movl	$100, %r8d
	movq	8(%rbx), %rdx
	movw	%r8w, 18(%rax)
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	16(%rbx), %rdx
	leaq	72(%rax), %rcx
	call	_ZN4slay6engine6actors5actor9flipbooksixEy
	movl	$100, %ecx
	movq	8(%rbx), %rdx
	movw	%cx, 20(%rax)
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	16(%rbx), %rdx
	leaq	72(%rax), %rcx
	call	_ZN4slay6engine6actors5actor9flipbooksixEy
	movb	$1, 16(%rax)
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	16(%rbx), %rdx
	leaq	72(%rax), %rcx
	call	_ZN4slay6engine6actors5actor9flipbooksixEy
	movb	$1, 17(%rax)
	leaq	.LC10(%rip), %rax
	movq	8(%rbx), %rdx
	movq	%rax, 48(%rsp)
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor5texts4text6StringEv
	movq	%rax, %rcx
	leaq	32(%rsp), %rdx
	movq	%rsi, 32(%rsp)
	movq	$1, 40(%rsp)
	call	_ZN3neo6stringaSESt16initializer_listIPKcE
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movq	48(%rbx), %rdx
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor5texts4text7SetFontEy
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movq	%rax, %rcx
	movl	$50, %edx
	call	_ZN4slay6engine6actors5actor5texts4text10SetOffsetYEi
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movl	$50, %edx
	movw	%dx, 18(%rax)
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movb	$1, 16(%rax)
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	40(%rbx), %rdx
	leaq	104(%rax), %rcx
	call	_ZN4slay6engine6actors5actor5textsixEy
	movb	$1, 17(%rax)
	addq	$104, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	movq	$6, 24(%rbx)
	movq	32(%rbx), %rcx
	movl	$48, %edx
	call	realloc
	movq	%rax, 32(%rbx)
	movq	%rax, %rdx
	testq	%rax, %rax
	je	.L5
	movq	24(%rbx), %rax
	jmp	.L6
.L5:
	movl	$6, %r8d
	movl	$8, %edx
	leaq	.LC6(%rip), %rcx
	call	_Z6printfPKcz
.LEHE0:
	movl	$1, %ecx
	call	exit
.L8:
	movq	%rax, %rsi
	jmp	.L7
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8433:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8433-.LLSDACSB8433
.LLSDACSB8433:
	.uleb128 .LEHB0-.LFB8433
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L8-.LFB8433
	.uleb128 0
.LLSDACSE8433:
	.text
	.seh_endproc
	.section	.text.unlikely,"x"
	.def	_ZN6playerC2ERN4slay6engineE.cold;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZN6playerC2ERN4slay6engineE.cold
	.seh_stackalloc	136
	.seh_savereg	%rbx, 104
	.seh_savereg	%rsi, 112
	.seh_savereg	%rdi, 120
	.seh_savereg	%rbp, 128
	.seh_endprologue
_ZN6playerC2ERN4slay6engineE.cold:
.L7:
	movq	32(%rbx), %rcx
	call	free
	movq	%rsi, %rcx
.LEHB1:
	call	_Unwind_Resume
	nop
.LEHE1:
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDAC8433:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC8433-.LLSDACSBC8433
.LLSDACSBC8433:
	.uleb128 .LEHB1-.LCOLDB11
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSEC8433:
	.section	.text.unlikely,"x"
	.text
	.section	.text.unlikely,"x"
	.seh_endproc
.LCOLDE11:
	.text
.LHOTE11:
	.globl	_ZN6playerC1ERN4slay6engineE
	.def	_ZN6playerC1ERN4slay6engineE;	.scl	2;	.type	32;	.endef
	.set	_ZN6playerC1ERN4slay6engineE,_ZN6playerC2ERN4slay6engineE
	.align 2
	.p2align 4
	.globl	_ZN6playerD2Ev
	.def	_ZN6playerD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6playerD2Ev
_ZN6playerD2Ev:
.LFB8436:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	cmpq	$0, 24(%rcx)
	movq	%rcx, %rbx
	je	.L12
	xorl	%esi, %esi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L13:
	movq	32(%rbx), %rdx
	addl	$1, %esi
	movq	(%rdx,%rax,8), %rdx
	movq	(%rbx), %rax
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets13UnloadTextureEy
	movzbl	%sil, %eax
	cmpq	24(%rbx), %rax
	jb	.L13
.L12:
	movq	(%rbx), %rax
	movq	48(%rbx), %rdx
	leaq	560(%rax), %rcx
	call	_ZN4slay6engine6assets10UnloadFontEy
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actors6DeleteEy
	movq	32(%rbx), %rcx
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	jmp	free
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8436:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8436-.LLSDACSB8436
.LLSDACSB8436:
.LLSDACSE8436:
	.text
	.seh_endproc
	.globl	_ZN6playerD1Ev
	.def	_ZN6playerD1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN6playerD1Ev,_ZN6playerD2Ev
	.align 2
	.p2align 4
	.globl	_ZN6player6UpdateEv
	.def	_ZN6player6UpdateEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6player6UpdateEv
_ZN6player6UpdateEv:
.LFB8438:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$80, %rsp
	.seh_stackalloc	80
	movaps	%xmm6, 48(%rsp)
	.seh_savexmm	%xmm6, 48
	movaps	%xmm7, 64(%rsp)
	.seh_savexmm	%xmm7, 64
	.seh_endprologue
	movl	$82, %edx
	movq	(%rcx), %rax
	movq	%rcx, %rbx
	leaq	160(%rax), %rcx
	call	_ZN4slay6engine4keysixENS_3keyE
	testb	%al, %al
	je	.L16
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	(%rbx), %rsi
	movq	8(%rbx), %rdx
	movq	%rax, %rdi
	leaq	528(%rsi), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8GetAngleEv
	movsd	.LC12(%rip), %xmm7
	movq	(%rbx), %rax
	movapd	%xmm0, %xmm3
	addsd	%xmm7, %xmm3
	leaq	632(%rax), %rcx
	movsd	%xmm3, 40(%rsp)
	call	_ZN4slay6engine6timing12GetDeltaTimeEv
	pxor	%xmm2, %xmm2
	movsd	.LC13(%rip), %xmm6
	movl	%eax, %eax
	cvtsi2sdq	%rax, %xmm2
.L38:
	mulsd	%xmm6, %xmm2
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	movsd	%xmm2, 32(%rsp)
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor4GetXEv
	movsd	32(%rsp), %xmm2
	movsd	40(%rsp), %xmm3
	leaq	552(%rsi), %rcx
	movapd	%xmm0, %xmm1
	call	_ZN4slay6engine6vector9TerminalXEddd
	movq	%rdi, %rcx
	movapd	%xmm0, %xmm1
	call	_ZN4slay6engine6actors5actor4SetXEd
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	(%rbx), %rsi
	movq	8(%rbx), %rdx
	movq	%rax, %rdi
	leaq	528(%rsi), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8GetAngleEv
	movq	(%rbx), %rax
	movapd	%xmm0, %xmm3
	addsd	%xmm7, %xmm3
	leaq	632(%rax), %rcx
	movsd	%xmm3, 40(%rsp)
	call	_ZN4slay6engine6timing12GetDeltaTimeEv
	pxor	%xmm2, %xmm2
	movq	8(%rbx), %rdx
	movl	%eax, %eax
	cvtsi2sdq	%rax, %xmm2
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	mulsd	%xmm6, %xmm2
	movsd	%xmm2, 32(%rsp)
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor4GetYEv
	movsd	40(%rsp), %xmm3
	movsd	32(%rsp), %xmm2
	leaq	552(%rsi), %rcx
	movapd	%xmm0, %xmm1
	call	_ZN4slay6engine6vector9TerminalYEddd
	movq	%rdi, %rcx
	movapd	%xmm0, %xmm1
	call	_ZN4slay6engine6actors5actor4SetYEd
.L21:
	movq	(%rbx), %rax
	movl	$80, %edx
	leaq	160(%rax), %rcx
	call	_ZN4slay6engine4keysixENS_3keyE
	testb	%al, %al
	je	.L26
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	8(%rbx), %rdx
	movq	%rax, %rsi
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8GetAngleEv
	movq	(%rbx), %rcx
	movapd	%xmm0, %xmm6
	addq	$632, %rcx
	call	_ZN4slay6engine6timing12GetDeltaTimeEv
	pxor	%xmm1, %xmm1
	movq	%rsi, %rcx
	movl	%eax, %eax
	cvtsi2sdq	%rax, %xmm1
	mulsd	.LC15(%rip), %xmm1
	addsd	%xmm6, %xmm1
	call	_ZN4slay6engine6actors5actor8SetAngleEd
	nop
.L29:
	movaps	48(%rsp), %xmm6
	movaps	64(%rsp), %xmm7
	xorl	%eax, %eax
	addq	$80, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L16:
	movq	(%rbx), %rax
	movl	$81, %edx
	leaq	160(%rax), %rcx
	call	_ZN4slay6engine4keysixENS_3keyE
	testb	%al, %al
	je	.L21
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	(%rbx), %rsi
	movq	8(%rbx), %rdx
	movq	%rax, %rdi
	leaq	528(%rsi), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8GetAngleEv
	movsd	.LC12(%rip), %xmm7
	movq	(%rbx), %rax
	movapd	%xmm0, %xmm3
	addsd	%xmm7, %xmm3
	leaq	632(%rax), %rcx
	movsd	%xmm3, 40(%rsp)
	call	_ZN4slay6engine6timing12GetDeltaTimeEv
	pxor	%xmm2, %xmm2
	movsd	.LC14(%rip), %xmm6
	movl	%eax, %eax
	cvtsi2sdq	%rax, %xmm2
	jmp	.L38
	.p2align 4,,10
	.p2align 3
.L26:
	movq	(%rbx), %rax
	movl	$79, %edx
	leaq	160(%rax), %rcx
	call	_ZN4slay6engine4keysixENS_3keyE
	testb	%al, %al
	je	.L29
	movq	(%rbx), %rax
	movq	8(%rbx), %rdx
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	8(%rbx), %rdx
	movq	%rax, %rsi
	movq	(%rbx), %rax
	leaq	528(%rax), %rcx
	call	_ZN4slay6engine6actorsixEy
	movq	%rax, %rcx
	call	_ZN4slay6engine6actors5actor8GetAngleEv
	movq	(%rbx), %rcx
	movsd	%xmm0, 32(%rsp)
	addq	$632, %rcx
	call	_ZN4slay6engine6timing12GetDeltaTimeEv
	pxor	%xmm2, %xmm2
	movsd	32(%rsp), %xmm1
	movq	%rsi, %rcx
	movl	%eax, %eax
	cvtsi2sdq	%rax, %xmm2
	mulsd	.LC15(%rip), %xmm2
	subsd	%xmm2, %xmm1
	call	_ZN4slay6engine6actors5actor8SetAngleEd
	jmp	.L29
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC8:
	.long	0
	.long	1072693248
	.align 8
.LC9:
	.long	-1717986918
	.long	1068079513
	.align 8
.LC12:
	.long	0
	.long	1079410688
	.align 8
.LC13:
	.long	0
	.long	1071644672
	.align 8
.LC14:
	.long	0
	.long	-1075838976
	.align 8
.LC15:
	.long	-1717986918
	.long	1070176665
	.ident	"GCC: (GNU) 13.1.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6assets11LoadTextureEPKc;	.scl	2;	.type	32;	.endef
	.def	_ZN3neo9memCopyToEPKvPvy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6assets8LoadFontEPKch;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors3NewEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actorsixEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor9flipbooks3NewEPN3neo5arrayIyEE;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor5texts3NewEv;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor8SetLayerEd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor8SetDepthEd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor9flipbooksixEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor9flipbooks8flipbook8SetDelayEj;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor5textsixEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor5texts4text6StringEv;	.scl	2;	.type	32;	.endef
	.def	_ZN3neo6stringaSESt16initializer_listIPKcE;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor5texts4text7SetFontEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor5texts4text10SetOffsetYEi;	.scl	2;	.type	32;	.endef
	.def	realloc;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6assets13UnloadTextureEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6assets10UnloadFontEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors6DeleteEy;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine4keysixENS_3keyE;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor8GetAngleEv;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6timing12GetDeltaTimeEv;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor4GetXEv;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6vector9TerminalXEddd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor4SetXEd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor4GetYEv;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6vector9TerminalYEddd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor4SetYEd;	.scl	2;	.type	32;	.endef
	.def	_ZN4slay6engine6actors5actor8SetAngleEd;	.scl	2;	.type	32;	.endef