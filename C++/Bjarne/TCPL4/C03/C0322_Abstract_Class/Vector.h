#pragma once
import std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector() : sz { 1 }, elem { new double[1] } {}

  Vector(int s) :sz { s }, elem { new double[s] } {
    for (int i = 0; i != s; ++i) elem[i] = 0;
    std::cout << "constructed a Vector of size " << sz << '\n';
  }

  Vector(std::initializer_list<double> lst)
    : sz { static_cast<int>(lst.size()) }, elem { new double[lst.size()] } {
    std::copy(lst.begin(), lst.end(), elem);
  }

  ~Vector() {
    delete[] elem;
    std::cout << "destructed a Vector of size " << sz << '\n';
  }

  void push_back(double d) {

  }

  double& operator[](int i) {
    if (i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }

  int size() const { return sz; }
};