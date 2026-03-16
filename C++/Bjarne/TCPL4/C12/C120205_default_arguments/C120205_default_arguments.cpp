// C120205_default_arguments.cpp 
#include <iostream>

class X {
public:
  static int def_arg;
  void f(int = def_arg);
};

int X::def_arg = 7;
void X::f(int i) {
  std::cout << "f's actual argument = " << i << '\n';
}

void g(X& a) {
  a.f();             // maybe f(7)
  a.def_arg = 9;     //
  a.f();             // f(9)
}

int main() {
  X x;
  g(x);
}
