// C16210_Self_Reference.cpp 
import std;

class Date {
public:
  Date(int dd, int mm, int yy);
  Date& add_year(int n);
  Date& add_month(int n);
  Date& add_day(int n);
private:
  int d, m, y;
};

Date::Date(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

Date& Date::add_day(int n) {
  d += n;
  return *this;
}

Date& Date::add_month(int n) {
  m += n;
  return *this;
}

Date& Date::add_year(int n) {
  y += n;
  return *this;
}

void f(Date& d) {
  d.add_day(1).add_month(1).add_year(1);
}

struct Link {
  Link* pre;
  Link* suc;
  int data;
  Link(Link* pre, Link* currentLink, int newData) {

  }

  Link* insert(int x) {   // insert x before this
    return pre = new Link(pre, this, x);
  }

  void remove() {         // remove and destroy this
    if (pre) pre->suc = suc;
    if (suc) suc->pre = pre;
    delete this;
  }
};

int main() {
  Date d { 1,14,1977 };
  f(d);
}
