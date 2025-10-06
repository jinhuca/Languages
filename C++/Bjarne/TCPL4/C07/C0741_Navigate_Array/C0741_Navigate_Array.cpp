// C0741_Navigate_Array.cpp 
import std;

void use(char c) {
  std::cout << c;
}

void fi(char v[]) {
  for (int i = 0; v[i] != 0; ++i)
    use(v[i]);
  std::cout << '\n';
}

void fp(char v[]) {
  for (char* p = v; *p != 0; ++p)
    use(*p);
  std::cout << '\n';
}

void g(char* a) {
  int j = 2;
  bool b1 = a[j] == *(&a[0] + j);
  bool b2 = a[j] == *(a + j);
  bool b3 = a[j] == j[a];

  bool b4 = 3["Texas"] == "Texas"[3];
  bool b5 = 3["Texas"] == 'a';
  bool b6 = "Texas"[3] == 'a';
}

template<typename T>
int byte_diff(T* p, T* q) {
  return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p);
}

void diff_test() {
  int vi[10];
  short vs[10];
  std::cout << vi << ' ' << &vi[1] << &vi[1] - &vi[0] << " = " << byte_diff(&vi[0], &vi[1]) << '\n';
  std::cout << vs << ' ' << &vs[1] << &vs[1] - &vs[0] << " = " << byte_diff(&vs[0], &vs[1]) << '\n';
}

void f() {
  int v1[10];
  int v2[10];

  int i1 = &v1[5] - &v1[3];     // i1 = 2
  int i2 = &v1[5] - &v2[3];     // result undefined

  int* p1 = v2 + 2;             // p1 = &v2[2]
  int* p2 = v2 - 2;             // p2 undefined
}

void gk(char v[], int size) {
  for (int i = 0; i != size; ++i)   // hope that v has at least size elements
    use(v[i]);
  //for (int x : v)                 // error: range-for does not work for pointers
    //use(x);

  const int N = 7;
  char v2[N];
  for (int i = 0; i != N; ++i)
    use(v2[i]);
  for (int x : v2)
    use(x);                         // range-for works for arrays of known size
}

int main() {
  char v[] = "hello, world!";
  fi(v);
  fp(v);
  g(v);
  diff_test();
  f();
}
