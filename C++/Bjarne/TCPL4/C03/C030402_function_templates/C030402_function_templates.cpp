// C030402_function_templates.cpp 
import std;

template<typename Container, typename Value>
Value sum(const Container& c, Value v) {
  for (auto& x : c)
    v += x;
  return v;
}

void f() {
  std::vector<int> v { 1, 2, 3, 4, 5, 6, 7 };
  std::cout << sum(v, 0) << '\n';
}

void use(std::vector<int> vi, std::list<double> ld) {
  int x = sum(vi, 0);
  double d = sum(ld, 0.0);
}

int main() {
  f();
}
