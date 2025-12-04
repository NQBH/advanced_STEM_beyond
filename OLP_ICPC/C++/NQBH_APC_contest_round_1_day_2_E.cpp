#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1000000007;

ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

const int MAXN = 2e5;
ll fac[MAXN + 1], inv[MAXN + 1];

/** @return x^n modulo m in O(log p) time. */
ll exp(ll x, ll n, ll m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(ll p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % p;
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(ll p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % p;
}

/** @return nCr mod p */
ll C(ll n, ll r, ll p) {
	if (r < 0 || r > n) return 0;
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	if (k == n - 1) cout << n + 1;
	else if (k == n) cout << 1;
	else { // a = number of A
		factorial(m);
		inverses(m);
		for (int a = k; a <= n; ++a) { // Euler's candy problem
			ans += C(a + 1, n - a, m);
			ans %= m;
		}
		cout << ans;
	}
}