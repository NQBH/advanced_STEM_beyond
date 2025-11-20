#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    // Directions: U R D L
    int dx[4] = {-1, 0, 1,  0};
    int dy[4] = { 0, 1, 0, -1};
    char dc[4] = {'U', 'R', 'D', 'L'};

    int sx = -1, sy = -1;

    // Find S
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S')
                sx = i, sy = j;

    // Find the two neighbors of S that are part of the cycle
    vector<int> neigh;
    for (int d = 0; d < 4; d++) {
        int nx = sx + dx[d], ny = sy + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (g[nx][ny] == '*' || g[nx][ny] == 'S')
                neigh.push_back(d);
    }

    // Pick one neighbor as direction to start
    int d = neigh[0]; // either direction is ok
    int px = sx, py = sy; // previous
    int cx = sx + dx[d], cy = sy + dy[d]; // current

    string ans;
    ans.push_back(dc[d]);

    // Walk until we return to S
    while (!(cx == sx && cy == sy)) {
        // find next direction from current
        for (int nd = 0; nd < 4; nd++) {
            int nx = cx + dx[nd], ny = cy + dy[nd];
            if (nx == px && ny == py) continue; // don't go back
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (g[nx][ny] == '*' || g[nx][ny] == 'S') {
                    // move
                    px = cx;
                    py = cy;
                    cx = nx;
                    cy = ny;
                    ans.push_back(dc[nd]);
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}