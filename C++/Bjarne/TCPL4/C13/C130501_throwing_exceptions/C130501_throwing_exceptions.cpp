// C130501_throwing_exceptions.cpp
#include <iostream>
#include <string>

using std::string;

class No_copy {
  No_copy(const No_copy&) = delete;    // prohibit copying
};

class My_error {
  // ...
};

namespace throw_copy_of_object {
  void f(int n) {
    switch(n) {
      case 0: throw My_error {};       // OK
      //case 1: throw No_copy {};        // error: can't copy a No_copy
      //case 2: throw No_copy;           // error: My_error is a type, rather than an object
    }
  }
}

namespace throw_stack_unwinding {
  void h() {
    string s = "not";
    throw My_error {};
    string s2 = "at all";
  }

  void g() {
    string s = "excess";
    {
      string s = "or";
      h();
    }
  }

  void f() {
    string name {"Byron"};
    try {
      string s = "in";
      g();
    }
    catch(My_error) {
      // ...
    }
  }
}

int main() {
  throw_copy_of_object::f(101);
  throw_stack_unwinding::f();
}
