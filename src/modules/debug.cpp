#include "debug.hpp"

void print_backtrace() {
  const int max_frames = 100;
  void *frames[max_frames];

  int size = backtrace(frames, max_frames);
  char **symbols = backtrace_symbols(frames, size);

  std::cout << "Stack trace:\n";
  for (int i = 0; i < size; ++i)
    std::cout << symbols[i] << std::endl;

  free(symbols);
}