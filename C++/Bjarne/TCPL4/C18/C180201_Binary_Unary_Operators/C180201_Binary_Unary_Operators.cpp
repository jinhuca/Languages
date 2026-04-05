// C180201_binary_unary_operators.cpp 
#include <iostream>
using std::cout;

class X {
public:
  X(int a) :val{a} {}
  void operator+(int a) { cout << "call in_class operator+.\n"; }
private:
  int val;
};

void operator+(X, X) {
  cout << "call non-member function - operator+(X, X).\n";
}

void operator+(X x, double d) {
  cout << "call non-member function - operator+(X, double).\n";
}

void call_binary_operator(X a) {
  a + 1;
  1 + a;
  a + 1.0;
}

class Y {
public:   // members (with implicit this pointer)
  Y* operator&();       // prefix unary & (address of)
  Y operator&(Y);       // binary & (and)
  Y operator++(int);    // postfix increment
  Y operator&(Y, Y);    // error: ternary
  Y operator/();        // error: unary /
};

// nonmember functions:
Y operator-(Y);         // prefix unary minus
Y operator-(Y, Y);      // binary minus
Y operator--(Y&, int);  // postfix decrement
Y operator-();          // error: no operand
Y operator-(Y, Y, Y);   // error: no ternary for -
Y operator%(Y);         // error: no unary for %

int main() {
  call_binary_operator(X{1});
}

