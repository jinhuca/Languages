export module Triangle;
import Shape;
import Point;
import std;

export class Triangle :public Shape {
public:
  Triangle(Point x, Point y, Point z, Point center)
    : p1 { x }, p2 { y }, p3 { z }, c { center } {
  }

  Point center() const override { return c; }
  void move(Point to) override {}
  void draw() const override {}
  void rotate(int angle) override {}
private:
  Point p1, p2, p3;
  Point c;
};