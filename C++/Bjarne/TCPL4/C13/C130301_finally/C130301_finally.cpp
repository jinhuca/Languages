// C130301_finally.cpp 
#include <iostream>

template<typename F>
// supply action to the constructor; execute the action in the destructor
struct Final_action {
  Final_action(F f) :clean{f} {}
  ~Final_action() { if(is_dirty) clean(); }
  bool is_dirty = true;
  F clean;
  Final_action(Final_action&& a) :clean(a) { a.is_dirty = false; }  // enable move
  Final_action(const Final_action&) = delete;                       // disable copy
  Final_action& operator=(const Final_action&) = delete;
};

template<typename F>
Final_action<F> finally(F f) {
  return Final_action<F>(f);
}

// handle undisciplined resource acquisition; demonstrate that arbitrary actions are possible
void test() {
  int* p = new int{7};        // probably should use a unique_ptr.
  int* buf = (int*)malloc(100 * sizeof(int));       // C-style allocation

  auto act1 = finally([&] {
    delete p;
    free(buf);                // C-style deallocation
    std::cout << "Goodby, Cruel world!\n";
  });
  
  int var = 0;
  std::cout << "var = " << var << '\n';
  
  {   // nested block:
    var = 1;
    auto act2 = finally([&] {std::cout << "finally!\n"; var = 7; });
    std::cout << "var = " << var << '\n';
  } // act2 is invoked here

  std::cout << "var = " << var << '\n';
}   // act1 is invoked here

int main() {
  test();
}
