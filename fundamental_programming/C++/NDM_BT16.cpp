#include <iostream>
using namespace std;
double a, b, c;
double f(double a, double b, double c, double x) {
	return (a * x * x) + (b * x) + c;
}

double F(int n, double alpha) {
	double current_val = alpha;
	for (int i = 0; i < n; ++i) {
		current_val = f(a, b, c, current_val);
	}
	return current_val;
}

int main() {
	double x;
	int n;
	cout << "a, b, c, x, n: ";
	if (cin >> a >> b >> c >> x >> n) {
		double alpha = x;
		cout << F(n, alpha);
	}
	return 0;
}