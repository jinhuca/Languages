// C0322.cpp : abstract type
import std;
#include "Vector.h"

class Container {
public:
  virtual double& operator[](int) = 0;
  virtual int size() const = 0;
  virtual ~Container() {};
};

void use(Container& c) {    // access object via interface (reference in this case)
  const int sz = c.size();
  for (int i = 0; i != c.size(); ++i) {
    std::cout << c[i] << '\n';
  }
}

class Vector_container :public Container {    // Vector_container implements Container
  Vector v;
public:
  Vector_container(int s) : v(s) {
    std::cout << "Vector_container constructor called.\n";
  }
  ~Vector_container() override {
    std::cout << "Vector_container destructor called.\n";
  }
  double& operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }
};

void g() {
  Vector_container vc(10);  //
  use(vc);
}

class List_container : public Container {
  std::list<double> ld;
public:
  List_container();
  List_container(std::initializer_list<double> il) :ld { il } {}
  ~List_container(){}

  double& operator[](int i)
  {
    for (auto& x : ld) {
      if (i == 0) return x;
      --i;
    }
    throw std::out_of_range("List container");
  }

  int size() const { return ld.size(); }
};

void h()
{
  List_container lc = { 1,2,3,4,5,6 };
  use(lc);
}

int main() {

}
