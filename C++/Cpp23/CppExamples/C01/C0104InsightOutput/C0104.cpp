import std;

int main() {
  std::operator<<
    (
      std::cout.operator<<
      (
        std::plus<int>{}.operator()(1, static_cast<const int>(1.23))
        ),
      '\n'
      );
  std::operator<<
    (
      std::cout.operator<<
      (
        std::plus<void>{}.operator()(1, 1.23)
        ),
      '\n'
      );
  return 0;
}