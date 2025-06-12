#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	if (a < 2)
		cout << "Error: square root of negative real number.";
	else if (a == 2 or b == 0 or c == -1 or c == 1)
		cout << "Error: division by 0.";
	else
		cout << pow(a, 4) * pow(b, 3 - 1.0 / 3) * pow(c, 1.0 / 3) * 1.0 / (sqrt(a - 2) * (c * c - 1));
}