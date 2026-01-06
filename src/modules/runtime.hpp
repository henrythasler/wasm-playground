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

  void allocate_and_copy(const uint8_t *data, size_t byte_size, int mode);

public:
  // Constructor for uint8_t vector (byte array)
  CustomMemory(const std::vector<uint8_t> &data, int mode = PROT_READ | PROT_EXEC) : mem_(nullptr), size_(data.size()) {
    if (size_ > 0) {
      allocate_and_copy(data.data(), size_, mode);
    }
  }

  // Constructor for uint32_t vector (word array)
  CustomMemory(const std::vector<uint32_t> &data, int mode = PROT_READ | PROT_EXEC) : mem_(nullptr), size_(get_byte_size(data)) {
    if (size_ > 0) {
      allocate_and_copy(get_byte_ptr(data), size_, mode);
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
  CustomMemory ro_mem_;
  using FuncPtr = ReturnType (*)(Args...);
  FuncPtr func_ptr_;
  uint8_t *ro_mem_ptr_;

public:
  explicit WasmExecutable(const std::vector<uint8_t> &machine_code, const std::vector<uint8_t> &functionTable, size_t offset = 0)
      : exec_mem_(machine_code), ro_mem_(functionTable, PROT_READ),
        func_ptr_(reinterpret_cast<FuncPtr>(static_cast<char *>(exec_mem_.get()) + offset)), ro_mem_ptr_(static_cast<uint8_t *>(ro_mem_.get())) {
    if (func_ptr_ == nullptr) {
      throw std::runtime_error("Invalid function pointer");
    }
  }

  // Constructor for uint32_t vector
  explicit WasmExecutable(const std::vector<uint32_t> &machine_code, const std::vector<uint8_t> &functionTable, size_t offset = 0)
      : exec_mem_(machine_code), ro_mem_(functionTable, PROT_READ),
        func_ptr_(reinterpret_cast<FuncPtr>(static_cast<char *>(exec_mem_.get()) + offset)), ro_mem_ptr_(static_cast<uint8_t *>(ro_mem_.get())) {
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

  uint8_t *get_ro_memory_pointer() const {
    return ro_mem_ptr_;
  }
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
  auto empty = std::vector<uint8_t>{};
  return WasmExecutable<ReturnType, Args...>(code, empty, offset);
}

template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint32_t> &code, size_t offset = 0) {
  auto empty = std::vector<uint8_t>{};
  return WasmExecutable<ReturnType, Args...>(code, empty, offset);
}

template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_linked_wasm_function(tiny::WasmModule &wasmModule, const std::string &funcName) {
  const auto &code = wasmModule.getMachinecode();
  size_t offset = wasmModule.getFunctionOffset(funcName);
  const auto *functionTable = wasmModule.getFunctionTable();

  auto wasmExecutable = WasmExecutable<ReturnType, Args...>(code, functionTable->data, offset);
  return wasmExecutable;
}

} // namespace tiny