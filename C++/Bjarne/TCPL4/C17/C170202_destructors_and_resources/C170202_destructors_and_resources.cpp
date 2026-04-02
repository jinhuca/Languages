// C170202_destructors_and_resources.cpp 
#include <iostream>

class Vector {
public:
  Vector(int s) :elem{new double[s]}, sz{s} {}    // constructor: acquire memory
  ~Vector() { delete[] elem; }                    // destructor: release memory
  // ...
private:
  double* elem;   // elem points to an array of sz doubles
  int sz;         // sz is non-negative
};

int main() {
  std::cout << "Hello World!\n";
}
