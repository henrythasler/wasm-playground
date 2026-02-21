#pragma once
#include <csetjmp>
#include <cstdint>

// Global jmp_buf for trap handling
extern jmp_buf g_jmpbuf;

struct RuntimeInfo {
  // Global variable to hold the base address for JIT-compiled code
  uint64_t machineCodeAddress = 0;
  uint64_t *machineCodeAddressPtr = nullptr;

  // Variable to hold the address of wasm-globals
  uint64_t globalsMemoryAddress = 0;
  uint64_t *globalsMemoryAddressPtr = nullptr;

  // Stack base address for stack overflow checks
  uint64_t stackBaseAddress = 0;
  uint64_t *stackBaseAddressPtr = nullptr;

  // holds a reference to the runtime-object itself
  uintptr_t objectPointer = 0;
  uintptr_t *objectPointerPtr = nullptr;

  RuntimeInfo() {
    machineCodeAddressPtr = &machineCodeAddress;
    globalsMemoryAddressPtr = &globalsMemoryAddress;
    stackBaseAddressPtr = &stackBaseAddress;
    objectPointerPtr = &objectPointer;
  }
};
extern RuntimeInfo gRuntimeInfo;

// Struct definition with self-initializing pointers
struct LinearMemoryInfo {
  uint64_t address = 0;
  uint64_t *addressPtr = nullptr;

  int32_t sizePages = 0;
  int32_t *sizePagesPtr = nullptr;

  int32_t sizeBytes = 0;
  int32_t *sizeBytesPtr = nullptr;

  uintptr_t growFunctionAddress = 0;
  uintptr_t *growFunctionAddressPtr = nullptr;

  // Constructor sets the pointers to point to the members
  LinearMemoryInfo() {
    sizeBytesPtr = &sizeBytes;
    sizePagesPtr = &sizePages;
    growFunctionAddressPtr = &growFunctionAddress;
    addressPtr = &address;
  }
};
// Declare a global instance of the struct
extern LinearMemoryInfo gLinearMemoryInfo;