export module Vector;
import std;

export class Vector {
public:
  Vector(int s) : elem { new double[s] }, sz { s } {   // constructor: acquire resources
    for(int i = 0; i != s; ++i) {
      elem[i] = 0;
    }
    std::cout << "constructor completed.\n";
  }
  Vector(std::initializer_list<double> lst)
    : elem { new double[lst.size()] }, sz { static_cast<int>(lst.size()) } {
    std::copy(lst.begin(), lst.end(), elem);
  }

  ~Vector()   // destructor: release resources
  {
    delete[] elem;
    std::cout << "destructor finished.\n";
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