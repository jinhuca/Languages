// P039.cpp
import std;
import Matrix;

int &bad()
{
  int x;
  return x;
}

void f()
{
  Matrix m1, m2;
  Matrix m3 = m1 + m2;
}

void g()
{
  Matrix m1, m2;
  Matrix *m3 = add(m1, m2);     // just copy a pointer
  // ...
  delete m3;        // easily forgotten
}

// here, "auto" means "deduce the return type"
auto mul(int i, double d) { return i * d; }

// the return type is "double"
auto div(int i, double d) -> double { return i / d; }

int main()
{
  std::cout << "Hello World!\n";
}
