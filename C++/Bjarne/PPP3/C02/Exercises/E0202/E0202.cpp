// E0202.cpp: convert mile to km
import std;

int main()
{
  std::cout << "Enter the value of miles to convert: ";
  double miles;
  std::cin >> miles;
  std::cout << "It is equivalent to " << miles * 1.609 << " kilometers";
}
