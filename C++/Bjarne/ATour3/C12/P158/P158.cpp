// P158.cpp : std::vector examples.
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
  os << en.name << "\t" << en.number << "\n";
  return os;
}

// access elements through subscription.
void print_book2(const std::vector<Entry>& book) {
  for (int i = 0; i != book.size(); ++i)
    std::cout << book[i];
}

// enable range-for-loop.
void print_book(const std::vector<Entry>& book) {
  for (const auto& i : book)
    std::cout << i;
}

void iterateVector() {
  std::vector<Entry> phone_book = {
    { "David Hume", 123456 },
    { "Karl Popper", 234567 },
    { "Bert Russell",345678 }
  };
  print_book(phone_book);
}

void InitializeVectors() {
  std::vector<int> v1 = { 1, 2, 3, 4 };         // size is 4
  std::vector<std::string> v2;                  // size is 0
  std::vector<Entry*> v3(23);             // size is 23; initial element value: nullptr
  std::vector<double> v4(32, 9.9);   // size is 32; initial element value: 9.9

  auto r1 = v1.at(2);
}

void input() {
  std::vector<Entry> phone_book;
  for (Entry e; std::cin >> e;)
    phone_book.push_back(e);
  auto c = phone_book.capacity();
}

int main() {
  InitializeVectors();
  //const std::vector<Entry> phone_book =
  //{
  //  { "David Hume", 123456 },
  //  { "Karl Popper", 234567 },
  //  { "B. Russell", 345678 }
  //};

  //print_book(phone_book);
  iterateVector();
}
