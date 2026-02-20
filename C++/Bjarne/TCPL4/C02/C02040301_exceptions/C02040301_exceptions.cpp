// C02040301_exceptions.cpp 
#include <iostream>
#include "Vector.h"

int main() {
  try {
    Vector v(5);
    std::cout << v[v.size()] << '\n';
  }
  catch(std::exception& exception) {
    std::cerr << exception.what() << '\n';
  }
}
