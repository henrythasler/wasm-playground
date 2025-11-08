#include <filesystem>
#include <fstream>
#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/loader.hpp"
#include "../src/modules/module.hpp"
#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace testing {

TEST(division, signed32) {
  auto wasmModule = helper::loadModule("division.wasm");
  auto machinecode = wasmModule.getWasmFunction("div_s32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("division.div_s32.bin", machinecode);

  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0, -1), 0);
  EXPECT_EQ(wasmFunction(-1, -1), 1);
  EXPECT_EQ(wasmFunction(0x80000000, 2), 0xc0000000);
  EXPECT_EQ(wasmFunction(0x80000001, 1000), 0xffdf3b65);
  EXPECT_EQ(wasmFunction(5, 2), 2);
  EXPECT_EQ(wasmFunction(-5, 2), -2);
  EXPECT_EQ(wasmFunction(5, -2), -2);
  EXPECT_EQ(wasmFunction(-5, -2), 2);
  EXPECT_EQ(wasmFunction(7, 3), 2);
  EXPECT_EQ(wasmFunction(-7, 3), -2);
  EXPECT_EQ(wasmFunction(7, -3), -2);
  EXPECT_EQ(wasmFunction(-7, -3), 2);
  EXPECT_EQ(wasmFunction(11, 5), 2);
  EXPECT_EQ(wasmFunction(17, 7), 2);

  EXPECT_THAT([&]{wasmFunction(1, 0);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerDivisionByZero)))
    )
  ));

  EXPECT_THAT([&]{wasmFunction(0, 0);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerDivisionByZero)))
    )
  ));  

  EXPECT_THAT([&]{wasmFunction(0x80000000, 0);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerDivisionByZero)))
    )
  ));

  EXPECT_THAT([&]{wasmFunction(0x80000000, -1);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerOverflow)))
    )
  ));  
}

} // namespace testing