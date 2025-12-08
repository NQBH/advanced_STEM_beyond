#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, n_covered = 0;
		ll k;
		cin >> n >> k;
		vector<ll> a(n), V, ans;
		for (ll &x : a) cin >> x;
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		n = a.size(); // distinct elements only
		for (ll x : a) {
			if (k / x > n) continue; // nx: bad
			bool ok = true;
			for (ll i = x; i <= k; i += x) {
				if (!binary_search(a.begin(), a.end(), i)) {
					ok = false;
					break;
				}
			}
			if (ok) V.push_back(x);
		}
		vector<bool> covered(n, false);
		for (ll v : V) {
			int idx = lower_bound(a.begin(), a.end(), v) - a.begin();
			if (covered[idx]) continue;
			ans.push_back(v);
			for (ll i = v; i <= k; i += v) {
				auto it = lower_bound(a.begin(), a.end(), i);
				if (it != a.end() && *it == i) {
					int idx2 = it - a.begin();
					if (!covered[idx2]) {
						covered[idx2] = true;
						++n_covered;
					}
				}
			}
		}
		if (n_covered == n) {
			cout << ans.size() << '\n';
			for (int i : ans) cout << i << ' ';
			cout << '\n';
		} else cout << "-1\n";
	}
}