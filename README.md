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

As a bonus I implemented another import function to write a PNG file to disk (`write_png()` using [stb](https://github.com/nothings/stb)). The only additional instruction that is needed is `i32.and`. As a showcase, I created a small c program that is capable of generating a [Sierpiński carpet](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_carpet). The program is compiled to webassembly and executed in the custom runtime to generate the following image:

![Sierpiński carpet](fractal.png)

> execute locally with `ASAN_OPTIONS=detect_leaks=0 qemu-aarch64 -L /usr/aarch64-linux-gnu/ build/src/tiny-wasm tests/assets/fractal.wasm _start`

## Feature Highlights

- Uses own [Kaitai Struct](https://github.com/henrythasler/wasm-kaitai-struct) to parse wasm-files
- Custom ELF writer to save generated machinecode to object files that can be [disassembled with aarch64-linux-gnu-objdump](tests/machinecode/empty-fn.asm).
- gtest is fetched on demand by cmake (no local installation required)
- [gtest-generator](test-generator/generate.py) for [wasm-spec-tests](tests/assets) using python and [Jinja](https://jinja.palletsprojects.com/en/stable/) template engine.

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

### JIT structure

The JIT-code on module-level is structured as follows:

Content | Size | Description
---|---|---
trap_handler | ~96 Bytes | loads the trap-code as argument into X0 and calls the trap-handler host function
function_table | n x 8 Bytes | an array of n tuples (`uint32_t offset`, `uint32_t typeidx`) where offset is the offset of that function and typeidx is the item in the type-section for that function.
globals | n x 8 Bytes | an array of all n globals as uint64_t
functions | variable | JIT code for each function of the module serialized back-to-back without padding/alignment

Each function follows this pattern:

Content | Size | Description
---|---|---
preamble | variable | create stack frame, store callee-saved registers, stack overflow check, allocate additional stack memory for parameters and locals
store parameters | variable | move parameters from registers (X0-X7) to stack memory
init locals | variable | initialize local variables on stack with zero (`str	wzr, [...]`)
function body | variable | JIT code of the function business logic itself
load result | variable | load return value into X0
epilogue | 24 Bytes | deallocate stack memory, restore callee-saved registers and return (`ret`)

### JIT-Runtime

One the JIT-code is assembled and address-patched, we need to load the JIT-code into a memory section with executable permissions. This is done by `class ModuleInstance` in [runtime.hpp](src/modules/runtime.hpp#L270) where in instance of `CustomMemory` is created that allocates the required memory, copies the code into that memory region and sets the execution permissions of said region.

To access host resources (e.g trap handler, linear memory), some global variables (`gLinearMemoryInfo` and `gRuntimeInfo`) are updated during that step.

### Accessing Host Ressources

The Runtime provides a set of global variables that contain the address of host ressources (memory, function). The assembler emits specific code to read from this global variable and use its content either to access the memory region or jump directly to this address to call a host function. Here is a commented example when loading a 32-bit value from linear memory:

```asm
// load from address of global variable that contains the start address of linear memory
mov	x9, #0xa360
movk	x9, #0xb6, lsl #16
movk	x9, #0x55, lsl #32
ldr	x9, [x9, xzr]

// trap (MemoryOutOfBounds) if the linear memory address is invalid (nullptr)
cbz	x9, 38 <trap_handler+0x38>

// load the current size of the linear memory region from a global variable
mov	x10, #0xa380
movk	x10, #0xb6, lsl #16
movk	x10, #0x55, lsl #32
ldr	w10, [x10, xzr]

// since we want to access a 4-byte value, the maximum allowed offset is 4 bytes smaller than the overall linear memory size
sub	w10, w10, #0x4
// compare the offset with the (corrected) linear memory size
cmp	w8, w10
// trap (MemoryOutOfBounds) if offset exceeds linear memory size
b.hi	38 <trap_handler+0x38>

// all check have passed and we can load the i32 from linear memory
ldrsw	x9, [x9, x8]
```

### Linear Memory

Linear memory is managed by the runtime that allocates the initial size in a dedicated memory region. It also provides a host function address via a global variable to grow the linear memory region.

### Trap Handler

A trap-handler is always insterted at the beginning of the JIT-code. It allows for setting a specific trap-code and call a runtime host function that will evaluate the trap-code and throw an exception [runtime.hpp](src/modules/runtime.hpp#L252). 

The following trap-codes (based on wasi-libc) are defined:

```cpp
enum class trap_code_t {
  None = 0,
  UnreachableCodeReached,
  MemoryOutOfBounds,
  TableOutOfBounds,
  IndirectCallToNull,
  IntegerDivisionByZero,
  IntegerOverflow,
  BadConversionToInteger,
  StackOverflow,
  BadSignature,
  OutOfFuel,
  GrowthOperationLimited,
  AssemblerAddressPatchError = 255,
};
```

Only a subset is currently in use. The available trap-codes are defined during module compilation in [module.cpp](src/modules/module.cpp#L93).

The trap-handler includes on special trap-code `AssemblerAddressPatchError` (0xFF) which is used by the compiler for jump/branch instructions that need to be patched later when the jump target location is known. This helps identify when address patching operations are incomplete.

### Globals

- Globals are stored in a separate dynamically allocated memory region at runtime. 
- All globals (const and mut) are stored as 64-bit values in memory
- Constant globals are inlined using mov/movk instructions
- Mutable globals are accessed using a pointer to the memory location of the globals calculated from a base address and the index of the global

### Stack Overflow Checks

A global variable is used to store the stack base address obtained via `pthread_attr_getstack()`. Before emitting the preamble for each function, the assembler calculates the required stack from the number of parameters and local variables. When emitting the preamble, the current stack pointer `SP` is checked against to the stack base address (global variable). When exceeding a threshold (currently 4MiB), the trap-handler is called.

## Improvements

- Use a custom memory region for the jit-stack to improve control over stack limits (Chapter 12).

## Tutorial Remarks

- The chapter description should state which new wasm-instructions need to be implemented. Alternatively, all instructions that are required in a later chapter should be implemented during the initial chapter (e.g. `i32.ge_u​` is first required in chapter 11 but could be implemented as part of chapter 4)
- Function calls do not depend on each other until chapter 11 and people can get away to create a new runtime instance for each function-call in the spec-tests. It should be required sooner (maybe as a new chapter) to create a runtime that can manage multiple function calls.
- Chapter 11 uncovered several bugs from previous chapters (br_if, if-else). The test coverage in the chapters should be increased to identify such bugs earlier.
- Wasi-SDK has no pre-build binaries that can be installed in the CI (using `ubuntu-24.04-arm`).
- Loop chapter does not check for correct branch target location.

### Unanswered Questions

1. Why does the trap-handling mechanism need `_setjmp` and `jmp_buf` where normal host functions can use other methods (e.g. global address)?

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
- [LEB128 Encoder and Decoder](https://www.dcode.fr/leb128-encoding)

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