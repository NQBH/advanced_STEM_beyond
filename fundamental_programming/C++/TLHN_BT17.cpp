#include <iostream>
#include <cmath>
using namespace std;



double tinh_f(double a, double x, double n) {
	double kq = a * pow(x, n);
	return kq;
}

double dao_ham_2(double a, double x, double n) {
	double kq = n * (n - 1) * a * pow(x, n - 2);
	return kq;
}

int main() {
	double a, x;
    int n;

	cout << "Nhap a:" << endl;
	cin >> a;

	cout << "Nhap x:" << endl;
	cin >> x;


	cout << "Nhap n:" << endl;
	cin >> n;



	double fx = tinh_f(a, x, n);
	double d2 = dao_ham_2(a, x, n);

	cout << "f(x) = " << fx << endl;
	cout << "f''(x) = " << d2 << endl;

	return 0;
}
