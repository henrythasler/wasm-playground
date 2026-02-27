
./tests/machinecode/local.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000050 type-local-i32
00000000000000ac g     F .text	0000000000000050 type-local-i64
00000000000000fc g     F .text	0000000000000050 type-param-i32
000000000000014c g     F .text	0000000000000050 type-param-i64


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
 0090 ff1300b9 e81340b9 e003082a ff430091  ......@....*.C..
 00a0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 00b0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 00c0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 00d0 1408a0f2 7f0214eb 4bfbff54 ff4300d1  ........K..T.C..
 00e0 ff0b00f9 e80b40f9 e00308aa ff430091  ......@......C..
 00f0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0100 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0110 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0120 1408a0f2 7f0214eb cbf8ff54 ff4300d1  ...........T.C..
 0130 e01300b9 e81340b9 e003082a ff430091  ......@....*.C..
 0140 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0150 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0160 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0170 1408a0f2 7f0214eb 4bf6ff54 ff4300d1  ........K..T.C..
 0180 e00b00f9 e80b40f9 e00308aa ff430091  ......@......C..
 0190 f353c1a8 fd7bc1a8 c0035fd6           .S...{...._.    

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
  94:	b94013e8 	ldr	w8, [sp, #16]
  98:	2a0803e0 	mov	w0, w8
  9c:	910043ff 	add	sp, sp, #0x10
  a0:	a8c153f3 	ldp	x19, x20, [sp], #16
  a4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  a8:	d65f03c0 	ret

00000000000000ac <type-local-i64>:
  ac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  b0:	910003fd 	mov	x29, sp
  b4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  b8:	d2946413 	mov	x19, #0xa320                	// #41760
  bc:	f2a016d3 	movk	x19, #0xb6, lsl #16
  c0:	f2c00ab3 	movk	x19, #0x55, lsl #32
  c4:	f87f6a73 	ldr	x19, [x19, xzr]
  c8:	cb3363f3 	sub	x19, sp, x19
  cc:	d2800014 	mov	x20, #0x0                   	// #0
  d0:	f2a00814 	movk	x20, #0x40, lsl #16
  d4:	eb14027f 	cmp	x19, x20
  d8:	54fffb4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
  dc:	d10043ff 	sub	sp, sp, #0x10
  e0:	f9000bff 	str	xzr, [sp, #16]
  e4:	f9400be8 	ldr	x8, [sp, #16]
  e8:	aa0803e0 	mov	x0, x8
  ec:	910043ff 	add	sp, sp, #0x10
  f0:	a8c153f3 	ldp	x19, x20, [sp], #16
  f4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  f8:	d65f03c0 	ret

00000000000000fc <type-param-i32>:
  fc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 100:	910003fd 	mov	x29, sp
 104:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 108:	d2946413 	mov	x19, #0xa320                	// #41760
 10c:	f2a016d3 	movk	x19, #0xb6, lsl #16
 110:	f2c00ab3 	movk	x19, #0x55, lsl #32
 114:	f87f6a73 	ldr	x19, [x19, xzr]
 118:	cb3363f3 	sub	x19, sp, x19
 11c:	d2800014 	mov	x20, #0x0                   	// #0
 120:	f2a00814 	movk	x20, #0x40, lsl #16
 124:	eb14027f 	cmp	x19, x20
 128:	54fff8cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 12c:	d10043ff 	sub	sp, sp, #0x10
 130:	b90013e0 	str	w0, [sp, #16]
 134:	b94013e8 	ldr	w8, [sp, #16]
 138:	2a0803e0 	mov	w0, w8
 13c:	910043ff 	add	sp, sp, #0x10
 140:	a8c153f3 	ldp	x19, x20, [sp], #16
 144:	a8c17bfd 	ldp	x29, x30, [sp], #16
 148:	d65f03c0 	ret

000000000000014c <type-param-i64>:
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
 17c:	d10043ff 	sub	sp, sp, #0x10
 180:	f9000be0 	str	x0, [sp, #16]
 184:	f9400be8 	ldr	x8, [sp, #16]
 188:	aa0803e0 	mov	x0, x8
 18c:	910043ff 	add	sp, sp, #0x10
 190:	a8c153f3 	ldp	x19, x20, [sp], #16
 194:	a8c17bfd 	ldp	x29, x30, [sp], #16
 198:	d65f03c0 	ret
