// P078.cpp : 
import std;

void printSmallerLargerInts(int x, int y)
{
  if (x == y)
    std::cout << "the numbers are equal\n";
  else if (x < y)
    std::cout << "the smaller value is: " << x << '\n'
    << "the larger value is: " << y << '\n';
  else
    std::cout << "the smaller value is: " << y << '\n'
    << "the larger value is: " << x << '\n';
}

int main()
{
  std::cout << "Enter two integers, end by |\n";
  int x, y;
  while (std::cin >> x >> y)
  {
    printSmallerLargerInts(x, y);
    //std::cout << x << ' ' << y << '\n';
  }
}
