// C0441_vector.cpp
import std;

struct Entry {
  std::string name;
  int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
  return os << "{ " << e.name << ", " << e.number << " }";
}

// read { "name", number } pair. Note: formatted with { "", and }
std::istream& operator>>(std::istream& is, Entry& e) {
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {   // start with a { "
    std::string name;                     // the default value of a string is the empty string: ""
    while (is.get(c) && c != '"') {       // anything before a " is part of the name
      name += c;
    }
    if (is >> c && c == ',') {
      int number;
      if (is >> number >> c && c == '}') {
        e = { name, number };
        return is;
      }
    }
  }
  is.setstate(std::ios_base::failbit);    // register the failure in the stream
  return is;
}

std::vector<Entry> create_book() {
  std::vector<Entry> book = {
    {"David Hume", 123456},
    {"Karl Popper",234567},
    {"Bertrand Arthur",345678}
  };
  return book;
}

void print_book(const std::vector<Entry>& book) {
  for (const auto& b : book)
    std::cout << b << '\n';
}

class Shape {

};

void init_size() {
  std::vector<int> v1 { 1,2,3,4 };
  std::vector<std::string> v2;
  std::vector<Shape*> v3(23);
  std::vector<std::unique_ptr<Shape>> v4(32);
  std::vector<double> v5(32.9, 91);
}

std::vector<Entry> phone_book;

void input() {
  for (Entry e; std::cin >> e;)
    phone_book.push_back(e);
}

auto j = 12;
auto k() -> void {
  std::vector<int> v1;
  v1.push_back(j);
  v1[0] = 13;
  std::cout << "j = " << j << '\n';
  std::cout << "v1[0] = " << v1[0] << '\n';
}

void silly(std::vector<Entry>& book) {
  int i = book[book.size()].number;
}

int main() {
  //print_book(create_book());
  //init_size();
  //k();
  create_book();
  //silly(phone_book);
}
