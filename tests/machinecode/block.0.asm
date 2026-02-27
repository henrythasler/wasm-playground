
./tests/machinecode/block.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000050 type-i32
00000000000000ac g     F .text	0000000000000050 type-i64
00000000000000fc g     F .text	0000000000000054 type-i32-value
0000000000000150 g     F .text	0000000000000054 type-i64-value
00000000000001a4 g     F .text	0000000000000060 as-block-first
0000000000000204 g     F .text	0000000000000060 as-block-first-value
0000000000000264 g     F .text	0000000000000054 as-binary-left
00000000000002b8 g     F .text	0000000000000058 as-binary-right
0000000000000310 g     F .text	000000000000005c as-test-operand
000000000000036c g     F .text	0000000000000064 as-compare-left
00000000000003d0 g     F .text	0000000000000068 as-compare-right
0000000000000438 g     F .text	0000000000000058 as-br_if-value
0000000000000490 g     F .text	000000000000005c as-br_if-value-cond
00000000000004ec g     F .text	0000000000000060 nested-br-value
000000000000054c g     F .text	0000000000000068 nested-br_if-value


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
 0090 29008052 69000035 0801c05a 0811c05a  )..Ri..5...Z...Z
 00a0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 00b0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 00c0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 00d0 1408a0f2 7f0214eb 4bfbff54 080080d2  ........K..T....
 00e0 29008052 69000035 0801c0da 0811c0da  )..Ri..5........
 00f0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0100 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0110 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0120 1408a0f2 7f0214eb cbf8ff54 28008052  ...........T(..R
 0130 29008052 69000035 0801c05a 0811c05a  )..Ri..5...Z...Z
 0140 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0150 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0160 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0170 140080d2 1408a0f2 7f0214eb 2bf6ff54  ............+..T
 0180 480080d2 29008052 69000035 0801c0da  H...)..Ri..5....
 0190 0811c0da e00308aa f353c1a8 fd7bc1a8  .........S...{..
 01a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01d0 8bf3ff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 01e0 68000035 48008052 5f0000b4 68008052  h..5H..R_...h..R
 01f0 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0200 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0210 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0220 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0230 8bf0ff54 ff4300d1 e01300b9 48018052  ...T.C......H..R
 0240 e91340b9 69000035 68018052 3f0000b4  ..@.i..5h..R?...
 0250 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0260 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0270 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0280 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0290 8bedff54 28008052 29008052 69000035  ...T(..R)..Ri..5
 02a0 49018052 0801090b e003082a f353c1a8  I..R.......*.S..
 02b0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 02c0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 02d0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 02e0 7f0214eb ebeaff54 48018052 29008052  .......TH..R)..R
 02f0 2a008052 6a000035 0801094b e903082a  *..Rj..5...K...*
 0300 e003092a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0310 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0320 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0330 140080d2 1408a0f2 7f0214eb 2be8ff54  ............+..T
 0340 08008052 29008052 a9000035 68000034  ...R)..R...5h..4
 0350 08008052 02000014 28008052 e003082a  ...R....(..R...*
 0360 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0370 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0380 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0390 1408a0f2 7f0214eb 4be5ff54 28008052  ........K..T(..R
 03a0 29008052 e9000035 49018052 1f01096b  )..R...5I..R...k
 03b0 69000054 08008052 02000014 28008052  i..T...R....(..R
 03c0 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 03d0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 03e0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 03f0 140080d2 1408a0f2 7f0214eb 2be2ff54  ............+..T
 0400 48018052 29008052 2a008052 ea000035  H..R)..R*..R...5
 0410 1f01096b 69000054 08008052 02000014  ...ki..T...R....
 0420 28008052 e903082a e003092a f353c1a8  (..R...*...*.S..
 0430 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0440 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0450 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0460 7f0214eb ebdeff54 08018052 bf0000b4  .......T...R....
 0470 29008052 e803082a 49000035 e8008052  )..R...*I..5...R
 0480 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0490 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 04a0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 04b0 140080d2 1408a0f2 7f0214eb 2bdcff54  ............+..T
 04c0 c8008052 29018052 bf0000b4 e903082a  ...R)..R.......*
 04d0 69000035 e8008052 e903082a e003092a  i..5...R...*...*
 04e0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 04f0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0500 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0510 1408a0f2 7f0214eb 4bd9ff54 28008052  ........K..T(..R
 0520 49008052 89008052 09018052 7f0000b4  I..R...R...R....
 0530 3f0000b4 09028052 0801090b e003082a  ?......R.......*
 0540 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0550 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0560 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0570 1408a0f2 7f0214eb 4bd6ff54 28008052  ........K..T(..R
 0580 49008052 89008052 09018052 bf0000b4  I..R...R...R....
 0590 2a008052 4a000035 09048052 09028052  *..RJ..5...R...R
 05a0 0801090b e003082a f353c1a8 fd7bc1a8  .......*.S...{..
 05b0 c0035fd6                             .._.            

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

000000000000005c <type-i32>:
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
  90:	52800029 	mov	w9, #0x1                   	// #1
  94:	35000069 	cbnz	w9, a0 <type-i32+0x44>
  98:	5ac00108 	rbit	w8, w8
  9c:	5ac01108 	clz	w8, w8
  a0:	a8c153f3 	ldp	x19, x20, [sp], #16
  a4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  a8:	d65f03c0 	ret

00000000000000ac <type-i64>:
  ac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  b0:	910003fd 	mov	x29, sp
  b4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  b8:	d2946413 	mov	x19, #0xa320                	// #41760
  bc:	f2a016d3 	movk	x19, #0xb6, lsl #16
  c0:	f2c00ab3 	movk	x19, #0x55, lsl #32
  c4:	f87f6a73 	ldr	x19, [x19, xzr]
  c8:	cb3363f3 	sub	x19, sp, x19
  cc:	d2800014 	mov	x20, #0x0                   	// #0
  d0:	f2a00814 	movk	x20, #0x40, lsl #16
  d4:	eb14027f 	cmp	x19, x20
  d8:	54fffb4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  dc:	d2800008 	mov	x8, #0x0                   	// #0
  e0:	52800029 	mov	w9, #0x1                   	// #1
  e4:	35000069 	cbnz	w9, f0 <type-i64+0x44>
  e8:	dac00108 	rbit	x8, x8
  ec:	dac01108 	clz	x8, x8
  f0:	a8c153f3 	ldp	x19, x20, [sp], #16
  f4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  f8:	d65f03c0 	ret

00000000000000fc <type-i32-value>:
  fc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 100:	910003fd 	mov	x29, sp
 104:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 108:	d2946413 	mov	x19, #0xa320                	// #41760
 10c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 110:	f2c00ab3 	movk	x19, #0x55, lsl #32
 114:	f87f6a73 	ldr	x19, [x19, xzr]
 118:	cb3363f3 	sub	x19, sp, x19
 11c:	d2800014 	mov	x20, #0x0                   	// #0
 120:	f2a00814 	movk	x20, #0x40, lsl #16
 124:	eb14027f 	cmp	x19, x20
 128:	54fff8cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 12c:	52800028 	mov	w8, #0x1                   	// #1
 130:	52800029 	mov	w9, #0x1                   	// #1
 134:	35000069 	cbnz	w9, 140 <type-i32-value+0x44>
 138:	5ac00108 	rbit	w8, w8
 13c:	5ac01108 	clz	w8, w8
 140:	2a0803e0 	mov	w0, w8
 144:	a8c153f3 	ldp	x19, x20, [sp], #16
 148:	a8c17bfd 	ldp	x29, x30, [sp], #16
 14c:	d65f03c0 	ret

0000000000000150 <type-i64-value>:
 150:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 154:	910003fd 	mov	x29, sp
 158:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 15c:	d2946413 	mov	x19, #0xa320                	// #41760
 160:	f2a016d3 	movk	x19, #0xb6, lsl #16
 164:	f2c00ab3 	movk	x19, #0x55, lsl #32
 168:	f87f6a73 	ldr	x19, [x19, xzr]
 16c:	cb3363f3 	sub	x19, sp, x19
 170:	d2800014 	mov	x20, #0x0                   	// #0
 174:	f2a00814 	movk	x20, #0x40, lsl #16
 178:	eb14027f 	cmp	x19, x20
 17c:	54fff62b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 180:	d2800048 	mov	x8, #0x2                   	// #2
 184:	52800029 	mov	w9, #0x1                   	// #1
 188:	35000069 	cbnz	w9, 194 <type-i64-value+0x44>
 18c:	dac00108 	rbit	x8, x8
 190:	dac01108 	clz	x8, x8
 194:	aa0803e0 	mov	x0, x8
 198:	a8c153f3 	ldp	x19, x20, [sp], #16
 19c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a0:	d65f03c0 	ret

00000000000001a4 <as-block-first>:
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
 1e0:	35000068 	cbnz	w8, 1ec <as-block-first+0x48>
 1e4:	52800048 	mov	w8, #0x2                   	// #2
 1e8:	b400005f 	cbz	xzr, 1f0 <as-block-first+0x4c>
 1ec:	52800068 	mov	w8, #0x3                   	// #3
 1f0:	2a0803e0 	mov	w0, w8
 1f4:	910043ff 	add	sp, sp, #0x10
 1f8:	a8c153f3 	ldp	x19, x20, [sp], #16
 1fc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 200:	d65f03c0 	ret

0000000000000204 <as-block-first-value>:
 204:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 208:	910003fd 	mov	x29, sp
 20c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 210:	d2946413 	mov	x19, #0xa320                	// #41760
 214:	f2a016d3 	movk	x19, #0xb6, lsl #16
 218:	f2c00ab3 	movk	x19, #0x55, lsl #32
 21c:	f87f6a73 	ldr	x19, [x19, xzr]
 220:	cb3363f3 	sub	x19, sp, x19
 224:	d2800014 	mov	x20, #0x0                   	// #0
 228:	f2a00814 	movk	x20, #0x40, lsl #16
 22c:	eb14027f 	cmp	x19, x20
 230:	54fff08b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 234:	d10043ff 	sub	sp, sp, #0x10
 238:	b90013e0 	str	w0, [sp, #16]
 23c:	52800148 	mov	w8, #0xa                   	// #10
 240:	b94013e9 	ldr	w9, [sp, #16]
 244:	35000069 	cbnz	w9, 250 <as-block-first-value+0x4c>
 248:	52800168 	mov	w8, #0xb                   	// #11
 24c:	b400003f 	cbz	xzr, 250 <as-block-first-value+0x4c>
 250:	2a0803e0 	mov	w0, w8
 254:	910043ff 	add	sp, sp, #0x10
 258:	a8c153f3 	ldp	x19, x20, [sp], #16
 25c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 260:	d65f03c0 	ret

0000000000000264 <as-binary-left>:
 264:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 268:	910003fd 	mov	x29, sp
 26c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 270:	d2946413 	mov	x19, #0xa320                	// #41760
 274:	f2a016d3 	movk	x19, #0xb6, lsl #16
 278:	f2c00ab3 	movk	x19, #0x55, lsl #32
 27c:	f87f6a73 	ldr	x19, [x19, xzr]
 280:	cb3363f3 	sub	x19, sp, x19
 284:	d2800014 	mov	x20, #0x0                   	// #0
 288:	f2a00814 	movk	x20, #0x40, lsl #16
 28c:	eb14027f 	cmp	x19, x20
 290:	54ffed8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 294:	52800028 	mov	w8, #0x1                   	// #1
 298:	52800029 	mov	w9, #0x1                   	// #1
 29c:	35000069 	cbnz	w9, 2a8 <as-binary-left+0x44>
 2a0:	52800149 	mov	w9, #0xa                   	// #10
 2a4:	0b090108 	add	w8, w8, w9
 2a8:	2a0803e0 	mov	w0, w8
 2ac:	a8c153f3 	ldp	x19, x20, [sp], #16
 2b0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2b4:	d65f03c0 	ret

00000000000002b8 <as-binary-right>:
 2b8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 2bc:	910003fd 	mov	x29, sp
 2c0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 2c4:	d2946413 	mov	x19, #0xa320                	// #41760
 2c8:	f2a016d3 	movk	x19, #0xb6, lsl #16
 2cc:	f2c00ab3 	movk	x19, #0x55, lsl #32
 2d0:	f87f6a73 	ldr	x19, [x19, xzr]
 2d4:	cb3363f3 	sub	x19, sp, x19
 2d8:	d2800014 	mov	x20, #0x0                   	// #0
 2dc:	f2a00814 	movk	x20, #0x40, lsl #16
 2e0:	eb14027f 	cmp	x19, x20
 2e4:	54ffeaeb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 2e8:	52800148 	mov	w8, #0xa                   	// #10
 2ec:	52800029 	mov	w9, #0x1                   	// #1
 2f0:	5280002a 	mov	w10, #0x1                   	// #1
 2f4:	3500006a 	cbnz	w10, 300 <as-binary-right+0x48>
 2f8:	4b090108 	sub	w8, w8, w9
 2fc:	2a0803e9 	mov	w9, w8
 300:	2a0903e0 	mov	w0, w9
 304:	a8c153f3 	ldp	x19, x20, [sp], #16
 308:	a8c17bfd 	ldp	x29, x30, [sp], #16
 30c:	d65f03c0 	ret

0000000000000310 <as-test-operand>:
 310:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 314:	910003fd 	mov	x29, sp
 318:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 31c:	d2946413 	mov	x19, #0xa320                	// #41760
 320:	f2a016d3 	movk	x19, #0xb6, lsl #16
 324:	f2c00ab3 	movk	x19, #0x55, lsl #32
 328:	f87f6a73 	ldr	x19, [x19, xzr]
 32c:	cb3363f3 	sub	x19, sp, x19
 330:	d2800014 	mov	x20, #0x0                   	// #0
 334:	f2a00814 	movk	x20, #0x40, lsl #16
 338:	eb14027f 	cmp	x19, x20
 33c:	54ffe82b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 340:	52800008 	mov	w8, #0x0                   	// #0
 344:	52800029 	mov	w9, #0x1                   	// #1
 348:	350000a9 	cbnz	w9, 35c <as-test-operand+0x4c>
 34c:	34000068 	cbz	w8, 358 <as-test-operand+0x48>
 350:	52800008 	mov	w8, #0x0                   	// #0
 354:	14000002 	b	35c <as-test-operand+0x4c>
 358:	52800028 	mov	w8, #0x1                   	// #1
 35c:	2a0803e0 	mov	w0, w8
 360:	a8c153f3 	ldp	x19, x20, [sp], #16
 364:	a8c17bfd 	ldp	x29, x30, [sp], #16
 368:	d65f03c0 	ret

000000000000036c <as-compare-left>:
 36c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 370:	910003fd 	mov	x29, sp
 374:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 378:	d2946413 	mov	x19, #0xa320                	// #41760
 37c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 380:	f2c00ab3 	movk	x19, #0x55, lsl #32
 384:	f87f6a73 	ldr	x19, [x19, xzr]
 388:	cb3363f3 	sub	x19, sp, x19
 38c:	d2800014 	mov	x20, #0x0                   	// #0
 390:	f2a00814 	movk	x20, #0x40, lsl #16
 394:	eb14027f 	cmp	x19, x20
 398:	54ffe54b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 39c:	52800028 	mov	w8, #0x1                   	// #1
 3a0:	52800029 	mov	w9, #0x1                   	// #1
 3a4:	350000e9 	cbnz	w9, 3c0 <as-compare-left+0x54>
 3a8:	52800149 	mov	w9, #0xa                   	// #10
 3ac:	6b09011f 	cmp	w8, w9
 3b0:	54000069 	b.ls	3bc <as-compare-left+0x50>  // b.plast
 3b4:	52800008 	mov	w8, #0x0                   	// #0
 3b8:	14000002 	b	3c0 <as-compare-left+0x54>
 3bc:	52800028 	mov	w8, #0x1                   	// #1
 3c0:	2a0803e0 	mov	w0, w8
 3c4:	a8c153f3 	ldp	x19, x20, [sp], #16
 3c8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 3cc:	d65f03c0 	ret

00000000000003d0 <as-compare-right>:
 3d0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 3d4:	910003fd 	mov	x29, sp
 3d8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 3dc:	d2946413 	mov	x19, #0xa320                	// #41760
 3e0:	f2a016d3 	movk	x19, #0xb6, lsl #16
 3e4:	f2c00ab3 	movk	x19, #0x55, lsl #32
 3e8:	f87f6a73 	ldr	x19, [x19, xzr]
 3ec:	cb3363f3 	sub	x19, sp, x19
 3f0:	d2800014 	mov	x20, #0x0                   	// #0
 3f4:	f2a00814 	movk	x20, #0x40, lsl #16
 3f8:	eb14027f 	cmp	x19, x20
 3fc:	54ffe22b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 400:	52800148 	mov	w8, #0xa                   	// #10
 404:	52800029 	mov	w9, #0x1                   	// #1
 408:	5280002a 	mov	w10, #0x1                   	// #1
 40c:	350000ea 	cbnz	w10, 428 <as-compare-right+0x58>
 410:	6b09011f 	cmp	w8, w9
 414:	54000069 	b.ls	420 <as-compare-right+0x50>  // b.plast
 418:	52800008 	mov	w8, #0x0                   	// #0
 41c:	14000002 	b	424 <as-compare-right+0x54>
 420:	52800028 	mov	w8, #0x1                   	// #1
 424:	2a0803e9 	mov	w9, w8
 428:	2a0903e0 	mov	w0, w9
 42c:	a8c153f3 	ldp	x19, x20, [sp], #16
 430:	a8c17bfd 	ldp	x29, x30, [sp], #16
 434:	d65f03c0 	ret

0000000000000438 <as-br_if-value>:
 438:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 43c:	910003fd 	mov	x29, sp
 440:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 444:	d2946413 	mov	x19, #0xa320                	// #41760
 448:	f2a016d3 	movk	x19, #0xb6, lsl #16
 44c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 450:	f87f6a73 	ldr	x19, [x19, xzr]
 454:	cb3363f3 	sub	x19, sp, x19
 458:	d2800014 	mov	x20, #0x0                   	// #0
 45c:	f2a00814 	movk	x20, #0x40, lsl #16
 460:	eb14027f 	cmp	x19, x20
 464:	54ffdeeb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 468:	52800108 	mov	w8, #0x8                   	// #8
 46c:	b40000bf 	cbz	xzr, 480 <as-br_if-value+0x48>
 470:	52800029 	mov	w9, #0x1                   	// #1
 474:	2a0803e8 	mov	w8, w8
 478:	35000049 	cbnz	w9, 480 <as-br_if-value+0x48>
 47c:	528000e8 	mov	w8, #0x7                   	// #7
 480:	2a0803e0 	mov	w0, w8
 484:	a8c153f3 	ldp	x19, x20, [sp], #16
 488:	a8c17bfd 	ldp	x29, x30, [sp], #16
 48c:	d65f03c0 	ret

0000000000000490 <as-br_if-value-cond>:
 490:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 494:	910003fd 	mov	x29, sp
 498:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 49c:	d2946413 	mov	x19, #0xa320                	// #41760
 4a0:	f2a016d3 	movk	x19, #0xb6, lsl #16
 4a4:	f2c00ab3 	movk	x19, #0x55, lsl #32
 4a8:	f87f6a73 	ldr	x19, [x19, xzr]
 4ac:	cb3363f3 	sub	x19, sp, x19
 4b0:	d2800014 	mov	x20, #0x0                   	// #0
 4b4:	f2a00814 	movk	x20, #0x40, lsl #16
 4b8:	eb14027f 	cmp	x19, x20
 4bc:	54ffdc2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 4c0:	528000c8 	mov	w8, #0x6                   	// #6
 4c4:	52800129 	mov	w9, #0x9                   	// #9
 4c8:	b40000bf 	cbz	xzr, 4dc <as-br_if-value-cond+0x4c>
 4cc:	2a0803e9 	mov	w9, w8
 4d0:	35000069 	cbnz	w9, 4dc <as-br_if-value-cond+0x4c>
 4d4:	528000e8 	mov	w8, #0x7                   	// #7
 4d8:	2a0803e9 	mov	w9, w8
 4dc:	2a0903e0 	mov	w0, w9
 4e0:	a8c153f3 	ldp	x19, x20, [sp], #16
 4e4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 4e8:	d65f03c0 	ret

00000000000004ec <nested-br-value>:
 4ec:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 4f0:	910003fd 	mov	x29, sp
 4f4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 4f8:	d2946413 	mov	x19, #0xa320                	// #41760
 4fc:	f2a016d3 	movk	x19, #0xb6, lsl #16
 500:	f2c00ab3 	movk	x19, #0x55, lsl #32
 504:	f87f6a73 	ldr	x19, [x19, xzr]
 508:	cb3363f3 	sub	x19, sp, x19
 50c:	d2800014 	mov	x20, #0x0                   	// #0
 510:	f2a00814 	movk	x20, #0x40, lsl #16
 514:	eb14027f 	cmp	x19, x20
 518:	54ffd94b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 51c:	52800028 	mov	w8, #0x1                   	// #1
 520:	52800049 	mov	w9, #0x2                   	// #2
 524:	52800089 	mov	w9, #0x4                   	// #4
 528:	52800109 	mov	w9, #0x8                   	// #8
 52c:	b400007f 	cbz	xzr, 538 <nested-br-value+0x4c>
 530:	b400003f 	cbz	xzr, 534 <nested-br-value+0x48>
 534:	52800209 	mov	w9, #0x10                  	// #16
 538:	0b090108 	add	w8, w8, w9
 53c:	2a0803e0 	mov	w0, w8
 540:	a8c153f3 	ldp	x19, x20, [sp], #16
 544:	a8c17bfd 	ldp	x29, x30, [sp], #16
 548:	d65f03c0 	ret

000000000000054c <nested-br_if-value>:
 54c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 550:	910003fd 	mov	x29, sp
 554:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 558:	d2946413 	mov	x19, #0xa320                	// #41760
 55c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 560:	f2c00ab3 	movk	x19, #0x55, lsl #32
 564:	f87f6a73 	ldr	x19, [x19, xzr]
 568:	cb3363f3 	sub	x19, sp, x19
 56c:	d2800014 	mov	x20, #0x0                   	// #0
 570:	f2a00814 	movk	x20, #0x40, lsl #16
 574:	eb14027f 	cmp	x19, x20
 578:	54ffd64b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 57c:	52800028 	mov	w8, #0x1                   	// #1
 580:	52800049 	mov	w9, #0x2                   	// #2
 584:	52800089 	mov	w9, #0x4                   	// #4
 588:	52800109 	mov	w9, #0x8                   	// #8
 58c:	b40000bf 	cbz	xzr, 5a0 <nested-br_if-value+0x54>
 590:	5280002a 	mov	w10, #0x1                   	// #1
 594:	3500004a 	cbnz	w10, 59c <nested-br_if-value+0x50>
 598:	52800409 	mov	w9, #0x20                  	// #32
 59c:	52800209 	mov	w9, #0x10                  	// #16
 5a0:	0b090108 	add	w8, w8, w9
 5a4:	2a0803e0 	mov	w0, w8
 5a8:	a8c153f3 	ldp	x19, x20, [sp], #16
 5ac:	a8c17bfd 	ldp	x29, x30, [sp], #16
 5b0:	d65f03c0 	ret
