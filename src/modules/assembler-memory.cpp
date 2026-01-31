#include "assembler-memory.hpp"

namespace assembler {

void LinearMemory::parseMemorySection(webassembly_t::memory_section_t &memory_section, webassembly_t::data_section_t &data_section){
  asserte(memory_section.num_memories()->value() == 1, "parseMemorySection(): Found unsupported number of memory sections");
  auto &wasm_memory = *memory_section.memories()->at(0);

  auto limits = wasm_memory.limits();
  this->minSize = limits->min()->value();
  this->maxSize = limits->flags() == 0x01 ? limits->max()->value() : INT32_MAX;

  asserte(this->minSize <= this->minSize, "parseMemorySection(): minSize is larger than maxSize");
  asserte(this->minSize <= MAX_LINEAR_MEMORY_PAGES, "parseMemorySection(): minSize of linear memory too large");
  asserte(this->maxSize <= MAX_LINEAR_MEMORY_PAGES, "parseMemorySection(): maxSize of linear memory too large");
}

} // namespace assembler