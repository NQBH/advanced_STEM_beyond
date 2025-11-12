#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

struct cell {
    int x, y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

signed main() {
    int t = 1; //cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        vector<vector<char>> a(r + 1, vector<char>(c + 1));
        queue<cell> q;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'W') {
                    q.push({i, j});
                }
                if (a[i][j] == '.') a[i][j] = 'D';
            }
        }
        bool check = true;
        while (q.empty() == false && check == true) {
            auto [x, y] = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
                    if (a[nx][ny] == 'S') {
                        check = false;
                        break;
                    }
                }
            }
        }
        if (check == false) {
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}
