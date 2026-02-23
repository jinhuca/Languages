// C0433_IO_UserDefinedTypes.cpp
import std;

struct Entry {
  std::string name;
  int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\," << e.number << '}';
}

void simple_ostream_demo() {
  Entry e { "Eric",12345 };
  std::cout << e << '\n';
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

void g() {
  for (Entry ee; std::cin >> ee;)
    std::cout << " -- " << ee << '\n';
}

int main() {
  simple_ostream_demo();
  g();
}
