
./tests/machinecode/functions.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000070 basic
00000000000000cc g     F .text	0000000000000044 one
0000000000000110 g     F .text	0000000000000070 back
0000000000000180 g     F .text	0000000000000078 four


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 ff0301d1  ...........T....
 0090 e82703a9 ea2f02a9 ec3701a9 ee3f00a9  .'.../...7...?..
 00a0 0b000094 e82743a9 ea2f42a9 ec3741a9  .....'C../B..7A.
 00b0 ee3f40a9 ff030191 e80300aa e00308aa  .?@.............
 00c0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 00d0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 00e0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 00f0 1408a0f2 7f0214eb 4bfaff54 280080d2  ........K..T(...
 0100 e00308aa f353c1a8 fd7bc1a8 c0035fd6  .....S...{...._.
 0110 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0120 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0130 140080d2 1408a0f2 7f0214eb 2bf8ff54  ............+..T
 0140 ff0301d1 e82703a9 ea2f02a9 ec3701a9  .....'.../...7..
 0150 ee3f00a9 deffff97 e82743a9 ea2f42a9  .?.......'C../B.
 0160 ec3741a9 ee3f40a9 ff030191 e80300aa  .7A..?@.........
 0170 e00308aa f353c1a8 fd7bc1a8 c0035fd6  .....S...{...._.
 0180 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0190 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 01a0 140080d2 1408a0f2 7f0214eb abf4ff54  ...............T
 01b0 680080d2 ff0301d1 e82703a9 ea2f02a9  h........'.../..
 01c0 ec3701a9 ee3f00a9 c1ffff97 e82743a9  .7...?.......'C.
 01d0 ea2f42a9 ec3741a9 ee3f40a9 ff030191  ./B..7A..?@.....
 01e0 e90300aa 0801098b e00308aa f353c1a8  .............S..
 01f0 fd7bc1a8 c0035fd6                    .{...._.        

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

000000000000005c <basic>:
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
  8c:	d10103ff 	sub	sp, sp, #0x40
  90:	a90327e8 	stp	x8, x9, [sp, #48]
  94:	a9022fea 	stp	x10, x11, [sp, #32]
  98:	a90137ec 	stp	x12, x13, [sp, #16]
  9c:	a9003fee 	stp	x14, x15, [sp]
  a0:	9400000b 	bl	cc <one>
  a4:	a94327e8 	ldp	x8, x9, [sp, #48]
  a8:	a9422fea 	ldp	x10, x11, [sp, #32]
  ac:	a94137ec 	ldp	x12, x13, [sp, #16]
  b0:	a9403fee 	ldp	x14, x15, [sp]
  b4:	910103ff 	add	sp, sp, #0x40
  b8:	aa0003e8 	mov	x8, x0
  bc:	aa0803e0 	mov	x0, x8
  c0:	a8c153f3 	ldp	x19, x20, [sp], #16
  c4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  c8:	d65f03c0 	ret

00000000000000cc <one>:
  cc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  d0:	910003fd 	mov	x29, sp
  d4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  d8:	d2946413 	mov	x19, #0xa320                	// #41760
  dc:	f2a016d3 	movk	x19, #0xb6, lsl #16
  e0:	f2c00ab3 	movk	x19, #0x55, lsl #32
  e4:	f87f6a73 	ldr	x19, [x19, xzr]
  e8:	cb3363f3 	sub	x19, sp, x19
  ec:	d2800014 	mov	x20, #0x0                   	// #0
  f0:	f2a00814 	movk	x20, #0x40, lsl #16
  f4:	eb14027f 	cmp	x19, x20
  f8:	54fffa4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  fc:	d2800028 	mov	x8, #0x1                   	// #1
 100:	aa0803e0 	mov	x0, x8
 104:	a8c153f3 	ldp	x19, x20, [sp], #16
 108:	a8c17bfd 	ldp	x29, x30, [sp], #16
 10c:	d65f03c0 	ret

0000000000000110 <back>:
 110:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 114:	910003fd 	mov	x29, sp
 118:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 11c:	d2946413 	mov	x19, #0xa320                	// #41760
 120:	f2a016d3 	movk	x19, #0xb6, lsl #16
 124:	f2c00ab3 	movk	x19, #0x55, lsl #32
 128:	f87f6a73 	ldr	x19, [x19, xzr]
 12c:	cb3363f3 	sub	x19, sp, x19
 130:	d2800014 	mov	x20, #0x0                   	// #0
 134:	f2a00814 	movk	x20, #0x40, lsl #16
 138:	eb14027f 	cmp	x19, x20
 13c:	54fff82b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 140:	d10103ff 	sub	sp, sp, #0x40
 144:	a90327e8 	stp	x8, x9, [sp, #48]
 148:	a9022fea 	stp	x10, x11, [sp, #32]
 14c:	a90137ec 	stp	x12, x13, [sp, #16]
 150:	a9003fee 	stp	x14, x15, [sp]
 154:	97ffffde 	bl	cc <one>
 158:	a94327e8 	ldp	x8, x9, [sp, #48]
 15c:	a9422fea 	ldp	x10, x11, [sp, #32]
 160:	a94137ec 	ldp	x12, x13, [sp, #16]
 164:	a9403fee 	ldp	x14, x15, [sp]
 168:	910103ff 	add	sp, sp, #0x40
 16c:	aa0003e8 	mov	x8, x0
 170:	aa0803e0 	mov	x0, x8
 174:	a8c153f3 	ldp	x19, x20, [sp], #16
 178:	a8c17bfd 	ldp	x29, x30, [sp], #16
 17c:	d65f03c0 	ret

0000000000000180 <four>:
 180:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 184:	910003fd 	mov	x29, sp
 188:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 18c:	d2946413 	mov	x19, #0xa320                	// #41760
 190:	f2a016d3 	movk	x19, #0xb6, lsl #16
 194:	f2c00ab3 	movk	x19, #0x55, lsl #32
 198:	f87f6a73 	ldr	x19, [x19, xzr]
 19c:	cb3363f3 	sub	x19, sp, x19
 1a0:	d2800014 	mov	x20, #0x0                   	// #0
 1a4:	f2a00814 	movk	x20, #0x40, lsl #16
 1a8:	eb14027f 	cmp	x19, x20
 1ac:	54fff4ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1b0:	d2800068 	mov	x8, #0x3                   	// #3
 1b4:	d10103ff 	sub	sp, sp, #0x40
 1b8:	a90327e8 	stp	x8, x9, [sp, #48]
 1bc:	a9022fea 	stp	x10, x11, [sp, #32]
 1c0:	a90137ec 	stp	x12, x13, [sp, #16]
 1c4:	a9003fee 	stp	x14, x15, [sp]
 1c8:	97ffffc1 	bl	cc <one>
 1cc:	a94327e8 	ldp	x8, x9, [sp, #48]
 1d0:	a9422fea 	ldp	x10, x11, [sp, #32]
 1d4:	a94137ec 	ldp	x12, x13, [sp, #16]
 1d8:	a9403fee 	ldp	x14, x15, [sp]
 1dc:	910103ff 	add	sp, sp, #0x40
 1e0:	aa0003e9 	mov	x9, x0
 1e4:	8b090108 	add	x8, x8, x9
 1e8:	aa0803e0 	mov	x0, x8
 1ec:	a8c153f3 	ldp	x19, x20, [sp], #16
 1f0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1f4:	d65f03c0 	ret
