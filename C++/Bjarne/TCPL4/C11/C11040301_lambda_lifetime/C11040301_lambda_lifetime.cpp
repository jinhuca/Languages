// C11040301_lambda_lifetime.cpp
#include <iostream>
#include <string>
#include <functional>

struct Point {
  int x, y;
};

class Menu {
public:
  void add(std::string msg, std::function<void(void)> f) {
  }
  void draw(Point p1, Point p2, Point p3) {
  }
};

void setup(Menu& m) {
  // ...
  Point p1, p2, p3;

  // ... capture positions of p1, p2, and p3 ...
  // probable disaster - the later invocation of the lambda will access p1, p2, and p3
  // which might be non-exist at the execution time.
  m.add("draw triangle", [&]() {m.draw(p1, p2, p3); });
  // ...
}

int main() {
  Menu m;
  setup(m);
}
