cmake_minimum_required(VERSION 3.20)

# Define the tiny-modules library, STATIC means it will be a static library
add_library(tiny_modules STATIC
    tiny-loader.cpp
    tiny-assembler.cpp
    tiny-runtime.cpp
    wasm-dissector.cpp
)

target_include_directories(tiny_modules PUBLIC 
    ../kaitai
    ../../extern/kaitai_struct_cpp_stl_runtime/src
)

# This depends on (header only) boost
target_link_libraries(tiny_modules PRIVATE kaitai_struct_cpp_stl_runtime)
