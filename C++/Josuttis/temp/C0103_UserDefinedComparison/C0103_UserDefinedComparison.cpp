// C0103_UserDefinedComparison.cpp 
import std;
import Coordinate;

void use_comparison() {
  Coordinate coord1 {1, 3};
  Coordinate coord2 {2, 4};
  std::cout << std::boolalpha 
    << "are they unequal? - " << (coord1 != coord2) << '\n';
  std::cout << (coord1 >= coord2) << '\n';
}

int main() {
  use_comparison();
}
