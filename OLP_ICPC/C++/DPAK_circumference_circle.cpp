/*
Source: Ulm Local Contest 1996.
IDs for online judges: POJ 2242, ZOJ 1090.
Status: Accepted
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct point {
	double x, y;
};

double pw(double x) {
	return x * x;
}

double triangle(point p1, point p2, point p3) {
	return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}

double R(point p1, point p2, point p3) {
	double ans = (sqrt(pw(p1.x - p2.x) + pw(p1.y - p2.y)) * sqrt(pw(p1.x - p3.x) + pw(p1.y - p3.y)) * sqrt(pw(p2.x - p3.x) + pw(p2.y - p3.y)));
	ans /= 4.0 * triangle(p1, p2, p3);
	return ans;
}

const double pi = 3.141592653589793;

int main() {
	point p1, p2, p3;
	while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) {
		double r = R(p1, p2, p3);
		double c = 2 * pi * r;
		cout << fixed << setprecision(2) << c << endl;
	}
}