// C0343_FunctionObject_a.cpp : for_all operations with lambda/function object.
import std;
#include "Shape.h"

template<typename C, typename Oper>
void for_all(C& c, Oper op) {
  for(auto& x : c)
    op(*x);
}

void use() {
  std::vector<std::unique_ptr<Shape>> v;
  v.push_back(std::move(std::make_unique<Circle>(Point(1, 1), 2)));
  for_all(v, [](Shape& s) {s.draw(); });
}

int main() {
  use();
}
