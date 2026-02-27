#include <csignal>
#include <cstdint>
#include <cstring>
#include <filesystem>
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

  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <wasm_file> <function>" << std::endl;
    return EXIT_FAILURE;
  }

  auto fileName = std::string(argv[argc - 2]);
  auto functionName = std::string(argv[argc - 1]);

  std::cout << "Loading WebAssembly file: '" << CYAN << fileName << RESET << "'... ";

  tiny::Loader loader = tiny::Loader();

  // Load WebAssembly file from command line argument
  if (!loader.loadFromFile(fileName)) {
    std::cerr << RED << "Error: Failed to load file " << fileName << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << GREEN "OK" << RESET << std::endl;

  // Get loaded bytecode
  std::vector<uint8_t> bytecode = loader.getBytecode();
  std::cout << "Bytecode size: " << bytecode.size() << " bytes" << std::endl;
  // std::cout << "Bytecode (hex): ";
  // for (uint8_t byte : bytecode) {
  //   std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
  // }
  // std::cout << std::dec << std::endl << std::endl;

  try {
    tiny::Dissector::dissect(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Dissection failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }

  std::unique_ptr<tiny::WasmModule> wasmModule;

  /**
   * Compile the module
   */
  try {
    wasmModule = std::make_unique<tiny::WasmModule>(bytecode);
  } catch (const std::exception &e) {
    std::cerr << RED << "Error: Assembly failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Functions: " << wasmModule->getNumFunctions() << std::endl;

  /**
   * print some infos about each function before executing it
   */
  // auto machinecode = wasmModule->getMachinecode();
  for (auto function : wasmModule->getWasmFunctions()) {
    std::cout << "  " << function->getResultString() << " " << function->getName() << "(" << function->getParameterString() << ")" << std::endl;
  }

  std::cout << std::endl << "Preparing execution of '" << functionName << "()' " << std::endl;

  tiny::ModuleInstance instance(*wasmModule);
  auto wasmFunction = instance.getFunction<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(functionName);

  std::cout << "  " << std::hex << "objectPointer: content=0x" << gRuntimeInfo.objectPointer << " location=0x" << &gRuntimeInfo.objectPointer
            << " wasmFunction=0x" << &wasmFunction << std::dec << std::endl;

  std::cout << "  " << std::hex << "linearMemoryGrowAddress: content=0x" << gLinearMemoryInfo.growFunctionAddress << " location=0x"
            << &gLinearMemoryInfo.growFunctionAddress << std::dec << std::endl;

  std::cout << "  " << std::hex << "machineCodeAddress: content=0x" << gRuntimeInfo.machineCodeAddress << " location=0x"
            << &gRuntimeInfo.machineCodeAddress << std::dec << std::endl;

  std::cout << "  " << std::hex << "globalsMemoryAddress: content=0x" << gRuntimeInfo.globalsMemoryAddress << " location=0x"
            << &gRuntimeInfo.globalsMemoryAddress << std::dec << std::endl;

  std::cout << "  " << std::hex << "linearMemorySizeBytes: content=0x" << gLinearMemoryInfo.sizeBytes << " location=0x"
            << &gLinearMemoryInfo.sizeBytes << std::dec << std::endl;

  std::cout << "  " << std::hex << "stackBaseAddress: content=0x" << gRuntimeInfo.stackBaseAddress << " location=0x" << &gRuntimeInfo.stackBaseAddress
            << std::dec << std::endl;

  if (wasmModule->getMemory()) {
    std::cout << "  " << std::hex << "linearMemoryAddress: content=0x" << gLinearMemoryInfo.address << " location=0x" << &gLinearMemoryInfo.address
              << std::dec << " size=" << wasmModule->getMemory()->initialSize * wasm::LINEAR_MEMORY_PAGE_SIZE << std::endl;
  }

  try {
    auto res = wasmFunction(0x123456789ABCDEF0LLU, 0x0000FFFF00000000LLU);
    std::cout << "result: " << std::hex << res << " " << std::endl;
  } catch (const std::exception &e) {
    std::cerr << RED << "Execution failed: " << e.what() << RESET << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << GREEN "done" << RESET << std::endl << std::endl;

  return EXIT_SUCCESS;
}
