
./tests/machinecode/globals-extended.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000048 get_const0
00000000000000a4 g     F .text	0000000000000050 get_const1
00000000000000f4 g     F .text	0000000000000058 get_mut0
000000000000014c g     F .text	0000000000000058 get_mut1
00000000000001a4 g     F .text	0000000000000080 store_mut0
0000000000000224 g     F .text	0000000000000080 store_mut1
0000000000000000 g     O .rodata	0000000000000028 globals


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
 01f0 29410091 28693ff8 086294d2 c816a0f2  )A..(i?..b......
 0200 a80ac0f2 08697ff8 08410091 08697ff8  .....i...A...i..
 0210 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 0220 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0230 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0240 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0250 8befff54 ff4300d1 e00b00f9 e80b40f9  ...T.C........@.
 0260 096294d2 c916a0f2 a90ac0f2 29697ff8  .b..........)i..
 0270 29610091 28693ff8 086294d2 c816a0f2  )a..(i?..b......
 0280 a80ac0f2 08697ff8 08610091 08697ff8  .....i...a...i..
 0290 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 02a0 c0035fd6                             .._.            
Contents of section .data:
 0000 feffffff ffffffff fbffffff ffffffff  ................
 0010 f4ffffff ffffffff 64000000 00000000  ........d.......
 0020 10d80200 00000000                    ........        

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

000000000000005c <get_const0>:
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

00000000000000a4 <get_const1>:
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

00000000000000f4 <get_mut0>:
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

000000000000014c <get_mut1>:
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

00000000000001a4 <store_mut0>:
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
 1f8:	d2946208 	mov	x8, #0xa310                	// #41744
 1fc:	f2a016c8 	movk	x8, #0xb6, lsl #16
 200:	f2c00aa8 	movk	x8, #0x55, lsl #32
 204:	f87f6908 	ldr	x8, [x8, xzr]
 208:	91004108 	add	x8, x8, #0x10
 20c:	f87f6908 	ldr	x8, [x8, xzr]
 210:	2a0803e0 	mov	w0, w8
 214:	910043ff 	add	sp, sp, #0x10
 218:	a8c153f3 	ldp	x19, x20, [sp], #16
 21c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 220:	d65f03c0 	ret

0000000000000224 <store_mut1>:
 224:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 228:	910003fd 	mov	x29, sp
 22c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 230:	d2946413 	mov	x19, #0xa320                	// #41760
 234:	f2a016d3 	movk	x19, #0xb6, lsl #16
 238:	f2c00ab3 	movk	x19, #0x55, lsl #32
 23c:	f87f6a73 	ldr	x19, [x19, xzr]
 240:	cb3363f3 	sub	x19, sp, x19
 244:	d2800014 	mov	x20, #0x0                   	// #0
 248:	f2a00814 	movk	x20, #0x40, lsl #16
 24c:	eb14027f 	cmp	x19, x20
 250:	54ffef8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 254:	d10043ff 	sub	sp, sp, #0x10
 258:	f9000be0 	str	x0, [sp, #16]
 25c:	f9400be8 	ldr	x8, [sp, #16]
 260:	d2946209 	mov	x9, #0xa310                	// #41744
 264:	f2a016c9 	movk	x9, #0xb6, lsl #16
 268:	f2c00aa9 	movk	x9, #0x55, lsl #32
 26c:	f87f6929 	ldr	x9, [x9, xzr]
 270:	91006129 	add	x9, x9, #0x18
 274:	f83f6928 	str	x8, [x9, xzr]
 278:	d2946208 	mov	x8, #0xa310                	// #41744
 27c:	f2a016c8 	movk	x8, #0xb6, lsl #16
 280:	f2c00aa8 	movk	x8, #0x55, lsl #32
 284:	f87f6908 	ldr	x8, [x8, xzr]
 288:	91006108 	add	x8, x8, #0x18
 28c:	f87f6908 	ldr	x8, [x8, xzr]
 290:	aa0803e0 	mov	x0, x8
 294:	910043ff 	add	sp, sp, #0x10
 298:	a8c153f3 	ldp	x19, x20, [sp], #16
 29c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2a0:	d65f03c0 	ret
