#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, -1, 1, 0};
int dy[4] = { -1, 0, 0, 1};
char movement[4] = {'D', 'L', 'R', 'U'};

int main() {
	int m, n, xA, yA, xB, yB;
	bool A_found = false, B_found = false;
	cin >> n >> m;
	string path, c[n];
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		for (int j = 0; j < m; ++j) { // search A & B
			if (A_found == false && c[i][j] == 'A') {
				A_found = true;
				xA = i;
				yA = j;
			}
			if (B_found == false && c[i][j] == 'B') {
				B_found = true;
				xB = i;
				yB = j;
			}
			if (A_found == true && B_found == true) break;
		}
	}
	queue<pair<int, int>> q;
	q.push({xA, yA});
	c[xA][yA] = '#';
	while (!q.empty()) {
		auto [x, y] = q.front(); // same as int x = q.front().first; y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny] != '#') {
            	if (c[nx][ny] == 'B') {
            		cout << "YES" << "\n";
            		path += movement[i];
            		cout << path.length() << "\n";
            		cout << path;
            		return 0;
            	}
            	if (c[nx][ny] == '.') {
            		c[nx][ny] = '#';
            		q.push({nx, ny});
            		path += movement[i];
            	}
            }
		}

	}
	cout << "NO";
}