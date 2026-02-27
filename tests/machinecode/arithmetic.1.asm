
./tests/machinecode/arithmetic.1.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	000000000000005c add
00000000000000b8 g     F .text	000000000000005c sub
0000000000000114 g     F .text	000000000000005c mul


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 ff4300d1  ...........T.C..
 0090 e00b00f9 e10700f9 e80b40f9 e90740f9  ..........@...@.
 00a0 0801098b e00308aa ff430091 f353c1a8  .........C...S..
 00b0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00c0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00d0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 00e0 7f0214eb ebfaff54 ff4300d1 e00b00f9  .......T.C......
 00f0 e10700f9 e80b40f9 e90740f9 080109cb  ......@...@.....
 0100 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 0110 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0120 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0130 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0140 0bf8ff54 ff4300d1 e00b00f9 e10700f9  ...T.C..........
 0150 e80b40f9 e90740f9 087d099b e00308aa  ..@...@..}......
 0160 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.

Disassembly of section .text:

0000000000000000 <trap_handler>:
   0:	d2801fe0 	mov	x0, #0xff                  	// #255
   4:	14000011 	b	48 <trap_handler+0x48>
   8:	d2800020 	mov	x0, #0x1                   	// #1
   c:	1400000f 	b	48 <trap_handler+0x48>
  10:	d28000a0 	mov	x0, #0x5                   	// #5
  14:	1400000d 	b	48 <trap_handler+0x48>
  18:	d28000c0 	mov	x0, #0x6                   	// #6
  1c:	1400000b 	b	48 <trap_handler+0x48>
  20:	d2800060 	mov	x0, #0x3                   	// #3
  24:	14000009 	b	48 <trap_handler+0x48>
  28:	d2800080 	mov	x0, #0x4                   	// #4
  2c:	14000007 	b	48 <trap_handler+0x48>
  30:	d2800120 	mov	x0, #0x9                   	// #9
  34:	14000005 	b	48 <trap_handler+0x48>
  38:	d2800040 	mov	x0, #0x2                   	// #2
  3c:	14000003 	b	48 <trap_handler+0x48>
  40:	d2800100 	mov	x0, #0x8                   	// #8
  44:	14000001 	b	48 <trap_handler+0x48>
  48:	d2914b09 	mov	x9, #0x8a58                	// #35416
  4c:	f2a00a09 	movk	x9, #0x50, lsl #16
  50:	f2c00aa9 	movk	x9, #0x55, lsl #32
  54:	f2e00009 	movk	x9, #0x0, lsl #48
  58:	d61f0120 	br	x9

000000000000005c <add>:
  5c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  60:	910003fd 	mov	x29, sp
  64:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  68:	d2946413 	mov	x19, #0xa320                	// #41760
  6c:	f2a016d3 	movk	x19, #0xb6, lsl #16
  70:	f2c00ab3 	movk	x19, #0x55, lsl #32
  74:	f87f6a73 	ldr	x19, [x19, xzr]
  78:	cb3363f3 	sub	x19, sp, x19
  7c:	d2800014 	mov	x20, #0x0                   	// #0
  80:	f2a00814 	movk	x20, #0x40, lsl #16
  84:	eb14027f 	cmp	x19, x20
  88:	54fffdcb 	b.lt	40 <trap_handler+0x40>  // b.tstop
  8c:	d10043ff 	sub	sp, sp, #0x10
  90:	f9000be0 	str	x0, [sp, #16]
  94:	f90007e1 	str	x1, [sp, #8]
  98:	f9400be8 	ldr	x8, [sp, #16]
  9c:	f94007e9 	ldr	x9, [sp, #8]
  a0:	8b090108 	add	x8, x8, x9
  a4:	aa0803e0 	mov	x0, x8
  a8:	910043ff 	add	sp, sp, #0x10
  ac:	a8c153f3 	ldp	x19, x20, [sp], #16
  b0:	a8c17bfd 	ldp	x29, x30, [sp], #16
  b4:	d65f03c0 	ret

00000000000000b8 <sub>:
  b8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  bc:	910003fd 	mov	x29, sp
  c0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  c4:	d2946413 	mov	x19, #0xa320                	// #41760
  c8:	f2a016d3 	movk	x19, #0xb6, lsl #16
  cc:	f2c00ab3 	movk	x19, #0x55, lsl #32
  d0:	f87f6a73 	ldr	x19, [x19, xzr]
  d4:	cb3363f3 	sub	x19, sp, x19
  d8:	d2800014 	mov	x20, #0x0                   	// #0
  dc:	f2a00814 	movk	x20, #0x40, lsl #16
  e0:	eb14027f 	cmp	x19, x20
  e4:	54fffaeb 	b.lt	40 <trap_handler+0x40>  // b.tstop
  e8:	d10043ff 	sub	sp, sp, #0x10
  ec:	f9000be0 	str	x0, [sp, #16]
  f0:	f90007e1 	str	x1, [sp, #8]
  f4:	f9400be8 	ldr	x8, [sp, #16]
  f8:	f94007e9 	ldr	x9, [sp, #8]
  fc:	cb090108 	sub	x8, x8, x9
 100:	aa0803e0 	mov	x0, x8
 104:	910043ff 	add	sp, sp, #0x10
 108:	a8c153f3 	ldp	x19, x20, [sp], #16
 10c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 110:	d65f03c0 	ret

0000000000000114 <mul>:
 114:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 118:	910003fd 	mov	x29, sp
 11c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 120:	d2946413 	mov	x19, #0xa320                	// #41760
 124:	f2a016d3 	movk	x19, #0xb6, lsl #16
 128:	f2c00ab3 	movk	x19, #0x55, lsl #32
 12c:	f87f6a73 	ldr	x19, [x19, xzr]
 130:	cb3363f3 	sub	x19, sp, x19
 134:	d2800014 	mov	x20, #0x0                   	// #0
 138:	f2a00814 	movk	x20, #0x40, lsl #16
 13c:	eb14027f 	cmp	x19, x20
 140:	54fff80b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 144:	d10043ff 	sub	sp, sp, #0x10
 148:	f9000be0 	str	x0, [sp, #16]
 14c:	f90007e1 	str	x1, [sp, #8]
 150:	f9400be8 	ldr	x8, [sp, #16]
 154:	f94007e9 	ldr	x9, [sp, #8]
 158:	9b097d08 	mul	x8, x8, x9
 15c:	aa0803e0 	mov	x0, x8
 160:	910043ff 	add	sp, sp, #0x10
 164:	a8c153f3 	ldp	x19, x20, [sp], #16
 168:	a8c17bfd 	ldp	x29, x30, [sp], #16
 16c:	d65f03c0 	ret
