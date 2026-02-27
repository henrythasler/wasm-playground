
./tests/machinecode/memory-grow.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000084 load_i32
00000000000000e0 g     F .text	00000000000000c4 store_i32
00000000000001a4 g     F .text	000000000000007c memory_grow
0000000000000220 g     F .text	0000000000000050 memory_size


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
 0090 e01300b9 e81340b9 096c94d2 c916a0f2  ......@..l......
 00a0 a90ac0f2 29697ff8 89fcffb4 0a7094d2  ....)i.......p..
 00b0 ca16a0f2 aa0ac0f2 4a697fb8 4a110051  ........Ji..J..Q
 00c0 1f010a6b a8fbff54 2969a8b8 e003092a  ...k...T)i.....*
 00d0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00e0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00f0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0100 140080d2 1408a0f2 7f0214eb abf9ff54  ...............T
 0110 ff4300d1 e01300b9 e10f00b9 e81340b9  .C............@.
 0120 e90f40b9 0a6c94d2 ca16a0f2 aa0ac0f2  ..@..l..........
 0130 4a697ff8 2af8ff34 0b7094d2 cb16a0f2  Ji..*..4.p......
 0140 ab0ac0f2 6b697fb8 6b110051 1f010b6b  ....ki..k..Q...k
 0150 48f7ff54 496928b8 e81340b9 096c94d2  H..TIi(...@..l..
 0160 c916a0f2 a90ac0f2 29697ff8 69f6ffb4  ........)i..i...
 0170 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0180 4a110051 1f010a6b 88f5ff54 2969a8b8  J..Q...k...T)i..
 0190 e003092a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 01a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01d0 8bf3ff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 01e0 097294d2 c916a0f2 a90ac0f2 29697ff8  .r..........)i..
 01f0 006694d2 c016a0f2 a00ac0f2 00687ff8  .f...........h..
 0200 e10308aa 20013fd6 e80300aa e003082a  .... .?........*
 0210 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0220 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0230 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0240 140080d2 1408a0f2 7f0214eb abefff54  ...............T
 0250 086e94d2 c816a0f2 a80ac0f2 08697fb8  .n...........i..
 0260 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.

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

000000000000005c <load_i32>:
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
  98:	d2946c09 	mov	x9, #0xa360                	// #41824
  9c:	f2a016c9 	movk	x9, #0xb6, lsl #16
  a0:	f2c00aa9 	movk	x9, #0x55, lsl #32
  a4:	f87f6929 	ldr	x9, [x9, xzr]
  a8:	b4fffc89 	cbz	x9, 38 <trap_handler+0x38>
  ac:	d294700a 	mov	x10, #0xa380                	// #41856
  b0:	f2a016ca 	movk	x10, #0xb6, lsl #16
  b4:	f2c00aaa 	movk	x10, #0x55, lsl #32
  b8:	b87f694a 	ldr	w10, [x10, xzr]
  bc:	5100114a 	sub	w10, w10, #0x4
  c0:	6b0a011f 	cmp	w8, w10
  c4:	54fffba8 	b.hi	38 <trap_handler+0x38>  // b.pmore
  c8:	b8a86929 	ldrsw	x9, [x9, x8]
  cc:	2a0903e0 	mov	w0, w9
  d0:	910043ff 	add	sp, sp, #0x10
  d4:	a8c153f3 	ldp	x19, x20, [sp], #16
  d8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  dc:	d65f03c0 	ret

00000000000000e0 <store_i32>:
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
 124:	d2946c0a 	mov	x10, #0xa360                	// #41824
 128:	f2a016ca 	movk	x10, #0xb6, lsl #16
 12c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 130:	f87f694a 	ldr	x10, [x10, xzr]
 134:	34fff82a 	cbz	w10, 38 <trap_handler+0x38>
 138:	d294700b 	mov	x11, #0xa380                	// #41856
 13c:	f2a016cb 	movk	x11, #0xb6, lsl #16
 140:	f2c00aab 	movk	x11, #0x55, lsl #32
 144:	b87f696b 	ldr	w11, [x11, xzr]
 148:	5100116b 	sub	w11, w11, #0x4
 14c:	6b0b011f 	cmp	w8, w11
 150:	54fff748 	b.hi	38 <trap_handler+0x38>  // b.pmore
 154:	b8286949 	str	w9, [x10, x8]
 158:	b94013e8 	ldr	w8, [sp, #16]
 15c:	d2946c09 	mov	x9, #0xa360                	// #41824
 160:	f2a016c9 	movk	x9, #0xb6, lsl #16
 164:	f2c00aa9 	movk	x9, #0x55, lsl #32
 168:	f87f6929 	ldr	x9, [x9, xzr]
 16c:	b4fff669 	cbz	x9, 38 <trap_handler+0x38>
 170:	d294700a 	mov	x10, #0xa380                	// #41856
 174:	f2a016ca 	movk	x10, #0xb6, lsl #16
 178:	f2c00aaa 	movk	x10, #0x55, lsl #32
 17c:	b87f694a 	ldr	w10, [x10, xzr]
 180:	5100114a 	sub	w10, w10, #0x4
 184:	6b0a011f 	cmp	w8, w10
 188:	54fff588 	b.hi	38 <trap_handler+0x38>  // b.pmore
 18c:	b8a86929 	ldrsw	x9, [x9, x8]
 190:	2a0903e0 	mov	w0, w9
 194:	910043ff 	add	sp, sp, #0x10
 198:	a8c153f3 	ldp	x19, x20, [sp], #16
 19c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a0:	d65f03c0 	ret

00000000000001a4 <memory_grow>:
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
 1d8:	b90013e0 	str	w0, [sp, #16]
 1dc:	b94013e8 	ldr	w8, [sp, #16]
 1e0:	d2947209 	mov	x9, #0xa390                	// #41872
 1e4:	f2a016c9 	movk	x9, #0xb6, lsl #16
 1e8:	f2c00aa9 	movk	x9, #0x55, lsl #32
 1ec:	f87f6929 	ldr	x9, [x9, xzr]
 1f0:	d2946600 	mov	x0, #0xa330                	// #41776
 1f4:	f2a016c0 	movk	x0, #0xb6, lsl #16
 1f8:	f2c00aa0 	movk	x0, #0x55, lsl #32
 1fc:	f87f6800 	ldr	x0, [x0, xzr]
 200:	aa0803e1 	mov	x1, x8
 204:	d63f0120 	blr	x9
 208:	aa0003e8 	mov	x8, x0
 20c:	2a0803e0 	mov	w0, w8
 210:	910043ff 	add	sp, sp, #0x10
 214:	a8c153f3 	ldp	x19, x20, [sp], #16
 218:	a8c17bfd 	ldp	x29, x30, [sp], #16
 21c:	d65f03c0 	ret

0000000000000220 <memory_size>:
 220:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 224:	910003fd 	mov	x29, sp
 228:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 22c:	d2946413 	mov	x19, #0xa320                	// #41760
 230:	f2a016d3 	movk	x19, #0xb6, lsl #16
 234:	f2c00ab3 	movk	x19, #0x55, lsl #32
 238:	f87f6a73 	ldr	x19, [x19, xzr]
 23c:	cb3363f3 	sub	x19, sp, x19
 240:	d2800014 	mov	x20, #0x0                   	// #0
 244:	f2a00814 	movk	x20, #0x40, lsl #16
 248:	eb14027f 	cmp	x19, x20
 24c:	54ffefab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 250:	d2946e08 	mov	x8, #0xa370                	// #41840
 254:	f2a016c8 	movk	x8, #0xb6, lsl #16
 258:	f2c00aa8 	movk	x8, #0x55, lsl #32
 25c:	b87f6908 	ldr	w8, [x8, xzr]
 260:	2a0803e0 	mov	w0, w8
 264:	a8c153f3 	ldp	x19, x20, [sp], #16
 268:	a8c17bfd 	ldp	x29, x30, [sp], #16
 26c:	d65f03c0 	ret
