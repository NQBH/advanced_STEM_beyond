#include <bits/stdc++.h>
using namespace std;

double hsa, hsb, hsc;

double j(double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}

double F(int n, double alpha) {
	double an = alpha;
	for (int i = 0; i < n; ++i) {
		an = j(hsa, hsb, hsc, an);
	}
	return an;
}

int main() {
	cout << "Nhập hệ số a, b, c cho hàm j(x) = ax^2 + bx + c: ";
	cin >> hsa >> hsb >> hsc;

	int n;
	double alpha;
	cout << "Nhập n va alpha: ";
	cin >> n >> alpha;

	cout << "Giá trị của a" << n << " là  " << F(n, alpha) << '\n';
	return 0;
}