// C0101_deduction.cpp 
#include <iostream>

auto correct(int i) {
  if(i == 1) {
    return i;
  }
  return correct(i - 1) + i;
}

/*
auto wrong(int i) {
  if(i != 1) {
    return wrong(i - 1) + 1;    // Too soon to call this. No prior return statement.
  }
  return i;
}
*/

int main() {
  auto result = correct(5);
  std::cout << "Result: " << result << "\n";
}
