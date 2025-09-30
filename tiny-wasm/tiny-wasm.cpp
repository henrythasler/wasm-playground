#include <iomanip>
#include <iostream>
#include <vector>

#include "modules/colors.hpp"
#include "modules/tiny-loader.hpp"
#include "version.hpp"

int main(int argc, char const *argv[]) {
  std::cerr << "Tiny WebAssembly Runtime for ARM64 (v" << PROJECT_VERSION << ")" << std::endl;

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <wasm_file>" << std::endl;
    return EXIT_FAILURE;
  }

  tiny::Loader loader = tiny::Loader();

  // Load WebAssembly file from command line argument
  std::cout << "Loading WebAssembly file: '" << CYAN << argv[1] << RESET << "'... ";
  if (!loader.loadFromFile(argv[1])) {
    std::cerr << RED << "Error: Failed to load file " << argv[1] << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << GREEN "OK" << RESET << std::endl;

  std::vector<uint8_t> bytecode = loader.getBytecode();
  std::cout << "Bytecode size: " << bytecode.size() << " bytes" << std::endl;
  std::cout << "Bytecode (hex): ";
  for (uint8_t byte : bytecode) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << std::endl;

  return EXIT_SUCCESS;
}
