// C120303_overload_and_scope.cpp 
#include <iostream>

void f(int i) {
  std::cout << "call f(int) with " << i << ".\n";
}

void f(double d) {
  std::cout << "call f(double) with " << d << ".\n";
}

void g() {
  void f(double d);   // hide f(int)
  f(1);
}

struct Base { 
  void f(int i) { std::cout << "call base function f(int) with " << i << ".\n"; } 
};

struct Derived :Base {
  void f(double d) { std::cout << "call derived function f(double) with " << d << ".\n"; }
};

void h(Derived d) {
  d.f(1);           // call Derived::f(double)
}

int main() {
  g();
  
  Derived d;
  d.f(1);
}
