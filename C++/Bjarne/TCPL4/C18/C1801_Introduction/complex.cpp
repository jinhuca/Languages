import std;
import complex;

complex complex::operator+(complex rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

complex complex::operator*(complex rhs) {
  re *= rhs.re;
  im *= rhs.im;
  return *this;
}
