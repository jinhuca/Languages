export module Vector_container;

import std;
import Container;
import Vector;

namespace P060
{
  // Vector_container implements Container
  export class Vector_container : public Container
  {
  public:
    explicit Vector_container(int s) : v(s) {}
    Vector_container(std::initializer_list<double> iv) : v { iv } {}
    ~Vector_container() override {}
    double &operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }
  private:
    Vector v;
  };
}
