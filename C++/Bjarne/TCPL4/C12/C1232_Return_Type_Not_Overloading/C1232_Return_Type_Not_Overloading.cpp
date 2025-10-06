// C1232_Return_Type_Not_Overloading.cpp 
import std;

float square(float f) { return f * f; }
double square(double d) { return d * d; }

void f(double da, float fa) {
  float fl = square(da);      // call square(double)
  double d = square(da);      // call square(double)
  fl = square(fa);            // call square(float)
  d = square(fa);             // call square(float)
}

int main() {
  f(1.23, 1.23f);
}
