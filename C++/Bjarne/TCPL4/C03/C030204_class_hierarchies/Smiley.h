#pragma once
#include "Circle.h"
#include <vector>
#include <iostream>

class Smiley :public Circle {   // use the circle as the base for a face
public:
	Smiley(Point p, int r) :Circle {p,r}, mouth {nullptr} {
		std::cout << "construct Smiley.\n";
	}
	~Smiley() override {
		delete mouth;
		for(auto p : eyes) delete p;
		std::cout << "destruct Smiley.\n";
	}
	void move(Point to) override {
		std::cout << "move Smiley.\n";
	}

	void draw() const override {
		std::cout << "draw Smiley.\n";
		Circle::draw();
		for(auto p : eyes)
			p->draw();
		if(mouth)
			mouth->draw();
	}
	void rotate(int x) override { std::cout << "rotate Smiley at " << x << '\n'; }

	void add_eye(Shape* s) { eyes.push_back(s); }
	void set_mouth(Shape* s) {}
	virtual void wink(int i) { std::cout << "wink eyes " << i << " times"; }
private:
	std::vector<Shape*> eyes;    // usually two eyes
	Shape* mouth;
};