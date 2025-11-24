#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, q, c, l, r;
		cin >> n >> k >> q;
		vector<int> a(n + 1, 1e9);
		vector<pair<int,int>> op2;
		for (int i = 0; i < q; ++i) {
			cin >> c >> l >> r;
			if (c == 1) {
				for (int i = l; i <= r; ++i) a[i] = k;
			} else op2.emplace_back(l, r);
		}
		sort(op2.begin(), op2.end());
		for (auto &e : op2) {
			tie(l, r) = e;
			// put 0, 1, ..., k - 1 in [l..r]
			if (a[l] == 1e9) for (int i = 0; i < k; ++i) a[l + i] = i;
			else if (a[l] == k) {
				for (int i = 0; i < k; ++i) a[r - i] = i;
				for (int i = l; i <= r - k; ++i) a[i] = 1e9;
			} else if (a[l] == k - 1) {
				for (int i = 1; i < k; ++i) a[l + i] = k - 1 - i;
			} else if (a[l] < k - 1) {
				for (int i = 1; i <= k - 1 - a[l]; ++i) a[l + i] = a[l + i - 1] + 1;
				for (int i = k - a[l]; i <= r; ++i) a[i] = 1e9;
			} else if (a[r] == k) {
				for (int i = 0; i < k; ++i) a[l + i] = i;
				for (int i = k; i <= r; ++i) a[i] = 1e9;
			}
		}
		for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
	}
}