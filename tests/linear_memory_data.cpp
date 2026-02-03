#include <gmock/gmock.h> // This is the key include for EXPECT_THAT
#include <gtest/gtest.h>

#include "../src/modules/runtime.hpp"
#include "helper.hpp"
namespace {

//1
  auto wasmModule = helper::loadModule("linear-memory-data.0.wasm");
//2
  EXPECT_EQ(wasmFunction(0), 0);
//3
  EXPECT_EQ(wasmFunction(0), 0);
//4
  EXPECT_EQ(wasmFunction(0), 0);
//5
  EXPECT_EQ(wasmFunction(0), 0);
//6
  EXPECT_EQ(wasmFunction(0), 0);
//7
  EXPECT_EQ(wasmFunction(0), 0);
//8
  EXPECT_EQ(wasmFunction(0), 0);
//9
  EXPECT_EQ(wasmFunction(0), 0);
//10
  EXPECT_EQ(wasmFunction(0), 0);
//11
  EXPECT_EQ(wasmFunction(0), 0);
//12
  EXPECT_EQ(wasmFunction(0), 0);
//13
  EXPECT_EQ(wasmFunction(0), 0);
//14
  EXPECT_EQ(wasmFunction(0), 0);
//15
  EXPECT_EQ(wasmFunction(0), 0);
//16
  EXPECT_EQ(wasmFunction(0), 0);
//17
  EXPECT_EQ(wasmFunction(0), 0);
//18
  EXPECT_EQ(wasmFunction(0), 0);
//19
  EXPECT_EQ(wasmFunction(0), 0);
//20
  EXPECT_EQ(wasmFunction(0), 0);

} // namespace