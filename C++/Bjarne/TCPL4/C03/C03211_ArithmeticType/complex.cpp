#include "complex.h"

complex& complex::operator*=(complex a) {
  re *= a.re;
  im *= a.im;
  return *this;
}

complex& complex::operator/=(complex b) {
  re /= b.re;
  im /= b.im;
  return *this;
}
