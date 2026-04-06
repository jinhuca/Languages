// C190402_friends_and_members.cpp 
#include <iostream>
class X;

int f1(X& x) { std::cout << "int f1() invoked.\n"; }
int f2(const X& x) { std::cout << "int f2() invoked.\n"; }
int f3(X) { std::cout << "int f3() invoked.\n"; }

class X {
  // ...
public:
  X(int);
  int m1();
  int m2() const;

  friend int f1(X&);
  friend int f2(const X&);
  friend int f3(X);
};

void g() {
  // 99.m1();    // error: X(99).m1() not tried
  // 99.m2();    // error: X(99).m2() not tried
}

void h() {
  // f1(99);       // error: f1(X(99)) not tried: non-const X& argument
  f2(99);       // OK: f2(X(99)); const X& argument
  f3(99);       // OK: f3(X(99)); X argument
}

int main() {
}
