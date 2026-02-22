#include "api-functions.hpp"

namespace env {
int32_t inc(int32_t num) {
  std::cout << "env.inc called with argument: " << num << std::endl;
  return num + 1;
}

int myPrintf(const char *format, const void *args_buffer) {
  const char *actualArgsBuffer =
      reinterpret_cast<const char *>(reinterpret_cast<uintptr_t>(args_buffer) + static_cast<uintptr_t>(gLinearMemoryInfo.address));
  api::NaturalAlignedArgReader reader(actualArgsBuffer);

  // debug: print raw arguments from buffer
  // for (auto i = 0; i < 8; i++) {
  //   std::cout << std::hex << "arg[" << i << "]: "
  //             << *(reinterpret_cast<uint32_t *>(reinterpret_cast<uintptr_t>(actualArgsBuffer) + reinterpret_cast<uintptr_t>(i * sizeof(uint32_t))))
  //             << std::dec << std::endl;
  // }

  const char *p = format + gLinearMemoryInfo.address;
  char output[4096];
  char *out = output;

  // FIXME: avoid out-of-memory writes to output buffer when format string is too long or has too many arguments
  while (*p) {
    if (*p == '%' && *(p + 1)) {
      p++;
      switch (*p) {
      case 'p': {
        int32_t val = reader.read_int32();
        out += sprintf(out, "%p", reinterpret_cast<void *>(val + gLinearMemoryInfo.address));
        break;
      }
      case 's': {
        int32_t val = reader.read_int32();
        out += sprintf(out, "%s", reinterpret_cast<const char *>(val + gLinearMemoryInfo.address));
        break;
      }
      case 'c': {
        int32_t val = reader.read_int32();
        out += sprintf(out, "%c", val);
        break;
      }
      case 'i': {
        int32_t val = reader.read_int32();
        out += sprintf(out, "%i", val);
        break;
      }
      case 'd': {
        int32_t val = reader.read_int32();
        out += sprintf(out, "%d", val);
        break;
      }
      case 'u': {
        uint32_t val = reader.read_uint32();
        out += sprintf(out, "%u", val);
        break;
      }
      case 'l': {
        if (*(p + 1) == 'u') {
          p++;
          uint64_t val = reader.read_uint64();
          out += sprintf(out, "%lu", val);
        } else if (*(p + 1) == 'd' || *(p + 1) == 'l') {
          p++;
          if (*p == 'l' && *(p + 1) == 'd') {
            p++;
            int64_t val = reader.read_int64();
            out += sprintf(out, "%ld", val);
          } else if (*p == 'l' && *(p + 1) == 'u') {
            p++;
            uint64_t val = reader.read_uint64();
            out += sprintf(out, "%lu", val);
          } else if (*p == 'l' && (*(p + 1) == 'x' || *(p + 1) == 'X')) {
            p++;
            int64_t val = reader.read_int64();
            out += sprintf(out, "%lX", val);
          }
        }
        break;
      }
      case '%':
        *out++ = '%';
        break;
      }
    } else {
      *out++ = *p;
    }
    p++;
  }
  *out = '\0';

  return fprintf(stdout, "%s", output);
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