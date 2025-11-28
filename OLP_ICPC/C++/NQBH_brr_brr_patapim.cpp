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
		vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
		vector<int> p(2 * n + 1, 0);
		vector<bool> vis(2 * n + 1, false);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				if (!vis[a[i][j]]) {
					p[i + j] = a[i][j];
					vis[a[i][j]] = true;
				}
			}
		for (int i = 1; i <= 2 * n; ++i)
			if (!vis[i]) {
				cout << i << ' ';
				break;
			}
		for (int i = 2; i <= 2 * n; ++i) cout << p[i] << ' ';
		cout << '\n';
	}
}