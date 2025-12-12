#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
const int MAXN = 200005;

int omega[MAXN], mu[MAXN], min_prime[MAXN];
vector<int> primes;

void sieve() {
	mu[1] = 1;
	omega[1] = 0;
	for (int i = 2; i < MAXN; ++i) {
		if (min_prime[i] == 0) {
			min_prime[i] = i;
			primes.push_back(i);
			omega[i] = 1;
			mu[i] = -1;
		}
		for (int p : primes) {
			if (p > min_prime[i] || (ll)i * p >= MAXN) break;
			min_prime[i * p] = p;
			if (min_prime[i] == p) {
				omega[i * p] = omega[i];
				mu[i * p] = 0;
			} else {
				omega[i * p] = omega[i] + 1;
				mu[i * p] = -mu[i];
			}
		}
	}
}

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
int cnt[8][MAXN], V[MAXN][15], pow_k[16], f[MAXN]; // cnt[p][T] = numbers of elements x divisible by T with omega(x) = p

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i <= n; ++i) f[i] = 0; // reset
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		if (f[1] == n) {
			cout << "0\n";
			continue;
		}
		for (int i = 0; i <= 14; ++i) pow_k[i] = binpow(i, k, mod);
		for (int i = 0; i <= 7; ++i)		
			for (int j = 1; j <= n; ++j) cnt[i][j] = 0;
		for (int k = 1; k <= n; ++k)
			for (int i = k; i <= n; i += k)
				if (f[i] > 0) cnt[omega[i]][k] += f[i];

		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= 14; ++j) V[i][j] = 0;
		for (int i = 1; i <= n; ++i) {
			if (!mu[i]) continue;
			for (int j = i; j <= n; j += i) {
				int w = omega[j / i], mu_val = mu[i];
				for (int k = 0; k <= 14; ++k)
					if (k >= w) {
						int term = pow_k[k - w];
						if (mu_val == 1) {
							V[j][k] += term;
							if (V[j][k] >= mod) V[j][k] -= mod;
						} else {
							V[j][k] -= term;
							if (V[j][k] < 0) V[j][k] += mod;
						}
					}
			}
		}
		ll total_sum = 0;
		for (int j = 1; j <= n; ++j)
			for (int p = 0; p <= 7; ++p) {
				if (!cnt[p][j]) continue;
				for (int k = 0; k <= 7; ++k) {
					if (!cnt[k][j]) continue;
					ll pairs = (ll)cnt[p][j] * cnt[k][j] % mod;
					ll term = pairs * V[j][p + k] % mod;
					total_sum += term;
					total_sum %= mod;
				}
			}
		ll diag_sum = 0;
		for (int x = 1; x <= n; ++x)
			if (f[x] > 0) {
				ll term = (ll)f[x] * pow_k[omega[x]] % mod;
				diag_sum += term;
				diag_sum %= mod;
			}
		ll ans = (total_sum - diag_sum + mod) % mod;
		ll inv2 = binpow(2, mod - 2, mod);
		ans = ans * inv2 % mod;
		cout << ans << '\n';		
	}
}