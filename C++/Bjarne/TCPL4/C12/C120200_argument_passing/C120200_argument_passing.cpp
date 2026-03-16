// C120200_argument_passing.cpp 
#include <iostream>

int* find(int* first, int* last, int v) {     // find v in [first:last)
  while(first != last && *first != v)
    ++first;
  return first;
}

void g(int* p, int* q) {
  int* pp = find(p, q, 'x');
  std::cout << *pp << '\n';
}

int main() {
  int arr[10]{71, 2, 13, 42, 5, 6, 120, 8, 9};
  g(arr, &arr[9]);
}
