// P0224.cpp : foreach1.cpp
// using function as algorithm arguments

import std;

// function that prints the passed argument
void print(int elem) {
  std::cout << elem << ' ';
}

int main()
{
  std::vector<int> coll;
  for (int i = 1; i <= 9; ++i) {
    coll.push_back(i);
  }
  std::for_each(coll.cbegin(), coll.cend(), print);
  std::cout << std::endl;
}
