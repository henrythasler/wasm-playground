
./tests/machinecode/stack_overflow.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	00000000000000b8 exhaust


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 ff8300d1  ...........T....
 0090 ff2300b9 ff1f00b9 ff1b00b9 ff1700b9  .#..............
 00a0 ff1300b9 ff0f00b9 ff0b00b9 08008052  ...............R
 00b0 e82300b9 28008052 e81f00b9 48008052  .#..(..R....H..R
 00c0 e81b00b9 68008052 e81700b9 88008052  ....h..R.......R
 00d0 e81300b9 ff0301d1 e82703a9 ea2f02a9  .........'.../..
 00e0 ec3701a9 ee3f00a9 ddffff97 e82743a9  .7...?.......'C.
 00f0 ea2f42a9 ec3741a9 ee3f40a9 ff030191  ./B..7A..?@.....
 0100 e80300aa ff830091 f353c1a8 fd7bc1a8  .........S...{..
 0110 c0035fd6                             .._.            

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

000000000000005c <exhaust>:
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
  8c:	d10083ff 	sub	sp, sp, #0x20
  90:	b90023ff 	str	wzr, [sp, #32]
  94:	b9001fff 	str	wzr, [sp, #28]
  98:	b9001bff 	str	wzr, [sp, #24]
  9c:	b90017ff 	str	wzr, [sp, #20]
  a0:	b90013ff 	str	wzr, [sp, #16]
  a4:	b9000fff 	str	wzr, [sp, #12]
  a8:	b9000bff 	str	wzr, [sp, #8]
  ac:	52800008 	mov	w8, #0x0                   	// #0
  b0:	b90023e8 	str	w8, [sp, #32]
  b4:	52800028 	mov	w8, #0x1                   	// #1
  b8:	b9001fe8 	str	w8, [sp, #28]
  bc:	52800048 	mov	w8, #0x2                   	// #2
  c0:	b9001be8 	str	w8, [sp, #24]
  c4:	52800068 	mov	w8, #0x3                   	// #3
  c8:	b90017e8 	str	w8, [sp, #20]
  cc:	52800088 	mov	w8, #0x4                   	// #4
  d0:	b90013e8 	str	w8, [sp, #16]
  d4:	d10103ff 	sub	sp, sp, #0x40
  d8:	a90327e8 	stp	x8, x9, [sp, #48]
  dc:	a9022fea 	stp	x10, x11, [sp, #32]
  e0:	a90137ec 	stp	x12, x13, [sp, #16]
  e4:	a9003fee 	stp	x14, x15, [sp]
  e8:	97ffffdd 	bl	5c <exhaust>
  ec:	a94327e8 	ldp	x8, x9, [sp, #48]
  f0:	a9422fea 	ldp	x10, x11, [sp, #32]
  f4:	a94137ec 	ldp	x12, x13, [sp, #16]
  f8:	a9403fee 	ldp	x14, x15, [sp]
  fc:	910103ff 	add	sp, sp, #0x40
 100:	aa0003e8 	mov	x8, x0
 104:	910083ff 	add	sp, sp, #0x20
 108:	a8c153f3 	ldp	x19, x20, [sp], #16
 10c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 110:	d65f03c0 	ret
