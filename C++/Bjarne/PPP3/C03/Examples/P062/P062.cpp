// P062.cpp
import std;

int main()
{
  constexpr double cm_per_inch = 2.54;
  double length = 1;
  char unit = ' ';
  std::cout << "Please enter a length followed by a unit (c or i):\n";
  std::cin >> length >> unit;
  switch (unit)
  {
  case 'i':
    std::cout << length << "in == " << length * cm_per_inch << "cm\n";
    break;
  case 'c':
    std::cout << length << "cm == " << length / cm_per_inch << "in\n";
    break;
  default:
    std::cout << "Sorry, I don't know a unit called '" << unit << "'\n";
    break;
  }
}
