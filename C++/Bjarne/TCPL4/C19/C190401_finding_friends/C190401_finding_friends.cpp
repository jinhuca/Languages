// C190401_finding_friends.cpp 
#include <iostream>

class C1 {};    // will become friend of N::C
void f1();      // will become friend of N::C

namespace N {
  class C2 {};      // will become friend of C
  void f2() {}      // will become friend of C

  class C {
    int x;
  public:
    friend class C1;    // OK (previous defined)
    friend void f1();
    friend class C2;    // OK (previous defined)
    friend void f2();
    friend class C3;    // OK (defined in enclosing namespace)
    friend void f3();   // OK (defined in enclosing namespace)
    friend class C4;    // first declared in N and assumed to be in N
    friend void f4();
  };

  class C3 {};                  // friend of C
  void f3() { C c; c.x = 1; }   // OK: friend of C
}

void f1() {}

class C4 {};            // not friend of N::C

void f4() {             // not friend of N::C
  N::C g;               // a object of N::C
  // g.x = 2;           // error: x is private and f4() is not a friend of N::C
}

class Matrix {
public:
  friend void invert(Matrix);
};

void f(Matrix m) {
  invert(m);    // Matrix's friend invert()
}

void invert(Matrix m) {}

class X {
  friend void f();
  friend void h(const X&);
};

void h(const X& x) {}

void g(const X& x) {
  // f();        // error: no f() in scope
  h(x);       // can be found through its argument
}

int main() {

}
