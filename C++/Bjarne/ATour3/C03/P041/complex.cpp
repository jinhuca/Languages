import complex;

complex operator/(complex a, complex b)
{
  return a /= b;
}

bool operator==(complex a, complex b)
{
  return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(complex a, complex b)
{
  return a.real() != b.real() || a.imag() != b.imag();
}

complex complex::operator+(const complex& x) const
{
  return complex(re + x.re, im + x.im);
}

complex complex::operator-(const complex& x) const
{
  return complex(re - x.re, im - x.im);
}

complex complex::operator*(const complex& x) const
{
  return complex(re * x.re, im * x.im);
}

complex complex::operator*=(const complex& a) const
{
  return complex{ real() * a.real(), imag() * a.imag() };
}

complex complex::operator/=(const complex& a) const
{
  return complex{ real() / a.real(), imag() / a.imag() };
}
