#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {

    int n, m; cin >> n >> m;

    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    queue<pair<int,int>> q;
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == false && a[i][j] == 'W') {
                visited[i][j] = true;
                cnt++;
                q.push({i, j});
                while (q.empty() == false) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int d = 0; d < 8; d++) {
                        int new_x = x + dx[d];
                        int new_y = y + dy[d];
                        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m &&
                        a[new_x][new_y] == 'W' && visited[new_x][new_y] == false) {
                            visited[new_x][new_y] = true;
                            q.push({new_x, new_y});
                        }
                    }
                }   
            } 
        }
    }
    cout << cnt;
}