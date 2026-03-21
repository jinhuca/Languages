// C13050101_noexception_functions.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <exception>

void throw_exception() {
  throw std::runtime_error("I give up.");
}

double compute(double d) noexcept {    // may not throw an exception
  std::string s = "Courtney and Anya";
  std::vector<double> tmp(10);
  // ...
  throw_exception();
  return d * 2.0;
}

int main() {
  std::cout << compute(123.45) << '\n';
}
