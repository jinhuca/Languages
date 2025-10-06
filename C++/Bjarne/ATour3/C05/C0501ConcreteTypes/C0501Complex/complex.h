#pragma once
#include <iostream>

class complex {
public:
  complex() : re { 0 }, im { 0 } {
    std::cout << "called default constructor.\n";
  }
  complex(double r) : re { r }, im { 0 } {}
  complex(double r, double i) :re { r }, im { i } {}
  complex(const complex& z) : re { z.re }, im { z.im } {
    std::cout << "called copy constructor" << "{ "
      << z.re << ", " << z.im << " }" << '\n';
  }

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void img(double d) { im = d; }

  complex& operator+=(complex z) {
    re += z.re;
    im += z.im;
    return *this;
  }

  complex& operator-=(complex z) {
    re -= z.re;
    im -= z.im;
    return *this;
  }

  complex& operator*=(complex);
  complex& operator/=(complex);
private:
  double re, im;    // representation: two doubles
};
