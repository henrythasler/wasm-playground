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

TEST(division, unsigned32) {
  auto wasmModule = helper::loadModule("division.wasm");
  auto machinecode = wasmModule.getWasmFunction("div_u32")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i32_t, wasm::wasm_i32_t, wasm::wasm_i32_t>(machinecode);
  helper::dump("division.div_u32.bin", machinecode);

  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0x80000000, 2), 0x40000000);
  EXPECT_EQ(wasmFunction(0x80000001, 1000), 0x20c49b);
  EXPECT_EQ(wasmFunction(5, 2), 2);
  EXPECT_EQ(wasmFunction(7, 3), 2);
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
}

TEST(division, signed64) {
  auto wasmModule = helper::loadModule("division.wasm");
  auto machinecode = wasmModule.getWasmFunction("div_s64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("division.div_s64.bin", machinecode);

  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0, -1), 0);
  EXPECT_EQ(wasmFunction(-1, -1), 1);
  EXPECT_EQ(wasmFunction(0x8000000000000000, 2), 0xc000000000000000);
  EXPECT_EQ(wasmFunction(0x8000000000000001, 1000), 0xffdf3b645a1cac09);
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

  EXPECT_THAT([&]{wasmFunction(0x8000000000000000, 0);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerDivisionByZero)))
    )
  ));

  EXPECT_THAT([&]{wasmFunction(0x8000000000000000, -1);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerOverflow)))
    )
  ));  
}

TEST(division, unsigned64) {
  auto wasmModule = helper::loadModule("division.wasm");
  auto machinecode = wasmModule.getWasmFunction("div_u64")->getMachinecode();
  auto wasmFunction = tiny::make_wasm_function<wasm::wasm_i64_t, wasm::wasm_i64_t, wasm::wasm_i64_t>(machinecode);
  helper::dump("division.div_u64.bin", machinecode);

  EXPECT_EQ(wasmFunction(1, 1), 1);
  EXPECT_EQ(wasmFunction(0, 1), 0);
  EXPECT_EQ(wasmFunction(0x8000000000000000, 2), 0x4000000000000000);
  EXPECT_EQ(wasmFunction(0x8000000000000001, 1000), 0x20c49ba5e353f7);
  EXPECT_EQ(wasmFunction(5, 2), 2);
  EXPECT_EQ(wasmFunction(7, 3), 2);
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

  EXPECT_THAT([&]{wasmFunction(0x8000000000000000, 0);}, Throws<std::system_error>(
    Property(&std::system_error::code,
      Property(&std::error_code::value, Eq(int32_t(wasm::trap_code_t::IntegerDivisionByZero)))
    )
  ));
}

} // namespace testing