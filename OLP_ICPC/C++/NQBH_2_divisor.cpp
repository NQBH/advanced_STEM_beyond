#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n == 2 || n == 3) return true;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0) return false;
	return true;
}

int gcd(int a, int b) {
	if (!a || !b) return a | b;
	unsigned shift = __builtin_ctz(a | b);
	a >>= __builtin_ctz(a);
	do {
		b >>= __builtin_ctz(b);
		if (a > b) swap(a, b);
		b -= a;
	} while (b);
	return a << shift;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int solve(int a, int b) {
	if (a == 1) return b * b;
	if (b == 1) return a * b;
	if (a % b == 0 && !is_prime(b)) return 2 * a;
	if (b % a == 0 && !is_prime(a)) return 2 * b;
	if (a % b == 0 && is_prime(b)) return a * b;
	if (b % a == 0 && is_prime(b)) return a * b;
	return lcm(a, b);
}

int main() {
	int a, b, t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve(a, b) << '\n';
	}
}