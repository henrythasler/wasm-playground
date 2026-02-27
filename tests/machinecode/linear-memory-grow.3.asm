
./tests/machinecode/linear-memory-grow.3.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	000000000000007c grow
00000000000000d8 g     F .text	000000000000010c check-memory-zero


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
 0090 e01300b9 e81340b9 097294d2 c916a0f2  ......@..r......
 00a0 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 00b0 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 00c0 e80300aa e003082a ff430091 f353c1a8  .......*.C...S..
 00d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0100 7f0214eb ebf9ff54 ff4300d1 e01300b9  .......T.C......
 0110 e10f00b9 ff0b00b9 28008052 e80b00b9  ........(..R....
 0120 e81340b9 096c94d2 c916a0f2 a90ac0f2  ..@..l..........
 0130 29697ff8 29f8ff34 0a7094d2 ca16a0f2  )i..)..4.p......
 0140 aa0ac0f2 4a697fb8 4a050051 1f010a6b  ....Ji..J..Q...k
 0150 48f7ff54 29796838 e90b00b9 e80b40b9  H..T)yh8......@.
 0160 09008052 1f0109eb 61000054 08008052  ...R....a..T...R
 0170 02000014 28008052 a8020035 e81340b9  ....(..R...5..@.
 0180 e90f40b9 1f01096b 62000054 08008052  ..@....kb..T...R
 0190 02000014 28008052 a8010035 e81340b9  ....(..R...5..@.
 01a0 29008052 0801090b e81300b9 e81340b9  )..R..........@.
 01b0 e90f40b9 1f01096b 69000054 08008052  ..@....ki..T...R
 01c0 02000014 28008052 c8faff35 e80b40b9  ....(..R...5..@.
 01d0 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 01e0 c0035fd6                             .._.            

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

000000000000005c <grow>:
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
  98:	d2947209 	mov	x9, #0xa390                	// #41872
  9c:	f2a016c9 	movk	x9, #0xb6, lsl #16
  a0:	f2c00aa9 	movk	x9, #0x55, lsl #32
  a4:	f87f6929 	ldr	x9, [x9, xzr]
  a8:	d2946600 	mov	x0, #0xa330                	// #41776
  ac:	f2a016c0 	movk	x0, #0xb6, lsl #16
  b0:	f2c00aa0 	movk	x0, #0x55, lsl #32
  b4:	f87f6800 	ldr	x0, [x0, xzr]
  b8:	aa0803e1 	mov	x1, x8
  bc:	d63f0120 	blr	x9
  c0:	aa0003e8 	mov	x8, x0
  c4:	2a0803e0 	mov	w0, w8
  c8:	910043ff 	add	sp, sp, #0x10
  cc:	a8c153f3 	ldp	x19, x20, [sp], #16
  d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
  d4:	d65f03c0 	ret

00000000000000d8 <check-memory-zero>:
  d8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  dc:	910003fd 	mov	x29, sp
  e0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  e4:	d2946413 	mov	x19, #0xa320                	// #41760
  e8:	f2a016d3 	movk	x19, #0xb6, lsl #16
  ec:	f2c00ab3 	movk	x19, #0x55, lsl #32
  f0:	f87f6a73 	ldr	x19, [x19, xzr]
  f4:	cb3363f3 	sub	x19, sp, x19
  f8:	d2800014 	mov	x20, #0x0                   	// #0
  fc:	f2a00814 	movk	x20, #0x40, lsl #16
 100:	eb14027f 	cmp	x19, x20
 104:	54fff9eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 108:	d10043ff 	sub	sp, sp, #0x10
 10c:	b90013e0 	str	w0, [sp, #16]
 110:	b9000fe1 	str	w1, [sp, #12]
 114:	b9000bff 	str	wzr, [sp, #8]
 118:	52800028 	mov	w8, #0x1                   	// #1
 11c:	b9000be8 	str	w8, [sp, #8]
 120:	b94013e8 	ldr	w8, [sp, #16]
 124:	d2946c09 	mov	x9, #0xa360                	// #41824
 128:	f2a016c9 	movk	x9, #0xb6, lsl #16
 12c:	f2c00aa9 	movk	x9, #0x55, lsl #32
 130:	f87f6929 	ldr	x9, [x9, xzr]
 134:	34fff829 	cbz	w9, 38 <trap_handler+0x38>
 138:	d294700a 	mov	x10, #0xa380                	// #41856
 13c:	f2a016ca 	movk	x10, #0xb6, lsl #16
 140:	f2c00aaa 	movk	x10, #0x55, lsl #32
 144:	b87f694a 	ldr	w10, [x10, xzr]
 148:	5100054a 	sub	w10, w10, #0x1
 14c:	6b0a011f 	cmp	w8, w10
 150:	54fff748 	b.hi	38 <trap_handler+0x38>  // b.pmore
 154:	38687929 	ldrb	w9, [x9, x8, lsl #0]
 158:	b9000be9 	str	w9, [sp, #8]
 15c:	b9400be8 	ldr	w8, [sp, #8]
 160:	52800009 	mov	w9, #0x0                   	// #0
 164:	eb09011f 	cmp	x8, x9
 168:	54000061 	b.ne	174 <check-memory-zero+0x9c>  // b.any
 16c:	52800008 	mov	w8, #0x0                   	// #0
 170:	14000002 	b	178 <check-memory-zero+0xa0>
 174:	52800028 	mov	w8, #0x1                   	// #1
 178:	350002a8 	cbnz	w8, 1cc <check-memory-zero+0xf4>
 17c:	b94013e8 	ldr	w8, [sp, #16]
 180:	b9400fe9 	ldr	w9, [sp, #12]
 184:	6b09011f 	cmp	w8, w9
 188:	54000062 	b.cs	194 <check-memory-zero+0xbc>  // b.hs, b.nlast
 18c:	52800008 	mov	w8, #0x0                   	// #0
 190:	14000002 	b	198 <check-memory-zero+0xc0>
 194:	52800028 	mov	w8, #0x1                   	// #1
 198:	350001a8 	cbnz	w8, 1cc <check-memory-zero+0xf4>
 19c:	b94013e8 	ldr	w8, [sp, #16]
 1a0:	52800029 	mov	w9, #0x1                   	// #1
 1a4:	0b090108 	add	w8, w8, w9
 1a8:	b90013e8 	str	w8, [sp, #16]
 1ac:	b94013e8 	ldr	w8, [sp, #16]
 1b0:	b9400fe9 	ldr	w9, [sp, #12]
 1b4:	6b09011f 	cmp	w8, w9
 1b8:	54000069 	b.ls	1c4 <check-memory-zero+0xec>  // b.plast
 1bc:	52800008 	mov	w8, #0x0                   	// #0
 1c0:	14000002 	b	1c8 <check-memory-zero+0xf0>
 1c4:	52800028 	mov	w8, #0x1                   	// #1
 1c8:	35fffac8 	cbnz	w8, 120 <check-memory-zero+0x48>
 1cc:	b9400be8 	ldr	w8, [sp, #8]
 1d0:	2a0803e0 	mov	w0, w8
 1d4:	910043ff 	add	sp, sp, #0x10
 1d8:	a8c153f3 	ldp	x19, x20, [sp], #16
 1dc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1e0:	d65f03c0 	ret
