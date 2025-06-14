#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G = <V,E> được biểu diễn dưới dạng ma trận kề.
Chuyển đổi biểu diễn đồ thị dưới dạng danh sách cạnh
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    vector<int> adj[n + 1];
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] == 1) edges.push_back({i + 1, j + 1});
    
    for (int i = 0; i < n; ++i)
        for (auto e : edges) if (e.first == i + 1) adj[i + 1].push_back(e.second);
    
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " : ";
        for (auto a : adj[i + 1]) cout << a << ' ';
        cout << '\n';
    }
}