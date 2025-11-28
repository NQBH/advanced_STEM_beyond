#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		map<int, int> f;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				if (a[i][j] < 0) f[i - j] = min(f[i - j], a[i][j]);
		}
		for (auto e : f)
			if (e.second) ans -= e.second;
		cout << ans << '\n';
	}
}