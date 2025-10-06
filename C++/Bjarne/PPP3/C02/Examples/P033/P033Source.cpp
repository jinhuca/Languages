import std;

void readNameAge()
{
  std::cout << "Please enter your first name and age\n";
  std::string first_name = "???";
  int age = -1;
  std::cin >> first_name >> age;
  std::cout << "Hello, " << first_name << " (age " << age << ")\n";
}

void readFirstLastNames()
{
  std::cout << "Please enter your first and second names\n";
  std::string first;
  std::string second;
  std::cin >> first >> second;
  std::cout << "Hello, " << first << " " << second << '\n';
}

int main()
{
  readFirstLastNames();
}