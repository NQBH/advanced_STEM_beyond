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
		ll p = power(m, mod - 2, mod); // p = m^{-1} % mod
		// compute p^0 to p^n
		vector<ll> pp(n + 1);
		pp[0] = 1;
		for (int i = 1; i <= n; ++i) pp[i] = (pp[i - 1] * p) % mod;
		vector<ll> prefp(n + 1, 0), pref_linear(n + 1, 0), pref_linear_odd(n + 1, 0);
		prefp[0] = 1, pref_linear[0] = 1, pref_linear_odd[0] = 0;
		for (int r = 1; r <= n; ++r) {
			prefp[r] = (prefp[r - 1] + pp[r]) % mod;
			pref_linear[r] = (pref_linear[r - 1] + (2ll * r + 1) % mod * pp[r] % mod) % mod;
			pref_linear_odd[r] = (pref_linear_odd[r - 1] + (2ll * r - 1) % mod * pp[r] % mod) % mod;
		}
		ll sumE = 0; // sum of E[Xc]
		ll sum_correction = 0; // sum of var[Xc] = sum(E[Xc^2] - E[Xc]^2)
		// integer-centered palindrome
		for (int i = 1; i <= n; ++i) {
			int K = min(i - 1, n - i);
			ll S = prefp[K], Q = pref_linear[K];
			// C = Var(Xc) = Q - S^2
			ll C = (Q - (S * S) % mod + mod) % mod;
			sumE = (sumE + S) % mod;
			sum_correction = (sum_correction + C) % mod;
		}
		// half-integer-centered palindrome
		for (int i = 1; i < n; ++i) {
			int K = min(i, n - i);
			ll S = (prefp[K] - 1 + mod) % mod, Q = pref_linear_odd[K];
			ll C = (Q - (S * S) % mod + mod) % mod;
			sumE = (sumE + S) % mod;
			sum_correction = (sum_correction + C) % mod;
		}
		// ans = (sum E)^2 + sum Var
		ll ans = (sumE * sumE) % mod;
		ans = (ans + sum_correction) % mod;
		cout << ans << '\n';
	}
}