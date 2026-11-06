// C0202_structures.cpp 
import std;

struct Vector {
  double* elem;   // pointer to elements
  int sz;         // number of elements
};

void vector_init(Vector& v, int s) {      // initialize a Vector
  v.elem = new double[s];                 // allocate an array of s doubles
  v.sz = s;
}

// read s integers from cin and return their sum; s is assumed to be positive
double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);                      // allocate s elements for v
  
  for(int i = 0; i != s; ++i)             // read into elements
    std::cin >> v.elem[i];
  
  double sum = 0;
  for(int i = 0; i != s; ++i)         
    sum += v.elem[i];                     // compute the sum of the elements
  return sum;
}

void f(Vector v, Vector& rv, Vector* pv) {
  int i1 = v.sz;        // access through variable name
  int i2 = rv.sz;       // access through reference
  int i3 = pv->sz;      // access through pointer
}

int main() {
  std::cout << read_and_sum(3) << std::endl;
  return 0;
}
