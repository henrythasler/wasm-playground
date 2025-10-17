[![build aarch64](https://github.com/henrythasler/wasm-playground/actions/workflows/build-aarch64.yml/badge.svg)](https://github.com/henrythasler/wasm-playground/actions/workflows/build-aarch64.yml)

# Tiny-Wasm

Following [Tiny Wasm Compiler Tutorial](https://github.com/Schleifner/Tiny-Wasm-Compiler-Learn) to build a compiler and runtime for WebAssembly modules.

Progress:

- Chapter00: ✅
- Chapter01: 95%
- Chapter02: 5%
- Chapter03: 0%
- Chapter04: 0%
- Chapter05: 0%
- Chapter06: 0%
- Chapter07: 0%
- Chapter08: 0%
- Chapter09: 0%
- Chapter10: 0%
- Chapter11: 0%
- Chapter12: 0%
- Chapter13: 0%

## Feature Highlights

- Uses Kaitai Struct to parse wasm-files
- gtest is fetched on demand by cmake (no local installation required)

## Prerequisites

### Install Dependencies

`sudo apt install g++-aarch64-linux-gnu clang-format clang-tidy wabt`

### Checkout Submodules

`git submodule update --init --recursive`

## Build Instructions

```
$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=cmake/aarch64-toolchain.cmake
$ cmake --build build --parallel
```

This will build the project in the `build` folder.

## Execution

### On x86 Machine using Qemu 

LeakSanitizer is incompatible with emulator/debugging/tracing tools. Setting `detect_leaks=0` disables leak detection during execution.

`ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ build/src/tiny-wasm wasm/nop-fn.wasm`

### On arm64 Machine

`./build/src/tiny-wasm wasm/nop-fn.wasm`

## Debug 

Start the executable:

`ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ -g 1234 ./tiny-wasm ../wasm/nop-fn.wasm`

Set breakpoint in source code. Start Debugging (F5).

## Code Quality Tools

### Visual Studio Code Integration

1. `Clang-Format` Extension

## Kaitai Struct

`kaitai-struct-compiler --target cpp_stl webassembly.ksy`

## References

### ARM64

- [Running Arm Binaries on x86 with QEMU-User](https://azeria-labs.com/arm-on-x86-qemu-user/)
- [ARM GCC Inline Assembler Cookbook](http://www.ethernut.de/en/documents/arm-inline-asm.html)
- [Mastering arm-linux-gnueabihf-gcc: A Comprehensive Guide ](https://linuxvox.com/blog/arm-linux-gnueabihf-gcc/)
- [ARMv8 AArch64/ARM64 Full Beginner's Assembly Tutorial](https://mariokartwii.com/armv8/)
- [Getting Started with Arm Assembly Language](https://developer.arm.com/documentation/107829/0201)
- [Procedure Call Standard for the Arm® 64-bit Architecture (AArch64) - Parameter passing](https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst#68parameter-passing)
- [arm64-book - A Book that explains in Detail ARM64 Assembly](https://github.com/maxvdec/arm64-book)

### ARM64 Online Tools

- [ARMConverter.com - Online ARM to HEX Converter](https://armconverter.com/?lock=arm64)
- [Online Assembler and Disassembler](https://shell-storm.org/online/Online-Assembler-and-Disassembler/)

### WebAssembly

- [WebAssembly 1.0 Core Specification](https://www.w3.org/TR/wasm-core-1/)
- [WebAssembly on developer.mozilla.org](https://developer.mozilla.org/en-US/docs/WebAssembly)
- [WebAssembly parser for Kaitai.io](https://github.com/evacchi/kaitai-webassembly)

### Programming

- [Linux System Calls](https://syscall.sh/)

### Build Pipeline

- [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/README.html)
- [Getting Started With CMake](https://earthly.dev/blog/using-cmake/)
- [Integrating Google Test Into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/)

### Compiler

- [godbolt - Compiler Explorer](https://godbolt.org/)
- [Compiler Design Tutorial](https://www.tutorialspoint.com/compiler_design/index.htm)