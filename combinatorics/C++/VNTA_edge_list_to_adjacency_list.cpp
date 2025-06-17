#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G=<V,E> được biểu diễn dưới dạng danh sách cạnh.
Chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << " : ";
        for (int x : adj[i]) cout << x << ' ';
        cout << '\n';
    }
}