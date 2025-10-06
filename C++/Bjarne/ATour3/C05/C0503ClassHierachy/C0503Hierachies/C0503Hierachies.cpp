// C0503Hierachies.cpp
import std;
import Point;
import Shape;
import Circle;
import Smiley;
import Triangle;

enum class Kind { circle, triangle, smiley };

// read shape descriptions from input stream is
Shape* read_shape(std::istream& is) {
  // read k for Kind for shape
  Kind k = Kind::circle;
  switch(k) {
  case Kind::circle:
    // read circle data (Point, int) into p and r...
    /*Point p(0, 0);
    int r { 1 };*/
    return new Circle { Point(0,0), 1 };
  case Kind::triangle:
    // read triangle data (point, point, point) into p1, p2 and p3
    return new Triangle { Point(0,0),Point(1,1),Point(2,2), Point(1,1) };
  case Kind::smiley:
    // ... read smiley data (Point, int, Shape, Shape, Shape) into
    // p, r, e1, e2, and m
    Point p1 { 1,2 };
    int rad { 1 };
    Smiley* ps = new Smiley(p1, rad);
    ps->add_eye(new Circle(Point(1, 1), 1));
    ps->add_eye(new Circle(Point(1, 2), 1));
    ps->set_mouth(new Circle(Point(2, 2), 2));
    return ps;
  }
}

void user() {
  std::vector<Shape*> v;
  while(std::cin)
    v.push_back(read_shape(std::cin));

  draw_all(v);
  rotate_all(v, 45);

  for(auto s : v)
    delete s;
}

int main() {
  std::cout << "Hello World!\n";
}
