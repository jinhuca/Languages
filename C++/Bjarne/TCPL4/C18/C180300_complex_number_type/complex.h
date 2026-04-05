#pragma once

namespace C18 {
  class complex {
    double re, im;
  public:
    complex(double r = 0, double i = 0) :re{r}, im{i} {}

    double real() const { return re; }
    double imag() const { return im; }

    complex& operator+=(complex a) {
      re += a.re;
      im += a.im;
      return *this;
    }
    complex& operator+=(double a) {
      re += a;
      return *this;
    }
    // ...
  };

  inline complex operator+(complex a, complex b) {
    return a += b;
  }

  inline complex operator+(complex a, double b) {
    return a += b;
  }

  inline complex operator+(double a, complex b) {
    return b += a;
  }
}