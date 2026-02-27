
./tests/machinecode/local.2.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000054 type-local-i32
00000000000000b0 g     F .text	0000000000000054 type-local-i64
0000000000000104 g     F .text	0000000000000054 type-param-i32
0000000000000158 g     F .text	0000000000000054 type-param-i64
00000000000001ac g     F .text	0000000000000054 as-local.set-value
0000000000000200 g     F .text	0000000000000058 as-local.tee-value


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
 0090 ff1300b9 28008052 e81300b9 e003082a  ....(..R.......*
 00a0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 00b0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 00c0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 00d0 140080d2 1408a0f2 7f0214eb 2bfbff54  ............+..T
 00e0 ff4300d1 ff0b00f9 280080d2 e80b00f9  .C......(.......
 00f0 e00308aa ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 0100 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0110 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0120 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0130 8bf8ff54 ff4300d1 e01300b9 48018052  ...T.C......H..R
 0140 e81300b9 e003082a ff430091 f353c1a8  .......*.C...S..
 0150 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0160 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0170 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0180 7f0214eb ebf5ff54 ff4300d1 e00b00f9  .......T.C......
 0190 680180d2 e80b00f9 e00308aa ff430091  h............C..
 01a0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 01b0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 01c0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 01d0 1408a0f2 7f0214eb 4bf3ff54 ff4300d1  ........K..T.C..
 01e0 ff1300b9 28008052 e81300b9 e81300b9  ....(..R........
 01f0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0200 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0210 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0220 140080d2 1408a0f2 7f0214eb abf0ff54  ...............T
 0230 ff4300d1 e01300b9 28008052 e81300b9  .C......(..R....
 0240 e81300b9 e003082a ff430091 f353c1a8  .......*.C...S..
 0250 fd7bc1a8 c0035fd6                    .{...._.        

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

000000000000005c <type-local-i32>:
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
  90:	b90013ff 	str	wzr, [sp, #16]
  94:	52800028 	mov	w8, #0x1                   	// #1
  98:	b90013e8 	str	w8, [sp, #16]
  9c:	2a0803e0 	mov	w0, w8
  a0:	910043ff 	add	sp, sp, #0x10
  a4:	a8c153f3 	ldp	x19, x20, [sp], #16
  a8:	a8c17bfd 	ldp	x29, x30, [sp], #16
  ac:	d65f03c0 	ret

00000000000000b0 <type-local-i64>:
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
  e0:	d10043ff 	sub	sp, sp, #0x10
  e4:	f9000bff 	str	xzr, [sp, #16]
  e8:	d2800028 	mov	x8, #0x1                   	// #1
  ec:	f9000be8 	str	x8, [sp, #16]
  f0:	aa0803e0 	mov	x0, x8
  f4:	910043ff 	add	sp, sp, #0x10
  f8:	a8c153f3 	ldp	x19, x20, [sp], #16
  fc:	a8c17bfd 	ldp	x29, x30, [sp], #16
 100:	d65f03c0 	ret

0000000000000104 <type-param-i32>:
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
 134:	d10043ff 	sub	sp, sp, #0x10
 138:	b90013e0 	str	w0, [sp, #16]
 13c:	52800148 	mov	w8, #0xa                   	// #10
 140:	b90013e8 	str	w8, [sp, #16]
 144:	2a0803e0 	mov	w0, w8
 148:	910043ff 	add	sp, sp, #0x10
 14c:	a8c153f3 	ldp	x19, x20, [sp], #16
 150:	a8c17bfd 	ldp	x29, x30, [sp], #16
 154:	d65f03c0 	ret

0000000000000158 <type-param-i64>:
 158:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 15c:	910003fd 	mov	x29, sp
 160:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 164:	d2946413 	mov	x19, #0xa320                	// #41760
 168:	f2a016d3 	movk	x19, #0xb6, lsl #16
 16c:	f2c00ab3 	movk	x19, #0x55, lsl #32
 170:	f87f6a73 	ldr	x19, [x19, xzr]
 174:	cb3363f3 	sub	x19, sp, x19
 178:	d2800014 	mov	x20, #0x0                   	// #0
 17c:	f2a00814 	movk	x20, #0x40, lsl #16
 180:	eb14027f 	cmp	x19, x20
 184:	54fff5eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 188:	d10043ff 	sub	sp, sp, #0x10
 18c:	f9000be0 	str	x0, [sp, #16]
 190:	d2800168 	mov	x8, #0xb                   	// #11
 194:	f9000be8 	str	x8, [sp, #16]
 198:	aa0803e0 	mov	x0, x8
 19c:	910043ff 	add	sp, sp, #0x10
 1a0:	a8c153f3 	ldp	x19, x20, [sp], #16
 1a4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a8:	d65f03c0 	ret

00000000000001ac <as-local.set-value>:
 1ac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 1b0:	910003fd 	mov	x29, sp
 1b4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 1b8:	d2946413 	mov	x19, #0xa320                	// #41760
 1bc:	f2a016d3 	movk	x19, #0xb6, lsl #16
 1c0:	f2c00ab3 	movk	x19, #0x55, lsl #32
 1c4:	f87f6a73 	ldr	x19, [x19, xzr]
 1c8:	cb3363f3 	sub	x19, sp, x19
 1cc:	d2800014 	mov	x20, #0x0                   	// #0
 1d0:	f2a00814 	movk	x20, #0x40, lsl #16
 1d4:	eb14027f 	cmp	x19, x20
 1d8:	54fff34b 	b.lt	40 <trap_handler+0x40>  // b.tstop
 1dc:	d10043ff 	sub	sp, sp, #0x10
 1e0:	b90013ff 	str	wzr, [sp, #16]
 1e4:	52800028 	mov	w8, #0x1                   	// #1
 1e8:	b90013e8 	str	w8, [sp, #16]
 1ec:	b90013e8 	str	w8, [sp, #16]
 1f0:	910043ff 	add	sp, sp, #0x10
 1f4:	a8c153f3 	ldp	x19, x20, [sp], #16
 1f8:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1fc:	d65f03c0 	ret

0000000000000200 <as-local.tee-value>:
 200:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 204:	910003fd 	mov	x29, sp
 208:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 20c:	d2946413 	mov	x19, #0xa320                	// #41760
 210:	f2a016d3 	movk	x19, #0xb6, lsl #16
 214:	f2c00ab3 	movk	x19, #0x55, lsl #32
 218:	f87f6a73 	ldr	x19, [x19, xzr]
 21c:	cb3363f3 	sub	x19, sp, x19
 220:	d2800014 	mov	x20, #0x0                   	// #0
 224:	f2a00814 	movk	x20, #0x40, lsl #16
 228:	eb14027f 	cmp	x19, x20
 22c:	54fff0ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 230:	d10043ff 	sub	sp, sp, #0x10
 234:	b90013e0 	str	w0, [sp, #16]
 238:	52800028 	mov	w8, #0x1                   	// #1
 23c:	b90013e8 	str	w8, [sp, #16]
 240:	b90013e8 	str	w8, [sp, #16]
 244:	2a0803e0 	mov	w0, w8
 248:	910043ff 	add	sp, sp, #0x10
 24c:	a8c153f3 	ldp	x19, x20, [sp], #16
 250:	a8c17bfd 	ldp	x29, x30, [sp], #16
 254:	d65f03c0 	ret
