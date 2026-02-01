// C060301_Examples.cpp 
import std;

void list_iterator_example() {
  std::list<char> coll;       // list container for characters
  // append elements from 'a' to 'z'
  for(char c = 'a'; c < 'z'; ++c) {
    coll.push_back(c);
  }
  // iterate over all elements and print them
  std::list<char>::const_iterator pos;
  for(pos = coll.cbegin(); pos != coll.cend(); ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << "\n";
}

int main() {
  list_iterator_example();
}
