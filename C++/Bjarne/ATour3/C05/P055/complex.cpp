import complex;
import std;

namespace P055
{
  complex complex::operator+(const complex &x) const
  {
    return complex(real() + x.real(), imag() + x.imag());
  }

  complex complex::operator-(const complex &x) const
  {
    return complex(real() - x.real(), imag() - x.imag());
  }

  complex complex::operator*(const complex &x) const
  {
    return complex(real() * x.real(), imag() * x.imag());
  }

  complex complex::operator/(const complex &x) const
  {
    return complex(real() / x.real(), imag() / x.imag());
  }

  complex complex::operator*=(const complex &a) const
  {
    return complex { real() * a.real(), imag() * a.imag() };
  }

  complex complex::operator/=(const complex &a) const
  {
    return complex { real() / a.real(), imag() / a.imag() };
  }

  bool complex::operator==(const complex &x) const
  {
    return real() == x.real() && imag() == x.imag();
  }

  bool complex::operator!=(const complex &x) const
  {
    return real() != x.real() || imag() != x.imag();
  }

  complex complex::operator-() const
  {
    auto r = -real();
    auto i = -imag();

    if(re == 0)
      r = 0;
    if(im == 0)
      i = 0;

    return complex(r, i);
  }

  std::ostream &operator<<(std::ostream &os, const complex &rhs)
  {
    os << "Real: " << rhs.real() << " : " << "Image: " << rhs.imag() << std::endl;
    return os;
  }
}