#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1, 0), plen(n + 1, 1), slen(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	// precompute for subtask 2
	for (int i = 2; i <= n; ++i) {
		int j = i;
		while (j >= 1 && a[j - 1] < a[j]) --j;
		plen[i] = i - j + 1;
	}
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (j <= n && a[j] < a[j + 1]) ++j;
		slen[i] = j - i + 1;
	}
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int i, x;
			cin >> i >> x;
			a[i] = x;
		} else {
			int l, r;
			cin >> l >> r;
			int cur_len = 1, ans = 0;
			for (int j = l + 1; j <= r; ++j) {
				if (a[j] > a[j - 1]) ++cur_len;
				else {
					ans = max(ans, cur_len);
					cur_len = 1;
				}
			}
			ans = max(ans, cur_len);
			cout << ans << '\n';
		}
	}
}