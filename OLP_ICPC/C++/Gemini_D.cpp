#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[c][v] stores the minimum penalty sum((v_r - v_{r-1}) * i_r)
    // for a sequence of values summing to c, ending with value v.
    vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, INF));

    // Base case: cost 0, last value 0, penalty 0
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        int limit = min(a[i-1], k);
        // We update dp in place. To avoid using updated values from the current friend
        // for the same friend (which would imply i_r = i_{r+1} = i, impossible since indices distinct),
        // we iterate cost c downwards.
        // However, the transition uses dp[c][u] to update dp[c+v][v].
        // Since v > 0, c+v > c. So iterating c downwards is correct.
        
        for (int c = k; c >= 0; --c) {
            long long best_diff = INF;
            // best_diff stores min(dp[c][u] - u * i) for u < v
            
            // We can iterate v from 1 to limit.
            // As v increases, the range of valid u (0 to v-1) grows.
            // So we can maintain best_diff incrementally.
            
            int u = 0;
            // Initialize best_diff for v=1 (u=0 only)
            if (dp[c][0] != INF) best_diff = dp[c][0] - 0;
            
            for (int v = 1; v <= limit; ++v) {
                // Before processing v, ensure best_diff covers u up to v-1.
                // It already covers up to v-2 from previous iteration.
                // We need to check u = v-1.
                int prev_u = v - 1;
                if (prev_u > 0) { // u=0 handled in init
                    if (dp[c][prev_u] != INF) {
                        best_diff = min(best_diff, dp[c][prev_u] - (long long)prev_u * i);
                    }
                }
                
                if (c + v <= k) {
                    if (best_diff != INF) {
                        dp[c+v][v] = min(dp[c+v][v], best_diff + (long long)v * i);
                    }
                }
            }
        }
    }

    long long max_happiness = 0;
    for (int c = 0; c <= k; ++c) {
        for (int v = 0; v <= k; ++v) {
            if (dp[c][v] != INF) {
                // Happiness = v_p * (n + 1) - Penalty
                long long current_happiness = (long long)v * (n + 1) - dp[c][v];
                max_happiness = max(max_happiness, current_happiness);
            }
        }
    }

    cout << max_happiness << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}