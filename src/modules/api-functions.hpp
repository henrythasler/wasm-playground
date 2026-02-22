#pragma once
#include <cstdarg>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

#include "debug.hpp"
#include "globals.hpp"
#include "webassembly.h"

namespace env {
int32_t inc(int32_t num);
// int myPrintf(uintptr_t msgPtr, int32_t msgLength);
int myPrintf(const char *format, const void *args_buffer);
} // namespace env

namespace api {

class NaturalAlignedArgReader {
private:
  const uint8_t *buffer;
  size_t offset;

  // Align offset to specified boundary
  void align(size_t alignment) {
    offset = (offset + alignment - 1) & ~(alignment - 1);
  }

public:
  NaturalAlignedArgReader(const void *buf) : buffer(static_cast<const uint8_t *>(buf)), offset(0) {
  }

  int32_t read_int32() {
    align(4); // Natural alignment for int32_t
    int32_t value;
    memcpy(&value, buffer + offset, sizeof(value));
    offset += sizeof(value);
    return value;
  }

  uint32_t read_uint32() {
    align(4); // Natural alignment for uint32_t
    uint32_t value;
    memcpy(&value, buffer + offset, sizeof(value));
    offset += sizeof(value);
    return value;
  }

  int64_t read_int64() {
    align(8); // Natural alignment for int64_t
    int64_t value;
    memcpy(&value, buffer + offset, sizeof(value));
    offset += sizeof(value);
    return value;
  }

  uint64_t read_uint64() {
    align(8); // Natural alignment for uint64_t
    uint64_t value;
    memcpy(&value, buffer + offset, sizeof(value));
    offset += sizeof(value);
    return value;
  }
};

class ImportedFunction {
private:
  int32_t index_;
  std::string moduleName_;
  std::string functionName_;
  std::uintptr_t functionAddress_;
  std::vector<webassembly_t::val_types_t> parameters;
  std::vector<webassembly_t::val_types_t> results;
  void processTypes(const std::unique_ptr<webassembly_t::functype_t> &funcType);

public:
  ImportedFunction(const int32_t index, const std::string &moduleName, const std::string &functionName,
                   const std::unique_ptr<webassembly_t::functype_t> &funcType, std::uintptr_t functionAddress)
      : index_(index), moduleName_(moduleName), functionName_(functionName), functionAddress_(functionAddress) {
    processTypes(funcType);
  }
  ~ImportedFunction() = default;
  std::uintptr_t getAddress() const {
    return functionAddress_;
  }

  const std::vector<webassembly_t::val_types_t> &getResults() {
    return results;
  };

  std::vector<webassembly_t::val_types_t> getParameters() {
    return parameters;
  };
};

std::uintptr_t getApiFunction(const std::string &moduleName, const std::string &functionName);
} // namespace api