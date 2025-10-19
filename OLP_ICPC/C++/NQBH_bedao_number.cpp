#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int m = 1e9 + 7;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k, ans = 0;
		cin >> n >> k;
		if (n == 2) {
			k %= m;
			cout << k << '\n';
		} else {
			vector<int> k_bin;
			while (k > 0) {
				k_bin.push_back(k % 2 == 0 ? 0 : 1);
				k /= 2;
			}
			for (int i = 0; i < k_bin.size(); ++i)
				if (k_bin[i]) ans += exp(n, i, m);
			ans %= m;
			cout << ans << '\n';
		}
	}
}