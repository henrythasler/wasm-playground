
./tests/machinecode/conditionals.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	0000000000000080 singular
00000000000000dc g     F .text	0000000000000064 as-return-value
0000000000000140 g     F .text	000000000000006c as-local.set-value
00000000000001ac g     F .text	0000000000000064 as-local.tee-value


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
 0090 e01300b9 e81340b9 48000034 1f2003d5  ......@.H..4. ..
 00a0 e81340b9 68000034 1f2003d5 02000014  ..@.h..4. ......
 00b0 1f2003d5 e81340b9 68000034 e8008052  . ....@.h..4...R
 00c0 02000014 08018052 e003082a ff430091  .......R...*.C..
 00d0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 00e0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 00f0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0100 1408a0f2 7f0214eb cbf9ff54 ff4300d1  ...........T.C..
 0110 e01300b9 e81340b9 68000034 28008052  ......@.h..4(..R
 0120 02000014 08008052 3f0000b4 e003082a  .......R?......*
 0130 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0140 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0150 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0160 140080d2 1408a0f2 7f0214eb abf6ff54  ...............T
 0170 ff4300d1 e01300b9 ff0f00b9 e81340b9  .C............@.
 0180 68000034 28008052 02000014 08008052  h..4(..R.......R
 0190 e81300b9 e81340b9 e003082a ff430091  ......@....*.C..
 01a0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 01b0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 01c0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 01d0 1408a0f2 7f0214eb 4bf3ff54 ff4300d1  ........K..T.C..
 01e0 e01300b9 e81340b9 68000034 28008052  ......@.h..4(..R
 01f0 02000014 08008052 e81300b9 e003082a  .......R.......*
 0200 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.

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

000000000000005c <singular>:
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
  98:	34000048 	cbz	w8, a0 <singular+0x44>
  9c:	d503201f 	nop
  a0:	b94013e8 	ldr	w8, [sp, #16]
  a4:	34000068 	cbz	w8, b0 <singular+0x54>
  a8:	d503201f 	nop
  ac:	14000002 	b	b4 <singular+0x58>
  b0:	d503201f 	nop
  b4:	b94013e8 	ldr	w8, [sp, #16]
  b8:	34000068 	cbz	w8, c4 <singular+0x68>
  bc:	528000e8 	mov	w8, #0x7                   	// #7
  c0:	14000002 	b	c8 <singular+0x6c>
  c4:	52800108 	mov	w8, #0x8                   	// #8
  c8:	2a0803e0 	mov	w0, w8
  cc:	910043ff 	add	sp, sp, #0x10
  d0:	a8c153f3 	ldp	x19, x20, [sp], #16
  d4:	a8c17bfd 	ldp	x29, x30, [sp], #16
  d8:	d65f03c0 	ret

00000000000000dc <as-return-value>:
  dc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
  e0:	910003fd 	mov	x29, sp
  e4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
  e8:	d2946413 	mov	x19, #0xa320                	// #41760
  ec:	f2a016d3 	movk	x19, #0xb6, lsl #16
  f0:	f2c00ab3 	movk	x19, #0x55, lsl #32
  f4:	f87f6a73 	ldr	x19, [x19, xzr]
  f8:	cb3363f3 	sub	x19, sp, x19
  fc:	d2800014 	mov	x20, #0x0                   	// #0
 100:	f2a00814 	movk	x20, #0x40, lsl #16
 104:	eb14027f 	cmp	x19, x20
 108:	54fff9cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
 10c:	d10043ff 	sub	sp, sp, #0x10
 110:	b90013e0 	str	w0, [sp, #16]
 114:	b94013e8 	ldr	w8, [sp, #16]
 118:	34000068 	cbz	w8, 124 <as-return-value+0x48>
 11c:	52800028 	mov	w8, #0x1                   	// #1
 120:	14000002 	b	128 <as-return-value+0x4c>
 124:	52800008 	mov	w8, #0x0                   	// #0
 128:	b400003f 	cbz	xzr, 12c <as-return-value+0x50>
 12c:	2a0803e0 	mov	w0, w8
 130:	910043ff 	add	sp, sp, #0x10
 134:	a8c153f3 	ldp	x19, x20, [sp], #16
 138:	a8c17bfd 	ldp	x29, x30, [sp], #16
 13c:	d65f03c0 	ret

0000000000000140 <as-local.set-value>:
 140:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
 144:	910003fd 	mov	x29, sp
 148:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
 14c:	d2946413 	mov	x19, #0xa320                	// #41760
 150:	f2a016d3 	movk	x19, #0xb6, lsl #16
 154:	f2c00ab3 	movk	x19, #0x55, lsl #32
 158:	f87f6a73 	ldr	x19, [x19, xzr]
 15c:	cb3363f3 	sub	x19, sp, x19
 160:	d2800014 	mov	x20, #0x0                   	// #0
 164:	f2a00814 	movk	x20, #0x40, lsl #16
 168:	eb14027f 	cmp	x19, x20
 16c:	54fff6ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
 170:	d10043ff 	sub	sp, sp, #0x10
 174:	b90013e0 	str	w0, [sp, #16]
 178:	b9000fff 	str	wzr, [sp, #12]
 17c:	b94013e8 	ldr	w8, [sp, #16]
 180:	34000068 	cbz	w8, 18c <as-local.set-value+0x4c>
 184:	52800028 	mov	w8, #0x1                   	// #1
 188:	14000002 	b	190 <as-local.set-value+0x50>
 18c:	52800008 	mov	w8, #0x0                   	// #0
 190:	b90013e8 	str	w8, [sp, #16]
 194:	b94013e8 	ldr	w8, [sp, #16]
 198:	2a0803e0 	mov	w0, w8
 19c:	910043ff 	add	sp, sp, #0x10
 1a0:	a8c153f3 	ldp	x19, x20, [sp], #16
 1a4:	a8c17bfd 	ldp	x29, x30, [sp], #16
 1a8:	d65f03c0 	ret

00000000000001ac <as-local.tee-value>:
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
 1e0:	b90013e0 	str	w0, [sp, #16]
 1e4:	b94013e8 	ldr	w8, [sp, #16]
 1e8:	34000068 	cbz	w8, 1f4 <as-local.tee-value+0x48>
 1ec:	52800028 	mov	w8, #0x1                   	// #1
 1f0:	14000002 	b	1f8 <as-local.tee-value+0x4c>
 1f4:	52800008 	mov	w8, #0x0                   	// #0
 1f8:	b90013e8 	str	w8, [sp, #16]
 1fc:	2a0803e0 	mov	w0, w8
 200:	910043ff 	add	sp, sp, #0x10
 204:	a8c153f3 	ldp	x19, x20, [sp], #16
 208:	a8c17bfd 	ldp	x29, x30, [sp], #16
 20c:	d65f03c0 	ret
