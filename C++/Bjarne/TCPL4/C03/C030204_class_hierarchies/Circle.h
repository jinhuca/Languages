#pragma once
#include "Shape.h"
#include <iostream>

class Circle : public Shape {
public:
	Circle(Point p, int rr) : x {p}, r {rr} { std::cout << "construct circle.\n"; }

	Point center() const override { return x; }
	void move(Point to) override { x = to; }

	void draw() const override { std::cout << "draw circle.\n"; };
	void rotate(int x) override { std::cout << "rotate circle at angle " << x << '\n'; }
	
	~Circle() override { std::cout << "destruct circle.\n"; }
private:
	Point x;     // center
	int r;       // radius
};