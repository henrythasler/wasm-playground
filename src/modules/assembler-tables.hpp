#include "helper.hpp"
#include "wasm.hpp"
#include "webassembly.h"

namespace assembler {
class TableSection {
private:
public:
  size_t machinecodeOffset = 0;
  size_t machinecodeSize = 0;
  std::string name;

  TableSection() = default;
  ~TableSection() = default;
};

void emitFunctionTable(webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section,
                       std::vector<uint32_t> &machinecode);
} // namespace assembler