#ifndef C1_HPP
#define C1_HPP

#include "FunctionRef.hpp"

class C1 {
public:
  void foo(vb::FunctionRef<void(int)> &callback);
};

#endif