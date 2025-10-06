// C0344_VariadicTemplates.cpp
import std;

void f() {}

template<typename T>
void g(T t) {
  std::cout << t << '\n';
}

template<typename T, typename... Tail>
void f(T head, Tail... tail) {
  g(head);        // do something to head
  f(tail...);     // try again with tail
}

int main() {
  f(1, 2.2, "hello", 123);
}
