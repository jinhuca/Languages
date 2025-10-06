// C170302_Init_Using_Constructors.cpp 
import std;

struct X {
  X(int a) { data = a; }
private:
  int data;
};

X x0;           // error: no initializer
X x1 {};        // error: empty initializer
X x2 { 2 };   // OK
X x3 { "two" };   // error: wrong initializer type
X x4 { 1,2 };     // error: wrong number of initializers
X x5 { x4 };      // OK: a copy constructor is implicit defined

void f() {
  X x0;           // error: no initializer
  X x1 {};        // error: empty initializer
  X x2 { 2 };   // OK
  X x3 { "two" };   // error: wrong initializer type
  X x4 { 1,2 };     // error: wrong number of initializers
  X x5 { x4 };      // OK: a copy constructor is implicit defined
}

struct Y :X {
  X m { 0 };      // provide default initializer for member X.m in Y
  Y(int a) :X { a }, m { a } {}   // initialize base and member
  Y() :X { 0 } {}               // initialize base and member
};

X g { 1 };        // initialize global variable

void h() {
  X def {};         // error: no default value for X
  Y def2 {};        // OK: use default constructor
  X* p { nullptr };
  X var { 2 };
  p = new X { 4 };    // initialize object on free store
  X a[] { 1,2,3 };    // initialize array elements
  std::vector<X> v { 1,2,3,4 };
}

int main() {
  std::cout << "Hello World!\n";
}
