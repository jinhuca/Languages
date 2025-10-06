// E0205.cpp
import std;

int main()
{
  std::cout << "Enter two floating-point values: ";
  double val1, val2;
  std::cin >> val1 >> val2;

  if (val1 == val2)
    std::cout << "The two integers are equal.\n";
  else if (val1 > val2)
    std::cout << val1 << " is larger than " << val2 << '\n';
  else
    std::cout << val1 << " is smaller than " << val2 << '\n';

  std::cout << "The sume of the two is: " << val1 + val2 << '\n';
  std::cout << "The difference of the two is: " << val1 - val2 << '\n';
  std::cout << "The product of the two is: " << val1 * val2 << '\n';
  std::cout << "The ratio of the two is: " << val1 / val2 << '\n';
}
