#include <bits/stdc++.h>
#define int long long
using namespace std;
// phải, xuống, trái, lên
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

signed main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    vector<vector<bool>> blocked(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        blocked[x][y] = true;
    }

    int r = (n + 1) / 2;
    int c = (n + 1) / 2;
    int dir = 0;
    int step_len = 1;
    int filled = 0;
    int step_number = 1;

    if (blocked[r][c]) a[r][c] = 0;
    else a[r][c] = step_number++;
    filled++;

    while (filled < n * n) {
        for (int repeat = 0; repeat < 2 && filled < n * n; repeat++) {
            for (int t = 0; t < step_len && filled < n * n; t++) {
                r += dr[dir];
                c += dc[dir];

                if (blocked[r][c]) a[r][c] = 0;
                else a[r][c] = step_number++;

                filled++;
            }
            dir = (dir + 1) % 4;
        }
        step_len++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
