
./tests/machinecode/bit.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000058 ctz-i32
00000000000000b4 g     F .text	0000000000000058 ctz-i64
000000000000010c g     F .text	000000000000005c bitand32
0000000000000168 g     F .text	000000000000005c bitand64


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
 0090 e01300b9 e81340b9 0801c05a 0811c05a  ......@....Z...Z
 00a0 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 00b0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 00c0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00d0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 00e0 0bfbff54 ff4300d1 e00b00f9 e80b40f9  ...T.C........@.
 00f0 0801c0da 0811c0da e00308aa ff430091  .............C..
 0100 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0110 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0120 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0130 1408a0f2 7f0214eb 4bf8ff54 ff4300d1  ........K..T.C..
 0140 e01300b9 e10f00b9 e81340b9 e90f40b9  ..........@...@.
 0150 0801090a e003082a ff430091 f353c1a8  .......*.C...S..
 0160 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0170 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0180 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0190 7f0214eb 6bf5ff54 ff4300d1 e00b00f9  ....k..T.C......
 01a0 e10700f9 e80b40f9 e90740f9 0801098a  ......@...@.....
 01b0 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 01c0 c0035fd6                             .._.            

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

000000000000005c <ctz-i32>:
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
  94:	b94013e8 	ldr	w8, [sp, #16]
  98:	5ac00108 	rbit	w8, w8
  9c:	5ac01108 	clz	w8, w8
  a0:	2a0803e0 	mov	w0, w8
  a4:	910043ff 	add	sp, sp, #0x10
  a8:	a8c153f3 	ldp	x19, x20, [sp], #16
  ac:	a8c17bfd 	ldp	x29, x30, [sp], #16
  b0:	d65f03c0 	ret

00000000000000b4 <ctz-i64>:
  b4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  b8:	910003fd 	mov	x29, sp
  bc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  c0:	d2946413 	mov	x19, #0xa320                	// #41760
  c4:	f2a016d3 	movk	x19, #0xb6, lsl #16
  c8:	f2c00ab3 	movk	x19, #0x55, lsl #32
  cc:	f87f6a73 	ldr	x19, [x19, xzr]
  d0:	cb3363f3 	sub	x19, sp, x19
  d4:	d2800014 	mov	x20, #0x0                   	// #0
  d8:	f2a00814 	movk	x20, #0x40, lsl #16
  dc:	eb14027f 	cmp	x19, x20
  e0:	54fffb0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  e4:	d10043ff 	sub	sp, sp, #0x10
  e8:	f9000be0 	str	x0, [sp, #16]
  ec:	f9400be8 	ldr	x8, [sp, #16]
  f0:	dac00108 	rbit	x8, x8
  f4:	dac01108 	clz	x8, x8
  f8:	aa0803e0 	mov	x0, x8
  fc:	910043ff 	add	sp, sp, #0x10
 100:	a8c153f3 	ldp	x19, x20, [sp], #16
 104:	a8c17bfd 	ldp	x29, x30, [sp], #16
 108:	d65f03c0 	ret

000000000000010c <bitand32>:
 10c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 110:	910003fd 	mov	x29, sp
 114:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 118:	d2946413 	mov	x19, #0xa320                	// #41760
 11c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 120:	f2c00ab3 	movk	x19, #0x55, lsl #32
 124:	f87f6a73 	ldr	x19, [x19, xzr]
 128:	cb3363f3 	sub	x19, sp, x19
 12c:	d2800014 	mov	x20, #0x0                   	// #0
 130:	f2a00814 	movk	x20, #0x40, lsl #16
 134:	eb14027f 	cmp	x19, x20
 138:	54fff84b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 13c:	d10043ff 	sub	sp, sp, #0x10
 140:	b90013e0 	str	w0, [sp, #16]
 144:	b9000fe1 	str	w1, [sp, #12]
 148:	b94013e8 	ldr	w8, [sp, #16]
 14c:	b9400fe9 	ldr	w9, [sp, #12]
 150:	0a090108 	and	w8, w8, w9
 154:	2a0803e0 	mov	w0, w8
 158:	910043ff 	add	sp, sp, #0x10
 15c:	a8c153f3 	ldp	x19, x20, [sp], #16
 160:	a8c17bfd 	ldp	x29, x30, [sp], #16
 164:	d65f03c0 	ret

0000000000000168 <bitand64>:
 168:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 16c:	910003fd 	mov	x29, sp
 170:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 174:	d2946413 	mov	x19, #0xa320                	// #41760
 178:	f2a016d3 	movk	x19, #0xb6, lsl #16
 17c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 180:	f87f6a73 	ldr	x19, [x19, xzr]
 184:	cb3363f3 	sub	x19, sp, x19
 188:	d2800014 	mov	x20, #0x0                   	// #0
 18c:	f2a00814 	movk	x20, #0x40, lsl #16
 190:	eb14027f 	cmp	x19, x20
 194:	54fff56b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 198:	d10043ff 	sub	sp, sp, #0x10
 19c:	f9000be0 	str	x0, [sp, #16]
 1a0:	f90007e1 	str	x1, [sp, #8]
 1a4:	f9400be8 	ldr	x8, [sp, #16]
 1a8:	f94007e9 	ldr	x9, [sp, #8]
 1ac:	8a090108 	and	x8, x8, x9
 1b0:	aa0803e0 	mov	x0, x8
 1b4:	910043ff 	add	sp, sp, #0x10
 1b8:	a8c153f3 	ldp	x19, x20, [sp], #16
 1bc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1c0:	d65f03c0 	ret
