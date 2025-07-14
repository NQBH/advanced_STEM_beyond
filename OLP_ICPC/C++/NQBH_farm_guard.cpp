#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int n, m, h; // h: ocean level
	cin >> n >> m;
	int a[m][n], h[m][n];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) cin >> a[i][j];
	queue<pair<int, int>> q;
	vector<vector<bool>> top(n, vector<bool>(m, true)), visited(n, vector<bool>(m, false));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			visited[i][j] = true;
			for (int k = 0; k < 8; ++k) {
				int new_x = i + dx[k];
				int new_y = j + dy[k];
				if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && visited[new_x][new_y] == false) {
					if (h[i][j] < h[new_x][new_y]) {
						top[i][j] = false;
					} // h_ij is not top
					else if (h[i][j] > h[new_x][new_y]) {
						top[new_x][new_y] = false;
						visited[new_x][new_y] = true;
					}
					else { // h[i][j] == h[new_x][new_y]
						q.push({i, j});
						visited[i][j] = true;
						q.push({new_x, new_y});
						visited[new_x][new_y] = true;
					}

				}
			}
		}
	// BFS count connected components
	int cnt = 0;
	vector<vector<bool>> checkComponent(n, vector<bool>(m, false));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visited[i][j] == false && checkComponent[i][j] == false) {
				cnt++;
				queue<pair<int, int>> cq;
				cq.push({i, j});
				checkComponent[i][j] = true;
				while (cq.empty() == false) {
					auto [x, y] = cq.front();
					cq.pop();
					for (int i = 0; i < 4; i++) {
						int new_x = dx[i] + x;
						int new_y = dy[i] + y;
						if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && visited[new_x][new_y] == false && checkComponent[new_x][new_y] == false) {
							cq.push({new_x, new_y});
							checkComponent[new_x][new_y] = true;
						}
					}
				}
			}
		}
	}
	cout << cnt;
}