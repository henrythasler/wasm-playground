# Tiny-Wasm

Following [Tiny Wasm Compiler Tutorial](https://github.com/Schleifner/Tiny-Wasm-Compiler-Learn).

## Prerequisites

`sudo apt install g++-aarch64-linux-gnu clang-format clang-tidy`

## Build Instructions

```
$ mkdir build && cd build
$ cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/aarch64-toolchain.cmake ..
$ cmake --build . --parallel
$ qemu-aarch64 -L /usr/aarch64-linux-gnu/ ./src/tiny-wasm ../wasm/nop-fn.wasm
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

### WebAssembly

- [WebAssembly parser for Kaitai.io](https://github.com/evacchi/kaitai-webassembly)

### Programming

- [Linux System Calls](https://syscall.sh/)

### Build Pipeline

- [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/README.html)
- [Getting Started With CMake](https://earthly.dev/blog/using-cmake/)