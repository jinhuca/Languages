// C03212.cpp : A container
#include <iostream>

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) :sz { s }, elem { new double[s] } {   // constructor: acquire resources
    for (int i = 0; i != s; ++i) elem[i] = 0;         // initialize elements
    std::cout << "constructed a Vector of size " << sz << '\n';
  }
  ~Vector() {                                         // destructor: release resources
    delete[] elem;
    std::cout << "destructed a Vector of size " << sz << '\n';
  }
  double& operator[](int i) {
    if (i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }
  int size() const { return sz; }
};

void fct(int n) {
  Vector v { n };   // construct v 
  {
    Vector v2(2 * n);   // construct v2
  }   // destruct v2
}   // destruct v

int main() {
  fct(7);
}
