// C1045_Address_Constants.cpp 
import std;

constexpr const char* p1 = "asdfds";
constexpr const char* p2 = p1;
constexpr const char* p3 = p1 + 2;
constexpr char c = p1[2];

int main() {
  std::cout << p1 << '\n';
  std::cout << p2 << '\n';
  std::cout << p3 << '\n';
  std::cout << c << '\n';
}
