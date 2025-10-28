#include <bits/stdc++.h>
using namespace std;

struct Solver {
    int n, k;
    vector<vector<int>> g;
    vector<int> sz;

    void dfs_sz(int v, int parent) {
        sz[v] = 1;
        for (int child : g[v]) {
            if (child == parent) continue;
            dfs_sz(child, v);
            sz[v] += sz[child];
        }
    }

    long long solve() {
        sz.assign(n + 1, 0);
        dfs_sz(1, -1);

        long long answer = 0;
        int limit = n - k;                     // heavy <= limit

        for (int v = 1; v <= n; ++v) {
            long long cnt = 0;
            // root = v itself
            if (0 <= limit) cnt += 1;

            // children in the *unrooted* tree
            for (int c : g[v]) {
                int heavy = n - sz[c];
                if (heavy <= limit) cnt += sz[c];
            }
            answer += cnt;
        }
        return answer;
    }

    Solver() {
        int T;
        if (!(cin >> T)) return;
        while (T--) {
            cin >> n >> k;
            g.assign(n + 1, {});
            for (int i = 0; i < n - 1; ++i) {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            cout << solve() << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solver solver;
    return 0;
}
// WA CF