#pragma once
#include <execinfo.h>
#include <iostream>
#define assertm(exp, msg) assert((void(msg), exp))
#define asserte(exp, msg)                                                                                                                            \
  if (!(exp))                                                                                                                                        \
    throw std::runtime_error(msg);

void print_backtrace();