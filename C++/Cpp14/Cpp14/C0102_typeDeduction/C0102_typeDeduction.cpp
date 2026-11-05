// C0102_typeDeduction.cpp 
#include <iostream>

int i = 1;
int&& f() { return static_cast<int&&>(i); }
auto x3a = i;               // int
decltype(i) x3d = i;        // int
auto x4a = (i);             // int&
decltype((i)) x4d = (i);    // int&
auto x5a = f();             // int&&
decltype(f()) x5d = f();    // int&&

int main() {
  std::cout << "decltype(i) x3d = " << typeid(x3d).name() << "\n";
  std::cout << "auto x4a = (i); = " << typeid(x4a).name() << "\n";
  std::cout << "decltype((i)) x4d = " << typeid(x4d).name() << "\n";
  std::cout << "auto x5a = f(); = " << typeid(x5a).name() << "\n";
  std::cout << "decltype(f()) x5d = " << typeid(x5d).name() << "\n";
}
