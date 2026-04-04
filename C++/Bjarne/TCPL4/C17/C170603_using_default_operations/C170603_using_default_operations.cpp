// C170603_using_default_operations.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using std::string;
using std::vector;

namespace default_constructors {    // C17.6.3.1
  struct X {
    X(int) {}   // require an int to initialize X
  };

  void f() {
    X a{1};     // OK
    X b{};      // error: no default constructor
  }

  struct Y {
    string s;
    int n;
    Y(const string& x) : s{x}, n{1} {}    // initialize Y with a string
    Y() = default;                        // get back the compiler-generated default constructor
  };

  void g() {
    Y b1{"hello"};      // OK: call user-provided ordinary constructor
    Y b2();             // OK: call compiler-generated default constructor
  }
}

namespace maintain_invariants {     // C17.6.3.2
  struct Z {  
    // invariant:
    // my_favorite is the index of my favorite element of elem
    // largest points to the element with the highest value in elem
    vector<int> elem;
    int my_favorite;
    int* largest;
  };

  Z move(Z& a) {
    return std::move(a);
  }

  void f() {
    Z v0;                               // no initialization (oops! possibility of undefined values)
    Z val({1, 2, 3}, 1, &v0.elem[2]);   // OK, but ugly and error-prone
    Z v2 = val;                         // copies: v2.largest points into val
    Z v3 = move(val);                   // moves: val.elem becomes empty; v3.my_favorite is out of range
  }
}

namespace resource_invariants {     // C17.6.3.3
  template<typename T>
  class Handle {
    T* p;
  public:
    Handle(T* pp) : p{pp} {}
    T& operator*() { return *p; }
    ~Handle() { delete p; }
  };

  void f1() {
    Handle<int> h{new int{99}};
    // ...
  }

  void f2() {
    Handle<int> h;      // error: no default constructor
    // ...
  }
}

int main() {
  maintain_invariants::f();
}
