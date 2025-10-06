export module Circle;

import Shape;
import Point;

export class Circle : public Shape {
public:
  Circle();
  Circle(Point p, int rad) : x { p }, r { rad } {}
  Point center() const override {
    return x;
  }
  void move(Point to) override {
    x = to;
  }
  void draw() const override {}
  void rotate(int) override {}    // nice simple algorithm
  ~Circle() override {}
private:
  Point x;      // center
  int r;        // radius
};