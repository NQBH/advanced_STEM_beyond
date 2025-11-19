#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int mn = n;
		vector<int> a(n + 1, 0), ans(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = n; i >= 1; --i) {
			mn = min(mn, i - a[i]);
			if (mn < i) ans[i] = 1;
		}
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}