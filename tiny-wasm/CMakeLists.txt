cmake_minimum_required(VERSION 3.20)
project(tiny-wasm
    VERSION 0.1.0
    DESCRIPTION "Tiny WebAssembly Runtime for ARM64"
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/henrythasler/wasm-playground"
    )

# Generate version.hpp from version.hpp.in containing the project version
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/version.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/version.hpp
  @ONLY
)

# specity the target system
set(CMAKE_SYSTEM_NAME Linux)
# specify the target architecture
set(CMAKE_SYSTEM_PROCESSOR aarch64)
# specify the cross compiler
set(CMAKE_CXX_COMPILER /usr/bin/aarch64-linux-gnu-g++)

# set compiler options to statically link the binary and include debug info
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -ggdb3")

add_subdirectory(modules)
add_executable(tiny-wasm tiny-wasm.cpp)

# Make the generated version.hpp available to the project, PRIVATE means only this target can see it
target_include_directories(tiny-wasm PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Link against the tiny-modules library
target_link_libraries(tiny-wasm tiny-modules)
