// P164.cpp :
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
  auto key = "David Hume";
  std::cout << "key = " << key << ", " << "Value = " << get_number(key) << '\n';
}
