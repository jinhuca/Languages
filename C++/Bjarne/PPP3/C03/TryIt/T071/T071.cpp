// T071.cpp.
import std;

int square(int);

int main()
{
  int x = 4;
  std::cout << "Square of " << x << " is: " << square(x) << '\n';
}

int square(int x)
{
  int result = x;
  for (int i = 1; i < x; ++i)
  {
    result += x;
  }
  return result;
}
