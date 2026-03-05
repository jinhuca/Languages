// C0955_Exit.cpp 
import std;

void f(std::vector<std::string>& v, char terminator) {
  char c;
  std::string s;
  while (std::cin >> c) {
    // ...
    if (c == terminator) break;
    // ...
  }
}

int main() {
  std::vector<std::string> v;
  char terminator = 'x';
  f(v, terminator);
}
