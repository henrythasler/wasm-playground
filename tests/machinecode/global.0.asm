
./tests/machinecode/global.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000048 get-a
00000000000000a4 g     F .text	0000000000000050 get-b
00000000000000f4 g     F .text	0000000000000058 get-x
000000000000014c g     F .text	0000000000000058 get-y
00000000000001a4 g     F .text	0000000000000064 set-x
0000000000000208 g     F .text	0000000000000064 set-y
000000000000026c g     F .text	0000000000000068 as-if-then
00000000000002d4 g     F .text	0000000000000068 as-if-else
000000000000033c g     F .text	000000000000006c as-br_if-first
00000000000003a8 g     F .text	000000000000006c as-br_if-last
0000000000000000 g     O .rodata	0000000000000020 globals


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 c8ff9f52  ...........T...R
 0090 e8ffbf72 e003082a f353c1a8 fd7bc1a8  ...r...*.S...{..
 00a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 00b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 00c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 00d0 8bfbff54 68ff9fd2 e8ffbff2 e8ffdff2  ...Th...........
 00e0 e8fffff2 e00308aa f353c1a8 fd7bc1a8  .........S...{..
 00f0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0100 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0110 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0120 0bf9ff54 086294d2 c816a0f2 a80ac0f2  ...T.b..........
 0130 08697ff8 08410091 08697ff8 e003082a  .i...A...i.....*
 0140 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0150 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0160 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0170 1408a0f2 7f0214eb 4bf6ff54 086294d2  ........K..T.b..
 0180 c816a0f2 a80ac0f2 08697ff8 08610091  .........i...a..
 0190 08697ff8 e00308aa f353c1a8 fd7bc1a8  .i.......S...{..
 01a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01d0 8bf3ff54 ff4300d1 e01300b9 e81340b9  ...T.C........@.
 01e0 096294d2 c916a0f2 a90ac0f2 29697ff8  .b..........)i..
 01f0 29410091 28693ff8 ff430091 f353c1a8  )A..(i?..C...S..
 0200 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0210 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0220 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0230 7f0214eb 6bf0ff54 ff4300d1 e00b00f9  ....k..T.C......
 0240 e80b40f9 096294d2 c916a0f2 a90ac0f2  ..@..b..........
 0250 29697ff8 29610091 28693ff8 ff430091  )i..)a..(i?..C..
 0260 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0270 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0280 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0290 1408a0f2 7f0214eb 4bedff54 28008052  ........K..T(..R
 02a0 08010034 086294d2 c816a0f2 a80ac0f2  ...4.b..........
 02b0 08697ff8 08410091 08697ff8 02000014  .i...A...i......
 02c0 48008052 e003082a f353c1a8 fd7bc1a8  H..R...*.S...{..
 02d0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 02e0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 02f0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0300 0beaff54 08008052 68000034 48008052  ...T...Rh..4H..R
 0310 07000014 086294d2 c816a0f2 a80ac0f2  .....b..........
 0320 08697ff8 08410091 08697ff8 e003082a  .i...A...i.....*
 0330 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0340 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0350 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0360 1408a0f2 7f0214eb cbe6ff54 086294d2  ...........T.b..
 0370 c816a0f2 a80ac0f2 08697ff8 08410091  .........i...A..
 0380 08697ff8 49008052 89000035 69008052  .i..I..R...5i..R
 0390 5f0000b4 e803092a e003082a f353c1a8  _......*...*.S..
 03a0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 03b0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 03c0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 03d0 7f0214eb 6be3ff54 48008052 096294d2  ....k..TH..R.b..
 03e0 c916a0f2 a90ac0f2 29697ff8 29410091  ........)i..)A..
 03f0 29697ff8 89000035 69008052 5f0000b4  )i.....5i..R_...
 0400 e803092a e003082a f353c1a8 fd7bc1a8  ...*...*.S...{..
 0410 c0035fd6                             .._.            
Contents of section .data:
 0000 feffffff ffffffff fbffffff ffffffff  ................
 0010 f4ffffff ffffffff f1ffffff ffffffff  ................

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

000000000000005c <get-a>:
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
  8c:	529fffc8 	mov	w8, #0xfffe                	// #65534
  90:	72bfffe8 	movk	w8, #0xffff, lsl #16
  94:	2a0803e0 	mov	w0, w8
  98:	a8c153f3 	ldp	x19, x20, [sp], #16
  9c:	a8c17bfd 	ldp	x29, x30, [sp], #16
  a0:	d65f03c0 	ret

00000000000000a4 <get-b>:
  a4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  a8:	910003fd 	mov	x29, sp
  ac:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  b0:	d2946413 	mov	x19, #0xa320                	// #41760
  b4:	f2a016d3 	movk	x19, #0xb6, lsl #16
  b8:	f2c00ab3 	movk	x19, #0x55, lsl #32
  bc:	f87f6a73 	ldr	x19, [x19, xzr]
  c0:	cb3363f3 	sub	x19, sp, x19
  c4:	d2800014 	mov	x20, #0x0                   	// #0
  c8:	f2a00814 	movk	x20, #0x40, lsl #16
  cc:	eb14027f 	cmp	x19, x20
  d0:	54fffb8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  d4:	d29fff68 	mov	x8, #0xfffb                	// #65531
  d8:	f2bfffe8 	movk	x8, #0xffff, lsl #16
  dc:	f2dfffe8 	movk	x8, #0xffff, lsl #32
  e0:	f2ffffe8 	movk	x8, #0xffff, lsl #48
  e4:	aa0803e0 	mov	x0, x8
  e8:	a8c153f3 	ldp	x19, x20, [sp], #16
  ec:	a8c17bfd 	ldp	x29, x30, [sp], #16
  f0:	d65f03c0 	ret

00000000000000f4 <get-x>:
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
 124:	d2946208 	mov	x8, #0xa310                	// #41744
 128:	f2a016c8 	movk	x8, #0xb6, lsl #16
 12c:	f2c00aa8 	movk	x8, #0x55, lsl #32
 130:	f87f6908 	ldr	x8, [x8, xzr]
 134:	91004108 	add	x8, x8, #0x10
 138:	f87f6908 	ldr	x8, [x8, xzr]
 13c:	2a0803e0 	mov	w0, w8
 140:	a8c153f3 	ldp	x19, x20, [sp], #16
 144:	a8c17bfd 	ldp	x29, x30, [sp], #16
 148:	d65f03c0 	ret

000000000000014c <get-y>:
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
 17c:	d2946208 	mov	x8, #0xa310                	// #41744
 180:	f2a016c8 	movk	x8, #0xb6, lsl #16
 184:	f2c00aa8 	movk	x8, #0x55, lsl #32
 188:	f87f6908 	ldr	x8, [x8, xzr]
 18c:	91006108 	add	x8, x8, #0x18
 190:	f87f6908 	ldr	x8, [x8, xzr]
 194:	aa0803e0 	mov	x0, x8
 198:	a8c153f3 	ldp	x19, x20, [sp], #16
 19c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a0:	d65f03c0 	ret

00000000000001a4 <set-x>:
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
 1e0:	d2946209 	mov	x9, #0xa310                	// #41744
 1e4:	f2a016c9 	movk	x9, #0xb6, lsl #16
 1e8:	f2c00aa9 	movk	x9, #0x55, lsl #32
 1ec:	f87f6929 	ldr	x9, [x9, xzr]
 1f0:	91004129 	add	x9, x9, #0x10
 1f4:	f83f6928 	str	x8, [x9, xzr]
 1f8:	910043ff 	add	sp, sp, #0x10
 1fc:	a8c153f3 	ldp	x19, x20, [sp], #16
 200:	a8c17bfd 	ldp	x29, x30, [sp], #16
 204:	d65f03c0 	ret

0000000000000208 <set-y>:
 208:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 20c:	910003fd 	mov	x29, sp
 210:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 214:	d2946413 	mov	x19, #0xa320                	// #41760
 218:	f2a016d3 	movk	x19, #0xb6, lsl #16
 21c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 220:	f87f6a73 	ldr	x19, [x19, xzr]
 224:	cb3363f3 	sub	x19, sp, x19
 228:	d2800014 	mov	x20, #0x0                   	// #0
 22c:	f2a00814 	movk	x20, #0x40, lsl #16
 230:	eb14027f 	cmp	x19, x20
 234:	54fff06b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 238:	d10043ff 	sub	sp, sp, #0x10
 23c:	f9000be0 	str	x0, [sp, #16]
 240:	f9400be8 	ldr	x8, [sp, #16]
 244:	d2946209 	mov	x9, #0xa310                	// #41744
 248:	f2a016c9 	movk	x9, #0xb6, lsl #16
 24c:	f2c00aa9 	movk	x9, #0x55, lsl #32
 250:	f87f6929 	ldr	x9, [x9, xzr]
 254:	91006129 	add	x9, x9, #0x18
 258:	f83f6928 	str	x8, [x9, xzr]
 25c:	910043ff 	add	sp, sp, #0x10
 260:	a8c153f3 	ldp	x19, x20, [sp], #16
 264:	a8c17bfd 	ldp	x29, x30, [sp], #16
 268:	d65f03c0 	ret

000000000000026c <as-if-then>:
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
 29c:	52800028 	mov	w8, #0x1                   	// #1
 2a0:	34000108 	cbz	w8, 2c0 <as-if-then+0x54>
 2a4:	d2946208 	mov	x8, #0xa310                	// #41744
 2a8:	f2a016c8 	movk	x8, #0xb6, lsl #16
 2ac:	f2c00aa8 	movk	x8, #0x55, lsl #32
 2b0:	f87f6908 	ldr	x8, [x8, xzr]
 2b4:	91004108 	add	x8, x8, #0x10
 2b8:	f87f6908 	ldr	x8, [x8, xzr]
 2bc:	14000002 	b	2c4 <as-if-then+0x58>
 2c0:	52800048 	mov	w8, #0x2                   	// #2
 2c4:	2a0803e0 	mov	w0, w8
 2c8:	a8c153f3 	ldp	x19, x20, [sp], #16
 2cc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2d0:	d65f03c0 	ret

00000000000002d4 <as-if-else>:
 2d4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 2d8:	910003fd 	mov	x29, sp
 2dc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 2e0:	d2946413 	mov	x19, #0xa320                	// #41760
 2e4:	f2a016d3 	movk	x19, #0xb6, lsl #16
 2e8:	f2c00ab3 	movk	x19, #0x55, lsl #32
 2ec:	f87f6a73 	ldr	x19, [x19, xzr]
 2f0:	cb3363f3 	sub	x19, sp, x19
 2f4:	d2800014 	mov	x20, #0x0                   	// #0
 2f8:	f2a00814 	movk	x20, #0x40, lsl #16
 2fc:	eb14027f 	cmp	x19, x20
 300:	54ffea0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 304:	52800008 	mov	w8, #0x0                   	// #0
 308:	34000068 	cbz	w8, 314 <as-if-else+0x40>
 30c:	52800048 	mov	w8, #0x2                   	// #2
 310:	14000007 	b	32c <as-if-else+0x58>
 314:	d2946208 	mov	x8, #0xa310                	// #41744
 318:	f2a016c8 	movk	x8, #0xb6, lsl #16
 31c:	f2c00aa8 	movk	x8, #0x55, lsl #32
 320:	f87f6908 	ldr	x8, [x8, xzr]
 324:	91004108 	add	x8, x8, #0x10
 328:	f87f6908 	ldr	x8, [x8, xzr]
 32c:	2a0803e0 	mov	w0, w8
 330:	a8c153f3 	ldp	x19, x20, [sp], #16
 334:	a8c17bfd 	ldp	x29, x30, [sp], #16
 338:	d65f03c0 	ret

000000000000033c <as-br_if-first>:
 33c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 340:	910003fd 	mov	x29, sp
 344:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 348:	d2946413 	mov	x19, #0xa320                	// #41760
 34c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 350:	f2c00ab3 	movk	x19, #0x55, lsl #32
 354:	f87f6a73 	ldr	x19, [x19, xzr]
 358:	cb3363f3 	sub	x19, sp, x19
 35c:	d2800014 	mov	x20, #0x0                   	// #0
 360:	f2a00814 	movk	x20, #0x40, lsl #16
 364:	eb14027f 	cmp	x19, x20
 368:	54ffe6cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 36c:	d2946208 	mov	x8, #0xa310                	// #41744
 370:	f2a016c8 	movk	x8, #0xb6, lsl #16
 374:	f2c00aa8 	movk	x8, #0x55, lsl #32
 378:	f87f6908 	ldr	x8, [x8, xzr]
 37c:	91004108 	add	x8, x8, #0x10
 380:	f87f6908 	ldr	x8, [x8, xzr]
 384:	52800049 	mov	w9, #0x2                   	// #2
 388:	35000089 	cbnz	w9, 398 <as-br_if-first+0x5c>
 38c:	52800069 	mov	w9, #0x3                   	// #3
 390:	b400005f 	cbz	xzr, 398 <as-br_if-first+0x5c>
 394:	2a0903e8 	mov	w8, w9
 398:	2a0803e0 	mov	w0, w8
 39c:	a8c153f3 	ldp	x19, x20, [sp], #16
 3a0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 3a4:	d65f03c0 	ret

00000000000003a8 <as-br_if-last>:
 3a8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 3ac:	910003fd 	mov	x29, sp
 3b0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 3b4:	d2946413 	mov	x19, #0xa320                	// #41760
 3b8:	f2a016d3 	movk	x19, #0xb6, lsl #16
 3bc:	f2c00ab3 	movk	x19, #0x55, lsl #32
 3c0:	f87f6a73 	ldr	x19, [x19, xzr]
 3c4:	cb3363f3 	sub	x19, sp, x19
 3c8:	d2800014 	mov	x20, #0x0                   	// #0
 3cc:	f2a00814 	movk	x20, #0x40, lsl #16
 3d0:	eb14027f 	cmp	x19, x20
 3d4:	54ffe36b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 3d8:	52800048 	mov	w8, #0x2                   	// #2
 3dc:	d2946209 	mov	x9, #0xa310                	// #41744
 3e0:	f2a016c9 	movk	x9, #0xb6, lsl #16
 3e4:	f2c00aa9 	movk	x9, #0x55, lsl #32
 3e8:	f87f6929 	ldr	x9, [x9, xzr]
 3ec:	91004129 	add	x9, x9, #0x10
 3f0:	f87f6929 	ldr	x9, [x9, xzr]
 3f4:	35000089 	cbnz	w9, 404 <as-br_if-last+0x5c>
 3f8:	52800069 	mov	w9, #0x3                   	// #3
 3fc:	b400005f 	cbz	xzr, 404 <as-br_if-last+0x5c>
 400:	2a0903e8 	mov	w8, w9
 404:	2a0803e0 	mov	w0, w8
 408:	a8c153f3 	ldp	x19, x20, [sp], #16
 40c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 410:	d65f03c0 	ret
