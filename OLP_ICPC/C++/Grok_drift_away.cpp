#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();

        // ---------- build graph ----------
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '<') g[i].push_back(i - 1);
            else if (s[i] == '>') g[i].push_back(i + 1);
            else {                     // '*'
                g[i].push_back(i - 1);
                g[i].push_back(i + 1);
            }
        }

        // ---------- DFS ----------
        vector<int> dp(n, 0);          // max moves from this cell
        vector<int> color(n, 0);       // 0=unvisited, 1=visiting, 2=finished
        bool has_cycle = false;

        function<void(int)> dfs = [&](int u) {
            color[u] = 1;              // visiting
            dp[u] = 0;
            for (int v : g[u]) {
                if (v < 0 || v >= n) { // out of bounds → 1 move
                    dp[u] = max(dp[u], 1);
                    continue;
                }
                if (color[v] == 1) {   // back edge → cycle
                    has_cycle = true;
                    return;
                }
                if (color[v] == 0) {
                    dfs(v);
                    if (has_cycle) return;
                }
                dp[u] = max(dp[u], 1 + dp[v]);
            }
            color[u] = 2;              // finished
        };

        for (int i = 0; i < n; ++i)
            if (color[i] == 0) {
                dfs(i);
                if (has_cycle) break;
            }

        if (has_cycle) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}