	.file	"stack1.c"
	.intel_syntax noprefix
# GNU C11 (Ubuntu 7.4.0-1ubuntu1~18.04.1) version 7.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.4.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu stack1.c -masm=intel
# -mtune=generic -march=x86-64 -auxbase-strip stack.s -fverbose-asm
# -fstack-protector-strong -Wformat -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-protector-strong
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
# -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
# -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
# -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC0:
	.string	"number=%d\n"
.LC1:
	.string	"hello %s"
.LC2:
	.string	"buffer=%s\n"
.LC3:
	.string	"buffer addr: %p\n"
.LC4:
	.string	"number addr: %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	sub	rsp, 64	#,
	mov	DWORD PTR -52[rbp], edi	# argc, argc
	mov	QWORD PTR -64[rbp], rsi	# argv, argv
# stack1.c:4: {
	mov	rax, QWORD PTR fs:40	# tmp99,
	mov	QWORD PTR -8[rbp], rax	# D.2260, tmp99
	xor	eax, eax	# tmp99
# stack1.c:5: 	volatile int number = 0;
	mov	DWORD PTR -36[rbp], 0	# number,
# stack1.c:8: 	if (argc != 2) return 0;
	cmp	DWORD PTR -52[rbp], 2	# argc,
	je	.L2	#,
# stack1.c:8: 	if (argc != 2) return 0;
	mov	eax, 0	# _5,
	jmp	.L4	#
.L2:
# stack1.c:10: 	printf("number=%d\n", number);
	mov	eax, DWORD PTR -36[rbp]	# number.0_1, number
	mov	esi, eax	#, number.0_1
	lea	rdi, .LC0[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# stack1.c:11: 	sprintf(buffer, "hello %s", argv[1]);
	mov	rax, QWORD PTR -64[rbp]	# tmp93, argv
	add	rax, 8	# _2,
	mov	rdx, QWORD PTR [rax]	# _3, *_2
	lea	rax, -32[rbp]	# tmp94,
	lea	rsi, .LC1[rip]	#,
	mov	rdi, rax	#, tmp94
	mov	eax, 0	#,
	call	sprintf@PLT	#
# stack1.c:12: 	printf("buffer=%s\n", buffer);
	lea	rax, -32[rbp]	# tmp95,
	mov	rsi, rax	#, tmp95
	lea	rdi, .LC2[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# stack1.c:13: 	printf("number=%d\n", number);
	mov	eax, DWORD PTR -36[rbp]	# number.1_4, number
	mov	esi, eax	#, number.1_4
	lea	rdi, .LC0[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# stack1.c:15: 	printf("buffer addr: %p\n", buffer);
	lea	rax, -32[rbp]	# tmp96,
	mov	rsi, rax	#, tmp96
	lea	rdi, .LC3[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# stack1.c:16: 	printf("number addr: %p\n", &number);
	lea	rax, -36[rbp]	# tmp97,
	mov	rsi, rax	#, tmp97
	lea	rdi, .LC4[rip]	#,
	mov	eax, 0	#,
	call	printf@PLT	#
# stack1.c:17: 	return 0;
	mov	eax, 0	# _5,
.L4:
# stack1.c:18: }
	mov	rcx, QWORD PTR -8[rbp]	# tmp100, D.2260
	xor	rcx, QWORD PTR fs:40	# tmp100,
	je	.L5	#,
# stack1.c:18: }
	call	__stack_chk_fail@PLT	#
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
