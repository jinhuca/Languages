// C1202List.cpp
import std;
using namespace std::string_literals;

struct Entry {
  std::string name;
  int number;
};

std::list<Entry> phone_book {
  { "David Hume", 123456 },
  { "Karl Popper", 234567 },
  { "Bert Russell",345678 }
};

int get_number(const std::string& s) {
  for(const auto& x : phone_book)
    if(x.name == s)
      return x.number;
  return 0;
}

int main() {
  std::cout << get_number("David Hume"s) << '\n';
}
