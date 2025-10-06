// P023.cpp : an implicit and explicit generic constructor
import std;

struct Implicit {
  template<typename T>
  Implicit(T t) {
    std::cout << t << '\n';
  }
};

struct Explicit {
  template<typename T>
  explicit Explicit(T t) {
    std::cout << t << '\n';
  }
};

int main()
{
  //Explicit exp1 = "implicit";     // 'initializing': cannot convert from 'const char [9]' to 'Explicit'
  Explicit exp2 { "explicit" };
}
