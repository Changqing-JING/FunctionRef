#include "C1.hpp"

void C1::foo(vb::FunctionRef<void(int)> &callback) { callback(5); }