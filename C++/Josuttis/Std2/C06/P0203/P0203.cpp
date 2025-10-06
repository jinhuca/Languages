// P0203.cpp : stl/find1.cpp
import std;

int main()
{
  std::list<int> coll;

  for (int i = 20; i <= 40; ++i) {
    coll.push_back(i);
  }

  // find position of element with value 3
  // - there is none, so pos3 gets coll.end()
  auto pos3 = std::find(coll.begin(), coll.end(), 3);

  // reverse the order of elements between found element and the end
  // - because pos3 is coll.end() it reverses an empty range
  std::reverse(pos3, coll.end());

  // find positions of values 25 and 35
  std::list<int>::iterator pos25, pos35;
  pos25 = std::find(coll.begin(), coll.end(), 25);
  pos35 = std::find(coll.begin(), coll.end(), 35);

  std::cout << "max: " << *max_element(pos25, pos35) << std::endl;
  std::cout << "min: " << *min_element(pos25, pos35) << std::endl;
}
