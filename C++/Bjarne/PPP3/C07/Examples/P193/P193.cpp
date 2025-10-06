// P193.cpp : Pass-by-value.
import std;

// pass-by-value (give the function a copy of the value passed)
int f(int x)
{
  x = x + 1;        // give the local x a new value
  return x;
}

int main()
{
  int xx = 0;
  std::cout << f(xx) << '\n';     // write: 1
  std::cout << xx << '\n';        // write: 0; f() doesn't change xx

  int yy = 7;
  std::cout << f(yy) << '\n';     // write: 8
  std::cout << yy << '\n';        // write: 7; f() doesn't change yy
}
