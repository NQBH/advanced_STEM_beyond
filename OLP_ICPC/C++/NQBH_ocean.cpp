#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main() {
    int n, m, h; // h: ocean level
    cin >> n >> m;
    int a[m][n];
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];

    vector<vector<bool>> visited(m, vector<bool>(n, false)), ocean(m, vector<bool>(n, false));
    deque<pair<int, int>> q, Q;

    for (int h = 0; h <= 1000; ++h) {
        for (int i = 0; i < m; ++i) {
            if (a[i][0] <= h) {
                ocean[i][0] = true;
                q.push_back(make_pair(i, 0));
            }
            if (a[i][n - 1] <= h) {
                ocean[i][n - 1] = true;
                q.push_back(make_pair(i, n - 1));
            }
        }
        for (int j = 0; j < n; ++j) {
            if (a[0][j] == h) q.push_back(make_pair(0, j));
            if (a[m - 1][j] == h) q.push_back(make_pair(0, j));
        }

        while (!q.empty()) {
            int i = q[0].first, j = q[0].second;
            q.pop_front();
            for (int k = 0; k < 4; ++k) {
                int ti = i + dx[k], tj = j + dy[k];
                if (ti >= 0 && ti < m && tj >=0 && tj < n) {
                    if (!visited[ti][tj] && a[ti][tj] == h) {
                        ocean[ti][tj] == true;
                        q.push_back(make_pair(ti, tj));
                    }
                }
            }
        }
        // BFS counts number of connected components


    }



    q.push(1);
    visited[1] = true;
    while (q.empty() == false) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (visited[v] == true) continue;
            visited[v] = true;
            q.push(v);
        }
    }
    int flag = 0;
    for (int i = 2; i <= n; i++) {
        if (visited[i] == false) {
            cout << i << " ";
            flag = 1;
        }
    }
    if (flag == 0) cout << 0;
}