#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G = <V,E> được biểu diễn dưới dạng danh sách cạnh.
Chuyển đổi biểu diễn đồ thị dưới dạng ma trận kề
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    int a[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a[i][j] = 0;

    for (int e = 0; e < m; e++) {
        cin >> u >> v;
        a[u - 1][v - 1] = 1;
        a[v - 1][u - 1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}