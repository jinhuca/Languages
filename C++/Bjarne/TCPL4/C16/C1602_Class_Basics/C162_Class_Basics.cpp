// C162_Class_Basics.cpp 
import std;

class X {
private:                        // the representation (implementation) is private
  int m;
public:                         // the interface is public
  X(int i = 0) :m { i } { }      // a constructor (initialize the data member m)
  int mf(int i) {               // a member function
    int old = m;
    m = i;                      // set a new value
    return old;                 // return the old value
  }
};

X x { 7 };                    // a variable of type X, initialized to 7

void user(X var, X* ptr) {
  int x = var.mf(11);
  int y = ptr->mf(9);
  std::cout << x << '\n';
  std::cout << y << '\n';
}

int main() {
  X x { 8 };
  X* pt = &x;
  user(x, pt);
}