#include "runtime.hpp"

namespace tiny {

void CustomMemory::allocate_and_copy(const uint8_t *data, size_t byte_size, int protectionMode) {
  asserte(byte_size > 0, "Cannot allocate zero-sized memory");

  // Allocate writable memory
  mem_ = static_cast<uint8_t *>(mmap(nullptr, byte_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
  asserte(mem_ != reinterpret_cast<uint8_t *>(MAP_FAILED), "mmap failed: " + std::string(strerror(errno)));

  // Copy data
  memcpy(mem_, data, byte_size);

  // Clear instruction cache (critical for ARM/AArch64)
  __builtin___clear_cache(mem_, mem_ + byte_size);

  // Set final permissions (e.g. remove write permission for W^X compliance)
  if (mprotect(mem_, byte_size, protectionMode) != 0) {
    munmap(mem_, byte_size);
    asserte(false, "mprotect failed: " + std::string(strerror(errno)));
  }
}

void CustomMemory::allocate_and_copy(const uint8_t *init, size_t initSize, size_t initOffset, int protectionMode) {
  asserte(this->size_ > 0, "Cannot allocate zero-sized memory");

  // Allocate writable memory
  mem_ = static_cast<uint8_t *>(mmap(nullptr, this->size_, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));
  asserte(mem_ != reinterpret_cast<uint8_t *>(MAP_FAILED), "mmap failed: " + std::string(strerror(errno)));

  // Copy data
  memcpy(mem_ + initOffset, init, initSize);

  // Clear instruction cache (critical for ARM/AArch64)
  __builtin___clear_cache(mem_, mem_ + this->size_);

  // Set final permissions (e.g. remove write permission for W^X compliance)
  if (mprotect(mem_, this->size_, protectionMode) != 0) {
    munmap(mem_, this->size_);
    asserte(false, "mprotect failed: " + std::string(strerror(errno)));
  }
}

ModuleInstance::ModuleInstance(WasmModule &module) : module_(module) {
  machineCode_ = std::make_unique<CustomMemory>(module.getMachinecode(), PROT_READ | PROT_EXEC);
  if (module.getGlobals()) {
    const auto globalMemory = std::make_unique<std::vector<uint64_t>>(module.getGlobals()->serialize());
  }
  if (module.getMemory()) {
    linearMemoryCurrentPages = module.getMemory()->initialSize;
    linearMemorySizeBytes = linearMemoryCurrentPages * wasm::LINEAR_MEMORY_PAGE_SIZE;
    linearMemory_ =
        std::make_unique<CustomMemory>(linearMemorySizeBytes, module.getMemory()->init.data, module.getMemory()->init.offset, PROT_READ | PROT_WRITE);
    linearMemoryAddress = reinterpret_cast<uint64_t>(linearMemory_->getAddress());
    linearMemoryGrowAddress = reinterpret_cast<uintptr_t>(ModuleInstance::getLinearMemoryGrowAddress());
  } else {
    linearMemoryGrowAddress = 0;
    linearMemoryAddress = 0;
  }
}

int32_t ModuleInstance::linearMemoryGrow(int32_t pages) {
  std::cout << "pages requested: " << pages << std::endl;
  return -1;
}

// Static trampoline for JIT to call
int32_t ModuleInstance::linearMemoryGrow_trampoline(ModuleInstance *self, int32_t pages) {
  return self->linearMemoryGrow(pages);
}

// Get the trampoline address
void *ModuleInstance::getLinearMemoryGrowAddress() {
  return reinterpret_cast<void *>(&ModuleInstance::linearMemoryGrow_trampoline);
}

} // namespace tiny