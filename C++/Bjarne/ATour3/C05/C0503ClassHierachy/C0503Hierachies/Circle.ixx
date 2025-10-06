export module Circle;
import Shape;
import Point;
import std;

export class Circle :public Shape {
public:
  Circle(Point p, int rad) :x { p }, r { rad } {}
  Point center() const override { return x; }
  void move(Point to) override { x = to; }
  void draw() const override {}
  void rotate(int angle) override {
    std::cout << "rotate circle.\n";
  }
private:
  Point x;
  int r;
};