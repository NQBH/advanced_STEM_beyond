#include <bits/stdc++.h>

using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, -1));

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == -1) {
                queue<pair<int, int>> q;
                q.push({i, j});
                bool check = true;
                visited[i][j] = a[i][j];
                int h = a[i][j];
                while (q.empty() == false) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d = 0; d < 8; d++) {
                        int new_x = dx[d] + x;
                        int new_y = dy[d] + y;
                        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m) {
                            if (visited[new_x][new_y] == -1) {
                                if (a[new_x][new_y] == h) {
                                    visited[new_x][new_y] = a[new_x][new_y];
                                    q.push({new_x, new_y});
                                }
                            }
                            if (a[new_x][new_y] > h) {
                                check = false;
                            }
                        }
                    }

                }

                if (check == true) ++cnt;
            }
        }
    }
    cout << cnt;
}