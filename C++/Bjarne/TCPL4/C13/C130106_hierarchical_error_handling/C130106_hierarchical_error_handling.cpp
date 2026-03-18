// C130106_hierarchical_error_handling.cpp 
#include <iostream>

#define E_CPLPLFCTBLEWIT 101

void c_function() {}

class cppException {
  // ... error information ...
};

void c_plus_plus_function(int a) {
  if(a > 1000) throw cppException();
  // ...
}

struct C_blewit {
  C_blewit(int e) : en{e} {}
  int en;
};

void callC() {    // call a C function from C++; convert errno to a throw
  errno = 0;
  c_function();
  if(errno) {
    // ... local cleanup, if possible and necessary ...
    throw C_blewit(errno);
  }
}

extern "C" void call_from_C() noexcept {    // call a C++ function from C; convert a throw to errno
  try {
    c_plus_plus_function(1001);
  }
  catch(...) {
    // ... local cleanup, if possible and necessary ...
    errno = E_CPLPLFCTBLEWIT;
  }
}

int main() {
  std::cout << "Hello World!\n";
}
