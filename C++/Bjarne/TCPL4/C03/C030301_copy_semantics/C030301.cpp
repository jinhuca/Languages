// C0331.cpp : copying containers
import std;
#include "Vector.h"

void print_vector(Vector& v) {
  for(int i = 0; i != v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
}

void bad_copy(Vector& v1) {
  Vector v2 = v1;
  print_vector(v1);
  print_vector(v2);
  v1[0] = 2;
  v2[1] = 3;
  print_vector(v1);
  print_vector(v2);
}

void f() {
  Vector v = Vector(4);
  for(int i = 0; i != v.size(); ++i)
    v[i] = i;

  print_vector(v);
  Vector v2 = Vector(4);
  for(int i = 0; i != v2.size(); ++i)
    v2[i] = i * 2;
  print_vector(v2);

  auto c = v + v2;
  print_vector(c);
  //print_vector(v);
  //bad_copy(v);
}

void h(const Vector& x, const Vector& y, const Vector& z) {
  Vector r(6);
  r = x + y + z;
}

int main() {
  Vector x(100);
  Vector y(100);
  Vector z(100);
  h(x, y, z);
}
