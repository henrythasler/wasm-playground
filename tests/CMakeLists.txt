if(ENABLE_ARM64_CROSSCOMPILE)
  message(STATUS "Enabling ARM64 (aarch64) cross-compilation for unit tests")
  set(CMAKE_CROSSCOMPILING TRUE)

  # Use qemu-aarch64-static for cross-platform execution
  message(STATUS "Using emulator for aarch64")
  set(CMAKE_CROSSCOMPILING_EMULATOR 
      /usr/bin/qemu-aarch64-static
      -L /usr/aarch64-linux-gnu
  )
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(all_tests
  loader_test.cpp
  instructions_test.cpp
  chapter02_test.cpp
  leb128_test.cpp
)

# GoogleTest requires at least C++17
set_target_properties(all_tests PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)

# Remove sanitizer flags from test target
target_compile_options(all_tests PRIVATE -fno-sanitize=all)
# target_link_options(loader_test PRIVATE -fno-sanitize=all)  # project is compiled with -fsanitize=address so linking without it will cause issues

target_include_directories(all_tests PRIVATE 
  ${CMAKE_ROOT_DIR}/src
)

target_link_libraries(all_tests PRIVATE
  tiny_modules
  kaitai_struct_cpp_stl_runtime
  GTest::gtest_main
  GTest::gmock
)

add_test(NAME all_tests COMMAND all_tests)
