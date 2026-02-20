// C02040303_static_assertions.cpp 
#include <iostream>

void assert1() {
  static_assert(sizeof(int) > 2, "integers are too small.");
}


constexpr double C = 299792.458;         // km/s
void f(double speed) {
  constexpr double local_max = 160.0 / (60 * 60);       // 160 km/h == 160.0/(60*60) km/s
  //static_assert(speed < C, "can't go that fast.");    // error: speed must be a constexpr
  static_assert(local_max < C, "can't go that fast");
}

int main() {
  f(1200.12);
}
