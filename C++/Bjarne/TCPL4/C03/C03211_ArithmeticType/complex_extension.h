#pragma once
#include "complex.h"

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
  return !(a == b);
}