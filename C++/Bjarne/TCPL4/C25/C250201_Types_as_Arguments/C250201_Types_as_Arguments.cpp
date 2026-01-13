// C250201_Types_as_Arguments.cpp 
#include <iostream>
#include <complex>
using namespace std;

template<typename T>
void f(T arg) {
}

template<typename T>
class X {
  // ...
};

int main() {
  f(10);                      // T is deduced as int;
  f<double>(10);              // T is explicitly specified as double;
  f<complex<double>>(1);      // T is explicitly specified as complex<double>;

  X<double> x1;               // T is double
  X<complex<double>> x2;      // T is complex<double>
}
