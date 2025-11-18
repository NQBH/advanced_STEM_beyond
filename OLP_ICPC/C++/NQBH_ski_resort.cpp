#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, q;
		long long ans = 0;
		cin >> n >> k >> q;
		vector<int> a(n);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] <= q) ++cnt;
			else {
				if (cnt >= k) ans += 1LL * (cnt + 1) * (cnt - k + 1) - 1LL * cnt * (cnt + 1) / 2 + 1LL * (k - 1) * k / 2;
				cnt = 0;
			}
		}
		if (a[n - 1] <= q) if (cnt >= k) ans += 1LL * (cnt + 1) * (cnt - k + 1) - 1LL * cnt * (cnt + 1) / 2 + 1LL * (k - 1) * k / 2;
		cout << ans << '\n';
	}
}