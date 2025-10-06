export module Smiley;
import Circle;
import Point;
import std;

export class Smiley :public Circle {
public:
  Smiley(Point p, int rad)
    : Circle(p, rad), mouth { nullptr } {
  }
  ~Smiley() {
    delete mouth;
    for(auto p : eyes)
      delete p;
  }

  Point center() const override { return Point(0, 0); }
  void draw() const override {
    Circle::draw();
    for(auto p : eyes)
      p->draw();
    mouth->draw();
  }

  void move(Point to) override {}
  void rotate(int angle) override {}

  void add_eye(Shape* s) {
    eyes.push_back(s);
  }

  void set_mouth(Shape* s) {
  }

  void wink(int i) {};
private:
  std::vector<Shape*> eyes;
  Shape* mouth;
};
