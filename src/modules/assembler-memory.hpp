#include <iomanip>

#include "helper.hpp"
#include "leb128.hpp"
#include "wasm.hpp"
#include "webassembly.h"

#define MAX_LINEAR_MEMORY_PAGES 16

namespace assembler {

struct InitData {
  int32_t offset;
  std::vector<uint8_t> data;
};

class LinearMemory {
private:
public:
  int32_t minSize;
  int32_t maxSize;
  InitData initData;

  LinearMemory() = default;
  ~LinearMemory() = default;

  void parseMemorySection(webassembly_t::memory_section_t &memory_section, webassembly_t::data_section_t &data_section);
};

} // namespace assembler