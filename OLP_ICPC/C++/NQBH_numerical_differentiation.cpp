#include <iostream>
#include <functional>
using namespace std;

static double derivative(const function<double(double)> &f, double x0, double eps) {
	double eps2 = eps / 2;
	double a = x0 - eps2;
	double b = x0 + eps2;
	return (f(b) - f(a)) / eps;
}

static double f(double x) {
	return x * x;
}

int main() {
	double x = 1;
	cout << "d/dx(x ^ 2) [@ x = " << x << "] = " << derivative(f, x, 1e-5) << '\n';
    return 0;
}