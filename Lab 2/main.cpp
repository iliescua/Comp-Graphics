#include <iostream>

#include "matrix.h"

using namespace std;

int main(void) {
  // test our matrix, valgrind should not find
  // any memory leaks

  matrix m1(3, 3);

  matrix m2 = matrix::identity(3);

  matrix m3(1, 6);

  m1 = m3;

  matrix m4 = m3;
  matrix m5(m1);
  return 0;
}