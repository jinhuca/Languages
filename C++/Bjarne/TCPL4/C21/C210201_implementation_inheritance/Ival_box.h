#pragma once

class Ival_box {
protected:
  int val;
  int low, high;
  bool changed{false};    // changed by user using set_value()
public:
  Ival_box(int ll, int hh) :val{ll}, low{ll}, high{hh} {}

  virtual int get_value() { changed = false; return val; }          // for application
  virtual void set_value(int i) { changed = true; val = i; }        // for user
  virtual void reset_value(int i) { changed = false; val = i; }     // for application
  virtual void prompt() {}
  virtual bool was_changed() const { return changed; }

  virtual ~Ival_box() {}
};