export module Smiley;

import std;
import Shape;
import Circle;
import Point;

export class Smiley : public Circle
{
public:
  Smiley(Point p, int rad) : Circle{p, rad}, mouth { nullptr } {  }
  ~Smiley() override
  {
    delete mouth;
    for(auto p : eyes)
      delete p;
  }
  void move(Point to) override;
  void draw() const override;
  void rotate(int) override;

  void add_eye(Shape *s)
  {
    eyes.push_back(s);
  }

  void set_mouth(Shape *s) {}

  virtual void wink(int i);     // wink eye number i
private:
  std::vector<Shape *> eyes;     // usually two eyes
  Shape *mouth;
};

void Smiley::move(Point to)
{
  Circle::move(to);
}

void Smiley::draw() const
{
  Circle::draw();
}

void Smiley::rotate(int i)
{
  Circle::rotate(i);
}

void Smiley::wink(int i)
{
}