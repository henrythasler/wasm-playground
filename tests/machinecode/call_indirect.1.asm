
./tests/machinecode/call_indirect.1.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000006c g     F .text	0000000000000044 func_0
00000000000000b0 g     F .text	0000000000000044 func_1
00000000000000f4 g     F .text	0000000000000098 callt
000000000000005c g     O .text	0000000000000010 function_table


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 6c000000  ........ ...l...
 0060 00000000 b0000000 00000000 fd7bbfa9  .............{..
 0070 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0080 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0090 1408a0f2 7f0214eb 4bfdff54 28008052  ........K..T(..R
 00a0 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 00b0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00c0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 00d0 140080d2 1408a0f2 7f0214eb 2bfbff54  ............+..T
 00e0 48008052 e003082a f353c1a8 fd7bc1a8  H..R...*.S...{..
 00f0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0100 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0110 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0120 0bf9ff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 0130 1f0900f1 6af7ff54 09000090 29710191  ....j..T....)q..
 0140 297968f8 3f0500b1 00f7ff54 2afd60d3  )yh.?......T*.`.
 0150 5f010071 e1f6ff54 086094d2 c816a0f2  _..q...T.`......
 0160 a80ac0f2 08697ff8 e903092a 0901098b  .....i.....*....
 0170 20013fd6 e80300aa e003082a ff430091   .?........*.C..
 0180 f353c1a8 fd7bc1a8 c0035fd6           .S...{...._.    

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
  5c:	0000006c 00000000 000000b0 00000000     l...............

000000000000006c <func_0>:
  6c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  70:	910003fd 	mov	x29, sp
  74:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  78:	d2946413 	mov	x19, #0xa320                	// #41760
  7c:	f2a016d3 	movk	x19, #0xb6, lsl #16
  80:	f2c00ab3 	movk	x19, #0x55, lsl #32
  84:	f87f6a73 	ldr	x19, [x19, xzr]
  88:	cb3363f3 	sub	x19, sp, x19
  8c:	d2800014 	mov	x20, #0x0                   	// #0
  90:	f2a00814 	movk	x20, #0x40, lsl #16
  94:	eb14027f 	cmp	x19, x20
  98:	54fffd4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  9c:	52800028 	mov	w8, #0x1                   	// #1
  a0:	2a0803e0 	mov	w0, w8
  a4:	a8c153f3 	ldp	x19, x20, [sp], #16
  a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  ac:	d65f03c0 	ret

00000000000000b0 <func_1>:
  b0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  b4:	910003fd 	mov	x29, sp
  b8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  bc:	d2946413 	mov	x19, #0xa320                	// #41760
  c0:	f2a016d3 	movk	x19, #0xb6, lsl #16
  c4:	f2c00ab3 	movk	x19, #0x55, lsl #32
  c8:	f87f6a73 	ldr	x19, [x19, xzr]
  cc:	cb3363f3 	sub	x19, sp, x19
  d0:	d2800014 	mov	x20, #0x0                   	// #0
  d4:	f2a00814 	movk	x20, #0x40, lsl #16
  d8:	eb14027f 	cmp	x19, x20
  dc:	54fffb2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  e0:	52800048 	mov	w8, #0x2                   	// #2
  e4:	2a0803e0 	mov	w0, w8
  e8:	a8c153f3 	ldp	x19, x20, [sp], #16
  ec:	a8c17bfd 	ldp	x29, x30, [sp], #16
  f0:	d65f03c0 	ret

00000000000000f4 <callt>:
  f4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  f8:	910003fd 	mov	x29, sp
  fc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 100:	d2946413 	mov	x19, #0xa320                	// #41760
 104:	f2a016d3 	movk	x19, #0xb6, lsl #16
 108:	f2c00ab3 	movk	x19, #0x55, lsl #32
 10c:	f87f6a73 	ldr	x19, [x19, xzr]
 110:	cb3363f3 	sub	x19, sp, x19
 114:	d2800014 	mov	x20, #0x0                   	// #0
 118:	f2a00814 	movk	x20, #0x40, lsl #16
 11c:	eb14027f 	cmp	x19, x20
 120:	54fff90b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 124:	d10043ff 	sub	sp, sp, #0x10
 128:	b90013e0 	str	w0, [sp, #16]
 12c:	b94013e8 	ldr	w8, [sp, #16]
 130:	f100091f 	cmp	x8, #0x2
 134:	54fff76a 	b.ge	20 <trap_handler+0x20>  // b.tcont
 138:	90000009 	adrp	x9, 0 <trap_handler>
 13c:	91017129 	add	x9, x9, #0x5c
 140:	f8687929 	ldr	x9, [x9, x8, lsl #3]
 144:	b100053f 	cmn	x9, #0x1
 148:	54fff700 	b.eq	28 <trap_handler+0x28>  // b.none
 14c:	d360fd2a 	lsr	x10, x9, #32
 150:	7100015f 	cmp	w10, #0x0
 154:	54fff6e1 	b.ne	30 <trap_handler+0x30>  // b.any
 158:	d2946008 	mov	x8, #0xa300                	// #41728
 15c:	f2a016c8 	movk	x8, #0xb6, lsl #16
 160:	f2c00aa8 	movk	x8, #0x55, lsl #32
 164:	f87f6908 	ldr	x8, [x8, xzr]
 168:	2a0903e9 	mov	w9, w9
 16c:	8b090109 	add	x9, x8, x9
 170:	d63f0120 	blr	x9
 174:	aa0003e8 	mov	x8, x0
 178:	2a0803e0 	mov	w0, w8
 17c:	910043ff 	add	sp, sp, #0x10
 180:	a8c153f3 	ldp	x19, x20, [sp], #16
 184:	a8c17bfd 	ldp	x29, x30, [sp], #16
 188:	d65f03c0 	ret
