
./tests/machinecode/abs.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	000000000000006c lt_s
00000000000000c8 g     F .text	0000000000000080 abs


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
 0090 e01300b9 e10f00b9 e81340b9 e90f40b9  ..........@...@.
 00a0 1f01096b 6b000054 08008052 02000014  ...kk..T...R....
 00b0 28008052 e003082a ff430091 f353c1a8  (..R...*.C...S..
 00c0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00d0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00e0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 00f0 7f0214eb 6bfaff54 ff4300d1 e01300b9  ....k..T.C......
 0100 e81340b9 09008052 1f01096b 6b000054  ..@....R...kk..T
 0110 08008052 02000014 28008052 a8000034  ...R....(..R...4
 0120 08008052 e91340b9 0801094b 02000014  ...R..@....K....
 0130 e81340b9 e003082a ff430091 f353c1a8  ..@....*.C...S..
 0140 fd7bc1a8 c0035fd6                    .{...._.        

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

000000000000005c <lt_s>:
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
  9c:	b9400fe9 	ldr	w9, [sp, #12]
  a0:	6b09011f 	cmp	w8, w9
  a4:	5400006b 	b.lt	b0 <lt_s+0x54>  // b.tstop
  a8:	52800008 	mov	w8, #0x0                   	// #0
  ac:	14000002 	b	b4 <lt_s+0x58>
  b0:	52800028 	mov	w8, #0x1                   	// #1
  b4:	2a0803e0 	mov	w0, w8
  b8:	910043ff 	add	sp, sp, #0x10
  bc:	a8c153f3 	ldp	x19, x20, [sp], #16
  c0:	a8c17bfd 	ldp	x29, x30, [sp], #16
  c4:	d65f03c0 	ret

00000000000000c8 <abs>:
  c8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  cc:	910003fd 	mov	x29, sp
  d0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  d4:	d2946413 	mov	x19, #0xa320                	// #41760
  d8:	f2a016d3 	movk	x19, #0xb6, lsl #16
  dc:	f2c00ab3 	movk	x19, #0x55, lsl #32
  e0:	f87f6a73 	ldr	x19, [x19, xzr]
  e4:	cb3363f3 	sub	x19, sp, x19
  e8:	d2800014 	mov	x20, #0x0                   	// #0
  ec:	f2a00814 	movk	x20, #0x40, lsl #16
  f0:	eb14027f 	cmp	x19, x20
  f4:	54fffa6b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  f8:	d10043ff 	sub	sp, sp, #0x10
  fc:	b90013e0 	str	w0, [sp, #16]
 100:	b94013e8 	ldr	w8, [sp, #16]
 104:	52800009 	mov	w9, #0x0                   	// #0
 108:	6b09011f 	cmp	w8, w9
 10c:	5400006b 	b.lt	118 <abs+0x50>  // b.tstop
 110:	52800008 	mov	w8, #0x0                   	// #0
 114:	14000002 	b	11c <abs+0x54>
 118:	52800028 	mov	w8, #0x1                   	// #1
 11c:	340000a8 	cbz	w8, 130 <abs+0x68>
 120:	52800008 	mov	w8, #0x0                   	// #0
 124:	b94013e9 	ldr	w9, [sp, #16]
 128:	4b090108 	sub	w8, w8, w9
 12c:	14000002 	b	134 <abs+0x6c>
 130:	b94013e8 	ldr	w8, [sp, #16]
 134:	2a0803e0 	mov	w0, w8
 138:	910043ff 	add	sp, sp, #0x10
 13c:	a8c153f3 	ldp	x19, x20, [sp], #16
 140:	a8c17bfd 	ldp	x29, x30, [sp], #16
 144:	d65f03c0 	ret
