# Tiny-Wasm

Following [Tiny Wasm Compiler Tutorial](https://github.com/Schleifner/Tiny-Wasm-Compiler-Learn).

## Build Instructions

### Prerequisites

`sudo apt install g++-aarch64-linux-gnu`

### Build Steps

```
$ cd tiny-wasm
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . --parallel
```

## Debug 

Start the executable:

`qemu-aarch64 -L /usr/aarch64-linux-gnu/ -g 1234 ./tiny-wasm ../wasm/nop-fn.wasm`

Set breakpoint in source code. Start Debugging (F5).