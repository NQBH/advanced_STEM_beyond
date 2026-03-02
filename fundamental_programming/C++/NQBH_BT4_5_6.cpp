#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Problem 4
	double x, y;
	cin >> x;
	if (x >= 0) cout << sqrt(x) << '\n';
	else cout << "Error.\n";

	cin >> y;
	if (x > 0) cout << pow(x, y) << '\n';
	else cout << "Error.\n";

	cout << log(x) << '\n';
	cout << log10(x) << '\n';

	int A;
	cin >> A;
	cout << abs(A) << '\n';
	long long B;
	cin >> B;
	cout << fabs(B) << '\n'; // tri tuyet doi cua so thuc: float
	double C;
	cin >> C;
	cout << fabs(C) << '\n';

	cout << cos(x) << '\n';
	cout << sin(x) << '\n';
	cout << tan(x) << '\n';
	cout << 1.0 / tan(x) << '\n'; // cot(x)

	if (x >= -1 && x <= 1) cout << acos(x) << '\n';
	else cout << "Error.\n";
	if (x >= -1 && x <= 1) cout << asin(x) << '\n';
	else cout << "Error.\n";
	cout << atan(x) << '\n';

	cout << floor(x) << '\n';
	cout << ceil(x) << '\n';

	// Problem 5: Solve ax + b = 0
	double a, b;
	cin >> a >> b;
	if (a == 0) { // if (!a)
		if (b == 0) cout << "Vo so nghiem.\n";
		else cout << "Vo nghiem.\n";
	} else {
		if (b == 0) cout << "x = 0.\n";
		else cout << "x = " << - b / a << "\n";
	}

	// Problem 6: Solve ax^2 + bx + c = 0
	double c;
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) cout << "Vo so nghiem.\n";
			else cout << "Vo nghiem.\n";
		} else {
			if (c == 0) cout << "x = 0.\n";
			else cout << "x = " << - c / b << "\n";
		}
	} else { // a != 0
		// Compute discriminant Delta = b^2 - 4ac
		double Delta = b * b - 4 * a * c;
		if (Delta < 0) {
			cout << "Phuong trinh co 2 nghiem phuc x1 = " << -b / (2 * a) << " - i" << sqrt(fabs(Delta)) / (2 * a) << " & ";
			cout << "x2 = " << -b / (2 * a) << " + i" << sqrt(fabs(Delta)) / (2 * a) << '\n';
		} else if (Delta == 0) {
			cout << "Phuong trinh co nghiem kep x = " << -b / (2 * a) << '\n';
		} else { // Delta > 0
			cout << "Phuong trinh co 2 nghiem thuc x1 = " << (-b - sqrt(Delta)) / (2 * a) << " & x2 = " << (-b + sqrt(Delta)) / (2 * a) << '\n';
		}
	}
}