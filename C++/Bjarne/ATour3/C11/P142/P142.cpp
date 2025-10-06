// P142.cpp
#include <iostream>
#include <string>

struct Entry
{
  std::string name;
  long number;
};

std::ostream &operator<<(std::ostream &os, const Entry &e)
{
  return os << "{\"" << e.name << "\", " << e.number << "}";
}

void outputEntry()
{
  Entry e1 { "Jin Hu", 0123 };
  std::cout << e1 << std::endl;
}

std::istream &operator>>(std::istream &is, Entry &e)
{
  char c, c2;
  if(is >> c && c == '{' && is >> c2 && c2 == '"')
  {
    std::string name;
    while(is.get(c) && c != '"')
      name += c;
    if(is >> c && c == ',')
    {
      int number = 0;
      if(is >> number >> c && c == '}')
      {
        e = { name,number };
        return is;
      }
    }
  }
  is.setstate(std::ios_base::failbit);
  return is;
}

void inputEntry()
{
  for(Entry ee; std::cin >> ee;)
    std::cout << ee << std::endl;
}

int main()
{
  outputEntry();
  inputEntry();
}
