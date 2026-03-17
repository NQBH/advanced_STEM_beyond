#include <cmath>
#include <iostream>
using namespace std;

// f(x) = ax^2 + bx + c
double f(double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}

double F(int n, double alpha, double a, double b, double c) {
	if (n == 0) return alpha;
	return f(a, b, c, F(n - 1, alpha, a, b, c));
}

int main() {
	double a, b, c, alpha;
	int n;
	cout << "Nhap a, b, c: ";
	cin >> a >> b >> c;
	cout << "Nhap alpha: ";
	cin >> alpha;
	cout << "Nhap n: ";
	cin >> n;
	cout << "a_" << n << " = " << F(n, alpha, a, b, c) << '\n';
	return 0;
}