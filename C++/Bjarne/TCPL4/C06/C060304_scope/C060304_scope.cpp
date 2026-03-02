// C060304_scope.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <list>

int x = 97;

void f3() {
  //int x = x;  // error: x is not yet declared, so it cannot be used to initialize itself.
}

void f(std::vector<std::string>& v, std::list<int>& lst) {
  for(const auto& x : v) std::cout << x << '\n';  // x is a const std::string& that refers to each element of v in turn.
  for(auto x : lst) std::cout << x << '\n';  // x is an int that is initialized by copying each element of lst in turn.
  for(int i = 0; i != v.size(); ++i) std::cout << v[i] << '\n';  // i is an int that is initialized to 0 and incremented until it reaches v.size().
  for(auto i : {1,2,3,4,5,6,7}) std::cout << i << '\n';  // i is an int that is initialized by copying each element of the initializer list in turn.
}

int main() {
  f3();
  std::vector<std::string> v {"one", "two", "three"};
  std::list<int> lst {1, 2, 3, 4, 5};
  f(v, lst);
}
