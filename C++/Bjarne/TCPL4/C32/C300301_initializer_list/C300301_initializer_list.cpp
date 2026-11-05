// C300301_initializer_list.cpp 
#include <iostream>
#include <initializer_list>

void f(std::initializer_list<int> lst) {
  for(int i = 0; i < lst.size(); ++i) {
    //std::cout << lst[i] << ' ';       // This is not valid, std::initializer_list does not support operator[]
  }

  const int* p = lst.begin();
  for(int i = 0; i < lst.size(); ++i) {
    std::cout << p[i] << ' ';         // This is valid, std::initializer_list supports begin() and end()
  }
  std::cout << '\n';

  for(int i = 0; i < lst.size(); ++i) {
    std::cout << lst.begin()[i] << ' ';     // This is valid, std::initializer_list supports begin() and end()
  }
  std::cout << '\n';

  for (const auto& elem : lst) {
    std::cout << elem << ' ';           // This is valid, std::initializer_list supports range-based for loop
  }
  std::cout << '\n';
}

int main() {
  f({1, 2, 3, 4, 5});
  return 0;
}
