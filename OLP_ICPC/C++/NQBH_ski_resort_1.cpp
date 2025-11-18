#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C2(int n) {
	return 1LL * n * (n - 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, q;
		ll ans = 0;
		cin >> n >> k >> q;
		vector<int> a(n);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] <= q) ++cnt;
			else {
				if (cnt >= k) ans += C2(cnt - k + 2);
				cnt = 0;
			}
		}
		if (a[n - 1] <= q) if (cnt >= k) ans += C2(cnt - k + 2);
		cout << ans << '\n';
	}
}