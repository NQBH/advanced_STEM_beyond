#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n+1);
        long long S = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            S += a[i];
        }
        
        // ---- build b[i] = a[i] - 2 * i ----
        long long min_sub = 0;      // minimum subarray sum of b
        long long cur = 0;
        for (int i = 1; i <= n; ++i) {
            long long bi = a[i] - (2LL * i);
            cur += bi;
            min_sub = min(min_sub, cur);
            if (cur > 0) cur = 0;
        }
        
        long long best = S - min_sub;   // S + (-min_sub)
        cout << max(S, best) << '\n';
    }
    return 0;
}