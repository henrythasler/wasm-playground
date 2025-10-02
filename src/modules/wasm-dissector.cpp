#include "wasm-dissector.hpp"

void Dissector::dissectCodeSection(webassembly_t::code_section_t *code_section) {
  if (code_section && code_section->bodies()) {
    std::cout << " (code section with " << code_section->bodies()->size() << " function bodies)";
    for (size_t j = 0; j < code_section->bodies()->size(); ++j) {
      const auto &body = code_section->bodies()->at(j);
      std::cout << std::endl << "    Function body " << j << " (" << body->body_size()->value() << " bytes)" << std::endl;
      std::cout << "      locals: " << body->data()->local_count()->value();
      if (body->data()->local_count()->value() > 0) {
        std::cout << " [ ";
        for (size_t k = 0; k < static_cast<size_t>(body->data()->local_count()->value()); ++k) {
          if (k > 0)
            std::cout << ", ";
          std::cout << static_cast<int>(body->data()->locals()->at(k)->count()->value()) << " x "
                    << static_cast<int>(body->data()->locals()->at(k)->type());
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
}

void Dissector::dissect(std::vector<uint8_t> bytecode) {
  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  webassembly_t wasm(&ks);

  std::cout << "Magic : " << wasm.magic() << " (" << wasm.magic().size() << " bytes)" << std::endl;
  std::cout << "WASM version: " << wasm.version() << std::endl;

  // iterate over sections
  auto sections = wasm.sections();
  const auto &section_items = *(sections->sections());
  for (size_t i = 0; i < section_items.size(); ++i) {
    const auto &section = section_items.at(i);
    std::cout << "  Section " << i << ": id=" << section->header()->id() << " size=" << section->header()->payload_len()->value() << " bytes";
    if (section->header()->id() == 0x0a) {
      // Section 0x0a is the code section; payload_data should be cast to webassembly_t::code_section_t
      auto code_section = dynamic_cast<webassembly_t::code_section_t *>(section->payload_data());
      dissectCodeSection(code_section);
    }
    std::cout << std::endl;
  }
  std::cout << std::endl; // Implementation of the dissect method
}
