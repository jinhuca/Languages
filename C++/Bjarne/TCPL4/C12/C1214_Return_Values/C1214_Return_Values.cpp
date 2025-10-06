// C1214_Return_Values.cpp 
import std;

std::string to_string(int a);           // prefix return type
auto to_string(int a) -> std::string;   // suffix return type

template<typename T, typename U>
auto product(const std::vector<T>& x, const std::vector<U>& y) -> decltype(x* y) {
  return x * y;
}

int fac(int n) {
  return (n > 1) ? n * fac(n - 1) : 1;
}

int* fp() {
  int local = 1;
  return &local;
}

void g(int* p) {
  return;
}

void h(int* p) {
  //...
  return g(p);    // OK: equivalent to "g(p); return;"
}

int& fr() {
  int local = 2;
  return local;
}

int main() {
  std::cout << fac(12) << '\n';
  std::cout << *fp() << '\n';
  std::cout << fr() << '\n';
}
