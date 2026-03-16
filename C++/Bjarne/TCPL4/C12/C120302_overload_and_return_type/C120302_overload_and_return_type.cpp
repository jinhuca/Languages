// C120302_overload_and_return_type.cpp 
#include <iostream>

float sqrtx(float f) {
  std::cout << "sqrt on float: " << f << '\n';
  return f * 2;
}
double sqrtx(double d) {
  std::cout << "sqrt on double: " << d << '\n';
  return d * 3;
}

void f(double da, float fla) {
  float fl = sqrtx(da);      // call sqrt(double)
  double d = sqrtx(da);      // call sqrt(double)
  fl = sqrtx(fla);           // call sqrt(float)
  d = sqrtx(fla);            // call sqrt(float)
}

int main() {
  f(1.32, 3.21f);
}
