#include <cstring>
#include <iomanip>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <vector>

#include "colors.hpp"
#include "tiny-assembler.hpp"
#include "tiny-loader.hpp"
#include "version.hpp"
#include "wasm-dissector.hpp"

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

  try {
    Dissector::dissect(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Dissection failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }

  // Assemble bytecode to machine code
  std::vector<uint8_t> machinecode;

  try {
    machinecode = assembler.assemble(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Assembly failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Machinecode size: " << machinecode.size() << " bytes" << std::endl;

  if (machinecode.size() == 0) {
    std::cout << YELLOW << "WARNING: Machinecode is empty!" << RESET << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Machinecode (hex): ";
  for (uint8_t byte : machinecode) {
    std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  }
  std::cout << std::dec << std::endl;

  // execute machine code
  std::cout << "Executing machine code... ";

  size_t page_size = sysconf(_SC_PAGESIZE);
  // Allocate page-aligned memory for executable code; this is required for mprotect as it works on page granularity
  void *exec_mem = aligned_alloc(page_size, ((machinecode.size() + page_size - 1) / page_size) * page_size);

  // Copy code to executable memory region
  memcpy(exec_mem, machinecode.data(), machinecode.size());
  // Make executable
  mprotect(exec_mem, machinecode.size(), PROT_READ | PROT_EXEC);

  // Execute
  auto wasm_module = reinterpret_cast<void (*)()>(exec_mem);
  wasm_module();

  // Cleanup
  free(exec_mem);

  std::cout << GREEN "done" << RESET << std::endl;
  return EXIT_SUCCESS;
}
