#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j =1 ; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cntFox = 0, cntChick = 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= m; j++) {
            if (visited[i][j] == false && a[i][j] != '#') {
                queue<pair<int,int>> q;
                int fox = 0, chick = 0;
                q.push({i, j});
                
                if (a[i][j] == 'c') chick++;
                else if (a[i][j] == 'f') fox++;
                visited[i][j] = true;
                while (q.empty() == false) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int new_x = x + dx[i];
                        int new_y = y + dy[i];
                        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && visited[new_x][new_y] == false && a[new_x][new_y] != '#') {
                            if (a[new_x][new_y] == 'c') chick++;
                            else if (a[new_x][new_y] == 'f') fox++;
                            visited[new_x][new_y] = true;
                            q.push({new_x, new_y});
                        }
                    }
                }
                if (chick > fox) {
                    cntChick += chick;
                }
                else {
                    cntFox += fox;
                }
            }
        }
    }
    cout << cntFox << " " << cntChick;
}