#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n+1), pos(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        // Check possibility: no split i with min(prefix)>max(suffix)
        vector<int> prefMin(n+1), sufMax(n+2);
        prefMin[1] = p[1];
        for (int i = 2; i <= n; ++i) prefMin[i] = min(prefMin[i-1], p[i]);
        sufMax[n] = p[n];
        for (int i = n-1; i >= 1; --i) sufMax[i] = max(sufMax[i+1], p[i]);

        bool possible = true;
        for (int i = 1; i < n; ++i) {
            if (prefMin[i] > sufMax[i+1]) { possible = false; break; }
        }

        if (!possible) {
            cout << "No\n";
            continue;
        }

        // Construct tree
        // We'll produce n-1 edges (u,v) where u < v and pos[u] < pos[v].
        vector<pair<int,int>> edges;
        edges.reserve(n-1);

        // set of positions of values > current v (we go descending v)
        set<int> S; // stores positions (indices) of already inserted values (>current v)

        // We go v = n down to 1 and for v != n link v to the value whose position is the smallest > pos[v]
        for (int v = n; v >= 1; --v) {
            if (!S.empty()) {
                // Find a position in S strictly greater than pos[v]
                auto it = S.lower_bound(pos[v] + 1);
                if (it == S.end()) {
                    // This should not happen under possibility check.
                    // But to be safe (defensive), try to continue — graph would be disconnected otherwise.
                    // We can skip adding an edge for v==n (largest) but for other v it's invalid.
                } else {
                    int chosenPos = *it;
                    int w = p[chosenPos]; // value at that position
                    // v < w by construction (we inserted only values > current v)
                    edges.emplace_back(v, w);
                }
            }
            // Insert current position for future smaller v's
            S.insert(pos[v]);
        }

        // We should have exactly n-1 edges
        // (If we have fewer due to defensive checks, fill won't occur — but under correctness we get n-1)
        cout << "Yes\n";
        for (auto &e : edges) cout << e.first << ' ' << e.second << '\n';
    }
    return 0;
}
// WA CF: useless