// C130501_throwing_exceptions.cpp
#include <iostream>
#include <string>
#include <exception>

using std::string;

class No_copy {
  No_copy(const No_copy&) = delete;       // prohibit copying
};

class My_error {
  // ...
};

namespace throw_copy_of_object {
  void f(int n) {
    switch(n) {
    case 0: throw My_error{};          // OK
          //case 1: throw No_copy {};         // error: can't copy a No_copy
          //case 2: throw No_copy;            // error: My_error is a type, rather than an object
    }
  }
}

namespace throw_stack_unwinding {
  void h() {
    string s = "not";
    throw My_error{};
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
    string name{"Byron"};
    try {
      string s = "in";
      g();
    }
    catch(My_error) {
      // ...
    }
  }
}

namespace create_own_exception {
  struct Some_error {};
  void fct(int something) {
    // ...
    if(something)
      throw Some_error{};
  }

  struct My_error2 : public std::runtime_error {
    explicit My_error2(const std::string& msg) : std::runtime_error(msg) {
    }
    const char* what() const noexcept { return "My_error2"; }
  };

  void g(int n) {   // throw some exception
    if(n)
      throw std::runtime_error{"I give up!"};
    else
      throw My_error2("error2");
  }
  void f(int n) {   // see what exception g() throws
    try {
      g(n);
    }
    catch(std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
}

int main() {
  //throw_copy_of_object::f(101);
  //throw_stack_unwinding::f();
  create_own_exception::f(0);
}
