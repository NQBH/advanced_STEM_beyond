#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		queue<pair<int, int>> q;
		int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) cin >> a[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				if (a[i][j] && !vis[i][j]) {
					int S = a[i][j]; // compute sum of connected component containing a[i][j]
					vis[i][j] = true;
					q.push({i, j});
					while (!q.empty()) {
						auto [x, y] = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nx = x + dx[k], ny = y + dy[k];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
								if (a[nx][ny] && !vis[nx][ny]) {
									S += a[nx][ny];
									q.push({nx, ny});
									vis[nx][ny] = true;
								}
							}
						}
					}
					ans = max(ans, S);
				}
			}
		cout << ans << '\n';
	}
}