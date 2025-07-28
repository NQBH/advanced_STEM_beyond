#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll bin_pow(ll a, ll b) {
	if (b == 0) return 1;
	ll res = bin_pow(a, b / 2);
	if (b % 2) return res * res * a;
	else return res * res;
}

ll bin_pow_1(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

ll bin_pow_mod(ll a, ll b, ll m) { // compute a^b mod m
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

int main() {
	ll a, b, m;
	cin >> a >> b >> m;
	cout << bin_pow(a, b) << " " << bin_pow_1(a, b) << bin_pow_mod(a, b, m);
}