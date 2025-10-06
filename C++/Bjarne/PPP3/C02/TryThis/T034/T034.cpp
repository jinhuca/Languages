// T034.cpp
import std;

int main()
{
  std::cout << "Please enter your name and age: \n";
  std::string name;
  double age;
  std::cin >> name >> age;
  std::cout << "Hello, " << name << ", you are " << age * 12 << " months old.\n";
}
