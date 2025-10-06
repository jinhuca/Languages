// P017.cpp : three-way comparison operator
import std;

struct MyInt {
  int value;
  MyInt(int val) : value { val } {}
  auto operator<=>(const MyInt&) const = default;
};

int main()
{
  const MyInt a = MyInt(2);
  const MyInt b = MyInt(3);
  std::cout << std::boolalpha;
  std::cout << "(a  <  b) = " << (a < b) << '\n';
  std::cout << "(a  <= b) = " << (a <= b) << '\n';
  std::cout << "(a  >  b) = " << (a > b) << '\n';
  std::cout << "(a  >= b) = " << (a >= b) << '\n';
  std::cout << "(a  == b) = " << (a == b) << '\n';
  std::cout << "(a  != b) = " << (a != b) << '\n';
}
