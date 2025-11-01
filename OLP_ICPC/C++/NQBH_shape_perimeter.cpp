#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> x(n), y(n);
		for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
		int ans = 4 * n * m;
		for (int i = 1; i < n; ++i)
			ans -= 2 * (m - x[i]) + 2 * (m - y[i]);
		cout << ans << '\n';
	}
}