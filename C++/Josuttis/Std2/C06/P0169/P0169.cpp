// P0169.cpp : vector1
import std;

int main()
{
  std::vector<int> coll;
  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i);
  }

  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
  }
  std::cout << '\n';
}
