// C0242.cpp : namespaces
#include <iostream>

namespace My_code {
  class complex {
  public:
    complex(double a, double b) : r { a }, i { b } {}
    double real() const { return r; }
    double img() const { return i; }
  private:
    double r, i;
  };
  int main();
}

int My_code::main() {
  complex z { 1.2,4.2 };
  std::cout << "{ " << z.real() << ", " << z.img() << " }\n";
  return 0;
}

int main() {
  My_code::main();
}
