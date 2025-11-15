#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '<') g[i].push_back(i - 1);
            else if (s[i] == '>') g[i].push_back(i + 1);
            else {
                g[i].push_back(i - 1);
                g[i].push_back(i + 1);
            }
        }
        vector<int> dp(n, 0); // dp[i] = max move from cell i
        vector<int> color(n, 0); // 0 = unvisited, 1 = visiting, 2 = finished
        bool inf = false;

        function<void(int)> dfs = [&](int u) {
            color[u] = 1;              // visiting
            dp[u] = 0;
            for (int v : g[u]) {
                if (v < 0 || v >= n) { // out of bounds: 1 move
                    dp[u] = max(dp[u], 1);
                    continue;
                }
                if (color[v] == 1) {   // back edge: cycle: infinity
                    inf = true;
                    return;
                }
                if (color[v] == 0) {
                    dfs(v);
                    if (inf) return;
                }
                dp[u] = max(dp[u], 1 + dp[v]);
            }
            color[u] = 2; // finished
        };

        for (int i = 0; i < n; ++i)
            if (color[i] == 0) {
                dfs(i);
                if (inf) break;
            }

        if (inf) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}