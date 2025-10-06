// C0101ComparisonBeforeCpp20.cpp
import std;
import Value;

// Using traditional comparison operators
void use_comparison() {
  Value v1{ 3 }, v2{ 11 };
  if(v1 < v2) {
    std::cout << "v1 is less than v2\n";
  }
  else {
    std::cout << "v1 is not less than v2\n";
  }
}

void use_comparison_indirectly() {
  Value v0{9}, v1{ 3 }, v2{ 11 }, v3{0};
  std::vector<Value> vec{ v0, v1, v2, v3 };
  std::ranges::sort(vec);
  for(const auto& v : vec) {
    std::cout << v << ' ';
  }
}

int main() {
  use_comparison();
  use_comparison_indirectly();
}
