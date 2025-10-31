cmake_minimum_required(VERSION 3.20)

# Define the tiny-modules library, STATIC means it will be a static library
add_library(kaitai STATIC
    vlq_base128_le.cpp
    webassembly.cpp
)

target_include_directories(kaitai PUBLIC 
    ../../extern/kaitai_struct_cpp_stl_runtime
)

# This depends on kaitai struct library (header only)
target_link_libraries(kaitai PRIVATE kaitai_struct_cpp_stl_runtime)

if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Enabling coverage collection.")
    target_compile_options(kaitai PRIVATE --coverage -O0 -g)
    target_link_options(kaitai PRIVATE --coverage)
endif()