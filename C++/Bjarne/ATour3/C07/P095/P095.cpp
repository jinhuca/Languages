import std;

template<typename C, typename P>
int count(const C &c, P pred)     // assume that C is a container and P is a predicate on its elements
{
  int cnt = 0;
  for(const auto &x : c)
    if(pred(x))
      ++cnt;
  return cnt;
}

void f(const std::vector<int> &vec, const std::list<std::string> &lst, int x, const std::string &s)
{
  std::cout << "number of values less than " << x << ": "
    << count(vec, [&](int a) { return a < x; }) << std::endl;
  std::cout << "number of values less than " << x << ": "
    << count(lst, [&](const std::string &a) { return a < s; }) << std::endl;
}

int main()
{
  auto vec = std::vector<int> { 1, 2, 3, 4, 5, 6 };
  auto lst = std::list<std::string> { "abc", "def", "ghi", "xyz" };
  f(vec, lst, 2, "hel");
}
