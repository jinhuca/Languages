// C045_algorithm.cpp
import std;

struct Entry {
  std::string name;
  int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\," << e.number << '}';
}

void print_book(std::list<Entry>& lst) {
  for(const auto& b : lst)
    std::cout << b << '\n';
}

bool operator<(const Entry& x, const Entry& y) {
  return x.name < y.name;
}

bool operator==(const Entry& x, const Entry& y) {
  return x.name == y.name;
}

bool operator!=(const Entry& x, const Entry& y) {
  return x.name != y.name;
}

std::vector<Entry> phone_book {
  { "David Hume", 123456 },
  { "Karl Popper", 234567 },
  { "Bertrand Arthur", 345678 },
  { "David Hume", 323456 },
};

std::list<Entry> phone_list(3);

void f(std::vector<Entry>& vec, std::list<Entry>& lst) {
  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.begin(), vec.end(), lst.begin());
}

std::list<Entry> f(std::vector<Entry>& vec) {
  std::list<Entry> res;
  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.begin(), vec.end(), std::back_inserter(res));
  return res;
}

void unique_copy_demo() {
  auto lst = f(phone_book);
  print_book(lst);
}

int main() {
  //f(phone_book, phone_list);
  //for(const auto& e : phone_list)
  //  std::cout << e.name << " - " << e.number << '\n';
  unique_copy_demo();
}
