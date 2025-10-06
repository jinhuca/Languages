import std;
import print_module;

// v is passed by value; rv is passed by reference
void test(std::vector<int> v, std::vector<int>& rv)
{
  v[1] = 99;        // modifying v (a local variable)
  rv[2] = 66;       // modifying whatever rv refers to
}

int main()
{
  std::vector<int> fib = { 1, 2, 3, 5, 8, 13, 21 };
  test(fib, fib);
  std::cout << fib[1] << " " << fib[2] << '\n';

  print(6,16);
  print(6);
}
