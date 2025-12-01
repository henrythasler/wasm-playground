#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "elfwriter.hpp"
#include "helper.hpp"

namespace {

TEST(objdump, wasm) {
  std::vector<std::string> wasmFiles = {"abs",       "arithmetic.0", "arithmetic.1",   "bit",      "block-extended", "block.0",
                                        "branch",    "compare",      "conditionals.0", "division", "echo",           "empty-fn",
                                        "functions", "local.0",      "local.1",        "local.2",  "loop.0"};

  for (const auto &wasmFile : wasmFiles) {
    auto wasmModule = helper::loadModule(wasmFile + ".wasm");
    std::vector<uint32_t> machinecode = wasmModule.getMachinecode();

    ELFWriter::ELFWriter writer;
    writer.add_code(reinterpret_cast<const uint8_t *>(machinecode.data()), machinecode.size() * sizeof(uint32_t));

    for(auto builtin : wasmModule.getBuiltins()) {
      writer.add_symbol(builtin->name, builtin->machinecodeOffset, builtin->machinecodeSize * sizeof(uint32_t));
    }

    for (auto function : wasmModule.getWasmFunctions()) {
      writer.add_symbol(function->getName(), wasmModule.getFunctionOffset(function->getName()), function->getMachinecodeSize() * sizeof(uint32_t));
    }
    writer.write_elf(wasmFile + ".o");
  }
}

} // namespace