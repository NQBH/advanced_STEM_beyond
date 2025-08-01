#include <iostream>
using namespace std;

int gcd(int a, int b, int& x, int& y) { // extended Euclidean algorithm
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

int gcd_iterative(int a, int b, int& x, int& y) { // // iterative extended Euclidean algorithm
	x = 1;
	y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while (b1) {
		int q = a1 / b1;
		tie(x, x1) = make_tuple(x1, x - q * x1);
		tie(y, y1) = make_tuple(y1, x - q * y1);
		tie(a1, b1) = make_tuple(b1, a1 - q * b1);
	}
	return a1;
}

int main() {
	int a, b, x = 1, y = 0;
	cin >> a >> b;
	cout << gcd(a, b, x, y) << " " << gcd_iterative(a, b, x, y);
}