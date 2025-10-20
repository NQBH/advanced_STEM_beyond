#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1, 0,0};
signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
//        set<pair<int,int>> ms;
        vector<vector<bool>> a(n + 1, vector<bool> (n + 1, true)), visited(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= m; i++) {
            int x,y; cin >> x >> y;
//            ms.insert({x, y});
            a[x][y] = false;
        }
        if (m == 0) {
            if (n % 2 == 0) {
                cout << "YES";
            }
            else cout << "NO";
            cout << endl;
            continue;
        }
        bool check = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visited[i][j] == true || a[i][j] == false) continue;
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (q.empty() == false) {
                    auto [x, y] = q.front();
                    q.pop();
                    cnt += (((x + y) % 2) ? 1 : - 1);
                    for (int k = 0; k < 4; k++) {
                        int new_x = x + dx[k];
                        int new_y = y + dy[k];
                        if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n && visited[new_x][new_y] == false && a[new_x][new_y] == true) {
                            visited[new_x][new_y] = true;
                            q.push({new_x, new_y});
                        }
                    }
                }
                if (cnt != 0) {
                    check = false;
                    break;
                }
            }
            if (check == false) break;
        }
        if (check == false) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}
/*
O O O
X X O
O O O
*/