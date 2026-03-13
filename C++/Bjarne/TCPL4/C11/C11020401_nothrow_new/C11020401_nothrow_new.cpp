// C11020401_nothrow_new.cpp 
#include <iostream>

void f(int n) {
  int* p = new(std::nothrow) int[n];    // allocate n ints on the free store
  if(p == nullptr) {    // no memory available
    // ... handle allocation error ...
  }
  delete(std::nothrow, p);              // deallocate *p
}

int main() {
  f(1024);
}
