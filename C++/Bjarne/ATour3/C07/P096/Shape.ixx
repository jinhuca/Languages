export module Shape;

import std;

export class Shape
{
public:
  virtual void draw() { std::cout << "draw in Shape"; };
};

export class Circle :public Shape
{
public:
  void draw() override { std::cout << "draw in Circle"; }
};

export class Triangle :public Shape
{
public:
  void draw() override { std::cout << "draw in Triangle"; }
};