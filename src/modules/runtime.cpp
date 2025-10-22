#include "runtime.hpp"

namespace tiny {

// template <typename Ret, typename... Args> Ret execute_jit(void *exec_mem, Args... args) {
//   auto func = reinterpret_cast<Ret (*)(Args...)>(exec_mem);
//   return func(args...);
// }

// void Runtime::execute(const std::vector<uint8_t> &machinecode) {
//   size_t alloc_size = machinecode.size(); // not required to be page-aligned as mmap will round up internally
//   void *exec_mem = mmap(NULL, alloc_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
//   asserte(exec_mem != MAP_FAILED, "mmap failed with " + std::string(strerror(errno)));

//   // Copy code to executable memory region
//   memcpy(exec_mem, machinecode.data(), machinecode.size());

//   // Invalidate and clean cache memory
//   __builtin___clear_cache(exec_mem, static_cast<char *>(exec_mem) + alloc_size);

//   // Make executable (remove write permission)
//   int result = mprotect(exec_mem, alloc_size, PROT_READ | PROT_EXEC);
//   asserte(result == 0, "mprotect failed with " + std::string(strerror(errno)));

//   // Execute
//   auto wasm_module = reinterpret_cast<void (*)()>(exec_mem);
//   wasm_module();

//   // Cleanup
//   asserte(munmap(exec_mem, alloc_size) == 0, "munmap failed with " + std::string(strerror(errno)));
// }
} // namespace tiny