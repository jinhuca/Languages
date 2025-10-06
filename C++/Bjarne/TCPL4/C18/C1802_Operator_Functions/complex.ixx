export module complex;

export class complex {
  double re, im;
public:
  complex(double r, double i) :re { r }, im { i } { }
  complex operator+(complex);
  complex operator*(complex);
};
