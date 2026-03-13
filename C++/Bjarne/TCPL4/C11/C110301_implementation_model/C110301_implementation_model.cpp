// C110301_implementation_model.cpp 
#include <iostream>
#include <vector>
#include <initializer_list>

void h() {
  std::vector<double> v1 = {1, 2, 3.14};

  // the above initialization is implemented as 
  const std::initializer_list<double> tmp{double{1}, double{2}, 3.14};
  std::vector<double> v2(tmp);
}

void f() {
  std::initializer_list<int> lst{1,2,3};
  std::cout << *lst.begin() << '\n';
  //*lst.begin() = 2;                   // error: lst is immutable
  std::cout << *lst.begin() << '\n';
}

int main() {
  h();
  f();
}
