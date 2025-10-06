// C0743_Passing_arrays.cpp
import std;

void comp(double arg[10]) {         // arg is a double*
  for (int i = 0; i != 10; ++i)
    arg[i] += 99;
}

void comp2(double* arg) {           // arg is a double*
  for (int i = 0; i != 10; ++i)
    arg[i] += 99;
}

void f() {
  double a1[10];
  double a2[5];
  double a3[100];

  comp(a1);
  comp(a2);   // disaster!
  comp(a3);   // uses only the first 10 elements!
}

void print_m35(int m[3][5]) {
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 5; ++j)
      std::cout << m[i][j] << '\t';
    std::cout << '\n';
  }
}

void print_mi5(int m[][5], int dim1) {
  for (int i = 0; i != dim1; i++) {
    for (int j = 0; j != 5; j++)
      std::cout << m[i][j] << '\t';
    std::cout << '\n';
  }
}

/*
 *  int m[][] is illegal
 */
 /*
 void print_mij(int m[][], int dim1, int dim2) {   // doesn't behave as most people would think
   for (int i = 0; i != dim1; ++i) {
     for (int j = 0; j != dim2; ++j)
       std::cout << m[i][j] << '\t';         // Surprise!
     std::cout << '\n';
   }
 }
 */

void init_mij(int* m, int dim1, int dim2) {
  for (int i = 0; i != dim1; ++i)
    for (int j = 0; j != dim2; ++j)
      m[i * dim2 + j] = i * 10 + j;
}

void print_mij(int* m, int dim1, int dim2) {
  for (int i = 0; i != dim1; ++i) {
    for (int j = 0; j != dim2; ++j)
      std::cout << m[i * dim2 + j] << '\t';
    std::cout << '\n';
  }
}

void g() {
  int v[3][5] {
    {0,1,2,3,4},
    {10,11,12,13,14},
    {20,21,22,23,24}
  };
  print_m35(v);
  print_mi5(v, 3);
  print_mij(&v[0][0], 3, 5);
}

void k() {
  int a[3][5];
  init_mij(&a[0][0], 3, 5);
  print_mij(&a[0][0], 3, 5);
}

int main() {
  //f();
  //g();
  k();
}
