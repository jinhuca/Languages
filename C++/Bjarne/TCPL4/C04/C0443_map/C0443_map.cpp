// C0443_map.cpp
import std;

//struct Entry {
//  std::string name;
//  int number;
//};

std::map<std::string, int> phone_book {
  { "John", 123456 },
  { "Doe",  234567 }
};

int get_number(std::string n) {
  return phone_book[n];
}

int main() {
  std::cout << get_number("John") << '\n';
  std::cout << get_number("Joe") << '\n';
}
