// C170201_Constructors_Invariants.cpp 
import std;

class Bad_size {
public:
  Bad_size(int s) :id { s } {}
private:
  int id;
};

class Vector {
public:
  Vector(int s);
  // ...
private:
  double* elem;     // elem points to an array of sz doubles
  int sz;           // sz is non-negative
};

Vector::Vector(int s) {
  if(s < 0) {
    throw Bad_size { s };
  }
  sz = s;
  elem = new double[s];
}

struct S {
  S();

};

int main() {
}
