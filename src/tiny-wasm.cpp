#include <iomanip>
#include <iostream>
#include <vector>

#include "colors.hpp"
#include "tiny-assembler.hpp"
#include "tiny-loader.hpp"
#include "version.hpp"
#include "webassembly.h"

int main(int argc, char const *argv[]) {
  std::cerr << "Tiny WebAssembly Runtime for ARM64 (v" << PROJECT_VERSION << ")" << std::endl << std::endl;

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <wasm_file>" << std::endl;
    return EXIT_FAILURE;
  }

  tiny::Loader loader = tiny::Loader();
  tiny::Assembler assembler = tiny::Assembler();

  // Load WebAssembly file from command line argument
  std::cout << "Loading WebAssembly file: '" << CYAN << argv[1] << RESET << "'... ";
  if (!loader.loadFromFile(argv[1])) {
    std::cerr << RED << "Error: Failed to load file " << argv[1] << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << GREEN "OK" << RESET << std::endl;

  // Get loaded bytecode
  std::vector<uint8_t> bytecode = loader.getBytecode();
  std::cout << "Bytecode size: " << bytecode.size() << " bytes" << std::endl;
  std::cout << "Bytecode (hex): ";
  for (uint8_t byte : bytecode) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << std::endl << std::endl;

  kaitai::kstream ks(std::string(bytecode.begin(), bytecode.end()));
  webassembly_t wasm(&ks);

  std::cout << "Magic : " << wasm.magic() << std::endl;
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
      if (code_section && code_section->bodies()) {
        std::cout << " (code section with " << code_section->bodies()->size() << " function bodies)";
        for (size_t j = 0; j < code_section->bodies()->size(); ++j) {
          const auto &body = code_section->bodies()->at(j);
          std::cout << std::endl << "    Function body " << j << " (" << body->body_size()->value() << " bytes)" << std::endl;
          std::cout << "      locals: " << body->data()->local_count()->value();
          if (body->data()->local_count()->value() > 0) {
            std::cout << " [ ";
            for (size_t k = 0; k < body->data()->local_count()->value(); ++k) {
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
    std::cout << std::endl;
  }
  std::cout << std::endl;

  // Assemble bytecode to machine code
  std::vector<uint8_t> machinecode = assembler.assemble(bytecode);
  std::cout << "Machinecode size: " << machinecode.size() << " bytes" << std::endl;

  if (machinecode.size() == 0) {
    std::cout << YELLOW << "WARNING: Assembler not implemented, machinecode is empty!" << RESET << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Machinecode (hex): ";
  for (uint8_t byte : machinecode) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << std::endl;

  return EXIT_SUCCESS;
}
