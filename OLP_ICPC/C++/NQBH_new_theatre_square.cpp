#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y, ans = 0;
		cin >> n >> m >> x >> y;
		vector<vector<char>> a(n, vector<char>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) cin >> a[i][j];
		if (2 * x <= y) { // use all 1 x 1
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					if (a[i][j] == '.') ++ans;
				}
			ans *= x;
		} else { // use 1 x 2 whenever possible
			for (int i = 0; i < n; ++i) {
				int n_conse = 0;
				for (int j = 0; j < m; ++j) {
					if (a[i][j] == '.') ++n_conse;
					else {
						if (n_conse & 1) {
							ans += n_conse / 2 * y + x;
						} else {
							ans += n_conse / 2 * y;
						}
						n_conse = 0;
					}
				}
				if (a[i][m - 1] == '.') {
					if (n_conse & 1) {
							ans += n_conse / 2 * y + x;
						} else {
							ans += n_conse / 2 * y;
						}
						n_conse = 0;
				}
			}
		}
		cout << ans << '\n';
	}
}