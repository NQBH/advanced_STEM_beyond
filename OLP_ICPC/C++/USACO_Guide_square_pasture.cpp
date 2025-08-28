#include <iostream>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int left, right, top, bottom;
	// find the sides of the smallest rectangle covering both pastures
	left = min(x1, x3);
	right = max(x2, x4);
	bottom = min(y1, y3);
	top = max(y2, y4);
	/*
	 * the smallest square will need a side length
	 * that is the maximum of the side lengths of the rectangle
	 */
	int side = max(right - left, top - bottom);
	cout << side * side << '\n';
}