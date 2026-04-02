// C170201_constructors_and_invariants.cpp 
#include <iostream>

class Vector {
public:
  Vector(int s);
  // ...
private:
  double* elem;    // pointer to the first element
  int sz;          // the number of elements
};

Vector::Vector(int s) {
  if (s < 0) {
    throw std::length_error{"size must be non-negative"};
  }
  // ... allocate and initialize a vector of size s
  sz = s;
  elem = new double[sz];
}

struct S {
  S();                    // fine
  void S(int);            // error: no type can be specified for a constructor
  int S;                  // error: no member can have the same name as its class
  enum S { foo, bar };    // error: no type can be specified for a constructor, and no member can have the same name as its class
};

int main() {
  
}
