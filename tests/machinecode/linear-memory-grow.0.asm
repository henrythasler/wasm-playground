
./tests/machinecode/linear-memory-grow.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000078 load_at_zero
00000000000000d4 g     F .text	0000000000000078 store_at_zero
000000000000014c g     F .text	000000000000007c load_at_page_size
00000000000001c8 g     F .text	000000000000007c store_at_page_size
0000000000000244 g     F .text	000000000000007c grow
00000000000002c0 g     F .text	0000000000000050 size


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 08008052  ...........T...R
 0090 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 00a0 c9fcffb4 0a7094d2 ca16a0f2 aa0ac0f2  .....p..........
 00b0 4a697fb8 4a110051 1f010a6b e8fbff54  Ji..J..Q...k...T
 00c0 2969a8b8 e003092a f353c1a8 fd7bc1a8  )i.....*.S...{..
 00d0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 00e0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00f0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0100 0bfaff54 08008052 49008052 0a6c94d2  ...T...RI..R.l..
 0110 ca16a0f2 aa0ac0f2 4a697ff8 eaf8ff34  ........Ji.....4
 0120 0b7094d2 cb16a0f2 ab0ac0f2 6b697fb8  .p..........ki..
 0130 6b110051 1f010b6b 08f8ff54 496928b8  k..Q...k...TIi(.
 0140 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0150 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0160 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0170 1408a0f2 7f0214eb 4bf6ff54 08008052  ........K..T...R
 0180 2800a072 096c94d2 c916a0f2 a90ac0f2  (..r.l..........
 0190 29697ff8 29f5ffb4 0a7094d2 ca16a0f2  )i..)....p......
 01a0 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 01b0 48f4ff54 2969a8b8 e003092a f353c1a8  H..T)i.....*.S..
 01c0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 01d0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 01e0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 01f0 7f0214eb 6bf2ff54 08008052 2800a072  ....k..T...R(..r
 0200 69008052 0a6c94d2 ca16a0f2 aa0ac0f2  i..R.l..........
 0210 4a697ff8 2af1ff34 0b7094d2 cb16a0f2  Ji..*..4.p......
 0220 ab0ac0f2 6b697fb8 6b110051 1f010b6b  ....ki..k..Q...k
 0230 48f0ff54 496928b8 f353c1a8 fd7bc1a8  H..TIi(..S...{..
 0240 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0250 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0260 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0270 8beeff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 0280 097294d2 c916a0f2 a90ac0f2 29697ff8  .r..........)i..
 0290 006694d2 c016a0f2 a00ac0f2 00687ff8  .f...........h..
 02a0 e10308aa 20013fd6 e80300aa e003082a  .... .?........*
 02b0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 02c0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 02d0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 02e0 140080d2 1408a0f2 7f0214eb abeaff54  ...............T
 02f0 086e94d2 c816a0f2 a80ac0f2 08697fb8  .n...........i..
 0300 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.

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

000000000000005c <load_at_zero>:
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
  8c:	52800008 	mov	w8, #0x0                   	// #0
  90:	d2946c09 	mov	x9, #0xa360                	// #41824
  94:	f2a016c9 	movk	x9, #0xb6, lsl #16
  98:	f2c00aa9 	movk	x9, #0x55, lsl #32
  9c:	f87f6929 	ldr	x9, [x9, xzr]
  a0:	b4fffcc9 	cbz	x9, 38 <trap_handler+0x38>
  a4:	d294700a 	mov	x10, #0xa380                	// #41856
  a8:	f2a016ca 	movk	x10, #0xb6, lsl #16
  ac:	f2c00aaa 	movk	x10, #0x55, lsl #32
  b0:	b87f694a 	ldr	w10, [x10, xzr]
  b4:	5100114a 	sub	w10, w10, #0x4
  b8:	6b0a011f 	cmp	w8, w10
  bc:	54fffbe8 	b.hi	38 <trap_handler+0x38>  // b.pmore
  c0:	b8a86929 	ldrsw	x9, [x9, x8]
  c4:	2a0903e0 	mov	w0, w9
  c8:	a8c153f3 	ldp	x19, x20, [sp], #16
  cc:	a8c17bfd 	ldp	x29, x30, [sp], #16
  d0:	d65f03c0 	ret

00000000000000d4 <store_at_zero>:
  d4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  d8:	910003fd 	mov	x29, sp
  dc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  e0:	d2946413 	mov	x19, #0xa320                	// #41760
  e4:	f2a016d3 	movk	x19, #0xb6, lsl #16
  e8:	f2c00ab3 	movk	x19, #0x55, lsl #32
  ec:	f87f6a73 	ldr	x19, [x19, xzr]
  f0:	cb3363f3 	sub	x19, sp, x19
  f4:	d2800014 	mov	x20, #0x0                   	// #0
  f8:	f2a00814 	movk	x20, #0x40, lsl #16
  fc:	eb14027f 	cmp	x19, x20
 100:	54fffa0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 104:	52800008 	mov	w8, #0x0                   	// #0
 108:	52800049 	mov	w9, #0x2                   	// #2
 10c:	d2946c0a 	mov	x10, #0xa360                	// #41824
 110:	f2a016ca 	movk	x10, #0xb6, lsl #16
 114:	f2c00aaa 	movk	x10, #0x55, lsl #32
 118:	f87f694a 	ldr	x10, [x10, xzr]
 11c:	34fff8ea 	cbz	w10, 38 <trap_handler+0x38>
 120:	d294700b 	mov	x11, #0xa380                	// #41856
 124:	f2a016cb 	movk	x11, #0xb6, lsl #16
 128:	f2c00aab 	movk	x11, #0x55, lsl #32
 12c:	b87f696b 	ldr	w11, [x11, xzr]
 130:	5100116b 	sub	w11, w11, #0x4
 134:	6b0b011f 	cmp	w8, w11
 138:	54fff808 	b.hi	38 <trap_handler+0x38>  // b.pmore
 13c:	b8286949 	str	w9, [x10, x8]
 140:	a8c153f3 	ldp	x19, x20, [sp], #16
 144:	a8c17bfd 	ldp	x29, x30, [sp], #16
 148:	d65f03c0 	ret

000000000000014c <load_at_page_size>:
 14c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 150:	910003fd 	mov	x29, sp
 154:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 158:	d2946413 	mov	x19, #0xa320                	// #41760
 15c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 160:	f2c00ab3 	movk	x19, #0x55, lsl #32
 164:	f87f6a73 	ldr	x19, [x19, xzr]
 168:	cb3363f3 	sub	x19, sp, x19
 16c:	d2800014 	mov	x20, #0x0                   	// #0
 170:	f2a00814 	movk	x20, #0x40, lsl #16
 174:	eb14027f 	cmp	x19, x20
 178:	54fff64b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 17c:	52800008 	mov	w8, #0x0                   	// #0
 180:	72a00028 	movk	w8, #0x1, lsl #16
 184:	d2946c09 	mov	x9, #0xa360                	// #41824
 188:	f2a016c9 	movk	x9, #0xb6, lsl #16
 18c:	f2c00aa9 	movk	x9, #0x55, lsl #32
 190:	f87f6929 	ldr	x9, [x9, xzr]
 194:	b4fff529 	cbz	x9, 38 <trap_handler+0x38>
 198:	d294700a 	mov	x10, #0xa380                	// #41856
 19c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 1a0:	f2c00aaa 	movk	x10, #0x55, lsl #32
 1a4:	b87f694a 	ldr	w10, [x10, xzr]
 1a8:	5100114a 	sub	w10, w10, #0x4
 1ac:	6b0a011f 	cmp	w8, w10
 1b0:	54fff448 	b.hi	38 <trap_handler+0x38>  // b.pmore
 1b4:	b8a86929 	ldrsw	x9, [x9, x8]
 1b8:	2a0903e0 	mov	w0, w9
 1bc:	a8c153f3 	ldp	x19, x20, [sp], #16
 1c0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1c4:	d65f03c0 	ret

00000000000001c8 <store_at_page_size>:
 1c8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1cc:	910003fd 	mov	x29, sp
 1d0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1d4:	d2946413 	mov	x19, #0xa320                	// #41760
 1d8:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1dc:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1e0:	f87f6a73 	ldr	x19, [x19, xzr]
 1e4:	cb3363f3 	sub	x19, sp, x19
 1e8:	d2800014 	mov	x20, #0x0                   	// #0
 1ec:	f2a00814 	movk	x20, #0x40, lsl #16
 1f0:	eb14027f 	cmp	x19, x20
 1f4:	54fff26b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1f8:	52800008 	mov	w8, #0x0                   	// #0
 1fc:	72a00028 	movk	w8, #0x1, lsl #16
 200:	52800069 	mov	w9, #0x3                   	// #3
 204:	d2946c0a 	mov	x10, #0xa360                	// #41824
 208:	f2a016ca 	movk	x10, #0xb6, lsl #16
 20c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 210:	f87f694a 	ldr	x10, [x10, xzr]
 214:	34fff12a 	cbz	w10, 38 <trap_handler+0x38>
 218:	d294700b 	mov	x11, #0xa380                	// #41856
 21c:	f2a016cb 	movk	x11, #0xb6, lsl #16
 220:	f2c00aab 	movk	x11, #0x55, lsl #32
 224:	b87f696b 	ldr	w11, [x11, xzr]
 228:	5100116b 	sub	w11, w11, #0x4
 22c:	6b0b011f 	cmp	w8, w11
 230:	54fff048 	b.hi	38 <trap_handler+0x38>  // b.pmore
 234:	b8286949 	str	w9, [x10, x8]
 238:	a8c153f3 	ldp	x19, x20, [sp], #16
 23c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 240:	d65f03c0 	ret

0000000000000244 <grow>:
 244:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 248:	910003fd 	mov	x29, sp
 24c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 250:	d2946413 	mov	x19, #0xa320                	// #41760
 254:	f2a016d3 	movk	x19, #0xb6, lsl #16
 258:	f2c00ab3 	movk	x19, #0x55, lsl #32
 25c:	f87f6a73 	ldr	x19, [x19, xzr]
 260:	cb3363f3 	sub	x19, sp, x19
 264:	d2800014 	mov	x20, #0x0                   	// #0
 268:	f2a00814 	movk	x20, #0x40, lsl #16
 26c:	eb14027f 	cmp	x19, x20
 270:	54ffee8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 274:	d10043ff 	sub	sp, sp, #0x10
 278:	b90013e0 	str	w0, [sp, #16]
 27c:	b94013e8 	ldr	w8, [sp, #16]
 280:	d2947209 	mov	x9, #0xa390                	// #41872
 284:	f2a016c9 	movk	x9, #0xb6, lsl #16
 288:	f2c00aa9 	movk	x9, #0x55, lsl #32
 28c:	f87f6929 	ldr	x9, [x9, xzr]
 290:	d2946600 	mov	x0, #0xa330                	// #41776
 294:	f2a016c0 	movk	x0, #0xb6, lsl #16
 298:	f2c00aa0 	movk	x0, #0x55, lsl #32
 29c:	f87f6800 	ldr	x0, [x0, xzr]
 2a0:	aa0803e1 	mov	x1, x8
 2a4:	d63f0120 	blr	x9
 2a8:	aa0003e8 	mov	x8, x0
 2ac:	2a0803e0 	mov	w0, w8
 2b0:	910043ff 	add	sp, sp, #0x10
 2b4:	a8c153f3 	ldp	x19, x20, [sp], #16
 2b8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2bc:	d65f03c0 	ret

00000000000002c0 <size>:
 2c0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 2c4:	910003fd 	mov	x29, sp
 2c8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 2cc:	d2946413 	mov	x19, #0xa320                	// #41760
 2d0:	f2a016d3 	movk	x19, #0xb6, lsl #16
 2d4:	f2c00ab3 	movk	x19, #0x55, lsl #32
 2d8:	f87f6a73 	ldr	x19, [x19, xzr]
 2dc:	cb3363f3 	sub	x19, sp, x19
 2e0:	d2800014 	mov	x20, #0x0                   	// #0
 2e4:	f2a00814 	movk	x20, #0x40, lsl #16
 2e8:	eb14027f 	cmp	x19, x20
 2ec:	54ffeaab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 2f0:	d2946e08 	mov	x8, #0xa370                	// #41840
 2f4:	f2a016c8 	movk	x8, #0xb6, lsl #16
 2f8:	f2c00aa8 	movk	x8, #0x55, lsl #32
 2fc:	b87f6908 	ldr	w8, [x8, xzr]
 300:	2a0803e0 	mov	w0, w8
 304:	a8c153f3 	ldp	x19, x20, [sp], #16
 308:	a8c17bfd 	ldp	x29, x30, [sp], #16
 30c:	d65f03c0 	ret
