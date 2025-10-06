// C180201_Binary_Unary_Operators.cpp 
import std;

class X {
public:
  X operator+(int a) {
    data += a;
    return *this;
  }
  X(int a) : data { a } {}

  int data;
};

X operator+(X a, X b) {
  a.data += b.data;
  return a;
}

X operator+(X a, double d) {
  a.data += d;
  return a;
}

void f(X a) {
  X b = a + 1;
  X c = 1 + a;
  X d = a + 1.0;
}

int main() {
  X x(1);
  f(x);
}
