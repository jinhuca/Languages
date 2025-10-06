export module complex;

export class complex
{
  double re, im;
public:
  complex(double r, double i) :re{ r }, im{ i } {}
  complex& operator+=(complex a)   // need to access to representations
  {
    re += a.re;
    im += a.im;
    return *this;
  }
  complex operator+(complex);
  complex operator*(complex);
};



