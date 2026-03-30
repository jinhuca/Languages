// C140204_argument_dependent_lookup.cpp 
#include <iostream>
#include <string>

namespace Chrono {
  class Date { };
  bool operator==(const Date&, const std::string&);
  std::string format(const Date&);  // make string representation
}

void f(Chrono::Date d, int i) {
  std::string s = format(d);  // call Chrono::format without qualification
  std::string t = format(i);  // error: no match for format(int)
}

namespace N {
  struct S { int i; };
  void f(S);
  void g(S);
  void h(int);
}

struct Base {
  void f(N::S);
};

struct D : Base {
  void mf(N::S);

  void g(N::S x) {
    f(x);   // call Base::f without qualification
    mf(x);  // call D::mf without qualification
    h(x);   // error: no match for h(N::S)
  }
};

namespace N {
  template<typename T>
  void f(T, int);
  class X{};
}

namespace N2 {
  N::X x;
  void f(N::X, unsigned);
  void g() {
    f(x, 1);   // call N::f(N::X, int) without qualification
  }
}

int main() {
  
}
