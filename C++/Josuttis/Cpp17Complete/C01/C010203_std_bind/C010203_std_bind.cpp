// C010203_std_bind.cpp 
#include <iostream>
#include <array>

std::array<int, 4> getArray() {
  return std::array<int, 4> {1, 2, 3, 4};
}

void bind_std_array() {
  auto [a, b, c, d] = getArray();
}

void bind() {
  std::array<int, 4> stdarr{ 1, 2, 3, 4 };
  
  auto& [a, b, c, d] = stdarr;
  a += 10;    // OK: modifies stdarr[0]

  const auto& [e, f, g, h] = stdarr;
  //e += 10;    // ERROR: reference to constant object

  auto&& [i, j, k, l] = stdarr;
  i += 10;      // OK: modifies stdarr[0]

  auto [m, n, o, p] = stdarr;
  m += 10;      // OK: modifies m, a copy of stdarr[0], not stdarr[0]
}

int main() {
  bind();
}
