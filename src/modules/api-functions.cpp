#include "api-functions.hpp"

namespace env {
int32_t inc(int32_t num) {
  std::cout << "env.inc called with argument: " << num << std::endl;
  return num + 1;
}

// int myPrintf(uintptr_t msgPtr, int32_t msgLength) {
int myPrintf(const char *msgPtr, void *args_offset) {
  // std::cout << std::hex << "env.myPrintf called with msgPtr: " << format << " msgLength: " << msgLength << std::dec << std::endl;
  // add offset of linear memory to pointer to get actual address of string
  const char *actualMsgPtr = reinterpret_cast<const char *>(msgPtr + gLinearMemoryInfo.address);

  va_list args;
  *(void **)&args = args_offset + gLinearMemoryInfo.address;

  std::cout << "Actual message pointer: " << static_cast<const void *>(actualMsgPtr) << std::endl;
  for (auto i = 0; i < 8; i++) {
    std::cout << std::hex << "arg[" << i << "]: " << *(reinterpret_cast<uint32_t *>(args_offset + gLinearMemoryInfo.address + i * sizeof(uint32_t)))
              << std::dec << std::endl;
  }

  int result = vprintf(actualMsgPtr, args);
  return result;
  return 0;
}
} // namespace env

namespace api {
std::uintptr_t getApiFunction(const std::string &moduleName, const std::string &functionName) {
  if (moduleName == "env") {
    if (functionName == "inc") {
      return reinterpret_cast<std::uintptr_t>(&env::inc);
    } else if (functionName == "myPrintf") {
      return reinterpret_cast<std::uintptr_t>(&env::myPrintf);
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