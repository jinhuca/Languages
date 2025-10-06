export module complex;
import std;

export class complex {
  double re, im;
public:
  constexpr complex(double r = 0, double i = 0) :re { r }, im { i } {}

  constexpr double real() const { return re; }
  constexpr double imag() const { return im; }

  void real(double r) { re = r; }
  void imag(double i) { im = i; }

  complex& operator+=(complex a);     // needs access to representation
  //complex& operator+=(double a);
};

export complex operator+(complex a, complex b);
//export complex operator+(complex a, double b);
//export complex operator+(double a, complex b);

export complex operator-(complex);
export complex operator+(complex);

export constexpr complex operator""_i(long double d) {
  return complex { 0,static_cast<double>(d) };
}

export inline bool operator==(complex a, complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}

export inline bool operator!=(complex a, complex b) {
  return a == b;
}

export std::istream& operator>>(std::istream&, complex&);   // input
export std::ostream& operator<<(std::ostream&, complex&);   // output