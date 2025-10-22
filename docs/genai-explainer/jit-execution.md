Source: https://claude.ai

I'll create a comprehensive template-based system for executing WebAssembly-compiled machine code with proper type safety and flexibility.

## Detailed Explanation

### **1. Core Template Class: `WasmFunction<ReturnType, Args...>`**

This is the main template that provides type-safe function execution:

```cpp
template<typename ReturnType, typename... Args>
class WasmFunction {
    using FuncPtr = ReturnType (*)(Args...);
    FuncPtr func_ptr_;
    // ...
};
```

**How it works:**
- **Template Parameters**: `ReturnType` is what the function returns, `Args...` is a variadic pack for all parameter types
- **Function Pointer Type**: `FuncPtr = ReturnType (*)(Args...)` creates the correct function pointer signature
- **Type Safety**: The compiler enforces that you call it with matching types

**Example:**
```cpp
WasmFunction<wasm_i32, wasm_i32, wasm_i32> add;  // (i32, i32) -> i32
add(10, 20);     // ✓ Correct
add(10.5, 20);   // ✗ Compile error: wrong type
add(10);         // ✗ Compile error: wrong number of args
```

### **2. RAII Memory Management: `ExecutableMemory`**

This class handles the lifecycle of JIT memory:

```cpp
class ExecutableMemory {
    void* mem_;
    size_t size_;
    
    // Constructor: allocate + copy + make executable
    // Destructor: automatically munmap()
};
```

**Benefits:**
- **Automatic cleanup**: Memory is freed when object goes out of scope
- **Exception safety**: If anything throws, destructor still runs
- **W^X compliance**: Separates write and execute phases
- **Cache coherency**: Calls `__builtin___clear_cache()` automatically

### **3. Factory Function: `make_wasm_function`**

Simplifies creation with type deduction:

```cpp
template<typename ReturnType, typename... Args>
WasmFunction<ReturnType, Args...> make_wasm_function(const std::vector<uint8_t>& code)
```

**Usage comparison:**
```cpp
// Without factory (verbose):
WasmFunction<wasm_i32, wasm_i32, wasm_i32> f(code);

// With factory (cleaner):
auto f = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(code);
```

### **4. One-Shot Executor: `execute_wasm_once`**

For when you only need to run code once:

```cpp
template<typename ReturnType, typename... Args>
ReturnType execute_wasm_once(const std::vector<uint8_t>& code, Args... args)
```

**When to use:**
- Quick calculations
- Testing
- When you don't need to keep the function around

### **Key Features**

1. **Type Safety**: Compiler catches signature mismatches at compile-time
2. **Zero Overhead**: Templates are resolved at compile-time (no runtime cost)
3. **Flexible**: Supports any combination of WASM types
4. **Safe**: RAII ensures memory is always cleaned up
5. **Compliant**: Follows W^X security policies

### **WebAssembly Type Mapping**

```cpp
using wasm_i32 = int32_t;   // 32-bit integer
using wasm_i64 = int64_t;   // 64-bit integer
using wasm_f32 = float;     // 32-bit float
using wasm_f64 = double;    // 64-bit double
```

These match the WebAssembly specification and typical C ABI conventions.

### **Real-World WebAssembly Integration**

```cpp
// Your WASM compiler output
std::vector<uint8_t> machinecode = compile_wasm_to_x86(wasm_module);

// Create type-safe function based on WASM signature
// For WASM: (func (param i32 i32) (result i32))
auto wasm_func = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(machinecode);

// Call it naturally
wasm_i32 result = wasm_func(100, 200);
```

This approach gives you both **safety** (compile-time type checking) and **performance** (zero runtime overhead from templates).

```cpp
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <stdexcept>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

// WebAssembly standard types
using wasm_i32 = int32_t;
using wasm_i64 = int64_t;
using wasm_f32 = float;
using wasm_f64 = double;

/**
 * RAII wrapper for JIT-compiled executable memory
 * Handles allocation, permission management, and automatic cleanup
 */
class ExecutableMemory {
private:
    void* mem_;
    size_t size_;
    
public:
    ExecutableMemory(const std::vector<uint8_t>& code) 
        : mem_(nullptr), size_(code.size()) {
        
        if (size_ == 0) {
            throw std::runtime_error("Cannot allocate zero-sized memory");
        }
        
        // Allocate writable memory
        mem_ = mmap(nullptr, size_, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        
        if (mem_ == MAP_FAILED) {
            throw std::runtime_error("mmap failed: " + std::string(strerror(errno)));
        }
        
        // Copy machine code
        memcpy(mem_, code.data(), code.size());
        
        // Clear instruction cache (critical for ARM/AArch64)
        __builtin___clear_cache(mem_, static_cast<char*>(mem_) + size_);
        
        // Make executable (remove write permission for W^X compliance)
        if (mprotect(mem_, size_, PROT_READ | PROT_EXEC) != 0) {
            munmap(mem_, size_);
            throw std::runtime_error("mprotect failed: " + std::string(strerror(errno)));
        }
    }
    
    ~ExecutableMemory() {
        if (mem_ != nullptr) {
            munmap(mem_, size_);
        }
    }
    
    // Delete copy constructor and assignment
    ExecutableMemory(const ExecutableMemory&) = delete;
    ExecutableMemory& operator=(const ExecutableMemory&) = delete;
    
    // Allow move semantics
    ExecutableMemory(ExecutableMemory&& other) noexcept 
        : mem_(other.mem_), size_(other.size_) {
        other.mem_ = nullptr;
        other.size_ = 0;
    }
    
    void* get() const { return mem_; }
};

/**
 * Template class for type-safe WebAssembly function execution
 * 
 * Usage:
 *   WasmFunction<wasm_i32, wasm_i32, wasm_i32> add_func(machine_code);
 *   wasm_i32 result = add_func(10, 20);
 */
template<typename ReturnType, typename... Args>
class WasmFunction {
private:
    ExecutableMemory exec_mem_;
    using FuncPtr = ReturnType (*)(Args...);
    FuncPtr func_ptr_;
    
public:
    explicit WasmFunction(const std::vector<uint8_t>& machine_code)
        : exec_mem_(machine_code),
          func_ptr_(reinterpret_cast<FuncPtr>(exec_mem_.get())) {
        
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
template<typename ReturnType, typename... Args>
WasmFunction<ReturnType, Args...> make_wasm_function(const std::vector<uint8_t>& code) {
    return WasmFunction<ReturnType, Args...>(code);
}

/**
 * Type-erased quick executor for one-time execution
 * Useful when you don't need to keep the function around
 */
template<typename ReturnType, typename... Args>
ReturnType execute_wasm_once(const std::vector<uint8_t>& code, Args... args) {
    ExecutableMemory exec_mem(code);
    auto func = reinterpret_cast<ReturnType (*)(Args...)>(exec_mem.get());
    return func(args...);
}

// ============================================================================
// EXAMPLE USAGE
// ============================================================================

#include <iostream>

// Example: Simulated machine code (in real usage, this comes from your compiler)
std::vector<uint8_t> create_add_function() {
    // x86-64 machine code for: int add(int a, int b) { return a + b; }
    // mov eax, edi    ; first param (a) in edi
    // add eax, esi    ; add second param (b) in esi
    // ret
    return {
        0x89, 0xf8,           // mov eax, edi
        0x01, 0xf0,           // add eax, esi
        0xc3                  // ret
    };
}

std::vector<uint8_t> create_multiply_function() {
    // x86-64 machine code for: int mul(int a, int b) { return a * b; }
    // mov eax, edi    ; first param
    // imul eax, esi   ; multiply by second param
    // ret
    return {
        0x89, 0xf8,           // mov eax, edi
        0x0f, 0xaf, 0xc6,     // imul eax, esi
        0xc3                  // ret
    };
}

int main() {
    try {
        std::cout << "=== WebAssembly JIT Execution Examples ===\n\n";
        
        // Example 1: Using WasmFunction class
        std::cout << "Example 1: Addition function\n";
        auto add_code = create_add_function();
        WasmFunction<wasm_i32, wasm_i32, wasm_i32> add_func(add_code);
        
        wasm_i32 sum1 = add_func(10, 20);
        wasm_i32 sum2 = add_func(100, 250);
        std::cout << "  10 + 20 = " << sum1 << "\n";
        std::cout << "  100 + 250 = " << sum2 << "\n\n";
        
        // Example 2: Using factory function
        std::cout << "Example 2: Multiplication function\n";
        auto mul_code = create_multiply_function();
        auto mul_func = make_wasm_function<wasm_i32, wasm_i32, wasm_i32>(mul_code);
        
        wasm_i32 product1 = mul_func(6, 7);
        wasm_i32 product2 = mul_func(12, 12);
        std::cout << "  6 * 7 = " << product1 << "\n";
        std::cout << "  12 * 12 = " << product2 << "\n\n";
        
        // Example 3: One-time execution
        std::cout << "Example 3: One-time execution\n";
        wasm_i32 result = execute_wasm_once<wasm_i32, wasm_i32, wasm_i32>(
            create_add_function(), 42, 58
        );
        std::cout << "  42 + 58 = " << result << "\n\n";
        
        // Example 4: Different signatures
        std::cout << "Example 4: No parameters (returning constant)\n";
        // Machine code for: int get_constant() { return 42; }
        // mov eax, 42; ret
        std::vector<uint8_t> const_code = {
            0xb8, 0x2a, 0x00, 0x00, 0x00,  // mov eax, 42
            0xc3                            // ret
        };
        
        WasmFunction<wasm_i32> get_constant(const_code);
        std::cout << "  Constant = " << get_constant() << "\n\n";
        
        std::cout << "All tests completed successfully!\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
```