#include "wasm-dissector.hpp"

namespace tiny {
std::vector<std::string> Dissector::section_names = {"Custom", "Type",   "Import", "Function", "Table", "Memory",
                                                     "Global", "Export", "Start",  "Element",  "Code",  "Data"};

std::map<uint8_t, std::string> Dissector::type_names = {
    {0x7F, "i32"}, {0x7E, "i64"}, {0x7D, "f32"}, {0x7C, "f64"}, {0x70, "ElementType"}, {0x60, "FunctionType"}, {0x40, "ResultType"},
};

std::vector<std::string> Dissector::export_type_names = {"Function", "Table", "Memory", "Global"};

void Dissector::dissectCodeSection(webassembly_t::code_section_t *code_section) {
  if (code_section && code_section->entries()) {
    std::cout << " (" << code_section->entries()->size() << " function bodies)";
    for (size_t j = 0; j < code_section->entries()->size(); ++j) {
      const auto &code = code_section->entries()->at(j);
      std::cout << std::endl << "    Function " << j << " (" << code->len_func()->value() << " bytes)" << std::endl;
      auto num_locals = code->func()->num_locals()->value();
      std::cout << "      locals: " << num_locals;
      if (num_locals > 0) {
        std::cout << " [ ";
        const auto &locals = code->func()->locals();
        for (size_t k = 0; k < static_cast<size_t>(num_locals); ++k) {
          if (k > 0)
            std::cout << ", ";
          auto local_count = static_cast<int>(locals->at(k)->num_valtype()->value());
          auto local_type = static_cast<uint8_t>(locals->at(k)->valtype());
          std::cout << local_count << " x " << type_names[local_type];
        }
        std::cout << " ]";
      }
      std::cout << std::endl;

      std::cout << "      instructions: " << code->func()->expr().size();
      if (code->func()->expr().size() > 0) {
        std::cout << " [ ";
        for (size_t k = 0; k < code->func()->expr().size(); ++k) {
          if (k > 0)
            std::cout << " ";
          std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(code->func()->expr().at(k));
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
  if (export_section && export_section->exports()) {
    std::cout << " (" << export_section->exports()->size() << " exports)";
    for (size_t j = 0; j < export_section->exports()->size(); ++j) {
      const auto &entry = export_section->exports()->at(j);
      std::cout << std::endl << "    Export " << j << ": '" << entry->name()->value() << "' (";
      std::cout << export_type_names[entry->exportdesc()] << ", index=" << entry->idx()->value() << ")";
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
  const auto &section_items = *(sections);
  for (size_t i = 0; i < section_items.size(); ++i) {
    const auto &section = section_items.at(i);
    auto section_id = section->id();
    std::cout << "  Section " << i << ": " << section_names[section_id] << " (" << section_id << ")";
    std::cout << " size=" << section->len_content()->value() << " bytes";
    if (SectionID(section_id) == SectionID::Code) {
      // Section 0x0a is the code section; payload_data should be cast to webassembly_t::code_section_t
      auto code_section = dynamic_cast<webassembly_t::code_section_t *>(section->content());
      dissectCodeSection(code_section);
    } else if (SectionID(section_id) == SectionID::Export) {
      auto export_section = dynamic_cast<webassembly_t::export_section_t *>(section->content());
      dissectExportSection(export_section);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl; // Implementation of the dissect method
}
} // namespace tiny