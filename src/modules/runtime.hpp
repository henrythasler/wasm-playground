#pragma once

#include <cerrno>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <sys/mman.h>
#include <vector>

#include "helper.hpp"

namespace tiny {

using wasm_i32_t = int32_t;
using wasm_i64_t = int64_t;
using wasm_f32_t = float;
using wasm_f64_t = double;

/**
 * RAII wrapper for JIT-compiled executable memory
 * Handles allocation, permission management, and automatic cleanup
 */
class ExecutableMemory {
private:
  void *mem_;
  size_t size_;

  // Helper to get byte size from uint32_t vector
  static size_t get_byte_size(const std::vector<uint32_t> &code) {
    return code.size() * sizeof(uint32_t);
  }

  // Helper to get byte pointer from uint32_t vector
  static const uint8_t *get_byte_ptr(const std::vector<uint32_t> &code) {
    return reinterpret_cast<const uint8_t *>(code.data());
  }

  void allocate_and_copy(const uint8_t *data, size_t byte_size) {
    asserte(byte_size > 0, "Cannot allocate zero-sized memory");

    // Allocate writable memory
    mem_ = mmap(nullptr, byte_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    asserte(mem_ != MAP_FAILED, "mmap failed: " + std::string(strerror(errno)));

    // Copy machine code
    memcpy(mem_, data, byte_size);

    // Clear instruction cache (critical for ARM/AArch64)
    __builtin___clear_cache(mem_, static_cast<char *>(mem_) + byte_size);

    // Make executable (remove write permission for W^X compliance)
    if (mprotect(mem_, byte_size, PROT_READ | PROT_EXEC) != 0) {
      munmap(mem_, byte_size);
      asserte(false, "mprotect failed: " + std::string(strerror(errno)));
    }
  }

public:
  // Constructor for uint8_t vector (byte array)
  ExecutableMemory(const std::vector<uint8_t> &code) : mem_(nullptr), size_(code.size()) {
    allocate_and_copy(code.data(), size_);
  }

  // Constructor for uint32_t vector (word array)
  ExecutableMemory(const std::vector<uint32_t> &code) : mem_(nullptr), size_(get_byte_size(code)) {
    allocate_and_copy(get_byte_ptr(code), size_);
  }

  ~ExecutableMemory() {
    if (mem_ != nullptr) {
      munmap(mem_, size_);
    }
  }

  // Delete copy constructor and assignment
  ExecutableMemory(const ExecutableMemory &) = delete;
  ExecutableMemory &operator=(const ExecutableMemory &) = delete;

  // Allow move semantics
  ExecutableMemory(ExecutableMemory &&other) noexcept : mem_(other.mem_), size_(other.size_) {
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
  ExecutableMemory exec_mem_;
  using FuncPtr = ReturnType (*)(Args...);
  FuncPtr func_ptr_;

public:
  explicit WasmExecutable(const std::vector<uint8_t> &machine_code) : exec_mem_(machine_code), func_ptr_(reinterpret_cast<FuncPtr>(exec_mem_.get())) {
    if (func_ptr_ == nullptr) {
      throw std::runtime_error("Invalid function pointer");
    }
  }

  // Constructor for uint32_t vector
  explicit WasmExecutable(const std::vector<uint32_t> &machine_code)
      : exec_mem_(machine_code), func_ptr_(reinterpret_cast<FuncPtr>(exec_mem_.get())) {
    if (func_ptr_ == nullptr) {
      throw std::runtime_error("Invalid function pointer");
    }
  }

  // Call operator - allows using the object like a function
  ReturnType operator()(Args... args) const {
    return func_ptr_(args...);
  }

  // Explicit call method
  ReturnType call(Args... args) const {
    return func_ptr_(args...);
  }

  // Get raw function pointer (for advanced usage)
  FuncPtr get_function_pointer() const {
    return func_ptr_;
  }
};

/**
 * Convenience factory function with automatic type deduction
 * calls WasmExecutable<ReturnType, Args...>
 * Usage:
 *   auto add = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(code);
 *   wasm_i32 result = add(5, 7);
 */
template <typename ReturnType, typename... Args> WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint8_t> &code) {
  return WasmExecutable<ReturnType, Args...>(code);
}

template <typename ReturnType, typename... Args> WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint32_t> &code) {
  return WasmExecutable<ReturnType, Args...>(code);
}

} // namespace tiny