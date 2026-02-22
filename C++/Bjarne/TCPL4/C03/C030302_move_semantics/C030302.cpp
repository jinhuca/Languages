// C0332.cpp : moving containers
#include "Vector.h"
import std;

Vector f(const Vector& x, const Vector& y, const Vector& z) {
	return x + y + z;
}

Vector f() {
	Vector x(1000);
	Vector y(1000);
	Vector z(1000);
	z = x;
	y = std::move(x);
	return z;
}

void g() {
	Vector a(5);
	Vector b(5);
	Vector c(5);
	Vector d = f(a, b, c);
}

void moveConstructor() {
	Vector v1(5);
	Vector v2 = std::move(v1);
}
int main() {
	//f();
	moveConstructor();
}
