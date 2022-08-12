#include "C1.hpp"

void C1::foo(FunctionRef<void(int)> &callback) { callback(5); }