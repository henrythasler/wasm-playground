
./tests/machinecode/loop-extended.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000084 loop_n
00000000000000e0 g     F .text	00000000000000a0 loop_n2


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
 0090 e01300b9 e10f00b9 e81340b9 29008052  ..........@.)..R
 00a0 0801090b e81300b9 e81340b9 e90f40b9  ..........@...@.
 00b0 1f01096b 63000054 08008052 02000014  ...kc..T...R....
 00c0 28008052 a8feff35 e81340b9 e003082a  (..R...5..@....*
 00d0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00e0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00f0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0100 140080d2 1408a0f2 7f0214eb abf9ff54  ...............T
 0110 ff4300d1 e01300b9 e10f00b9 e81340b9  .C............@.
 0120 e90f40b9 1f01096b 6b000054 08008052  ..@....kk..T...R
 0130 02000014 28008052 29008052 0801090a  ....(..R)..R....
 0140 68000034 08008052 02000014 28008052  h..4...R....(..R
 0150 c8000035 e81340b9 29008052 0801090b  ...5..@.)..R....
 0160 e81300b9 eeffff17 e81340b9 e003082a  ..........@....*
 0170 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.

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

000000000000005c <loop_n>:
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
  94:	b9000fe1 	str	w1, [sp, #12]
  98:	b94013e8 	ldr	w8, [sp, #16]
  9c:	52800029 	mov	w9, #0x1                   	// #1
  a0:	0b090108 	add	w8, w8, w9
  a4:	b90013e8 	str	w8, [sp, #16]
  a8:	b94013e8 	ldr	w8, [sp, #16]
  ac:	b9400fe9 	ldr	w9, [sp, #12]
  b0:	6b09011f 	cmp	w8, w9
  b4:	54000063 	b.cc	c0 <loop_n+0x64>  // b.lo, b.ul, b.last
  b8:	52800008 	mov	w8, #0x0                   	// #0
  bc:	14000002 	b	c4 <loop_n+0x68>
  c0:	52800028 	mov	w8, #0x1                   	// #1
  c4:	35fffea8 	cbnz	w8, 98 <loop_n+0x3c>
  c8:	b94013e8 	ldr	w8, [sp, #16]
  cc:	2a0803e0 	mov	w0, w8
  d0:	910043ff 	add	sp, sp, #0x10
  d4:	a8c153f3 	ldp	x19, x20, [sp], #16
  d8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  dc:	d65f03c0 	ret

00000000000000e0 <loop_n2>:
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
 124:	6b09011f 	cmp	w8, w9
 128:	5400006b 	b.lt	134 <loop_n2+0x54>  // b.tstop
 12c:	52800008 	mov	w8, #0x0                   	// #0
 130:	14000002 	b	138 <loop_n2+0x58>
 134:	52800028 	mov	w8, #0x1                   	// #1
 138:	52800029 	mov	w9, #0x1                   	// #1
 13c:	0a090108 	and	w8, w8, w9
 140:	34000068 	cbz	w8, 14c <loop_n2+0x6c>
 144:	52800008 	mov	w8, #0x0                   	// #0
 148:	14000002 	b	150 <loop_n2+0x70>
 14c:	52800028 	mov	w8, #0x1                   	// #1
 150:	350000c8 	cbnz	w8, 168 <loop_n2+0x88>
 154:	b94013e8 	ldr	w8, [sp, #16]
 158:	52800029 	mov	w9, #0x1                   	// #1
 15c:	0b090108 	add	w8, w8, w9
 160:	b90013e8 	str	w8, [sp, #16]
 164:	17ffffee 	b	11c <loop_n2+0x3c>
 168:	b94013e8 	ldr	w8, [sp, #16]
 16c:	2a0803e0 	mov	w0, w8
 170:	910043ff 	add	sp, sp, #0x10
 174:	a8c153f3 	ldp	x19, x20, [sp], #16
 178:	a8c17bfd 	ldp	x29, x30, [sp], #16
 17c:	d65f03c0 	ret
