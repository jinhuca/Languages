// C17050101_Default_Constructors.cpp 
import std;

class X {
  std::string s;
  std::string s2;
  std::vector<std::string> v;

  X() {
  }

  X(const X& a)       // copy constructor
    : s { a.s }, s2 { a.s2 }, v { a.v } {     // probably sloppy and probably wrong
  }
  // ...
};

void f() {
  const X x1();
}

int main() {
  f();
}
