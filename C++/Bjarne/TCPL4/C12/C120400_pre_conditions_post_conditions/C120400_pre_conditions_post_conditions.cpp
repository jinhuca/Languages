// C120400_pre_conditions_post_conditions.cpp 
#include <iostream>

int area(int len, int wid)
/*
* calculate the area of a rectangle
* precodition: len and wid are positive
* postcondition: the return value is positive
* postcondition: the return value is the area of a rectangle with sides len and wid
*/
{
  return len * wid;
}

int main() {
  std::cout << area(std::numeric_limits<int>::max(), 2) << '\n';
  std::cout << area(-2, 5) << '\n';
  std::cout << area(31, 12) << '\n';
}
