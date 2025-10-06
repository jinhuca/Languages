// P162.cpp: std::list examples.
import std;

struct Entry
{
  std::string name;
  int number;
};

std::list<Entry> phone_book = {

};

int get_number(const std::string& s)
{
  for(const auto &x : phone_book)
    if(x.name == s)
      return x.number;
  return 0;
}

void f(const Entry& ee, std::list<Entry>::iterator p, std::list<Entry>::iterator q)
{
  phone_book.insert(p, ee);
  phone_book.erase(q);
}

int main()
{
}
