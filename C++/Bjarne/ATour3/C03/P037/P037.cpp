import std;

int sum(const std::vector<int>& v)
{
  int s = 0;
  for (const int i : v)
  {
    s += i;
  }
  return s;
}

int main()
{
  std::vector fib = { 1, 2, 3, 5, 8, 13, 21 };
  int x = sum(fib);
  std::cout << x << '\n';
}
