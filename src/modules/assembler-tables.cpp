#include "assembler-tables.hpp"

namespace assembler {
void emitFunctionTable(webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section,
                       std::vector<uint32_t> &machinecode) {
  auto &tables = *table_section->tables();
  for (const auto &table : tables) {
    asserte(table->elemtype() == webassembly_t::types_t::TYPES_ELEMENT,
            "Only funcref element type is supported in function tables. Found: " + std::to_string(table->elemtype()));
    auto limits = table->limits();
    for (auto i = 0u; i < limits->min()->value(); i++) {
      machinecode.push_back(0xffffffff);
    }
  }
}
} // namespace assembler