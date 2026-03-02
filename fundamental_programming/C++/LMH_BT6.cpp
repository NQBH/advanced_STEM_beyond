#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c, d, x1, x2, x, x0;
	cin >> a >> b >> c;

	if (a == 0) {
		if (b != 0) {
			x = -c / b;
			cout << "x = " << x << endl;
		}
		else if (b == 0 && c != 0) {
			cout << "error" << endl;
		}
		else if (b == 0 && c == 0)
		{
			cout << "vo so nghiem" << endl;
		}
	}
	else {
		d = b * b - 4 * a * c;
		if (d < 0) {
			cout << "pt ko co nghiem thuc ,có nghiem phuc" << endl;
			x1 = (-b + sqrt(-d)) / (2 * a);
			cout << "x1 = " << x1 << endl;
			x2 = (-b - sqrt(-d)) / (2 * a);
			cout << "x2 = " << x2 << endl;
		}
		else if (d == 0) {
			x0 = -b / (2 * a);
			cout << "phuong trinh có nghiem kép  = " << x0 << endl;
		}
		else {
			cout << "pt có 2 nghiem thuc " << endl;
			x1 = (-b + sqrt(d)) / (2 * a);
			cout << "x1 = " << x1 << endl;
			x2 = (-b - sqrt(d)) / (2 * a);
			cout << "x2 = " << x2 << endl;
		}
		return 0;
	}
}
