
./tests/machinecode/linear-memory-grow.4.o:     file format elf64-littleaarch64

SYMBOL TABLE:
0000000000000000 g     F .text	000000000000005c trap_handler
0000000000000064 g     F .text	0000000000000074 as-br-value
00000000000000d8 g     F .text	0000000000000070 as-br_if-cond
0000000000000148 g     F .text	000000000000007c as-br_if-value
00000000000001c4 g     F .text	000000000000007c as-br_if-value-cond
0000000000000240 g     F .text	0000000000000074 as-return-value
00000000000002b4 g     F .text	0000000000000080 as-if-cond
0000000000000334 g     F .text	0000000000000080 as-if-then
00000000000003b4 g     F .text	0000000000000080 as-if-else
0000000000000434 g     F .text	000000000000005c func_8
0000000000000490 g     F .text	00000000000000b4 as-call-first
0000000000000544 g     F .text	00000000000000b4 as-call-mid
00000000000005f8 g     F .text	00000000000000b4 as-call-last
00000000000006ac g     F .text	00000000000000d0 as-call_indirect-first
000000000000077c g     F .text	00000000000000d0 as-call_indirect-mid
000000000000084c g     F .text	00000000000000d0 as-call_indirect-last
000000000000091c g     F .text	00000000000000d0 as-call_indirect-index
00000000000009ec g     F .text	000000000000007c as-local.set-value
0000000000000a68 g     F .text	0000000000000080 as-local.tee-value
0000000000000ae8 g     F .text	0000000000000090 as-global.set-value
0000000000000b78 g     F .text	00000000000000a4 as-load-address
0000000000000c1c g     F .text	00000000000000a4 as-loadN-address
0000000000000cc0 g     F .text	00000000000000a4 as-store-address
0000000000000d64 g     F .text	00000000000000a4 as-store-value
0000000000000e08 g     F .text	00000000000000a4 as-storeN-address
0000000000000eac g     F .text	00000000000000a4 as-storeN-value
0000000000000f50 g     F .text	0000000000000074 as-unary-operand
0000000000000fc4 g     F .text	0000000000000078 as-binary-left
000000000000103c g     F .text	0000000000000078 as-binary-right
00000000000010b4 g     F .text	0000000000000080 as-test-operand
0000000000001134 g     F .text	0000000000000088 as-compare-left
00000000000011bc g     F .text	0000000000000088 as-compare-right
0000000000001244 g     F .text	000000000000009c as-memory.grow-size
000000000000005c g     O .text	0000000000000008 function_table
0000000000000000 g     O .rodata	0000000000000008 globals


Contents of section .text:
 0000 e01f80d2 11000014 200080d2 0f000014  ........ .......
 0010 a00080d2 0d000014 c00080d2 0b000014  ................
 0020 600080d2 09000014 800080d2 07000014  `...............
 0030 200180d2 05000014 400080d2 03000014   .......@.......
 0040 000180d2 01000014 094b91d2 090aa0f2  .........K......
 0050 a90ac0f2 0900e0f2 20011fd6 34040000  ........ ...4...
 0060 00000000 fd7bbfa9 fd030091 f353bfa9  .....{.......S..
 0070 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0080 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0090 8bfdff54 08008052 097294d2 c916a0f2  ...T...R.r......
 00a0 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 00b0 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 00c0 e80300aa 3f0000b4 e003082a f353c1a8  ....?......*.S..
 00d0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 00e0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 00f0 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0100 7f0214eb ebf9ff54 08008052 097294d2  .......T...R.r..
 0110 c916a0f2 a90ac0f2 29697ff8 006694d2  ........)i...f..
 0120 c016a0f2 a00ac0f2 00687ff8 e10308aa  .........h......
 0130 20013fd6 e80300aa 28000035 f353c1a8   .?.....(..5.S..
 0140 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0150 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0160 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0170 7f0214eb 6bf6ff54 08008052 097294d2  ....k..T...R.r..
 0180 c916a0f2 a90ac0f2 29697ff8 006694d2  ........)i...f..
 0190 c016a0f2 a00ac0f2 00687ff8 e10308aa  .........h......
 01a0 20013fd6 e80300aa 29008052 49000035   .?.....)..RI..5
 01b0 e8008052 e003082a f353c1a8 fd7bc1a8  ...R...*.S...{..
 01c0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 01d0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 01e0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 01f0 8bf2ff54 c8008052 09008052 0a7294d2  ...T...R...R.r..
 0200 ca16a0f2 aa0ac0f2 4a697ff8 006694d2  ........Ji...f..
 0210 c016a0f2 a00ac0f2 00687ff8 e10309aa  .........h......
 0220 40013fd6 e90300aa 49000035 e8008052  @.?.....I..5...R
 0230 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0240 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0250 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0260 140080d2 1408a0f2 7f0214eb abeeff54  ...............T
 0270 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 0280 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 0290 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 02a0 3f0000b4 e003082a f353c1a8 fd7bc1a8  ?......*.S...{..
 02b0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 02c0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 02d0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 02e0 0bebff54 08008052 097294d2 c916a0f2  ...T...R.r......
 02f0 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 0300 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 0310 e80300aa 68000034 08008052 02000014  ....h..4...R....
 0320 28008052 e003082a f353c1a8 fd7bc1a8  (..R...*.S...{..
 0330 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0340 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0350 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0360 0be7ff54 28008052 c8010034 08008052  ...T(..R...4...R
 0370 097294d2 c916a0f2 a90ac0f2 29697ff8  .r..........)i..
 0380 006694d2 c016a0f2 a00ac0f2 00687ff8  .f...........h..
 0390 e10308aa 20013fd6 e80300aa 02000014  .... .?.........
 03a0 08008052 e003082a f353c1a8 fd7bc1a8  ...R...*.S...{..
 03b0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 03c0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 03d0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 03e0 0be3ff54 08008052 68000034 08008052  ...T...Rh..4...R
 03f0 0d000014 08008052 097294d2 c916a0f2  .......R.r......
 0400 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 0410 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 0420 e80300aa e003082a f353c1a8 fd7bc1a8  .......*.S...{..
 0430 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0440 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0450 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0460 0bdfff54 ff4300d1 e01300b9 e10f00b9  ...T.C..........
 0470 e20b00b9 e8ff9f52 e8ffbf72 e003082a  .......R...r...*
 0480 ff430091 f353c1a8 fd7bc1a8 c0035fd6  .C...S...{...._.
 0490 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 04a0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 04b0 140080d2 1408a0f2 7f0214eb 2bdcff54  ............+..T
 04c0 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 04d0 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 04e0 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 04f0 49008052 6a008052 e2030a2a e103092a  I..Rj..R...*...*
 0500 e003082a ff0301d1 e82703a9 ea2f02a9  ...*.....'.../..
 0510 ec3701a9 ee3f00a9 c7ffff97 e82743a9  .7...?.......'C.
 0520 ea2f42a9 ec3741a9 ee3f40a9 ff030191  ./B..7A..?@.....
 0530 e80300aa e003082a f353c1a8 fd7bc1a8  .......*.S...{..
 0540 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0550 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0560 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0570 8bd6ff54 28008052 09008052 0a7294d2  ...T(..R...R.r..
 0580 ca16a0f2 aa0ac0f2 4a697ff8 006694d2  ........Ji...f..
 0590 c016a0f2 a00ac0f2 00687ff8 e10309aa  .........h......
 05a0 40013fd6 e90300aa 6a008052 e2030a2a  @.?.....j..R...*
 05b0 e103092a e003082a ff0301d1 e82703a9  ...*...*.....'..
 05c0 ea2f02a9 ec3701a9 ee3f00a9 9affff97  ./...7...?......
 05d0 e82743a9 ea2f42a9 ec3741a9 ee3f40a9  .'C../B..7A..?@.
 05e0 ff030191 e80300aa e003082a f353c1a8  ...........*.S..
 05f0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0600 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0610 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0620 7f0214eb ebd0ff54 28008052 49008052  .......T(..RI..R
 0630 0a008052 0b7294d2 cb16a0f2 ab0ac0f2  ...R.r..........
 0640 6b697ff8 006694d2 c016a0f2 a00ac0f2  ki...f..........
 0650 00687ff8 e1030aaa 60013fd6 ea0300aa  .h......`.?.....
 0660 e2030a2a e103092a e003082a ff0301d1  ...*...*...*....
 0670 e82703a9 ea2f02a9 ec3701a9 ee3f00a9  .'.../...7...?..
 0680 6dffff97 e82743a9 ea2f42a9 ec3741a9  m....'C../B..7A.
 0690 ee3f40a9 ff030191 e80300aa e003082a  .?@............*
 06a0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 06b0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 06c0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 06d0 1408a0f2 7f0214eb 4bcbff54 08008052  ........K..T...R
 06e0 097294d2 c916a0f2 a90ac0f2 29697ff8  .r..........)i..
 06f0 006694d2 c016a0f2 a00ac0f2 00687ff8  .f...........h..
 0700 e10308aa 20013fd6 e80300aa 49008052  .... .?.....I..R
 0710 6a008052 0b008052 7f0500f1 2ac8ff54  j..R...R....*..T
 0720 0c000090 8c710191 8c796bf8 9f0500b1  .....q...yk.....
 0730 c0c7ff54 8dfd60d3 bf010071 a1c7ff54  ...T..`....q...T
 0740 0b6094d2 cb16a0f2 ab0ac0f2 6b697ff8  .`..........ki..
 0750 ec030c2a 6c010c8b e2030a2a e103092a  ...*l......*...*
 0760 e003082a 80013fd6 e80300aa e003082a  ...*..?........*
 0770 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0780 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0790 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 07a0 1408a0f2 7f0214eb cbc4ff54 28008052  ...........T(..R
 07b0 09008052 0a7294d2 ca16a0f2 aa0ac0f2  ...R.r..........
 07c0 4a697ff8 006694d2 c016a0f2 a00ac0f2  Ji...f..........
 07d0 00687ff8 e10309aa 40013fd6 e90300aa  .h......@.?.....
 07e0 6a008052 0b008052 7f0500f1 aac1ff54  j..R...R.......T
 07f0 0c000090 8c710191 8c796bf8 9f0500b1  .....q...yk.....
 0800 40c1ff54 8dfd60d3 bf010071 21c1ff54  @..T..`....q!..T
 0810 0b6094d2 cb16a0f2 ab0ac0f2 6b697ff8  .`..........ki..
 0820 ec030c2a 6c010c8b e2030a2a e103092a  ...*l......*...*
 0830 e003082a 80013fd6 e80300aa e003082a  ...*..?........*
 0840 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0850 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0860 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0870 1408a0f2 7f0214eb 4bbeff54 28008052  ........K..T(..R
 0880 49008052 0a008052 0b7294d2 cb16a0f2  I..R...R.r......
 0890 ab0ac0f2 6b697ff8 006694d2 c016a0f2  ....ki...f......
 08a0 a00ac0f2 00687ff8 e1030aaa 60013fd6  .....h......`.?.
 08b0 ea0300aa 0b008052 7f0500f1 2abbff54  .......R....*..T
 08c0 0c000090 8c710191 8c796bf8 9f0500b1  .....q...yk.....
 08d0 c0baff54 8dfd60d3 bf010071 a1baff54  ...T..`....q...T
 08e0 0b6094d2 cb16a0f2 ab0ac0f2 6b697ff8  .`..........ki..
 08f0 ec030c2a 6c010c8b e2030a2a e103092a  ...*l......*...*
 0900 e003082a 80013fd6 e80300aa e003082a  ...*..?........*
 0910 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0920 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0930 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0940 1408a0f2 7f0214eb cbb7ff54 28008052  ...........T(..R
 0950 49008052 6a008052 0b008052 0c7294d2  I..Rj..R...R.r..
 0960 cc16a0f2 ac0ac0f2 8c697ff8 006694d2  .........i...f..
 0970 c016a0f2 a00ac0f2 00687ff8 e1030baa  .........h......
 0980 80013fd6 eb0300aa 7f0500f1 aab4ff54  ..?............T
 0990 0c000090 8c710191 8c796bf8 9f0500b1  .....q...yk.....
 09a0 40b4ff54 8dfd60d3 bf010071 21b4ff54  @..T..`....q!..T
 09b0 0b6094d2 cb16a0f2 ab0ac0f2 6b697ff8  .`..........ki..
 09c0 ec030c2a 6c010c8b e2030a2a e103092a  ...*l......*...*
 09d0 e003082a 80013fd6 e80300aa e003082a  ...*..?........*
 09e0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 09f0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0a00 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0a10 1408a0f2 7f0214eb 4bb1ff54 ff4300d1  ........K..T.C..
 0a20 ff1300b9 08008052 097294d2 c916a0f2  .......R.r......
 0a30 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 0a40 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 0a50 e80300aa e81300b9 ff430091 f353c1a8  .........C...S..
 0a60 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0a70 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0a80 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0a90 7f0214eb 6badff54 ff4300d1 ff1300b9  ....k..T.C......
 0aa0 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 0ab0 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 0ac0 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 0ad0 e81300b9 e003082a ff430091 f353c1a8  .......*.C...S..
 0ae0 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0af0 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0b00 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0b10 7f0214eb 6ba9ff54 ff4300d1 ff1300b9  ....k..T.C......
 0b20 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 0b30 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 0b40 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 0b50 096294d2 c916a0f2 a90ac0f2 29697ff8  .b..........)i..
 0b60 29010091 28693ff8 ff430091 f353c1a8  )...(i?..C...S..
 0b70 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0b80 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0b90 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0ba0 7f0214eb eba4ff54 08008052 097294d2  .......T...R.r..
 0bb0 c916a0f2 a90ac0f2 29697ff8 006694d2  ........)i...f..
 0bc0 c016a0f2 a00ac0f2 00687ff8 e10308aa  .........h......
 0bd0 20013fd6 e80300aa 096c94d2 c916a0f2   .?......l......
 0be0 a90ac0f2 29697ff8 89a2ffb4 0a7094d2  ....)i.......p..
 0bf0 ca16a0f2 aa0ac0f2 4a697fb8 4a110051  ........Ji..J..Q
 0c00 1f010a6b a8a1ff54 2969a8b8 e003092a  ...k...T)i.....*
 0c10 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0c20 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0c30 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0c40 1408a0f2 7f0214eb cb9fff54 08008052  ...........T...R
 0c50 097294d2 c916a0f2 a90ac0f2 29697ff8  .r..........)i..
 0c60 006694d2 c016a0f2 a00ac0f2 00687ff8  .f...........h..
 0c70 e10308aa 20013fd6 e80300aa 096c94d2  .... .?......l..
 0c80 c916a0f2 a90ac0f2 29697ff8 699dff34  ........)i..i..4
 0c90 0a7094d2 ca16a0f2 aa0ac0f2 4a697fb8  .p..........Ji..
 0ca0 4a050051 1f010a6b 889cff54 2979e838  J..Q...k...T)y.8
 0cb0 e003092a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
 0cc0 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0cd0 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0ce0 140080d2 1408a0f2 7f0214eb ab9aff54  ...............T
 0cf0 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 0d00 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 0d10 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 0d20 e9008052 0a6c94d2 ca16a0f2 aa0ac0f2  ...R.l..........
 0d30 4a697ff8 2a98ff34 0b7094d2 cb16a0f2  Ji..*..4.p......
 0d40 ab0ac0f2 6b697fb8 6b110051 1f010b6b  ....ki..k..Q...k
 0d50 4897ff54 496928b8 f353c1a8 fd7bc1a8  H..TIi(..S...{..
 0d60 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0d70 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0d80 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0d90 8b95ff54 48008052 09008052 0a7294d2  ...TH..R...R.r..
 0da0 ca16a0f2 aa0ac0f2 4a697ff8 006694d2  ........Ji...f..
 0db0 c016a0f2 a00ac0f2 00687ff8 e10309aa  .........h......
 0dc0 40013fd6 e90300aa 0a6c94d2 ca16a0f2  @.?......l......
 0dd0 aa0ac0f2 4a697ff8 0a93ff34 0b7094d2  ....Ji.....4.p..
 0de0 cb16a0f2 ab0ac0f2 6b697fb8 6b110051  ........ki..k..Q
 0df0 1f010b6b 2892ff54 496928b8 f353c1a8  ...k(..TIi(..S..
 0e00 fd7bc1a8 c0035fd6 fd7bbfa9 fd030091  .{...._..{......
 0e10 f353bfa9 136494d2 d316a0f2 b30ac0f2  .S...d..........
 0e20 736a7ff8 f36333cb 140080d2 1408a0f2  sj...c3.........
 0e30 7f0214eb 6b90ff54 08008052 097294d2  ....k..T...R.r..
 0e40 c916a0f2 a90ac0f2 29697ff8 006694d2  ........)i...f..
 0e50 c016a0f2 a00ac0f2 00687ff8 e10308aa  .........h......
 0e60 20013fd6 e80300aa e9008052 0a6c94d2   .?........R.l..
 0e70 ca16a0f2 aa0ac0f2 4a697ff8 ea8dff34  ........Ji.....4
 0e80 0b7094d2 cb16a0f2 ab0ac0f2 6b697fb8  .p..........ki..
 0e90 6b050051 1f010b6b 088dff54 49792838  k..Q...k...TIy(8
 0ea0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 0eb0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 0ec0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 0ed0 1408a0f2 7f0214eb 4b8bff54 48008052  ........K..TH..R
 0ee0 09008052 0a7294d2 ca16a0f2 aa0ac0f2  ...R.r..........
 0ef0 4a697ff8 006694d2 c016a0f2 a00ac0f2  Ji...f..........
 0f00 00687ff8 e10309aa 40013fd6 e90300aa  .h......@.?.....
 0f10 0a6c94d2 ca16a0f2 aa0ac0f2 4a697ff8  .l..........Ji..
 0f20 ca88ff34 0b7094d2 cb16a0f2 ab0ac0f2  ...4.p..........
 0f30 6b697fb8 6b090051 1f010b6b e887ff54  ki..k..Q...k...T
 0f40 49692878 f353c1a8 fd7bc1a8 c0035fd6  Ii(x.S...{...._.
 0f50 fd7bbfa9 fd030091 f353bfa9 136494d2  .{.......S...d..
 0f60 d316a0f2 b30ac0f2 736a7ff8 f36333cb  ........sj...c3.
 0f70 140080d2 1408a0f2 7f0214eb 2b86ff54  ............+..T
 0f80 08008052 097294d2 c916a0f2 a90ac0f2  ...R.r..........
 0f90 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 0fa0 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 0fb0 0811c05a e003082a f353c1a8 fd7bc1a8  ...Z...*.S...{..
 0fc0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 0fd0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 0fe0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 0ff0 8b82ff54 08008052 097294d2 c916a0f2  ...T...R.r......
 1000 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 1010 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 1020 e80300aa 49018052 0801090b e003082a  ....I..R.......*
 1030 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 1040 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 1050 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 1060 1408a0f2 7f0214eb cb7eff54 48018052  .........~.TH..R
 1070 09008052 0a7294d2 ca16a0f2 aa0ac0f2  ...R.r..........
 1080 4a697ff8 006694d2 c016a0f2 a00ac0f2  Ji...f..........
 1090 00687ff8 e10309aa 40013fd6 e90300aa  .h......@.?.....
 10a0 0801094b e003082a f353c1a8 fd7bc1a8  ...K...*.S...{..
 10b0 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 10c0 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 10d0 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 10e0 0b7bff54 08008052 097294d2 c916a0f2  .{.T...R.r......
 10f0 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 1100 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 1110 e80300aa 68000034 08008052 02000014  ....h..4...R....
 1120 28008052 e003082a f353c1a8 fd7bc1a8  (..R...*.S...{..
 1130 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 1140 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 1150 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 1160 0b77ff54 08008052 097294d2 c916a0f2  .w.T...R.r......
 1170 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 1180 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 1190 e80300aa 49018052 1f01096b 6d000054  ....I..R...km..T
 11a0 08008052 02000014 28008052 e003082a  ...R....(..R...*
 11b0 f353c1a8 fd7bc1a8 c0035fd6 fd7bbfa9  .S...{...._..{..
 11c0 fd030091 f353bfa9 136494d2 d316a0f2  .....S...d......
 11d0 b30ac0f2 736a7ff8 f36333cb 140080d2  ....sj...c3.....
 11e0 1408a0f2 7f0214eb cb72ff54 48018052  .........r.TH..R
 11f0 09008052 0a7294d2 ca16a0f2 aa0ac0f2  ...R.r..........
 1200 4a697ff8 006694d2 c016a0f2 a00ac0f2  Ji...f..........
 1210 00687ff8 e10309aa 40013fd6 e90300aa  .h......@.?.....
 1220 1f0109eb 61000054 08008052 02000014  ....a..T...R....
 1230 28008052 e003082a f353c1a8 fd7bc1a8  (..R...*.S...{..
 1240 c0035fd6 fd7bbfa9 fd030091 f353bfa9  .._..{.......S..
 1250 136494d2 d316a0f2 b30ac0f2 736a7ff8  .d..........sj..
 1260 f36333cb 140080d2 1408a0f2 7f0214eb  .c3.............
 1270 8b6eff54 08008052 097294d2 c916a0f2  .n.T...R.r......
 1280 a90ac0f2 29697ff8 006694d2 c016a0f2  ....)i...f......
 1290 a00ac0f2 00687ff8 e10308aa 20013fd6  .....h...... .?.
 12a0 e80300aa 097294d2 c916a0f2 a90ac0f2  .....r..........
 12b0 29697ff8 006694d2 c016a0f2 a00ac0f2  )i...f..........
 12c0 00687ff8 e10308aa 20013fd6 e80300aa  .h...... .?.....
 12d0 e003082a f353c1a8 fd7bc1a8 c0035fd6  ...*.S...{...._.
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

000000000000005c <function_table>:
      5c:	00000434 00000000                       4.......

0000000000000064 <as-br-value>:
      64:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
      68:	910003fd 	mov	x29, sp
      6c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
      70:	d2946413 	mov	x19, #0xa320                	// #41760
      74:	f2a016d3 	movk	x19, #0xb6, lsl #16
      78:	f2c00ab3 	movk	x19, #0x55, lsl #32
      7c:	f87f6a73 	ldr	x19, [x19, xzr]
      80:	cb3363f3 	sub	x19, sp, x19
      84:	d2800014 	mov	x20, #0x0                   	// #0
      88:	f2a00814 	movk	x20, #0x40, lsl #16
      8c:	eb14027f 	cmp	x19, x20
      90:	54fffd8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
      94:	52800008 	mov	w8, #0x0                   	// #0
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
      c4:	b400003f 	cbz	xzr, c8 <as-br-value+0x64>
      c8:	2a0803e0 	mov	w0, w8
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
     10c:	d2947209 	mov	x9, #0xa390                	// #41872
     110:	f2a016c9 	movk	x9, #0xb6, lsl #16
     114:	f2c00aa9 	movk	x9, #0x55, lsl #32
     118:	f87f6929 	ldr	x9, [x9, xzr]
     11c:	d2946600 	mov	x0, #0xa330                	// #41776
     120:	f2a016c0 	movk	x0, #0xb6, lsl #16
     124:	f2c00aa0 	movk	x0, #0x55, lsl #32
     128:	f87f6800 	ldr	x0, [x0, xzr]
     12c:	aa0803e1 	mov	x1, x8
     130:	d63f0120 	blr	x9
     134:	aa0003e8 	mov	x8, x0
     138:	35000028 	cbnz	w8, 13c <as-br_if-cond+0x64>
     13c:	a8c153f3 	ldp	x19, x20, [sp], #16
     140:	a8c17bfd 	ldp	x29, x30, [sp], #16
     144:	d65f03c0 	ret

0000000000000148 <as-br_if-value>:
     148:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     14c:	910003fd 	mov	x29, sp
     150:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     154:	d2946413 	mov	x19, #0xa320                	// #41760
     158:	f2a016d3 	movk	x19, #0xb6, lsl #16
     15c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     160:	f87f6a73 	ldr	x19, [x19, xzr]
     164:	cb3363f3 	sub	x19, sp, x19
     168:	d2800014 	mov	x20, #0x0                   	// #0
     16c:	f2a00814 	movk	x20, #0x40, lsl #16
     170:	eb14027f 	cmp	x19, x20
     174:	54fff66b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     178:	52800008 	mov	w8, #0x0                   	// #0
     17c:	d2947209 	mov	x9, #0xa390                	// #41872
     180:	f2a016c9 	movk	x9, #0xb6, lsl #16
     184:	f2c00aa9 	movk	x9, #0x55, lsl #32
     188:	f87f6929 	ldr	x9, [x9, xzr]
     18c:	d2946600 	mov	x0, #0xa330                	// #41776
     190:	f2a016c0 	movk	x0, #0xb6, lsl #16
     194:	f2c00aa0 	movk	x0, #0x55, lsl #32
     198:	f87f6800 	ldr	x0, [x0, xzr]
     19c:	aa0803e1 	mov	x1, x8
     1a0:	d63f0120 	blr	x9
     1a4:	aa0003e8 	mov	x8, x0
     1a8:	52800029 	mov	w9, #0x1                   	// #1
     1ac:	35000049 	cbnz	w9, 1b4 <as-br_if-value+0x6c>
     1b0:	528000e8 	mov	w8, #0x7                   	// #7
     1b4:	2a0803e0 	mov	w0, w8
     1b8:	a8c153f3 	ldp	x19, x20, [sp], #16
     1bc:	a8c17bfd 	ldp	x29, x30, [sp], #16
     1c0:	d65f03c0 	ret

00000000000001c4 <as-br_if-value-cond>:
     1c4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     1c8:	910003fd 	mov	x29, sp
     1cc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     1d0:	d2946413 	mov	x19, #0xa320                	// #41760
     1d4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     1d8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     1dc:	f87f6a73 	ldr	x19, [x19, xzr]
     1e0:	cb3363f3 	sub	x19, sp, x19
     1e4:	d2800014 	mov	x20, #0x0                   	// #0
     1e8:	f2a00814 	movk	x20, #0x40, lsl #16
     1ec:	eb14027f 	cmp	x19, x20
     1f0:	54fff28b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     1f4:	528000c8 	mov	w8, #0x6                   	// #6
     1f8:	52800009 	mov	w9, #0x0                   	// #0
     1fc:	d294720a 	mov	x10, #0xa390                	// #41872
     200:	f2a016ca 	movk	x10, #0xb6, lsl #16
     204:	f2c00aaa 	movk	x10, #0x55, lsl #32
     208:	f87f694a 	ldr	x10, [x10, xzr]
     20c:	d2946600 	mov	x0, #0xa330                	// #41776
     210:	f2a016c0 	movk	x0, #0xb6, lsl #16
     214:	f2c00aa0 	movk	x0, #0x55, lsl #32
     218:	f87f6800 	ldr	x0, [x0, xzr]
     21c:	aa0903e1 	mov	x1, x9
     220:	d63f0140 	blr	x10
     224:	aa0003e9 	mov	x9, x0
     228:	35000049 	cbnz	w9, 230 <as-br_if-value-cond+0x6c>
     22c:	528000e8 	mov	w8, #0x7                   	// #7
     230:	2a0803e0 	mov	w0, w8
     234:	a8c153f3 	ldp	x19, x20, [sp], #16
     238:	a8c17bfd 	ldp	x29, x30, [sp], #16
     23c:	d65f03c0 	ret

0000000000000240 <as-return-value>:
     240:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     244:	910003fd 	mov	x29, sp
     248:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     24c:	d2946413 	mov	x19, #0xa320                	// #41760
     250:	f2a016d3 	movk	x19, #0xb6, lsl #16
     254:	f2c00ab3 	movk	x19, #0x55, lsl #32
     258:	f87f6a73 	ldr	x19, [x19, xzr]
     25c:	cb3363f3 	sub	x19, sp, x19
     260:	d2800014 	mov	x20, #0x0                   	// #0
     264:	f2a00814 	movk	x20, #0x40, lsl #16
     268:	eb14027f 	cmp	x19, x20
     26c:	54ffeeab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     270:	52800008 	mov	w8, #0x0                   	// #0
     274:	d2947209 	mov	x9, #0xa390                	// #41872
     278:	f2a016c9 	movk	x9, #0xb6, lsl #16
     27c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     280:	f87f6929 	ldr	x9, [x9, xzr]
     284:	d2946600 	mov	x0, #0xa330                	// #41776
     288:	f2a016c0 	movk	x0, #0xb6, lsl #16
     28c:	f2c00aa0 	movk	x0, #0x55, lsl #32
     290:	f87f6800 	ldr	x0, [x0, xzr]
     294:	aa0803e1 	mov	x1, x8
     298:	d63f0120 	blr	x9
     29c:	aa0003e8 	mov	x8, x0
     2a0:	b400003f 	cbz	xzr, 2a4 <as-return-value+0x64>
     2a4:	2a0803e0 	mov	w0, w8
     2a8:	a8c153f3 	ldp	x19, x20, [sp], #16
     2ac:	a8c17bfd 	ldp	x29, x30, [sp], #16
     2b0:	d65f03c0 	ret

00000000000002b4 <as-if-cond>:
     2b4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     2b8:	910003fd 	mov	x29, sp
     2bc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     2c0:	d2946413 	mov	x19, #0xa320                	// #41760
     2c4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     2c8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     2cc:	f87f6a73 	ldr	x19, [x19, xzr]
     2d0:	cb3363f3 	sub	x19, sp, x19
     2d4:	d2800014 	mov	x20, #0x0                   	// #0
     2d8:	f2a00814 	movk	x20, #0x40, lsl #16
     2dc:	eb14027f 	cmp	x19, x20
     2e0:	54ffeb0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     2e4:	52800008 	mov	w8, #0x0                   	// #0
     2e8:	d2947209 	mov	x9, #0xa390                	// #41872
     2ec:	f2a016c9 	movk	x9, #0xb6, lsl #16
     2f0:	f2c00aa9 	movk	x9, #0x55, lsl #32
     2f4:	f87f6929 	ldr	x9, [x9, xzr]
     2f8:	d2946600 	mov	x0, #0xa330                	// #41776
     2fc:	f2a016c0 	movk	x0, #0xb6, lsl #16
     300:	f2c00aa0 	movk	x0, #0x55, lsl #32
     304:	f87f6800 	ldr	x0, [x0, xzr]
     308:	aa0803e1 	mov	x1, x8
     30c:	d63f0120 	blr	x9
     310:	aa0003e8 	mov	x8, x0
     314:	34000068 	cbz	w8, 320 <as-if-cond+0x6c>
     318:	52800008 	mov	w8, #0x0                   	// #0
     31c:	14000002 	b	324 <as-if-cond+0x70>
     320:	52800028 	mov	w8, #0x1                   	// #1
     324:	2a0803e0 	mov	w0, w8
     328:	a8c153f3 	ldp	x19, x20, [sp], #16
     32c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     330:	d65f03c0 	ret

0000000000000334 <as-if-then>:
     334:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     338:	910003fd 	mov	x29, sp
     33c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     340:	d2946413 	mov	x19, #0xa320                	// #41760
     344:	f2a016d3 	movk	x19, #0xb6, lsl #16
     348:	f2c00ab3 	movk	x19, #0x55, lsl #32
     34c:	f87f6a73 	ldr	x19, [x19, xzr]
     350:	cb3363f3 	sub	x19, sp, x19
     354:	d2800014 	mov	x20, #0x0                   	// #0
     358:	f2a00814 	movk	x20, #0x40, lsl #16
     35c:	eb14027f 	cmp	x19, x20
     360:	54ffe70b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     364:	52800028 	mov	w8, #0x1                   	// #1
     368:	340001c8 	cbz	w8, 3a0 <as-if-then+0x6c>
     36c:	52800008 	mov	w8, #0x0                   	// #0
     370:	d2947209 	mov	x9, #0xa390                	// #41872
     374:	f2a016c9 	movk	x9, #0xb6, lsl #16
     378:	f2c00aa9 	movk	x9, #0x55, lsl #32
     37c:	f87f6929 	ldr	x9, [x9, xzr]
     380:	d2946600 	mov	x0, #0xa330                	// #41776
     384:	f2a016c0 	movk	x0, #0xb6, lsl #16
     388:	f2c00aa0 	movk	x0, #0x55, lsl #32
     38c:	f87f6800 	ldr	x0, [x0, xzr]
     390:	aa0803e1 	mov	x1, x8
     394:	d63f0120 	blr	x9
     398:	aa0003e8 	mov	x8, x0
     39c:	14000002 	b	3a4 <as-if-then+0x70>
     3a0:	52800008 	mov	w8, #0x0                   	// #0
     3a4:	2a0803e0 	mov	w0, w8
     3a8:	a8c153f3 	ldp	x19, x20, [sp], #16
     3ac:	a8c17bfd 	ldp	x29, x30, [sp], #16
     3b0:	d65f03c0 	ret

00000000000003b4 <as-if-else>:
     3b4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     3b8:	910003fd 	mov	x29, sp
     3bc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     3c0:	d2946413 	mov	x19, #0xa320                	// #41760
     3c4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     3c8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     3cc:	f87f6a73 	ldr	x19, [x19, xzr]
     3d0:	cb3363f3 	sub	x19, sp, x19
     3d4:	d2800014 	mov	x20, #0x0                   	// #0
     3d8:	f2a00814 	movk	x20, #0x40, lsl #16
     3dc:	eb14027f 	cmp	x19, x20
     3e0:	54ffe30b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     3e4:	52800008 	mov	w8, #0x0                   	// #0
     3e8:	34000068 	cbz	w8, 3f4 <as-if-else+0x40>
     3ec:	52800008 	mov	w8, #0x0                   	// #0
     3f0:	1400000d 	b	424 <as-if-else+0x70>
     3f4:	52800008 	mov	w8, #0x0                   	// #0
     3f8:	d2947209 	mov	x9, #0xa390                	// #41872
     3fc:	f2a016c9 	movk	x9, #0xb6, lsl #16
     400:	f2c00aa9 	movk	x9, #0x55, lsl #32
     404:	f87f6929 	ldr	x9, [x9, xzr]
     408:	d2946600 	mov	x0, #0xa330                	// #41776
     40c:	f2a016c0 	movk	x0, #0xb6, lsl #16
     410:	f2c00aa0 	movk	x0, #0x55, lsl #32
     414:	f87f6800 	ldr	x0, [x0, xzr]
     418:	aa0803e1 	mov	x1, x8
     41c:	d63f0120 	blr	x9
     420:	aa0003e8 	mov	x8, x0
     424:	2a0803e0 	mov	w0, w8
     428:	a8c153f3 	ldp	x19, x20, [sp], #16
     42c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     430:	d65f03c0 	ret

0000000000000434 <func_8>:
     434:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     438:	910003fd 	mov	x29, sp
     43c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     440:	d2946413 	mov	x19, #0xa320                	// #41760
     444:	f2a016d3 	movk	x19, #0xb6, lsl #16
     448:	f2c00ab3 	movk	x19, #0x55, lsl #32
     44c:	f87f6a73 	ldr	x19, [x19, xzr]
     450:	cb3363f3 	sub	x19, sp, x19
     454:	d2800014 	mov	x20, #0x0                   	// #0
     458:	f2a00814 	movk	x20, #0x40, lsl #16
     45c:	eb14027f 	cmp	x19, x20
     460:	54ffdf0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     464:	d10043ff 	sub	sp, sp, #0x10
     468:	b90013e0 	str	w0, [sp, #16]
     46c:	b9000fe1 	str	w1, [sp, #12]
     470:	b9000be2 	str	w2, [sp, #8]
     474:	529fffe8 	mov	w8, #0xffff                	// #65535
     478:	72bfffe8 	movk	w8, #0xffff, lsl #16
     47c:	2a0803e0 	mov	w0, w8
     480:	910043ff 	add	sp, sp, #0x10
     484:	a8c153f3 	ldp	x19, x20, [sp], #16
     488:	a8c17bfd 	ldp	x29, x30, [sp], #16
     48c:	d65f03c0 	ret

0000000000000490 <as-call-first>:
     490:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     494:	910003fd 	mov	x29, sp
     498:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     49c:	d2946413 	mov	x19, #0xa320                	// #41760
     4a0:	f2a016d3 	movk	x19, #0xb6, lsl #16
     4a4:	f2c00ab3 	movk	x19, #0x55, lsl #32
     4a8:	f87f6a73 	ldr	x19, [x19, xzr]
     4ac:	cb3363f3 	sub	x19, sp, x19
     4b0:	d2800014 	mov	x20, #0x0                   	// #0
     4b4:	f2a00814 	movk	x20, #0x40, lsl #16
     4b8:	eb14027f 	cmp	x19, x20
     4bc:	54ffdc2b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     4c0:	52800008 	mov	w8, #0x0                   	// #0
     4c4:	d2947209 	mov	x9, #0xa390                	// #41872
     4c8:	f2a016c9 	movk	x9, #0xb6, lsl #16
     4cc:	f2c00aa9 	movk	x9, #0x55, lsl #32
     4d0:	f87f6929 	ldr	x9, [x9, xzr]
     4d4:	d2946600 	mov	x0, #0xa330                	// #41776
     4d8:	f2a016c0 	movk	x0, #0xb6, lsl #16
     4dc:	f2c00aa0 	movk	x0, #0x55, lsl #32
     4e0:	f87f6800 	ldr	x0, [x0, xzr]
     4e4:	aa0803e1 	mov	x1, x8
     4e8:	d63f0120 	blr	x9
     4ec:	aa0003e8 	mov	x8, x0
     4f0:	52800049 	mov	w9, #0x2                   	// #2
     4f4:	5280006a 	mov	w10, #0x3                   	// #3
     4f8:	2a0a03e2 	mov	w2, w10
     4fc:	2a0903e1 	mov	w1, w9
     500:	2a0803e0 	mov	w0, w8
     504:	d10103ff 	sub	sp, sp, #0x40
     508:	a90327e8 	stp	x8, x9, [sp, #48]
     50c:	a9022fea 	stp	x10, x11, [sp, #32]
     510:	a90137ec 	stp	x12, x13, [sp, #16]
     514:	a9003fee 	stp	x14, x15, [sp]
     518:	97ffffc7 	bl	434 <func_8>
     51c:	a94327e8 	ldp	x8, x9, [sp, #48]
     520:	a9422fea 	ldp	x10, x11, [sp, #32]
     524:	a94137ec 	ldp	x12, x13, [sp, #16]
     528:	a9403fee 	ldp	x14, x15, [sp]
     52c:	910103ff 	add	sp, sp, #0x40
     530:	aa0003e8 	mov	x8, x0
     534:	2a0803e0 	mov	w0, w8
     538:	a8c153f3 	ldp	x19, x20, [sp], #16
     53c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     540:	d65f03c0 	ret

0000000000000544 <as-call-mid>:
     544:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     548:	910003fd 	mov	x29, sp
     54c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     550:	d2946413 	mov	x19, #0xa320                	// #41760
     554:	f2a016d3 	movk	x19, #0xb6, lsl #16
     558:	f2c00ab3 	movk	x19, #0x55, lsl #32
     55c:	f87f6a73 	ldr	x19, [x19, xzr]
     560:	cb3363f3 	sub	x19, sp, x19
     564:	d2800014 	mov	x20, #0x0                   	// #0
     568:	f2a00814 	movk	x20, #0x40, lsl #16
     56c:	eb14027f 	cmp	x19, x20
     570:	54ffd68b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     574:	52800028 	mov	w8, #0x1                   	// #1
     578:	52800009 	mov	w9, #0x0                   	// #0
     57c:	d294720a 	mov	x10, #0xa390                	// #41872
     580:	f2a016ca 	movk	x10, #0xb6, lsl #16
     584:	f2c00aaa 	movk	x10, #0x55, lsl #32
     588:	f87f694a 	ldr	x10, [x10, xzr]
     58c:	d2946600 	mov	x0, #0xa330                	// #41776
     590:	f2a016c0 	movk	x0, #0xb6, lsl #16
     594:	f2c00aa0 	movk	x0, #0x55, lsl #32
     598:	f87f6800 	ldr	x0, [x0, xzr]
     59c:	aa0903e1 	mov	x1, x9
     5a0:	d63f0140 	blr	x10
     5a4:	aa0003e9 	mov	x9, x0
     5a8:	5280006a 	mov	w10, #0x3                   	// #3
     5ac:	2a0a03e2 	mov	w2, w10
     5b0:	2a0903e1 	mov	w1, w9
     5b4:	2a0803e0 	mov	w0, w8
     5b8:	d10103ff 	sub	sp, sp, #0x40
     5bc:	a90327e8 	stp	x8, x9, [sp, #48]
     5c0:	a9022fea 	stp	x10, x11, [sp, #32]
     5c4:	a90137ec 	stp	x12, x13, [sp, #16]
     5c8:	a9003fee 	stp	x14, x15, [sp]
     5cc:	97ffff9a 	bl	434 <func_8>
     5d0:	a94327e8 	ldp	x8, x9, [sp, #48]
     5d4:	a9422fea 	ldp	x10, x11, [sp, #32]
     5d8:	a94137ec 	ldp	x12, x13, [sp, #16]
     5dc:	a9403fee 	ldp	x14, x15, [sp]
     5e0:	910103ff 	add	sp, sp, #0x40
     5e4:	aa0003e8 	mov	x8, x0
     5e8:	2a0803e0 	mov	w0, w8
     5ec:	a8c153f3 	ldp	x19, x20, [sp], #16
     5f0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     5f4:	d65f03c0 	ret

00000000000005f8 <as-call-last>:
     5f8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     5fc:	910003fd 	mov	x29, sp
     600:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     604:	d2946413 	mov	x19, #0xa320                	// #41760
     608:	f2a016d3 	movk	x19, #0xb6, lsl #16
     60c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     610:	f87f6a73 	ldr	x19, [x19, xzr]
     614:	cb3363f3 	sub	x19, sp, x19
     618:	d2800014 	mov	x20, #0x0                   	// #0
     61c:	f2a00814 	movk	x20, #0x40, lsl #16
     620:	eb14027f 	cmp	x19, x20
     624:	54ffd0eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     628:	52800028 	mov	w8, #0x1                   	// #1
     62c:	52800049 	mov	w9, #0x2                   	// #2
     630:	5280000a 	mov	w10, #0x0                   	// #0
     634:	d294720b 	mov	x11, #0xa390                	// #41872
     638:	f2a016cb 	movk	x11, #0xb6, lsl #16
     63c:	f2c00aab 	movk	x11, #0x55, lsl #32
     640:	f87f696b 	ldr	x11, [x11, xzr]
     644:	d2946600 	mov	x0, #0xa330                	// #41776
     648:	f2a016c0 	movk	x0, #0xb6, lsl #16
     64c:	f2c00aa0 	movk	x0, #0x55, lsl #32
     650:	f87f6800 	ldr	x0, [x0, xzr]
     654:	aa0a03e1 	mov	x1, x10
     658:	d63f0160 	blr	x11
     65c:	aa0003ea 	mov	x10, x0
     660:	2a0a03e2 	mov	w2, w10
     664:	2a0903e1 	mov	w1, w9
     668:	2a0803e0 	mov	w0, w8
     66c:	d10103ff 	sub	sp, sp, #0x40
     670:	a90327e8 	stp	x8, x9, [sp, #48]
     674:	a9022fea 	stp	x10, x11, [sp, #32]
     678:	a90137ec 	stp	x12, x13, [sp, #16]
     67c:	a9003fee 	stp	x14, x15, [sp]
     680:	97ffff6d 	bl	434 <func_8>
     684:	a94327e8 	ldp	x8, x9, [sp, #48]
     688:	a9422fea 	ldp	x10, x11, [sp, #32]
     68c:	a94137ec 	ldp	x12, x13, [sp, #16]
     690:	a9403fee 	ldp	x14, x15, [sp]
     694:	910103ff 	add	sp, sp, #0x40
     698:	aa0003e8 	mov	x8, x0
     69c:	2a0803e0 	mov	w0, w8
     6a0:	a8c153f3 	ldp	x19, x20, [sp], #16
     6a4:	a8c17bfd 	ldp	x29, x30, [sp], #16
     6a8:	d65f03c0 	ret

00000000000006ac <as-call_indirect-first>:
     6ac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     6b0:	910003fd 	mov	x29, sp
     6b4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     6b8:	d2946413 	mov	x19, #0xa320                	// #41760
     6bc:	f2a016d3 	movk	x19, #0xb6, lsl #16
     6c0:	f2c00ab3 	movk	x19, #0x55, lsl #32
     6c4:	f87f6a73 	ldr	x19, [x19, xzr]
     6c8:	cb3363f3 	sub	x19, sp, x19
     6cc:	d2800014 	mov	x20, #0x0                   	// #0
     6d0:	f2a00814 	movk	x20, #0x40, lsl #16
     6d4:	eb14027f 	cmp	x19, x20
     6d8:	54ffcb4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     6dc:	52800008 	mov	w8, #0x0                   	// #0
     6e0:	d2947209 	mov	x9, #0xa390                	// #41872
     6e4:	f2a016c9 	movk	x9, #0xb6, lsl #16
     6e8:	f2c00aa9 	movk	x9, #0x55, lsl #32
     6ec:	f87f6929 	ldr	x9, [x9, xzr]
     6f0:	d2946600 	mov	x0, #0xa330                	// #41776
     6f4:	f2a016c0 	movk	x0, #0xb6, lsl #16
     6f8:	f2c00aa0 	movk	x0, #0x55, lsl #32
     6fc:	f87f6800 	ldr	x0, [x0, xzr]
     700:	aa0803e1 	mov	x1, x8
     704:	d63f0120 	blr	x9
     708:	aa0003e8 	mov	x8, x0
     70c:	52800049 	mov	w9, #0x2                   	// #2
     710:	5280006a 	mov	w10, #0x3                   	// #3
     714:	5280000b 	mov	w11, #0x0                   	// #0
     718:	f100057f 	cmp	x11, #0x1
     71c:	54ffc82a 	b.ge	20 <trap_handler+0x20>  // b.tcont
     720:	9000000c 	adrp	x12, 0 <trap_handler>
     724:	9101718c 	add	x12, x12, #0x5c
     728:	f86b798c 	ldr	x12, [x12, x11, lsl #3]
     72c:	b100059f 	cmn	x12, #0x1
     730:	54ffc7c0 	b.eq	28 <trap_handler+0x28>  // b.none
     734:	d360fd8d 	lsr	x13, x12, #32
     738:	710001bf 	cmp	w13, #0x0
     73c:	54ffc7a1 	b.ne	30 <trap_handler+0x30>  // b.any
     740:	d294600b 	mov	x11, #0xa300                	// #41728
     744:	f2a016cb 	movk	x11, #0xb6, lsl #16
     748:	f2c00aab 	movk	x11, #0x55, lsl #32
     74c:	f87f696b 	ldr	x11, [x11, xzr]
     750:	2a0c03ec 	mov	w12, w12
     754:	8b0c016c 	add	x12, x11, x12
     758:	2a0a03e2 	mov	w2, w10
     75c:	2a0903e1 	mov	w1, w9
     760:	2a0803e0 	mov	w0, w8
     764:	d63f0180 	blr	x12
     768:	aa0003e8 	mov	x8, x0
     76c:	2a0803e0 	mov	w0, w8
     770:	a8c153f3 	ldp	x19, x20, [sp], #16
     774:	a8c17bfd 	ldp	x29, x30, [sp], #16
     778:	d65f03c0 	ret

000000000000077c <as-call_indirect-mid>:
     77c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     780:	910003fd 	mov	x29, sp
     784:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     788:	d2946413 	mov	x19, #0xa320                	// #41760
     78c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     790:	f2c00ab3 	movk	x19, #0x55, lsl #32
     794:	f87f6a73 	ldr	x19, [x19, xzr]
     798:	cb3363f3 	sub	x19, sp, x19
     79c:	d2800014 	mov	x20, #0x0                   	// #0
     7a0:	f2a00814 	movk	x20, #0x40, lsl #16
     7a4:	eb14027f 	cmp	x19, x20
     7a8:	54ffc4cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     7ac:	52800028 	mov	w8, #0x1                   	// #1
     7b0:	52800009 	mov	w9, #0x0                   	// #0
     7b4:	d294720a 	mov	x10, #0xa390                	// #41872
     7b8:	f2a016ca 	movk	x10, #0xb6, lsl #16
     7bc:	f2c00aaa 	movk	x10, #0x55, lsl #32
     7c0:	f87f694a 	ldr	x10, [x10, xzr]
     7c4:	d2946600 	mov	x0, #0xa330                	// #41776
     7c8:	f2a016c0 	movk	x0, #0xb6, lsl #16
     7cc:	f2c00aa0 	movk	x0, #0x55, lsl #32
     7d0:	f87f6800 	ldr	x0, [x0, xzr]
     7d4:	aa0903e1 	mov	x1, x9
     7d8:	d63f0140 	blr	x10
     7dc:	aa0003e9 	mov	x9, x0
     7e0:	5280006a 	mov	w10, #0x3                   	// #3
     7e4:	5280000b 	mov	w11, #0x0                   	// #0
     7e8:	f100057f 	cmp	x11, #0x1
     7ec:	54ffc1aa 	b.ge	20 <trap_handler+0x20>  // b.tcont
     7f0:	9000000c 	adrp	x12, 0 <trap_handler>
     7f4:	9101718c 	add	x12, x12, #0x5c
     7f8:	f86b798c 	ldr	x12, [x12, x11, lsl #3]
     7fc:	b100059f 	cmn	x12, #0x1
     800:	54ffc140 	b.eq	28 <trap_handler+0x28>  // b.none
     804:	d360fd8d 	lsr	x13, x12, #32
     808:	710001bf 	cmp	w13, #0x0
     80c:	54ffc121 	b.ne	30 <trap_handler+0x30>  // b.any
     810:	d294600b 	mov	x11, #0xa300                	// #41728
     814:	f2a016cb 	movk	x11, #0xb6, lsl #16
     818:	f2c00aab 	movk	x11, #0x55, lsl #32
     81c:	f87f696b 	ldr	x11, [x11, xzr]
     820:	2a0c03ec 	mov	w12, w12
     824:	8b0c016c 	add	x12, x11, x12
     828:	2a0a03e2 	mov	w2, w10
     82c:	2a0903e1 	mov	w1, w9
     830:	2a0803e0 	mov	w0, w8
     834:	d63f0180 	blr	x12
     838:	aa0003e8 	mov	x8, x0
     83c:	2a0803e0 	mov	w0, w8
     840:	a8c153f3 	ldp	x19, x20, [sp], #16
     844:	a8c17bfd 	ldp	x29, x30, [sp], #16
     848:	d65f03c0 	ret

000000000000084c <as-call_indirect-last>:
     84c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     850:	910003fd 	mov	x29, sp
     854:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     858:	d2946413 	mov	x19, #0xa320                	// #41760
     85c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     860:	f2c00ab3 	movk	x19, #0x55, lsl #32
     864:	f87f6a73 	ldr	x19, [x19, xzr]
     868:	cb3363f3 	sub	x19, sp, x19
     86c:	d2800014 	mov	x20, #0x0                   	// #0
     870:	f2a00814 	movk	x20, #0x40, lsl #16
     874:	eb14027f 	cmp	x19, x20
     878:	54ffbe4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     87c:	52800028 	mov	w8, #0x1                   	// #1
     880:	52800049 	mov	w9, #0x2                   	// #2
     884:	5280000a 	mov	w10, #0x0                   	// #0
     888:	d294720b 	mov	x11, #0xa390                	// #41872
     88c:	f2a016cb 	movk	x11, #0xb6, lsl #16
     890:	f2c00aab 	movk	x11, #0x55, lsl #32
     894:	f87f696b 	ldr	x11, [x11, xzr]
     898:	d2946600 	mov	x0, #0xa330                	// #41776
     89c:	f2a016c0 	movk	x0, #0xb6, lsl #16
     8a0:	f2c00aa0 	movk	x0, #0x55, lsl #32
     8a4:	f87f6800 	ldr	x0, [x0, xzr]
     8a8:	aa0a03e1 	mov	x1, x10
     8ac:	d63f0160 	blr	x11
     8b0:	aa0003ea 	mov	x10, x0
     8b4:	5280000b 	mov	w11, #0x0                   	// #0
     8b8:	f100057f 	cmp	x11, #0x1
     8bc:	54ffbb2a 	b.ge	20 <trap_handler+0x20>  // b.tcont
     8c0:	9000000c 	adrp	x12, 0 <trap_handler>
     8c4:	9101718c 	add	x12, x12, #0x5c
     8c8:	f86b798c 	ldr	x12, [x12, x11, lsl #3]
     8cc:	b100059f 	cmn	x12, #0x1
     8d0:	54ffbac0 	b.eq	28 <trap_handler+0x28>  // b.none
     8d4:	d360fd8d 	lsr	x13, x12, #32
     8d8:	710001bf 	cmp	w13, #0x0
     8dc:	54ffbaa1 	b.ne	30 <trap_handler+0x30>  // b.any
     8e0:	d294600b 	mov	x11, #0xa300                	// #41728
     8e4:	f2a016cb 	movk	x11, #0xb6, lsl #16
     8e8:	f2c00aab 	movk	x11, #0x55, lsl #32
     8ec:	f87f696b 	ldr	x11, [x11, xzr]
     8f0:	2a0c03ec 	mov	w12, w12
     8f4:	8b0c016c 	add	x12, x11, x12
     8f8:	2a0a03e2 	mov	w2, w10
     8fc:	2a0903e1 	mov	w1, w9
     900:	2a0803e0 	mov	w0, w8
     904:	d63f0180 	blr	x12
     908:	aa0003e8 	mov	x8, x0
     90c:	2a0803e0 	mov	w0, w8
     910:	a8c153f3 	ldp	x19, x20, [sp], #16
     914:	a8c17bfd 	ldp	x29, x30, [sp], #16
     918:	d65f03c0 	ret

000000000000091c <as-call_indirect-index>:
     91c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     920:	910003fd 	mov	x29, sp
     924:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     928:	d2946413 	mov	x19, #0xa320                	// #41760
     92c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     930:	f2c00ab3 	movk	x19, #0x55, lsl #32
     934:	f87f6a73 	ldr	x19, [x19, xzr]
     938:	cb3363f3 	sub	x19, sp, x19
     93c:	d2800014 	mov	x20, #0x0                   	// #0
     940:	f2a00814 	movk	x20, #0x40, lsl #16
     944:	eb14027f 	cmp	x19, x20
     948:	54ffb7cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     94c:	52800028 	mov	w8, #0x1                   	// #1
     950:	52800049 	mov	w9, #0x2                   	// #2
     954:	5280006a 	mov	w10, #0x3                   	// #3
     958:	5280000b 	mov	w11, #0x0                   	// #0
     95c:	d294720c 	mov	x12, #0xa390                	// #41872
     960:	f2a016cc 	movk	x12, #0xb6, lsl #16
     964:	f2c00aac 	movk	x12, #0x55, lsl #32
     968:	f87f698c 	ldr	x12, [x12, xzr]
     96c:	d2946600 	mov	x0, #0xa330                	// #41776
     970:	f2a016c0 	movk	x0, #0xb6, lsl #16
     974:	f2c00aa0 	movk	x0, #0x55, lsl #32
     978:	f87f6800 	ldr	x0, [x0, xzr]
     97c:	aa0b03e1 	mov	x1, x11
     980:	d63f0180 	blr	x12
     984:	aa0003eb 	mov	x11, x0
     988:	f100057f 	cmp	x11, #0x1
     98c:	54ffb4aa 	b.ge	20 <trap_handler+0x20>  // b.tcont
     990:	9000000c 	adrp	x12, 0 <trap_handler>
     994:	9101718c 	add	x12, x12, #0x5c
     998:	f86b798c 	ldr	x12, [x12, x11, lsl #3]
     99c:	b100059f 	cmn	x12, #0x1
     9a0:	54ffb440 	b.eq	28 <trap_handler+0x28>  // b.none
     9a4:	d360fd8d 	lsr	x13, x12, #32
     9a8:	710001bf 	cmp	w13, #0x0
     9ac:	54ffb421 	b.ne	30 <trap_handler+0x30>  // b.any
     9b0:	d294600b 	mov	x11, #0xa300                	// #41728
     9b4:	f2a016cb 	movk	x11, #0xb6, lsl #16
     9b8:	f2c00aab 	movk	x11, #0x55, lsl #32
     9bc:	f87f696b 	ldr	x11, [x11, xzr]
     9c0:	2a0c03ec 	mov	w12, w12
     9c4:	8b0c016c 	add	x12, x11, x12
     9c8:	2a0a03e2 	mov	w2, w10
     9cc:	2a0903e1 	mov	w1, w9
     9d0:	2a0803e0 	mov	w0, w8
     9d4:	d63f0180 	blr	x12
     9d8:	aa0003e8 	mov	x8, x0
     9dc:	2a0803e0 	mov	w0, w8
     9e0:	a8c153f3 	ldp	x19, x20, [sp], #16
     9e4:	a8c17bfd 	ldp	x29, x30, [sp], #16
     9e8:	d65f03c0 	ret

00000000000009ec <as-local.set-value>:
     9ec:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     9f0:	910003fd 	mov	x29, sp
     9f4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     9f8:	d2946413 	mov	x19, #0xa320                	// #41760
     9fc:	f2a016d3 	movk	x19, #0xb6, lsl #16
     a00:	f2c00ab3 	movk	x19, #0x55, lsl #32
     a04:	f87f6a73 	ldr	x19, [x19, xzr]
     a08:	cb3363f3 	sub	x19, sp, x19
     a0c:	d2800014 	mov	x20, #0x0                   	// #0
     a10:	f2a00814 	movk	x20, #0x40, lsl #16
     a14:	eb14027f 	cmp	x19, x20
     a18:	54ffb14b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     a1c:	d10043ff 	sub	sp, sp, #0x10
     a20:	b90013ff 	str	wzr, [sp, #16]
     a24:	52800008 	mov	w8, #0x0                   	// #0
     a28:	d2947209 	mov	x9, #0xa390                	// #41872
     a2c:	f2a016c9 	movk	x9, #0xb6, lsl #16
     a30:	f2c00aa9 	movk	x9, #0x55, lsl #32
     a34:	f87f6929 	ldr	x9, [x9, xzr]
     a38:	d2946600 	mov	x0, #0xa330                	// #41776
     a3c:	f2a016c0 	movk	x0, #0xb6, lsl #16
     a40:	f2c00aa0 	movk	x0, #0x55, lsl #32
     a44:	f87f6800 	ldr	x0, [x0, xzr]
     a48:	aa0803e1 	mov	x1, x8
     a4c:	d63f0120 	blr	x9
     a50:	aa0003e8 	mov	x8, x0
     a54:	b90013e8 	str	w8, [sp, #16]
     a58:	910043ff 	add	sp, sp, #0x10
     a5c:	a8c153f3 	ldp	x19, x20, [sp], #16
     a60:	a8c17bfd 	ldp	x29, x30, [sp], #16
     a64:	d65f03c0 	ret

0000000000000a68 <as-local.tee-value>:
     a68:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     a6c:	910003fd 	mov	x29, sp
     a70:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     a74:	d2946413 	mov	x19, #0xa320                	// #41760
     a78:	f2a016d3 	movk	x19, #0xb6, lsl #16
     a7c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     a80:	f87f6a73 	ldr	x19, [x19, xzr]
     a84:	cb3363f3 	sub	x19, sp, x19
     a88:	d2800014 	mov	x20, #0x0                   	// #0
     a8c:	f2a00814 	movk	x20, #0x40, lsl #16
     a90:	eb14027f 	cmp	x19, x20
     a94:	54ffad6b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     a98:	d10043ff 	sub	sp, sp, #0x10
     a9c:	b90013ff 	str	wzr, [sp, #16]
     aa0:	52800008 	mov	w8, #0x0                   	// #0
     aa4:	d2947209 	mov	x9, #0xa390                	// #41872
     aa8:	f2a016c9 	movk	x9, #0xb6, lsl #16
     aac:	f2c00aa9 	movk	x9, #0x55, lsl #32
     ab0:	f87f6929 	ldr	x9, [x9, xzr]
     ab4:	d2946600 	mov	x0, #0xa330                	// #41776
     ab8:	f2a016c0 	movk	x0, #0xb6, lsl #16
     abc:	f2c00aa0 	movk	x0, #0x55, lsl #32
     ac0:	f87f6800 	ldr	x0, [x0, xzr]
     ac4:	aa0803e1 	mov	x1, x8
     ac8:	d63f0120 	blr	x9
     acc:	aa0003e8 	mov	x8, x0
     ad0:	b90013e8 	str	w8, [sp, #16]
     ad4:	2a0803e0 	mov	w0, w8
     ad8:	910043ff 	add	sp, sp, #0x10
     adc:	a8c153f3 	ldp	x19, x20, [sp], #16
     ae0:	a8c17bfd 	ldp	x29, x30, [sp], #16
     ae4:	d65f03c0 	ret

0000000000000ae8 <as-global.set-value>:
     ae8:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     aec:	910003fd 	mov	x29, sp
     af0:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     af4:	d2946413 	mov	x19, #0xa320                	// #41760
     af8:	f2a016d3 	movk	x19, #0xb6, lsl #16
     afc:	f2c00ab3 	movk	x19, #0x55, lsl #32
     b00:	f87f6a73 	ldr	x19, [x19, xzr]
     b04:	cb3363f3 	sub	x19, sp, x19
     b08:	d2800014 	mov	x20, #0x0                   	// #0
     b0c:	f2a00814 	movk	x20, #0x40, lsl #16
     b10:	eb14027f 	cmp	x19, x20
     b14:	54ffa96b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     b18:	d10043ff 	sub	sp, sp, #0x10
     b1c:	b90013ff 	str	wzr, [sp, #16]
     b20:	52800008 	mov	w8, #0x0                   	// #0
     b24:	d2947209 	mov	x9, #0xa390                	// #41872
     b28:	f2a016c9 	movk	x9, #0xb6, lsl #16
     b2c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     b30:	f87f6929 	ldr	x9, [x9, xzr]
     b34:	d2946600 	mov	x0, #0xa330                	// #41776
     b38:	f2a016c0 	movk	x0, #0xb6, lsl #16
     b3c:	f2c00aa0 	movk	x0, #0x55, lsl #32
     b40:	f87f6800 	ldr	x0, [x0, xzr]
     b44:	aa0803e1 	mov	x1, x8
     b48:	d63f0120 	blr	x9
     b4c:	aa0003e8 	mov	x8, x0
     b50:	d2946209 	mov	x9, #0xa310                	// #41744
     b54:	f2a016c9 	movk	x9, #0xb6, lsl #16
     b58:	f2c00aa9 	movk	x9, #0x55, lsl #32
     b5c:	f87f6929 	ldr	x9, [x9, xzr]
     b60:	91000129 	add	x9, x9, #0x0
     b64:	f83f6928 	str	x8, [x9, xzr]
     b68:	910043ff 	add	sp, sp, #0x10
     b6c:	a8c153f3 	ldp	x19, x20, [sp], #16
     b70:	a8c17bfd 	ldp	x29, x30, [sp], #16
     b74:	d65f03c0 	ret

0000000000000b78 <as-load-address>:
     b78:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     b7c:	910003fd 	mov	x29, sp
     b80:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     b84:	d2946413 	mov	x19, #0xa320                	// #41760
     b88:	f2a016d3 	movk	x19, #0xb6, lsl #16
     b8c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     b90:	f87f6a73 	ldr	x19, [x19, xzr]
     b94:	cb3363f3 	sub	x19, sp, x19
     b98:	d2800014 	mov	x20, #0x0                   	// #0
     b9c:	f2a00814 	movk	x20, #0x40, lsl #16
     ba0:	eb14027f 	cmp	x19, x20
     ba4:	54ffa4eb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     ba8:	52800008 	mov	w8, #0x0                   	// #0
     bac:	d2947209 	mov	x9, #0xa390                	// #41872
     bb0:	f2a016c9 	movk	x9, #0xb6, lsl #16
     bb4:	f2c00aa9 	movk	x9, #0x55, lsl #32
     bb8:	f87f6929 	ldr	x9, [x9, xzr]
     bbc:	d2946600 	mov	x0, #0xa330                	// #41776
     bc0:	f2a016c0 	movk	x0, #0xb6, lsl #16
     bc4:	f2c00aa0 	movk	x0, #0x55, lsl #32
     bc8:	f87f6800 	ldr	x0, [x0, xzr]
     bcc:	aa0803e1 	mov	x1, x8
     bd0:	d63f0120 	blr	x9
     bd4:	aa0003e8 	mov	x8, x0
     bd8:	d2946c09 	mov	x9, #0xa360                	// #41824
     bdc:	f2a016c9 	movk	x9, #0xb6, lsl #16
     be0:	f2c00aa9 	movk	x9, #0x55, lsl #32
     be4:	f87f6929 	ldr	x9, [x9, xzr]
     be8:	b4ffa289 	cbz	x9, 38 <trap_handler+0x38>
     bec:	d294700a 	mov	x10, #0xa380                	// #41856
     bf0:	f2a016ca 	movk	x10, #0xb6, lsl #16
     bf4:	f2c00aaa 	movk	x10, #0x55, lsl #32
     bf8:	b87f694a 	ldr	w10, [x10, xzr]
     bfc:	5100114a 	sub	w10, w10, #0x4
     c00:	6b0a011f 	cmp	w8, w10
     c04:	54ffa1a8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     c08:	b8a86929 	ldrsw	x9, [x9, x8]
     c0c:	2a0903e0 	mov	w0, w9
     c10:	a8c153f3 	ldp	x19, x20, [sp], #16
     c14:	a8c17bfd 	ldp	x29, x30, [sp], #16
     c18:	d65f03c0 	ret

0000000000000c1c <as-loadN-address>:
     c1c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     c20:	910003fd 	mov	x29, sp
     c24:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     c28:	d2946413 	mov	x19, #0xa320                	// #41760
     c2c:	f2a016d3 	movk	x19, #0xb6, lsl #16
     c30:	f2c00ab3 	movk	x19, #0x55, lsl #32
     c34:	f87f6a73 	ldr	x19, [x19, xzr]
     c38:	cb3363f3 	sub	x19, sp, x19
     c3c:	d2800014 	mov	x20, #0x0                   	// #0
     c40:	f2a00814 	movk	x20, #0x40, lsl #16
     c44:	eb14027f 	cmp	x19, x20
     c48:	54ff9fcb 	b.lt	40 <trap_handler+0x40>  // b.tstop
     c4c:	52800008 	mov	w8, #0x0                   	// #0
     c50:	d2947209 	mov	x9, #0xa390                	// #41872
     c54:	f2a016c9 	movk	x9, #0xb6, lsl #16
     c58:	f2c00aa9 	movk	x9, #0x55, lsl #32
     c5c:	f87f6929 	ldr	x9, [x9, xzr]
     c60:	d2946600 	mov	x0, #0xa330                	// #41776
     c64:	f2a016c0 	movk	x0, #0xb6, lsl #16
     c68:	f2c00aa0 	movk	x0, #0x55, lsl #32
     c6c:	f87f6800 	ldr	x0, [x0, xzr]
     c70:	aa0803e1 	mov	x1, x8
     c74:	d63f0120 	blr	x9
     c78:	aa0003e8 	mov	x8, x0
     c7c:	d2946c09 	mov	x9, #0xa360                	// #41824
     c80:	f2a016c9 	movk	x9, #0xb6, lsl #16
     c84:	f2c00aa9 	movk	x9, #0x55, lsl #32
     c88:	f87f6929 	ldr	x9, [x9, xzr]
     c8c:	34ff9d69 	cbz	w9, 38 <trap_handler+0x38>
     c90:	d294700a 	mov	x10, #0xa380                	// #41856
     c94:	f2a016ca 	movk	x10, #0xb6, lsl #16
     c98:	f2c00aaa 	movk	x10, #0x55, lsl #32
     c9c:	b87f694a 	ldr	w10, [x10, xzr]
     ca0:	5100054a 	sub	w10, w10, #0x1
     ca4:	6b0a011f 	cmp	w8, w10
     ca8:	54ff9c88 	b.hi	38 <trap_handler+0x38>  // b.pmore
     cac:	38e87929 	ldrsb	w9, [x9, x8, lsl #0]
     cb0:	2a0903e0 	mov	w0, w9
     cb4:	a8c153f3 	ldp	x19, x20, [sp], #16
     cb8:	a8c17bfd 	ldp	x29, x30, [sp], #16
     cbc:	d65f03c0 	ret

0000000000000cc0 <as-store-address>:
     cc0:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     cc4:	910003fd 	mov	x29, sp
     cc8:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     ccc:	d2946413 	mov	x19, #0xa320                	// #41760
     cd0:	f2a016d3 	movk	x19, #0xb6, lsl #16
     cd4:	f2c00ab3 	movk	x19, #0x55, lsl #32
     cd8:	f87f6a73 	ldr	x19, [x19, xzr]
     cdc:	cb3363f3 	sub	x19, sp, x19
     ce0:	d2800014 	mov	x20, #0x0                   	// #0
     ce4:	f2a00814 	movk	x20, #0x40, lsl #16
     ce8:	eb14027f 	cmp	x19, x20
     cec:	54ff9aab 	b.lt	40 <trap_handler+0x40>  // b.tstop
     cf0:	52800008 	mov	w8, #0x0                   	// #0
     cf4:	d2947209 	mov	x9, #0xa390                	// #41872
     cf8:	f2a016c9 	movk	x9, #0xb6, lsl #16
     cfc:	f2c00aa9 	movk	x9, #0x55, lsl #32
     d00:	f87f6929 	ldr	x9, [x9, xzr]
     d04:	d2946600 	mov	x0, #0xa330                	// #41776
     d08:	f2a016c0 	movk	x0, #0xb6, lsl #16
     d0c:	f2c00aa0 	movk	x0, #0x55, lsl #32
     d10:	f87f6800 	ldr	x0, [x0, xzr]
     d14:	aa0803e1 	mov	x1, x8
     d18:	d63f0120 	blr	x9
     d1c:	aa0003e8 	mov	x8, x0
     d20:	528000e9 	mov	w9, #0x7                   	// #7
     d24:	d2946c0a 	mov	x10, #0xa360                	// #41824
     d28:	f2a016ca 	movk	x10, #0xb6, lsl #16
     d2c:	f2c00aaa 	movk	x10, #0x55, lsl #32
     d30:	f87f694a 	ldr	x10, [x10, xzr]
     d34:	34ff982a 	cbz	w10, 38 <trap_handler+0x38>
     d38:	d294700b 	mov	x11, #0xa380                	// #41856
     d3c:	f2a016cb 	movk	x11, #0xb6, lsl #16
     d40:	f2c00aab 	movk	x11, #0x55, lsl #32
     d44:	b87f696b 	ldr	w11, [x11, xzr]
     d48:	5100116b 	sub	w11, w11, #0x4
     d4c:	6b0b011f 	cmp	w8, w11
     d50:	54ff9748 	b.hi	38 <trap_handler+0x38>  // b.pmore
     d54:	b8286949 	str	w9, [x10, x8]
     d58:	a8c153f3 	ldp	x19, x20, [sp], #16
     d5c:	a8c17bfd 	ldp	x29, x30, [sp], #16
     d60:	d65f03c0 	ret

0000000000000d64 <as-store-value>:
     d64:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     d68:	910003fd 	mov	x29, sp
     d6c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     d70:	d2946413 	mov	x19, #0xa320                	// #41760
     d74:	f2a016d3 	movk	x19, #0xb6, lsl #16
     d78:	f2c00ab3 	movk	x19, #0x55, lsl #32
     d7c:	f87f6a73 	ldr	x19, [x19, xzr]
     d80:	cb3363f3 	sub	x19, sp, x19
     d84:	d2800014 	mov	x20, #0x0                   	// #0
     d88:	f2a00814 	movk	x20, #0x40, lsl #16
     d8c:	eb14027f 	cmp	x19, x20
     d90:	54ff958b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     d94:	52800048 	mov	w8, #0x2                   	// #2
     d98:	52800009 	mov	w9, #0x0                   	// #0
     d9c:	d294720a 	mov	x10, #0xa390                	// #41872
     da0:	f2a016ca 	movk	x10, #0xb6, lsl #16
     da4:	f2c00aaa 	movk	x10, #0x55, lsl #32
     da8:	f87f694a 	ldr	x10, [x10, xzr]
     dac:	d2946600 	mov	x0, #0xa330                	// #41776
     db0:	f2a016c0 	movk	x0, #0xb6, lsl #16
     db4:	f2c00aa0 	movk	x0, #0x55, lsl #32
     db8:	f87f6800 	ldr	x0, [x0, xzr]
     dbc:	aa0903e1 	mov	x1, x9
     dc0:	d63f0140 	blr	x10
     dc4:	aa0003e9 	mov	x9, x0
     dc8:	d2946c0a 	mov	x10, #0xa360                	// #41824
     dcc:	f2a016ca 	movk	x10, #0xb6, lsl #16
     dd0:	f2c00aaa 	movk	x10, #0x55, lsl #32
     dd4:	f87f694a 	ldr	x10, [x10, xzr]
     dd8:	34ff930a 	cbz	w10, 38 <trap_handler+0x38>
     ddc:	d294700b 	mov	x11, #0xa380                	// #41856
     de0:	f2a016cb 	movk	x11, #0xb6, lsl #16
     de4:	f2c00aab 	movk	x11, #0x55, lsl #32
     de8:	b87f696b 	ldr	w11, [x11, xzr]
     dec:	5100116b 	sub	w11, w11, #0x4
     df0:	6b0b011f 	cmp	w8, w11
     df4:	54ff9228 	b.hi	38 <trap_handler+0x38>  // b.pmore
     df8:	b8286949 	str	w9, [x10, x8]
     dfc:	a8c153f3 	ldp	x19, x20, [sp], #16
     e00:	a8c17bfd 	ldp	x29, x30, [sp], #16
     e04:	d65f03c0 	ret

0000000000000e08 <as-storeN-address>:
     e08:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     e0c:	910003fd 	mov	x29, sp
     e10:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     e14:	d2946413 	mov	x19, #0xa320                	// #41760
     e18:	f2a016d3 	movk	x19, #0xb6, lsl #16
     e1c:	f2c00ab3 	movk	x19, #0x55, lsl #32
     e20:	f87f6a73 	ldr	x19, [x19, xzr]
     e24:	cb3363f3 	sub	x19, sp, x19
     e28:	d2800014 	mov	x20, #0x0                   	// #0
     e2c:	f2a00814 	movk	x20, #0x40, lsl #16
     e30:	eb14027f 	cmp	x19, x20
     e34:	54ff906b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     e38:	52800008 	mov	w8, #0x0                   	// #0
     e3c:	d2947209 	mov	x9, #0xa390                	// #41872
     e40:	f2a016c9 	movk	x9, #0xb6, lsl #16
     e44:	f2c00aa9 	movk	x9, #0x55, lsl #32
     e48:	f87f6929 	ldr	x9, [x9, xzr]
     e4c:	d2946600 	mov	x0, #0xa330                	// #41776
     e50:	f2a016c0 	movk	x0, #0xb6, lsl #16
     e54:	f2c00aa0 	movk	x0, #0x55, lsl #32
     e58:	f87f6800 	ldr	x0, [x0, xzr]
     e5c:	aa0803e1 	mov	x1, x8
     e60:	d63f0120 	blr	x9
     e64:	aa0003e8 	mov	x8, x0
     e68:	528000e9 	mov	w9, #0x7                   	// #7
     e6c:	d2946c0a 	mov	x10, #0xa360                	// #41824
     e70:	f2a016ca 	movk	x10, #0xb6, lsl #16
     e74:	f2c00aaa 	movk	x10, #0x55, lsl #32
     e78:	f87f694a 	ldr	x10, [x10, xzr]
     e7c:	34ff8dea 	cbz	w10, 38 <trap_handler+0x38>
     e80:	d294700b 	mov	x11, #0xa380                	// #41856
     e84:	f2a016cb 	movk	x11, #0xb6, lsl #16
     e88:	f2c00aab 	movk	x11, #0x55, lsl #32
     e8c:	b87f696b 	ldr	w11, [x11, xzr]
     e90:	5100056b 	sub	w11, w11, #0x1
     e94:	6b0b011f 	cmp	w8, w11
     e98:	54ff8d08 	b.hi	38 <trap_handler+0x38>  // b.pmore
     e9c:	38287949 	strb	w9, [x10, x8, lsl #0]
     ea0:	a8c153f3 	ldp	x19, x20, [sp], #16
     ea4:	a8c17bfd 	ldp	x29, x30, [sp], #16
     ea8:	d65f03c0 	ret

0000000000000eac <as-storeN-value>:
     eac:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     eb0:	910003fd 	mov	x29, sp
     eb4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     eb8:	d2946413 	mov	x19, #0xa320                	// #41760
     ebc:	f2a016d3 	movk	x19, #0xb6, lsl #16
     ec0:	f2c00ab3 	movk	x19, #0x55, lsl #32
     ec4:	f87f6a73 	ldr	x19, [x19, xzr]
     ec8:	cb3363f3 	sub	x19, sp, x19
     ecc:	d2800014 	mov	x20, #0x0                   	// #0
     ed0:	f2a00814 	movk	x20, #0x40, lsl #16
     ed4:	eb14027f 	cmp	x19, x20
     ed8:	54ff8b4b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     edc:	52800048 	mov	w8, #0x2                   	// #2
     ee0:	52800009 	mov	w9, #0x0                   	// #0
     ee4:	d294720a 	mov	x10, #0xa390                	// #41872
     ee8:	f2a016ca 	movk	x10, #0xb6, lsl #16
     eec:	f2c00aaa 	movk	x10, #0x55, lsl #32
     ef0:	f87f694a 	ldr	x10, [x10, xzr]
     ef4:	d2946600 	mov	x0, #0xa330                	// #41776
     ef8:	f2a016c0 	movk	x0, #0xb6, lsl #16
     efc:	f2c00aa0 	movk	x0, #0x55, lsl #32
     f00:	f87f6800 	ldr	x0, [x0, xzr]
     f04:	aa0903e1 	mov	x1, x9
     f08:	d63f0140 	blr	x10
     f0c:	aa0003e9 	mov	x9, x0
     f10:	d2946c0a 	mov	x10, #0xa360                	// #41824
     f14:	f2a016ca 	movk	x10, #0xb6, lsl #16
     f18:	f2c00aaa 	movk	x10, #0x55, lsl #32
     f1c:	f87f694a 	ldr	x10, [x10, xzr]
     f20:	34ff88ca 	cbz	w10, 38 <trap_handler+0x38>
     f24:	d294700b 	mov	x11, #0xa380                	// #41856
     f28:	f2a016cb 	movk	x11, #0xb6, lsl #16
     f2c:	f2c00aab 	movk	x11, #0x55, lsl #32
     f30:	b87f696b 	ldr	w11, [x11, xzr]
     f34:	5100096b 	sub	w11, w11, #0x2
     f38:	6b0b011f 	cmp	w8, w11
     f3c:	54ff87e8 	b.hi	38 <trap_handler+0x38>  // b.pmore
     f40:	78286949 	strh	w9, [x10, x8]
     f44:	a8c153f3 	ldp	x19, x20, [sp], #16
     f48:	a8c17bfd 	ldp	x29, x30, [sp], #16
     f4c:	d65f03c0 	ret

0000000000000f50 <as-unary-operand>:
     f50:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     f54:	910003fd 	mov	x29, sp
     f58:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     f5c:	d2946413 	mov	x19, #0xa320                	// #41760
     f60:	f2a016d3 	movk	x19, #0xb6, lsl #16
     f64:	f2c00ab3 	movk	x19, #0x55, lsl #32
     f68:	f87f6a73 	ldr	x19, [x19, xzr]
     f6c:	cb3363f3 	sub	x19, sp, x19
     f70:	d2800014 	mov	x20, #0x0                   	// #0
     f74:	f2a00814 	movk	x20, #0x40, lsl #16
     f78:	eb14027f 	cmp	x19, x20
     f7c:	54ff862b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     f80:	52800008 	mov	w8, #0x0                   	// #0
     f84:	d2947209 	mov	x9, #0xa390                	// #41872
     f88:	f2a016c9 	movk	x9, #0xb6, lsl #16
     f8c:	f2c00aa9 	movk	x9, #0x55, lsl #32
     f90:	f87f6929 	ldr	x9, [x9, xzr]
     f94:	d2946600 	mov	x0, #0xa330                	// #41776
     f98:	f2a016c0 	movk	x0, #0xb6, lsl #16
     f9c:	f2c00aa0 	movk	x0, #0x55, lsl #32
     fa0:	f87f6800 	ldr	x0, [x0, xzr]
     fa4:	aa0803e1 	mov	x1, x8
     fa8:	d63f0120 	blr	x9
     fac:	aa0003e8 	mov	x8, x0
     fb0:	5ac01108 	clz	w8, w8
     fb4:	2a0803e0 	mov	w0, w8
     fb8:	a8c153f3 	ldp	x19, x20, [sp], #16
     fbc:	a8c17bfd 	ldp	x29, x30, [sp], #16
     fc0:	d65f03c0 	ret

0000000000000fc4 <as-binary-left>:
     fc4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
     fc8:	910003fd 	mov	x29, sp
     fcc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
     fd0:	d2946413 	mov	x19, #0xa320                	// #41760
     fd4:	f2a016d3 	movk	x19, #0xb6, lsl #16
     fd8:	f2c00ab3 	movk	x19, #0x55, lsl #32
     fdc:	f87f6a73 	ldr	x19, [x19, xzr]
     fe0:	cb3363f3 	sub	x19, sp, x19
     fe4:	d2800014 	mov	x20, #0x0                   	// #0
     fe8:	f2a00814 	movk	x20, #0x40, lsl #16
     fec:	eb14027f 	cmp	x19, x20
     ff0:	54ff828b 	b.lt	40 <trap_handler+0x40>  // b.tstop
     ff4:	52800008 	mov	w8, #0x0                   	// #0
     ff8:	d2947209 	mov	x9, #0xa390                	// #41872
     ffc:	f2a016c9 	movk	x9, #0xb6, lsl #16
    1000:	f2c00aa9 	movk	x9, #0x55, lsl #32
    1004:	f87f6929 	ldr	x9, [x9, xzr]
    1008:	d2946600 	mov	x0, #0xa330                	// #41776
    100c:	f2a016c0 	movk	x0, #0xb6, lsl #16
    1010:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1014:	f87f6800 	ldr	x0, [x0, xzr]
    1018:	aa0803e1 	mov	x1, x8
    101c:	d63f0120 	blr	x9
    1020:	aa0003e8 	mov	x8, x0
    1024:	52800149 	mov	w9, #0xa                   	// #10
    1028:	0b090108 	add	w8, w8, w9
    102c:	2a0803e0 	mov	w0, w8
    1030:	a8c153f3 	ldp	x19, x20, [sp], #16
    1034:	a8c17bfd 	ldp	x29, x30, [sp], #16
    1038:	d65f03c0 	ret

000000000000103c <as-binary-right>:
    103c:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    1040:	910003fd 	mov	x29, sp
    1044:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    1048:	d2946413 	mov	x19, #0xa320                	// #41760
    104c:	f2a016d3 	movk	x19, #0xb6, lsl #16
    1050:	f2c00ab3 	movk	x19, #0x55, lsl #32
    1054:	f87f6a73 	ldr	x19, [x19, xzr]
    1058:	cb3363f3 	sub	x19, sp, x19
    105c:	d2800014 	mov	x20, #0x0                   	// #0
    1060:	f2a00814 	movk	x20, #0x40, lsl #16
    1064:	eb14027f 	cmp	x19, x20
    1068:	54ff7ecb 	b.lt	40 <trap_handler+0x40>  // b.tstop
    106c:	52800148 	mov	w8, #0xa                   	// #10
    1070:	52800009 	mov	w9, #0x0                   	// #0
    1074:	d294720a 	mov	x10, #0xa390                	// #41872
    1078:	f2a016ca 	movk	x10, #0xb6, lsl #16
    107c:	f2c00aaa 	movk	x10, #0x55, lsl #32
    1080:	f87f694a 	ldr	x10, [x10, xzr]
    1084:	d2946600 	mov	x0, #0xa330                	// #41776
    1088:	f2a016c0 	movk	x0, #0xb6, lsl #16
    108c:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1090:	f87f6800 	ldr	x0, [x0, xzr]
    1094:	aa0903e1 	mov	x1, x9
    1098:	d63f0140 	blr	x10
    109c:	aa0003e9 	mov	x9, x0
    10a0:	4b090108 	sub	w8, w8, w9
    10a4:	2a0803e0 	mov	w0, w8
    10a8:	a8c153f3 	ldp	x19, x20, [sp], #16
    10ac:	a8c17bfd 	ldp	x29, x30, [sp], #16
    10b0:	d65f03c0 	ret

00000000000010b4 <as-test-operand>:
    10b4:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    10b8:	910003fd 	mov	x29, sp
    10bc:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    10c0:	d2946413 	mov	x19, #0xa320                	// #41760
    10c4:	f2a016d3 	movk	x19, #0xb6, lsl #16
    10c8:	f2c00ab3 	movk	x19, #0x55, lsl #32
    10cc:	f87f6a73 	ldr	x19, [x19, xzr]
    10d0:	cb3363f3 	sub	x19, sp, x19
    10d4:	d2800014 	mov	x20, #0x0                   	// #0
    10d8:	f2a00814 	movk	x20, #0x40, lsl #16
    10dc:	eb14027f 	cmp	x19, x20
    10e0:	54ff7b0b 	b.lt	40 <trap_handler+0x40>  // b.tstop
    10e4:	52800008 	mov	w8, #0x0                   	// #0
    10e8:	d2947209 	mov	x9, #0xa390                	// #41872
    10ec:	f2a016c9 	movk	x9, #0xb6, lsl #16
    10f0:	f2c00aa9 	movk	x9, #0x55, lsl #32
    10f4:	f87f6929 	ldr	x9, [x9, xzr]
    10f8:	d2946600 	mov	x0, #0xa330                	// #41776
    10fc:	f2a016c0 	movk	x0, #0xb6, lsl #16
    1100:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1104:	f87f6800 	ldr	x0, [x0, xzr]
    1108:	aa0803e1 	mov	x1, x8
    110c:	d63f0120 	blr	x9
    1110:	aa0003e8 	mov	x8, x0
    1114:	34000068 	cbz	w8, 1120 <as-test-operand+0x6c>
    1118:	52800008 	mov	w8, #0x0                   	// #0
    111c:	14000002 	b	1124 <as-test-operand+0x70>
    1120:	52800028 	mov	w8, #0x1                   	// #1
    1124:	2a0803e0 	mov	w0, w8
    1128:	a8c153f3 	ldp	x19, x20, [sp], #16
    112c:	a8c17bfd 	ldp	x29, x30, [sp], #16
    1130:	d65f03c0 	ret

0000000000001134 <as-compare-left>:
    1134:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    1138:	910003fd 	mov	x29, sp
    113c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    1140:	d2946413 	mov	x19, #0xa320                	// #41760
    1144:	f2a016d3 	movk	x19, #0xb6, lsl #16
    1148:	f2c00ab3 	movk	x19, #0x55, lsl #32
    114c:	f87f6a73 	ldr	x19, [x19, xzr]
    1150:	cb3363f3 	sub	x19, sp, x19
    1154:	d2800014 	mov	x20, #0x0                   	// #0
    1158:	f2a00814 	movk	x20, #0x40, lsl #16
    115c:	eb14027f 	cmp	x19, x20
    1160:	54ff770b 	b.lt	40 <trap_handler+0x40>  // b.tstop
    1164:	52800008 	mov	w8, #0x0                   	// #0
    1168:	d2947209 	mov	x9, #0xa390                	// #41872
    116c:	f2a016c9 	movk	x9, #0xb6, lsl #16
    1170:	f2c00aa9 	movk	x9, #0x55, lsl #32
    1174:	f87f6929 	ldr	x9, [x9, xzr]
    1178:	d2946600 	mov	x0, #0xa330                	// #41776
    117c:	f2a016c0 	movk	x0, #0xb6, lsl #16
    1180:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1184:	f87f6800 	ldr	x0, [x0, xzr]
    1188:	aa0803e1 	mov	x1, x8
    118c:	d63f0120 	blr	x9
    1190:	aa0003e8 	mov	x8, x0
    1194:	52800149 	mov	w9, #0xa                   	// #10
    1198:	6b09011f 	cmp	w8, w9
    119c:	5400006d 	b.le	11a8 <as-compare-left+0x74>
    11a0:	52800008 	mov	w8, #0x0                   	// #0
    11a4:	14000002 	b	11ac <as-compare-left+0x78>
    11a8:	52800028 	mov	w8, #0x1                   	// #1
    11ac:	2a0803e0 	mov	w0, w8
    11b0:	a8c153f3 	ldp	x19, x20, [sp], #16
    11b4:	a8c17bfd 	ldp	x29, x30, [sp], #16
    11b8:	d65f03c0 	ret

00000000000011bc <as-compare-right>:
    11bc:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    11c0:	910003fd 	mov	x29, sp
    11c4:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    11c8:	d2946413 	mov	x19, #0xa320                	// #41760
    11cc:	f2a016d3 	movk	x19, #0xb6, lsl #16
    11d0:	f2c00ab3 	movk	x19, #0x55, lsl #32
    11d4:	f87f6a73 	ldr	x19, [x19, xzr]
    11d8:	cb3363f3 	sub	x19, sp, x19
    11dc:	d2800014 	mov	x20, #0x0                   	// #0
    11e0:	f2a00814 	movk	x20, #0x40, lsl #16
    11e4:	eb14027f 	cmp	x19, x20
    11e8:	54ff72cb 	b.lt	40 <trap_handler+0x40>  // b.tstop
    11ec:	52800148 	mov	w8, #0xa                   	// #10
    11f0:	52800009 	mov	w9, #0x0                   	// #0
    11f4:	d294720a 	mov	x10, #0xa390                	// #41872
    11f8:	f2a016ca 	movk	x10, #0xb6, lsl #16
    11fc:	f2c00aaa 	movk	x10, #0x55, lsl #32
    1200:	f87f694a 	ldr	x10, [x10, xzr]
    1204:	d2946600 	mov	x0, #0xa330                	// #41776
    1208:	f2a016c0 	movk	x0, #0xb6, lsl #16
    120c:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1210:	f87f6800 	ldr	x0, [x0, xzr]
    1214:	aa0903e1 	mov	x1, x9
    1218:	d63f0140 	blr	x10
    121c:	aa0003e9 	mov	x9, x0
    1220:	eb09011f 	cmp	x8, x9
    1224:	54000061 	b.ne	1230 <as-compare-right+0x74>  // b.any
    1228:	52800008 	mov	w8, #0x0                   	// #0
    122c:	14000002 	b	1234 <as-compare-right+0x78>
    1230:	52800028 	mov	w8, #0x1                   	// #1
    1234:	2a0803e0 	mov	w0, w8
    1238:	a8c153f3 	ldp	x19, x20, [sp], #16
    123c:	a8c17bfd 	ldp	x29, x30, [sp], #16
    1240:	d65f03c0 	ret

0000000000001244 <as-memory.grow-size>:
    1244:	a9bf7bfd 	stp	x29, x30, [sp, #-16]!
    1248:	910003fd 	mov	x29, sp
    124c:	a9bf53f3 	stp	x19, x20, [sp, #-16]!
    1250:	d2946413 	mov	x19, #0xa320                	// #41760
    1254:	f2a016d3 	movk	x19, #0xb6, lsl #16
    1258:	f2c00ab3 	movk	x19, #0x55, lsl #32
    125c:	f87f6a73 	ldr	x19, [x19, xzr]
    1260:	cb3363f3 	sub	x19, sp, x19
    1264:	d2800014 	mov	x20, #0x0                   	// #0
    1268:	f2a00814 	movk	x20, #0x40, lsl #16
    126c:	eb14027f 	cmp	x19, x20
    1270:	54ff6e8b 	b.lt	40 <trap_handler+0x40>  // b.tstop
    1274:	52800008 	mov	w8, #0x0                   	// #0
    1278:	d2947209 	mov	x9, #0xa390                	// #41872
    127c:	f2a016c9 	movk	x9, #0xb6, lsl #16
    1280:	f2c00aa9 	movk	x9, #0x55, lsl #32
    1284:	f87f6929 	ldr	x9, [x9, xzr]
    1288:	d2946600 	mov	x0, #0xa330                	// #41776
    128c:	f2a016c0 	movk	x0, #0xb6, lsl #16
    1290:	f2c00aa0 	movk	x0, #0x55, lsl #32
    1294:	f87f6800 	ldr	x0, [x0, xzr]
    1298:	aa0803e1 	mov	x1, x8
    129c:	d63f0120 	blr	x9
    12a0:	aa0003e8 	mov	x8, x0
    12a4:	d2947209 	mov	x9, #0xa390                	// #41872
    12a8:	f2a016c9 	movk	x9, #0xb6, lsl #16
    12ac:	f2c00aa9 	movk	x9, #0x55, lsl #32
    12b0:	f87f6929 	ldr	x9, [x9, xzr]
    12b4:	d2946600 	mov	x0, #0xa330                	// #41776
    12b8:	f2a016c0 	movk	x0, #0xb6, lsl #16
    12bc:	f2c00aa0 	movk	x0, #0x55, lsl #32
    12c0:	f87f6800 	ldr	x0, [x0, xzr]
    12c4:	aa0803e1 	mov	x1, x8
    12c8:	d63f0120 	blr	x9
    12cc:	aa0003e8 	mov	x8, x0
    12d0:	2a0803e0 	mov	w0, w8
    12d4:	a8c153f3 	ldp	x19, x20, [sp], #16
    12d8:	a8c17bfd 	ldp	x29, x30, [sp], #16
    12dc:	d65f03c0 	ret
