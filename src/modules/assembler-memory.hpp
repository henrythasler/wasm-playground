#include <algorithm>
#include <iomanip>

#include "debug.hpp"
#include "leb128.hpp"
#include "wasm.hpp"
#include "webassembly.h"

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
  InitData init;

  int32_t initialSize;

  LinearMemory() = default;
  ~LinearMemory() = default;

  void parseMemorySection(webassembly_t::memory_section_t *memory_section, webassembly_t::data_section_t *data_section);
};

} // namespace assembler