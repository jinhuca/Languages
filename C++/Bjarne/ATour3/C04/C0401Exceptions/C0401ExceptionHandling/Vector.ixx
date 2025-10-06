export module Vector;
import std;
export class Vector {
public:
  Vector(int s) : elem { new double[s] }, sz { s } {}
  double& operator[](int i) {
    if(!(0 <= i && i <= size())) {
      throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
  }
  int size() const {
    return sz;
  }
private:
  double* elem;
  int sz;
};