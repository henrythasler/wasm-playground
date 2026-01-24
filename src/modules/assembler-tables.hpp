#include "helper.hpp"
#include "wasm.hpp"
#include "webassembly.h"

namespace assembler {

struct FunctionTableEntry {
  uint32_t index;
  uint32_t offset;
  uint32_t typeIndex;
};

class FunctionTable {
private:
public:
  size_t offset = 0;
  std::string name;
  std::vector<FunctionTableEntry> entries;

  FunctionTable() = default;
  ~FunctionTable() = default;
};

void emitFunctionTable(assembler::FunctionTable *functionTable, webassembly_t::function_section_t *function_section,
                       webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section,
                       std::vector<uint32_t> &machinecode);
} // namespace assembler