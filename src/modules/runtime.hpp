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

public:
  ExecutableMemory(const std::vector<uint8_t> &code) : mem_(nullptr), size_(code.size()) {
    asserte(size_ > 0, "Cannot allocate zero-sized memory");

    // Allocate writable memory
    mem_ = mmap(nullptr, size_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    asserte(mem_ != MAP_FAILED, "mmap failed: " + std::string(strerror(errno)));

    // Copy machine code
    memcpy(mem_, code.data(), code.size());

    // Clear instruction cache (critical for ARM/AArch64)
    __builtin___clear_cache(mem_, static_cast<char *>(mem_) + size_);

    // Make executable (remove write permission for W^X compliance)
    if (mprotect(mem_, size_, PROT_READ | PROT_EXEC) != 0) {
      munmap(mem_, size_);
      asserte(false, "mprotect failed: " + std::string(strerror(errno)));
    }
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
 *
 * Usage:
 *   auto add = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(code);
 *   wasm_i32 result = add(5, 7);
 */
template <typename ReturnType, typename... Args> WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint8_t> &code) {
  return WasmExecutable<ReturnType, Args...>(code);
}

/**
 * Type-erased quick executor for one-time execution
 * Useful when you don't need to keep the function around
 */
template <typename ReturnType, typename... Args> ReturnType execute_wasm_once(const std::vector<uint8_t> &code, Args... args) {
  ExecutableMemory exec_mem(code);
  auto func = reinterpret_cast<ReturnType (*)(Args...)>(exec_mem.get());
  return func(args...);
}
} // namespace tiny