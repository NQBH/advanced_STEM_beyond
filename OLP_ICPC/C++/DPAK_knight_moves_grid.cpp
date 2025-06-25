#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>a(1005, vector<int>(1005, -1));
int n;

int dx[8] = {-1, -1, -2, -2, 1,  1, 2,  2};
int dy[8] = {-2,  2, -1,  1, -2, 2, -1, 1};

signed main() {
    cin >> n;

    queue<pair<int, int>> q;

    q.push({1, 1});
    a[1][1] = 0;

    while (q.empty() == false) {
        auto [x, y] = q.front();

        q.pop();

        for (int i = 0; i < 8; i++) {
            int new_x = dx[i] + x;
            int new_y = dy[i] + y;
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= n && a[new_x][new_y] == -1) {
                a[new_x][new_y] = a[x][y] + 1;
                q.push({new_x, new_y});
            }
        }


    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}