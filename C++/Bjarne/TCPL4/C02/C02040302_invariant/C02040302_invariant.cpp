// C02040302_invariant.cpp 
#include "Vector.h"
#include <iostream>
#include <stdexcept>

void test() {
  try {
    Vector v(-28); 
  }
  catch(std::out_of_range ex1) {
    std::cerr << ex1.what() << '\n';
  }
  catch(std::bad_alloc ex2) {
    std::cerr << ex2.what() << '\n';
  }
  catch(...) {
    std::cerr << "Something wrong.\n";
  }
}

int main() {
  test();
}
