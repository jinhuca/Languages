// P0173.cpp : list1.
import std;

int main()
{
  std::list<char> coll;
  for (char c = 'a'; c <= 'z'; ++c) {
    coll.push_back(c);
  }
  for (const auto& e : coll) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}
