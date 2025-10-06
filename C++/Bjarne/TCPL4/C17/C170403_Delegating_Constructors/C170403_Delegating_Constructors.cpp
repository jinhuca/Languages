// C170403_Delegating_Constructors.cpp 
import std;
#include <climits>

class Bad_X {
  int x;
public:
  Bad_X(int a) :x { a } { };
};

class X {
  int a;
  void validate(int x) {
    if (0 < x && x <= INT_MAX) a = x;
    else throw Bad_X(x);
  }
public:
  X(int x) { validate(x); }
  X() :X(42) { }
  X(std::string s) :X { std::stoi(s) } { }
};

int main() {
  X();
  X { 12 };
  X("72");
}
