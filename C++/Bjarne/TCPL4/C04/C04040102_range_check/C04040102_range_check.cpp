// C04412_RangeCheck.cpp
import std;

template<typename T>
class Vec : public std::vector<T> {
public:
  using std::vector<T>::vector;   // use the constructors from std::vector
  T& operator[](int i) { return std::vector<T>::at(i); }
  const T& operator[](int i) const { return std::vector<T>::at(i); }
};

struct Entry {
  std::string name;
  int number;
};

Vec<Entry> book = {
  { "John", 1234567 },
  { "Doe", 2345678 }
};

void checked() {
  try {
    book[book.size()] = { "Joe", 999999 };
    // ...
  }
  catch (std::out_of_range& e) {
    std::cerr << e.what() << '\n';
  }
}

int main()
try {
  book[book.size()] = { "Joe",777777 };
}
catch (...) {
  std::cerr << "unknown exception thrown.\n";
}
