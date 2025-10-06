// C073_Arrays.cpp 
import std;

void f() {
  float v[3];     // an array of three floats
  char* a[32];    // an array of 32 pointers to char

  int aa[10];
  aa[6] = 99;
  int x = aa[99];
}

void g(int n) {
  //int v1[n];                // compile-time error:
  int* v12 = new int[n];
  v12[0] = 1;
  std::vector<int> v2(n);
}

int a1[10];                 // 10 ints in static storage

void k() {
  int a2[20];               // 20 ints on the stack
  int* p = new int[10];     // 40 ints on the free store
  delete[] p;
}

int main() {
  //f();
  //g(12);
  k();
}
