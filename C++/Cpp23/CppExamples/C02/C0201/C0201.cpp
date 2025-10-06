import std;

void generate_triangle() {
  const std::vector data { 1 };
  for(auto number : data) {
    std::cout << number << ' ';
  }
  std::cout << '\n';
}

int main() {
  generate_triangle();
}