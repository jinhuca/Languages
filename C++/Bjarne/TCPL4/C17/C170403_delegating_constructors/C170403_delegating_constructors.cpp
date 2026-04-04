// C170403_delegating_constructors.cpp 
#include <iostream>
#include <string>
using std::string;

static int max = 1024;
class Bad_X {
public:
  Bad_X(int) {};
};

namespace without_delegating {
  class X {
    int a;
    void validate(int x) { if(0 < x && x <= max) a = x; else throw Bad_X(x); }
  public:
    X(int x) { validate(x); }
    X() { validate(42); }
    X(string s) { int x = std::stoi(s); validate(x); }
  };
}

namespace with_delegating {
  class X {
    int a;
  public:
    X(int x) { if(0 < x && x <= max) a = x; else throw Bad_X(x); }
    X() :X{42} {}
    X(string s) :X{std::stoi(s)} {}
    // ...
  };
}

int main() {
}
