// T067.cpp
import std;

int main()
{
  int x = 'a';
  while (x < 'a' + 26) {
    std::cout << static_cast<char>(x) << '\t' << x << '\n';
    ++x;
  }
}
