#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m), f(n + 1), st(n + 1, 0), en(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i];
		st[l[i]] = 1;
		en[r[i]] = 1;
		for (int j = l[i]; j <= r[i]; ++j) ++f[j];
	}
	vector<int> ans(n + 1, -1);
	auto fill = [&]() {
		vector<bool> used(n, false);
		for (int i = 1; i <= n; ++i)
			if (ans[i] != -1) used[ans[i]] = true;
		int p = 0;
		for (int i = 1; i <= n; ++i)
			if (ans[i] == -1) {
				while (used[p]) ++p;
				ans[i] = p;
				used[p] = true;
			}
		for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
	};

	for (int i = 1; i <= n; ++i)
		if (f[i] == m) {
			int ptr = 1; // unused?
			ans[i] = 0;
			fill();
			return;
		}
	for (int i = 1; i < n; ++i) {
		if (en[i] == 0) {
			ans[i] = 0;
			ans[i + 1] = 1;
			fill();
			return;
		}
		if (st[i + 1] == 0) {
			ans[i] = 1;
			ans[i + 1] = 0;
			fill();
			return;
		}
	}
	assert(n >= 3);
	ans[1] = 0;
	ans[2] = 2;
	ans[3] = 1;
	fill();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}