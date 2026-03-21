// C130502_catching_exceptions.cpp 
#include <iostream>

struct E {};
struct H {};

void f() {
  try {
    throw E{};
  }
  catch(H) { // when do we get here?
    std::cout << "we caught the exception.\n";
  }
}

struct Error {};

void g() {
  int x1{0};        // will be used in both try and catch parts

  try {
    int x2 = x1;
  }
  catch(Error) {
    ++x1;           // OK
    // ++x2;        // error: x2 not in scope
    int x3 = 7;
  }
  catch(...) {
    // ++x3;        // error
  }

  ++x1;             // OK
  // ++x2;          // error: x2 not in scope
  // ++x3;          // error: x3 not in scope
}

int main() {
  f();
}
