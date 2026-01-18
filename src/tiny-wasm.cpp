#include <csignal>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

#include "colors.hpp"
#include "loader.hpp"
#include "module.hpp"
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
  // tiny::WasmModule assembler = tiny::WasmModule();

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

  tiny::WasmModule *wasmModule = nullptr;

  /**
   * Compile the module
   */
  try {
    wasmModule = new tiny::WasmModule(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Assembly failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Functions: " << wasmModule->getNumFunctions() << std::endl;

  /**
   * print some infos about each function before executing it
   */
  auto machinecode = wasmModule->getMachinecode();
  for (auto function : wasmModule->getWasmFunctions()) {
    std::cout << "  " << function->getResultString() << " " << function->getName() << "(" << function->getParameterString() << ")" << std::endl;
    // auto machinecode = function->getMachinecode();
    // if (machinecode.size() == 0) {
    //   std::cout << YELLOW << "WARNING: Machinecode is empty!" << RESET << std::endl;
    // } else {
    //   std::cout << "  Machinecode (hex): " << std::hex;
    //   for (const auto instruction : machinecode) {
    //     std::cout << std::setw(8) << std::setfill('0') << instruction << " ";
    //   }
    //   std::cout << std::dec << std::endl;
    // }

    /* execute machine code */
    if (!dry_run) {
      // std::cout << "  Executing machine code (break *0x" << machinecode.data() << ")... ";
      // auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(
      //     machinecode, wasmModule->getFunctionOffset(function->getName()));
      auto wasmFunction =
          tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(*wasmModule, function->getName());
      try {
        std::cout << std::hex << "executableMemoryAddress: content=0x" << executableMemoryAddress << " location=0x" << &executableMemoryAddress
                  << std::dec << std::endl;

        auto res = wasmFunction.call(0, 10, 20);
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
