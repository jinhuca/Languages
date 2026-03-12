// C110101_logical_operators.cpp 
// The logical operators 
#include <iostream>

void test_logical_operators() {
  int x { 21 }, y { 0 };
  float z1 { 1.34f }, z2 { 0.0f };
  int* xp = new int(123);
  int* yp = new int(123);

  auto r1 = x && y;
  auto r2 = x || y;
  auto r3 = !x;

  auto a = !z1;
  auto b = !z2;

  auto r4 = !xp;
  auto r5 = xp && yp;
}

int count_chars(char* p) {
  int count = 0;
  // short_circuit_evaluation: second part (*p != ' ') will be evaluated only if first part p is true.
  while(p && (*p != ' ')) {  
    ++count;
    ++p;
  }
  return count;
}

void short_circuit_evaluation() {
  char word[] = "hello world!";
  std::cout << count_chars(word) << '\n';
}

int main() {
  test_logical_operators();
  short_circuit_evaluation();
}
