#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, sx, sy;
char a[N][N];   

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	a[sx][sy] = '*';
	int px = -1, py = -1;
	while (true) {
		bool wasMove = false;
		for (int i = 0; i < 4; ++i) {
			int nx = sx + dx[i];
    		int ny = sy + dy[i];
    		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    		if (a[nx][ny] != '*') continue;
    		if (nx == px && ny == py) continue;
    		a[nx][ny] = '.';
    		px = sx, py = sy;
    		sx = nx, sy = ny;
    		cout << dir[i];
    		wasMove = true;
    		break;
		}
		if (wasMove) break;
	}
	puts("");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}