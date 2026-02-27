
./tests/machinecode/block-extended.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000040 simple
000000000000009c g     F .text	000000000000004c simple-br-i32
00000000000000e8 g     F .text	000000000000004c simple-return
0000000000000134 g     F .text	0000000000000060 simple-br_if
0000000000000194 g     F .text	0000000000000078 parameter-br_if
000000000000020c g     F .text	000000000000006c parameter-nested-return
0000000000000278 g     F .text	0000000000000080 nested-br_if


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 e8078052  ...........T...R
 0090 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 00a0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 00b0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 00c0 1408a0f2 7f0214eb cbfbff54 48058052  ...........TH..R
 00d0 5f0000b4 68018052 e003082a f353c1a8  _...h..R...*.S..
 00e0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00f0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0100 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0110 7f0214eb 6bf9ff54 48058052 5f0000b4  ....k..TH..R_...
 0120 68018052 e003082a f353c1a8 fd7bc1a8  h..R...*.S...{..
 0130 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0140 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0150 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0160 0bf7ff54 08048052 09008052 c9000035  ...T...R...R...5
 0170 48058052 29008052 e803082a 49000035  H..R)..R...*I..5
 0180 68018052 e003082a f353c1a8 fd7bc1a8  h..R...*.S...{..
 0190 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01a0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01b0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01c0 0bf4ff54 ff4300d1 e01300b9 48058052  ...T.C......H..R
 01d0 e91340b9 29010035 88ff9f52 e8ffbf72  ..@.)..5...R...r
 01e0 a9ff9f52 e9ffbf72 caff9f52 eaffbf72  ...R...r...R...r
 01f0 ebff9f52 ebffbf72 e003082a ff430091  ...R...r...*.C..
 0200 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0210 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0220 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0230 1408a0f2 7f0214eb 4bf0ff54 ff4300d1  ........K..T.C..
 0240 e01300b9 08058052 e91340b9 89000035  .......R..@....5
 0250 88ff9f52 e8ffbf72 7f0000b4 49008052  ...R...r....I..R
 0260 0801090b e003082a ff430091 f353c1a8  .......*.C...S..
 0270 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0280 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0290 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 02a0 7f0214eb ebecff54 08048052 09008052  .......T...R...R
 02b0 a9000035 48058052 29008052 69010035  ...5H..R)..Ri..5
 02c0 68018052 48018052 09008052 e803082a  h..RH..R...R...*
 02d0 c9000035 88028052 29008052 e803082a  ...5...R)..R...*
 02e0 49000035 c8038052 e003082a f353c1a8  I..5...R...*.S..
 02f0 fd7bc1a8 c0035fd6                    .{...._.        

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

000000000000005c <simple>:
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
  8c:	528007e8 	mov	w8, #0x3f                  	// #63
  90:	a8c153f3 	ldp	x19, x20, [sp], #16
  94:	a8c17bfd 	ldp	x29, x30, [sp], #16
  98:	d65f03c0 	ret

000000000000009c <simple-br-i32>:
  9c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  a0:	910003fd 	mov	x29, sp
  a4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  a8:	d2946413 	mov	x19, #0xa320                	// #41760
  ac:	f2a016d3 	movk	x19, #0xb6, lsl #16
  b0:	f2c00ab3 	movk	x19, #0x55, lsl #32
  b4:	f87f6a73 	ldr	x19, [x19, xzr]
  b8:	cb3363f3 	sub	x19, sp, x19
  bc:	d2800014 	mov	x20, #0x0                   	// #0
  c0:	f2a00814 	movk	x20, #0x40, lsl #16
  c4:	eb14027f 	cmp	x19, x20
  c8:	54fffbcb 	b.lt	40 <trap_handler+0x40>  // b.tstop
  cc:	52800548 	mov	w8, #0x2a                  	// #42
  d0:	b400005f 	cbz	xzr, d8 <simple-br-i32+0x3c>
  d4:	52800168 	mov	w8, #0xb                   	// #11
  d8:	2a0803e0 	mov	w0, w8
  dc:	a8c153f3 	ldp	x19, x20, [sp], #16
  e0:	a8c17bfd 	ldp	x29, x30, [sp], #16
  e4:	d65f03c0 	ret

00000000000000e8 <simple-return>:
  e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  ec:	910003fd 	mov	x29, sp
  f0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  f4:	d2946413 	mov	x19, #0xa320                	// #41760
  f8:	f2a016d3 	movk	x19, #0xb6, lsl #16
  fc:	f2c00ab3 	movk	x19, #0x55, lsl #32
 100:	f87f6a73 	ldr	x19, [x19, xzr]
 104:	cb3363f3 	sub	x19, sp, x19
 108:	d2800014 	mov	x20, #0x0                   	// #0
 10c:	f2a00814 	movk	x20, #0x40, lsl #16
 110:	eb14027f 	cmp	x19, x20
 114:	54fff96b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 118:	52800548 	mov	w8, #0x2a                  	// #42
 11c:	b400005f 	cbz	xzr, 124 <simple-return+0x3c>
 120:	52800168 	mov	w8, #0xb                   	// #11
 124:	2a0803e0 	mov	w0, w8
 128:	a8c153f3 	ldp	x19, x20, [sp], #16
 12c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 130:	d65f03c0 	ret

0000000000000134 <simple-br_if>:
 134:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 138:	910003fd 	mov	x29, sp
 13c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 140:	d2946413 	mov	x19, #0xa320                	// #41760
 144:	f2a016d3 	movk	x19, #0xb6, lsl #16
 148:	f2c00ab3 	movk	x19, #0x55, lsl #32
 14c:	f87f6a73 	ldr	x19, [x19, xzr]
 150:	cb3363f3 	sub	x19, sp, x19
 154:	d2800014 	mov	x20, #0x0                   	// #0
 158:	f2a00814 	movk	x20, #0x40, lsl #16
 15c:	eb14027f 	cmp	x19, x20
 160:	54fff70b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 164:	52800408 	mov	w8, #0x20                  	// #32
 168:	52800009 	mov	w9, #0x0                   	// #0
 16c:	350000c9 	cbnz	w9, 184 <simple-br_if+0x50>
 170:	52800548 	mov	w8, #0x2a                  	// #42
 174:	52800029 	mov	w9, #0x1                   	// #1
 178:	2a0803e8 	mov	w8, w8
 17c:	35000049 	cbnz	w9, 184 <simple-br_if+0x50>
 180:	52800168 	mov	w8, #0xb                   	// #11
 184:	2a0803e0 	mov	w0, w8
 188:	a8c153f3 	ldp	x19, x20, [sp], #16
 18c:	a8c17bfd 	ldp	x29, x30, [sp], #16
 190:	d65f03c0 	ret

0000000000000194 <parameter-br_if>:
 194:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 198:	910003fd 	mov	x29, sp
 19c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1a0:	d2946413 	mov	x19, #0xa320                	// #41760
 1a4:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1a8:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1ac:	f87f6a73 	ldr	x19, [x19, xzr]
 1b0:	cb3363f3 	sub	x19, sp, x19
 1b4:	d2800014 	mov	x20, #0x0                   	// #0
 1b8:	f2a00814 	movk	x20, #0x40, lsl #16
 1bc:	eb14027f 	cmp	x19, x20
 1c0:	54fff40b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1c4:	d10043ff 	sub	sp, sp, #0x10
 1c8:	b90013e0 	str	w0, [sp, #16]
 1cc:	52800548 	mov	w8, #0x2a                  	// #42
 1d0:	b94013e9 	ldr	w9, [sp, #16]
 1d4:	35000129 	cbnz	w9, 1f8 <parameter-br_if+0x64>
 1d8:	529fff88 	mov	w8, #0xfffc                	// #65532
 1dc:	72bfffe8 	movk	w8, #0xffff, lsl #16
 1e0:	529fffa9 	mov	w9, #0xfffd                	// #65533
 1e4:	72bfffe9 	movk	w9, #0xffff, lsl #16
 1e8:	529fffca 	mov	w10, #0xfffe                	// #65534
 1ec:	72bfffea 	movk	w10, #0xffff, lsl #16
 1f0:	529fffeb 	mov	w11, #0xffff                	// #65535
 1f4:	72bfffeb 	movk	w11, #0xffff, lsl #16
 1f8:	2a0803e0 	mov	w0, w8
 1fc:	910043ff 	add	sp, sp, #0x10
 200:	a8c153f3 	ldp	x19, x20, [sp], #16
 204:	a8c17bfd 	ldp	x29, x30, [sp], #16
 208:	d65f03c0 	ret

000000000000020c <parameter-nested-return>:
 20c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 210:	910003fd 	mov	x29, sp
 214:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 218:	d2946413 	mov	x19, #0xa320                	// #41760
 21c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 220:	f2c00ab3 	movk	x19, #0x55, lsl #32
 224:	f87f6a73 	ldr	x19, [x19, xzr]
 228:	cb3363f3 	sub	x19, sp, x19
 22c:	d2800014 	mov	x20, #0x0                   	// #0
 230:	f2a00814 	movk	x20, #0x40, lsl #16
 234:	eb14027f 	cmp	x19, x20
 238:	54fff04b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 23c:	d10043ff 	sub	sp, sp, #0x10
 240:	b90013e0 	str	w0, [sp, #16]
 244:	52800508 	mov	w8, #0x28                  	// #40
 248:	b94013e9 	ldr	w9, [sp, #16]
 24c:	35000089 	cbnz	w9, 25c <parameter-nested-return+0x50>
 250:	529fff88 	mov	w8, #0xfffc                	// #65532
 254:	72bfffe8 	movk	w8, #0xffff, lsl #16
 258:	b400007f 	cbz	xzr, 264 <parameter-nested-return+0x58>
 25c:	52800049 	mov	w9, #0x2                   	// #2
 260:	0b090108 	add	w8, w8, w9
 264:	2a0803e0 	mov	w0, w8
 268:	910043ff 	add	sp, sp, #0x10
 26c:	a8c153f3 	ldp	x19, x20, [sp], #16
 270:	a8c17bfd 	ldp	x29, x30, [sp], #16
 274:	d65f03c0 	ret

0000000000000278 <nested-br_if>:
 278:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 27c:	910003fd 	mov	x29, sp
 280:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 284:	d2946413 	mov	x19, #0xa320                	// #41760
 288:	f2a016d3 	movk	x19, #0xb6, lsl #16
 28c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 290:	f87f6a73 	ldr	x19, [x19, xzr]
 294:	cb3363f3 	sub	x19, sp, x19
 298:	d2800014 	mov	x20, #0x0                   	// #0
 29c:	f2a00814 	movk	x20, #0x40, lsl #16
 2a0:	eb14027f 	cmp	x19, x20
 2a4:	54ffeceb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 2a8:	52800408 	mov	w8, #0x20                  	// #32
 2ac:	52800009 	mov	w9, #0x0                   	// #0
 2b0:	350000a9 	cbnz	w9, 2c4 <nested-br_if+0x4c>
 2b4:	52800548 	mov	w8, #0x2a                  	// #42
 2b8:	52800029 	mov	w9, #0x1                   	// #1
 2bc:	35000169 	cbnz	w9, 2e8 <nested-br_if+0x70>
 2c0:	52800168 	mov	w8, #0xb                   	// #11
 2c4:	52800148 	mov	w8, #0xa                   	// #10
 2c8:	52800009 	mov	w9, #0x0                   	// #0
 2cc:	2a0803e8 	mov	w8, w8
 2d0:	350000c9 	cbnz	w9, 2e8 <nested-br_if+0x70>
 2d4:	52800288 	mov	w8, #0x14                  	// #20
 2d8:	52800029 	mov	w9, #0x1                   	// #1
 2dc:	2a0803e8 	mov	w8, w8
 2e0:	35000049 	cbnz	w9, 2e8 <nested-br_if+0x70>
 2e4:	528003c8 	mov	w8, #0x1e                  	// #30
 2e8:	2a0803e0 	mov	w0, w8
 2ec:	a8c153f3 	ldp	x19, x20, [sp], #16
 2f0:	a8c17bfd 	ldp	x29, x30, [sp], #16
 2f4:	d65f03c0 	ret
