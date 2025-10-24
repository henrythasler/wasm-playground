cmake_minimum_required(VERSION 3.20)

# Define the tiny-modules library, STATIC means it will be a static library
add_library(tiny_modules STATIC
    loader.cpp
    module.cpp
    function.cpp
    runtime.cpp
    wasm-dissector.cpp
    aarch64-instructions.cpp
)

# set compiler options for warnings and treat warnings as errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic  -Wformat=2 -Wformat-security -Werror=format-security -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Wfloat-equal -Wmissing-include-dirs  -Wredundant-decls -Wshadow -Wsign-conversion -Wswitch -Wuninitialized -Wunused-parameter -Walloca -Wunused-result -Wunused-local-typedefs -Wwrite-strings -Wpointer-arith -Wfloat-conversion -Wnull-dereference -Wdiv-by-zero -Wswitch-default -Wno-switch-bool -Wunknown-pragmas -Werror")

target_include_directories(tiny_modules PUBLIC 
    ../kaitai
)

target_link_libraries(tiny_modules PRIVATE kaitai)
