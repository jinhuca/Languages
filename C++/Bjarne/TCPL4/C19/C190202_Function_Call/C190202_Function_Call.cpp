// C190202_Function_Call.cpp
import std;
import complex;

struct Action {
  int operator()(int i) const { return i * 3; }
  double operator()(double d) const { return d * d; }
  std::pair<int, int> operator()(int a, int b) { return std::pair(a, b); }
  // ...
};

void f(Action act) {
  int x = act(2);
  auto y = act(3, 4);
  double z = act(2.3);
}

class Add {
  complex val;
public:
  Add(complex c) :val { c } {}
  Add(double r, double i) :val { complex{r, i} } {}
  void operator()(complex& c) const { c += val; }
};

void h(std::vector<complex>& vec, std::list<complex>& lst, complex z) {
  std::for_each(vec.begin(), vec.end(), Add(2, 3));
  std::for_each(lst.begin(), lst.end(), Add(z));
}

void h2(std::vector<complex>& vec, std::list<complex>& lst, complex z) {
  std::for_each(vec.begin(), vec.end(), [](complex& a) { a += complex { 2,3 }; });
  std::for_each(lst.begin(), lst.end(), [z](complex& a) { a += z; });
}

int main() {
  Action act;
  f(act);

  std::vector<complex> vec { complex{1,2}, complex{2,3}, complex{3,4} };
  std::list<complex> lst { complex {3,1}, complex{4,2} };
  complex z { 3,3 };
  h(vec, lst, z);
}
