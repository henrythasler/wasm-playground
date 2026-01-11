#pragma once

#include <cerrno>
#include <csetjmp>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <sys/mman.h>
#include <vector>

#include "assembler.hpp"
#include "helper.hpp"
#include "module.hpp"
#include "wasm.hpp"

namespace tiny {

/**
 * RAII wrapper for JIT-compiled executable memory
 * Handles allocation, permission management, and automatic cleanup
 */
class CustomMemory {
private:
  void *mem_;
  size_t size_;

  // Helper to get byte size from uint32_t vector
  static size_t get_byte_size(const std::vector<uint32_t> &data) {
    return data.size() * sizeof(uint32_t);
  }

  // Helper to get byte pointer from uint32_t vector
  static const uint8_t *get_byte_ptr(const std::vector<uint32_t> &code) {
    return reinterpret_cast<const uint8_t *>(code.data());
  }

  void allocate_and_copy(const uint8_t *data, size_t byte_size, int protectionMode);

public:
  // Constructor for uint8_t vector (byte array)
  CustomMemory(const std::vector<uint8_t> &data, int protectionMode) : mem_(nullptr), size_(data.size()) {
    if (size_ > 0) {
      allocate_and_copy(data.data(), size_, protectionMode);
    }
  }

  // Constructor for uint32_t vector (word array)
  CustomMemory(const std::vector<uint32_t> &data, int protectionMode) : mem_(nullptr), size_(get_byte_size(data)) {
    if (size_ > 0) {
      allocate_and_copy(get_byte_ptr(data), size_, protectionMode);
    }
  }

  ~CustomMemory() {
    if (mem_ != nullptr) {
      munmap(mem_, size_);
    }
  }

  // Delete copy constructor and assignment
  CustomMemory(const CustomMemory &) = delete;
  CustomMemory &operator=(const CustomMemory &) = delete;

  // Allow move semantics
  CustomMemory(CustomMemory &&other) noexcept : mem_(other.mem_), size_(other.size_) {
    other.mem_ = nullptr;
    other.size_ = 0;
  }

  void *get() const {
    return mem_;
  }

  size_t size() const {
    return size_;
  }
};

/**
 * Template class for type-safe WebAssembly function execution
 *
 * Usage:
 *   WasmFunction<wasm_i32, wasm_i32, wasm_i32> add_func(machine_code);
 *   wasm_i32 result = add_func(10, 20);
 */
template <typename ReturnType, typename... Args> class WasmExecutable {
private:
  CustomMemory exec_mem_;
  using FuncPtr = ReturnType (*)(Args...);
  FuncPtr func_ptr_;

public:
  explicit WasmExecutable(const std::vector<uint8_t> &machine_code, size_t offset = 0)
      : exec_mem_(machine_code, PROT_READ | PROT_EXEC), func_ptr_(reinterpret_cast<FuncPtr>(static_cast<char *>(exec_mem_.get()) + offset)) {
    if (func_ptr_ == nullptr) {
      throw std::runtime_error("Invalid function pointer");
    }
  }

  // Constructor for uint32_t vector
  explicit WasmExecutable(const std::vector<uint32_t> &machine_code, size_t offset = 0)
      : exec_mem_(machine_code, PROT_READ | PROT_EXEC), func_ptr_(reinterpret_cast<FuncPtr>(static_cast<char *>(exec_mem_.get()) + offset)) {
    if (func_ptr_ == nullptr) {
      throw std::runtime_error("Invalid function pointer");
    }
  }

  // Call operator - allows using the object like a function
  ReturnType operator()(Args... args) const {
    return call(args...);
  }

  // Explicit call method
  ReturnType call(Args... args) const {
    auto trap_code = wasm::trap_code_t(_setjmp(g_jmpbuf));
    if (trap_code == wasm::trap_code_t::None) {
      // First time - call the JIT function
      return func_ptr_(args...);
    } else {
      // Returned via longjmp - handle the error
      std::error_code ec(int32_t(trap_code), std::generic_category());
      throw std::system_error(ec, wasm::trapCodeToString(trap_code));
    }
  }

  // Get raw function pointer (for advanced usage)
  FuncPtr get_function_pointer() const {
    return func_ptr_;
  }

  // intptr_t get_fntable_memory_address() const {
  //   return reinterpret_cast<intptr_t>(fn_table_.get());
  // }

  // intptr_t get_code_memory_address() const {
  //   return reinterpret_cast<intptr_t>(exec_mem_.get());
  // }

  // uint32_t *get_mutable_code_pointer() {
  //   return static_cast<uint32_t *>(exec_mem_.get());
  // }
};

/**
 * Convenience factory function with automatic type deduction
 * calls WasmExecutable<ReturnType, Args...>
 * Usage:
 *   auto add = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(code);
 *   wasm_i32 result = add(5, 7);
 */
template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint8_t> &code, size_t offset = 0) {
  return WasmExecutable<ReturnType, Args...>(code, offset);
}

template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint32_t> &code, size_t offset = 0) {
  return WasmExecutable<ReturnType, Args...>(code, offset);
}

template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(tiny::WasmModule &wasmModule, const std::string &funcName) {
  const auto &linkedCode = wasmModule.linkMachinecode();
  size_t exportFunctionOffset = wasmModule.getFunctionOffset(funcName);
  auto wasmExecutable = WasmExecutable<ReturnType, Args...>(linkedCode, exportFunctionOffset);

  // auto fnTableAddress = wasmExecutable.get_fntable_memory_address();
  // auto codeAddress = wasmExecutable.get_code_memory_address();

  // uint32_t *codePtr = wasmExecutable.get_mutable_code_pointer();

  // for (auto wasmFunction : wasmModule.getWasmFunctions()) {
  //   for (auto patchLocation : wasmFunction->getDataSegmentPatches()) {
  //     switch (patchLocation.type) {
  //     case assembler::DataSegmentType::FUNCTION_TABLE: {
  //       // FIXME: consider patch location offset
  //       uint64_t code_page = (uint64_t)codeAddress & ~0xfffULL;
  //       uint64_t target_page = (uint64_t)fnTableAddress & ~0xfffULL;
  //       int64_t page_offset = (int64_t)(target_page - code_page);
  //       uint32_t low12 = (uint64_t)fnTableAddress & 0xfff;

  //       std::cout << std::hex << "Patching code segment 0x" << codeAddress << " at offset 0x" << patchLocation.offset * 4
  //                 << " with function table address at 0x" << fnTableAddress << " (page_offset: 0x" << page_offset << " low12: 0x" << low12 << ")"
  //                 << std::dec << std::endl;
  //       std::cout << std::hex << "  Current ADRP instruction: 0x" << codePtr[patchLocation.offset] << std::dec << std::endl;
  //       arm64::patch_adrp(codePtr[patchLocation.offset], page_offset);
  //       std::cout << std::hex << "  Patched ADRP instruction: 0x" << codePtr[patchLocation.offset] << std::dec << std::endl;

  //       std::cout << std::hex << "  Current ADD instruction: 0x" << codePtr[patchLocation.offset + 1] << std::dec << std::endl;
  //       arm64::patch_add_immediate(codePtr[patchLocation.offset + 1], static_cast<uint16_t>(low12));
  //       std::cout << std::hex << "  Patched ADD instruction: 0x" << codePtr[patchLocation.offset + 1] << std::dec << std::endl;

  //       std::cout << std::hex << "  Table[0]: " << reinterpret_cast<uint32_t *>(fnTableAddress)[0] << std::dec << std::endl;

  //       break;
  //     }
  //     default: {
  //       asserte(false, "Unsupported patch location type");
  //       break;
  //     }
  //     }
  //   }
  // }

  return wasmExecutable;
}

} // namespace tiny