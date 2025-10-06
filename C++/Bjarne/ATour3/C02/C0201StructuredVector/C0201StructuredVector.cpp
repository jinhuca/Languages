// C0201StructuredVector.cpp: user-defined type - Vector
import std;

struct Vector {
  double* elem;   // pointer to elements
  int sz;         // number of elements
};

void declareVectorWithoutInitialization() {
  Vector v;   // define a variable of type Vector
}

void vector_init(Vector& v, int s) {  // initialize a Vector
  v.elem = new double[s];   // allocate an array of s doubles
  v.sz = s;
}

double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);

  for(int i = 0; i != s; ++i) {
    std::cin >> v.elem[i];
  }

  double sum = 0;
  for(int i = 0; i != s; ++i) {
    sum += v.elem[i];
  }
  return sum;
}

int main() {
  declareVectorWithoutInitialization();
  Vector v;
  vector_init(v, 5);
  std::cout << read_and_sum(5) << '\n';
}
