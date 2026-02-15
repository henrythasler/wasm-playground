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

void CustomMemory::grow(size_t newSize) {
  asserte(newSize >= size_, "grow(): new size is smaller that current size");
  asserte(newSize < wasm::LINEAR_MEMORY_MAX_PAGES * wasm::LINEAR_MEMORY_PAGE_SIZE, "grow(): new size exceeds limit");

  // allocate new memory region
  void *newMemory = mmap(nullptr, newSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  asserte(newMemory != MAP_FAILED, "grow(): mmap failed with " + std::string(strerror(errno)));

  // Copy old data to new region
  memcpy(newMemory, mem_, std::min(size_, newSize));
  // delete old memory
  munmap(mem_, size_);

  // switch to new memory
  mem_ = static_cast<uint8_t *>(newMemory);
  size_ = newSize;

  // Clear instruction cache (critical for ARM/AArch64)
  __builtin___clear_cache(mem_, mem_ + size_);

  // Set final permissions (e.g. remove write permission for W^X compliance)
  if (mprotect(mem_, size_, protectionMode_) != 0) {
    munmap(mem_, size_);
    asserte(false, "grow(): mprotect failed with " + std::string(strerror(errno)));
  }
}

void *ModuleInstance::getStackBaseAddress() {
  pthread_attr_t attr;
  void *stack_addr;
  size_t stack_size;
  // Get current thread's stack attributes
  pthread_getattr_np(pthread_self(), &attr);
  pthread_attr_getstack(&attr, &stack_addr, &stack_size);
  pthread_attr_destroy(&attr);
  return stack_addr;
}

ModuleInstance::ModuleInstance(WasmModule &module) : module_(module) {
  // copy a reference of itself to global record for access from within the JIT code
  gRuntimeInfo.objectPointer = reinterpret_cast<uintptr_t>(this);

  // allocate JIT code memory
  machineCode_ = std::make_unique<CustomMemory>(module.getMachinecode(), PROT_READ | PROT_EXEC);
  gRuntimeInfo.machineCodeAddress = reinterpret_cast<uint64_t>(machineCode_->getAddress());

  // allocate globals if needed
  if (module.getGlobals()) {
    auto globalMemory = module_.getGlobals()->serialize();
    globals_ = std::make_unique<CustomMemory>(globalMemory, PROT_READ | PROT_WRITE);
    gRuntimeInfo.globalsMemoryAddress = reinterpret_cast<uint64_t>(globals_->getAddress());
  }

  // add linear memory if needed
  if (module.getMemory()) {
    gLinearMemoryInfo.sizePages = module.getMemory()->initialSize;
    gLinearMemoryInfo.sizeBytes = gLinearMemoryInfo.sizePages * wasm::LINEAR_MEMORY_PAGE_SIZE;
    linearMemory_ = std::make_unique<CustomMemory>(gLinearMemoryInfo.sizeBytes, module.getMemory()->init.data, module.getMemory()->init.offset,
                                                   PROT_READ | PROT_WRITE);
    gLinearMemoryInfo.address = reinterpret_cast<uint64_t>(linearMemory_->getAddress());
    gLinearMemoryInfo.growFunctionAddress = reinterpret_cast<uintptr_t>(ModuleInstance::getLinearMemoryGrowAddress());
  } else {
    gLinearMemoryInfo.growFunctionAddress = 0;
    gLinearMemoryInfo.address = 0;
    gLinearMemoryInfo.sizePages = 0;
    gLinearMemoryInfo.sizeBytes = gLinearMemoryInfo.sizePages * wasm::LINEAR_MEMORY_PAGE_SIZE;
  }

  gRuntimeInfo.stackBaseAddress = reinterpret_cast<uint64_t>(getStackBaseAddress());
}

int32_t ModuleInstance::linearMemoryGrow(int32_t pagesRequested) {
  // std::cout << "pages requested: " << pagesRequested << std::endl;
  if (gLinearMemoryInfo.sizePages + pagesRequested <= module_.getMemory()->maxSize) {
    auto currentPages = gLinearMemoryInfo.sizePages;
    gLinearMemoryInfo.sizePages += pagesRequested;
    if (currentPages != gLinearMemoryInfo.sizePages) {
      gLinearMemoryInfo.sizeBytes = gLinearMemoryInfo.sizePages * wasm::LINEAR_MEMORY_PAGE_SIZE;
      linearMemory_->grow(gLinearMemoryInfo.sizeBytes);
      gLinearMemoryInfo.address = reinterpret_cast<uint64_t>(linearMemory_->getAddress());
    }
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