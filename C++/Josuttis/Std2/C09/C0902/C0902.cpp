// C0902.cpp : Iterator Categories
#include <vector>
#include <iostream>

int main() {
  std::vector<int> coll;

  // insert elements from -3 to 9
  for (int i = -3; i <= 9; ++i) {
    coll.push_back(i);
  }
  std::cout << "number/distance: " << coll.end() - coll.begin() << std::endl;
}
