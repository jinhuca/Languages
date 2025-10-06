// Ex01_03_Function_Object_With_State.cpp 
#include <algorithm>
#include <vector>
#include <iostream>

struct PrinterEx {
  PrinterEx() :numCalls(0) {}
  void operator()(int x) {
    std::cout << x << '\n';
    ++numCalls;
  }
  int numCalls;
};

int main() {
  std::vector<int> v;
  v.push_back(1);    // no uniform initialization in C++03!
  v.push_back(2);    // push_back available only ...
  const PrinterEx vis = std::for_each(v.begin(), v.end(), PrinterEx());
  std::cout << "num calls: " << vis.numCalls << '\n';
}
