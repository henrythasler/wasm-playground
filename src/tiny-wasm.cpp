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
