// C11040304_mutable_lambda.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const std::vector<int>& v) {
  std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ' '; });
  std::cout << '\n';
}

void algo(std::vector<int>& v) {
  int count = v.size();
  std::generate(v.begin(), v.end(), [count]()mutable { return --count; });
}

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7,8};
  print_vector(v);
  algo(v);
  print_vector(v);
}
