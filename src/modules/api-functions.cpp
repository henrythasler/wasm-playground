#include "api-functions.hpp"

namespace env {
int32_t inc(int32_t num) {
  std::cout << "env.inc called with argument: " << num << std::endl;
  return num + 1;
}
} // namespace env

namespace api {
std::uintptr_t getApiFunction(const std::string &moduleName, const std::string &functionName) {
  if (moduleName == "env") {
    if (functionName == "inc") {
      return reinterpret_cast<std::uintptr_t>(&env::inc);
    }
  }
  asserte(false, "getApiFunction(): no API function found for module '" + moduleName + "' and function '" + functionName + "'");
  return 0;
}

void ImportedFunction::processTypes(const std::unique_ptr<webassembly_t::functype_t> &funcType) {
  // evaluate parameters to determine initial stack size
  auto parameterTypes = *funcType->parameters()->valtype();
  for (auto valtype : parameterTypes) {
    parameters.push_back(valtype);
  }

  // copy result types into new vector for easier access later
  auto resultTypes = *funcType->results()->valtype();
  for (auto valtype : resultTypes) {
    results.push_back(valtype);
  }
}
} // namespace api