// C180201_Pass_Arguments.cpp 
import std;

void f(std::vector<double>& v) {  // function: do something with v
  v[0] = 42.0;
}

struct F {                        // function object: do something with v
  std::vector<double>& v;
  F(std::vector<double>& vv) : v(vv) {}
  void operator()() { v[0] = 42.0; }     // application operator
};

int main() {
  std::vector<double> some_vec {1,2,3,4,5,6,7,8,9};
  std::vector<double> vec2 {10,11,12,13,14};
  std::jthread t1 {f, ref(some_vec)};  // pass by reference, f(some_vec) executed in a separate thread
  std::jthread t2 {F{vec2}};           // pass by value, F{vec2} executed in a separate thread
}
