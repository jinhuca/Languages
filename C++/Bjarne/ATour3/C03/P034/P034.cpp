// P034.cpp : use Vector
import std;
import Vector;

int main() {
  Vector v(9);
  std::cout << v.size() << '\n';

  for(int i = 0; i <= v.size(); ++i) {
    v[i] = i;
  }

  for(int i = 0; i <= v.size(); ++i) {
    std::cout << v[i] << '\n';
  }
}
