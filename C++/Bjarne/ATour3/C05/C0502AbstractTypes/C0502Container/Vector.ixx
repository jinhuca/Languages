export module Vector;
import std;

export class Vector {
public:
  Vector(int s) :elem { new double[s] }, sz { s } {
    for(int i = 0; i != sz; ++i) {
      elem[i] = 0;
    }
  }
  Vector(std::initializer_list<double> lst)
    : elem { new double[lst.size()] }, sz { static_cast<int>(lst.size()) } {
    std::copy(lst.begin(), lst.end(), elem);
  }
  ~Vector() {
    delete[] elem;
  }
  double& operator[](int i) {
    return elem[i];
  }
  int size() const {
    return sz;
  }
private:
  double* elem;
  int sz;
};