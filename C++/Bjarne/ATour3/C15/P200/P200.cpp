// P200.cpp 
import std;

void fs(std::span<int> p) {
  for (auto& x : p) {
    x = 0;
  }

  for (auto i = 0; i < p.size(); ++i) {
    p[i] = i;
    std::cout << p[i] << '\n';
  }
}

void use(size_t x) {
  int a[5];
  fs(a);
}

int main() {
  use(5);
}
