#include <iostream>
#include <cmath>
using namespace std;
double f ( double a, double b, double c, double x) {
	return a * x * x + b * x + c;
}
double F ( int n, double a, double b, double c, double A) {
	double res = A;
	for ( int i = 0 ; i < n ; ++i) {
		res = f(a, b, c, res);
	} return res;
}
int main() {
	int n;
	double a, b , c, A;
	cout << "nhap: n, a, b, c, alpha ";
	cin >> n >> a >> b >> c >> A;
	cout << F(n, a, b, c, A) << '\n';
	return 0;
}