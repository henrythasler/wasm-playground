cmake_minimum_required(VERSION 3.20)
project(tiny-wasm
    VERSION 0.1.0
    DESCRIPTION "Tiny WebAssembly Runtime for ARM64"
    LANGUAGES CXX
    HOMEPAGE_URL "https://github.com/henrythasler/wasm-playground"
    )

function(CLANG_TIDY ENABLED)
  if(ENABLED)
    message(STATUS "Enabling clang-tidy static analysis")
    set(CMAKE_CXX_CLANG_TIDY
        clang-tidy
        --config-file ${CMAKE_CURRENT_LIST_DIR}/.clang-tidy
        "--header-filter=${CMAKE_CURRENT_LIST_DIR}/(src|tests)/.*"
        --extra-arg=-isystem/usr/aarch64-linux-gnu/include/c++/11
        --extra-arg=-isystem/usr/aarch64-linux-gnu/include/c++/11/aarch64-linux-gnu
        --extra-arg=-isystem/usr/aarch64-linux-gnu/include
        --extra-arg=-isystem/usr/lib/gcc-cross/aarch64-linux-gnu/11/include
    )
  else()
    message(STATUS "Disabling clang-tidy static analysis")
    set(CMAKE_CXX_CLANG_TIDY "")
  endif()
endfunction()

# Find wat2wasm tool
find_program(WAT2WASM_EXECUTABLE wat2wasm)
if(NOT WAT2WASM_EXECUTABLE)
  message(FATAL_ERROR "wat2wasm not found. Please install wabt tools.")
else()
  message(STATUS "Found wat2wasm: ${WAT2WASM_EXECUTABLE}")
endif()

# compile all wat-files in wasm-folder to wasm using wat2wasm if not already done
file(GLOB WAT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/wasm/*.wat")
foreach(WAT_FILE ${WAT_FILES})
  get_filename_component(WAT_FILENAME ${WAT_FILE} NAME_WE)
  set(WASM_FILE "${CMAKE_CURRENT_SOURCE_DIR}/wasm/${WAT_FILENAME}.wasm")
  if(NOT EXISTS ${WASM_FILE} OR ${WAT_FILE} IS_NEWER_THAN ${WASM_FILE})
    add_custom_command(
      OUTPUT ${WASM_FILE}
      COMMAND ${WAT2WASM_EXECUTABLE} ${WAT_FILE} -o ${WASM_FILE}
      DEPENDS ${WAT_FILE}
      COMMENT "Compiling ${WAT_FILE} to ${WASM_FILE}"
      VERBATIM
    )
    list(APPEND GENERATED_WASM_FILES ${WASM_FILE})
  endif()
endforeach()

if(GENERATED_WASM_FILES)
  add_custom_target(generate_wasm_files ALL DEPENDS ${GENERATED_WASM_FILES})
  message(STATUS "Added custom target to generate wasm files: ${GENERATED_WASM_FILES}")
endif()

option(ENABLE_CLANG_TIDY "Enable clang-tidy static analysis" ON)
option(ENABLE_UNITTEST "Enable unit tests" ON)
option(ENABLE_ARM64_CROSSCOMPILE "Enable arm64 (aarch64) cross-compilation" ON)

# set C++ standard to C++14
set (CMAKE_CXX_STANDARD 14)

# set compiler options to include debug info
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")

# enable address sanitizer
cmake_host_system_information(RESULT DISTRIB_VERSION_ID QUERY DISTRIB_VERSION_ID)
cmake_host_system_information(RESULT DISTRIB_ID QUERY DISTRIB_ID)
message(STATUS "${DISTRIB_ID}: ${DISTRIB_VERSION_ID}")
if((DISTRIB_ID STREQUAL "ubuntu") AND (DISTRIB_VERSION_ID STREQUAL "24.04"))
  message(STATUS "Disabling address sanitizer for ${DISTRIB_ID} ${DISTRIB_VERSION_ID}")
else()
  message(STATUS "Enabling address sanitizer")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif()

# Add Kaitai runtime dependency
CLANG_TIDY(OFF)  # disable clang-tidy
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)  # Disable building tests for kaitai runtime
add_subdirectory(extern/kaitai_struct_cpp_stl_runtime)
CLANG_TIDY(${ENABLE_CLANG_TIDY})  # re-enable clang-tidy

# Add  the main source directory
add_subdirectory(src)

# Generate version.hpp from version.hpp.in containing the project version
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/src/version.hpp.in
  ${CMAKE_CURRENT_BINARY_DIR}/src/version.hpp
  @ONLY
)

if(ENABLE_UNITTEST)
  # Add the tests directory
  enable_testing()
  add_subdirectory(tests)
else()
  message(STATUS "Unit tests are disabled!")
endif()
