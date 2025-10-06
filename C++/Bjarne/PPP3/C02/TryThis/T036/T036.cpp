// T036.cpp
import std;

int main()
{
  std::cout << "Please enter an integer value: ";
  int i = 0;
  std::cin >> i;
  std::cout << "i == " << i
    << "\ni + 1 == " << i + 1
    << "\ntwice i == " << i + i
    << "\nn squared == " << i * i
    << "\nhalf of i == " << i / 2
    << "\nsquare root of i == " << std::sqrt(i)
    << "\n2 modulo of i == " << i % 2
    << '\n';
}
