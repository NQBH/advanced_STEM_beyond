#include <iostream>
#include <queue>
using namespace std;

const int mod = 1e9 + 7;
int dx[2] = {1, 0}, dy[2] = {0, 1};

int main() {
	int m, n, k, x, y;
	long long num_path = 0;
	cin >> m >> n >> k;
	int a[m + 1][n + 1] = {0};
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		a[x][y] = -1; // forbidden
	}
	if (a[m][n] == -1) {
		cout << 0;
		return 0;
	}
	queue<pair<int, int>> q;
	q.push({1, 1});
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 2; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx == m && ny == n) ++num_path;
			else if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && a[nx][ny] != -1) q.push({nx, ny});
		}
	}
	cout << num_path % mod;
}