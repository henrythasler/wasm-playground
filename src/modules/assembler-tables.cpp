#include "assembler-tables.hpp"

namespace assembler {
void emitFunctionTable(assembler::FunctionTable &functionTable, webassembly_t::function_section_t *function_section,
                       webassembly_t::table_section_t *table_section, webassembly_t::element_section_t *element_section,
                       std::vector<uint32_t> &machinecode) {
  // auto &tables = *table_section->tables();
  // for (const auto &table : tables) {
  //   asserte(table->elemtype() == webassembly_t::types_t::TYPES_ELEMENT,
  //           "Only funcref element type is supported in function tables. Found: " + std::to_string(table->elemtype()));
  //   auto limits = table->limits();
  //   for (auto i = 0u; i < limits->min()->value(); i++) {
  //     data.push_back(0xff);
  //   }
  // }

  // if (element_section != nullptr) {
  //   for (const auto &element : *element_section->elements()) {
  //     auto table_index = element->tableidx()->value(); // currently only one table is supported
  //     asserte(table_index == 0, "Only one function table is supported. Found table index: " + std::to_string(table_index));
  //     for (int32_t i = 0; i < element->num_init()->value(); i++) {
  //       data.at(i) = static_cast<uint8_t>(element->init_vec()->at(i)->value());
  //     }
  //   }
  // }

  const auto &table = *table_section->tables()->at(0);
  const auto &element = *element_section->elements()->at(0);

  functionTable.offset = machinecode.size();

  asserte(table.elemtype() == webassembly_t::types_t::TYPES_ELEMENT,
          "Only funcref element type is supported in function tables. Found: " + std::to_string(table.elemtype()));
  auto limits = table.limits();
  asserte(limits->min()->value() < 0xff, "Function table size > 254: " + std::to_string(limits->min()->value()));
  for (auto i = 0; i < limits->min()->value(); i++) {
    functionTable.entries.push_back({0xff, static_cast<uint32_t>(machinecode.size()), 0xffffffff});
    // emit placeholder for function address and type index
    machinecode.push_back(-1);
    machinecode.push_back(-1);
  }

  // initialize function table with element section
  auto table_index = element.tableidx()->value(); // currently only one table is supported
  asserte(table_index == 0, "Only one function table is supported. Found table index: " + std::to_string(table_index));
  for (int32_t i = 0; i < element.num_init()->value(); i++) {
    auto value = element.init_vec()->at(i)->value();
    asserte(value < 0xff, "Function index in table >254: " + std::to_string(value));
    functionTable.entries.at(i).index = static_cast<uint8_t>(value);
    functionTable.entries.at(i).typeIndex = function_section->typeidx()->at(static_cast<size_t>(value))->value();
  }

  functionTable.name = "function_table";
}
} // namespace assembler