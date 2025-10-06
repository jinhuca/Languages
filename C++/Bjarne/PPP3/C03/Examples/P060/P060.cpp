// P060.cpp
import std;

int main()
{
  // convert from inches to centimeters or centimeters to inches
  // a suffix 'i' or 'c' indicates the unit of the input
  constexpr double cm_per_inch = 2.54;
  double length = 1;
  char unit = ' ';
  std::cout << "Please enter a length followed by a unit (c or i):\n";
  std::cin >> length >> unit;
  if (unit == 'i')
    std::cout << length << "in == " << length * cm_per_inch << "cm\n";
  else if (unit == 'c')
    std::cout << "cm == " << length / cm_per_inch << "in\n";
  else
    std::cout << "Sorry, I don't know a unit called '" << unit << "'\n";
}
