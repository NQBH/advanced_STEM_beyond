#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, A, B, C, x, y, d, dx, dy;
	cout << "ax+by=c" << endl;
	cout << "Ax+By=C" << endl;
	cout << "nhap a = "; cin >> a;
	cout << "nhap b = "; cin >> b;
	cout << "nhap c = "; cin >> c;
	cout << "nhap A = "; cin >> A;
	cout << "nhap B = "; cin >> B;
	cout << "nhap C = "; cin >> C;
	d = a * B - A * b;
	dx = c * B - C * b;
	dy = a * C - A * c;
	if (d != 0) {
		x = dx / d;
		y = dy / d;
		cout << "pt có 1 nghiem" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	else if (dx == 0 && dy == 0) {
		cout << "vo so nghiem" << endl;
	}
	else {
		cout << "vo nghiem" << endl;
	}
	return 0 ;
}


