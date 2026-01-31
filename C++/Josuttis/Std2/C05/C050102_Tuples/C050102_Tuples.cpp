// C050102_Tuples.cpp 
#include <tuple>
#include <iostream>
#include <complex>
#include <string>

int main() {
  // create a four-element tuple
  // - elements are initialized with default value (0 for fundamental types)
  std::tuple<int, float, std::string> t1(41, 6.3, "nico");

  // "iterate" over elements:
  std::cout << get<0>(t1) << ' ';
  std::cout << get<1>(t1) << ' ';
  std::cout << get<2>(t1) << '\n';

  // create tuple with make_tuple()
  // - auto declares t2 with type right-hand side
  // - thus, type of t2 is tuple
  auto t2 = std::make_tuple(22, 44.1, "stefan");

  // assign second value in t2 to t1
  std::get<1>(t1) = std::get<1>(t2);

  // comparison and assignment
  // - including type conversion from tuple<int, int, const char*>
  // to tuple<int, float, string>
  if(t1 < t2) {   // compares value for value
    t1 = t2;      // OK, assigns value for value
  }
}
