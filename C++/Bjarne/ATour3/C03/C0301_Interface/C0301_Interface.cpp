// C0301_Interface.cpp 
#include <iostream>
#include <cmath>

double sqrtx(double n);

class Vector {
public:
  Vector(int s);
  double& operator[](int i) const;
  int size() const;
private:
  double* elem;             // elem points to an array of sz doubles
  int sz;
};

Vector::Vector(int s)
  : elem {new double[s]}, sz {s}     // initialize members
{}

double& Vector::operator[](int i) const {    // definition of subscripting
  return elem[i];
}

int Vector::size() const {                 // definition of size()
  return sz;
}

double sqrtx(double n) {
  return std::sqrt(n);
}

int main() {
  Vector v(3);
  v[1] = 1.2;
  std::cout << v[1] << '\n';
  std::cout << sqrt(1.234) << '\n';
}
