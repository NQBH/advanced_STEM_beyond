#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, y;
	cin >> x >> y;
	if (x < 0) {
		cout << "x must be nonnegative";
	}
	else {
		cout << sqrt(x);
		cout << pow(x, y);
		cout << exp(x);
	}
	if (x > 0) {
		cout << log(x);
		cout << log10(x);
	}
	else {
		cout << "x must be nonnegative";
	}
	cout << abs((int)x);
	cout << labs((long)x);
	cout << fabs(x);

	cout << cos(x);
	cout << sin(x);
	cout << tan(x);
	if (x >= -1 && x <= 1) {
		cout << acos(x);
		cout << asin(x);
	}
	else {
		cout << "x must be nonnegative";
	}
	cout << atan(x);
	cout << floor(x);
	cout << ceil(x);
	return 0;
}