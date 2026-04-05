// C180200_operator_functions.cpp 
#include <iostream>

class complex {
  double re, im;
public:
  complex(double r, double i) : re{r}, im{i} {}
  complex operator+(complex);
};

complex complex::operator+(complex a) {
  return {re + a.re, im + a.im};
}

void equivalent_calls(complex a, complex b) {
  complex c = a + b;            // shorthand
  complex d = a.operator+(b);   // explicit call
}

int main() {

}
