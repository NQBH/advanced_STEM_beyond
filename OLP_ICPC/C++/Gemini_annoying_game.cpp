#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<long long> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    // L[i] stores the maximum subarray sum ending at index i
    vector<long long> L(n);
    L[0] = a[0];
    for (int i = 1; i < n; ++i) {
        // Standard Kadane's logic: extend previous or start new
        L[i] = max(a[i], L[i - 1] + a[i]);
    }

    // R[i] stores the maximum subarray sum starting at index i
    vector<long long> R(n);
    R[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        R[i] = max(a[i], R[i + 1] + a[i]);
    }

    // Calculate the max subarray sum of the original array
    // Initialize with a very small number since values can be negative
    long long original_max = -2e18;
    for (long long val : L) {
        original_max = max(original_max, val);
    }

    if (k % 2 == 0) {
        // If k is even, Bob can always cancel Alice's moves to maintain the status quo.
        cout << original_max << "\n";
    } else {
        // If k is odd, Alice effectively gets one uncancelled move.
        // We check the best possible result by modifying exactly one a[i] += b[i].
        long long ans = original_max;
        for (int i = 0; i < n; ++i) {
            // Calculate max subarray sum passing through i with the modification
            // L[i] + R[i] - a[i] is the max subarray passing through i in original array.
            // We add b[i] to that sum.
            long long modified_pass_through = L[i] + R[i] - a[i] + b[i];
            ans = max(ans, modified_pass_through);
        }
        cout << ans << "\n";
    }
}

int main() {
    // Optimize I/O operations
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