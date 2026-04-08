#pragma once

#include "Ival_box.h"

class Ival_slider :public Ival_box {
private:
  // ... graphics stuff to define what the slider looks like, etc. ...
public:
  Ival_slider(int, int);
  int get_value() override;
  void prompt() override;
};

Ival_slider::Ival_slider(int ll, int hh) :
  Ival_box(ll, hh) {
}

inline int Ival_slider::get_value() {
  return 0;
}

inline void Ival_slider::prompt() {
}
