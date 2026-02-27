
./tests/machinecode/local-extended.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000064 store_i64
00000000000000c0 g     F .text	000000000000006c store_i64_const
000000000000012c g     F .text	0000000000000158 many_locals


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
 0090 e01300f9 ff1b00b9 ff0b00f9 ff0f00b9  ................
 00a0 e81340f9 e80b00f9 e80b40f9 e00308aa  ..@.......@.....
 00b0 ff830091 f353c1a8 fd7bc1a8 c0035fd6  .....S...{...._.
 00c0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00d0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 00e0 140080d2 1408a0f2 7f0214eb abfaff54  ...............T
 00f0 ff4300d1 ff1300b9 ff0700f9 ff0700b9  .C..............
 0100 e8ff9fd2 e8ffbff2 e8ffdff2 e8ffeff2  ................
 0110 e80700f9 e80740f9 e00308aa ff430091  ......@......C..
 0120 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0130 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0140 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0150 1408a0f2 7f0214eb 4bf7ff54 ffc301d1  ........K..T....
 0160 e07300b9 ff6f00b9 ff6b00b9 ff6700b9  .s...o...k...g..
 0170 ff6300b9 ff5f00b9 ff5b00b9 ff5700b9  .c..._...[...W..
 0180 ff5300b9 ff4f00b9 ff4b00b9 ff4700b9  .S...O...K...G..
 0190 ff4300b9 ff1f00f9 ff1b00f9 ff1700f9  .C..............
 01a0 ff2700b9 ff2300b9 ff1f00b9 ff1b00b9  .'...#..........
 01b0 ff1700b9 ff1300b9 ff0f00b9 e87340b9  .............s@.
 01c0 e86f00b9 e86f40b9 e86b00b9 e86b40b9  .o...o@..k...k@.
 01d0 e86700b9 e86740b9 e86300b9 e86340b9  .g...g@..c...c@.
 01e0 e85f00b9 e85f40b9 e85b00b9 e85b40b9  ._..._@..[...[@.
 01f0 e85700b9 e85740b9 e85300b9 e85340b9  .W...W@..S...S@.
 0200 e84f00b9 e84f40b9 e84b00b9 e84b40b9  .O...O@..K...K@.
 0210 e84700b9 e84740b9 e84300b9 280080d2  .G...G@..C..(...
 0220 e81f00f9 480080d2 e81b00f9 680080d2  ....H.......h...
 0230 e81700f9 e84340b9 e82700b9 e82740b9  .....C@..'...'@.
 0240 e82300b9 e82340b9 e81f00b9 e81f40b9  .#...#@.......@.
 0250 e81b00b9 e81b40b9 e81700b9 e81740b9  ......@.......@.
 0260 e81300b9 e81340b9 e80f00b9 e80f40b9  ......@.......@.
 0270 e003082a ffc30191 f353c1a8 fd7bc1a8  ...*.....S...{..
 0280 c0035fd6                             .._.            

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

000000000000005c <store_i64>:
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
  90:	f90013e0 	str	x0, [sp, #32]
  94:	b9001bff 	str	wzr, [sp, #24]
  98:	f9000bff 	str	xzr, [sp, #16]
  9c:	b9000fff 	str	wzr, [sp, #12]
  a0:	f94013e8 	ldr	x8, [sp, #32]
  a4:	f9000be8 	str	x8, [sp, #16]
  a8:	f9400be8 	ldr	x8, [sp, #16]
  ac:	aa0803e0 	mov	x0, x8
  b0:	910083ff 	add	sp, sp, #0x20
  b4:	a8c153f3 	ldp	x19, x20, [sp], #16
  b8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  bc:	d65f03c0 	ret

00000000000000c0 <store_i64_const>:
  c0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  c4:	910003fd 	mov	x29, sp
  c8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  cc:	d2946413 	mov	x19, #0xa320                	// #41760
  d0:	f2a016d3 	movk	x19, #0xb6, lsl #16
  d4:	f2c00ab3 	movk	x19, #0x55, lsl #32
  d8:	f87f6a73 	ldr	x19, [x19, xzr]
  dc:	cb3363f3 	sub	x19, sp, x19
  e0:	d2800014 	mov	x20, #0x0                   	// #0
  e4:	f2a00814 	movk	x20, #0x40, lsl #16
  e8:	eb14027f 	cmp	x19, x20
  ec:	54fffaab 	b.lt	40 <trap_handler+0x40>  // b.tstop
  f0:	d10043ff 	sub	sp, sp, #0x10
  f4:	b90013ff 	str	wzr, [sp, #16]
  f8:	f90007ff 	str	xzr, [sp, #8]
  fc:	b90007ff 	str	wzr, [sp, #4]
 100:	d29fffe8 	mov	x8, #0xffff                	// #65535
 104:	f2bfffe8 	movk	x8, #0xffff, lsl #16
 108:	f2dfffe8 	movk	x8, #0xffff, lsl #32
 10c:	f2efffe8 	movk	x8, #0x7fff, lsl #48
 110:	f90007e8 	str	x8, [sp, #8]
 114:	f94007e8 	ldr	x8, [sp, #8]
 118:	aa0803e0 	mov	x0, x8
 11c:	910043ff 	add	sp, sp, #0x10
 120:	a8c153f3 	ldp	x19, x20, [sp], #16
 124:	a8c17bfd 	ldp	x29, x30, [sp], #16
 128:	d65f03c0 	ret

000000000000012c <many_locals>:
 12c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 130:	910003fd 	mov	x29, sp
 134:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 138:	d2946413 	mov	x19, #0xa320                	// #41760
 13c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 140:	f2c00ab3 	movk	x19, #0x55, lsl #32
 144:	f87f6a73 	ldr	x19, [x19, xzr]
 148:	cb3363f3 	sub	x19, sp, x19
 14c:	d2800014 	mov	x20, #0x0                   	// #0
 150:	f2a00814 	movk	x20, #0x40, lsl #16
 154:	eb14027f 	cmp	x19, x20
 158:	54fff74b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 15c:	d101c3ff 	sub	sp, sp, #0x70
 160:	b90073e0 	str	w0, [sp, #112]
 164:	b9006fff 	str	wzr, [sp, #108]
 168:	b9006bff 	str	wzr, [sp, #104]
 16c:	b90067ff 	str	wzr, [sp, #100]
 170:	b90063ff 	str	wzr, [sp, #96]
 174:	b9005fff 	str	wzr, [sp, #92]
 178:	b9005bff 	str	wzr, [sp, #88]
 17c:	b90057ff 	str	wzr, [sp, #84]
 180:	b90053ff 	str	wzr, [sp, #80]
 184:	b9004fff 	str	wzr, [sp, #76]
 188:	b9004bff 	str	wzr, [sp, #72]
 18c:	b90047ff 	str	wzr, [sp, #68]
 190:	b90043ff 	str	wzr, [sp, #64]
 194:	f9001fff 	str	xzr, [sp, #56]
 198:	f9001bff 	str	xzr, [sp, #48]
 19c:	f90017ff 	str	xzr, [sp, #40]
 1a0:	b90027ff 	str	wzr, [sp, #36]
 1a4:	b90023ff 	str	wzr, [sp, #32]
 1a8:	b9001fff 	str	wzr, [sp, #28]
 1ac:	b9001bff 	str	wzr, [sp, #24]
 1b0:	b90017ff 	str	wzr, [sp, #20]
 1b4:	b90013ff 	str	wzr, [sp, #16]
 1b8:	b9000fff 	str	wzr, [sp, #12]
 1bc:	b94073e8 	ldr	w8, [sp, #112]
 1c0:	b9006fe8 	str	w8, [sp, #108]
 1c4:	b9406fe8 	ldr	w8, [sp, #108]
 1c8:	b9006be8 	str	w8, [sp, #104]
 1cc:	b9406be8 	ldr	w8, [sp, #104]
 1d0:	b90067e8 	str	w8, [sp, #100]
 1d4:	b94067e8 	ldr	w8, [sp, #100]
 1d8:	b90063e8 	str	w8, [sp, #96]
 1dc:	b94063e8 	ldr	w8, [sp, #96]
 1e0:	b9005fe8 	str	w8, [sp, #92]
 1e4:	b9405fe8 	ldr	w8, [sp, #92]
 1e8:	b9005be8 	str	w8, [sp, #88]
 1ec:	b9405be8 	ldr	w8, [sp, #88]
 1f0:	b90057e8 	str	w8, [sp, #84]
 1f4:	b94057e8 	ldr	w8, [sp, #84]
 1f8:	b90053e8 	str	w8, [sp, #80]
 1fc:	b94053e8 	ldr	w8, [sp, #80]
 200:	b9004fe8 	str	w8, [sp, #76]
 204:	b9404fe8 	ldr	w8, [sp, #76]
 208:	b9004be8 	str	w8, [sp, #72]
 20c:	b9404be8 	ldr	w8, [sp, #72]
 210:	b90047e8 	str	w8, [sp, #68]
 214:	b94047e8 	ldr	w8, [sp, #68]
 218:	b90043e8 	str	w8, [sp, #64]
 21c:	d2800028 	mov	x8, #0x1                   	// #1
 220:	f9001fe8 	str	x8, [sp, #56]
 224:	d2800048 	mov	x8, #0x2                   	// #2
 228:	f9001be8 	str	x8, [sp, #48]
 22c:	d2800068 	mov	x8, #0x3                   	// #3
 230:	f90017e8 	str	x8, [sp, #40]
 234:	b94043e8 	ldr	w8, [sp, #64]
 238:	b90027e8 	str	w8, [sp, #36]
 23c:	b94027e8 	ldr	w8, [sp, #36]
 240:	b90023e8 	str	w8, [sp, #32]
 244:	b94023e8 	ldr	w8, [sp, #32]
 248:	b9001fe8 	str	w8, [sp, #28]
 24c:	b9401fe8 	ldr	w8, [sp, #28]
 250:	b9001be8 	str	w8, [sp, #24]
 254:	b9401be8 	ldr	w8, [sp, #24]
 258:	b90017e8 	str	w8, [sp, #20]
 25c:	b94017e8 	ldr	w8, [sp, #20]
 260:	b90013e8 	str	w8, [sp, #16]
 264:	b94013e8 	ldr	w8, [sp, #16]
 268:	b9000fe8 	str	w8, [sp, #12]
 26c:	b9400fe8 	ldr	w8, [sp, #12]
 270:	2a0803e0 	mov	w0, w8
 274:	9101c3ff 	add	sp, sp, #0x70
 278:	a8c153f3 	ldp	x19, x20, [sp], #16
 27c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 280:	d65f03c0 	ret
