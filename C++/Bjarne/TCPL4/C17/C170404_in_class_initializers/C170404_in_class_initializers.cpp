// C170404_in_class_initializers.cpp 
#include <iostream>
#include <string>
using std::string;

struct HashFunction { HashFunction(string n) {} };
struct D { int x; };

namespace in_class_initialization {
  class A {
  public:
    int a{77};
    int b = 77;
  };
}

namespace default_constructor_initialization {
  class A {
  public:
    int a;
    int b;
    A() :a{77}, b{77} {}
  };
}

namespace multiple_constructors {
  class A {
  public:
    A() : a{7}, b{5}, algorithm{"MD5"}, state{"Constructor run"} {}
    A(int a_val) : a{a_val}, b{5}, algorithm{"MD5"}, state{"Constructor run"} {}
    A(D d) :a{7}, b{5}, algorithm{"MD5"}, state{"Constructor run"} {}
    // ...
  private:
    int a, b;
    HashFunction algorithm;
    string state;
  };
}

namespace multiple_constructors_with_in_class_initializers {
  class A {
  public:
    A() {}
    A(int a_val) : a{a_val} {}
    A(D d) : b{d.x} {}
    // ...
  private:
    int a{5}, b{7};
    HashFunction algorithm{"MD5"};
    string state{"Constructor run"};
  };
}

int main() {
  
}
