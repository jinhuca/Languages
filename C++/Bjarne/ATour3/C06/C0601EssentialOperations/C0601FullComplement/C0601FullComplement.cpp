// C0601FullComplement.cpp
import std;
import X;

void call_default_constructor() {
  X x1;
}

void call_ordinary_constructor() {
  X x2(5);
}

void call_copy_constructor() {
  X x1(4);
  X x2 = x1;
}

void call_copy_assignment() {
  X x1(5);
  X x2;
  x2 = x1;
}

void call_move_constructor() {
  X x1(5);
  X x2 = std::move(x1);
  std::cout << "" << x1.size() << '\n';
}

void call_move_assignment() {
  X x1(4);
  X x2;
  x2 = std::move(x1);
  std::cout << "x1 size = " << x1.size() << '\n';
  std::cout << "x2 size = " << x2.size() << '\n';
}

int main() {
  //call_default_constructor();
  //call_ordinary_constructor();
  //call_copy_constructor();
  //call_copy_assignment();
  //call_move_constructor();
  call_move_assignment();
}
