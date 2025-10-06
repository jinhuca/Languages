// P0189.cpp : list1old.cpp
import std;

int main()
{
  std::list<char> coll;         // list container for character elements
  // append elements from 'a' to 'z'
  for (char c = 'a'; c <= 'z'; ++c) {
    coll.push_back(c);
  }

  // print all elements:
  // - iterate over all elements
  std::list<char>::const_iterator pos;

  std::cout << "Hello World!\n";
}
