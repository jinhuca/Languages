// Ex01_04_Function_Object_With_Capture.cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

struct PrinterEx {
  PrinterEx(const std::string& str) :strText(str), numCalls(0) {}
  void operator()(int x) {
    std::cout << strText << x << '\n';
    ++numCalls;
  }
  std::string strText;
  int numCalls;
};

int main()
{
  std::vector<int> v;
  v.push_back(1);    // no uniform initialization in C++03!
  v.push_back(2);    // push_back available only ...
  const std::string introText("Elem: ");
  const PrinterEx vis = std::for_each(v.begin(), v.end(), PrinterEx(introText));
  std::cout << "num calls: " << vis.numCalls << '\n';
}
