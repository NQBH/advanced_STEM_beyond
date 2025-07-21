#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &a, int r, int c, int n, int m) {
    if ( r < 0 || c < 0 || r >= n || c >= m || a[r][c] != '.' ) return;
    a[r][c] = '#';
    dfs(a, r + 1, c, n, m);
    dfs(a, r - 1, c, n, m);
    dfs(a, r, c + 1, n, m);
    dfs(a, r, c - 1, n, m);
}

void Countroom(vector<vector<char>> &a, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.') {
                dfs(a, i, j, n, m);
                ++count;
            }
    cout << count;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m)) ;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    Countroom(a, n, m);
}