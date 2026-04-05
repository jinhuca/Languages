// C180100_introduction.cpp 
#include <iostream>

class complex {     // very simplified complex
  double re, im;
public:
  complex(double r, double i) : re{r}, im{i} {}
  complex operator+(complex);
  complex operator*(complex);
};

void f() {
  complex a = complex{1, 3.1};
  complex b{1.2, 2};
  complex c{b};

  a = b + c;
  b = b + c * a;
  c = a * b + complex(1, 2);
}

void g(complex a, complex b) {
  a = {1, 2};             // OK: right hand side of assignment
  a += {1, 2};            // error: no += defined
  b = a + {1, 2};         // syntax error
  b = a + complex{1, 2};  // OK
  g(a, {1, 2});           // OK: a function argument is considered an initialier
  { a, b } = {b, a};      // syntax error
}

int main() {

}
