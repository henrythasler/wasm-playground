#include "tiny-runtime.hpp"

namespace tiny {
void Runtime::execute(const std::vector<uint8_t> &machinecode) {
  size_t alloc_size = machinecode.size(); // not required to be page-aligned as mmap will round up internally
  void *exec_mem = mmap(NULL, alloc_size, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  asserte(exec_mem != MAP_FAILED, "mmap failed with " + std::string(strerror(errno)));

  // Copy code to executable memory region
  memcpy(exec_mem, machinecode.data(), machinecode.size());

  // Execute
  auto wasm_module = reinterpret_cast<void (*)()>(exec_mem);
  __builtin___clear_cache(exec_mem, static_cast<size_t *>(exec_mem) + alloc_size);
  wasm_module();

  // Cleanup
  asserte(munmap(exec_mem, alloc_size) == 0, "munmap failed with " + std::string(strerror(errno)));
}
} // namespace tiny