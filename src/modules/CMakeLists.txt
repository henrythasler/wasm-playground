cmake_minimum_required(VERSION 3.20)

# Define the tiny-modules library, STATIC means it will be a static library
add_library(tiny-modules STATIC
    tiny-loader.cpp
    tiny-assembler.cpp
)