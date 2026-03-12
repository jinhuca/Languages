// C110200_free_store.cpp 
#include <iostream>
#include <complex>

void create_objects_in_free_store() {
  auto pc = new std::complex<double>;     // the complex is initialized to {0,0}
  auto pi = new int;                      // the int is unitialized

  // use {} to get default initialization
  auto pc1 = new std::complex<double> { };
  auto pi2 = new int {};

}

int main() {
  create_objects_in_free_store();
}
