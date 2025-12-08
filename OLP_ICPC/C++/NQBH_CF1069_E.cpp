#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll base, ll exp, ll mod) {
	ll res = 1;
	base %= mod;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}

ll modInverse(ll n, ll mod) {
	return power(n, mod - 2, mod);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, mod;
		cin >> n >> m >> mod;
		if (m == 1) {
			ll N = 1ll * n * (n + 1) / 2;
			N %= mod;
			cout << (N * N) % mod << '\n';
			continue;
		}
		ll p = modInverse(m, mod); // p = m^{-1} % mod
		// compute p^0 to p^n
		vector<ll> pp(n + 1);
		pp[0] = 1;
		for (int i = 1; i <= n; ++i) pp[i] = (pp[i - 1] * p) % mod;
		ll total_sum = 0, total_square_sum = 0, total_diag = 0;
		// center: 1, 1.5, 2, ..., n: 2n - 1 centers
		for (int c2 = 2; c2 <= 2 * n; ++c2) {
			ll currS = 0, currD = 0;
			if (c2 & 1) {
				int i = (c2 - 1) / 2, K = min(i, n - i);
				for (int r = 1; r <= K; ++r) currS = (currS + pp[r]) % mod;
				for (int r = 1; r <= K; ++r) {
					ll term = (ll)(2 * r - 1) * pp[r];
					currD = (currD + term) % mod;
				}
			} else {
				int c = c2 / 2, K = min(c - 1, n - c);
				for (int r = 0; r <= K; ++r) currS = (currS + pp[r]) % mod;
				for (int r = 0; r <= K; ++r) {
					ll term = (ll)(2 * r + 1) * pp[r];
					currD = (currD + term) % mod;
				}
			}
			total_sum = (total_sum + currS) % mod;
			ll sq = (currS * currS) % mod;
			total_square_sum = (total_square_sum + sq) % mod;
			total_diag = (total_diag + currD) % mod;
		}
		// ans = (sum S)^2 - sum S^2 + sumD
		ll ans = ((total_sum * total_sum) % mod - total_square_sum + total_diag) % mod;
		if (ans < 0) ans += mod;
		cout << ans << '\n';
	}
}