// P041.cpp 
import std;
import complex;

struct Entry
{
  std::string name;
  int value;
};

Entry read_entry(std::istream& is)     // naive read function
{
  std::string s;
  int i;
  is >> s >> i;
  return { s, i };
}

void f()
{
  auto e = read_entry(std::cin);
  std::cout << "{ " << e.name << ", " << e.value << " }\n";
}

void g()
{
  auto [n, v] = read_entry(std::cin);
  std::cout << "{ " << n << ", " << v << " }\n";
}

void h()
{
  std::map<std::string, int> m;
  for (const auto [key, value] : m)
    std::cout << "{" << key << "," << value << "}\n";
}

void k()
{
  int a[2] = { 1, 2 };
  auto [x, y] = a;
  auto &[xr, yr] = a;
}

int main()
{
  k();
}