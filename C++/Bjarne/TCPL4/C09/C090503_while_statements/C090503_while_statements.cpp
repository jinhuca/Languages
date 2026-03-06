// C090503_while_statements.cpp 
#include <iostream>
#include <vector>
#include <string>

template<class Iter, class Value>
Iter findv(Iter first, Iter last, Value val) {
  while(first != last && *first != val)
    ++first;
  return first;
}

int main() {
  std::vector<int> v { 3, 5, 1, 3, 6, 7, 8, 5, 4 };
  auto result = findv(v.begin(), v.end(), 6);
  std::cout << (result != v.end() ? "found" : "not found") << '\n';
  std::cout << (result != v.end() ? std::to_string(*result) : "n/a") << '\n';
}
