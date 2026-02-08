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
  // copy a reference of itself to global record for access from within the JIT code
  gRuntimeInfo.objectPointer = reinterpret_cast<uintptr_t>(this);

  // allocate JIT code memory
  machineCode_ = std::make_unique<CustomMemory>(module.getMachinecode(), PROT_READ | PROT_EXEC);

  // allocate globals if needed
  if (module.getGlobals()) {
    const auto globalMemory = std::make_unique<std::vector<uint64_t>>(module.getGlobals()->serialize());
  }

  // add linear memory if needed
  if (module.getMemory()) {
    linearMemoryState.pages = module.getMemory()->initialSize;
    linearMemoryState.maxPages = module.getMemory()->maxSize;
    gLinearMemoryInfo.sizeBytes = linearMemoryState.pages * wasm::LINEAR_MEMORY_PAGE_SIZE;
    linearMemory_ = std::make_unique<CustomMemory>(gLinearMemoryInfo.sizeBytes, module.getMemory()->init.data, module.getMemory()->init.offset,
                                                   PROT_READ | PROT_WRITE);
    gLinearMemoryInfo.address = reinterpret_cast<uint64_t>(linearMemory_->getAddress());
    gLinearMemoryInfo.growFunctionAddress = reinterpret_cast<uintptr_t>(ModuleInstance::getLinearMemoryGrowAddress());
  } else {
    gLinearMemoryInfo.growFunctionAddress = 0;
    gLinearMemoryInfo.address = 0;
  }
}

int32_t ModuleInstance::linearMemoryGrow(int32_t pages) {
  std::cout << "pages requested: " << pages << std::endl;
  if (linearMemoryState.pages + pages <= linearMemoryState.maxPages) {
    auto currentPages = linearMemoryState.pages;
    // FIXME: implement actual memory grow operation
    linearMemoryState.pages += pages;
    gLinearMemoryInfo.sizeBytes = linearMemoryState.pages * wasm::LINEAR_MEMORY_PAGE_SIZE;
    return currentPages;
  } else {
    return -1;
  }
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