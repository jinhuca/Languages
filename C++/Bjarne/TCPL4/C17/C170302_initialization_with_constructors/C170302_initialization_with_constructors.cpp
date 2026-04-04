// C170302_initialization_with_constructors.cpp 
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

namespace use_constructors {
  struct X {
    X(int) { std::cout << "X(int)\n"; }
  };

  void f() {
    X x0;           // error: no default constructor for X
    X x1{};         // error: empty initializer list does not match any constructor for X
    X x2{7};        // OK: x2 is initialized by X(int)
    X x3{"two"};    // error: no matching constructor for X(const char*)
    X x4{1, 2};     // error: wrong number of initializers
    X x5{x2};       // OK: a copy constructor is synthesized by the compiler: x5 is initialized by copying x2
  }

  struct Y :X {
    X m{0};                     // provide default initilizer for member X.m in Y
    Y(int a) :X{a}, m{a} {}     // initialize base and member
    Y() :X{0} {}                // initialize base and member
  };

  X g{1};                       // OK: initialize global variable by X(int)

  void h(int a) {
    X def{};                    // error: empty initializer list does not match any constructor for X
    Y def2{};                   // OK: use default constructor
    X* p{nullptr};              // OK: initialize pointer to nullptr
    X var{2};                   // OK: initialize local variable by X(int)
    p = new X{4};               // OK: initialize dynamically allocated object by X(int)
    X a[]{1, 2, 3};             // OK: initialize array of X by X(int)
    vector<X> v{1, 2, 3, 4};    // OK: initialize vector of X by X(int)
  }
}

namespace use_universal_uniform_initializer {
  struct X {
    X(int) { std::cout << "X(int)\n"; }
  };

  struct Y : X {
    X m;
    Y(int a) : X(a), m{a} {}
  };

  X g{1};                       // initialize global variable by X(int)

  void use_non_universal_initializer(int a) {
    X def();                    // function returning an X (surprise?)
    X* p(nullptr);              // OK: initialize pointer to nullptr
    X var = 2;                  // OK: initialize local variable 
    p = new X = 4;              // syntax error: can't use = for new
    p = new X{4};               // OK: initialize dynamically allocated object by X(int)
    X a[](1, 2, 3);             // error: can't use () for array initialization
    vector<X> v(1, 2, 3, 4);    // error: can't use () for vector initialization
  }

  struct S {
    S(const char*);
    S(double*);
  };

  S s1{"Napier"};               // S::S(const char*)
  S s2{new double{1.0}};        // S::S(double*)
  S s3{nullptr};                // ambiguous: S::S(const char*) or S(double*)?
}

namespace initialization_by_constructors {
  struct S1 {
    int a, b;
  };

  struct S2 {
    int a, b;
    S2(int aa = 0, int bb = 0) :a(aa), b(bb) {}   // constructor
  };

  S1 x11(1, 2);           // error: no constructor
  S1 x12{1, 2};           // OK: memberwise initialization

  S1 x13(1);              // error: no constructor
  S1 x14{1};              // OK: x14.b becomes 0

  S2 x21(1, 2);           // OK: use constructor
  S2 x22{1, 2};           // OK: use constructor

  S2 x23(1);              // OK: use constructor and one default argument
  S2 x24{1};              // OK: use constructor and one default argument

  void init_vec() {
    vector<int> v11{77};       // one element with the value 77
    vector<int> v12(77);       // 77 elements with the default value 0

    vector<string> v1{77};      // 77 elements with the default value ""
    vector<string> v2(77);      // 77 elements with the default value ""

    vector<string> v3{"Booh!"};   // one element with the value "Booh!"
    vector<string> v4("Booh!");   // error: no constructor takes a string argument

    vector<int*> v5{100, 0};       // 100 int*s initialized to nullptr

    vector<int*> v6{0, 0};        // 2 int*s initialized to pullptr
    vector<int*> v7(0, 0);        // empty vector (v7.size() == 0)

    vector<int*> v8;              // empty vector (v8.size() == 0)
  }
}

int main() {

}
