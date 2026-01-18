#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

TEST(functions, basic) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto caller = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "basic");
  auto callee = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "one");

  EXPECT_EQ(callee(), 1);
  EXPECT_EQ(caller(), 1);
}

TEST(functions, jump_back) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "back");

  EXPECT_EQ(wasmFunction(), 1);
}

TEST(functions, save_regs) {
  auto wasmModule = helper::loadModule("functions.wasm");
  auto machinecode = wasmModule.getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t>(wasmModule, "four");

  EXPECT_EQ(wasmFunction(), 4);
}

TEST(functions_indirect, calculate) {
  auto wasmModule = helper::loadModule("functions_indirect.wasm");
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(wasmModule, "calculate");

  EXPECT_EQ(wasmFunction(0, 10, 20), 30);
  EXPECT_EQ(wasmFunction(1, 10, 20), 200);

  // Test for indirect call to uninitialized table entry (4)
  EXPECT_THROW(
      {
        try {
          wasmFunction(4, 0, 0);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::IndirectCallToNull);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);
      
  // Test for indirect call to function with wrong signature (square function has signature (i32) -> i32)
  EXPECT_THROW(
      {
        try {
          wasmFunction(2, 20, 0);
        } catch (const std::system_error &e) {
          EXPECT_EQ(static_cast<wasm::trap_code_t>(e.code().value()), wasm::trap_code_t::BadSignature);
          throw; // Re-throw for EXPECT_THROW to catch
        }
      },
      std::system_error);

}

} // namespace