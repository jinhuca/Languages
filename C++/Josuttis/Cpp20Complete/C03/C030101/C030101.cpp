// C030101.cpp 
import std;
import maxValue;

void demo1() {
  int x = 10, y = 20;
  std::cout << "Max of " << x << " and " << y << " is " << maxValue(x, y) << '\n';
}

void demo2() {
  double p = 5.5, q = 3.3;
  double* dp1 = &p;
  double* dp2 = &q;
  // The following line would cause a compilation error due to the pointer constraint
  //std::cout << "Max of " << dp1 << " and " << dp2 << " is " << maxValue(dp1, dp2) << '\n';
}

void demo3() {
  int a = 15, b = 25;
  std::cout << MinValue(&a, &b) << '\n';
}
int main() {
  demo3();
}
