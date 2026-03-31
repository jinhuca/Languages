// C160210_self_reference.cpp 
#include <iostream>

class Date {
public:
  Date& add_day(int n);
  Date& add_month(int n);
  Date& add_year(int n);
private:
  int d, m, y;
};

bool leapyear(int y) {
  return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

Date& Date::add_year(int n) {
  if(m == 2 && d == 29 && !leapyear(y)) {
    m = 3;
    d = 1;
  }
  y += n;
  return *this;
}

Date& Date::add_day(int n) {
  d += n;
  return *this;
}

struct Link {
  Link* pre;
  Link* suc;
  int data;

  Link* insert(int x) {   // insert x before this
    return pre = new Link{pre, this, x};
  }

  void remove() {     // remove and destroy this
    if(pre) pre->suc = suc;
    if(suc) suc->pre = pre;
    delete this;
  }
};

int main() {

}
