#pragma once

class complex {
  double re, im;
public:
  complex(double r, double i) :re { r }, im { i } {}
  complex(double r) :re { r }, im { 0 } {}
  complex() :re { 0 }, im { 0 } {}

  double real() const { return re; }
  void real(double r) { re = r; }
  double imag() const { return im; }
  void imag(double i) { im = i; }

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

  //complex& operator+(complex);
  //complex& operator-(complex);
  //complex& operator*(complex);
  //complex& operator/(complex);

  //bool operator==(const complex&) const;
  //bool operator!=(const complex&) const;

};