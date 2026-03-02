#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;
	double delta, x1, x2;
	cout << "Bai Tap 6" << endl;
	cout << "giai phuong trinh bac 2: ax^2 + bx + c = 0" << endl;
	cout << "nhap he so a: ";
	cin >> a;
	cout << "nhap he so b: ";
	cin >> b;
	cout << "nhap he so c: ";
	cin >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "phuong trinh co vo so nghiem." << endl;
			} else {
				cout << "phuong trinh vo nghiem." << endl;
			}
		} else {
			cout << "phuong trinh co 1 nghiem duy nhat: x = " << -c / b << endl;
		}
	}
	else {
		delta = b * b - 4 * a * c;

		if (delta > 0) {
			x1 = (-b + sqrt(delta)) / (2 * a);
			x2 = (-b - sqrt(delta)) / (2 * a);
			cout << "phuong trinh co 2 nghiem phan biet:" << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		} else if (delta == 0) {
			x1 = -b / (2 * a);
			cout << "phuong trinh co nghiem kep: x1 = x2 = " << x1 << endl;
		} else {
			cout << "phuong trinh vo nghiem (khong co nghiem thuc)." << endl;
		}
	}

	return 0;
}