import std;

template<typename T, typename U>
auto simple_plus(T lhs, U rhs) -> decltype(lhs + rhs) {
  return lhs + rhs;
}

auto main() -> int {
  std::cout << simple_plus(1, 1.23) << '\n';
}