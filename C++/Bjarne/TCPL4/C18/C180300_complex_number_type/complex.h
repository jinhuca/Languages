#pragma once

namespace C18 {
  class complex {
    double re, im;
  public:
    constexpr complex(double r = 0, double i = 0) :re{r}, im{i} {}
       
    constexpr double real() const { return re; }
    constexpr double imag() const { return im; }

    void real(double r) { re = r; }
    void imag(double i) { im = i; }

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

  inline constexpr complex operator""_i(long double d) {
    return complex{0.0, static_cast<double>(d)};
  }

  inline bool operator==(complex a, complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
  }
}