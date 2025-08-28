#include <iostream>
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	void read() {
		cin >> x1 >> y1 >> x2 >> y2;
	}
	int area() { // area of the rectangle
		return (y2 - y1) * (x2 - x1);
	}
}

int intersect(Rect p, Rect q) {
	// calculate overlap in x & y directions
	int x_overlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int y_overlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return x_overlap * y_overlap; // area of intersection
}

int main() {
	Rect a, b, t; // billboards a, b, & the truck
	a.read();
	b.read();
	t.read();
	// total visible area = area of both billboards - area covered by truck
	cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << '\n';
}