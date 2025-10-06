// C0502Container.cpp
import std;
import Container;
import Vector_container;
import List_container;

void use(Container& c) {
  const int sz = c.size();
  for(int i = 0; i != sz; ++i)
    std::cout << c[i] << '\n';
}

void g() {
  Vector_container vc { 1,2,3,4,5 };
  use(vc);
}

void h() {
  List_container lc { 1,2,3,4,5,6 };
  use(lc);
}

int main() {
  g();
  h();
}
