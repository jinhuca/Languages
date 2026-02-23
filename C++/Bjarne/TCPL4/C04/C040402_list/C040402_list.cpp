// C0442_list.cpp
import std;

struct Entry {
  std::string name;
  int number;
};

std::list<Entry> phone_book {
  {"John", 123456},
  {"Doe", 234567}
};

int get_number(const std::string s) {
  for (const auto& x : phone_book) {
    if (x.name == s)
      return x.number;
  }
  return 0; // use 0 to represent "number not found"
}

int get_number2(const std::string s) {
  for (auto p = phone_book.begin(); p != phone_book.end(); ++p) {
    if (p->name == s)
      return p->number;
  }
  return 0;
}

int main() {
  std::cout << get_number("John") << '\n';
  std::cout << get_number2("John") << '\n';
}
