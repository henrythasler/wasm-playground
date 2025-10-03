# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# disable address sanitizer for tests
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize=address")

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

target_link_libraries(loader_test
  GTest::gtest_main
)

add_test(NAME loader_test COMMAND loader_test)
