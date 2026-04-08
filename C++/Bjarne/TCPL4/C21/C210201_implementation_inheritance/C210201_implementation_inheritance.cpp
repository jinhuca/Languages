// C210201_implementation_inheritance.cpp 
#include <iostream>
#include <memory>
#include "Ival_box.h"
#include "Ival_slider.h"
#include "Ival_dial.h"

void interact(Ival_box* pb) {
  int old_val = pb->get_value();
  pb->prompt();   // alert user
  // ...
  int i = pb->get_value();
  if(i != old_val) {
    // ... new value; do something ...
  }
  else {
    // ... do something else ...
  }
}

void some_fct() {
  std::unique_ptr<Ival_box> p1{new Ival_slider{0, 5}};    // Ival_slider derived from Ival_box
  interact(p1.get());
  std::unique_ptr<Ival_box> p2{new Ival_dial{1, 12}};     // Ival_dial derived from Ival_box
  interact(p2.get());
}

int main() {
}
