// C0342.cpp : Function template
import std;

template<typename Container, typename Value>
Value sum(const Container& c, Value v) {
  for(auto x : c)
    v += x;
  return v;
}

void f() {
  std::vector<int> v { 1, 2, 3, 4, 5, 6 };
  std::cout << sum(v, 0) << '\n';
}

int main() {
  f();
}
