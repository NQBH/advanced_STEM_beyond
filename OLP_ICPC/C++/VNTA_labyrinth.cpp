#include <bits/stdc++.h>
using namespace std;

int n, m, si, sj, ei, ej;
char a[1001][1001];
bool visited[1001][1001];
int dx[4] = { -1, 0, 0, 1}; // x: row
int dy[4] = {0, -1, 1, 0}; // y: column
char dir[4] = {'U', 'L', 'R', 'D'};
int d[1001][1001]; // d[i][j]: # steps from starting node to (i,j)
pair<int, int> parent[1001][1001];

void inp()  {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                si = i;
                sj = j;
            }
            else if (a[i][j] == 'B') {
                ei = i;
                ej = j;
            }
        }
    memset(visited, false, sizeof(visited));
    memset(d, 0, sizeof(d));
}

// find the shortest path from 'A' to 'B'
void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    d[i][j] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = x + dx[k];
            int nj = y + dy[k];
            if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && a[ni][nj] != '#' && !visited[ni][nj]) {
                parent[ni][nj] = {x, y};
                d[ni][nj] = d[x][y] + 1;
                q.push({ni, nj});
                visited[ni][nj] = true;
                if (a[ni][nj] == 'B') return;
            }
        }
    }
}

void trace_shortest_path() {
    if (!d[ei][ej]) cout << "NO";
    else {
        cout << "YES\n" << d[ei][ej] << '\n';
        string path = "";
        int x = ei, y = ej;
        while (make_pair(x, y) != make_pair(si, sj)) {
            auto [px, py] = parent[x][y];
            for (int k = 0; k < 4; ++k) {
                if (px + dx[k] == x && py + dy[k] == y) {
                    path += dir[k];
                    break;
                }
            }
            x = px;
            y = py;
        }
        reverse(path.begin(), path.end());
        cout << path;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    inp();
    bfs(si, sj);
    trace_shortest_path();
}