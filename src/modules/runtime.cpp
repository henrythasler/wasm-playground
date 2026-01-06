#include "runtime.hpp"

namespace tiny {

void CustomMemory::allocate_and_copy(const uint8_t *data, size_t byte_size, int mode) {
  asserte(byte_size > 0, "Cannot allocate zero-sized memory");

  // Allocate writable memory
  mem_ = mmap(nullptr, byte_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  asserte(mem_ != MAP_FAILED, "mmap failed: " + std::string(strerror(errno)));

  // Copy data
  memcpy(mem_, data, byte_size);

  // Clear instruction cache (critical for ARM/AArch64)
  __builtin___clear_cache(mem_, static_cast<char *>(mem_) + byte_size);

  // Set final permissions (e.g. remove write permission for W^X compliance)
  if (mprotect(mem_, byte_size, mode) != 0) {
    munmap(mem_, byte_size);
    asserte(false, "mprotect failed: " + std::string(strerror(errno)));
  }
}

} // namespace tiny