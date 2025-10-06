import std;

template<typename T>
void print_elements(T coll) {
  for (const auto& e : coll) {
    std::cout << e << ' ';
  }
  std::cout << std::endl;
}