// C0101_ComparisonBeforeCpp20.cpp 
import std;
import Item;

void use_comparison() {
  Item item1(1);
  Item item2(2);
  std::cout << std::boolalpha 
    << "are they unequal? - " << (item1 != item2) << '\n';
  std::cout << "item1 < item2? - " << (item1 < item2) << '\n';
  std::cout << "item1 >= item2? - " << (item1 >= item2) << '\n';
}

int main() {
  use_comparison();
}
