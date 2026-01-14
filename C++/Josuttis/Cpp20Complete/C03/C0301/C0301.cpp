// C0301.cpp 
import std;

// Function template to return the maximum of two values of any same type
template<typename T>
T maxValue(T a, T b) {
  return (a > b) ? a : b;
}

void demo1() {
  int x = 10, y = 20;
  std::cout << "Max of " << x << " and " << y << " is " << maxValue(x, y) << '\n';
}

void demo2() {
  double p = 5.5, q = 3.3;
  std::cout << "Max of " << p << " and " << q << " is " << maxValue(p, q) << '\n';
}

void demo3() {
  char c1 = 'z';
  char c2 = 'a';
  char* pc1 = &c1;
  char* pc2 = &c2;

  std::cout << "Max of " << c1 << " and " << c2 << " is " << maxValue(pc1, pc2) << '\n';
}

int main() {
  demo1();
  demo2();
  demo3();
}
