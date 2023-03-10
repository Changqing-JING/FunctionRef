#include "C1.hpp"
#include "FunctionRef.hpp"
#include <cstdio>

int main() {
  C1 c1;
  int x = 10;
  int y = 20;
  auto const fx = [x](int m) {
    int sum = m + x;
    printf("foo %d\n", sum);
  };

  auto yx = [y](int m) {
    int sum = m + y;
    printf("foo %d\n", sum);
  };

  vb::FunctionRef<void(int)> rfx(fx);
  vb::FunctionRef<void(int)> ryx(yx);

  c1.foo(rfx);
  c1.foo(ryx);

  return 0;
}