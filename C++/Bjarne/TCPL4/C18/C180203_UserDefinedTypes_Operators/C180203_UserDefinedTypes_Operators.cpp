// C180203_UserDefinedTypes_Operators.cpp 
import std;

enum class Day{sun, mon, tue, wed, thu, fri, sat};
Day& operator++(Day& d) {
  return d = (Day::sat == d) ? Day::sun : static_cast<Day>(static_cast<int>(d) + 1);
}

void f(Day d) {
  ++d;
}

int main() {
  f(Day::fri);
}
