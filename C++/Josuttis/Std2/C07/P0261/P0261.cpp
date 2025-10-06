// P0261.cpp : std::array
import std;

template<typename T>
void print_elements(T coll) {
  for (const auto& e : coll) {
    std::cout << e << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  std::array<int, 10> a { 11, 22, 33, 44 };
  print_elements(a);
}
