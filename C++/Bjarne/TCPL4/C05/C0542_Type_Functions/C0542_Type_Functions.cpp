// C0542_Type_Functions.cpp 
import std;

int main() {
  constexpr float min = std::numeric_limits<float>::min();  // smallest positive float
  std::cout << min << '\n';
  constexpr int szi = sizeof(int);
  std::cout << szi << '\n';
}
