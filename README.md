[![build aarch64](https://github.com/henrythasler/wasm-playground/actions/workflows/build-aarch64.yml/badge.svg)](https://github.com/henrythasler/wasm-playground/actions/workflows/build-aarch64.yml)

# Tiny-Wasm

Following [Tiny Wasm Compiler Tutorial](https://github.com/Schleifner/Tiny-Wasm-Compiler-Learn) to build a compiler and runtime for WebAssembly modules.

Progress:

- Chapter00: ✅
- Chapter01: ✅
- Chapter02: ✅
- Chapter03: ✅
- Chapter04: ✅
- Chapter05: ✅
- Chapter06: ✅
- Chapter07: ✅
- Chapter08: ✅
- Chapter09: ✅
- Chapter10: ✅
- Chapter11: ✅
- Chapter12: ✅
- Chapter13: ✅

### Bonus Chapter

As a bonus I implemented another import function to write a PNG file to disk (`write_png()`). As a showcase, I created a small c program that is capable of generating a [Sierpiński carpet](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_carpet). The program is compiled to webassembly and executed in my custom runtime to generate the following image:

![Sierpiński carpet](fractal.png)

## Feature Highlights

- Uses Kaitai Struct to parse wasm-files
- Custom ELF writer to save generated machinecode to object files that can be disassembled with aarch64-linux-gnu-objdump
- gtest is fetched on demand by cmake (no local installation required)

## Limitations and Known Issues

- Wasm-Stack can not exceed 7 items as the current design stores all stack elements in registers (X9-X15).
- Machinecode can not exceed 64KiB
- Entries in the type section are not canonicalization and different entries with the same structure/meaning are treated as different.
- Function call parameters are limited to 8 as only X0..X7 are used for parameter passing.

## Prerequisites

### Install Dependencies

`sudo apt install g++-aarch64-linux-gnu clang-format clang-tidy wabt cmake qemu-user qemu-user-static gdb-multiarch lcov`

Install the [Native Debug](https://marketplace.visualstudio.com/items?itemName=webfreak.debug) Visual Studio Code extension for debugging.

### Checkout Submodules

`git submodule update --init --recursive`

## Build Instructions

```
$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=cmake/aarch64-toolchain.cmake
$ cmake --build build --parallel
```
This will build the project in the `build` folder.

### Using npm

Build the project with `npm run build`
Run unit-tests with: `npm test`

## Execution

### On x86 Machine using Qemu 

LeakSanitizer is incompatible with emulator/debugging/tracing tools. Setting `detect_leaks=0` disables leak detection during execution.

`ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ build/src/tiny-wasm tests/assets/empty-fn.wasm foo`

### On arm64 Machine

`./build/src/tiny-wasm wasm/nop-fn.wasm`

## Gtest Generator

To create unit-tests from spec-test files (`.wast`), the following workflow can be used:

1. Install python and create a new virtual environment. Use [uv](https://docs.astral.sh/uv/getting-started/installation/) (`uv venv && source .venv/bin/activate`) or any other venv manager.
2. Install python dependencies using uv: `uv sync`.
3. Copy new spectest wast-file to `tests/assets/`
4. add new files to allow_list in `test-generator/generate.py`
5. generate unit-tests with `npm run json2gtest`
6. add new unit-tests to `tests/CMakeLists.txt`
7. execute tests with `npm test`

## Debug 

Start the executable:

`ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ -g 1234 build/src/tiny-wasm tests/assets/empty-fn.wasm foo`

Set breakpoint in source code. Start Debugging (F5).

## gdb cheat sheet

- run debugger: `gdb-multiarch -q --nh -ex 'set architecture aarch64' -ex 'file build/src/tiny-wasm' -ex 'target remote localhost:1234' -ex 'layout split' -ex 'layout regs'`
- add breakpoint at current instruction: `b`
- add breakpoint at function: `b <fn_name>`
- add breakpoint at line in current file: `b <#line>`
- continue to next breakpoint: `c`
- step to next machinecode instruction: `stepi`
- show variable information: `info address <var>`
- show memory content (4 hex uint32_t) : `x/4xw <addr>`
- finish current function (stack frame) and return: `finish`

## Code Quality Tools

### Visual Studio Code Integration

1. `Clang-Format` Extension

## Kaitai Struct

`kaitai-struct-compiler --target cpp_stl webassembly.ksy`

## Design Documentation

### Globals

- Globals are stored in a separate dynamically allocated memory region at runtime. 
- All globals (const and mut) are stored as 64-bit values in memory
- Constant globals are inlined using mov/movk instructions
- Mutable globals are accessed using a pointer to the memory location of the globals calculated from a base address and the index of the global

### Stack Overflow Checks

A global variable is used to store the stack base address obtained via pthread_attr_getstack(). The current SP is compared to this value at runtime and when exceeding a threshold, the trap-handler is called.

## Improvements

- Use a custom memory region for the jit-stack to improve control over stack limits (Chapter 12).

## Tutorial Remarks

- The chapter description should state which new wasm-instructions need to be implemented. Alternatively, all instructions that are required in a later chapter should be implemented during the initial chapter (e.g. `i32.ge_u​` is first required in chapter 11 but could be implemented as part of chapter 4)
- Function calls do not depend on each other until chapter 11 and people can get away to create a new runtime instance for each function-call in the spec-tests. It should be required sooner (maybe as a new chapter) to create a runtime that can manage multiple function calls.
- Chapter 11 uncovered several bugs from previous chapters (br_if, if-else). The test coverage in the chapters should be increased to identify such bugs earlier.
- Wasi-SDK has no pre-build binaries that can be installed in the CI (using `ubuntu-24.04-arm`).
- Loop chapter does not check for correct branch target location.

## Common Pitfalls

- Emitting an instruction with the wrong register size (W8 instead of X8). This error is only noticeable when the value actually exceeds the 32-bit range. This error can be avoided by a careful unit-test design that covers a wide variety of value ranges.

## References

### ARM64 Introduction

- [Running Arm Binaries on x86 with QEMU-User](https://azeria-labs.com/arm-on-x86-qemu-user/)
- [ARM GCC Inline Assembler Cookbook](http://www.ethernut.de/en/documents/arm-inline-asm.html)
- [Mastering arm-linux-gnueabihf-gcc: A Comprehensive Guide ](https://linuxvox.com/blog/arm-linux-gnueabihf-gcc/)
- [ARMv8 AArch64/ARM64 Full Beginner's Assembly Tutorial](https://mariokartwii.com/arm64/)
- [Getting Started with Arm Assembly Language](https://developer.arm.com/documentation/107829/0201)
- [Procedure Call Standard for the Arm® 64-bit Architecture (AArch64) - Parameter passing](https://github.com/ARM-software/abi-aa/blob/main/aapcs64/aapcs64.rst#68parameter-passing)
- [arm64-book - A Book that explains in Detail ARM64 Assembly](https://github.com/maxvdec/arm64-book)

### ARM64 Technical Details

- [AArch64 Interrupt and Exception handling](https://krinkinmu.github.io/2021/01/10/aarch64-interrupt-handling.html)

### ARM64 Instructions

- [Learn the architecture - A64 Instruction Set Architecture Guide](https://developer.arm.com/documentation/102374/latest/)
- [Tuna Cici: AArch64 Procedure Call Standard (AAPCS64): ABI, Calling Conventions & Machine Registers](https://medium.com/@tunacici7/aarch64-procedure-call-standard-aapcs64-abi-calling-conventions-machine-registers-a2c762540278)
- [The Aarch64 Instruction Format for Code Generation in Compiler Design](https://deviceix.github.io/posts/arm_isa_encoding/)
- [Arm A-profile A64 Instruction Set Architecture](https://developer.arm.com/documentation/ddi0602/2025-09?lang=en)
- [ARM Load/Store Addressing Modes](https://duetorun.com/blog/20230613/arm-addressing-modes/)

### ARM64 Online Tools

- [ARMConverter.com - Online ARM to HEX Converter](https://armconverter.com/?lock=arm64)
- [Online Assembler and Disassembler](https://shell-storm.org/online/Online-Assembler-and-Disassembler/)

### WebAssembly

- [WebAssembly 1.0 Core Specification](https://www.w3.org/TR/wasm-core-1/)
- [WebAssembly on developer.mozilla.org](https://developer.mozilla.org/en-US/docs/WebAssembly)
- [Human-readable WebAssembly Reference Manual](https://github.com/sunfishcode/wasm-reference-manual/blob/master/WebAssembly.md)
- [WebAssembly parser for Kaitai.io](https://github.com/evacchi/kaitai-webassembly)
- [Nish Tahir: The WebAssembly Text Format](https://nishtahir.com/the-wasm-text-format/)
- [Stack machines and assembly](https://stanford-cs242.github.io/f18/lectures/04-1-webassembly-practice.html)

### WebAssembly Online Tools

- [WebAssembly Code Explorer](https://wasdk.github.io/wasmcodeexplorer/)

### WebAssembly Runtimes

- [Wasmi - WebAssembly (Wasm) Interpreter](https://github.com/wasmi-labs/wasmi)

### Programming

- [Linux System Calls](https://syscall.sh/)
- [C/C++ open-source libraries with minimal dependencies](https://github.com/r-lyeh/single_file_libs)

### Build Pipeline

- [An Introduction to Modern CMake](https://cliutils.gitlab.io/modern-cmake/README.html)
- [Getting Started With CMake](https://earthly.dev/blog/using-cmake/)
- [Integrating Google Test Into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/)
- [How to measure code coverage with lcov and GTest](https://svnscha.de/posts/cpp-code-coverage/)

### Compiler

- [godbolt - Compiler Explorer](https://godbolt.org/)
- [Compiler Design Tutorial](https://www.tutorialspoint.com/compiler_design/index.htm)