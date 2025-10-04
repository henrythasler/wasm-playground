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

add_executable(loader_test
  loader_test.cpp
)

# GoogleTest requires at least C++17
set_target_properties(loader_test PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)

# Remove sanitizer flags from test target
target_compile_options(loader_test PRIVATE -fno-sanitize=all)
# target_link_options(loader_test PRIVATE -fno-sanitize=all)  # project is compiled with -fsanitize=address so linking without it will cause issues

target_include_directories(loader_test PRIVATE 
  ${CMAKE_ROOT_DIR}/src
)

target_link_libraries(loader_test PRIVATE
  tiny_modules  
  GTest::gtest_main
  GTest::gmock
)

add_test(NAME loader_test COMMAND loader_test)
