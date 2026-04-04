// C17050103_meaning_of_copy.cpp 
#include <iostream>

namespace problem_of_default_copy_constructor {
  struct S {
    int* p;     // a pointer
  };

  S x{new int{0}};

  void f() {
    S y{x};             // "copy" x
    *y.p = 1;           // change y; affect x
    *x.p = 2;           // change x; affect y
    delete y.p;         // affects both x and y
    y.p = new int{3};   // OK: change y; does not affect x
    *x.p = 4;           // oops: write to deallocated memory
  }
}

int main() {
  problem_of_default_copy_constructor::f();
}
