#pragma once
#include "Container.h"
#include <list>

class List_container : public Container {
  std::list<double> ld;
public:
  List_container() { }
  List_container(std::initializer_list<double> il) :ld { il } { }
  ~List_container() { }

  int size() const { return static_cast<int>(ld.size()); }
  double& operator[](int index) {
    return *(ld.begin());
  }
};