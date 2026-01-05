#include "helper.hpp"
#include "wasm.hpp"
#include "webassembly.h"

namespace assembler {
class FunctionTable {
private:
public:
  size_t offset = 0;
  size_t size = 0;
  std::string name;
  std::vector<uint8_t> data;

  FunctionTable() = default;
  ~FunctionTable() = default;
};

void emitFunctionTable(webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section, std::vector<uint8_t> &data);
} // namespace assembler