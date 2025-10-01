add_executable(tiny_wasm 
  tiny-wasm.cpp
  kaitai/webassembly.cpp
  kaitai/vlq_base128_le.cpp
)
set_target_properties(tiny_wasm PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(modules)

target_include_directories(tiny_wasm PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/modules
  ${CMAKE_CURRENT_SOURCE_DIR}/kaitai
  )

# Make the generated version.hpp available to the project, PRIVATE means only this target can see it
target_include_directories(tiny_wasm PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


# Link against the tiny-modules library
target_link_libraries(tiny_wasm 
  tiny_modules
  kaitai_struct_cpp_stl_runtime
)