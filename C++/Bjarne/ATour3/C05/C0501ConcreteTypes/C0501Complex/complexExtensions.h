#pragma once
#include "complex.h"

inline complex operator+(complex a, complex b) {
  return a += b;
}

inline complex operator-(complex a, complex b) {
  return a -= b;
}

inline complex operator-(complex a) {
  return { -a.real(), -a.imag() };
}

inline complex operator*(complex a, complex b) { return a *= b; }
inline complex operator/(complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b) {
  return !(a == b);
}