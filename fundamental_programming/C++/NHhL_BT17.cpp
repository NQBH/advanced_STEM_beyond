#include <bits/stdc++.h>
using namespace std;

double j(double a, double x, double n) {
	return a * pow(x, n);
}

double Dj(double a, double x, double n) {
	return n * a * pow(x, n - 1);
}

double D2j(double a, double x, double n) {
	return n * (n - 1) * a * pow(x, n - 2);
}

int main() {
	double a, x, n;
	
	cout << "Nhập hệ số a: ";
	cin >> a;
	cout << "Nhập biến x: ";
	cin >> x;
	cout << "Nhập số mũ n: ";
	cin >> n;
    
	cout << "Giá trị của j(x) = " << j(a, x, n) << '\n';
	cout << "Giá trị đạo hàm bậc 1 Dj(x) = " << Dj(a, x, n) << '\n';
	cout << "Giá trị đạo hàm bậc 2 D2j(x) = " << D2j(a, x, n) << '\n';

	return 0;
}