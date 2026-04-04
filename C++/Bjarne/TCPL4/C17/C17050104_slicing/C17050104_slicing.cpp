// C17050104_slicing.cpp 
#include <iostream>
using std::cout;

struct Base {
  int b;
  Base() :b{0} {}
  Base(int y) :b{y} {}
  Base(const Base& x) : b{x.b} {
    cout << "Base copy constructor called.\n";
  }
};

struct Derived :Base {
  int d;
  Derived() :d{0} {}
  Derived(int x) :d{x} {}
  Derived(const Derived& x) : d{x.d}, Base{x.b} {
    cout << "Derived copy constructor called.\n";
  }
};

void naive(Base* p) {
  Base b2 = *p;   // may slice: invokes Base::Base(const Base&)
  // ...
}

void user() {
  Derived d;
  naive(&d);
  Base bb = d;    // slices: invokes Base::Base(const Base&), not Derived::Derived(const Derived&)
}

int main() {
  user();
}
