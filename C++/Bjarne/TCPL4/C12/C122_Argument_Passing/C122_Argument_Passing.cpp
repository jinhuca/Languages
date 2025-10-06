// C122_Argument_Passing.cpp 
import std;

int* find(int* first, int* last, int v) {   // find v in [first, last)
  while(first != last && *first != v)
    ++first;
  return first;
}

void g(int* p, int* q) {
  int* pp = find(p, q, 9);
  // ...
}

int main() {
  int arr[] { 1, 3, 5, 9, 12, 13, 16, 19, 21 };
  g(arr, &arr[8]);
}
