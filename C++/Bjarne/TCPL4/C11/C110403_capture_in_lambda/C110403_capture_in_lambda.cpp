// C110403_capture_in_lambda.cpp 
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

void algo_without_capture_in_lambda(std::vector<int>& v) {
  std::sort(v.begin(), v.end());
  std::sort(v.begin(), v.end(), [](int x, int y) { return std::abs(x) < std::abs(y); });
}

void algo_with_capture_in_lambda(std::vector<int>& v) {
  bool sensitive = true;
  sort(v.begin(), v.end(),
    [sensitive](int x, int y) { return sensitive ? x < y : std::abs(x) < std::abs(y); });
}

template<typename... Var>
void algo(int s, Var... v) {
  auto helper = [&s, &v...] { return s * (h1(v...) + h2(v...)); };
}

int main() {
  std::vector<int> v {4,2,66,1,-2,3,4,-1,9,1,32,-45};
  algo_without_capture_in_lambda(v);
  v = {4,2,66,1,-2,3,4,-1,9,1,32,-45};
  algo_with_capture_in_lambda(v);
}
