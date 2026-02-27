
./tests/machinecode/call_indirect.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
0000000000000094 g     F .text	0000000000000044 func_0
00000000000000d8 g     F .text	0000000000000044 func_1
000000000000011c g     F .text	0000000000000044 func_2
0000000000000160 g     F .text	0000000000000044 func_3
00000000000001a4 g     F .text	0000000000000044 func_4
00000000000001e8 g     F .text	0000000000000098 callt
0000000000000280 g     F .text	0000000000000098 callu
000000000000005c g     O .text	0000000000000038 function_table


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 94000000  ........ .......
 0060 00000000 d8000000 00000000 1c010000  ................
 0070 00000000 60010000 01000000 a4010000  ....`...........
 0080 01000000 94000000 00000000 1c010000  ................
 0090 00000000 fd7bbfa9 fd030091 f353bfa9  .....{.......S..
 00a0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00b0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 00c0 0bfcff54 28008052 e003082a f353c1a8  ...T(..R...*.S..
 00d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0100 7f0214eb ebf9ff54 48008052 e003082a  .......TH..R...*
 0110 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0120 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0130 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0140 1408a0f2 7f0214eb cbf7ff54 68008052  ...........Th..R
 0150 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0160 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0170 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0180 140080d2 1408a0f2 7f0214eb abf5ff54  ...............T
 0190 88008052 e003082a f353c1a8 fd7bc1a8  ...R...*.S...{..
 01a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01d0 8bf3ff54 a8008052 e003082a f353c1a8  ...T...R...*.S..
 01e0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 01f0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0200 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0210 7f0214eb 6bf1ff54 ff4300d1 e01300b9  ....k..T.C......
 0220 e81340b9 1f1d00f1 caefff54 09000090  ..@........T....
 0230 29710191 297968f8 3f0500b1 60efff54  )q..)yh.?...`..T
 0240 2afd60d3 5f010071 41efff54 086094d2  *.`._..qA..T.`..
 0250 c816a0f2 a80ac0f2 08697ff8 e903092a  .........i.....*
 0260 0901098b 20013fd6 e80300aa e003082a  .... .?........*
 0270 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0280 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0290 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 02a0 140080d2 1408a0f2 7f0214eb abecff54  ...............T
 02b0 ff4300d1 e01300b9 e81340b9 1f1d00f1  .C........@.....
 02c0 0aebff54 09000090 29710191 297968f8  ...T....)q..)yh.
 02d0 3f0500b1 a0eaff54 2afd60d3 5f050071  ?......T*.`._..q
 02e0 81eaff54 086094d2 c816a0f2 a80ac0f2  ...T.`..........
 02f0 08697ff8 e903092a 0901098b 20013fd6  .i.....*.... .?.
 0300 e80300aa e003082a ff430091 f353c1a8  .......*.C...S..
 0310 fd7bc1a8 c0035fd6                    .{...._.        

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
  5c:	00000094 00000000 000000d8 00000000     ................
  6c:	0000011c 00000000 00000160 00000001     ........`.......
  7c:	000001a4 00000001 00000094 00000000     ................
  8c:	0000011c 00000000                       ........

0000000000000094 <func_0>:
  94:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  98:	910003fd 	mov	x29, sp
  9c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  a0:	d2946413 	mov	x19, #0xa320                	// #41760
  a4:	f2a016d3 	movk	x19, #0xb6, lsl #16
  a8:	f2c00ab3 	movk	x19, #0x55, lsl #32
  ac:	f87f6a73 	ldr	x19, [x19, xzr]
  b0:	cb3363f3 	sub	x19, sp, x19
  b4:	d2800014 	mov	x20, #0x0                   	// #0
  b8:	f2a00814 	movk	x20, #0x40, lsl #16
  bc:	eb14027f 	cmp	x19, x20
  c0:	54fffc0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  c4:	52800028 	mov	w8, #0x1                   	// #1
  c8:	2a0803e0 	mov	w0, w8
  cc:	a8c153f3 	ldp	x19, x20, [sp], #16
  d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
  d4:	d65f03c0 	ret

00000000000000d8 <func_1>:
  d8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  dc:	910003fd 	mov	x29, sp
  e0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  e4:	d2946413 	mov	x19, #0xa320                	// #41760
  e8:	f2a016d3 	movk	x19, #0xb6, lsl #16
  ec:	f2c00ab3 	movk	x19, #0x55, lsl #32
  f0:	f87f6a73 	ldr	x19, [x19, xzr]
  f4:	cb3363f3 	sub	x19, sp, x19
  f8:	d2800014 	mov	x20, #0x0                   	// #0
  fc:	f2a00814 	movk	x20, #0x40, lsl #16
 100:	eb14027f 	cmp	x19, x20
 104:	54fff9eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 108:	52800048 	mov	w8, #0x2                   	// #2
 10c:	2a0803e0 	mov	w0, w8
 110:	a8c153f3 	ldp	x19, x20, [sp], #16
 114:	a8c17bfd 	ldp	x29, x30, [sp], #16
 118:	d65f03c0 	ret

000000000000011c <func_2>:
 11c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 120:	910003fd 	mov	x29, sp
 124:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 128:	d2946413 	mov	x19, #0xa320                	// #41760
 12c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 130:	f2c00ab3 	movk	x19, #0x55, lsl #32
 134:	f87f6a73 	ldr	x19, [x19, xzr]
 138:	cb3363f3 	sub	x19, sp, x19
 13c:	d2800014 	mov	x20, #0x0                   	// #0
 140:	f2a00814 	movk	x20, #0x40, lsl #16
 144:	eb14027f 	cmp	x19, x20
 148:	54fff7cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 14c:	52800068 	mov	w8, #0x3                   	// #3
 150:	2a0803e0 	mov	w0, w8
 154:	a8c153f3 	ldp	x19, x20, [sp], #16
 158:	a8c17bfd 	ldp	x29, x30, [sp], #16
 15c:	d65f03c0 	ret

0000000000000160 <func_3>:
 160:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 164:	910003fd 	mov	x29, sp
 168:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 16c:	d2946413 	mov	x19, #0xa320                	// #41760
 170:	f2a016d3 	movk	x19, #0xb6, lsl #16
 174:	f2c00ab3 	movk	x19, #0x55, lsl #32
 178:	f87f6a73 	ldr	x19, [x19, xzr]
 17c:	cb3363f3 	sub	x19, sp, x19
 180:	d2800014 	mov	x20, #0x0                   	// #0
 184:	f2a00814 	movk	x20, #0x40, lsl #16
 188:	eb14027f 	cmp	x19, x20
 18c:	54fff5ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 190:	52800088 	mov	w8, #0x4                   	// #4
 194:	2a0803e0 	mov	w0, w8
 198:	a8c153f3 	ldp	x19, x20, [sp], #16
 19c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a0:	d65f03c0 	ret

00000000000001a4 <func_4>:
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
 1d4:	528000a8 	mov	w8, #0x5                   	// #5
 1d8:	2a0803e0 	mov	w0, w8
 1dc:	a8c153f3 	ldp	x19, x20, [sp], #16
 1e0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1e4:	d65f03c0 	ret

00000000000001e8 <callt>:
 1e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1ec:	910003fd 	mov	x29, sp
 1f0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1f4:	d2946413 	mov	x19, #0xa320                	// #41760
 1f8:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1fc:	f2c00ab3 	movk	x19, #0x55, lsl #32
 200:	f87f6a73 	ldr	x19, [x19, xzr]
 204:	cb3363f3 	sub	x19, sp, x19
 208:	d2800014 	mov	x20, #0x0                   	// #0
 20c:	f2a00814 	movk	x20, #0x40, lsl #16
 210:	eb14027f 	cmp	x19, x20
 214:	54fff16b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 218:	d10043ff 	sub	sp, sp, #0x10
 21c:	b90013e0 	str	w0, [sp, #16]
 220:	b94013e8 	ldr	w8, [sp, #16]
 224:	f1001d1f 	cmp	x8, #0x7
 228:	54ffefca 	b.ge	20 <trap_handler+0x20>  // b.tcont
 22c:	90000009 	adrp	x9, 0 <trap_handler>
 230:	91017129 	add	x9, x9, #0x5c
 234:	f8687929 	ldr	x9, [x9, x8, lsl #3]
 238:	b100053f 	cmn	x9, #0x1
 23c:	54ffef60 	b.eq	28 <trap_handler+0x28>  // b.none
 240:	d360fd2a 	lsr	x10, x9, #32
 244:	7100015f 	cmp	w10, #0x0
 248:	54ffef41 	b.ne	30 <trap_handler+0x30>  // b.any
 24c:	d2946008 	mov	x8, #0xa300                	// #41728
 250:	f2a016c8 	movk	x8, #0xb6, lsl #16
 254:	f2c00aa8 	movk	x8, #0x55, lsl #32
 258:	f87f6908 	ldr	x8, [x8, xzr]
 25c:	2a0903e9 	mov	w9, w9
 260:	8b090109 	add	x9, x8, x9
 264:	d63f0120 	blr	x9
 268:	aa0003e8 	mov	x8, x0
 26c:	2a0803e0 	mov	w0, w8
 270:	910043ff 	add	sp, sp, #0x10
 274:	a8c153f3 	ldp	x19, x20, [sp], #16
 278:	a8c17bfd 	ldp	x29, x30, [sp], #16
 27c:	d65f03c0 	ret

0000000000000280 <callu>:
 280:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 284:	910003fd 	mov	x29, sp
 288:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 28c:	d2946413 	mov	x19, #0xa320                	// #41760
 290:	f2a016d3 	movk	x19, #0xb6, lsl #16
 294:	f2c00ab3 	movk	x19, #0x55, lsl #32
 298:	f87f6a73 	ldr	x19, [x19, xzr]
 29c:	cb3363f3 	sub	x19, sp, x19
 2a0:	d2800014 	mov	x20, #0x0                   	// #0
 2a4:	f2a00814 	movk	x20, #0x40, lsl #16
 2a8:	eb14027f 	cmp	x19, x20
 2ac:	54ffecab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 2b0:	d10043ff 	sub	sp, sp, #0x10
 2b4:	b90013e0 	str	w0, [sp, #16]
 2b8:	b94013e8 	ldr	w8, [sp, #16]
 2bc:	f1001d1f 	cmp	x8, #0x7
 2c0:	54ffeb0a 	b.ge	20 <trap_handler+0x20>  // b.tcont
 2c4:	90000009 	adrp	x9, 0 <trap_handler>
 2c8:	91017129 	add	x9, x9, #0x5c
 2cc:	f8687929 	ldr	x9, [x9, x8, lsl #3]
 2d0:	b100053f 	cmn	x9, #0x1
 2d4:	54ffeaa0 	b.eq	28 <trap_handler+0x28>  // b.none
 2d8:	d360fd2a 	lsr	x10, x9, #32
 2dc:	7100055f 	cmp	w10, #0x1
 2e0:	54ffea81 	b.ne	30 <trap_handler+0x30>  // b.any
 2e4:	d2946008 	mov	x8, #0xa300                	// #41728
 2e8:	f2a016c8 	movk	x8, #0xb6, lsl #16
 2ec:	f2c00aa8 	movk	x8, #0x55, lsl #32
 2f0:	f87f6908 	ldr	x8, [x8, xzr]
 2f4:	2a0903e9 	mov	w9, w9
 2f8:	8b090109 	add	x9, x8, x9
 2fc:	d63f0120 	blr	x9
 300:	aa0003e8 	mov	x8, x0
 304:	2a0803e0 	mov	w0, w8
 308:	910043ff 	add	sp, sp, #0x10
 30c:	a8c153f3 	ldp	x19, x20, [sp], #16
 310:	a8c17bfd 	ldp	x29, x30, [sp], #16
 314:	d65f03c0 	ret
