// C0952_For_statements.cpp 
import std;

int sum(int v[], int size) {
  int result { 0 };
  for (int i = 0; i != size; ++i)
    result += v[i];
  return result;
}

void f1(int v[], int max) {
  for (int i = 0; i != max; ++i)
    v[i] = i * i;
}

void f2(int v[], int max) {
  int i = 0;              // introduce loop variable
  while (i != max) {      // test termination condition
    v[i] = i * i;         // execute the loop body
    ++i;                  // increment loop variable
  }
}

int main() {
  int a1[5] { 1, 2, 3, 4, 5 };
  std::cout << sum(a1, 5) << '\n';
  f1(a1, 5);
  std::cout << sum(a1, 5) << '\n';
}
