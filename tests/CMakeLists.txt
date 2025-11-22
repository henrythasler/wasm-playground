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

# Find wat2wasm tool
find_program(WAT2WASM_EXECUTABLE wat2wasm)
if(NOT WAT2WASM_EXECUTABLE)
  message(FATAL_ERROR "wat2wasm not found. Please install wabt tools.")
else()
  message(STATUS "Found wat2wasm: ${WAT2WASM_EXECUTABLE}")
endif()

# compile all wat-files in wasm-folder to wasm using wat2wasm if not already done
file(GLOB WAT_FILES "${CMAKE_CURRENT_SOURCE_DIR}/assets/*.wat")
foreach(WAT_FILE ${WAT_FILES})
  get_filename_component(WAT_FILENAME ${WAT_FILE} NAME_WE)
  set(WASM_FILE "${CMAKE_CURRENT_SOURCE_DIR}/assets/${WAT_FILENAME}.wasm")
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


## convert wast spectest files
# Find wast2json tool
find_program(WAST2JSON_EXECUTABLE wast2json)
if(NOT WAST2JSON_EXECUTABLE)
  message(FATAL_ERROR "wast2json not found. Please install wabt tools.")
else()
  message(STATUS "Found wast2json: ${WAST2JSON_EXECUTABLE}")
endif()

# compile all wat-files in wasm-folder to wasm using wat2wasm if not already done
file(GLOB WAST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/assets/*.wast")
foreach(WAST_FILE ${WAST_FILES})
  get_filename_component(WAST_FILENAME ${WAST_FILE} NAME_WE)
  set(JSON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/assets/${WAST_FILENAME}.json")
  if(NOT EXISTS ${JSON_FILE} OR ${WAST_FILE} IS_NEWER_THAN ${JSON_FILE})
    add_custom_command(
      OUTPUT ${JSON_FILE}
      COMMAND ${WAST2JSON_EXECUTABLE} ${WAST_FILE} -o ${JSON_FILE}
      DEPENDS ${WAST_FILE}
      COMMENT "Compiling ${WAST_FILE}"
      VERBATIM
    )
    list(APPEND GENERATED_WAST_FILES ${JSON_FILE})
  endif()
endforeach()

if(GENERATED_WAST_FILES)
  add_custom_target(compile_wast_files ALL DEPENDS ${GENERATED_WAST_FILES})
  message(STATUS "Added custom target to compile wast files: ${GENERATED_WAST_FILES}")
endif()

add_executable(all_tests
  # test helper
  helper.cpp
  # support function tests
  loader_test.cpp
  leb128_test.cpp
  # aarch64 instruction encoder tests
  instructions_test.cpp
  # tutorial chapters (in sequence)
  empty_test.cpp
  local_test.cpp
  arithmetic_test.cpp
  conditionals_test.cpp
  division_test.cpp
  block_test.cpp
  loop_test.cpp
  # additional test cases
  echo_test.cpp
  compare_test.cpp
  branch_test.cpp
  block_extended_test.cpp
  bit_test.cpp
)

# GoogleTest requires at least C++17
set_target_properties(all_tests PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)

# Remove sanitizer flags from test target
target_compile_options(all_tests PRIVATE -fno-sanitize=all)
# target_link_options(loader_test PRIVATE -fno-sanitize=all)  # project is compiled with -fsanitize=address so linking without it will cause issues

target_include_directories(all_tests PRIVATE 
  ${CMAKE_ROOT_DIR}/src
)

target_link_libraries(all_tests PRIVATE
  tiny_modules
  kaitai_struct_cpp_stl_runtime
  GTest::gtest_main
  GTest::gmock
)

add_test(NAME all_tests COMMAND all_tests)

if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Enabling coverage collection.")
    target_compile_options(all_tests PRIVATE --coverage -O0 -g)
    target_link_options(all_tests PRIVATE --coverage)    
endif()