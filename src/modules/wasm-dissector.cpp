#include "wasm-dissector.hpp"

namespace tiny {
std::vector<std::string> Dissector::section_names = {"Custom", "Type",   "Import", "Function", "Table", "Memory",
                                                     "Global", "Export", "Start",  "Element",  "Code",  "Data"};

std::map<uint8_t, std::string> Dissector::type_names = {
    {0x7F, "i32"}, {0x7E, "i64"}, {0x7D, "f32"}, {0x7C, "f64"}, {0x70, "ElementType"}, {0x60, "FunctionType"}, {0x40, "ResultType"},
};

std::vector<std::string> Dissector::export_type_names = {"Function", "Table", "Memory", "Global"};

void Dissector::dissectCodeSection(webassembly_t::code_section_t *code_section) {
  if (code_section && code_section->bodies()) {
    std::cout << " (" << code_section->bodies()->size() << " function bodies)";
    for (size_t j = 0; j < code_section->bodies()->size(); ++j) {
      const auto &body = code_section->bodies()->at(j);
      std::cout << std::endl << "    Function body " << j << " (" << body->body_size()->value() << " bytes)" << std::endl;
      std::cout << "      locals: " << body->data()->local_count()->value();
      if (body->data()->local_count()->value() > 0) {
        std::cout << " [ ";
        for (size_t k = 0; k < static_cast<size_t>(body->data()->local_count()->value()); ++k) {
          if (k > 0)
            std::cout << ", ";
          auto local_count = static_cast<int>(body->data()->locals()->at(k)->count()->value());
          auto local_type = static_cast<uint8_t>(body->data()->locals()->at(k)->type());
          std::cout << local_count << " x " << type_names[local_type];
        }
        std::cout << " ]";
      }
      std::cout << std::endl;

      std::cout << "      instructions: " << body->data()->code().size();
      if (body->data()->code().size() > 0) {
        std::cout << " [ ";
        for (size_t k = 0; k < body->data()->code().size(); ++k) {
          if (k > 0)
            std::cout << " ";
          std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(body->data()->code().at(k));
        }
        std::cout << " ]" << std::dec;
      }
    }
  } else {
    std::cout << " (code section, but failed to parse function bodies)";
  }
  std::cout << std::endl;
}

void Dissector::dissectExportSection(webassembly_t::export_section_t *export_section) {
  if (export_section && export_section->entries()) {
    std::cout << " (" << export_section->entries()->size() << " exports)";
    for (size_t j = 0; j < export_section->entries()->size(); ++j) {
      const auto &entry = export_section->entries()->at(j);
      std::cout << std::endl << "    Export " << j << ": '" << entry->field_str() << "' (";
      std::cout << export_type_names[entry->kind()] << ", index=" << entry->index()->value() << ")";
    }
  } else {
    std::cout << " (export section, but failed to parse entries)";
  }
  std::cout << std::endl;
}

void Dissector::dissect(std::vector<uint8_t> bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  webassembly_t wasm(&ks);

  std::cout << "Magic: " << wasm.magic() << " (" << wasm.magic().size() << " bytes)" << std::endl;
  std::cout << "WASM version: " << wasm.version() << std::endl;

  // iterate over sections
  auto sections = wasm.sections();
  const auto &section_items = *(sections->sections());
  for (size_t i = 0; i < section_items.size(); ++i) {
    const auto &section = section_items.at(i);
    auto section_id = section->header()->id();
    std::cout << "  Section " << i << ": " << section_names[section_id] << " (" << section_id << ")"
              << " size=" << section->header()->payload_len()->value() << " bytes";
    if (SectionID(section_id) == SectionID::Code) {
      // Section 0x0a is the code section; payload_data should be cast to webassembly_t::code_section_t
      auto code_section = dynamic_cast<webassembly_t::code_section_t *>(section->payload_data());
      dissectCodeSection(code_section);
    } else if (SectionID(section_id) == SectionID::Export) {
      auto export_section = dynamic_cast<webassembly_t::export_section_t *>(section->payload_data());
      dissectExportSection(export_section);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl; // Implementation of the dissect method
}
} // namespace tiny