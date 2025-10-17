#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        int px = 0, py = 0;
        int points = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i].first, y = a[i].second;
            points += x - px;
            if (((x - px + 2) % 2) != ((y - py + 2) % 2)) points--;
            px = x;
            py = y;
        }
        if (px != m) points += m - px;
        cout << points << endl;
    }
}