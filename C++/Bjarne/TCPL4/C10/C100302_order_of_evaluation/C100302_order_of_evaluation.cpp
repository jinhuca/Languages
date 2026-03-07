// C1032_Order_of_Evaluation.cpp 
import std;

int f(int x) {
  return ++x;
}

int g(int y) {
  return y += 2;
}

void k() {
  int x = f(2) + g(3);
}

void h() {
  std::vector<int> v { 0,0,0,0,0 };
  int i = 1;
  v[i] = i++;     // undefined result
}

void j() {
  int a = 1;
  int b = 2;
  b = (a = 2, a + 1);
}

int main() {
  k();
  h();
  j();
}
