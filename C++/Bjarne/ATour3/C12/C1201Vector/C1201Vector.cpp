// C1201Vector.cpp : std::vector samples - P158
import std;

struct Entry {
  std::string name;
  int number;
};

std::istream& operator>>(std::istream& is, Entry& en) {
  is >> en.name >> en.number;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Entry& en) {
  os << en.name << "\t" << en.number << '\n';
  return os;
}

void print_book(const std::vector<Entry>& book) {
  for(const auto& b : book)
    std::cout << b;
}

void iterateBook() {
  std::vector<Entry> phone_book = {
    { "David Hume", 123456 },
    { "Karl Popper", 234567 },
    { "Bert Russell",345678 }
  };
  print_book(phone_book);
}

void initialize_vectors()
{
  std::vector<int> v1 { 1,2,3,4 };
  std::vector<std::string> v2;
  std::vector<int*> v3(23);
  std::vector<double> v4(32, 9.9);
}

int main() {
  //iterateBook();
  initialize_vectors();
}
