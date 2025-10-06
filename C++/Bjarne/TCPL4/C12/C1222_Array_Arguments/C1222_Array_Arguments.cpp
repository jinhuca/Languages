// C1222_Array_Arguments.cpp 
import std;

int strlen2(const char* p) {
  int num = 0;
  while(p && *p != '\0') {
    num += 1;
    ++p;
  }
  return num;
}

void f() {
  char v[] = "Annemarie";
  int i = strlen2(v);
  int j = strlen2("Nicolas");
  int k = strlen2(&v[0]);
}

int sum_of_array_int(int(&r)[4]) {
  int sum = 0;
  for(int i = 0; i != 4; ++i) {
    sum += r[i];
  }
  return sum;
}

void sum() {
  int a1[] { 1, 2, 3, 4 };
  std::cout << sum_of_array_int(a1);    // OK
  int a2[] = { 1, 2 };
  //std::cout << sum_of_array_int(a2);    // error: wrong number of elements
}

int main() {
  //f();
  sum();
}
