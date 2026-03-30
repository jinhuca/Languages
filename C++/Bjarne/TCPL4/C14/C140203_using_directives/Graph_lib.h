#pragma once

namespace Graph_lib {
  class Shape { /* ... */ };
  class Line :public Shape { /* ... */ };
  class Poly_line : public Shape { /* ... */ };
  class Text :public Shape { /* ... */ };

  Shape operator+(const Shape& a, const Shape& b) {   // compose
    return Shape{};
  }

  struct Graph_reader {};
  Graph_reader open(const char* f) {  // open file of Shapes
    return Graph_reader{};
  }
}