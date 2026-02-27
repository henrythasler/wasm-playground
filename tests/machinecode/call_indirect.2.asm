
./tests/machinecode/call_indirect.2.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000006c g     F .text	0000000000000058 func_0
00000000000000c4 g     F .text	0000000000000048 func_1
000000000000010c g     F .text	00000000000000a4 call_indirect
000000000000005c g     O .text	0000000000000010 function_table


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 6c000000  ........ ...l...
 0060 00000000 c4000000 01000000 fd7bbfa9  .............{..
 0070 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0080 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0090 1408a0f2 7f0214eb 4bfdff54 ff4300d1  ........K..T.C..
 00a0 e01300b9 e81340b9 29008052 0801090b  ......@.)..R....
 00b0 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 00c0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 00d0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00e0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 00f0 8bfaff54 ff4300d1 e01300b9 ff430091  ...T.C.......C..
 0100 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0110 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0120 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0130 1408a0f2 7f0214eb 4bf8ff54 ff4300d1  ........K..T.C..
 0140 e01300b9 e10f00b9 e80f40b9 e91340b9  ..........@...@.
 0150 3f0900f1 6af6ff54 0a000090 4a710191  ?...j..T....Jq..
 0160 4a7969f8 5f0500b1 00f6ff54 4bfd60d3  Jyi._......TK.`.
 0170 7f010071 e1f5ff54 096094d2 c916a0f2  ...q...T.`......
 0180 a90ac0f2 29697ff8 ea030a2a 2a010a8b  ....)i.....**...
 0190 e003082a 40013fd6 e80300aa e003082a  ...*@.?........*
 01a0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.

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
  5c:	0000006c 00000000 000000c4 00000001     l...............

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
  9c:	d10043ff 	sub	sp, sp, #0x10
  a0:	b90013e0 	str	w0, [sp, #16]
  a4:	b94013e8 	ldr	w8, [sp, #16]
  a8:	52800029 	mov	w9, #0x1                   	// #1
  ac:	0b090108 	add	w8, w8, w9
  b0:	2a0803e0 	mov	w0, w8
  b4:	910043ff 	add	sp, sp, #0x10
  b8:	a8c153f3 	ldp	x19, x20, [sp], #16
  bc:	a8c17bfd 	ldp	x29, x30, [sp], #16
  c0:	d65f03c0 	ret

00000000000000c4 <func_1>:
  c4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  c8:	910003fd 	mov	x29, sp
  cc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  d0:	d2946413 	mov	x19, #0xa320                	// #41760
  d4:	f2a016d3 	movk	x19, #0xb6, lsl #16
  d8:	f2c00ab3 	movk	x19, #0x55, lsl #32
  dc:	f87f6a73 	ldr	x19, [x19, xzr]
  e0:	cb3363f3 	sub	x19, sp, x19
  e4:	d2800014 	mov	x20, #0x0                   	// #0
  e8:	f2a00814 	movk	x20, #0x40, lsl #16
  ec:	eb14027f 	cmp	x19, x20
  f0:	54fffa8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  f4:	d10043ff 	sub	sp, sp, #0x10
  f8:	b90013e0 	str	w0, [sp, #16]
  fc:	910043ff 	add	sp, sp, #0x10
 100:	a8c153f3 	ldp	x19, x20, [sp], #16
 104:	a8c17bfd 	ldp	x29, x30, [sp], #16
 108:	d65f03c0 	ret

000000000000010c <call_indirect>:
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
 148:	b9400fe8 	ldr	w8, [sp, #12]
 14c:	b94013e9 	ldr	w9, [sp, #16]
 150:	f100093f 	cmp	x9, #0x2
 154:	54fff66a 	b.ge	20 <trap_handler+0x20>  // b.tcont
 158:	9000000a 	adrp	x10, 0 <trap_handler>
 15c:	9101714a 	add	x10, x10, #0x5c
 160:	f869794a 	ldr	x10, [x10, x9, lsl #3]
 164:	b100055f 	cmn	x10, #0x1
 168:	54fff600 	b.eq	28 <trap_handler+0x28>  // b.none
 16c:	d360fd4b 	lsr	x11, x10, #32
 170:	7100017f 	cmp	w11, #0x0
 174:	54fff5e1 	b.ne	30 <trap_handler+0x30>  // b.any
 178:	d2946009 	mov	x9, #0xa300                	// #41728
 17c:	f2a016c9 	movk	x9, #0xb6, lsl #16
 180:	f2c00aa9 	movk	x9, #0x55, lsl #32
 184:	f87f6929 	ldr	x9, [x9, xzr]
 188:	2a0a03ea 	mov	w10, w10
 18c:	8b0a012a 	add	x10, x9, x10
 190:	2a0803e0 	mov	w0, w8
 194:	d63f0140 	blr	x10
 198:	aa0003e8 	mov	x8, x0
 19c:	2a0803e0 	mov	w0, w8
 1a0:	910043ff 	add	sp, sp, #0x10
 1a4:	a8c153f3 	ldp	x19, x20, [sp], #16
 1a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1ac:	d65f03c0 	ret
