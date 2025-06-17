#include <bits/stdc++.h>
using namespace std;

/*
Cho đồ thị vô hướng G = <V,E> được biểu diễn dưới dạng danh sách kề.
Chuyển đổi biểu diễn đồ thị dưới dạng danh sách cạnh
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int, int>> edges;
    for (int i = 1; i <= n; ++i) {
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> num)
            if (i < stoi(num)) edges.push_back({i, stoi(num)});
    }
    for (auto e : edges) cout << e.first << ' ' << e.second << '\n';
}