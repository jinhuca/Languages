// C170303_default_constructors.cpp 
#include <iostream>
using std::cout;

class Vector {
public:
  Vector();         // default constructor: no elements
  // ...
};

Vector::Vector() {
  cout << "default constructor called.\n";
}

class String {
public:
  String(const char* p = "");   // default constructor: empty string
};

void invoke_default_constructor() {
  Vector v1;        // OK
  Vector v2{};      // OK
}

void f() {
  int a0;               // uninitialized
  int a1();             // function declaration (intended?)

  int a{};              // a becomes 0
  double d{};           // d becomes 0.0
  char* p{};            // p becomes nullptr

  int* p1 = new int;    // p1 points to an uninitialized int
  int* p2 = new int{};  // p2 points to an int initialized as 0
}

template<typename T>
struct Handle {
  T* p;
  Handle(T* pp = new T{}) :p{pp} {}
  // ...
};

Handle<int> px;         // will generate int{}

int glob{9};

struct X {
  const int a1{7};      // OK
  const int a2;         // error: requires a user-defined constructor

};

int main() {
  invoke_default_constructor();
}
