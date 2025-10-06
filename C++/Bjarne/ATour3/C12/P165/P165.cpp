// P165.cpp : unordered_map
import std;

std::map<std::string, int> phone_book {
  { "David Hume", 123456 },
  { "Karl Popper", 234567 },
  { "Bert Russell", 345678 }
};

int get_number(const std::string &s)
{
  return phone_book[s];
}

int main()
{
  std::cout << "Hello World!\n";
}
