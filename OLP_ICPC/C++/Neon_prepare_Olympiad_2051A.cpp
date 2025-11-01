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
		vector<int> a(n), b(n);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		int ans = a[n - 1];
		for (int i = 0; i < n - 1; ++i)
			ans += max(0, a[i] - b[i + 1]);
		cout << ans << '\n';
	}
}