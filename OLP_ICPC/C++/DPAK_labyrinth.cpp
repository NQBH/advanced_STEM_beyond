#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;
vector<vector<bool>> check;
pair<int,int> parent[1005][1005];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int start_x, int start_y) {
    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    check[start_x][start_y] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && !check[new_x][new_y] && a[new_x][new_y] != '#') {
                check[new_x][new_y] = true;
                parent[new_x][new_y] = {x, y};
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    check.resize(n + 1, vector<bool>(m + 1, false));
    
    pair<int,int> A, B;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                A = {i,j};
            }
            else if (a[i][j] == 'B') {
                B = {i,j};
            }
        }
    }

    parent[A.first][A.second] = {A.first, A.second};
    bfs(A.first, A.second);
    
    vector<pair<int,int>> path;

    if (!check[B.first][B.second]) {
        cout << "NO";
        return 0;
    } else {
        pair<int,int> cur = B;
        while (cur != A) {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        path.push_back(A);
        reverse(path.begin(), path.end());
    }

    vector<char> real_path;
    for (int i = 1; i < path.size(); i++) {
        int x = path[i].first, y = path[i].second;
        int prev_x = path[i-1].first, prev_y = path[i-1].second;
        if (prev_y - 1 == y) {
            real_path.push_back('L');
        }
        else if (prev_x + 1 == x) {
            real_path.push_back('D');
        }
        else if (prev_y + 1 == y) {
            real_path.push_back('R');
        }
        else if (prev_x - 1 == x) {
            real_path.push_back('U');
        }
    }
    
    cout << "YES" << endl << real_path.size() << endl;
    for (auto r : real_path) {
        cout << r;
    }
}
