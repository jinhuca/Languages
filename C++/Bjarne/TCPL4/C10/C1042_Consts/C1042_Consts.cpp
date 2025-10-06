// C1042_Consts.cpp 
import std;

const int x = 7;
const std::string s = "asdf";
const int y = std::sqrt(x);

//constexpr int z = std::sqrt(7);     // std::sqrt is not constexpr function

constexpr int incr(const int x) {
  return x + 1;
}

constexpr int z = incr(x);

constexpr int xx = x;
//constexpr std::string ss = s;         // error: s is not a constant expression
//constexpr int yy = y;                 // error: sqrt(x) is not a constant expression

int main() {
  std::cout << "Hello World!\n";
}
