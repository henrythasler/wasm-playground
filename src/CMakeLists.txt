add_executable(tiny_wasm 
  tiny-wasm.cpp
)
set_target_properties(tiny_wasm PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(modules)
add_subdirectory(kaitai)

# set compiler options for warnings and treat warnings as errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic  -Wformat=2 -Wformat-security -Werror=format-security -Wcast-align -Wcast-qual -Wconversion -Wdouble-promotion -Wfloat-equal -Wmissing-include-dirs  -Wredundant-decls -Wshadow -Wsign-conversion -Wswitch -Wuninitialized -Wunused-parameter -Walloca -Wunused-result -Wunused-local-typedefs -Wwrite-strings -Wpointer-arith -Wfloat-conversion -Wnull-dereference -Wdiv-by-zero -Wswitch-default -Wno-switch-bool -Wunknown-pragmas -Werror")

target_include_directories(tiny_wasm PRIVATE 
  ${CMAKE_CURRENT_SOURCE_DIR}/modules
  )
# Make the generated version.hpp available to the project, PRIVATE means only this target can see it
target_include_directories(tiny_wasm PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Link against the tiny-modules library
target_link_libraries(tiny_wasm 
  tiny_modules
  kaitai
)