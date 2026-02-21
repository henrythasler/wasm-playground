#pragma once
#include <iostream>

#include "helper.hpp"

namespace env {
int32_t inc(int32_t num);
}

namespace api {
class ImportedFunction {
private:
  int32_t index_;
  std::string moduleName_;
  std::string functionName_;
  std::uintptr_t functionAddress_;

public:
  ImportedFunction(const int32_t index, const std::string &moduleName, const std::string &functionName, std::uintptr_t functionAddress)
      : index_(index), moduleName_(moduleName), functionName_(functionName), functionAddress_(functionAddress) {
  }
  ~ImportedFunction() = default;
  std::uintptr_t getAddress() const {
    return functionAddress_;
  }
};

std::uintptr_t getApiFunction(const std::string &moduleName, const std::string &functionName);
} // namespace api