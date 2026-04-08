#pragma once
#include "Ival_box.h"

class Ival_dial :public Ival_box {
private:
  // ...
public:
  Ival_dial(int ll, int hh);
};

Ival_dial::Ival_dial(int ll, int hh)
  :Ival_box(ll, hh) {
}