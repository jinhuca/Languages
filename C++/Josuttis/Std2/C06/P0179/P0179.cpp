// P0179.cpp : multimap1
import std;

int main()
{
  std::multimap<int, std::string> coll;
  coll = { 
    { 5, "tagged" },
    { 2, "a" },
    { 1, "this" },
    { 4, "of" },
    { 6, "strings" },
    { 1, "is" },
    { 3, "multimap" } };
  
  for (const auto& elem : coll) {
    std::cout << elem.first << ' ';
  }

  for (const auto& elem : coll) {
    std::cout << elem.second << ' ';
  }
  std::cout << std::endl;
}
