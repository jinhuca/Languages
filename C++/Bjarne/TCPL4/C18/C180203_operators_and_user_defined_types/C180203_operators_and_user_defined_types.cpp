// C180203_operators_and_user_defined_types.cpp 
#include <iostream>

enum class Day{ sun, mon, tue, wed, thu, fri, sat};
Day& operator++(Day& d) {
  return d = (Day::sat == d) ? Day::sun : static_cast<Day>( static_cast<int>(d) + 1);
}

int main() {
  Day d1 = Day::fri;
  ++d1;
}
