// C0324_a.cpp : safer use of class hierarchies
// - use unique_ptr instead of naked pointer

import std;

struct Point {
  int x, y;
};

class Shape {
public:
  virtual Point center() const = 0;
  virtual void move(Point to) = 0;
  virtual void draw() const = 0;
  virtual void rotate(int angle) = 0;
  virtual ~Shape() = 0;
};

Shape::~Shape() {
  std::cout << "Destructed a shape in base class.\n";
}

//void rotate_all(std::vector<std::unique_ptr<Shape>> v, int angle) {   // rotate v's elements by angle degree
//  for(auto p : v)
//    p->rotate(angle);
//}

class Circle :public Shape {
public:
  Circle(Point p, int rr) : x { p }, r { rr } {
    std::cout << "constructed a circle.\n";
  }
  Point center() const override {
    std::cout << "get circle center.\n";
    return x;
  }
  void move(Point to) override {
    std::cout << "move circle.\n";
  }
  void draw() const override {
    std::cout << "draw circle.\n";
  }
  void rotate(int angle) override {
    std::cout << "rotate circle.\n";
  }
  ~Circle() override {
    std::cout << "destructed a circle.\n";
  }
private:
  Point x;
  int r;
};

class Triangle : public Shape {
public:
  Triangle(Point pp1, Point pp2, Point pp3)
    :p1 { pp1 }, p2 { pp2 }, p3 { pp3 } {
  }
  Point center() const override {
    return Point(1,2);
  }
  void move(Point to) override {}
  void draw() const override {}
  void rotate(int angle) override {}
  ~Triangle() override {}
private:
  Point p1, p2, p3;
};

class Smiley :public Circle {   // use the circle as the base for a face
public:
  Smiley(Point p, int r) :Circle { p,r }, mouth { nullptr } {
    std::cout << "constructed a smiley.\n";
  }
  ~Smiley() override {
    std::cout << "destructed a smiley.\n";
  }
  void move(Point to) override {
    std::cout << "move a smiley.\n";
  }
  void draw() const override {
    //Circle::draw();
    //for(auto p : eyes)
    //  p->draw();
    //if(mouth)
    //  mouth->draw();
    std::cout << "draw a smiley.\n";
  }
  void rotate(int angle) override {
    std::cout << "rotate a smiley.\n";
  }

  void add_eyes(std::unique_ptr<Shape> s) {
    //eyes.push_back(s);
    std::cout << "add eyes to a smiley.\n";
  }
  void set_eyes(std::unique_ptr<Shape> s) {
    //eyes.push_back(s);
    std::cout << "set eyes to a smiley.\n";
  }
  virtual void wink(int i) {
    std::cout << "smiley winks.\n";
  }
private:
  std::vector<std::unique_ptr<Shape>> eyes;
  std::unique_ptr<Shape> mouth;
};

enum class Kind { circle, triangle, smiley };

// read shape descriptions from input stream is
std::unique_ptr<Shape> read_shape(std::istream& is) { 
  // ... read shape header from is and find its Kind k ...
  int ki;
  std::cout << "Enter 0, 1, or 2 for shape kind Circle, Triangle, or Smiley: \n";
  std::cin >> ki;
  Kind k = static_cast<Kind>(ki);
  switch(k) {
  case Kind::circle:
    // read circle data (Point, int) into p and r
    return std::make_unique<Circle>(Point(1,2), 3);
  case Kind::triangle:
    // read triangle data (Point, Point, Point) into p1, p2, p3
    return std::make_unique<Triangle>(Point{ 0,0 }, Point{ 1,1 }, Point{ 2,2 });
  case Kind::smiley:
    // read smiley data
    auto result= std::make_unique<Smiley>(Point(9, 9), 1);
    return result;
  }
  throw std::bad_alloc();
}

int main() {

}
