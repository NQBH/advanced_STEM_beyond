#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    // Input grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Find start ('A') and end ('B')
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    // BFS setup
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> parentDir(n, vector<char>(m, 0)); // store move direction

    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dirChar[] = {'U', 'D', 'L', 'R'};

    // for BFS 
    queue<pair<int, int>> q;
    q.push(start); // start at A
    visited[start.first][start.second] = true; // check it off first 

    bool found = false; // for when found B 

    // BFS loop
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Check all 4 directions
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Check bounds, not wall, not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                parentDir[nx][ny] = dirChar[d];
                q.push({nx, ny});
                // If found end
                if (make_pair(nx, ny) == end) {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (!visited[end.first][end.second]) {
        cout << "NO" << endl;
    } else {
        // Reconstruct path
        string path;
        pair<int, int> curr = end;
        while (curr != start) {
            char d = parentDir[curr.first][curr.second];
            path += d;
            curr = parent[curr.first][curr.second]; // update 
        }
        reverse(path.begin(), path.end()); // because we start backwards 
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}