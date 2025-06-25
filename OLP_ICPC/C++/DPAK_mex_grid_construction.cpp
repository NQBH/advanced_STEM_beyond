#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int num = 0;
            set<int> ms;
            for (int r = 1; r <= n; ++r)
                if (a[r][j] != -1) ms.insert(a[r][j]);
            for (int c = 1; c <= n; ++c)
                if (a[i][c] != -1) ms.insert(a[i][c]);

            for (auto it : ms)
                if (it == num) ++num;
            a[i][j] = num;
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cout << a[i][j] << " ";
    cout << '\n';
}