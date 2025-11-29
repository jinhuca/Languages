// C0102_EqualityInCpp20.cpp 
import std;
import Item;

void use_equality() {
  Item item1(1);
  Item item2(2);
  std::cout << std::boolalpha 
    << "are they equal? - " << (item1 == item2) << '\n';
  std::cout << "are they unequal? - " << (item1 != item2) << '\n';
}

int main() {
  use_equality();
}
