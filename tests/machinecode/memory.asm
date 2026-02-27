
./tests/machinecode/memory.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000084 load_i64
00000000000000e0 g     F .text	0000000000000084 load_i32
0000000000000164 g     F .text	0000000000000084 load_u16
00000000000001e8 g     F .text	0000000000000084 load_u8
000000000000026c g     F .text	0000000000000084 load_i8
00000000000002f0 g     F .text	0000000000000088 load_u8_offset
0000000000000378 g     F .text	00000000000000c4 store_i64
000000000000043c g     F .text	00000000000000c4 store_i32
0000000000000500 g     F .text	00000000000000c4 store_i16
00000000000005c4 g     F .text	00000000000000c4 store_i8
0000000000000688 g     F .text	00000000000001dc loop
0000000000000000 g     O .rodata	0000000000000008 globals


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
 00b0 ca16a0f2 aa0ac0f2 4a697fb8 4a210051  ........Ji..J!.Q
 00c0 1f010a6b a8fbff54 296968f8 e00309aa  ...k...T)ih.....
 00d0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00e0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00f0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0100 140080d2 1408a0f2 7f0214eb abf9ff54  ...............T
 0110 ff4300d1 e01300b9 e81340b9 096c94d2  .C........@..l..
 0120 c916a0f2 a90ac0f2 29697ff8 69f8ffb4  ........)i..i...
 0130 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0140 4a110051 1f010a6b 88f7ff54 2969a8b8  J..Q...k...T)i..
 0150 e003092a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0160 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0170 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0180 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0190 8bf5ff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 01a0 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 01b0 49f4ff34 0a7094d2 ca16a0f2 aa0ac0f2  I..4.p..........
 01c0 4a697fb8 4a090051 1f010a6b 68f3ff54  Ji..J..Q...kh..T
 01d0 29696878 e003092a ff430091 f353c1a8  )ihx...*.C...S..
 01e0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 01f0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0200 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0210 7f0214eb 6bf1ff54 ff4300d1 e01300b9  ....k..T.C......
 0220 e81340b9 096c94d2 c916a0f2 a90ac0f2  ..@..l..........
 0230 29697ff8 29f0ff34 0a7094d2 ca16a0f2  )i..)..4.p......
 0240 aa0ac0f2 4a697fb8 4a050051 1f010a6b  ....Ji..J..Q...k
 0250 48efff54 29796838 e003092a ff430091  H..T)yh8...*.C..
 0260 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0270 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0280 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0290 1408a0f2 7f0214eb 4bedff54 ff4300d1  ........K..T.C..
 02a0 e01300b9 e81340b9 096c94d2 c916a0f2  ......@..l......
 02b0 a90ac0f2 29697ff8 09ecff34 0a7094d2  ....)i.....4.p..
 02c0 ca16a0f2 aa0ac0f2 4a697fb8 4a050051  ........Ji..J..Q
 02d0 1f010a6b 28ebff54 2979e838 e003092a  ...k(..T)y.8...*
 02e0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 02f0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0300 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0310 140080d2 1408a0f2 7f0214eb 2be9ff54  ............+..T
 0320 ff4300d1 e01300b9 e81340b9 096c94d2  .C........@..l..
 0330 c916a0f2 a90ac0f2 29697ff8 e9e7ff34  ........)i.....4
 0340 08010c91 0a7094d2 ca16a0f2 aa0ac0f2  .....p..........
 0350 4a697fb8 4a050051 1f010a6b e8e6ff54  Ji..J..Q...k...T
 0360 29796838 e003092a ff430091 f353c1a8  )yh8...*.C...S..
 0370 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0380 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0390 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 03a0 7f0214eb ebe4ff54 ff4300d1 e01300b9  .......T.C......
 03b0 e10700f9 e81340b9 e90740f9 0a6c94d2  ......@...@..l..
 03c0 ca16a0f2 aa0ac0f2 4a697ff8 6ae3ffb4  ........Ji..j...
 03d0 0b7094d2 cb16a0f2 ab0ac0f2 6b697fb8  .p..........ki..
 03e0 6b210051 1f010b6b 88e2ff54 496928f8  k!.Q...k...TIi(.
 03f0 e81340b9 096c94d2 c916a0f2 a90ac0f2  ..@..l..........
 0400 29697ff8 a9e1ffb4 0a7094d2 ca16a0f2  )i.......p......
 0410 aa0ac0f2 4a697fb8 4a210051 1f010a6b  ....Ji..J!.Q...k
 0420 c8e0ff54 296968f8 e00309aa ff430091  ...T)ih......C..
 0430 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0440 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0450 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0460 1408a0f2 7f0214eb cbdeff54 ff4300d1  ...........T.C..
 0470 e01300b9 e10f00b9 e81340b9 e90f40b9  ..........@...@.
 0480 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0490 4addff34 0b7094d2 cb16a0f2 ab0ac0f2  J..4.p..........
 04a0 6b697fb8 6b110051 1f010b6b 68dcff54  ki..k..Q...kh..T
 04b0 496928b8 e81340b9 096c94d2 c916a0f2  Ii(...@..l......
 04c0 a90ac0f2 29697ff8 89dbffb4 0a7094d2  ....)i.......p..
 04d0 ca16a0f2 aa0ac0f2 4a697fb8 4a110051  ........Ji..J..Q
 04e0 1f010a6b a8daff54 2969a8b8 e003092a  ...k...T)i.....*
 04f0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0500 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0510 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0520 140080d2 1408a0f2 7f0214eb abd8ff54  ...............T
 0530 ff4300d1 e01300b9 e10f00b9 e81340b9  .C............@.
 0540 e90f40b9 0a6c94d2 ca16a0f2 aa0ac0f2  ..@..l..........
 0550 4a697ff8 2ad7ff34 0b7094d2 cb16a0f2  Ji..*..4.p......
 0560 ab0ac0f2 6b697fb8 6b090051 1f010b6b  ....ki..k..Q...k
 0570 48d6ff54 49692878 e81340b9 096c94d2  H..TIi(x..@..l..
 0580 c916a0f2 a90ac0f2 29697ff8 69d5ff34  ........)i..i..4
 0590 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 05a0 4a090051 1f010a6b 88d4ff54 29696878  J..Q...k...T)ihx
 05b0 e003092a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 05c0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 05d0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 05e0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 05f0 8bd2ff54 ff4300d1 e01300b9 e10f00b9  ...T.C..........
 0600 e81340b9 e90f40b9 0a6c94d2 ca16a0f2  ..@...@..l......
 0610 aa0ac0f2 4a697ff8 0ad1ff34 0b7094d2  ....Ji.....4.p..
 0620 cb16a0f2 ab0ac0f2 6b697fb8 6b050051  ........ki..k..Q
 0630 1f010b6b 28d0ff54 49792838 e81340b9  ...k(..TIy(8..@.
 0640 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 0650 49cfff34 0a7094d2 ca16a0f2 aa0ac0f2  I..4.p..........
 0660 4a697fb8 4a050051 1f010a6b 68ceff54  Ji..J..Q...kh..T
 0670 29796838 e003092a ff430091 f353c1a8  )yh8...*.C...S..
 0680 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0690 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 06a0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 06b0 7f0214eb 6bccff54 ff4300d1 ff1300b9  ....k..T.C......
 06c0 28008052 097294d2 c916a0f2 a90ac0f2  (..R.r..........
 06d0 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 06e0 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 06f0 096294d2 c916a0f2 a90ac0f2 29697ff8  .b..........)i..
 0700 29010091 29697ff8 0a028052 29010a4b  )...)i.....R)..K
 0710 e91300b9 e91340b9 4a018052 0b6c94d2  ......@.J..R.l..
 0720 cb16a0f2 ab0ac0f2 6b697ff8 6bc8ff34  ........ki..k..4
 0730 29310091 0c7094d2 cc16a0f2 ac0ac0f2  )1...p..........
 0740 8c697fb8 8c110051 3f010c6b 68c7ff54  .i.....Q?..kh..T
 0750 6a6929b8 e91340b9 0a6c94d2 ca16a0f2  ji)...@..l......
 0760 aa0ac0f2 4a697ff8 8ac6ffb4 29310091  ....Ji......)1..
 0770 0b7094d2 cb16a0f2 ab0ac0f2 6b697fb8  .p..........ki..
 0780 6b110051 3f010b6b 88c5ff54 4a69a9b8  k..Q?..k...TJi..
 0790 89028052 5f01096b 6b000054 0a008052  ...R_..kk..T...R
 07a0 02000014 2a008052 29008052 4a01090a  ....*..R)..RJ...
 07b0 6a000034 0a008052 02000014 2a008052  j..4...R....*..R
 07c0 4a040035 e91340b9 ea1340b9 0b6c94d2  J..5..@...@..l..
 07d0 cb16a0f2 ab0ac0f2 6b697ff8 ebc2ffb4  ........ki......
 07e0 4a310091 0c7094d2 cc16a0f2 ac0ac0f2  J1...p..........
 07f0 8c697fb8 8c110051 5f010c6b e8c1ff54  .i.....Q_..k...T
 0800 6b69aab8 2a008052 6b010a0b 0a6c94d2  ki..*..Rk....l..
 0810 ca16a0f2 aa0ac0f2 4a697ff8 eac0ff34  ........Ji.....4
 0820 29310091 0c7094d2 cc16a0f2 ac0ac0f2  )1...p..........
 0830 8c697fb8 8c110051 3f010c6b e8bfff54  .i.....Q?..k...T
 0840 4b6929b8 c4ffff17 09008052 3f0000b4  Ki)........R?...
 0850 e003092a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0860 c0035fd6                             .._.            
Contents of section .data:
 0000 10240000 00000000                    .$......        

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

000000000000005c <load_i64>:
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
  bc:	5100214a 	sub	w10, w10, #0x8
  c0:	6b0a011f 	cmp	w8, w10
  c4:	54fffba8 	b.hi	38 <trap_handler+0x38>  // b.pmore
  c8:	f8686929 	ldr	x9, [x9, x8]
  cc:	aa0903e0 	mov	x0, x9
  d0:	910043ff 	add	sp, sp, #0x10
  d4:	a8c153f3 	ldp	x19, x20, [sp], #16
  d8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  dc:	d65f03c0 	ret

00000000000000e0 <load_i32>:
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
 118:	b94013e8 	ldr	w8, [sp, #16]
 11c:	d2946c09 	mov	x9, #0xa360                	// #41824
 120:	f2a016c9 	movk	x9, #0xb6, lsl #16
 124:	f2c00aa9 	movk	x9, #0x55, lsl #32
 128:	f87f6929 	ldr	x9, [x9, xzr]
 12c:	b4fff869 	cbz	x9, 38 <trap_handler+0x38>
 130:	d294700a 	mov	x10, #0xa380                	// #41856
 134:	f2a016ca 	movk	x10, #0xb6, lsl #16
 138:	f2c00aaa 	movk	x10, #0x55, lsl #32
 13c:	b87f694a 	ldr	w10, [x10, xzr]
 140:	5100114a 	sub	w10, w10, #0x4
 144:	6b0a011f 	cmp	w8, w10
 148:	54fff788 	b.hi	38 <trap_handler+0x38>  // b.pmore
 14c:	b8a86929 	ldrsw	x9, [x9, x8]
 150:	2a0903e0 	mov	w0, w9
 154:	910043ff 	add	sp, sp, #0x10
 158:	a8c153f3 	ldp	x19, x20, [sp], #16
 15c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 160:	d65f03c0 	ret

0000000000000164 <load_u16>:
 164:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 168:	910003fd 	mov	x29, sp
 16c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 170:	d2946413 	mov	x19, #0xa320                	// #41760
 174:	f2a016d3 	movk	x19, #0xb6, lsl #16
 178:	f2c00ab3 	movk	x19, #0x55, lsl #32
 17c:	f87f6a73 	ldr	x19, [x19, xzr]
 180:	cb3363f3 	sub	x19, sp, x19
 184:	d2800014 	mov	x20, #0x0                   	// #0
 188:	f2a00814 	movk	x20, #0x40, lsl #16
 18c:	eb14027f 	cmp	x19, x20
 190:	54fff58b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 194:	d10043ff 	sub	sp, sp, #0x10
 198:	b90013e0 	str	w0, [sp, #16]
 19c:	b94013e8 	ldr	w8, [sp, #16]
 1a0:	d2946c09 	mov	x9, #0xa360                	// #41824
 1a4:	f2a016c9 	movk	x9, #0xb6, lsl #16
 1a8:	f2c00aa9 	movk	x9, #0x55, lsl #32
 1ac:	f87f6929 	ldr	x9, [x9, xzr]
 1b0:	34fff449 	cbz	w9, 38 <trap_handler+0x38>
 1b4:	d294700a 	mov	x10, #0xa380                	// #41856
 1b8:	f2a016ca 	movk	x10, #0xb6, lsl #16
 1bc:	f2c00aaa 	movk	x10, #0x55, lsl #32
 1c0:	b87f694a 	ldr	w10, [x10, xzr]
 1c4:	5100094a 	sub	w10, w10, #0x2
 1c8:	6b0a011f 	cmp	w8, w10
 1cc:	54fff368 	b.hi	38 <trap_handler+0x38>  // b.pmore
 1d0:	78686929 	ldrh	w9, [x9, x8]
 1d4:	2a0903e0 	mov	w0, w9
 1d8:	910043ff 	add	sp, sp, #0x10
 1dc:	a8c153f3 	ldp	x19, x20, [sp], #16
 1e0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1e4:	d65f03c0 	ret

00000000000001e8 <load_u8>:
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
 224:	d2946c09 	mov	x9, #0xa360                	// #41824
 228:	f2a016c9 	movk	x9, #0xb6, lsl #16
 22c:	f2c00aa9 	movk	x9, #0x55, lsl #32
 230:	f87f6929 	ldr	x9, [x9, xzr]
 234:	34fff029 	cbz	w9, 38 <trap_handler+0x38>
 238:	d294700a 	mov	x10, #0xa380                	// #41856
 23c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 240:	f2c00aaa 	movk	x10, #0x55, lsl #32
 244:	b87f694a 	ldr	w10, [x10, xzr]
 248:	5100054a 	sub	w10, w10, #0x1
 24c:	6b0a011f 	cmp	w8, w10
 250:	54ffef48 	b.hi	38 <trap_handler+0x38>  // b.pmore
 254:	38687929 	ldrb	w9, [x9, x8, lsl #0]
 258:	2a0903e0 	mov	w0, w9
 25c:	910043ff 	add	sp, sp, #0x10
 260:	a8c153f3 	ldp	x19, x20, [sp], #16
 264:	a8c17bfd 	ldp	x29, x30, [sp], #16
 268:	d65f03c0 	ret

000000000000026c <load_i8>:
 26c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 270:	910003fd 	mov	x29, sp
 274:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 278:	d2946413 	mov	x19, #0xa320                	// #41760
 27c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 280:	f2c00ab3 	movk	x19, #0x55, lsl #32
 284:	f87f6a73 	ldr	x19, [x19, xzr]
 288:	cb3363f3 	sub	x19, sp, x19
 28c:	d2800014 	mov	x20, #0x0                   	// #0
 290:	f2a00814 	movk	x20, #0x40, lsl #16
 294:	eb14027f 	cmp	x19, x20
 298:	54ffed4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 29c:	d10043ff 	sub	sp, sp, #0x10
 2a0:	b90013e0 	str	w0, [sp, #16]
 2a4:	b94013e8 	ldr	w8, [sp, #16]
 2a8:	d2946c09 	mov	x9, #0xa360                	// #41824
 2ac:	f2a016c9 	movk	x9, #0xb6, lsl #16
 2b0:	f2c00aa9 	movk	x9, #0x55, lsl #32
 2b4:	f87f6929 	ldr	x9, [x9, xzr]
 2b8:	34ffec09 	cbz	w9, 38 <trap_handler+0x38>
 2bc:	d294700a 	mov	x10, #0xa380                	// #41856
 2c0:	f2a016ca 	movk	x10, #0xb6, lsl #16
 2c4:	f2c00aaa 	movk	x10, #0x55, lsl #32
 2c8:	b87f694a 	ldr	w10, [x10, xzr]
 2cc:	5100054a 	sub	w10, w10, #0x1
 2d0:	6b0a011f 	cmp	w8, w10
 2d4:	54ffeb28 	b.hi	38 <trap_handler+0x38>  // b.pmore
 2d8:	38e87929 	ldrsb	w9, [x9, x8, lsl #0]
 2dc:	2a0903e0 	mov	w0, w9
 2e0:	910043ff 	add	sp, sp, #0x10
 2e4:	a8c153f3 	ldp	x19, x20, [sp], #16
 2e8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2ec:	d65f03c0 	ret

00000000000002f0 <load_u8_offset>:
 2f0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 2f4:	910003fd 	mov	x29, sp
 2f8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 2fc:	d2946413 	mov	x19, #0xa320                	// #41760
 300:	f2a016d3 	movk	x19, #0xb6, lsl #16
 304:	f2c00ab3 	movk	x19, #0x55, lsl #32
 308:	f87f6a73 	ldr	x19, [x19, xzr]
 30c:	cb3363f3 	sub	x19, sp, x19
 310:	d2800014 	mov	x20, #0x0                   	// #0
 314:	f2a00814 	movk	x20, #0x40, lsl #16
 318:	eb14027f 	cmp	x19, x20
 31c:	54ffe92b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 320:	d10043ff 	sub	sp, sp, #0x10
 324:	b90013e0 	str	w0, [sp, #16]
 328:	b94013e8 	ldr	w8, [sp, #16]
 32c:	d2946c09 	mov	x9, #0xa360                	// #41824
 330:	f2a016c9 	movk	x9, #0xb6, lsl #16
 334:	f2c00aa9 	movk	x9, #0x55, lsl #32
 338:	f87f6929 	ldr	x9, [x9, xzr]
 33c:	34ffe7e9 	cbz	w9, 38 <trap_handler+0x38>
 340:	910c0108 	add	x8, x8, #0x300
 344:	d294700a 	mov	x10, #0xa380                	// #41856
 348:	f2a016ca 	movk	x10, #0xb6, lsl #16
 34c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 350:	b87f694a 	ldr	w10, [x10, xzr]
 354:	5100054a 	sub	w10, w10, #0x1
 358:	6b0a011f 	cmp	w8, w10
 35c:	54ffe6e8 	b.hi	38 <trap_handler+0x38>  // b.pmore
 360:	38687929 	ldrb	w9, [x9, x8, lsl #0]
 364:	2a0903e0 	mov	w0, w9
 368:	910043ff 	add	sp, sp, #0x10
 36c:	a8c153f3 	ldp	x19, x20, [sp], #16
 370:	a8c17bfd 	ldp	x29, x30, [sp], #16
 374:	d65f03c0 	ret

0000000000000378 <store_i64>:
 378:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 37c:	910003fd 	mov	x29, sp
 380:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 384:	d2946413 	mov	x19, #0xa320                	// #41760
 388:	f2a016d3 	movk	x19, #0xb6, lsl #16
 38c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 390:	f87f6a73 	ldr	x19, [x19, xzr]
 394:	cb3363f3 	sub	x19, sp, x19
 398:	d2800014 	mov	x20, #0x0                   	// #0
 39c:	f2a00814 	movk	x20, #0x40, lsl #16
 3a0:	eb14027f 	cmp	x19, x20
 3a4:	54ffe4eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 3a8:	d10043ff 	sub	sp, sp, #0x10
 3ac:	b90013e0 	str	w0, [sp, #16]
 3b0:	f90007e1 	str	x1, [sp, #8]
 3b4:	b94013e8 	ldr	w8, [sp, #16]
 3b8:	f94007e9 	ldr	x9, [sp, #8]
 3bc:	d2946c0a 	mov	x10, #0xa360                	// #41824
 3c0:	f2a016ca 	movk	x10, #0xb6, lsl #16
 3c4:	f2c00aaa 	movk	x10, #0x55, lsl #32
 3c8:	f87f694a 	ldr	x10, [x10, xzr]
 3cc:	b4ffe36a 	cbz	x10, 38 <trap_handler+0x38>
 3d0:	d294700b 	mov	x11, #0xa380                	// #41856
 3d4:	f2a016cb 	movk	x11, #0xb6, lsl #16
 3d8:	f2c00aab 	movk	x11, #0x55, lsl #32
 3dc:	b87f696b 	ldr	w11, [x11, xzr]
 3e0:	5100216b 	sub	w11, w11, #0x8
 3e4:	6b0b011f 	cmp	w8, w11
 3e8:	54ffe288 	b.hi	38 <trap_handler+0x38>  // b.pmore
 3ec:	f8286949 	str	x9, [x10, x8]
 3f0:	b94013e8 	ldr	w8, [sp, #16]
 3f4:	d2946c09 	mov	x9, #0xa360                	// #41824
 3f8:	f2a016c9 	movk	x9, #0xb6, lsl #16
 3fc:	f2c00aa9 	movk	x9, #0x55, lsl #32
 400:	f87f6929 	ldr	x9, [x9, xzr]
 404:	b4ffe1a9 	cbz	x9, 38 <trap_handler+0x38>
 408:	d294700a 	mov	x10, #0xa380                	// #41856
 40c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 410:	f2c00aaa 	movk	x10, #0x55, lsl #32
 414:	b87f694a 	ldr	w10, [x10, xzr]
 418:	5100214a 	sub	w10, w10, #0x8
 41c:	6b0a011f 	cmp	w8, w10
 420:	54ffe0c8 	b.hi	38 <trap_handler+0x38>  // b.pmore
 424:	f8686929 	ldr	x9, [x9, x8]
 428:	aa0903e0 	mov	x0, x9
 42c:	910043ff 	add	sp, sp, #0x10
 430:	a8c153f3 	ldp	x19, x20, [sp], #16
 434:	a8c17bfd 	ldp	x29, x30, [sp], #16
 438:	d65f03c0 	ret

000000000000043c <store_i32>:
 43c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 440:	910003fd 	mov	x29, sp
 444:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 448:	d2946413 	mov	x19, #0xa320                	// #41760
 44c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 450:	f2c00ab3 	movk	x19, #0x55, lsl #32
 454:	f87f6a73 	ldr	x19, [x19, xzr]
 458:	cb3363f3 	sub	x19, sp, x19
 45c:	d2800014 	mov	x20, #0x0                   	// #0
 460:	f2a00814 	movk	x20, #0x40, lsl #16
 464:	eb14027f 	cmp	x19, x20
 468:	54ffdecb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 46c:	d10043ff 	sub	sp, sp, #0x10
 470:	b90013e0 	str	w0, [sp, #16]
 474:	b9000fe1 	str	w1, [sp, #12]
 478:	b94013e8 	ldr	w8, [sp, #16]
 47c:	b9400fe9 	ldr	w9, [sp, #12]
 480:	d2946c0a 	mov	x10, #0xa360                	// #41824
 484:	f2a016ca 	movk	x10, #0xb6, lsl #16
 488:	f2c00aaa 	movk	x10, #0x55, lsl #32
 48c:	f87f694a 	ldr	x10, [x10, xzr]
 490:	34ffdd4a 	cbz	w10, 38 <trap_handler+0x38>
 494:	d294700b 	mov	x11, #0xa380                	// #41856
 498:	f2a016cb 	movk	x11, #0xb6, lsl #16
 49c:	f2c00aab 	movk	x11, #0x55, lsl #32
 4a0:	b87f696b 	ldr	w11, [x11, xzr]
 4a4:	5100116b 	sub	w11, w11, #0x4
 4a8:	6b0b011f 	cmp	w8, w11
 4ac:	54ffdc68 	b.hi	38 <trap_handler+0x38>  // b.pmore
 4b0:	b8286949 	str	w9, [x10, x8]
 4b4:	b94013e8 	ldr	w8, [sp, #16]
 4b8:	d2946c09 	mov	x9, #0xa360                	// #41824
 4bc:	f2a016c9 	movk	x9, #0xb6, lsl #16
 4c0:	f2c00aa9 	movk	x9, #0x55, lsl #32
 4c4:	f87f6929 	ldr	x9, [x9, xzr]
 4c8:	b4ffdb89 	cbz	x9, 38 <trap_handler+0x38>
 4cc:	d294700a 	mov	x10, #0xa380                	// #41856
 4d0:	f2a016ca 	movk	x10, #0xb6, lsl #16
 4d4:	f2c00aaa 	movk	x10, #0x55, lsl #32
 4d8:	b87f694a 	ldr	w10, [x10, xzr]
 4dc:	5100114a 	sub	w10, w10, #0x4
 4e0:	6b0a011f 	cmp	w8, w10
 4e4:	54ffdaa8 	b.hi	38 <trap_handler+0x38>  // b.pmore
 4e8:	b8a86929 	ldrsw	x9, [x9, x8]
 4ec:	2a0903e0 	mov	w0, w9
 4f0:	910043ff 	add	sp, sp, #0x10
 4f4:	a8c153f3 	ldp	x19, x20, [sp], #16
 4f8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 4fc:	d65f03c0 	ret

0000000000000500 <store_i16>:
 500:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 504:	910003fd 	mov	x29, sp
 508:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 50c:	d2946413 	mov	x19, #0xa320                	// #41760
 510:	f2a016d3 	movk	x19, #0xb6, lsl #16
 514:	f2c00ab3 	movk	x19, #0x55, lsl #32
 518:	f87f6a73 	ldr	x19, [x19, xzr]
 51c:	cb3363f3 	sub	x19, sp, x19
 520:	d2800014 	mov	x20, #0x0                   	// #0
 524:	f2a00814 	movk	x20, #0x40, lsl #16
 528:	eb14027f 	cmp	x19, x20
 52c:	54ffd8ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 530:	d10043ff 	sub	sp, sp, #0x10
 534:	b90013e0 	str	w0, [sp, #16]
 538:	b9000fe1 	str	w1, [sp, #12]
 53c:	b94013e8 	ldr	w8, [sp, #16]
 540:	b9400fe9 	ldr	w9, [sp, #12]
 544:	d2946c0a 	mov	x10, #0xa360                	// #41824
 548:	f2a016ca 	movk	x10, #0xb6, lsl #16
 54c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 550:	f87f694a 	ldr	x10, [x10, xzr]
 554:	34ffd72a 	cbz	w10, 38 <trap_handler+0x38>
 558:	d294700b 	mov	x11, #0xa380                	// #41856
 55c:	f2a016cb 	movk	x11, #0xb6, lsl #16
 560:	f2c00aab 	movk	x11, #0x55, lsl #32
 564:	b87f696b 	ldr	w11, [x11, xzr]
 568:	5100096b 	sub	w11, w11, #0x2
 56c:	6b0b011f 	cmp	w8, w11
 570:	54ffd648 	b.hi	38 <trap_handler+0x38>  // b.pmore
 574:	78286949 	strh	w9, [x10, x8]
 578:	b94013e8 	ldr	w8, [sp, #16]
 57c:	d2946c09 	mov	x9, #0xa360                	// #41824
 580:	f2a016c9 	movk	x9, #0xb6, lsl #16
 584:	f2c00aa9 	movk	x9, #0x55, lsl #32
 588:	f87f6929 	ldr	x9, [x9, xzr]
 58c:	34ffd569 	cbz	w9, 38 <trap_handler+0x38>
 590:	d294700a 	mov	x10, #0xa380                	// #41856
 594:	f2a016ca 	movk	x10, #0xb6, lsl #16
 598:	f2c00aaa 	movk	x10, #0x55, lsl #32
 59c:	b87f694a 	ldr	w10, [x10, xzr]
 5a0:	5100094a 	sub	w10, w10, #0x2
 5a4:	6b0a011f 	cmp	w8, w10
 5a8:	54ffd488 	b.hi	38 <trap_handler+0x38>  // b.pmore
 5ac:	78686929 	ldrh	w9, [x9, x8]
 5b0:	2a0903e0 	mov	w0, w9
 5b4:	910043ff 	add	sp, sp, #0x10
 5b8:	a8c153f3 	ldp	x19, x20, [sp], #16
 5bc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 5c0:	d65f03c0 	ret

00000000000005c4 <store_i8>:
 5c4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 5c8:	910003fd 	mov	x29, sp
 5cc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 5d0:	d2946413 	mov	x19, #0xa320                	// #41760
 5d4:	f2a016d3 	movk	x19, #0xb6, lsl #16
 5d8:	f2c00ab3 	movk	x19, #0x55, lsl #32
 5dc:	f87f6a73 	ldr	x19, [x19, xzr]
 5e0:	cb3363f3 	sub	x19, sp, x19
 5e4:	d2800014 	mov	x20, #0x0                   	// #0
 5e8:	f2a00814 	movk	x20, #0x40, lsl #16
 5ec:	eb14027f 	cmp	x19, x20
 5f0:	54ffd28b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 5f4:	d10043ff 	sub	sp, sp, #0x10
 5f8:	b90013e0 	str	w0, [sp, #16]
 5fc:	b9000fe1 	str	w1, [sp, #12]
 600:	b94013e8 	ldr	w8, [sp, #16]
 604:	b9400fe9 	ldr	w9, [sp, #12]
 608:	d2946c0a 	mov	x10, #0xa360                	// #41824
 60c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 610:	f2c00aaa 	movk	x10, #0x55, lsl #32
 614:	f87f694a 	ldr	x10, [x10, xzr]
 618:	34ffd10a 	cbz	w10, 38 <trap_handler+0x38>
 61c:	d294700b 	mov	x11, #0xa380                	// #41856
 620:	f2a016cb 	movk	x11, #0xb6, lsl #16
 624:	f2c00aab 	movk	x11, #0x55, lsl #32
 628:	b87f696b 	ldr	w11, [x11, xzr]
 62c:	5100056b 	sub	w11, w11, #0x1
 630:	6b0b011f 	cmp	w8, w11
 634:	54ffd028 	b.hi	38 <trap_handler+0x38>  // b.pmore
 638:	38287949 	strb	w9, [x10, x8, lsl #0]
 63c:	b94013e8 	ldr	w8, [sp, #16]
 640:	d2946c09 	mov	x9, #0xa360                	// #41824
 644:	f2a016c9 	movk	x9, #0xb6, lsl #16
 648:	f2c00aa9 	movk	x9, #0x55, lsl #32
 64c:	f87f6929 	ldr	x9, [x9, xzr]
 650:	34ffcf49 	cbz	w9, 38 <trap_handler+0x38>
 654:	d294700a 	mov	x10, #0xa380                	// #41856
 658:	f2a016ca 	movk	x10, #0xb6, lsl #16
 65c:	f2c00aaa 	movk	x10, #0x55, lsl #32
 660:	b87f694a 	ldr	w10, [x10, xzr]
 664:	5100054a 	sub	w10, w10, #0x1
 668:	6b0a011f 	cmp	w8, w10
 66c:	54ffce68 	b.hi	38 <trap_handler+0x38>  // b.pmore
 670:	38687929 	ldrb	w9, [x9, x8, lsl #0]
 674:	2a0903e0 	mov	w0, w9
 678:	910043ff 	add	sp, sp, #0x10
 67c:	a8c153f3 	ldp	x19, x20, [sp], #16
 680:	a8c17bfd 	ldp	x29, x30, [sp], #16
 684:	d65f03c0 	ret

0000000000000688 <loop>:
 688:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 68c:	910003fd 	mov	x29, sp
 690:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 694:	d2946413 	mov	x19, #0xa320                	// #41760
 698:	f2a016d3 	movk	x19, #0xb6, lsl #16
 69c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 6a0:	f87f6a73 	ldr	x19, [x19, xzr]
 6a4:	cb3363f3 	sub	x19, sp, x19
 6a8:	d2800014 	mov	x20, #0x0                   	// #0
 6ac:	f2a00814 	movk	x20, #0x40, lsl #16
 6b0:	eb14027f 	cmp	x19, x20
 6b4:	54ffcc6b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 6b8:	d10043ff 	sub	sp, sp, #0x10
 6bc:	b90013ff 	str	wzr, [sp, #16]
 6c0:	52800028 	mov	w8, #0x1                   	// #1
 6c4:	d2947209 	mov	x9, #0xa390                	// #41872
 6c8:	f2a016c9 	movk	x9, #0xb6, lsl #16
 6cc:	f2c00aa9 	movk	x9, #0x55, lsl #32
 6d0:	f87f6929 	ldr	x9, [x9, xzr]
 6d4:	d2946600 	mov	x0, #0xa330                	// #41776
 6d8:	f2a016c0 	movk	x0, #0xb6, lsl #16
 6dc:	f2c00aa0 	movk	x0, #0x55, lsl #32
 6e0:	f87f6800 	ldr	x0, [x0, xzr]
 6e4:	aa0803e1 	mov	x1, x8
 6e8:	d63f0120 	blr	x9
 6ec:	aa0003e8 	mov	x8, x0
 6f0:	d2946209 	mov	x9, #0xa310                	// #41744
 6f4:	f2a016c9 	movk	x9, #0xb6, lsl #16
 6f8:	f2c00aa9 	movk	x9, #0x55, lsl #32
 6fc:	f87f6929 	ldr	x9, [x9, xzr]
 700:	91000129 	add	x9, x9, #0x0
 704:	f87f6929 	ldr	x9, [x9, xzr]
 708:	5280020a 	mov	w10, #0x10                  	// #16
 70c:	4b0a0129 	sub	w9, w9, w10
 710:	b90013e9 	str	w9, [sp, #16]
 714:	b94013e9 	ldr	w9, [sp, #16]
 718:	5280014a 	mov	w10, #0xa                   	// #10
 71c:	d2946c0b 	mov	x11, #0xa360                	// #41824
 720:	f2a016cb 	movk	x11, #0xb6, lsl #16
 724:	f2c00aab 	movk	x11, #0x55, lsl #32
 728:	f87f696b 	ldr	x11, [x11, xzr]
 72c:	34ffc86b 	cbz	w11, 38 <trap_handler+0x38>
 730:	91003129 	add	x9, x9, #0xc
 734:	d294700c 	mov	x12, #0xa380                	// #41856
 738:	f2a016cc 	movk	x12, #0xb6, lsl #16
 73c:	f2c00aac 	movk	x12, #0x55, lsl #32
 740:	b87f698c 	ldr	w12, [x12, xzr]
 744:	5100118c 	sub	w12, w12, #0x4
 748:	6b0c013f 	cmp	w9, w12
 74c:	54ffc768 	b.hi	38 <trap_handler+0x38>  // b.pmore
 750:	b829696a 	str	w10, [x11, x9]
 754:	b94013e9 	ldr	w9, [sp, #16]
 758:	d2946c0a 	mov	x10, #0xa360                	// #41824
 75c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 760:	f2c00aaa 	movk	x10, #0x55, lsl #32
 764:	f87f694a 	ldr	x10, [x10, xzr]
 768:	b4ffc68a 	cbz	x10, 38 <trap_handler+0x38>
 76c:	91003129 	add	x9, x9, #0xc
 770:	d294700b 	mov	x11, #0xa380                	// #41856
 774:	f2a016cb 	movk	x11, #0xb6, lsl #16
 778:	f2c00aab 	movk	x11, #0x55, lsl #32
 77c:	b87f696b 	ldr	w11, [x11, xzr]
 780:	5100116b 	sub	w11, w11, #0x4
 784:	6b0b013f 	cmp	w9, w11
 788:	54ffc588 	b.hi	38 <trap_handler+0x38>  // b.pmore
 78c:	b8a9694a 	ldrsw	x10, [x10, x9]
 790:	52800289 	mov	w9, #0x14                  	// #20
 794:	6b09015f 	cmp	w10, w9
 798:	5400006b 	b.lt	7a4 <loop+0x11c>  // b.tstop
 79c:	5280000a 	mov	w10, #0x0                   	// #0
 7a0:	14000002 	b	7a8 <loop+0x120>
 7a4:	5280002a 	mov	w10, #0x1                   	// #1
 7a8:	52800029 	mov	w9, #0x1                   	// #1
 7ac:	0a09014a 	and	w10, w10, w9
 7b0:	3400006a 	cbz	w10, 7bc <loop+0x134>
 7b4:	5280000a 	mov	w10, #0x0                   	// #0
 7b8:	14000002 	b	7c0 <loop+0x138>
 7bc:	5280002a 	mov	w10, #0x1                   	// #1
 7c0:	3500044a 	cbnz	w10, 848 <loop+0x1c0>
 7c4:	b94013e9 	ldr	w9, [sp, #16]
 7c8:	b94013ea 	ldr	w10, [sp, #16]
 7cc:	d2946c0b 	mov	x11, #0xa360                	// #41824
 7d0:	f2a016cb 	movk	x11, #0xb6, lsl #16
 7d4:	f2c00aab 	movk	x11, #0x55, lsl #32
 7d8:	f87f696b 	ldr	x11, [x11, xzr]
 7dc:	b4ffc2eb 	cbz	x11, 38 <trap_handler+0x38>
 7e0:	9100314a 	add	x10, x10, #0xc
 7e4:	d294700c 	mov	x12, #0xa380                	// #41856
 7e8:	f2a016cc 	movk	x12, #0xb6, lsl #16
 7ec:	f2c00aac 	movk	x12, #0x55, lsl #32
 7f0:	b87f698c 	ldr	w12, [x12, xzr]
 7f4:	5100118c 	sub	w12, w12, #0x4
 7f8:	6b0c015f 	cmp	w10, w12
 7fc:	54ffc1e8 	b.hi	38 <trap_handler+0x38>  // b.pmore
 800:	b8aa696b 	ldrsw	x11, [x11, x10]
 804:	5280002a 	mov	w10, #0x1                   	// #1
 808:	0b0a016b 	add	w11, w11, w10
 80c:	d2946c0a 	mov	x10, #0xa360                	// #41824
 810:	f2a016ca 	movk	x10, #0xb6, lsl #16
 814:	f2c00aaa 	movk	x10, #0x55, lsl #32
 818:	f87f694a 	ldr	x10, [x10, xzr]
 81c:	34ffc0ea 	cbz	w10, 38 <trap_handler+0x38>
 820:	91003129 	add	x9, x9, #0xc
 824:	d294700c 	mov	x12, #0xa380                	// #41856
 828:	f2a016cc 	movk	x12, #0xb6, lsl #16
 82c:	f2c00aac 	movk	x12, #0x55, lsl #32
 830:	b87f698c 	ldr	w12, [x12, xzr]
 834:	5100118c 	sub	w12, w12, #0x4
 838:	6b0c013f 	cmp	w9, w12
 83c:	54ffbfe8 	b.hi	38 <trap_handler+0x38>  // b.pmore
 840:	b829694b 	str	w11, [x10, x9]
 844:	17ffffc4 	b	754 <loop+0xcc>
 848:	52800009 	mov	w9, #0x0                   	// #0
 84c:	b400003f 	cbz	xzr, 850 <loop+0x1c8>
 850:	2a0903e0 	mov	w0, w9
 854:	910043ff 	add	sp, sp, #0x10
 858:	a8c153f3 	ldp	x19, x20, [sp], #16
 85c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 860:	d65f03c0 	ret
