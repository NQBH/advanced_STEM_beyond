#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n, k;
	cin >> m >> n >> k;
	if (m == 1 && k == 1) cout << binpow(4, n, mod);
	else if (k == 1) cout << binpow(binpow(4, n, mod), m, mod); // má tại case trên mà thiếu case này
	else if (k == 2) {
		ll a = (binpow(4, n, mod) - 4) % mod;
		if (a < 0) a += mod;
		cout << binpow(a, m, mod);
	} else if (k == 3) {
		ll a = (binpow(4, n, mod) - 6 * binpow(2, n, mod) + 8) % mod;
		if (a < 0) a += mod;
		cout << binpow(a, m, mod);
	} else {
		ll a = (binpow(4, n, mod) - 4 * binpow(3, n, mod) + 6 * binpow(2, n, mod) - 4) % mod;
		if (a < 0) a += mod;
		cout << binpow(a, m, mod);
	}
}