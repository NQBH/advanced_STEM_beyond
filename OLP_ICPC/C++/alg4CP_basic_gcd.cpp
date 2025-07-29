#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd (b, a % b);
}

int gcd_1(int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int gcd_2(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int gcd_3(int a, int b) {
	if (!a || !b) return a | b;
	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do {
		b >>= __builtin_ctz(b);
		if (a > b) swap(a,b);
		b -= a;
	} while (b);
	return a << shift;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << " " << gcd_1(a, b) << " " << gcd_2(a, b) << " " << gcd_3(a, b);
}