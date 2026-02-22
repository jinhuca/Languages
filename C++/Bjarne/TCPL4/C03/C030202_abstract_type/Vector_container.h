#pragma once
#include "Container.h"
#include "Vector.h"

class Vector_container : public Container {
  Vector v;
public:
  Vector_container(int s) : v (s) {
    std::cout << "Vector_container constructor.\n";
  }
  ~Vector_container() {
    std::cout << "Vector_container destructor.\n";
  }
  int size() const { return v.size(); }
  double& operator[](int index) { return v[index]; }
};