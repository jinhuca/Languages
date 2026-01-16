// C010202_Raw_Arrays.cpp 
#include <iostream>

auto getArr() -> int(&)[2] {    // get a raw array with size
  int result[2] = {1, 2};
  return result;
}

int main() {
  int arr[] = { 47, 11 };
  auto [x, y] = arr;        // x and y are the int elems of a copy of arr
  //auto [z] = arr;           // ERROR: number of elements doesn't fit
  //auto [a, b, c] = arr;     // ERROR: number of elements doesn't fit

  auto [i, j] = getArr();
}
