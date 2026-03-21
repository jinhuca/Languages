// C130502_catching_exceptions.cpp 
#include <iostream>

struct E {};
struct H {};

void f() {
  try {
    throw E{};
  }
  catch(H) {
    // when do we get here?
    std::cout << "we caught the exception.\n";
  }
}

int main() {
  f();
}
