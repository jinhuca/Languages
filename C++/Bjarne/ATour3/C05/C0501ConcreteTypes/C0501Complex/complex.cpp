#include "complex.h"

complex& complex::operator*=(complex x) {
  re = re * x.re;
  im = im * x.im;
  return *this;
}

complex& complex::operator/=(complex x) {
  re = re / x.re;
  im = im / x.im;
  return *this;
}
