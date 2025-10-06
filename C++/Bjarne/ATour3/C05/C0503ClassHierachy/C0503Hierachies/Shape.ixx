export module Shape;
import Point;
import std;

export class Shape {
public:
  virtual Point center() const = 0;
  virtual void move(Point to) = 0;

  virtual void draw() const = 0;
  virtual void rotate(int angle) = 0;

  virtual ~Shape() {}
};

export void rotate_all(std::vector<Shape*>& v, int angle) {
  for(auto p : v) {
    p->rotate(angle);
  }
}

export void draw_all(std::vector<Shape*> v) {
  for(auto s : v)
    s->draw();
}