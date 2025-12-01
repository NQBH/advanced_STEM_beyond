#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];
	vector<int> cnt(2 * n + 1);
	for (auto &x : a) ++cnt[x];
	int x = 0, y = 0, z = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		if (cnt[i] == 0) continue;
		if (cnt[i] & 1) ++x; // odd elements
		else if (cnt[i] % 4) ++y; // element of form 4k + 2
		else ++z; // element of form 4k
	}
	int ans = x + 2 * y + 2 * z;
	if ((z & 1) && x == 0) ans -= 2;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}