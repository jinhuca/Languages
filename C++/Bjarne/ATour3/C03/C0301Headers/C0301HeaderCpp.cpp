// C0301HeaderCpp.cpp 
#include "Vector.h"
#include <iostream>

int main() {
  Vector v1(5);
  for(int i = 0; i != 5; ++i) {
    v1[i] = i;
  }
  for(int i = 0; i != 5; ++i) {
    std::cout << v1[i] << ' ';
  }
}
