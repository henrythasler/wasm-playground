
./tests/machinecode/division.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000074 div_s32
00000000000000d0 g     F .text	0000000000000060 div_u32
0000000000000130 g     F .text	0000000000000074 div_s64
00000000000001a4 g     F .text	0000000000000060 div_u64


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
 0090 e01300b9 e10f00b9 e81340b9 e90f40b9  ..........@...@.
 00a0 89fbff34 3f050031 81000054 0a00b052  ...4?..1...T...R
 00b0 1f010a6b 20fbff54 080dc91a e003082a  ...k ..T.......*
 00c0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00d0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00e0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 00f0 140080d2 1408a0f2 7f0214eb 2bfaff54  ............+..T
 0100 ff4300d1 e01300b9 e10f00b9 e81340b9  .C............@.
 0110 e90f40b9 e9f7ffb4 0809c99a e003082a  ..@............*
 0120 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0130 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0140 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0150 140080d2 1408a0f2 7f0214eb 2bf7ff54  ............+..T
 0160 ff4300d1 e00b00f9 e10700f9 e80b40f9  .C............@.
 0170 e90740f9 e9f4ffb4 3f0500b1 81000054  ..@.....?......T
 0180 0a00f0d2 1f010aeb 80f4ff54 080dc99a  ...........T....
 0190 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 01a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01d0 8bf3ff54 ff4300d1 e00b00f9 e10700f9  ...T.C..........
 01e0 e80b40f9 e90740f9 49f1ffb4 0809c99a  ..@...@.I.......
 01f0 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 0200 c0035fd6                             .._.            

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

000000000000005c <div_s32>:
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
  90:	b90013e0 	str	w0, [sp, #16]
  94:	b9000fe1 	str	w1, [sp, #12]
  98:	b94013e8 	ldr	w8, [sp, #16]
  9c:	b9400fe9 	ldr	w9, [sp, #12]
  a0:	34fffb89 	cbz	w9, 10 <trap_handler+0x10>
  a4:	3100053f 	cmn	w9, #0x1
  a8:	54000081 	b.ne	b8 <div_s32+0x5c>  // b.any
  ac:	52b0000a 	mov	w10, #0x80000000            	// #-2147483648
  b0:	6b0a011f 	cmp	w8, w10
  b4:	54fffb20 	b.eq	18 <trap_handler+0x18>  // b.none
  b8:	1ac90d08 	sdiv	w8, w8, w9
  bc:	2a0803e0 	mov	w0, w8
  c0:	910043ff 	add	sp, sp, #0x10
  c4:	a8c153f3 	ldp	x19, x20, [sp], #16
  c8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  cc:	d65f03c0 	ret

00000000000000d0 <div_u32>:
  d0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  d4:	910003fd 	mov	x29, sp
  d8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  dc:	d2946413 	mov	x19, #0xa320                	// #41760
  e0:	f2a016d3 	movk	x19, #0xb6, lsl #16
  e4:	f2c00ab3 	movk	x19, #0x55, lsl #32
  e8:	f87f6a73 	ldr	x19, [x19, xzr]
  ec:	cb3363f3 	sub	x19, sp, x19
  f0:	d2800014 	mov	x20, #0x0                   	// #0
  f4:	f2a00814 	movk	x20, #0x40, lsl #16
  f8:	eb14027f 	cmp	x19, x20
  fc:	54fffa2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 100:	d10043ff 	sub	sp, sp, #0x10
 104:	b90013e0 	str	w0, [sp, #16]
 108:	b9000fe1 	str	w1, [sp, #12]
 10c:	b94013e8 	ldr	w8, [sp, #16]
 110:	b9400fe9 	ldr	w9, [sp, #12]
 114:	b4fff7e9 	cbz	x9, 10 <trap_handler+0x10>
 118:	9ac90908 	udiv	x8, x8, x9
 11c:	2a0803e0 	mov	w0, w8
 120:	910043ff 	add	sp, sp, #0x10
 124:	a8c153f3 	ldp	x19, x20, [sp], #16
 128:	a8c17bfd 	ldp	x29, x30, [sp], #16
 12c:	d65f03c0 	ret

0000000000000130 <div_s64>:
 130:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 134:	910003fd 	mov	x29, sp
 138:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 13c:	d2946413 	mov	x19, #0xa320                	// #41760
 140:	f2a016d3 	movk	x19, #0xb6, lsl #16
 144:	f2c00ab3 	movk	x19, #0x55, lsl #32
 148:	f87f6a73 	ldr	x19, [x19, xzr]
 14c:	cb3363f3 	sub	x19, sp, x19
 150:	d2800014 	mov	x20, #0x0                   	// #0
 154:	f2a00814 	movk	x20, #0x40, lsl #16
 158:	eb14027f 	cmp	x19, x20
 15c:	54fff72b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 160:	d10043ff 	sub	sp, sp, #0x10
 164:	f9000be0 	str	x0, [sp, #16]
 168:	f90007e1 	str	x1, [sp, #8]
 16c:	f9400be8 	ldr	x8, [sp, #16]
 170:	f94007e9 	ldr	x9, [sp, #8]
 174:	b4fff4e9 	cbz	x9, 10 <trap_handler+0x10>
 178:	b100053f 	cmn	x9, #0x1
 17c:	54000081 	b.ne	18c <div_s64+0x5c>  // b.any
 180:	d2f0000a 	mov	x10, #0x8000000000000000    	// #-9223372036854775808
 184:	eb0a011f 	cmp	x8, x10
 188:	54fff480 	b.eq	18 <trap_handler+0x18>  // b.none
 18c:	9ac90d08 	sdiv	x8, x8, x9
 190:	aa0803e0 	mov	x0, x8
 194:	910043ff 	add	sp, sp, #0x10
 198:	a8c153f3 	ldp	x19, x20, [sp], #16
 19c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a0:	d65f03c0 	ret

00000000000001a4 <div_u64>:
 1a4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1a8:	910003fd 	mov	x29, sp
 1ac:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1b0:	d2946413 	mov	x19, #0xa320                	// #41760
 1b4:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1b8:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1bc:	f87f6a73 	ldr	x19, [x19, xzr]
 1c0:	cb3363f3 	sub	x19, sp, x19
 1c4:	d2800014 	mov	x20, #0x0                   	// #0
 1c8:	f2a00814 	movk	x20, #0x40, lsl #16
 1cc:	eb14027f 	cmp	x19, x20
 1d0:	54fff38b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1d4:	d10043ff 	sub	sp, sp, #0x10
 1d8:	f9000be0 	str	x0, [sp, #16]
 1dc:	f90007e1 	str	x1, [sp, #8]
 1e0:	f9400be8 	ldr	x8, [sp, #16]
 1e4:	f94007e9 	ldr	x9, [sp, #8]
 1e8:	b4fff149 	cbz	x9, 10 <trap_handler+0x10>
 1ec:	9ac90908 	udiv	x8, x8, x9
 1f0:	aa0803e0 	mov	x0, x8
 1f4:	910043ff 	add	sp, sp, #0x10
 1f8:	a8c153f3 	ldp	x19, x20, [sp], #16
 1fc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 200:	d65f03c0 	ret
