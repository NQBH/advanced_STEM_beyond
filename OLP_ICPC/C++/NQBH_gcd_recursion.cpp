#include <iostream>
using namespace std;

int gcd_recursion(int a, int b) {
	a = abs(a);
	b = abs(b);
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == 1 || b == 1) return 1;
	if (a == b) return a;
	if (a > b) return gcd_recursion(b, a % b);
	else return gcd_recursion(a, b % a);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd_recursion(a, b);
}