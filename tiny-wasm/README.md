# Tiny-Wasm

Following [Tiny Wasm Compiler Tutorial](https://github.com/Schleifner/Tiny-Wasm-Compiler-Learn).

## Prerequisites

`sudo apt install g++-aarch64-linux-gnu clang-format clang-tidy`

## Build Instructions

```
$ cd tiny-wasm
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --parallel
```

## Debug 

Start the executable:

`ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ -g 1234 ./tiny-wasm ../wasm/nop-fn.wasm`

> LeakSanitizer is incompatible with debugging/tracing tools. Setting `detect_leaks=0` disables leak detection while debugging.

Set breakpoint in source code. Start Debugging (F5).

## Code Quality Tools

### Visual Studio Code Integration

1. `Clang-Format` Extension

## Kaitai Struct

`kaitai-struct-compiler --target cpp_stl --outdir kaitai-struct webassembly.ksy`