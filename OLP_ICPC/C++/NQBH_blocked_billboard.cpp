#include <iostream>
using namespace std;

int area_intersection(int a1, int b1, int c1, int d1, int a2, int b2, int c2, int d2) {
	int width_intersection = max(min(c1, c2) - max(a1, a2), 0);
	int height_intersection = max(min(d1, d2) - max(b1, b2), 0);
	return width_intersection * height_intersection;
}

int main() {
	int a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3, ans = 0;
	cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2 >> a3 >> b3 >> c3 >> d3;
	ans += (c1 - a1) * (d1 - b1) + (c2 - a2) * (d2 - b2);
	ans -= area_intersection(a1, b1, c1, d1, a3, b3, c3, d3);
	ans -= area_intersection(a2, b2, c2, d2, a3, b3, c3, d3);
	cout << ans << '\n';
}