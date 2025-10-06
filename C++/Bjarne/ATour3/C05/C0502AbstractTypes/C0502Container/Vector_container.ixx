export module Vector_container;
import std;
import Container;
import Vector;

export class Vector_container :public Container {
public:
  Vector_container(int s) :v(s) {}
  Vector_container(std::initializer_list<double> lst) :
    v { lst } {
  };
  ~Vector_container() {}
  double& operator[](int i) override { return v[i]; }
  int size() const override { return v.size(); }
private:
  Vector v;
};