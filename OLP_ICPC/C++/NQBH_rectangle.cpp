#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)), ans(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i) {
			string s;
			cin >> s;
			for (int j = 1; j <= m; ++j)
			if (s[j - 1] == '1') a[i][j] = 1;
		}
		/*
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cout << a[i][j] << " ";
			cout << '\n';
		}
		*/
		for (int u = 1; u <= n; ++u) {
			for (int l = 1; l <= m; ++l) {
				if (!a[u][l]) continue;
				for (int d = u + 1; d <= n; ++d) {
					if (!a[d][l]) continue;
					for (int r = l + 1; r <= m; ++r) {
						if (!a[u][r] || !a[d][r]) continue;
						// valid rectangle
						int S = (d - u + 1) * (r - l + 1);
						for (int i = u; i <= d; ++i)
							for (int j = l; j <= r; ++j) {
								if (!ans[i][j]) ans[i][j] = S;
								else if (S < ans[i][j]) ans[i][j] = S;
							}
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j)
				cout << ans[i][j] << " ";
			cout << '\n';
		}
	}
}
// TLE on pretest 7 CodeForces