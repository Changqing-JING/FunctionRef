#ifndef C1_HPP
#define C1_HPP

#include "FunctionRef.hpp"

class C1{
public:
    void foo(FunctionRef<void(int)>& callback);
};

#endif