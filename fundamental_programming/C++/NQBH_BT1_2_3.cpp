#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Problem 1
	float a;
	cin >> a;
	if (a <= 0) cout << "Wrong input.\n";
	else {
		float C = 4 * a, S = a * a;
		cout << "Chu vi C = " << C << '\n';
		cout << "Dien tich S = " << S << '\n';
	}

	// Problem 2
	float b;
	cin >> a >> b;
	if (a <= 0 || b <= 0) cout << "Wrong input.\n";
	else {
		float C = 2 * (a + b), S = a * b, d = sqrt(a * a + b * b);
		cout << "Chu vi C = " << C << '\n';
		cout << "Dien tich S = " << S << '\n';
		cout << "Duong cheo d = " << d << '\n';
	}

	// Problem 3
	float c;
	cin >> a >> b >> c;
	if (a <= 0 || b <= 0 || c <= 0) cout << "-1\n";
	else {
		if (a > 0 && a == b && b == c) { // case HLP
			cout << "HLP\n";
			float Sxq = 4 * a * a, Stp = 6 * a * a, V = a * a * a, d = sqrt(3) * a;
			cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
			cout << "Dien tich toan phan Stp = " << Stp << '\n';
			cout << "The tich V = " << V << '\n';
			cout << "Duong cheo d = " << d << '\n';

		} else { // case HHCN
			cout << "HHCN\n";
			float Sxq = 2 * (a + b) * c, Stp = 2 * (a * b + b * c + c * a), V = a * b * c, d = sqrt(a * a + b * b + c * c);
			cout << "Dien tich xung quanh Sxq = " << Sxq << '\n';
			cout << "Dien tich toan phan Stp = " << Stp << '\n';
			cout << "The tich V = " << V << '\n';
			cout << "Duong cheo d = " << d << '\n';
		}
	}
}