#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"

#include "helper.hpp"
namespace {

TEST(local0, function0) {
  auto wasmModule = helper::loadModule("empty-fn.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<void>(machinecode, wasmModule.getFunctionOffset("foo"));

  wasmFunction();
}

} // namespace