#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G = <V,E> được biểu diễn dưới dạng danh sách kề.
Chuyển đổi biểu diễn đồ thị dưới dạng ma trận kề
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    int a[n + 1][n + 1];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) a[i][j] = 0;

    for (int i = 1; i <= n; ++i) {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num) a[i][stoi(num)] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}