import std;

void readFirstSecondNames()
{
  std::cout << "Please enter your first and second names\n";
  std::string first;
  std::string second;
  std::cin >> first >> second;

  std::string name = first + ' ' + second;
  std::cout << "Hello, " << name << '\n';
}

void readCompareNames()
{
  std::cout << "Please enter two names\n";
  std::string first;
  std::string second;
  std::cin >> first >> second;    // read two strings

  if (first == second)
    std::cout << "that's the same name twice\n";
  if (first < second)
    std::cout << first << " is alphabetically before " << second << '\n';
  if (first > second)
    std::cout << first << " is alphabetically after " << second << '\n';
}

int main()
{
  readCompareNames();
}