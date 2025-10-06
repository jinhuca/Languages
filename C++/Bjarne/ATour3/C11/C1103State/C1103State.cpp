// C1103State.cpp
import std;

std::vector<int> read_ints(std::istream& is) {
  std::vector<int> res;
  for(int i; is >> i;) {
    res.push_back(i);
  }
  return res;
}

int main() {
  for(auto& i : read_ints(std::cin)) {
    std::cout << i << ' ';
  }
}
