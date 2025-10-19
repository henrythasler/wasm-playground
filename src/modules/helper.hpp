#pragma once
#include <stdexcept>
#define assertm(exp, msg) assert((void(msg), exp))
#define asserte(exp, msg)                                                                                                                            \
  if (!(exp))                                                                                                                                        \
    throw std::runtime_error(msg);
