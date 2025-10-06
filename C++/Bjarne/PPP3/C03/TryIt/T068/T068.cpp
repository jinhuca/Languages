// T068.cpp.
import std;

int main()
{
  for (int i = 'a'; i <= 'z'; ++i)
  {
    std::cout << (char)i << '\t' << (int)i << '\n';
  }

  for (int i = 'A'; i <= 'Z'; ++i)
  {
    std::cout << (char)i << '\t' << (int)i << '\n';
  }

  for (int i = '0'; i <= '9'; ++i)
  {
    std::cout << (char)i << '\t' << (int)i << '\n';
  }
}
