#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// The problem asks for modulo 998244353.
const int MOD = 998244353;

struct Edge {
    int u, v;
    ll val_u, val_v;
};

// Comparator to sort edges based on the value of the destination node.
// This ensures that when we process an edge u->v, any potential 
// predecessor edge t->u (where a_t + a_u = a_v) has already been processed
// because a_v = a_u + a_t implies a_v > a_u (since a_t >= 1).
bool compareEdges(const Edge& a, const Edge& b) {
    return a.val_v < b.val_v;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Use 1-based indexing for convenience
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, a[u], a[v]});
    }

    // Sort edges by destination value to process in topological order of sequence growth
    sort(edges.begin(), edges.end(), compareEdges);

    // sum_dp[u][val] stores the sum of valid paths ending at node u
    // where the node preceding u had the value 'val'.
    // Effectively: sum(dp[t->u]) where a[t] == val.
    vector<map<long long, long long>> sum_dp(n + 1);

    long long total_ans = 0;

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long val_u = edge.val_u;
        long long val_v = edge.val_v;

        // Base case: The path consisting of just the edge (u, v) is always valid (len 2)
        long long current_paths = 1;

        // Recursive step: Try to extend paths ending at u.
        // We look for a predecessor t such that a[t] + a[u] == a[v].
        // So we need a[t] == a[v] - a[u].
        long long required_val_t = val_v - val_u;

        // If required_val_t <= 0, no such t exists (since a[i] >= 1).
        if (required_val_t > 0) {
            auto it = sum_dp[u].find(required_val_t);
            if (it != sum_dp[u].end()) {
                current_paths = (current_paths + it->second) % MOD;
            }
        }

        // Add the number of valid paths ending with this edge to the total answer
        total_ans = (total_ans + current_paths) % MOD;

        // Update the DP state for node v.
        // Any path ending with this edge u->v has a second-to-last value of a[u].
        // This will be useful for edges starting from v.
        sum_dp[v][val_u] = (sum_dp[v][val_u] + current_paths) % MOD;
    }

    cout << total_ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}