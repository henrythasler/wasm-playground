#include <csignal>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

#include "assembler.hpp"
#include "colors.hpp"
#include "loader.hpp"
#include "runtime.hpp"
#include "version.hpp"
#include "wasm-dissector.hpp"

int main(int argc, char const *argv[]) {
  std::cerr << "Tiny WebAssembly Runtime for ARM64 (v" << PROJECT_VERSION << ")" << std::endl << std::endl;

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <options> <wasm_file>" << std::endl;
    std::cerr << "Options:" << std::endl;
    std::cerr << "  --dry-run        Assemble but do not execute the code" << std::endl;
    return EXIT_FAILURE;
  }

  tiny::Loader loader = tiny::Loader();
  tiny::Assembler assembler = tiny::Assembler();

  // Parse command line arguments
  // The last argument is always the filename
  // All preceding arguments are options
  auto filename = std::string(argv[argc - 1]);
  bool dry_run = false;
  for (int i = 1; i < argc - 1; ++i) {
    if (std::strcmp(argv[i], "--dry-run") == 0) {
      dry_run = true;
    } else {
      std::cerr << RED << "Error: Unknown option '" << argv[i] << "'" << RESET << std::endl;
      return EXIT_FAILURE;
    }
  }

  // Load WebAssembly file from command line argument
  std::cout << "Loading WebAssembly file: '" << CYAN << filename << RESET << "'... ";
  if (!loader.loadFromFile(filename)) {
    std::cerr << RED << "Error: Failed to load file " << filename << RESET << std::endl;
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
    tiny::Dissector::dissect(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Dissection failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }

  // Assemble bytecode to machine code
  std::vector<tiny::WasmFunction> wasmModule;

  /**
   * Compile the module
   */
  try {
    wasmModule = assembler.compileModule(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Assembly failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Functions: " << wasmModule.size() << std::endl;

  /**
   * print some infos about each function before executing it
   */
  for (tiny::WasmFunction function : wasmModule) {
    std::cout << "  " << function.getResultString() << " " << function.getName() << "(" << function.getParameterString() << ")" << std::endl;
    auto machinecode = function.getBytecode();
    if (machinecode.size() == 0) {
      std::cout << YELLOW << "WARNING: Machinecode is empty!" << RESET << std::endl;
    } else {
      std::cout << "  Machinecode (hex): ";
      for (int32_t i = 0; i < int32_t(machinecode.size() >> 2); i++) {
        // const uint32_t instruction = uint32_t(machinecode.at(size_t((i << 2) + 3)) << 24) + uint32_t(machinecode.at(size_t((i << 2) + 2)) << 16) +
        //                              uint32_t(machinecode.at(size_t((i << 2) + 1)) << 8) + uint32_t(machinecode.at(size_t((i << 2) + 0)));
        const uint32_t instruction = uint32_t(machinecode.at(size_t((i << 2) + 0)) << 24) + uint32_t(machinecode.at(size_t((i << 2) + 1)) << 16) +
                                     uint32_t(machinecode.at(size_t((i << 2) + 2)) << 8) + uint32_t(machinecode.at(size_t((i << 2) + 3)));
        std::cout << std::hex << std::setw(8) << std::setfill('0') << instruction << " ";
      }
      std::cout << std::dec << std::endl;
    }

    /* execute machine code */
    if (!dry_run) {
      std::cout << "  Executing machine code... ";
      auto wasmFunction = tiny::make_wasm_function<tiny::wasm_i32_t>(machinecode);
      try {
        // std::raise(SIGINT);
        auto res = wasmFunction();
        std::cout << res << " ";
      } catch (const std::exception &e) {
        std::cerr << RED << "Execution failed: " << e.what() << RESET << std::endl;
        return EXIT_FAILURE;
      }
    } else {
      std::cout << "  Dry run mode, skipping execution... ";
    }

    std::cout << GREEN "done" << RESET << std::endl << std::endl;
  }

  return EXIT_SUCCESS;
}
