// C110102_bitwise_operators.cpp 
#include <iostream>

enum flags : short {
  jammed = 0,
  empty = 1,
  busy = 2,
  available = 4,
};

flags f1 = flags::jammed, f2 = flags::busy;

void bitwise_on_enum() {
  auto c1 = f1 & f2;
  auto c2 = f1 | f2;
  auto c3 = flags::available | flags::busy;
}

enum class traffic_lights {
  green = 0,
  yellow = 1 << 0,
  red = 1 << 1
};

traffic_lights t1 = traffic_lights::green;
traffic_lights t2 = traffic_lights::red;

// bitwise operators are not allowed on enum class (scoped enum) directly
//void bitwise_on_enum_class() {
//  auto r1 = t1 & t2;
//  auto r2 = t1 | t2;
//}

int main() {
  bitwise_on_enum();
  //bitwise_on_enum_class();
  auto r1 = t1;
  auto r2 = t2;
}
