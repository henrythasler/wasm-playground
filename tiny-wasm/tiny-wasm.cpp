#include <iostream>
#include <vector>
#include <iomanip>
#include "modules/tiny-loader.hpp"
#include "version.hpp"

int main(int argc, char const *argv[])
{
  std::cerr << "Tiny WebAssembly Runtime for ARM64 (v" << VERSION << ")" << std::endl;

  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <wasm_file>" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Loading WebAssembly file: " << argv[1] << std::endl;
  tiny::Loader loader(argv[1]);
  std::vector<uint8_t> bytecode = loader.getBytecode();

  std::cout << "Loaded bytecode size: " << bytecode.size() << " bytes" << std::endl;
  std::cout << "Bytecode (hex): ";
  for (uint8_t byte : bytecode)
  {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << std::endl;

  return EXIT_SUCCESS;
}
