#include <iostream>
#include <cassert>
using namespace std;
using ll = long long;

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m; // note: m * m must be < 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) res = res * x % m;
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		cout << exp(a, b, 1e9 + 7) << '\n';
	}
}