// P1034.cpp : Character classification.
#include <ctype.h>
import std;

int main()
{
  char c = ' ';
  std::cout << "c is a space  : " << (bool)isspace(c) << '\n';
  std::cout << "c is blank    : " << (bool)isblank(c) << '\n';
  std::cout << "c is alpha    : " << (bool)isalpha(c) << '\n';

  int i = 12;
  char c1 = std::char_traits<char>::to_char_type(i);
  char c2 = (char)i;
  std::cout << c1 << '\n';
  std::cout << c2 << '\n';
}
