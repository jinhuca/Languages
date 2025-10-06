import std;

auto main() -> int {
  std::cout << std::plus<int>{}(1, 1.23) << '\n';   // Enforces a sum of two ints, so returns 2
  std::cout << std::plus<>{}(1, 1.23) << '\n';      // Figures out the different types
}