// C030201_Three_Ways_Comparison.cpp 
import std;

struct MyInt {
  int value;
  MyInt(int v) : value(v) {}
  auto operator<=>(const MyInt& other) const = default;
};

int main() {
  MyInt a {5}, b {10};
  std::cout << std::boolalpha;
  std::cout << "a {5} == b {10} is " << (a == b) << '\n';
  std::cout << "a {5} < b {10} is " << (a < b) << '\n';
  std::cout << "a {5} > b {10} is " << (a > b) << '\n';
}
