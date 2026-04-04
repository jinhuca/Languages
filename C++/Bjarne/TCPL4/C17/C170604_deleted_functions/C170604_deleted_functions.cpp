// C170604_deleted_functions.cpp 
#include <iostream>

class Base {
  // ...
  Base& operator=(const Base&) = delete;    // disallow copying
  Base(const Base&) = delete;

  Base& operator=(Base&&) = delete;         // disallow moving
  Base(Base&&) = delete;
};

Base x1;
Base X2{x1};    // error: no copy constructor

struct Foo{};
class Shape {};

template<typename T>
T* clone(T* p) {    // return copy of *p
  return new T{*p};
}

Foo* clone(Foo*) = delete;    // don't try to clone a Foo

void f(Shape* ps, Foo* pf) {
  Shape* ps2 = clone(ps);     // fine
  Foo* pf2 = clone(pf);       // error: clone(Foo*) deleted
}

struct Z {
  Z(double);        // can initialize with a double
  Z(int) = delete;  // but not with an integer
};

void g() {
  Z z1{1};          // error: Z(int) deleted
  Z z2{1.0};        // OK
}

class Not_on_stack {
public:
  // ...
  ~Not_on_stack() = delete;
};

class Not_on_free_store {
public:
  // ...
  void* operator new(size_t) = delete;
};

void h() {
  Not_on_stack v1;                                  // error: can't destroy
  Not_on_free_store v2;                             // OK

  Not_on_stack* p1 = new Not_on_stack;              // OK
  Not_on_free_store* p2 = new Not_on_free_store;    // error: can't allocate
}

int main() {

}
