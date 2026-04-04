// C17050101_beware_of_default_constructors.cpp 
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class X {
  string s;
  string s2;
  vector<string> v;
public:
  X(string ss, string ss2, vector<string> vs)
    : s{ss}, s2{ss2}, v{vs} {
  }

  X() {}
  
  X(const X& a)         // copy constructor
    : s{a.s}, v{a.v}    // probably sloppy and probably wrong
  {}
  // ...
};

int main() {
  X x1{"hello", "C++", {"bye"}};
  X x2{x1};             // use our sloppy and buggy copy constructor
}
