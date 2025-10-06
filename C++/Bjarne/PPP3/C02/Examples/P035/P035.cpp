// P035.cpp
import std;

int main()
{
  std::cout << "Please enter a floating-point value: ";
  double n = 0;
  std::cin >> n;
  std::cout << "n == " << n
    << "\nn + 1 == " << n + 1
    << "\nthree times n == " << 3 * n
    << "\ntwice n == " << n + n
    << "\nn squared == " << n * n
    << "\nhalf of n == " << n / 2
    << "\nsquare root of n == " << std::sqrt(n)
    << '\n';
}
