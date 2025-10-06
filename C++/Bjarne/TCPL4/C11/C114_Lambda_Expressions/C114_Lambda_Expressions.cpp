// C114_Lambda_Expressions.cpp 
import std;

void print_modulo(const std::vector<int>& v, std::ostream& os, int m) {
  // output v[i] to os if v[i]%m == 0
  std::for_each(
    std::begin(v),
    std::end(v),
    [&os, m](int x) {if(x % m == 0) os << x << '\n'; });
}

class Modulo_print {
  std::ostream& os;     // members to hold the capture list
  int m;
public:
  Modulo_print(std::ostream& s, int mm) :os(s), m(mm) {}
  void operator()(int x) const {
    if(x % m == 0) os << x << '\n';
  }
};

void print_modulo2(const std::vector<int>& v, std::ostream& os, int m) {
  std::for_each(
    std::begin(v),
    std::end(v),
    Modulo_print { os, m });
}

void test() {
  std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
  print_modulo(v, std::cout, 3);

  /*Modulo_print mp { std::cout, 3 };*/
  print_modulo2(v, std::cout, 3);
}

int main() {
  test();
}
