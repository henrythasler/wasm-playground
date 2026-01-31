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

  // Helper to get byte size from uint64_t vector
  static size_t get_byte_size(const std::vector<uint64_t> &data) {
    return data.size() * sizeof(uint64_t);
  }

  // Helper to get byte pointer from uint32_t vector
  static const uint8_t *get_byte_ptr(const std::vector<uint32_t> &code) {
    return reinterpret_cast<const uint8_t *>(code.data());
  }

  // Helper to get byte pointer from uint64_t vector
  static const uint8_t *get_byte_ptr(const std::vector<uint64_t> &code) {
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

  CustomMemory(const std::vector<uint64_t> &data, int protectionMode) : mem_(nullptr), size_(get_byte_size(data)) {
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

  void *getAddress() const {
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
  std::unique_ptr<CustomMemory> exec_mem_;
  std::unique_ptr<CustomMemory> globals_mem_;
  std::unique_ptr<CustomMemory> linearMemory;
  using FuncPtr = ReturnType (*)(Args...);
  FuncPtr func_ptr_;

public:
  WasmExecutable() = default;
  WasmExecutable(const std::vector<uint32_t> &machine_code, const std::unique_ptr<std::vector<uint64_t>> &globals, size_t offset = 0)
      : WasmExecutable() {
    exec_mem_ = std::make_unique<CustomMemory>(machine_code, PROT_READ | PROT_EXEC);
    executableMemoryAddress = reinterpret_cast<uint64_t>(exec_mem_->getAddress());

    if (globals) {
      globals_mem_ = std::make_unique<CustomMemory>(*globals.get(), PROT_READ | PROT_WRITE);
      globalsMemoryAddress = reinterpret_cast<uint64_t>(globals_mem_->getAddress());
    }

    func_ptr_ = reinterpret_cast<FuncPtr>(static_cast<char *>(exec_mem_->getAddress()) + offset);
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
      std::error_code ec = make_trap_error(trap_code);
      throw std::system_error(ec);
    }
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
template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(const std::vector<uint32_t> &code, size_t offset = 0) {
  return WasmExecutable<ReturnType, Args...>(code, nullptr, offset);
}

template <typename ReturnType, typename... Args>
WasmExecutable<ReturnType, Args...> make_wasm_function(tiny::WasmModule &wasmModule, const std::string &funcName) {
  const auto &linkedCode = wasmModule.linkMachinecode();
  size_t exportFunctionOffset = wasmModule.getFunctionOffset(funcName);
  const auto globalMemory = wasmModule.getGlobals() ? std::make_unique<std::vector<uint64_t>>(wasmModule.getGlobals()->serialize()) : nullptr;
  auto wasmExecutable = WasmExecutable<ReturnType, Args...>(linkedCode, globalMemory, exportFunctionOffset);
  return wasmExecutable;
}

} // namespace tiny