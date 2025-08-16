#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n, m, ans;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		int c[n][m];
		for (int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j) cin >> c[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = 0; k < m; ++k)
					ans += abs(c[i][k] - c[j][k]);
		cout << ans << '\n';
	}
}
// TLE on test 4 CodeForces: https://codeforces.com/contest/1808/problem/B
// must sort in each column vector c[i]