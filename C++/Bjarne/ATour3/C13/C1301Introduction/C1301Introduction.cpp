// C1301Introduction.cpp
import std;

struct Entry {
  std::string name;
  int number;
};

bool operator<(const Entry &x, const Entry &y) {
  return x.name < y.name;
}

bool operator==(const Entry &x, const Entry &y) {
  return x.name == y.name;
}

std::ostream &operator<<(std::ostream &os, const Entry &e) {
  return os << "{ " << e.name << " - " << e.number << " }";
}

// sort a vector of Entrys and place a copy of each unique vector element on a list
void f(std::vector<Entry> &vec, std::list<Entry> &lst) {
  std::sort(vec.begin(), vec.end());
  std::unique_copy(vec.begin(), vec.end(), lst.begin());
}

void read_and_sort() {
  std::vector<Entry> v {
    {"John Doe", 123456 },
    {"Jonathan Smith", 654321 },
    {"Andy Skeet", 345261 },
    {"John Doe", 123456 },
    {"Helen Helms", 987893 },
    {"Xavier Johnson", 327737}
  };
  for (const auto &e : v) {
    std::cout << e << '\n';
  }
  std::list<Entry> lst(6);
  f(v, lst);
  std::cout << "== After sorted ==\n";
  for (const auto &e : lst) {
    std::cout << e << '\n';
  }
}

int main() {
  read_and_sort();
}
