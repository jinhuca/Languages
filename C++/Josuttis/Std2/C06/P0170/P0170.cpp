// P0170.cpp : std::deque
import std;

int main()
{
  std::deque<float> coll;
  for (int i = 1; i <= 6; ++i) {
    coll.push_front(i * 1.1);
  }
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
  }
  std::cout << '\n';
}
