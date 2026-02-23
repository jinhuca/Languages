// C0444_unordered_map.cpp
import std;

std::unordered_map<std::string, int> phone_book {
  { "David Hume", 123456 },
  { "Karl Popper", 234567 },
  { "Bertrand Arthur", 345678 }
};

int get_number(std::string n) {
  return phone_book[n];
}

int main() {
  std::cout << get_number("David Hume") << '\n';
}
