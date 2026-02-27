
./tests/machinecode/loop.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000054 as-if-then
00000000000000b0 g     F .text	0000000000000054 as-if-else
0000000000000104 g     F .text	000000000000004c as-br_if-first
0000000000000150 g     F .text	000000000000004c as-br_if-last
000000000000019c g     F .text	00000000000000b8 effects
0000000000000254 g     F .text	0000000000000098 while
00000000000002ec g     F .text	00000000000000ac for


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 28008052  ...........T(..R
 0090 68000034 28008052 02000014 48008052  h..4(..R....H..R
 00a0 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 00b0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00c0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 00d0 140080d2 1408a0f2 7f0214eb 2bfbff54  ............+..T
 00e0 28008052 68000034 48008052 02000014  (..Rh..4H..R....
 00f0 28008052 e003082a f353c1a8 fd7bc1a8  (..R...*.S...{..
 0100 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0110 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0120 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0130 8bf8ff54 28008052 49008052 29000035  ...T(..RI..R)..5
 0140 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0150 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0160 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0170 140080d2 1408a0f2 7f0214eb 2bf6ff54  ............+..T
 0180 48008052 29008052 29000035 e003082a  H..R)..R)..5...*
 0190 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 01a0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 01b0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 01c0 1408a0f2 7f0214eb cbf3ff54 ff4300d1  ...........T.C..
 01d0 ff1300b9 28008052 e81300b9 e81340b9  ....(..R......@.
 01e0 69008052 087d091b e81300b9 e81340b9  i..R.}........@.
 01f0 a9008052 0801094b e81300b9 e81340b9  ...R...K......@.
 0200 e9008052 087d091b e81300b9 bf0000b4  ...R.}..........
 0210 e81340b9 890c8052 087d091b e81300b9  ..@....R.}......
 0220 e81340b9 49fe9f52 e9ffbf72 1f01096b  ..@.I..R...r...k
 0230 60000054 08008052 02000014 28008052  `..T...R....(..R
 0240 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0250 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0260 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0270 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0280 0beeff54 ff4300d1 e00b00f9 ff0700f9  ...T.C..........
 0290 280080d2 e80700f9 e80b40f9 680000b4  (.........@.h...
 02a0 08008052 02000014 28008052 48010035  ...R....(..RH..5
 02b0 e80b40f9 e90740f9 087d099b e80700f9  ..@...@..}......
 02c0 e80b40f9 290080d2 080109cb e80b00f9  ..@.)...........
 02d0 f2ffff17 e80740f9 e00308aa ff430091  ......@......C..
 02e0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 02f0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0300 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0310 1408a0f2 7f0214eb 4be9ff54 ff8300d1  ........K..T....
 0320 e01300f9 ff0f00f9 ff0b00f9 280080d2  ............(...
 0330 e80f00f9 480080d2 e80b00f9 e80b40f9  ....H.........@.
 0340 e91340f9 1f0109eb 68000054 08008052  ..@.....h..T...R
 0350 02000014 28008052 48010035 e80f40f9  ....(..RH..5..@.
 0360 e90b40f9 087d099b e80f00f9 e80b40f9  ..@..}........@.
 0370 290080d2 0801098b e80b00f9 f0ffff17  )...............
 0380 e80f40f9 e00308aa ff830091 f353c1a8  ..@..........S..
 0390 fd7bc1a8 c0035fd6                    .{...._.        

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

000000000000005c <as-if-then>:
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
  8c:	52800028 	mov	w8, #0x1                   	// #1
  90:	34000068 	cbz	w8, 9c <as-if-then+0x40>
  94:	52800028 	mov	w8, #0x1                   	// #1
  98:	14000002 	b	a0 <as-if-then+0x44>
  9c:	52800048 	mov	w8, #0x2                   	// #2
  a0:	2a0803e0 	mov	w0, w8
  a4:	a8c153f3 	ldp	x19, x20, [sp], #16
  a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  ac:	d65f03c0 	ret

00000000000000b0 <as-if-else>:
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
  e0:	52800028 	mov	w8, #0x1                   	// #1
  e4:	34000068 	cbz	w8, f0 <as-if-else+0x40>
  e8:	52800048 	mov	w8, #0x2                   	// #2
  ec:	14000002 	b	f4 <as-if-else+0x44>
  f0:	52800028 	mov	w8, #0x1                   	// #1
  f4:	2a0803e0 	mov	w0, w8
  f8:	a8c153f3 	ldp	x19, x20, [sp], #16
  fc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 100:	d65f03c0 	ret

0000000000000104 <as-br_if-first>:
 104:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 108:	910003fd 	mov	x29, sp
 10c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 110:	d2946413 	mov	x19, #0xa320                	// #41760
 114:	f2a016d3 	movk	x19, #0xb6, lsl #16
 118:	f2c00ab3 	movk	x19, #0x55, lsl #32
 11c:	f87f6a73 	ldr	x19, [x19, xzr]
 120:	cb3363f3 	sub	x19, sp, x19
 124:	d2800014 	mov	x20, #0x0                   	// #0
 128:	f2a00814 	movk	x20, #0x40, lsl #16
 12c:	eb14027f 	cmp	x19, x20
 130:	54fff88b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 134:	52800028 	mov	w8, #0x1                   	// #1
 138:	52800049 	mov	w9, #0x2                   	// #2
 13c:	35000029 	cbnz	w9, 140 <as-br_if-first+0x3c>
 140:	2a0803e0 	mov	w0, w8
 144:	a8c153f3 	ldp	x19, x20, [sp], #16
 148:	a8c17bfd 	ldp	x29, x30, [sp], #16
 14c:	d65f03c0 	ret

0000000000000150 <as-br_if-last>:
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
 180:	52800048 	mov	w8, #0x2                   	// #2
 184:	52800029 	mov	w9, #0x1                   	// #1
 188:	35000029 	cbnz	w9, 18c <as-br_if-last+0x3c>
 18c:	2a0803e0 	mov	w0, w8
 190:	a8c153f3 	ldp	x19, x20, [sp], #16
 194:	a8c17bfd 	ldp	x29, x30, [sp], #16
 198:	d65f03c0 	ret

000000000000019c <effects>:
 19c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1a0:	910003fd 	mov	x29, sp
 1a4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1a8:	d2946413 	mov	x19, #0xa320                	// #41760
 1ac:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1b0:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1b4:	f87f6a73 	ldr	x19, [x19, xzr]
 1b8:	cb3363f3 	sub	x19, sp, x19
 1bc:	d2800014 	mov	x20, #0x0                   	// #0
 1c0:	f2a00814 	movk	x20, #0x40, lsl #16
 1c4:	eb14027f 	cmp	x19, x20
 1c8:	54fff3cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1cc:	d10043ff 	sub	sp, sp, #0x10
 1d0:	b90013ff 	str	wzr, [sp, #16]
 1d4:	52800028 	mov	w8, #0x1                   	// #1
 1d8:	b90013e8 	str	w8, [sp, #16]
 1dc:	b94013e8 	ldr	w8, [sp, #16]
 1e0:	52800069 	mov	w9, #0x3                   	// #3
 1e4:	1b097d08 	mul	w8, w8, w9
 1e8:	b90013e8 	str	w8, [sp, #16]
 1ec:	b94013e8 	ldr	w8, [sp, #16]
 1f0:	528000a9 	mov	w9, #0x5                   	// #5
 1f4:	4b090108 	sub	w8, w8, w9
 1f8:	b90013e8 	str	w8, [sp, #16]
 1fc:	b94013e8 	ldr	w8, [sp, #16]
 200:	528000e9 	mov	w9, #0x7                   	// #7
 204:	1b097d08 	mul	w8, w8, w9
 208:	b90013e8 	str	w8, [sp, #16]
 20c:	b40000bf 	cbz	xzr, 220 <effects+0x84>
 210:	b94013e8 	ldr	w8, [sp, #16]
 214:	52800c89 	mov	w9, #0x64                  	// #100
 218:	1b097d08 	mul	w8, w8, w9
 21c:	b90013e8 	str	w8, [sp, #16]
 220:	b94013e8 	ldr	w8, [sp, #16]
 224:	529ffe49 	mov	w9, #0xfff2                	// #65522
 228:	72bfffe9 	movk	w9, #0xffff, lsl #16
 22c:	6b09011f 	cmp	w8, w9
 230:	54000060 	b.eq	23c <effects+0xa0>  // b.none
 234:	52800008 	mov	w8, #0x0                   	// #0
 238:	14000002 	b	240 <effects+0xa4>
 23c:	52800028 	mov	w8, #0x1                   	// #1
 240:	2a0803e0 	mov	w0, w8
 244:	910043ff 	add	sp, sp, #0x10
 248:	a8c153f3 	ldp	x19, x20, [sp], #16
 24c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 250:	d65f03c0 	ret

0000000000000254 <while>:
 254:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 258:	910003fd 	mov	x29, sp
 25c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 260:	d2946413 	mov	x19, #0xa320                	// #41760
 264:	f2a016d3 	movk	x19, #0xb6, lsl #16
 268:	f2c00ab3 	movk	x19, #0x55, lsl #32
 26c:	f87f6a73 	ldr	x19, [x19, xzr]
 270:	cb3363f3 	sub	x19, sp, x19
 274:	d2800014 	mov	x20, #0x0                   	// #0
 278:	f2a00814 	movk	x20, #0x40, lsl #16
 27c:	eb14027f 	cmp	x19, x20
 280:	54ffee0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 284:	d10043ff 	sub	sp, sp, #0x10
 288:	f9000be0 	str	x0, [sp, #16]
 28c:	f90007ff 	str	xzr, [sp, #8]
 290:	d2800028 	mov	x8, #0x1                   	// #1
 294:	f90007e8 	str	x8, [sp, #8]
 298:	f9400be8 	ldr	x8, [sp, #16]
 29c:	b4000068 	cbz	x8, 2a8 <while+0x54>
 2a0:	52800008 	mov	w8, #0x0                   	// #0
 2a4:	14000002 	b	2ac <while+0x58>
 2a8:	52800028 	mov	w8, #0x1                   	// #1
 2ac:	35000148 	cbnz	w8, 2d4 <while+0x80>
 2b0:	f9400be8 	ldr	x8, [sp, #16]
 2b4:	f94007e9 	ldr	x9, [sp, #8]
 2b8:	9b097d08 	mul	x8, x8, x9
 2bc:	f90007e8 	str	x8, [sp, #8]
 2c0:	f9400be8 	ldr	x8, [sp, #16]
 2c4:	d2800029 	mov	x9, #0x1                   	// #1
 2c8:	cb090108 	sub	x8, x8, x9
 2cc:	f9000be8 	str	x8, [sp, #16]
 2d0:	17fffff2 	b	298 <while+0x44>
 2d4:	f94007e8 	ldr	x8, [sp, #8]
 2d8:	aa0803e0 	mov	x0, x8
 2dc:	910043ff 	add	sp, sp, #0x10
 2e0:	a8c153f3 	ldp	x19, x20, [sp], #16
 2e4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2e8:	d65f03c0 	ret

00000000000002ec <for>:
 2ec:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 2f0:	910003fd 	mov	x29, sp
 2f4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 2f8:	d2946413 	mov	x19, #0xa320                	// #41760
 2fc:	f2a016d3 	movk	x19, #0xb6, lsl #16
 300:	f2c00ab3 	movk	x19, #0x55, lsl #32
 304:	f87f6a73 	ldr	x19, [x19, xzr]
 308:	cb3363f3 	sub	x19, sp, x19
 30c:	d2800014 	mov	x20, #0x0                   	// #0
 310:	f2a00814 	movk	x20, #0x40, lsl #16
 314:	eb14027f 	cmp	x19, x20
 318:	54ffe94b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 31c:	d10083ff 	sub	sp, sp, #0x20
 320:	f90013e0 	str	x0, [sp, #32]
 324:	f9000fff 	str	xzr, [sp, #24]
 328:	f9000bff 	str	xzr, [sp, #16]
 32c:	d2800028 	mov	x8, #0x1                   	// #1
 330:	f9000fe8 	str	x8, [sp, #24]
 334:	d2800048 	mov	x8, #0x2                   	// #2
 338:	f9000be8 	str	x8, [sp, #16]
 33c:	f9400be8 	ldr	x8, [sp, #16]
 340:	f94013e9 	ldr	x9, [sp, #32]
 344:	eb09011f 	cmp	x8, x9
 348:	54000068 	b.hi	354 <for+0x68>  // b.pmore
 34c:	52800008 	mov	w8, #0x0                   	// #0
 350:	14000002 	b	358 <for+0x6c>
 354:	52800028 	mov	w8, #0x1                   	// #1
 358:	35000148 	cbnz	w8, 380 <for+0x94>
 35c:	f9400fe8 	ldr	x8, [sp, #24]
 360:	f9400be9 	ldr	x9, [sp, #16]
 364:	9b097d08 	mul	x8, x8, x9
 368:	f9000fe8 	str	x8, [sp, #24]
 36c:	f9400be8 	ldr	x8, [sp, #16]
 370:	d2800029 	mov	x9, #0x1                   	// #1
 374:	8b090108 	add	x8, x8, x9
 378:	f9000be8 	str	x8, [sp, #16]
 37c:	17fffff0 	b	33c <for+0x50>
 380:	f9400fe8 	ldr	x8, [sp, #24]
 384:	aa0803e0 	mov	x0, x8
 388:	910083ff 	add	sp, sp, #0x20
 38c:	a8c153f3 	ldp	x19, x20, [sp], #16
 390:	a8c17bfd 	ldp	x29, x30, [sp], #16
 394:	d65f03c0 	ret
