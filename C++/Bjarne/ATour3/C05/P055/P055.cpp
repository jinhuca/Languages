import std;
import complex;

namespace P055
{
  void f(const complex &x, const complex &y)
  {
    std::cout << "x = " << x;
    std::cout << "y = " << y;

    std::cout << "x + y = ";
    std::cout << x + y;

    std::cout << "x - y = ";
    std::cout << x - y;

    std::cout << "x * y = ";
    std::cout << x * y;

    std::cout << "x / y = ";
    std::cout << x / y;

    std::cout << "x *= y = ";
    std::cout << (x *= y);

    std::cout << "x /= y = ";
    std::cout << (x /= y);

    std::cout << "x == y is ";
    std::cout << (x == y) << std::endl;

    std::cout << "x != y is ";
    std::cout << (x != y) << std::endl;

    std::cout << -x;
    std::cout << -y << std::endl;
  }
}

int main()
{
  const P055::complex x = { 1, 0 };
  const P055::complex y = { 3, 4 };
  f(x, y);
}
