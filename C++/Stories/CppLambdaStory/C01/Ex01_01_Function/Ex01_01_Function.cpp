// Ex01_01_Function.cpp : A basic print function.
#include <algorithm>
#include <iostream>
#include <vector>

void PrintFunction(int x) {
  std::cout << x << '\n';
}

int main() {
  std::vector<int> v;
  v.push_back(1);    // no uniform initialization in C++03!
  v.push_back(2);    // push_back available only ...
  std::for_each(v.begin(), v.end(), PrintFunction);
}
