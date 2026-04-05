// C180202_predefined_meanings_for_operators.cpp 
#include <iostream>

class X {
public:
  // ...
  void operator=(const X&) = delete;    //
  void operator&() = delete;
  void operator,(const X&) = delete;
  // ...
};

void f(X a, X b) {
  a = b;    // error: no operator=()
  &a;       // error: operator&() is deleted
  a, b;     // error: no operator,()
}

int main() {
  
}
