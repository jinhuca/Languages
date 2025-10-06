import std;

namespace My_code
{
  class complex
  {
    double re, im;                                            // representation: two doubles
  public:
    complex(double r, double i) :re(r), im(i) {  }            // construct complex from two scalars
    complex(double r) :re{ r }, im{ 0 } {}                    // construct complex from one scalar
    complex() :re{ 0 }, im{ 0 } {}                            // default complex: {0, 0}
    complex(const complex& z) :re{ z.re }, im{ z.im } {}      // copy constructor

    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }

    complex& operator+=(const complex z)
    {
      re += z.re;
      im += z.im;
      return *this;
    }

    complex& operator-=(const complex z)
    {
      re -= z.re;
      im -= z.im;
      return *this;
    }

    complex operator*=(complex) const;                       // defined out-of-class somewhere
    complex operator/=(complex) const;                       // defined out-of-class somewhere
  };
  void doSth(std::vector<int>& x, std::vector<int>& y);
  int main();
}

int My_code::main()
{
  complex z{ 1.2 };
  std::cout << '(' << z.real() << ", " << z.imag() << ')' << '\n';
  return 0;
}

void My_code::doSth(std::vector<int>& x, std::vector<int>& y)
{
  using std::swap;
  swap(x, y);
}

int main()
{
  return My_code::main();
}
