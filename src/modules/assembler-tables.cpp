#include "assembler-tables.hpp"

namespace assembler {
void emitFunctionTable(webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section, std::vector<uint8_t> &data) {
  auto &tables = *table_section->tables();
  for (const auto &table : tables) {
    asserte(table->elemtype() == webassembly_t::types_t::TYPES_ELEMENT,
            "Only funcref element type is supported in function tables. Found: " + std::to_string(table->elemtype()));
    auto limits = table->limits();
    for (auto i = 0u; i < limits->min()->value(); i++) {
      data.push_back(0xff);
    }
  }

  if (element_section != nullptr) {
    for (const auto &element : *element_section->elements()) {
      auto table_index = element->tableidx()->value(); // currently only one table is supported
      asserte(table_index == 0, "Only one function table is supported. Found table index: " + std::to_string(table_index));
      for (int32_t i = 0; i < element->num_init()->value(); i++) {
        data.at(i) = static_cast<uint8_t>(element->init_vec()->at(i)->value());
      }
    }
  }
}
} // namespace assembler