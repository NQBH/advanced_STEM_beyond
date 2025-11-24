#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		ll ans = 0;
		cin >> n >> l >> r;
		vector<ll> a(n), ps(n + 1, 0);
		for (ll &x : a) cin >> x;
		sort(a.begin(), a.end());
		for (int i = 1; i <= n; ++i) ps[i] = ps[i - 1] + a[i - 1];
		for (int i = 0; i <= n / 2 + 1; ++i)	 {
			ll profit = ps[n] - ps[n - i] - ps[i];
			ans = max(ans, profit);
		}
		/*
		for (int i = 0; i < n; ++i) {
			if (a[i] <= l) ans += l - a[i];
			else if (a[i] >= r) ans += a[i] - r;
		}
		*/
		cout << ans << '\n';
	}
}