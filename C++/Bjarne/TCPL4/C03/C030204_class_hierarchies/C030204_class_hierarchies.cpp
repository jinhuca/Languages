// C030204_class_hierarchies.cpp 
#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Smiley.h"

enum class Kind { circle, smiley, triangle };

Shape* read_shape(std::istream& is) {  // read shape descriptions from input stream
	// ... read shape header from is and find its Kind k ...
	Kind k = Kind::circle;
	switch(k) {
		case Kind::circle:
			return new Circle(Point(0, 0, 0), 1);
		case Kind::smiley:
			return new Smiley(Point(1, 1, 1), 2);
			//case Kind::triangle:
	}
	return nullptr;
}

void rotate_all(std::vector<Shape*>& v, int angle) {
	for(auto p : v)
		p->rotate(angle);
}

void use() {
	std::vector<Shape*> v;
	while(std::cin)
		v.push_back(read_shape(std::cin));
	rotate_all(v, 45);
	for(auto p : v) delete p;
}
void r() {
	std::vector<Shape*> v1 {
		new Circle(Point(0,2,1), 1),
		new Circle(Point(0,3,1),2)};
	rotate_all(v1, 12);
}

void f() {
	Smiley s(Point(0, 1, 2), 3);
	s.add_eye(new Circle(Point(1, 1, 1), 2));
	s.add_eye(new Circle(Point(2, 1, 2), 2));
	s.draw();
}

int main() {
	f();
}
