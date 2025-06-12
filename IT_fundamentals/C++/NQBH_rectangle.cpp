#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	if (a <= 0 or b <= 0)
		cout << "Error: a & b must be positive.";
	else {
		cout << "P = " << 2 * (a + b) << '\n' << "S = " << a * b << '\n' << "d = " << sqrt(a * a + b * b);
	}
}