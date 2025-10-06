// P106.cpp : Concept-based overloading.
import std;

template<std::forward_iterator Iterator>
void advance(Iterator p, int n)
{
  while(n--)
    ++p;
  std::cout << *p << std::endl;
}

template<std::random_access_iterator Iterator>
void advance(Iterator p, int n)
{
  p += n;
  std::cout << *p << std::endl;
}

void use(std::vector<int>::iterator vip, std::list<std::string>::iterator lip)
{
  advance(vip, 2);
  advance(lip, 2);
}

int main()
{
  std::vector<int> vec = {1, 2, 3, 4, 5, 6};
  std::list<std::string> lst = { "hello", "C++", "concept" };
  use(vec.begin(), lst.begin());
}
