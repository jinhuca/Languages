// P140.cpp
import std;

void demo_floating_point_format()
{
  std::cout << "enter an integer - ";
  int i;
  std::cin >> i;      // read an integer into i
  std::cout << i << std::endl;

  std::cout << "enter a double - ";
  double d;
  std::cin >> d;      // read a double-precision into d
  std::cout << d << std::endl;

  std::cout << "enter your name - ";
  std::string str;
  std::cin >> str;
  std::cout << "Hello, " << str << "!\n";
}

void g()
{
  std::cout << "enter your first and last name - ";
  std::string str2;
  std::getline(std::cin, str2);
  std::cout << "Hello, " << str2 << "!\n";
}

int main()
{
  //f();
  g();
}
