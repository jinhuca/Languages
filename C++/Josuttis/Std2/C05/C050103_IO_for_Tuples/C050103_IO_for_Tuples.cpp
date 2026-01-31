// C050103_IO_for_Tuples.cpp 
#include <tuple>
#include <iostream>
#include <string>
#include "printtuple.h"

int main() {
  std::tuple<int, float, std::string> t(77, 1.1, "more light");
  std::cout << t << '\n';
}
