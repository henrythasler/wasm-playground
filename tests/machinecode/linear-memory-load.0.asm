
./tests/machinecode/linear-memory-load.0.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
000000000000005c g     F .text	000000000000007c as-br-value
00000000000000d8 g     F .text	0000000000000078 as-br_if-cond
0000000000000150 g     F .text	0000000000000088 as-br_if-value
00000000000001d8 g     F .text	0000000000000084 as-br_if-value-cond
000000000000025c g     F .text	000000000000007c as-return-value
00000000000002d8 g     F .text	0000000000000088 as-if-cond
0000000000000360 g     F .text	0000000000000088 as-if-then
00000000000003e8 g     F .text	0000000000000088 as-if-else
0000000000000470 g     F .text	00000000000000bc as-call-first
000000000000052c g     F .text	00000000000000bc as-call-mid
00000000000005e8 g     F .text	00000000000000bc as-call-last
00000000000006a4 g     F .text	000000000000005c func_11
0000000000000700 g     F .text	0000000000000084 as-local.set-value
0000000000000784 g     F .text	0000000000000088 as-local.tee-value
000000000000080c g     F .text	0000000000000098 as-global.set-value
00000000000008a4 g     F .text	00000000000000ac as-load-address
0000000000000950 g     F .text	00000000000000ac as-loadN-address
00000000000009fc g     F .text	00000000000000ac as-store-address
0000000000000aa8 g     F .text	00000000000000ac as-store-value
0000000000000b54 g     F .text	00000000000000ac as-storeN-address
0000000000000c00 g     F .text	00000000000000ac as-storeN-value
0000000000000cac g     F .text	000000000000007c as-unary-operand
0000000000000d28 g     F .text	0000000000000080 as-binary-left
0000000000000da8 g     F .text	0000000000000080 as-binary-right
0000000000000e28 g     F .text	0000000000000088 as-test-operand
0000000000000eb0 g     F .text	0000000000000090 as-compare-left
0000000000000f40 g     F .text	0000000000000090 as-compare-right
0000000000000fd0 g     F .text	00000000000000a4 as-memory.grow-size
0000000000001074 g     F .text	00000000000000b0 address-as-param
0000000000000000 g     O .rodata	0000000000000008 globals


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 fd7bbfa9  ........ ....{..
 0060 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0070 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0080 1408a0f2 7f0214eb cbfdff54 08008052  ...........T...R
 0090 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 00a0 c9fcffb4 0a7094d2 ca16a0f2 aa0ac0f2  .....p..........
 00b0 4a697fb8 4a110051 1f010a6b e8fbff54  Ji..J..Q...k...T
 00c0 2969a8b8 3f0000b4 e003092a f353c1a8  )i..?......*.S..
 00d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0100 7f0214eb ebf9ff54 08008052 096c94d2  .......T...R.l..
 0110 c916a0f2 a90ac0f2 29697ff8 e9f8ffb4  ........)i......
 0120 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0130 4a110051 1f010a6b 08f8ff54 2969a8b8  J..Q...k...T)i..
 0140 29000035 f353c1a8 fd7bc1a8 c0035fd6  )..5.S...{...._.
 0150 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0160 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0170 140080d2 1408a0f2 7f0214eb 2bf6ff54  ............+..T
 0180 08008052 096c94d2 c916a0f2 a90ac0f2  ...R.l..........
 0190 29697ff8 29f5ffb4 0a7094d2 ca16a0f2  )i..)....p......
 01a0 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 01b0 48f4ff54 2969a8b8 28008052 68000035  H..T)i..(..Rh..5
 01c0 e8008052 e903082a e003092a f353c1a8  ...R...*...*.S..
 01d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 01e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 01f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0200 7f0214eb ebf1ff54 c8008052 09008052  .......T...R...R
 0210 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0220 caf0ffb4 0b7094d2 cb16a0f2 ab0ac0f2  .....p..........
 0230 6b697fb8 6b110051 3f010b6b e8efff54  ki..k..Q?..k...T
 0240 4a69a9b8 4a000035 e8008052 e003082a  Ji..J..5...R...*
 0250 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0260 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0270 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0280 1408a0f2 7f0214eb cbedff54 08008052  ...........T...R
 0290 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 02a0 c9ecffb4 0a7094d2 ca16a0f2 aa0ac0f2  .....p..........
 02b0 4a697fb8 4a110051 1f010a6b e8ebff54  Ji..J..Q...k...T
 02c0 2969a8b8 3f0000b4 e003092a f353c1a8  )i..?......*.S..
 02d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 02e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 02f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0300 7f0214eb ebe9ff54 08008052 096c94d2  .......T...R.l..
 0310 c916a0f2 a90ac0f2 29697ff8 e9e8ffb4  ........)i......
 0320 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0330 4a110051 1f010a6b 08e8ff54 2969a8b8  J..Q...k...T)i..
 0340 69000034 08008052 02000014 28008052  i..4...R....(..R
 0350 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0360 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0370 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0380 140080d2 1408a0f2 7f0214eb abe5ff54  ...............T
 0390 28008052 08020034 08008052 096c94d2  (..R...4...R.l..
 03a0 c916a0f2 a90ac0f2 29697ff8 69e4ffb4  ........)i..i...
 03b0 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 03c0 4a110051 1f010a6b 88e3ff54 2969a8b8  J..Q...k...T)i..
 03d0 02000014 08008052 e003082a f353c1a8  .......R...*.S..
 03e0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 03f0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0400 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0410 7f0214eb 6be1ff54 08008052 68000034  ....k..T...Rh..4
 0420 08008052 0f000014 08008052 096c94d2  ...R.......R.l..
 0430 c916a0f2 a90ac0f2 29697ff8 e9dfffb4  ........)i......
 0440 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0450 4a110051 1f010a6b 08dfff54 2969a8b8  J..Q...k...T)i..
 0460 e003092a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0470 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0480 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0490 140080d2 1408a0f2 7f0214eb 2bddff54  ............+..T
 04a0 08008052 096c94d2 c916a0f2 a90ac0f2  ...R.l..........
 04b0 29697ff8 29dcffb4 0a7094d2 ca16a0f2  )i..)....p......
 04c0 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 04d0 48dbff54 2969a8b8 48008052 6a008052  H..T)i..H..Rj..R
 04e0 e2030a2a e103082a e003092a ff0301d1  ...*...*...*....
 04f0 e82703a9 ea2f02a9 ec3701a9 ee3f00a9  .'.../...7...?..
 0500 69000094 e82743a9 ea2f42a9 ec3741a9  i....'C../B..7A.
 0510 ee3f40a9 ff030191 e80300aa e003082a  .?@............*
 0520 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0530 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0540 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0550 1408a0f2 7f0214eb 4bd7ff54 28008052  ........K..T(..R
 0560 09008052 0a6c94d2 ca16a0f2 aa0ac0f2  ...R.l..........
 0570 4a697ff8 2ad6ffb4 0b7094d2 cb16a0f2  Ji..*....p......
 0580 ab0ac0f2 6b697fb8 6b110051 3f010b6b  ....ki..k..Q?..k
 0590 48d5ff54 4a69a9b8 69008052 e203092a  H..TJi..i..R...*
 05a0 e1030a2a e003082a ff0301d1 e82703a9  ...*...*.....'..
 05b0 ea2f02a9 ec3701a9 ee3f00a9 3a000094  ./...7...?..:...
 05c0 e82743a9 ea2f42a9 ec3741a9 ee3f40a9  .'C../B..7A..?@.
 05d0 ff030191 e80300aa e003082a f353c1a8  ...........*.S..
 05e0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 05f0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0600 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0610 7f0214eb 6bd1ff54 28008052 49008052  ....k..T(..RI..R
 0620 0a008052 0b6c94d2 cb16a0f2 ab0ac0f2  ...R.l..........
 0630 6b697ff8 2bd0ffb4 0c7094d2 cc16a0f2  ki..+....p......
 0640 ac0ac0f2 8c697fb8 8c110051 5f010c6b  .....i.....Q_..k
 0650 48cfff54 6b69aab8 e2030b2a e103092a  H..Tki.....*...*
 0660 e003082a ff0301d1 e82703a9 ea2f02a9  ...*.....'.../..
 0670 ec3701a9 ee3f00a9 0b000094 e82743a9  .7...?.......'C.
 0680 ea2f42a9 ec3741a9 ee3f40a9 ff030191  ./B..7A..?@.....
 0690 e80300aa e003082a f353c1a8 fd7bc1a8  .......*.S...{..
 06a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 06b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 06c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 06d0 8bcbff54 ff4300d1 e01300b9 e10f00b9  ...T.C..........
 06e0 e20b00b9 e8ff9f52 e8ffbf72 e003082a  .......R...r...*
 06f0 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0700 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0710 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0720 140080d2 1408a0f2 7f0214eb abc8ff54  ...............T
 0730 ff4300d1 ff1300b9 08008052 096c94d2  .C.........R.l..
 0740 c916a0f2 a90ac0f2 29697ff8 69c7ffb4  ........)i..i...
 0750 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0760 4a110051 1f010a6b 88c6ff54 2969a8b8  J..Q...k...T)i..
 0770 e91300b9 ff430091 f353c1a8 fd7bc1a8  .....C...S...{..
 0780 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0790 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 07a0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 07b0 8bc4ff54 ff4300d1 ff1300b9 08008052  ...T.C.........R
 07c0 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 07d0 49c3ffb4 0a7094d2 ca16a0f2 aa0ac0f2  I....p..........
 07e0 4a697fb8 4a110051 1f010a6b 68c2ff54  Ji..J..Q...kh..T
 07f0 2969a8b8 e91300b9 e003092a ff430091  )i.........*.C..
 0800 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0810 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0820 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0830 1408a0f2 7f0214eb 4bc0ff54 ff4300d1  ........K..T.C..
 0840 ff1300b9 08008052 096c94d2 c916a0f2  .......R.l......
 0850 a90ac0f2 29697ff8 09bfffb4 0a7094d2  ....)i.......p..
 0860 ca16a0f2 aa0ac0f2 4a697fb8 4a110051  ........Ji..J..Q
 0870 1f010a6b 28beff54 2969a8b8 086294d2  ...k(..T)i...b..
 0880 c816a0f2 a80ac0f2 08697ff8 08010091  .........i......
 0890 09693ff8 ff430091 f353c1a8 fd7bc1a8  .i?..C...S...{..
 08a0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 08b0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 08c0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 08d0 8bbbff54 08008052 096c94d2 c916a0f2  ...T...R.l......
 08e0 a90ac0f2 29697ff8 89baffb4 0a7094d2  ....)i.......p..
 08f0 ca16a0f2 aa0ac0f2 4a697fb8 4a110051  ........Ji..J..Q
 0900 1f010a6b a8b9ff54 2969a8b8 086c94d2  ...k...T)i...l..
 0910 c816a0f2 a80ac0f2 08697ff8 e8b8ffb4  .........i......
 0920 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0930 4a110051 3f010a6b 08b8ff54 0869a9b8  J..Q?..k...T.i..
 0940 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0950 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0960 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0970 140080d2 1408a0f2 7f0214eb 2bb6ff54  ............+..T
 0980 08008052 096c94d2 c916a0f2 a90ac0f2  ...R.l..........
 0990 29697ff8 29b5ffb4 0a7094d2 ca16a0f2  )i..)....p......
 09a0 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 09b0 48b4ff54 2969a8b8 086c94d2 c816a0f2  H..T)i...l......
 09c0 a80ac0f2 08697ff8 88b3ff34 0a7094d2  .....i.....4.p..
 09d0 ca16a0f2 aa0ac0f2 4a697fb8 4a050051  ........Ji..J..Q
 09e0 3f010a6b a8b2ff54 0879e938 e003082a  ?..k...T.y.8...*
 09f0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0a00 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0a10 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0a20 1408a0f2 7f0214eb cbb0ff54 08008052  ...........T...R
 0a30 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 0a40 c9afffb4 0a7094d2 ca16a0f2 aa0ac0f2  .....p..........
 0a50 4a697fb8 4a110051 1f010a6b e8aeff54  Ji..J..Q...k...T
 0a60 2969a8b8 e8008052 0a6c94d2 ca16a0f2  )i.....R.l......
 0a70 aa0ac0f2 4a697ff8 0aaeff34 0b7094d2  ....Ji.....4.p..
 0a80 cb16a0f2 ab0ac0f2 6b697fb8 6b110051  ........ki..k..Q
 0a90 3f010b6b 28adff54 486929b8 f353c1a8  ?..k(..THi)..S..
 0aa0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0ab0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0ac0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0ad0 7f0214eb 6babff54 48008052 09008052  ....k..TH..R...R
 0ae0 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0af0 4aaaffb4 0b7094d2 cb16a0f2 ab0ac0f2  J....p..........
 0b00 6b697fb8 6b110051 3f010b6b 68a9ff54  ki..k..Q?..kh..T
 0b10 4a69a9b8 096c94d2 c916a0f2 a90ac0f2  Ji...l..........
 0b20 29697ff8 a9a8ff34 0b7094d2 cb16a0f2  )i.....4.p......
 0b30 ab0ac0f2 6b697fb8 6b110051 1f010b6b  ....ki..k..Q...k
 0b40 c8a7ff54 2a6928b8 f353c1a8 fd7bc1a8  ...T*i(..S...{..
 0b50 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0b60 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0b70 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0b80 0ba6ff54 08008052 096c94d2 c916a0f2  ...T...R.l......
 0b90 a90ac0f2 29697ff8 09a5ff34 0a7094d2  ....)i.....4.p..
 0ba0 ca16a0f2 aa0ac0f2 4a697fb8 4a050051  ........Ji..J..Q
 0bb0 1f010a6b 28a4ff54 2979e838 e8008052  ...k(..T)y.8...R
 0bc0 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0bd0 4aa3ff34 0b7094d2 cb16a0f2 ab0ac0f2  J..4.p..........
 0be0 6b697fb8 6b050051 3f010b6b 68a2ff54  ki..k..Q?..kh..T
 0bf0 48792938 f353c1a8 fd7bc1a8 c0035fd6  Hy)8.S...{...._.
 0c00 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0c10 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0c20 140080d2 1408a0f2 7f0214eb aba0ff54  ...............T
 0c30 48008052 09008052 0a6c94d2 ca16a0f2  H..R...R.l......
 0c40 aa0ac0f2 4a697ff8 8a9fffb4 0b7094d2  ....Ji.......p..
 0c50 cb16a0f2 ab0ac0f2 6b697fb8 6b110051  ........ki..k..Q
 0c60 3f010b6b a89eff54 4a69a9b8 096c94d2  ?..k...TJi...l..
 0c70 c916a0f2 a90ac0f2 29697ff8 e99dff34  ........)i.....4
 0c80 0b7094d2 cb16a0f2 ab0ac0f2 6b697fb8  .p..........ki..
 0c90 6b090051 1f010b6b 089dff54 2a692878  k..Q...k...T*i(x
 0ca0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0cb0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0cc0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0cd0 1408a0f2 7f0214eb 4b9bff54 880c8052  ........K..T...R
 0ce0 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 0cf0 499affb4 0a7094d2 ca16a0f2 aa0ac0f2  I....p..........
 0d00 4a697fb8 4a110051 1f010a6b 6899ff54  Ji..J..Q...kh..T
 0d10 2969a8b8 2911c05a e003092a f353c1a8  )i..)..Z...*.S..
 0d20 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0d30 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0d40 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0d50 7f0214eb 6b97ff54 880c8052 096c94d2  ....k..T...R.l..
 0d60 c916a0f2 a90ac0f2 29697ff8 6996ffb4  ........)i..i...
 0d70 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0d80 4a110051 1f010a6b 8895ff54 2969a8b8  J..Q...k...T)i..
 0d90 48018052 2901080b e003092a f353c1a8  H..R)......*.S..
 0da0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0db0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0dc0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0dd0 7f0214eb 6b93ff54 48018052 890c8052  ....k..TH..R...R
 0de0 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0df0 4a92ffb4 0b7094d2 cb16a0f2 ab0ac0f2  J....p..........
 0e00 6b697fb8 6b110051 3f010b6b 6891ff54  ki..k..Q?..kh..T
 0e10 4a69a9b8 08010a4b e003082a f353c1a8  Ji.....K...*.S..
 0e20 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0e30 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0e40 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0e50 7f0214eb 6b8fff54 880c8052 096c94d2  ....k..T...R.l..
 0e60 c916a0f2 a90ac0f2 29697ff8 698effb4  ........)i..i...
 0e70 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0e80 4a110051 1f010a6b 888dff54 2969a8b8  J..Q...k...T)i..
 0e90 69000034 09008052 02000014 29008052  i..4...R....)..R
 0ea0 e003092a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0eb0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0ec0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0ed0 140080d2 1408a0f2 7f0214eb 2b8bff54  ............+..T
 0ee0 880c8052 096c94d2 c916a0f2 a90ac0f2  ...R.l..........
 0ef0 29697ff8 298affb4 0a7094d2 ca16a0f2  )i..)....p......
 0f00 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 0f10 4889ff54 2969a8b8 48018052 3f01086b  H..T)i..H..R?..k
 0f20 6d000054 09008052 02000014 29008052  m..T...R....)..R
 0f30 e003092a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0f40 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0f50 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0f60 140080d2 1408a0f2 7f0214eb ab86ff54  ...............T
 0f70 48018052 890c8052 0a6c94d2 ca16a0f2  H..R...R.l......
 0f80 aa0ac0f2 4a697ff8 8a85ffb4 0b7094d2  ....Ji.......p..
 0f90 cb16a0f2 ab0ac0f2 6b697fb8 6b110051  ........ki..k..Q
 0fa0 3f010b6b a884ff54 4a69a9b8 1f010aeb  ?..k...TJi......
 0fb0 61000054 08008052 02000014 28008052  a..T...R....(..R
 0fc0 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0fd0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0fe0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0ff0 140080d2 1408a0f2 7f0214eb 2b82ff54  ............+..T
 1000 880c8052 096c94d2 c916a0f2 a90ac0f2  ...R.l..........
 1010 29697ff8 2981ffb4 0a7094d2 ca16a0f2  )i..)....p......
 1020 aa0ac0f2 4a697fb8 4a110051 1f010a6b  ....Ji..J..Q...k
 1030 4880ff54 2969a8b8 087294d2 c816a0f2  H..T)i...r......
 1040 a80ac0f2 08697ff8 006694d2 c016a0f2  .....i...f......
 1050 a00ac0f2 00687ff8 e10309aa 00013fd6  .....h........?.
 1060 e80300aa e003082a f353c1a8 fd7bc1a8  .......*.S...{..
 1070 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 1080 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 1090 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 10a0 0b7dff54 ff4300d1 e01300b9 e81340b9  .}.T.C........@.
 10b0 096c94d2 c916a0f2 a90ac0f2 29697ff8  .l..........)i..
 10c0 c97bffb4 0a7094d2 ca16a0f2 aa0ac0f2  .{...p..........
 10d0 4a697fb8 4a110051 1f010a6b e87aff54  Ji..J..Q...k.z.T
 10e0 2969a8b8 087294d2 c816a0f2 a80ac0f2  )i...r..........
 10f0 08697ff8 006694d2 c016a0f2 a00ac0f2  .i...f..........
 1100 00687ff8 e10309aa 00013fd6 e80300aa  .h........?.....
 1110 e003082a ff430091 f353c1a8 fd7bc1a8  ...*.C...S...{..
 1120 c0035fd6                             .._.            
Contents of section .data:
 0000 00000000 00000000                    ........        

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

000000000000005c <as-br-value>:
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
      8c:	52800008 	mov	w8, #0x0                   	// #0
      90:	d2946c09 	mov	x9, #0xa360                	// #41824
      94:	f2a016c9 	movk	x9, #0xb6, lsl #16
      98:	f2c00aa9 	movk	x9, #0x55, lsl #32
      9c:	f87f6929 	ldr	x9, [x9, xzr]
      a0:	b4fffcc9 	cbz	x9, 38 <trap_handler+0x38>
      a4:	d294700a 	mov	x10, #0xa380                	// #41856
      a8:	f2a016ca 	movk	x10, #0xb6, lsl #16
      ac:	f2c00aaa 	movk	x10, #0x55, lsl #32
      b0:	b87f694a 	ldr	w10, [x10, xzr]
      b4:	5100114a 	sub	w10, w10, #0x4
      b8:	6b0a011f 	cmp	w8, w10
      bc:	54fffbe8 	b.hi	38 <trap_handler+0x38>  // b.pmore
      c0:	b8a86929 	ldrsw	x9, [x9, x8]
      c4:	b400003f 	cbz	xzr, c8 <as-br-value+0x6c>
      c8:	2a0903e0 	mov	w0, w9
      cc:	a8c153f3 	ldp	x19, x20, [sp], #16
      d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
      d4:	d65f03c0 	ret

00000000000000d8 <as-br_if-cond>:
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
     108:	52800008 	mov	w8, #0x0                   	// #0
     10c:	d2946c09 	mov	x9, #0xa360                	// #41824
     110:	f2a016c9 	movk	x9, #0xb6, lsl #16
     114:	f2c00aa9 	movk	x9, #0x55, lsl #32
     118:	f87f6929 	ldr	x9, [x9, xzr]
     11c:	b4fff8e9 	cbz	x9, 38 <trap_handler+0x38>
     120:	d294700a 	mov	x10, #0xa380                	// #41856
     124:	f2a016ca 	movk	x10, #0xb6, lsl #16
     128:	f2c00aaa 	movk	x10, #0x55, lsl #32
     12c:	b87f694a 	ldr	w10, [x10, xzr]
     130:	5100114a 	sub	w10, w10, #0x4
     134:	6b0a011f 	cmp	w8, w10
     138:	54fff808 	b.hi	38 <trap_handler+0x38>  // b.pmore
     13c:	b8a86929 	ldrsw	x9, [x9, x8]
     140:	35000029 	cbnz	w9, 144 <as-br_if-cond+0x6c>
     144:	a8c153f3 	ldp	x19, x20, [sp], #16
     148:	a8c17bfd 	ldp	x29, x30, [sp], #16
     14c:	d65f03c0 	ret

0000000000000150 <as-br_if-value>:
     150:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     154:	910003fd 	mov	x29, sp
     158:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     15c:	d2946413 	mov	x19, #0xa320                	// #41760
     160:	f2a016d3 	movk	x19, #0xb6, lsl #16
     164:	f2c00ab3 	movk	x19, #0x55, lsl #32
     168:	f87f6a73 	ldr	x19, [x19, xzr]
     16c:	cb3363f3 	sub	x19, sp, x19
     170:	d2800014 	mov	x20, #0x0                   	// #0
     174:	f2a00814 	movk	x20, #0x40, lsl #16
     178:	eb14027f 	cmp	x19, x20
     17c:	54fff62b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     180:	52800008 	mov	w8, #0x0                   	// #0
     184:	d2946c09 	mov	x9, #0xa360                	// #41824
     188:	f2a016c9 	movk	x9, #0xb6, lsl #16
     18c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     190:	f87f6929 	ldr	x9, [x9, xzr]
     194:	b4fff529 	cbz	x9, 38 <trap_handler+0x38>
     198:	d294700a 	mov	x10, #0xa380                	// #41856
     19c:	f2a016ca 	movk	x10, #0xb6, lsl #16
     1a0:	f2c00aaa 	movk	x10, #0x55, lsl #32
     1a4:	b87f694a 	ldr	w10, [x10, xzr]
     1a8:	5100114a 	sub	w10, w10, #0x4
     1ac:	6b0a011f 	cmp	w8, w10
     1b0:	54fff448 	b.hi	38 <trap_handler+0x38>  // b.pmore
     1b4:	b8a86929 	ldrsw	x9, [x9, x8]
     1b8:	52800028 	mov	w8, #0x1                   	// #1
     1bc:	35000068 	cbnz	w8, 1c8 <as-br_if-value+0x78>
     1c0:	528000e8 	mov	w8, #0x7                   	// #7
     1c4:	2a0803e9 	mov	w9, w8
     1c8:	2a0903e0 	mov	w0, w9
     1cc:	a8c153f3 	ldp	x19, x20, [sp], #16
     1d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     1d4:	d65f03c0 	ret

00000000000001d8 <as-br_if-value-cond>:
     1d8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     1dc:	910003fd 	mov	x29, sp
     1e0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     1e4:	d2946413 	mov	x19, #0xa320                	// #41760
     1e8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     1ec:	f2c00ab3 	movk	x19, #0x55, lsl #32
     1f0:	f87f6a73 	ldr	x19, [x19, xzr]
     1f4:	cb3363f3 	sub	x19, sp, x19
     1f8:	d2800014 	mov	x20, #0x0                   	// #0
     1fc:	f2a00814 	movk	x20, #0x40, lsl #16
     200:	eb14027f 	cmp	x19, x20
     204:	54fff1eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     208:	528000c8 	mov	w8, #0x6                   	// #6
     20c:	52800009 	mov	w9, #0x0                   	// #0
     210:	d2946c0a 	mov	x10, #0xa360                	// #41824
     214:	f2a016ca 	movk	x10, #0xb6, lsl #16
     218:	f2c00aaa 	movk	x10, #0x55, lsl #32
     21c:	f87f694a 	ldr	x10, [x10, xzr]
     220:	b4fff0ca 	cbz	x10, 38 <trap_handler+0x38>
     224:	d294700b 	mov	x11, #0xa380                	// #41856
     228:	f2a016cb 	movk	x11, #0xb6, lsl #16
     22c:	f2c00aab 	movk	x11, #0x55, lsl #32
     230:	b87f696b 	ldr	w11, [x11, xzr]
     234:	5100116b 	sub	w11, w11, #0x4
     238:	6b0b013f 	cmp	w9, w11
     23c:	54ffefe8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     240:	b8a9694a 	ldrsw	x10, [x10, x9]
     244:	3500004a 	cbnz	w10, 24c <as-br_if-value-cond+0x74>
     248:	528000e8 	mov	w8, #0x7                   	// #7
     24c:	2a0803e0 	mov	w0, w8
     250:	a8c153f3 	ldp	x19, x20, [sp], #16
     254:	a8c17bfd 	ldp	x29, x30, [sp], #16
     258:	d65f03c0 	ret

000000000000025c <as-return-value>:
     25c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     260:	910003fd 	mov	x29, sp
     264:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     268:	d2946413 	mov	x19, #0xa320                	// #41760
     26c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     270:	f2c00ab3 	movk	x19, #0x55, lsl #32
     274:	f87f6a73 	ldr	x19, [x19, xzr]
     278:	cb3363f3 	sub	x19, sp, x19
     27c:	d2800014 	mov	x20, #0x0                   	// #0
     280:	f2a00814 	movk	x20, #0x40, lsl #16
     284:	eb14027f 	cmp	x19, x20
     288:	54ffedcb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     28c:	52800008 	mov	w8, #0x0                   	// #0
     290:	d2946c09 	mov	x9, #0xa360                	// #41824
     294:	f2a016c9 	movk	x9, #0xb6, lsl #16
     298:	f2c00aa9 	movk	x9, #0x55, lsl #32
     29c:	f87f6929 	ldr	x9, [x9, xzr]
     2a0:	b4ffecc9 	cbz	x9, 38 <trap_handler+0x38>
     2a4:	d294700a 	mov	x10, #0xa380                	// #41856
     2a8:	f2a016ca 	movk	x10, #0xb6, lsl #16
     2ac:	f2c00aaa 	movk	x10, #0x55, lsl #32
     2b0:	b87f694a 	ldr	w10, [x10, xzr]
     2b4:	5100114a 	sub	w10, w10, #0x4
     2b8:	6b0a011f 	cmp	w8, w10
     2bc:	54ffebe8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     2c0:	b8a86929 	ldrsw	x9, [x9, x8]
     2c4:	b400003f 	cbz	xzr, 2c8 <as-return-value+0x6c>
     2c8:	2a0903e0 	mov	w0, w9
     2cc:	a8c153f3 	ldp	x19, x20, [sp], #16
     2d0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     2d4:	d65f03c0 	ret

00000000000002d8 <as-if-cond>:
     2d8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     2dc:	910003fd 	mov	x29, sp
     2e0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     2e4:	d2946413 	mov	x19, #0xa320                	// #41760
     2e8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     2ec:	f2c00ab3 	movk	x19, #0x55, lsl #32
     2f0:	f87f6a73 	ldr	x19, [x19, xzr]
     2f4:	cb3363f3 	sub	x19, sp, x19
     2f8:	d2800014 	mov	x20, #0x0                   	// #0
     2fc:	f2a00814 	movk	x20, #0x40, lsl #16
     300:	eb14027f 	cmp	x19, x20
     304:	54ffe9eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     308:	52800008 	mov	w8, #0x0                   	// #0
     30c:	d2946c09 	mov	x9, #0xa360                	// #41824
     310:	f2a016c9 	movk	x9, #0xb6, lsl #16
     314:	f2c00aa9 	movk	x9, #0x55, lsl #32
     318:	f87f6929 	ldr	x9, [x9, xzr]
     31c:	b4ffe8e9 	cbz	x9, 38 <trap_handler+0x38>
     320:	d294700a 	mov	x10, #0xa380                	// #41856
     324:	f2a016ca 	movk	x10, #0xb6, lsl #16
     328:	f2c00aaa 	movk	x10, #0x55, lsl #32
     32c:	b87f694a 	ldr	w10, [x10, xzr]
     330:	5100114a 	sub	w10, w10, #0x4
     334:	6b0a011f 	cmp	w8, w10
     338:	54ffe808 	b.hi	38 <trap_handler+0x38>  // b.pmore
     33c:	b8a86929 	ldrsw	x9, [x9, x8]
     340:	34000069 	cbz	w9, 34c <as-if-cond+0x74>
     344:	52800008 	mov	w8, #0x0                   	// #0
     348:	14000002 	b	350 <as-if-cond+0x78>
     34c:	52800028 	mov	w8, #0x1                   	// #1
     350:	2a0803e0 	mov	w0, w8
     354:	a8c153f3 	ldp	x19, x20, [sp], #16
     358:	a8c17bfd 	ldp	x29, x30, [sp], #16
     35c:	d65f03c0 	ret

0000000000000360 <as-if-then>:
     360:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     364:	910003fd 	mov	x29, sp
     368:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     36c:	d2946413 	mov	x19, #0xa320                	// #41760
     370:	f2a016d3 	movk	x19, #0xb6, lsl #16
     374:	f2c00ab3 	movk	x19, #0x55, lsl #32
     378:	f87f6a73 	ldr	x19, [x19, xzr]
     37c:	cb3363f3 	sub	x19, sp, x19
     380:	d2800014 	mov	x20, #0x0                   	// #0
     384:	f2a00814 	movk	x20, #0x40, lsl #16
     388:	eb14027f 	cmp	x19, x20
     38c:	54ffe5ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     390:	52800028 	mov	w8, #0x1                   	// #1
     394:	34000208 	cbz	w8, 3d4 <as-if-then+0x74>
     398:	52800008 	mov	w8, #0x0                   	// #0
     39c:	d2946c09 	mov	x9, #0xa360                	// #41824
     3a0:	f2a016c9 	movk	x9, #0xb6, lsl #16
     3a4:	f2c00aa9 	movk	x9, #0x55, lsl #32
     3a8:	f87f6929 	ldr	x9, [x9, xzr]
     3ac:	b4ffe469 	cbz	x9, 38 <trap_handler+0x38>
     3b0:	d294700a 	mov	x10, #0xa380                	// #41856
     3b4:	f2a016ca 	movk	x10, #0xb6, lsl #16
     3b8:	f2c00aaa 	movk	x10, #0x55, lsl #32
     3bc:	b87f694a 	ldr	w10, [x10, xzr]
     3c0:	5100114a 	sub	w10, w10, #0x4
     3c4:	6b0a011f 	cmp	w8, w10
     3c8:	54ffe388 	b.hi	38 <trap_handler+0x38>  // b.pmore
     3cc:	b8a86929 	ldrsw	x9, [x9, x8]
     3d0:	14000002 	b	3d8 <as-if-then+0x78>
     3d4:	52800008 	mov	w8, #0x0                   	// #0
     3d8:	2a0803e0 	mov	w0, w8
     3dc:	a8c153f3 	ldp	x19, x20, [sp], #16
     3e0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     3e4:	d65f03c0 	ret

00000000000003e8 <as-if-else>:
     3e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     3ec:	910003fd 	mov	x29, sp
     3f0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     3f4:	d2946413 	mov	x19, #0xa320                	// #41760
     3f8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     3fc:	f2c00ab3 	movk	x19, #0x55, lsl #32
     400:	f87f6a73 	ldr	x19, [x19, xzr]
     404:	cb3363f3 	sub	x19, sp, x19
     408:	d2800014 	mov	x20, #0x0                   	// #0
     40c:	f2a00814 	movk	x20, #0x40, lsl #16
     410:	eb14027f 	cmp	x19, x20
     414:	54ffe16b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     418:	52800008 	mov	w8, #0x0                   	// #0
     41c:	34000068 	cbz	w8, 428 <as-if-else+0x40>
     420:	52800008 	mov	w8, #0x0                   	// #0
     424:	1400000f 	b	460 <as-if-else+0x78>
     428:	52800008 	mov	w8, #0x0                   	// #0
     42c:	d2946c09 	mov	x9, #0xa360                	// #41824
     430:	f2a016c9 	movk	x9, #0xb6, lsl #16
     434:	f2c00aa9 	movk	x9, #0x55, lsl #32
     438:	f87f6929 	ldr	x9, [x9, xzr]
     43c:	b4ffdfe9 	cbz	x9, 38 <trap_handler+0x38>
     440:	d294700a 	mov	x10, #0xa380                	// #41856
     444:	f2a016ca 	movk	x10, #0xb6, lsl #16
     448:	f2c00aaa 	movk	x10, #0x55, lsl #32
     44c:	b87f694a 	ldr	w10, [x10, xzr]
     450:	5100114a 	sub	w10, w10, #0x4
     454:	6b0a011f 	cmp	w8, w10
     458:	54ffdf08 	b.hi	38 <trap_handler+0x38>  // b.pmore
     45c:	b8a86929 	ldrsw	x9, [x9, x8]
     460:	2a0903e0 	mov	w0, w9
     464:	a8c153f3 	ldp	x19, x20, [sp], #16
     468:	a8c17bfd 	ldp	x29, x30, [sp], #16
     46c:	d65f03c0 	ret

0000000000000470 <as-call-first>:
     470:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     474:	910003fd 	mov	x29, sp
     478:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     47c:	d2946413 	mov	x19, #0xa320                	// #41760
     480:	f2a016d3 	movk	x19, #0xb6, lsl #16
     484:	f2c00ab3 	movk	x19, #0x55, lsl #32
     488:	f87f6a73 	ldr	x19, [x19, xzr]
     48c:	cb3363f3 	sub	x19, sp, x19
     490:	d2800014 	mov	x20, #0x0                   	// #0
     494:	f2a00814 	movk	x20, #0x40, lsl #16
     498:	eb14027f 	cmp	x19, x20
     49c:	54ffdd2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     4a0:	52800008 	mov	w8, #0x0                   	// #0
     4a4:	d2946c09 	mov	x9, #0xa360                	// #41824
     4a8:	f2a016c9 	movk	x9, #0xb6, lsl #16
     4ac:	f2c00aa9 	movk	x9, #0x55, lsl #32
     4b0:	f87f6929 	ldr	x9, [x9, xzr]
     4b4:	b4ffdc29 	cbz	x9, 38 <trap_handler+0x38>
     4b8:	d294700a 	mov	x10, #0xa380                	// #41856
     4bc:	f2a016ca 	movk	x10, #0xb6, lsl #16
     4c0:	f2c00aaa 	movk	x10, #0x55, lsl #32
     4c4:	b87f694a 	ldr	w10, [x10, xzr]
     4c8:	5100114a 	sub	w10, w10, #0x4
     4cc:	6b0a011f 	cmp	w8, w10
     4d0:	54ffdb48 	b.hi	38 <trap_handler+0x38>  // b.pmore
     4d4:	b8a86929 	ldrsw	x9, [x9, x8]
     4d8:	52800048 	mov	w8, #0x2                   	// #2
     4dc:	5280006a 	mov	w10, #0x3                   	// #3
     4e0:	2a0a03e2 	mov	w2, w10
     4e4:	2a0803e1 	mov	w1, w8
     4e8:	2a0903e0 	mov	w0, w9
     4ec:	d10103ff 	sub	sp, sp, #0x40
     4f0:	a90327e8 	stp	x8, x9, [sp, #48]
     4f4:	a9022fea 	stp	x10, x11, [sp, #32]
     4f8:	a90137ec 	stp	x12, x13, [sp, #16]
     4fc:	a9003fee 	stp	x14, x15, [sp]
     500:	94000069 	bl	6a4 <func_11>
     504:	a94327e8 	ldp	x8, x9, [sp, #48]
     508:	a9422fea 	ldp	x10, x11, [sp, #32]
     50c:	a94137ec 	ldp	x12, x13, [sp, #16]
     510:	a9403fee 	ldp	x14, x15, [sp]
     514:	910103ff 	add	sp, sp, #0x40
     518:	aa0003e8 	mov	x8, x0
     51c:	2a0803e0 	mov	w0, w8
     520:	a8c153f3 	ldp	x19, x20, [sp], #16
     524:	a8c17bfd 	ldp	x29, x30, [sp], #16
     528:	d65f03c0 	ret

000000000000052c <as-call-mid>:
     52c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     530:	910003fd 	mov	x29, sp
     534:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     538:	d2946413 	mov	x19, #0xa320                	// #41760
     53c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     540:	f2c00ab3 	movk	x19, #0x55, lsl #32
     544:	f87f6a73 	ldr	x19, [x19, xzr]
     548:	cb3363f3 	sub	x19, sp, x19
     54c:	d2800014 	mov	x20, #0x0                   	// #0
     550:	f2a00814 	movk	x20, #0x40, lsl #16
     554:	eb14027f 	cmp	x19, x20
     558:	54ffd74b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     55c:	52800028 	mov	w8, #0x1                   	// #1
     560:	52800009 	mov	w9, #0x0                   	// #0
     564:	d2946c0a 	mov	x10, #0xa360                	// #41824
     568:	f2a016ca 	movk	x10, #0xb6, lsl #16
     56c:	f2c00aaa 	movk	x10, #0x55, lsl #32
     570:	f87f694a 	ldr	x10, [x10, xzr]
     574:	b4ffd62a 	cbz	x10, 38 <trap_handler+0x38>
     578:	d294700b 	mov	x11, #0xa380                	// #41856
     57c:	f2a016cb 	movk	x11, #0xb6, lsl #16
     580:	f2c00aab 	movk	x11, #0x55, lsl #32
     584:	b87f696b 	ldr	w11, [x11, xzr]
     588:	5100116b 	sub	w11, w11, #0x4
     58c:	6b0b013f 	cmp	w9, w11
     590:	54ffd548 	b.hi	38 <trap_handler+0x38>  // b.pmore
     594:	b8a9694a 	ldrsw	x10, [x10, x9]
     598:	52800069 	mov	w9, #0x3                   	// #3
     59c:	2a0903e2 	mov	w2, w9
     5a0:	2a0a03e1 	mov	w1, w10
     5a4:	2a0803e0 	mov	w0, w8
     5a8:	d10103ff 	sub	sp, sp, #0x40
     5ac:	a90327e8 	stp	x8, x9, [sp, #48]
     5b0:	a9022fea 	stp	x10, x11, [sp, #32]
     5b4:	a90137ec 	stp	x12, x13, [sp, #16]
     5b8:	a9003fee 	stp	x14, x15, [sp]
     5bc:	9400003a 	bl	6a4 <func_11>
     5c0:	a94327e8 	ldp	x8, x9, [sp, #48]
     5c4:	a9422fea 	ldp	x10, x11, [sp, #32]
     5c8:	a94137ec 	ldp	x12, x13, [sp, #16]
     5cc:	a9403fee 	ldp	x14, x15, [sp]
     5d0:	910103ff 	add	sp, sp, #0x40
     5d4:	aa0003e8 	mov	x8, x0
     5d8:	2a0803e0 	mov	w0, w8
     5dc:	a8c153f3 	ldp	x19, x20, [sp], #16
     5e0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     5e4:	d65f03c0 	ret

00000000000005e8 <as-call-last>:
     5e8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     5ec:	910003fd 	mov	x29, sp
     5f0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     5f4:	d2946413 	mov	x19, #0xa320                	// #41760
     5f8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     5fc:	f2c00ab3 	movk	x19, #0x55, lsl #32
     600:	f87f6a73 	ldr	x19, [x19, xzr]
     604:	cb3363f3 	sub	x19, sp, x19
     608:	d2800014 	mov	x20, #0x0                   	// #0
     60c:	f2a00814 	movk	x20, #0x40, lsl #16
     610:	eb14027f 	cmp	x19, x20
     614:	54ffd16b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     618:	52800028 	mov	w8, #0x1                   	// #1
     61c:	52800049 	mov	w9, #0x2                   	// #2
     620:	5280000a 	mov	w10, #0x0                   	// #0
     624:	d2946c0b 	mov	x11, #0xa360                	// #41824
     628:	f2a016cb 	movk	x11, #0xb6, lsl #16
     62c:	f2c00aab 	movk	x11, #0x55, lsl #32
     630:	f87f696b 	ldr	x11, [x11, xzr]
     634:	b4ffd02b 	cbz	x11, 38 <trap_handler+0x38>
     638:	d294700c 	mov	x12, #0xa380                	// #41856
     63c:	f2a016cc 	movk	x12, #0xb6, lsl #16
     640:	f2c00aac 	movk	x12, #0x55, lsl #32
     644:	b87f698c 	ldr	w12, [x12, xzr]
     648:	5100118c 	sub	w12, w12, #0x4
     64c:	6b0c015f 	cmp	w10, w12
     650:	54ffcf48 	b.hi	38 <trap_handler+0x38>  // b.pmore
     654:	b8aa696b 	ldrsw	x11, [x11, x10]
     658:	2a0b03e2 	mov	w2, w11
     65c:	2a0903e1 	mov	w1, w9
     660:	2a0803e0 	mov	w0, w8
     664:	d10103ff 	sub	sp, sp, #0x40
     668:	a90327e8 	stp	x8, x9, [sp, #48]
     66c:	a9022fea 	stp	x10, x11, [sp, #32]
     670:	a90137ec 	stp	x12, x13, [sp, #16]
     674:	a9003fee 	stp	x14, x15, [sp]
     678:	9400000b 	bl	6a4 <func_11>
     67c:	a94327e8 	ldp	x8, x9, [sp, #48]
     680:	a9422fea 	ldp	x10, x11, [sp, #32]
     684:	a94137ec 	ldp	x12, x13, [sp, #16]
     688:	a9403fee 	ldp	x14, x15, [sp]
     68c:	910103ff 	add	sp, sp, #0x40
     690:	aa0003e8 	mov	x8, x0
     694:	2a0803e0 	mov	w0, w8
     698:	a8c153f3 	ldp	x19, x20, [sp], #16
     69c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     6a0:	d65f03c0 	ret

00000000000006a4 <func_11>:
     6a4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     6a8:	910003fd 	mov	x29, sp
     6ac:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     6b0:	d2946413 	mov	x19, #0xa320                	// #41760
     6b4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     6b8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     6bc:	f87f6a73 	ldr	x19, [x19, xzr]
     6c0:	cb3363f3 	sub	x19, sp, x19
     6c4:	d2800014 	mov	x20, #0x0                   	// #0
     6c8:	f2a00814 	movk	x20, #0x40, lsl #16
     6cc:	eb14027f 	cmp	x19, x20
     6d0:	54ffcb8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     6d4:	d10043ff 	sub	sp, sp, #0x10
     6d8:	b90013e0 	str	w0, [sp, #16]
     6dc:	b9000fe1 	str	w1, [sp, #12]
     6e0:	b9000be2 	str	w2, [sp, #8]
     6e4:	529fffe8 	mov	w8, #0xffff                	// #65535
     6e8:	72bfffe8 	movk	w8, #0xffff, lsl #16
     6ec:	2a0803e0 	mov	w0, w8
     6f0:	910043ff 	add	sp, sp, #0x10
     6f4:	a8c153f3 	ldp	x19, x20, [sp], #16
     6f8:	a8c17bfd 	ldp	x29, x30, [sp], #16
     6fc:	d65f03c0 	ret

0000000000000700 <as-local.set-value>:
     700:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     704:	910003fd 	mov	x29, sp
     708:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     70c:	d2946413 	mov	x19, #0xa320                	// #41760
     710:	f2a016d3 	movk	x19, #0xb6, lsl #16
     714:	f2c00ab3 	movk	x19, #0x55, lsl #32
     718:	f87f6a73 	ldr	x19, [x19, xzr]
     71c:	cb3363f3 	sub	x19, sp, x19
     720:	d2800014 	mov	x20, #0x0                   	// #0
     724:	f2a00814 	movk	x20, #0x40, lsl #16
     728:	eb14027f 	cmp	x19, x20
     72c:	54ffc8ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     730:	d10043ff 	sub	sp, sp, #0x10
     734:	b90013ff 	str	wzr, [sp, #16]
     738:	52800008 	mov	w8, #0x0                   	// #0
     73c:	d2946c09 	mov	x9, #0xa360                	// #41824
     740:	f2a016c9 	movk	x9, #0xb6, lsl #16
     744:	f2c00aa9 	movk	x9, #0x55, lsl #32
     748:	f87f6929 	ldr	x9, [x9, xzr]
     74c:	b4ffc769 	cbz	x9, 38 <trap_handler+0x38>
     750:	d294700a 	mov	x10, #0xa380                	// #41856
     754:	f2a016ca 	movk	x10, #0xb6, lsl #16
     758:	f2c00aaa 	movk	x10, #0x55, lsl #32
     75c:	b87f694a 	ldr	w10, [x10, xzr]
     760:	5100114a 	sub	w10, w10, #0x4
     764:	6b0a011f 	cmp	w8, w10
     768:	54ffc688 	b.hi	38 <trap_handler+0x38>  // b.pmore
     76c:	b8a86929 	ldrsw	x9, [x9, x8]
     770:	b90013e9 	str	w9, [sp, #16]
     774:	910043ff 	add	sp, sp, #0x10
     778:	a8c153f3 	ldp	x19, x20, [sp], #16
     77c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     780:	d65f03c0 	ret

0000000000000784 <as-local.tee-value>:
     784:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     788:	910003fd 	mov	x29, sp
     78c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     790:	d2946413 	mov	x19, #0xa320                	// #41760
     794:	f2a016d3 	movk	x19, #0xb6, lsl #16
     798:	f2c00ab3 	movk	x19, #0x55, lsl #32
     79c:	f87f6a73 	ldr	x19, [x19, xzr]
     7a0:	cb3363f3 	sub	x19, sp, x19
     7a4:	d2800014 	mov	x20, #0x0                   	// #0
     7a8:	f2a00814 	movk	x20, #0x40, lsl #16
     7ac:	eb14027f 	cmp	x19, x20
     7b0:	54ffc48b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     7b4:	d10043ff 	sub	sp, sp, #0x10
     7b8:	b90013ff 	str	wzr, [sp, #16]
     7bc:	52800008 	mov	w8, #0x0                   	// #0
     7c0:	d2946c09 	mov	x9, #0xa360                	// #41824
     7c4:	f2a016c9 	movk	x9, #0xb6, lsl #16
     7c8:	f2c00aa9 	movk	x9, #0x55, lsl #32
     7cc:	f87f6929 	ldr	x9, [x9, xzr]
     7d0:	b4ffc349 	cbz	x9, 38 <trap_handler+0x38>
     7d4:	d294700a 	mov	x10, #0xa380                	// #41856
     7d8:	f2a016ca 	movk	x10, #0xb6, lsl #16
     7dc:	f2c00aaa 	movk	x10, #0x55, lsl #32
     7e0:	b87f694a 	ldr	w10, [x10, xzr]
     7e4:	5100114a 	sub	w10, w10, #0x4
     7e8:	6b0a011f 	cmp	w8, w10
     7ec:	54ffc268 	b.hi	38 <trap_handler+0x38>  // b.pmore
     7f0:	b8a86929 	ldrsw	x9, [x9, x8]
     7f4:	b90013e9 	str	w9, [sp, #16]
     7f8:	2a0903e0 	mov	w0, w9
     7fc:	910043ff 	add	sp, sp, #0x10
     800:	a8c153f3 	ldp	x19, x20, [sp], #16
     804:	a8c17bfd 	ldp	x29, x30, [sp], #16
     808:	d65f03c0 	ret

000000000000080c <as-global.set-value>:
     80c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     810:	910003fd 	mov	x29, sp
     814:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     818:	d2946413 	mov	x19, #0xa320                	// #41760
     81c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     820:	f2c00ab3 	movk	x19, #0x55, lsl #32
     824:	f87f6a73 	ldr	x19, [x19, xzr]
     828:	cb3363f3 	sub	x19, sp, x19
     82c:	d2800014 	mov	x20, #0x0                   	// #0
     830:	f2a00814 	movk	x20, #0x40, lsl #16
     834:	eb14027f 	cmp	x19, x20
     838:	54ffc04b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     83c:	d10043ff 	sub	sp, sp, #0x10
     840:	b90013ff 	str	wzr, [sp, #16]
     844:	52800008 	mov	w8, #0x0                   	// #0
     848:	d2946c09 	mov	x9, #0xa360                	// #41824
     84c:	f2a016c9 	movk	x9, #0xb6, lsl #16
     850:	f2c00aa9 	movk	x9, #0x55, lsl #32
     854:	f87f6929 	ldr	x9, [x9, xzr]
     858:	b4ffbf09 	cbz	x9, 38 <trap_handler+0x38>
     85c:	d294700a 	mov	x10, #0xa380                	// #41856
     860:	f2a016ca 	movk	x10, #0xb6, lsl #16
     864:	f2c00aaa 	movk	x10, #0x55, lsl #32
     868:	b87f694a 	ldr	w10, [x10, xzr]
     86c:	5100114a 	sub	w10, w10, #0x4
     870:	6b0a011f 	cmp	w8, w10
     874:	54ffbe28 	b.hi	38 <trap_handler+0x38>  // b.pmore
     878:	b8a86929 	ldrsw	x9, [x9, x8]
     87c:	d2946208 	mov	x8, #0xa310                	// #41744
     880:	f2a016c8 	movk	x8, #0xb6, lsl #16
     884:	f2c00aa8 	movk	x8, #0x55, lsl #32
     888:	f87f6908 	ldr	x8, [x8, xzr]
     88c:	91000108 	add	x8, x8, #0x0
     890:	f83f6909 	str	x9, [x8, xzr]
     894:	910043ff 	add	sp, sp, #0x10
     898:	a8c153f3 	ldp	x19, x20, [sp], #16
     89c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     8a0:	d65f03c0 	ret

00000000000008a4 <as-load-address>:
     8a4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     8a8:	910003fd 	mov	x29, sp
     8ac:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     8b0:	d2946413 	mov	x19, #0xa320                	// #41760
     8b4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     8b8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     8bc:	f87f6a73 	ldr	x19, [x19, xzr]
     8c0:	cb3363f3 	sub	x19, sp, x19
     8c4:	d2800014 	mov	x20, #0x0                   	// #0
     8c8:	f2a00814 	movk	x20, #0x40, lsl #16
     8cc:	eb14027f 	cmp	x19, x20
     8d0:	54ffbb8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     8d4:	52800008 	mov	w8, #0x0                   	// #0
     8d8:	d2946c09 	mov	x9, #0xa360                	// #41824
     8dc:	f2a016c9 	movk	x9, #0xb6, lsl #16
     8e0:	f2c00aa9 	movk	x9, #0x55, lsl #32
     8e4:	f87f6929 	ldr	x9, [x9, xzr]
     8e8:	b4ffba89 	cbz	x9, 38 <trap_handler+0x38>
     8ec:	d294700a 	mov	x10, #0xa380                	// #41856
     8f0:	f2a016ca 	movk	x10, #0xb6, lsl #16
     8f4:	f2c00aaa 	movk	x10, #0x55, lsl #32
     8f8:	b87f694a 	ldr	w10, [x10, xzr]
     8fc:	5100114a 	sub	w10, w10, #0x4
     900:	6b0a011f 	cmp	w8, w10
     904:	54ffb9a8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     908:	b8a86929 	ldrsw	x9, [x9, x8]
     90c:	d2946c08 	mov	x8, #0xa360                	// #41824
     910:	f2a016c8 	movk	x8, #0xb6, lsl #16
     914:	f2c00aa8 	movk	x8, #0x55, lsl #32
     918:	f87f6908 	ldr	x8, [x8, xzr]
     91c:	b4ffb8e8 	cbz	x8, 38 <trap_handler+0x38>
     920:	d294700a 	mov	x10, #0xa380                	// #41856
     924:	f2a016ca 	movk	x10, #0xb6, lsl #16
     928:	f2c00aaa 	movk	x10, #0x55, lsl #32
     92c:	b87f694a 	ldr	w10, [x10, xzr]
     930:	5100114a 	sub	w10, w10, #0x4
     934:	6b0a013f 	cmp	w9, w10
     938:	54ffb808 	b.hi	38 <trap_handler+0x38>  // b.pmore
     93c:	b8a96908 	ldrsw	x8, [x8, x9]
     940:	2a0803e0 	mov	w0, w8
     944:	a8c153f3 	ldp	x19, x20, [sp], #16
     948:	a8c17bfd 	ldp	x29, x30, [sp], #16
     94c:	d65f03c0 	ret

0000000000000950 <as-loadN-address>:
     950:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     954:	910003fd 	mov	x29, sp
     958:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     95c:	d2946413 	mov	x19, #0xa320                	// #41760
     960:	f2a016d3 	movk	x19, #0xb6, lsl #16
     964:	f2c00ab3 	movk	x19, #0x55, lsl #32
     968:	f87f6a73 	ldr	x19, [x19, xzr]
     96c:	cb3363f3 	sub	x19, sp, x19
     970:	d2800014 	mov	x20, #0x0                   	// #0
     974:	f2a00814 	movk	x20, #0x40, lsl #16
     978:	eb14027f 	cmp	x19, x20
     97c:	54ffb62b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     980:	52800008 	mov	w8, #0x0                   	// #0
     984:	d2946c09 	mov	x9, #0xa360                	// #41824
     988:	f2a016c9 	movk	x9, #0xb6, lsl #16
     98c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     990:	f87f6929 	ldr	x9, [x9, xzr]
     994:	b4ffb529 	cbz	x9, 38 <trap_handler+0x38>
     998:	d294700a 	mov	x10, #0xa380                	// #41856
     99c:	f2a016ca 	movk	x10, #0xb6, lsl #16
     9a0:	f2c00aaa 	movk	x10, #0x55, lsl #32
     9a4:	b87f694a 	ldr	w10, [x10, xzr]
     9a8:	5100114a 	sub	w10, w10, #0x4
     9ac:	6b0a011f 	cmp	w8, w10
     9b0:	54ffb448 	b.hi	38 <trap_handler+0x38>  // b.pmore
     9b4:	b8a86929 	ldrsw	x9, [x9, x8]
     9b8:	d2946c08 	mov	x8, #0xa360                	// #41824
     9bc:	f2a016c8 	movk	x8, #0xb6, lsl #16
     9c0:	f2c00aa8 	movk	x8, #0x55, lsl #32
     9c4:	f87f6908 	ldr	x8, [x8, xzr]
     9c8:	34ffb388 	cbz	w8, 38 <trap_handler+0x38>
     9cc:	d294700a 	mov	x10, #0xa380                	// #41856
     9d0:	f2a016ca 	movk	x10, #0xb6, lsl #16
     9d4:	f2c00aaa 	movk	x10, #0x55, lsl #32
     9d8:	b87f694a 	ldr	w10, [x10, xzr]
     9dc:	5100054a 	sub	w10, w10, #0x1
     9e0:	6b0a013f 	cmp	w9, w10
     9e4:	54ffb2a8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     9e8:	38e97908 	ldrsb	w8, [x8, x9, lsl #0]
     9ec:	2a0803e0 	mov	w0, w8
     9f0:	a8c153f3 	ldp	x19, x20, [sp], #16
     9f4:	a8c17bfd 	ldp	x29, x30, [sp], #16
     9f8:	d65f03c0 	ret

00000000000009fc <as-store-address>:
     9fc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     a00:	910003fd 	mov	x29, sp
     a04:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     a08:	d2946413 	mov	x19, #0xa320                	// #41760
     a0c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     a10:	f2c00ab3 	movk	x19, #0x55, lsl #32
     a14:	f87f6a73 	ldr	x19, [x19, xzr]
     a18:	cb3363f3 	sub	x19, sp, x19
     a1c:	d2800014 	mov	x20, #0x0                   	// #0
     a20:	f2a00814 	movk	x20, #0x40, lsl #16
     a24:	eb14027f 	cmp	x19, x20
     a28:	54ffb0cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     a2c:	52800008 	mov	w8, #0x0                   	// #0
     a30:	d2946c09 	mov	x9, #0xa360                	// #41824
     a34:	f2a016c9 	movk	x9, #0xb6, lsl #16
     a38:	f2c00aa9 	movk	x9, #0x55, lsl #32
     a3c:	f87f6929 	ldr	x9, [x9, xzr]
     a40:	b4ffafc9 	cbz	x9, 38 <trap_handler+0x38>
     a44:	d294700a 	mov	x10, #0xa380                	// #41856
     a48:	f2a016ca 	movk	x10, #0xb6, lsl #16
     a4c:	f2c00aaa 	movk	x10, #0x55, lsl #32
     a50:	b87f694a 	ldr	w10, [x10, xzr]
     a54:	5100114a 	sub	w10, w10, #0x4
     a58:	6b0a011f 	cmp	w8, w10
     a5c:	54ffaee8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     a60:	b8a86929 	ldrsw	x9, [x9, x8]
     a64:	528000e8 	mov	w8, #0x7                   	// #7
     a68:	d2946c0a 	mov	x10, #0xa360                	// #41824
     a6c:	f2a016ca 	movk	x10, #0xb6, lsl #16
     a70:	f2c00aaa 	movk	x10, #0x55, lsl #32
     a74:	f87f694a 	ldr	x10, [x10, xzr]
     a78:	34ffae0a 	cbz	w10, 38 <trap_handler+0x38>
     a7c:	d294700b 	mov	x11, #0xa380                	// #41856
     a80:	f2a016cb 	movk	x11, #0xb6, lsl #16
     a84:	f2c00aab 	movk	x11, #0x55, lsl #32
     a88:	b87f696b 	ldr	w11, [x11, xzr]
     a8c:	5100116b 	sub	w11, w11, #0x4
     a90:	6b0b013f 	cmp	w9, w11
     a94:	54ffad28 	b.hi	38 <trap_handler+0x38>  // b.pmore
     a98:	b8296948 	str	w8, [x10, x9]
     a9c:	a8c153f3 	ldp	x19, x20, [sp], #16
     aa0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     aa4:	d65f03c0 	ret

0000000000000aa8 <as-store-value>:
     aa8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     aac:	910003fd 	mov	x29, sp
     ab0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     ab4:	d2946413 	mov	x19, #0xa320                	// #41760
     ab8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     abc:	f2c00ab3 	movk	x19, #0x55, lsl #32
     ac0:	f87f6a73 	ldr	x19, [x19, xzr]
     ac4:	cb3363f3 	sub	x19, sp, x19
     ac8:	d2800014 	mov	x20, #0x0                   	// #0
     acc:	f2a00814 	movk	x20, #0x40, lsl #16
     ad0:	eb14027f 	cmp	x19, x20
     ad4:	54ffab6b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     ad8:	52800048 	mov	w8, #0x2                   	// #2
     adc:	52800009 	mov	w9, #0x0                   	// #0
     ae0:	d2946c0a 	mov	x10, #0xa360                	// #41824
     ae4:	f2a016ca 	movk	x10, #0xb6, lsl #16
     ae8:	f2c00aaa 	movk	x10, #0x55, lsl #32
     aec:	f87f694a 	ldr	x10, [x10, xzr]
     af0:	b4ffaa4a 	cbz	x10, 38 <trap_handler+0x38>
     af4:	d294700b 	mov	x11, #0xa380                	// #41856
     af8:	f2a016cb 	movk	x11, #0xb6, lsl #16
     afc:	f2c00aab 	movk	x11, #0x55, lsl #32
     b00:	b87f696b 	ldr	w11, [x11, xzr]
     b04:	5100116b 	sub	w11, w11, #0x4
     b08:	6b0b013f 	cmp	w9, w11
     b0c:	54ffa968 	b.hi	38 <trap_handler+0x38>  // b.pmore
     b10:	b8a9694a 	ldrsw	x10, [x10, x9]
     b14:	d2946c09 	mov	x9, #0xa360                	// #41824
     b18:	f2a016c9 	movk	x9, #0xb6, lsl #16
     b1c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     b20:	f87f6929 	ldr	x9, [x9, xzr]
     b24:	34ffa8a9 	cbz	w9, 38 <trap_handler+0x38>
     b28:	d294700b 	mov	x11, #0xa380                	// #41856
     b2c:	f2a016cb 	movk	x11, #0xb6, lsl #16
     b30:	f2c00aab 	movk	x11, #0x55, lsl #32
     b34:	b87f696b 	ldr	w11, [x11, xzr]
     b38:	5100116b 	sub	w11, w11, #0x4
     b3c:	6b0b011f 	cmp	w8, w11
     b40:	54ffa7c8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     b44:	b828692a 	str	w10, [x9, x8]
     b48:	a8c153f3 	ldp	x19, x20, [sp], #16
     b4c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     b50:	d65f03c0 	ret

0000000000000b54 <as-storeN-address>:
     b54:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     b58:	910003fd 	mov	x29, sp
     b5c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     b60:	d2946413 	mov	x19, #0xa320                	// #41760
     b64:	f2a016d3 	movk	x19, #0xb6, lsl #16
     b68:	f2c00ab3 	movk	x19, #0x55, lsl #32
     b6c:	f87f6a73 	ldr	x19, [x19, xzr]
     b70:	cb3363f3 	sub	x19, sp, x19
     b74:	d2800014 	mov	x20, #0x0                   	// #0
     b78:	f2a00814 	movk	x20, #0x40, lsl #16
     b7c:	eb14027f 	cmp	x19, x20
     b80:	54ffa60b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     b84:	52800008 	mov	w8, #0x0                   	// #0
     b88:	d2946c09 	mov	x9, #0xa360                	// #41824
     b8c:	f2a016c9 	movk	x9, #0xb6, lsl #16
     b90:	f2c00aa9 	movk	x9, #0x55, lsl #32
     b94:	f87f6929 	ldr	x9, [x9, xzr]
     b98:	34ffa509 	cbz	w9, 38 <trap_handler+0x38>
     b9c:	d294700a 	mov	x10, #0xa380                	// #41856
     ba0:	f2a016ca 	movk	x10, #0xb6, lsl #16
     ba4:	f2c00aaa 	movk	x10, #0x55, lsl #32
     ba8:	b87f694a 	ldr	w10, [x10, xzr]
     bac:	5100054a 	sub	w10, w10, #0x1
     bb0:	6b0a011f 	cmp	w8, w10
     bb4:	54ffa428 	b.hi	38 <trap_handler+0x38>  // b.pmore
     bb8:	38e87929 	ldrsb	w9, [x9, x8, lsl #0]
     bbc:	528000e8 	mov	w8, #0x7                   	// #7
     bc0:	d2946c0a 	mov	x10, #0xa360                	// #41824
     bc4:	f2a016ca 	movk	x10, #0xb6, lsl #16
     bc8:	f2c00aaa 	movk	x10, #0x55, lsl #32
     bcc:	f87f694a 	ldr	x10, [x10, xzr]
     bd0:	34ffa34a 	cbz	w10, 38 <trap_handler+0x38>
     bd4:	d294700b 	mov	x11, #0xa380                	// #41856
     bd8:	f2a016cb 	movk	x11, #0xb6, lsl #16
     bdc:	f2c00aab 	movk	x11, #0x55, lsl #32
     be0:	b87f696b 	ldr	w11, [x11, xzr]
     be4:	5100056b 	sub	w11, w11, #0x1
     be8:	6b0b013f 	cmp	w9, w11
     bec:	54ffa268 	b.hi	38 <trap_handler+0x38>  // b.pmore
     bf0:	38297948 	strb	w8, [x10, x9, lsl #0]
     bf4:	a8c153f3 	ldp	x19, x20, [sp], #16
     bf8:	a8c17bfd 	ldp	x29, x30, [sp], #16
     bfc:	d65f03c0 	ret

0000000000000c00 <as-storeN-value>:
     c00:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     c04:	910003fd 	mov	x29, sp
     c08:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     c0c:	d2946413 	mov	x19, #0xa320                	// #41760
     c10:	f2a016d3 	movk	x19, #0xb6, lsl #16
     c14:	f2c00ab3 	movk	x19, #0x55, lsl #32
     c18:	f87f6a73 	ldr	x19, [x19, xzr]
     c1c:	cb3363f3 	sub	x19, sp, x19
     c20:	d2800014 	mov	x20, #0x0                   	// #0
     c24:	f2a00814 	movk	x20, #0x40, lsl #16
     c28:	eb14027f 	cmp	x19, x20
     c2c:	54ffa0ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     c30:	52800048 	mov	w8, #0x2                   	// #2
     c34:	52800009 	mov	w9, #0x0                   	// #0
     c38:	d2946c0a 	mov	x10, #0xa360                	// #41824
     c3c:	f2a016ca 	movk	x10, #0xb6, lsl #16
     c40:	f2c00aaa 	movk	x10, #0x55, lsl #32
     c44:	f87f694a 	ldr	x10, [x10, xzr]
     c48:	b4ff9f8a 	cbz	x10, 38 <trap_handler+0x38>
     c4c:	d294700b 	mov	x11, #0xa380                	// #41856
     c50:	f2a016cb 	movk	x11, #0xb6, lsl #16
     c54:	f2c00aab 	movk	x11, #0x55, lsl #32
     c58:	b87f696b 	ldr	w11, [x11, xzr]
     c5c:	5100116b 	sub	w11, w11, #0x4
     c60:	6b0b013f 	cmp	w9, w11
     c64:	54ff9ea8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     c68:	b8a9694a 	ldrsw	x10, [x10, x9]
     c6c:	d2946c09 	mov	x9, #0xa360                	// #41824
     c70:	f2a016c9 	movk	x9, #0xb6, lsl #16
     c74:	f2c00aa9 	movk	x9, #0x55, lsl #32
     c78:	f87f6929 	ldr	x9, [x9, xzr]
     c7c:	34ff9de9 	cbz	w9, 38 <trap_handler+0x38>
     c80:	d294700b 	mov	x11, #0xa380                	// #41856
     c84:	f2a016cb 	movk	x11, #0xb6, lsl #16
     c88:	f2c00aab 	movk	x11, #0x55, lsl #32
     c8c:	b87f696b 	ldr	w11, [x11, xzr]
     c90:	5100096b 	sub	w11, w11, #0x2
     c94:	6b0b011f 	cmp	w8, w11
     c98:	54ff9d08 	b.hi	38 <trap_handler+0x38>  // b.pmore
     c9c:	7828692a 	strh	w10, [x9, x8]
     ca0:	a8c153f3 	ldp	x19, x20, [sp], #16
     ca4:	a8c17bfd 	ldp	x29, x30, [sp], #16
     ca8:	d65f03c0 	ret

0000000000000cac <as-unary-operand>:
     cac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     cb0:	910003fd 	mov	x29, sp
     cb4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     cb8:	d2946413 	mov	x19, #0xa320                	// #41760
     cbc:	f2a016d3 	movk	x19, #0xb6, lsl #16
     cc0:	f2c00ab3 	movk	x19, #0x55, lsl #32
     cc4:	f87f6a73 	ldr	x19, [x19, xzr]
     cc8:	cb3363f3 	sub	x19, sp, x19
     ccc:	d2800014 	mov	x20, #0x0                   	// #0
     cd0:	f2a00814 	movk	x20, #0x40, lsl #16
     cd4:	eb14027f 	cmp	x19, x20
     cd8:	54ff9b4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     cdc:	52800c88 	mov	w8, #0x64                  	// #100
     ce0:	d2946c09 	mov	x9, #0xa360                	// #41824
     ce4:	f2a016c9 	movk	x9, #0xb6, lsl #16
     ce8:	f2c00aa9 	movk	x9, #0x55, lsl #32
     cec:	f87f6929 	ldr	x9, [x9, xzr]
     cf0:	b4ff9a49 	cbz	x9, 38 <trap_handler+0x38>
     cf4:	d294700a 	mov	x10, #0xa380                	// #41856
     cf8:	f2a016ca 	movk	x10, #0xb6, lsl #16
     cfc:	f2c00aaa 	movk	x10, #0x55, lsl #32
     d00:	b87f694a 	ldr	w10, [x10, xzr]
     d04:	5100114a 	sub	w10, w10, #0x4
     d08:	6b0a011f 	cmp	w8, w10
     d0c:	54ff9968 	b.hi	38 <trap_handler+0x38>  // b.pmore
     d10:	b8a86929 	ldrsw	x9, [x9, x8]
     d14:	5ac01129 	clz	w9, w9
     d18:	2a0903e0 	mov	w0, w9
     d1c:	a8c153f3 	ldp	x19, x20, [sp], #16
     d20:	a8c17bfd 	ldp	x29, x30, [sp], #16
     d24:	d65f03c0 	ret

0000000000000d28 <as-binary-left>:
     d28:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     d2c:	910003fd 	mov	x29, sp
     d30:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     d34:	d2946413 	mov	x19, #0xa320                	// #41760
     d38:	f2a016d3 	movk	x19, #0xb6, lsl #16
     d3c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     d40:	f87f6a73 	ldr	x19, [x19, xzr]
     d44:	cb3363f3 	sub	x19, sp, x19
     d48:	d2800014 	mov	x20, #0x0                   	// #0
     d4c:	f2a00814 	movk	x20, #0x40, lsl #16
     d50:	eb14027f 	cmp	x19, x20
     d54:	54ff976b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     d58:	52800c88 	mov	w8, #0x64                  	// #100
     d5c:	d2946c09 	mov	x9, #0xa360                	// #41824
     d60:	f2a016c9 	movk	x9, #0xb6, lsl #16
     d64:	f2c00aa9 	movk	x9, #0x55, lsl #32
     d68:	f87f6929 	ldr	x9, [x9, xzr]
     d6c:	b4ff9669 	cbz	x9, 38 <trap_handler+0x38>
     d70:	d294700a 	mov	x10, #0xa380                	// #41856
     d74:	f2a016ca 	movk	x10, #0xb6, lsl #16
     d78:	f2c00aaa 	movk	x10, #0x55, lsl #32
     d7c:	b87f694a 	ldr	w10, [x10, xzr]
     d80:	5100114a 	sub	w10, w10, #0x4
     d84:	6b0a011f 	cmp	w8, w10
     d88:	54ff9588 	b.hi	38 <trap_handler+0x38>  // b.pmore
     d8c:	b8a86929 	ldrsw	x9, [x9, x8]
     d90:	52800148 	mov	w8, #0xa                   	// #10
     d94:	0b080129 	add	w9, w9, w8
     d98:	2a0903e0 	mov	w0, w9
     d9c:	a8c153f3 	ldp	x19, x20, [sp], #16
     da0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     da4:	d65f03c0 	ret

0000000000000da8 <as-binary-right>:
     da8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     dac:	910003fd 	mov	x29, sp
     db0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     db4:	d2946413 	mov	x19, #0xa320                	// #41760
     db8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     dbc:	f2c00ab3 	movk	x19, #0x55, lsl #32
     dc0:	f87f6a73 	ldr	x19, [x19, xzr]
     dc4:	cb3363f3 	sub	x19, sp, x19
     dc8:	d2800014 	mov	x20, #0x0                   	// #0
     dcc:	f2a00814 	movk	x20, #0x40, lsl #16
     dd0:	eb14027f 	cmp	x19, x20
     dd4:	54ff936b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     dd8:	52800148 	mov	w8, #0xa                   	// #10
     ddc:	52800c89 	mov	w9, #0x64                  	// #100
     de0:	d2946c0a 	mov	x10, #0xa360                	// #41824
     de4:	f2a016ca 	movk	x10, #0xb6, lsl #16
     de8:	f2c00aaa 	movk	x10, #0x55, lsl #32
     dec:	f87f694a 	ldr	x10, [x10, xzr]
     df0:	b4ff924a 	cbz	x10, 38 <trap_handler+0x38>
     df4:	d294700b 	mov	x11, #0xa380                	// #41856
     df8:	f2a016cb 	movk	x11, #0xb6, lsl #16
     dfc:	f2c00aab 	movk	x11, #0x55, lsl #32
     e00:	b87f696b 	ldr	w11, [x11, xzr]
     e04:	5100116b 	sub	w11, w11, #0x4
     e08:	6b0b013f 	cmp	w9, w11
     e0c:	54ff9168 	b.hi	38 <trap_handler+0x38>  // b.pmore
     e10:	b8a9694a 	ldrsw	x10, [x10, x9]
     e14:	4b0a0108 	sub	w8, w8, w10
     e18:	2a0803e0 	mov	w0, w8
     e1c:	a8c153f3 	ldp	x19, x20, [sp], #16
     e20:	a8c17bfd 	ldp	x29, x30, [sp], #16
     e24:	d65f03c0 	ret

0000000000000e28 <as-test-operand>:
     e28:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     e2c:	910003fd 	mov	x29, sp
     e30:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     e34:	d2946413 	mov	x19, #0xa320                	// #41760
     e38:	f2a016d3 	movk	x19, #0xb6, lsl #16
     e3c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     e40:	f87f6a73 	ldr	x19, [x19, xzr]
     e44:	cb3363f3 	sub	x19, sp, x19
     e48:	d2800014 	mov	x20, #0x0                   	// #0
     e4c:	f2a00814 	movk	x20, #0x40, lsl #16
     e50:	eb14027f 	cmp	x19, x20
     e54:	54ff8f6b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     e58:	52800c88 	mov	w8, #0x64                  	// #100
     e5c:	d2946c09 	mov	x9, #0xa360                	// #41824
     e60:	f2a016c9 	movk	x9, #0xb6, lsl #16
     e64:	f2c00aa9 	movk	x9, #0x55, lsl #32
     e68:	f87f6929 	ldr	x9, [x9, xzr]
     e6c:	b4ff8e69 	cbz	x9, 38 <trap_handler+0x38>
     e70:	d294700a 	mov	x10, #0xa380                	// #41856
     e74:	f2a016ca 	movk	x10, #0xb6, lsl #16
     e78:	f2c00aaa 	movk	x10, #0x55, lsl #32
     e7c:	b87f694a 	ldr	w10, [x10, xzr]
     e80:	5100114a 	sub	w10, w10, #0x4
     e84:	6b0a011f 	cmp	w8, w10
     e88:	54ff8d88 	b.hi	38 <trap_handler+0x38>  // b.pmore
     e8c:	b8a86929 	ldrsw	x9, [x9, x8]
     e90:	34000069 	cbz	w9, e9c <as-test-operand+0x74>
     e94:	52800009 	mov	w9, #0x0                   	// #0
     e98:	14000002 	b	ea0 <as-test-operand+0x78>
     e9c:	52800029 	mov	w9, #0x1                   	// #1
     ea0:	2a0903e0 	mov	w0, w9
     ea4:	a8c153f3 	ldp	x19, x20, [sp], #16
     ea8:	a8c17bfd 	ldp	x29, x30, [sp], #16
     eac:	d65f03c0 	ret

0000000000000eb0 <as-compare-left>:
     eb0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     eb4:	910003fd 	mov	x29, sp
     eb8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     ebc:	d2946413 	mov	x19, #0xa320                	// #41760
     ec0:	f2a016d3 	movk	x19, #0xb6, lsl #16
     ec4:	f2c00ab3 	movk	x19, #0x55, lsl #32
     ec8:	f87f6a73 	ldr	x19, [x19, xzr]
     ecc:	cb3363f3 	sub	x19, sp, x19
     ed0:	d2800014 	mov	x20, #0x0                   	// #0
     ed4:	f2a00814 	movk	x20, #0x40, lsl #16
     ed8:	eb14027f 	cmp	x19, x20
     edc:	54ff8b2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     ee0:	52800c88 	mov	w8, #0x64                  	// #100
     ee4:	d2946c09 	mov	x9, #0xa360                	// #41824
     ee8:	f2a016c9 	movk	x9, #0xb6, lsl #16
     eec:	f2c00aa9 	movk	x9, #0x55, lsl #32
     ef0:	f87f6929 	ldr	x9, [x9, xzr]
     ef4:	b4ff8a29 	cbz	x9, 38 <trap_handler+0x38>
     ef8:	d294700a 	mov	x10, #0xa380                	// #41856
     efc:	f2a016ca 	movk	x10, #0xb6, lsl #16
     f00:	f2c00aaa 	movk	x10, #0x55, lsl #32
     f04:	b87f694a 	ldr	w10, [x10, xzr]
     f08:	5100114a 	sub	w10, w10, #0x4
     f0c:	6b0a011f 	cmp	w8, w10
     f10:	54ff8948 	b.hi	38 <trap_handler+0x38>  // b.pmore
     f14:	b8a86929 	ldrsw	x9, [x9, x8]
     f18:	52800148 	mov	w8, #0xa                   	// #10
     f1c:	6b08013f 	cmp	w9, w8
     f20:	5400006d 	b.le	f2c <as-compare-left+0x7c>
     f24:	52800009 	mov	w9, #0x0                   	// #0
     f28:	14000002 	b	f30 <as-compare-left+0x80>
     f2c:	52800029 	mov	w9, #0x1                   	// #1
     f30:	2a0903e0 	mov	w0, w9
     f34:	a8c153f3 	ldp	x19, x20, [sp], #16
     f38:	a8c17bfd 	ldp	x29, x30, [sp], #16
     f3c:	d65f03c0 	ret

0000000000000f40 <as-compare-right>:
     f40:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     f44:	910003fd 	mov	x29, sp
     f48:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     f4c:	d2946413 	mov	x19, #0xa320                	// #41760
     f50:	f2a016d3 	movk	x19, #0xb6, lsl #16
     f54:	f2c00ab3 	movk	x19, #0x55, lsl #32
     f58:	f87f6a73 	ldr	x19, [x19, xzr]
     f5c:	cb3363f3 	sub	x19, sp, x19
     f60:	d2800014 	mov	x20, #0x0                   	// #0
     f64:	f2a00814 	movk	x20, #0x40, lsl #16
     f68:	eb14027f 	cmp	x19, x20
     f6c:	54ff86ab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     f70:	52800148 	mov	w8, #0xa                   	// #10
     f74:	52800c89 	mov	w9, #0x64                  	// #100
     f78:	d2946c0a 	mov	x10, #0xa360                	// #41824
     f7c:	f2a016ca 	movk	x10, #0xb6, lsl #16
     f80:	f2c00aaa 	movk	x10, #0x55, lsl #32
     f84:	f87f694a 	ldr	x10, [x10, xzr]
     f88:	b4ff858a 	cbz	x10, 38 <trap_handler+0x38>
     f8c:	d294700b 	mov	x11, #0xa380                	// #41856
     f90:	f2a016cb 	movk	x11, #0xb6, lsl #16
     f94:	f2c00aab 	movk	x11, #0x55, lsl #32
     f98:	b87f696b 	ldr	w11, [x11, xzr]
     f9c:	5100116b 	sub	w11, w11, #0x4
     fa0:	6b0b013f 	cmp	w9, w11
     fa4:	54ff84a8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     fa8:	b8a9694a 	ldrsw	x10, [x10, x9]
     fac:	eb0a011f 	cmp	x8, x10
     fb0:	54000061 	b.ne	fbc <as-compare-right+0x7c>  // b.any
     fb4:	52800008 	mov	w8, #0x0                   	// #0
     fb8:	14000002 	b	fc0 <as-compare-right+0x80>
     fbc:	52800028 	mov	w8, #0x1                   	// #1
     fc0:	2a0803e0 	mov	w0, w8
     fc4:	a8c153f3 	ldp	x19, x20, [sp], #16
     fc8:	a8c17bfd 	ldp	x29, x30, [sp], #16
     fcc:	d65f03c0 	ret

0000000000000fd0 <as-memory.grow-size>:
     fd0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     fd4:	910003fd 	mov	x29, sp
     fd8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     fdc:	d2946413 	mov	x19, #0xa320                	// #41760
     fe0:	f2a016d3 	movk	x19, #0xb6, lsl #16
     fe4:	f2c00ab3 	movk	x19, #0x55, lsl #32
     fe8:	f87f6a73 	ldr	x19, [x19, xzr]
     fec:	cb3363f3 	sub	x19, sp, x19
     ff0:	d2800014 	mov	x20, #0x0                   	// #0
     ff4:	f2a00814 	movk	x20, #0x40, lsl #16
     ff8:	eb14027f 	cmp	x19, x20
     ffc:	54ff822b 	b.lt	40 <trap_handler+0x40>  // b.tstop
    1000:	52800c88 	mov	w8, #0x64                  	// #100
    1004:	d2946c09 	mov	x9, #0xa360                	// #41824
    1008:	f2a016c9 	movk	x9, #0xb6, lsl #16
    100c:	f2c00aa9 	movk	x9, #0x55, lsl #32
    1010:	f87f6929 	ldr	x9, [x9, xzr]
    1014:	b4ff8129 	cbz	x9, 38 <trap_handler+0x38>
    1018:	d294700a 	mov	x10, #0xa380                	// #41856
    101c:	f2a016ca 	movk	x10, #0xb6, lsl #16
    1020:	f2c00aaa 	movk	x10, #0x55, lsl #32
    1024:	b87f694a 	ldr	w10, [x10, xzr]
    1028:	5100114a 	sub	w10, w10, #0x4
    102c:	6b0a011f 	cmp	w8, w10
    1030:	54ff8048 	b.hi	38 <trap_handler+0x38>  // b.pmore
    1034:	b8a86929 	ldrsw	x9, [x9, x8]
    1038:	d2947208 	mov	x8, #0xa390                	// #41872
    103c:	f2a016c8 	movk	x8, #0xb6, lsl #16
    1040:	f2c00aa8 	movk	x8, #0x55, lsl #32
    1044:	f87f6908 	ldr	x8, [x8, xzr]
    1048:	d2946600 	mov	x0, #0xa330                	// #41776
    104c:	f2a016c0 	movk	x0, #0xb6, lsl #16
    1050:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1054:	f87f6800 	ldr	x0, [x0, xzr]
    1058:	aa0903e1 	mov	x1, x9
    105c:	d63f0100 	blr	x8
    1060:	aa0003e8 	mov	x8, x0
    1064:	2a0803e0 	mov	w0, w8
    1068:	a8c153f3 	ldp	x19, x20, [sp], #16
    106c:	a8c17bfd 	ldp	x29, x30, [sp], #16
    1070:	d65f03c0 	ret

0000000000001074 <address-as-param>:
    1074:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    1078:	910003fd 	mov	x29, sp
    107c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    1080:	d2946413 	mov	x19, #0xa320                	// #41760
    1084:	f2a016d3 	movk	x19, #0xb6, lsl #16
    1088:	f2c00ab3 	movk	x19, #0x55, lsl #32
    108c:	f87f6a73 	ldr	x19, [x19, xzr]
    1090:	cb3363f3 	sub	x19, sp, x19
    1094:	d2800014 	mov	x20, #0x0                   	// #0
    1098:	f2a00814 	movk	x20, #0x40, lsl #16
    109c:	eb14027f 	cmp	x19, x20
    10a0:	54ff7d0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
    10a4:	d10043ff 	sub	sp, sp, #0x10
    10a8:	b90013e0 	str	w0, [sp, #16]
    10ac:	b94013e8 	ldr	w8, [sp, #16]
    10b0:	d2946c09 	mov	x9, #0xa360                	// #41824
    10b4:	f2a016c9 	movk	x9, #0xb6, lsl #16
    10b8:	f2c00aa9 	movk	x9, #0x55, lsl #32
    10bc:	f87f6929 	ldr	x9, [x9, xzr]
    10c0:	b4ff7bc9 	cbz	x9, 38 <trap_handler+0x38>
    10c4:	d294700a 	mov	x10, #0xa380                	// #41856
    10c8:	f2a016ca 	movk	x10, #0xb6, lsl #16
    10cc:	f2c00aaa 	movk	x10, #0x55, lsl #32
    10d0:	b87f694a 	ldr	w10, [x10, xzr]
    10d4:	5100114a 	sub	w10, w10, #0x4
    10d8:	6b0a011f 	cmp	w8, w10
    10dc:	54ff7ae8 	b.hi	38 <trap_handler+0x38>  // b.pmore
    10e0:	b8a86929 	ldrsw	x9, [x9, x8]
    10e4:	d2947208 	mov	x8, #0xa390                	// #41872
    10e8:	f2a016c8 	movk	x8, #0xb6, lsl #16
    10ec:	f2c00aa8 	movk	x8, #0x55, lsl #32
    10f0:	f87f6908 	ldr	x8, [x8, xzr]
    10f4:	d2946600 	mov	x0, #0xa330                	// #41776
    10f8:	f2a016c0 	movk	x0, #0xb6, lsl #16
    10fc:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1100:	f87f6800 	ldr	x0, [x0, xzr]
    1104:	aa0903e1 	mov	x1, x9
    1108:	d63f0100 	blr	x8
    110c:	aa0003e8 	mov	x8, x0
    1110:	2a0803e0 	mov	w0, w8
    1114:	910043ff 	add	sp, sp, #0x10
    1118:	a8c153f3 	ldp	x19, x20, [sp], #16
    111c:	a8c17bfd 	ldp	x29, x30, [sp], #16
    1120:	d65f03c0 	ret
