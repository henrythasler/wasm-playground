#include "assembler-globals.hpp"
#include "assembler-memory.hpp"

namespace assembler {

void LinearMemory::parseMemorySection(webassembly_t::memory_section_t *memory_section, webassembly_t::data_section_t *data_section) {
  asserte(memory_section->num_memories()->value() == 1, "parseMemorySection(): Found unsupported number of memory sections");
  auto &wasm_memory = memory_section->memories()->at(0);

  auto limits = wasm_memory->limits();
  this->minSize = limits->min()->value();
  this->initialSize = this->minSize;
  this->maxSize = limits->flags() == 0x01 ? limits->max()->value() : wasm::LINEAR_MEMORY_MAX_PAGES;

  asserte(this->minSize <= this->minSize, "parseMemorySection(): minSize is larger than maxSize");
  asserte(this->minSize <= wasm::LINEAR_MEMORY_MAX_PAGES, "parseMemorySection(): minSize of linear memory too large");
  asserte(this->maxSize <= wasm::LINEAR_MEMORY_MAX_PAGES, "parseMemorySection(): maxSize of linear memory too large");

  if (data_section != nullptr) {
    asserte(data_section->num_data()->value() == 1, "parseMemorySection(): Found unsupported number of data sections");
    auto &data = data_section->data_segments()->at(0);

    if (data->num_init()->value() > 0) {
      // parse offset value
      std::vector<uint8_t> expression = *data->offset_expr()->bytes();
      this->init.offset = parseInitExpr(expression);

      auto init_vec = data->init_vec();
      // verify size boundaries
      asserte(init_vec.size() + this->init.offset <= this->maxSize * wasm::LINEAR_MEMORY_PAGE_SIZE,
              "parseMemorySection(): Data segment does not fit into defined linear memory");
      // copy initializer vector from data section into linear memory structure
      this->init.data.assign(init_vec.begin(), init_vec.end());

      // calculate initial number of pages
      this->initialSize =
          std::max(this->initialSize, static_cast<int32_t>((this->init.data.size() + this->init.offset) / wasm::LINEAR_MEMORY_PAGE_SIZE + 1));
    }
  }
}

} // namespace assembler