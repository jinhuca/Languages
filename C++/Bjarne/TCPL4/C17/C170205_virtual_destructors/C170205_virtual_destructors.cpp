// C170205_virtual_destructors.cpp 
#include <iostream>

class Shape {
public:
  // ...
  virtual void draw() = 0;   // pure virtual function: Shape is an abstract class
  virtual ~Shape() { std::cout << "Shape dtor.\n"; }   // virtual destructor
};

class Circle : public Shape {
public:
  // ...
  void draw() override { std::cout << "Circle::draw()\n"; }
  ~Circle() { std::cout << "Circle dtor.\n"; }  // override the destructor of Shape
};

void user(Shape* p) {
  p->draw();    // invoke the appropriate draw()
  // ...
  delete p;     // invoke the appropriate destructor: 
                // Circle's and then Shape's if the destructor of Shape is virtual
}

int main() {
  Circle* p = new Circle;   // create a Circle object
  user(p);                  // pass it to user()
}
