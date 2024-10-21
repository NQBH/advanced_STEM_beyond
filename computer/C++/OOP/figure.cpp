#include "figure.h"
void point2D::set(double x0, double y0) {
	x = x0;	// equivalent: this->x = x0
	y = y0; // equivalent: this->y = y0
}

void point2D::move(double dx, double dy) {
	x += dx;
	y += dy;
}

void point2D::scale(double sx, double sy) {
	x *= sx;
	y *= sy;
}

const double PI = 3.14159;

void circle::set(double x0, double y0, double r) {
	center.set(x0, y0);
	if (r < 0) r = 0;
	this->radius = r;
}

void circle::move(double dx, double dy) {
	center.move(dx, dy);
}

double circle::area() {
	return PI*radius*radius;
}

double circle::perimeter() {
	return 2*PI*radius;
}