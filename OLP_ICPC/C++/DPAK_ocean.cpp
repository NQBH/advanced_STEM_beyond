#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    int NUM = 1;
    int  n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        bool ok = true;
        for (int f = 1; f <= 1001; f++) {
            queue<pair<int,int>> q;
            vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (i == 1 || i == n || j == 1 || j == m) {
                        if (a[i][j] <= f) {
                            q.push({i, j});
                            visited[i][j] = true;
                        }
                    }

                }
            }
            while (q.empty() == false) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int new_x = dx[i] + x;
                    int new_y = dy[i] + y;
                    if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && a[new_x][new_y] <= f && visited[new_x][new_y] == false) {
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = true;
                    }
                }
            }
            int cnt = 0;
            vector<vector<bool>> checkComponent(n + 1, vector<bool>(m + 1, false));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (visited[i][j] == false && checkComponent[i][j] == false) {
                        cnt++;
                        queue<pair<int,int>> cq;
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
            if (cnt >= 2) {
                cout << "Case " <<NUM++ <<": Island splits when ocean rises " << f << " feet." << endl;
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Case " << NUM++ <<": Island never splits." << endl;
        }
    }
}