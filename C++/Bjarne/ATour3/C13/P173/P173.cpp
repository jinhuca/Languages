// P173.cpp
import std;

void f(std::vector<int> &vec, std::list<int> &lst)
{
  sort(vec.begin(), vec.end());                         // use < for order
  unique_copy(vec.begin(), vec.end(), lst.begin());     // don't copy adjacent equal elements
}

void g()
{
  std::vector<int> v1 { 9, 11, 1, 2, 3, 5, 7, 8 };
  std::vector<int> v2(12);

  std::ranges::copy(v1.begin(), v1.end(), v2.begin());
  for(const auto &x : v2)
    std::cout << x << ' ';

  std::cout << std::endl;

  std::ranges::sort(v2);
  for(const auto &x : v2)
    std::cout << x << ' ';
  std::cout << std::endl;
}

bool has_c(const std::string &s, char c)
{
  const auto p = std::ranges::find(s, c);
  if(p != s.end())
    return true;
  return false;
}

int main()
{
  g();

  if(has_c("hello, world!", 'e'))
  {
    std::cout << "found.";
  }
  else
  {
    std::cout << "no found.";
  }
}
