#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "helper.hpp"

namespace {

TEST(objdump, wasm) {
  std::vector<std::string> wasmFiles = {"abs",       "arithmetic.0", "arithmetic.1",   "bit",      "block-extended", "block.0",
                                        "branch",    "compare",      "conditionals.0", "division", "echo",           "empty-fn",
                                        "functions", "local.0",      "local.1",        "local.2",  "loop.0"};

  for (const auto &wasmFile : wasmFiles) {
    auto wasmModule = helper::loadModule(wasmFile + ".wasm");
    auto machinecode = wasmModule.getMachinecode();
    helper::dump(wasmFile + ".o", machinecode);
  }
}

} // namespace