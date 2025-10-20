#pragma once

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

#include "webassembly.h"

namespace tiny {
enum class SectionID : uint8_t {
  Custom = 0,
  Type = 1,
  Import = 2,
  Function = 3,
  Table = 4,
  Memory = 5,
  Global = 6,
  Export = 7,
  Start = 8,
  Element = 9,
  Code = 10,
  Data = 11
};

class Dissector {
private:
  static void dissectCodeSection(webassembly_t::code_section_t *code_section);
  static void dissectExportSection(webassembly_t::export_section_t *export_section);

public:
  Dissector() = default;
  ~Dissector() = default;

  static std::vector<std::string> section_names;
  static std::map<uint8_t, std::string> type_names;
  static std::vector<std::string> export_type_names;

  static void dissect(std::vector<uint8_t> bytecode);
  static std::string getSectionName(uint8_t id);
};
} // namespace tiny