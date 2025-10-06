// Ex02_01.cpp 
#include <algorithm>
#include <iostream>
#include <vector>

void use_lambda() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::for_each(vec.begin(), vec.end(), [](int n) { std::cout << n << " "; });
}

int main() {
  use_lambda();
}
