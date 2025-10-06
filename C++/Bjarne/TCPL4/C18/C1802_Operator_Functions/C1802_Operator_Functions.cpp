// C1802_Operator_Functions.cpp 
import std;
import complex;

void f(complex a, complex b) {
  complex c = a + b;              // shorthand for operator+ function
  complex d = a.operator+(b);     // explicitly call operator+ function
}

int main() {
  complex a { 1.3, 4.2 };
  complex b { 3.3, 2.6 };
  f(a, b);
}
