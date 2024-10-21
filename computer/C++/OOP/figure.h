#ifndef _FIGURE_H
#define _FIGURE_H

class point2D {
	double x, y;
public:
	void set(double x0, double y0);
	void move(double dx, double dy);
	void scale(double sx, double sy);
}; // end declaration of point2D class

class circle {
	point2D center;
	double radius;
public:
	void set(double x0, double y0, double r);
	void set(double r);
	void move(double dx, double dy);
	double area();
	double perimeter();
}; // end declaration of circle class

#endif