// C0240.cpp : Modularity
#include <iostream>
#include <cmath>

double sqrt1(double);      // function declaration

class Vector {            // class declaration
public:
  Vector(int);
  double& operator[](int);
  int size() const;
private:
  double* elem;
  int sz;
};

Vector::Vector(int s) : elem { new double[s] }, sz { s } {
  for(int i = 0; i != s; ++i)
    elem[i] = i;
}
double& Vector::operator[](int i) { return elem[i]; }
int Vector::size() const { return sz; }

int main() {
  Vector v { 5 };
  std::cout << v.size() << '\n';
  std::cout << v[1] << '\n';
  std::cout << sqrt(5.6) << '\n';
}

double sqrt1(double s) {
  return std::sqrt(s);
}