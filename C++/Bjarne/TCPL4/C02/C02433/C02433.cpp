// C02433.cpp : static assertion
import std;

constexpr double C = 299792.458;      // km/s
void f(double speed) {
  constexpr double local_max = 160.0 * (60 * 60);
  //static_assert(speed < C, "can't go that fast");
  static_assert(local_max < C, "can't go that fast");
}

int main() {
  f(300000);
}
