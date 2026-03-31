// C160211_member_access.cpp 
#include <iostream>

struct X {
  void f();
  int g() const { return m; }  // OK, "this->m"
  int m;
};

void X::f() {
  m = 1;        // OK, "this->m = 1;"
}

void user(X x, X* px) {
  m = 1;        // error: m is not declared in this scope  
  x.m = 2;      // OK: set m of x to 2
  x->m = 3;     // error: x is not a pointer
  x.f();        // call f() for x
  px->m = 4;    // OK: set m of *px to 4
  px.m = 5;     // error: px is a pointer, not an object
}

int main() {
  std::cout << "Hello World!\n";
}
