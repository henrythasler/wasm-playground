#pragma once
#include <iostream>
#include <vector>

#include "helper.hpp"
#include "webassembly.h"

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