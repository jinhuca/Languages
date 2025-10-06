import complex;
import std;

inline complex& complex::operator+=(complex a) {
  re += a.re;
  im += a.im;
  return *this;
}

//inline complex& complex::operator+=(double a) {
//  re += a;
//  return *this;
//}

complex operator+(complex a, complex b) {
  return a += b;        // access representation through +=
}

complex operator-(complex a) {
  return { -a.real(), -a.imag() };
}

complex operator+(complex a) {
  return { std::abs(a.real()), std::abs(a.imag()) };
}

//std::istream& operator>>(std::istream&, complex&) {
//}
//
//std::ostream& operator<<(std::ostream&, complex&) {
//}

