
./tests/machinecode/functions_indirect.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
0000000000000084 g     F .text	000000000000005c func_0
00000000000000e0 g     F .text	000000000000005c func_1
000000000000013c g     F .text	0000000000000058 func_2
0000000000000194 g     F .text	000000000000003c func_3
00000000000001d0 g     F .text	00000000000000b0 calculate
000000000000005c g     O .text	0000000000000028 function_table


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 84000000  ........ .......
 0060 00000000 e0000000 00000000 3c010000  ............<...
 0070 01000000 94010000 02000000 ffffffff  ................
 0080 ffffffff fd7bbfa9 fd030091 f353bfa9  .....{.......S..
 0090 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00a0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 00b0 8bfcff54 ff4300d1 e01300b9 e10f00b9  ...T.C..........
 00c0 e81340b9 e90f40b9 0801090b e003082a  ..@...@........*
 00d0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00e0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00f0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0100 140080d2 1408a0f2 7f0214eb abf9ff54  ...............T
 0110 ff4300d1 e01300b9 e10f00b9 e81340b9  .C............@.
 0120 e90f40b9 087d091b e003082a ff430091  ..@..}.....*.C..
 0130 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0140 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0150 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0160 1408a0f2 7f0214eb cbf6ff54 ff4300d1  ...........T.C..
 0170 e01300b9 e81340b9 e91340b9 087d091b  ......@...@..}..
 0180 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0190 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01a0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01b0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01c0 0bf4ff54 f353c1a8 fd7bc1a8 c0035fd6  ...T.S...{...._.
 01d0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 01e0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 01f0 140080d2 1408a0f2 7f0214eb 2bf2ff54  ............+..T
 0200 ff4300d1 e01300b9 e10f00b9 e20b00b9  .C..............
 0210 e80f40b9 e90b40b9 ea1340b9 5f1500f1  ..@...@...@._...
 0220 0af0ff54 0b000090 6b710191 6b796af8  ...T....kq..kyj.
 0230 7f0500b1 a0efff54 6cfd60d3 9f010071  .......Tl.`....q
 0240 81efff54 0a6094d2 ca16a0f2 aa0ac0f2  ...T.`..........
 0250 4a697ff8 eb030b2a 4b010b8b e103092a  Ji.....*K......*
 0260 e003082a 60013fd6 e80300aa e003082a  ...*`.?........*
 0270 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.

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

000000000000005c <function_table>:
  5c:	00000084 00000000 000000e0 00000000     ................
  6c:	0000013c 00000001 00000194 00000002     <...............
  7c:	ffffffff ffffffff                       ........

0000000000000084 <func_0>:
  84:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  88:	910003fd 	mov	x29, sp
  8c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  90:	d2946413 	mov	x19, #0xa320                	// #41760
  94:	f2a016d3 	movk	x19, #0xb6, lsl #16
  98:	f2c00ab3 	movk	x19, #0x55, lsl #32
  9c:	f87f6a73 	ldr	x19, [x19, xzr]
  a0:	cb3363f3 	sub	x19, sp, x19
  a4:	d2800014 	mov	x20, #0x0                   	// #0
  a8:	f2a00814 	movk	x20, #0x40, lsl #16
  ac:	eb14027f 	cmp	x19, x20
  b0:	54fffc8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  b4:	d10043ff 	sub	sp, sp, #0x10
  b8:	b90013e0 	str	w0, [sp, #16]
  bc:	b9000fe1 	str	w1, [sp, #12]
  c0:	b94013e8 	ldr	w8, [sp, #16]
  c4:	b9400fe9 	ldr	w9, [sp, #12]
  c8:	0b090108 	add	w8, w8, w9
  cc:	2a0803e0 	mov	w0, w8
  d0:	910043ff 	add	sp, sp, #0x10
  d4:	a8c153f3 	ldp	x19, x20, [sp], #16
  d8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  dc:	d65f03c0 	ret

00000000000000e0 <func_1>:
  e0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  e4:	910003fd 	mov	x29, sp
  e8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  ec:	d2946413 	mov	x19, #0xa320                	// #41760
  f0:	f2a016d3 	movk	x19, #0xb6, lsl #16
  f4:	f2c00ab3 	movk	x19, #0x55, lsl #32
  f8:	f87f6a73 	ldr	x19, [x19, xzr]
  fc:	cb3363f3 	sub	x19, sp, x19
 100:	d2800014 	mov	x20, #0x0                   	// #0
 104:	f2a00814 	movk	x20, #0x40, lsl #16
 108:	eb14027f 	cmp	x19, x20
 10c:	54fff9ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 110:	d10043ff 	sub	sp, sp, #0x10
 114:	b90013e0 	str	w0, [sp, #16]
 118:	b9000fe1 	str	w1, [sp, #12]
 11c:	b94013e8 	ldr	w8, [sp, #16]
 120:	b9400fe9 	ldr	w9, [sp, #12]
 124:	1b097d08 	mul	w8, w8, w9
 128:	2a0803e0 	mov	w0, w8
 12c:	910043ff 	add	sp, sp, #0x10
 130:	a8c153f3 	ldp	x19, x20, [sp], #16
 134:	a8c17bfd 	ldp	x29, x30, [sp], #16
 138:	d65f03c0 	ret

000000000000013c <func_2>:
 13c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 140:	910003fd 	mov	x29, sp
 144:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 148:	d2946413 	mov	x19, #0xa320                	// #41760
 14c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 150:	f2c00ab3 	movk	x19, #0x55, lsl #32
 154:	f87f6a73 	ldr	x19, [x19, xzr]
 158:	cb3363f3 	sub	x19, sp, x19
 15c:	d2800014 	mov	x20, #0x0                   	// #0
 160:	f2a00814 	movk	x20, #0x40, lsl #16
 164:	eb14027f 	cmp	x19, x20
 168:	54fff6cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 16c:	d10043ff 	sub	sp, sp, #0x10
 170:	b90013e0 	str	w0, [sp, #16]
 174:	b94013e8 	ldr	w8, [sp, #16]
 178:	b94013e9 	ldr	w9, [sp, #16]
 17c:	1b097d08 	mul	w8, w8, w9
 180:	2a0803e0 	mov	w0, w8
 184:	910043ff 	add	sp, sp, #0x10
 188:	a8c153f3 	ldp	x19, x20, [sp], #16
 18c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 190:	d65f03c0 	ret

0000000000000194 <func_3>:
 194:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 198:	910003fd 	mov	x29, sp
 19c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1a0:	d2946413 	mov	x19, #0xa320                	// #41760
 1a4:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1a8:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1ac:	f87f6a73 	ldr	x19, [x19, xzr]
 1b0:	cb3363f3 	sub	x19, sp, x19
 1b4:	d2800014 	mov	x20, #0x0                   	// #0
 1b8:	f2a00814 	movk	x20, #0x40, lsl #16
 1bc:	eb14027f 	cmp	x19, x20
 1c0:	54fff40b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1c4:	a8c153f3 	ldp	x19, x20, [sp], #16
 1c8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1cc:	d65f03c0 	ret

00000000000001d0 <calculate>:
 1d0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1d4:	910003fd 	mov	x29, sp
 1d8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1dc:	d2946413 	mov	x19, #0xa320                	// #41760
 1e0:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1e4:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1e8:	f87f6a73 	ldr	x19, [x19, xzr]
 1ec:	cb3363f3 	sub	x19, sp, x19
 1f0:	d2800014 	mov	x20, #0x0                   	// #0
 1f4:	f2a00814 	movk	x20, #0x40, lsl #16
 1f8:	eb14027f 	cmp	x19, x20
 1fc:	54fff22b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 200:	d10043ff 	sub	sp, sp, #0x10
 204:	b90013e0 	str	w0, [sp, #16]
 208:	b9000fe1 	str	w1, [sp, #12]
 20c:	b9000be2 	str	w2, [sp, #8]
 210:	b9400fe8 	ldr	w8, [sp, #12]
 214:	b9400be9 	ldr	w9, [sp, #8]
 218:	b94013ea 	ldr	w10, [sp, #16]
 21c:	f100155f 	cmp	x10, #0x5
 220:	54fff00a 	b.ge	20 <trap_handler+0x20>  // b.tcont
 224:	9000000b 	adrp	x11, 0 <trap_handler>
 228:	9101716b 	add	x11, x11, #0x5c
 22c:	f86a796b 	ldr	x11, [x11, x10, lsl #3]
 230:	b100057f 	cmn	x11, #0x1
 234:	54ffefa0 	b.eq	28 <trap_handler+0x28>  // b.none
 238:	d360fd6c 	lsr	x12, x11, #32
 23c:	7100019f 	cmp	w12, #0x0
 240:	54ffef81 	b.ne	30 <trap_handler+0x30>  // b.any
 244:	d294600a 	mov	x10, #0xa300                	// #41728
 248:	f2a016ca 	movk	x10, #0xb6, lsl #16
 24c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 250:	f87f694a 	ldr	x10, [x10, xzr]
 254:	2a0b03eb 	mov	w11, w11
 258:	8b0b014b 	add	x11, x10, x11
 25c:	2a0903e1 	mov	w1, w9
 260:	2a0803e0 	mov	w0, w8
 264:	d63f0160 	blr	x11
 268:	aa0003e8 	mov	x8, x0
 26c:	2a0803e0 	mov	w0, w8
 270:	910043ff 	add	sp, sp, #0x10
 274:	a8c153f3 	ldp	x19, x20, [sp], #16
 278:	a8c17bfd 	ldp	x29, x30, [sp], #16
 27c:	d65f03c0 	ret
