#include<iostream>
#include<cmath>
using namespace std;
double f(double a, double x, double n) {
	return a * pow(x, n);
}
double d1f(double a, double x, double n) {
	return n * a * pow(x, n - 1);

}
double d2f(double a, double x, double n) {
	return n * (n - 1) * a * pow(x, n - 2);
}
int main() {
	double a, x, n;
	cout << "Nhap a, x, n ";
	cin >> a >> x >> n;
	cout << f(a, x, n) << '\n';
	cout << d1f(a, x, n) << '\n';
	cout << d2f(a, x, n) << '\n';
	return 0;
}