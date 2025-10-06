// C0302ModuleCpp.cpp
#include <iostream>
import Vector;

int main() {
  Vector v(5);
  for(int i = 0; i != v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
}
