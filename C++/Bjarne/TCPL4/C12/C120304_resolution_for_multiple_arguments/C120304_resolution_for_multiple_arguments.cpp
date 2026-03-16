// C120304_resolution_for_multiple_arguments.cpp 
#include <iostream>
#include <complex>

using std::complex;

int pow(int i1, int i2) { return 1; }
double pow(double d1, double s2) { return 1.2; }
complex<double> pow(double d, complex<double> c) { return complex<double>{0,0}; }
complex<double> pow(complex<double> c, int i) { return complex<double>{0,0}; }
complex<double> pow(complex<double> c1, complex<double> c2) { return complex<double>{0,0}; }

void k(complex<double> z) {
  int i = pow(2, 2);                  // invoke pow(int, int)
  double d = pow(2.0, 2.0);           // invoke pow(double, double)
  complex<double> z2 = pow(2, z);     // invoke pow(double, complex)
  complex<double> z3 = pow(z, 2);     // invoke pow(complex, int)
  complex<double> z4 = pow(z, z);     // invoke pow(complex, complex)
}

int main() {
  k(complex<double>(0, 0));
}
