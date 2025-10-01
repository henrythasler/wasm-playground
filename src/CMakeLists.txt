add_executable(tiny-wasm 
  tiny-wasm.cpp
  kaitai/webassembly.cpp
  kaitai/vlq_base128_le.cpp
)

target_compile_features(tiny-wasm PRIVATE cxx_std_14)

add_subdirectory(modules)

target_include_directories(tiny-wasm PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/modules
  ${CMAKE_CURRENT_SOURCE_DIR}/kaitai
  )

# Make the generated version.hpp available to the project, PRIVATE means only this target can see it
target_include_directories(tiny-wasm PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


# Link against the tiny-modules library
target_link_libraries(tiny-wasm 
  tiny-modules
  kaitai_struct_cpp_stl_runtime
)