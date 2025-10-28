#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;           // safe upper bound

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n+1), c(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> c[i];
        
        if (n == 1) {                     // trivial case
            cout << "0\n";
            continue;
        }
        
        vector<ll> dp0(n+1, INF), dp1(n+1, INF);   // dp[i][0/1]
        vector<ll> lastVal0(n+1), lastVal1(n+1);   // final value of i
        
        // position 1
        dp0[1] = 0;           lastVal0[1] = a[1];
        dp1[1] = c[1];        lastVal1[1] = a[1];   // value does not matter
        
        for (int i = 2; i <= n; ++i) {
            // ----- keep i (value = a[i]) -----
            ll needPrev = a[i];
            ll bestPrev = INF;
            // can we use the best previous decision?
            if (dp0[i-1] <= dp1[i-1]) {               // previous kept is cheaper
                if (lastVal0[i-1] <= needPrev) bestPrev = dp0[i-1];
            } else {
                if (lastVal1[i-1] <= needPrev) bestPrev = dp1[i-1];
            }
            if (bestPrev == INF) bestPrev = dp1[i-1]; // force previous change
            dp0[i] = bestPrev;
            lastVal0[i] = a[i];
            
            // ----- change i (pay c[i]) -----
            ll needPrev2 = -INF;        // any previous value is acceptable
            ll bestPrev2 = INF;
            if (dp0[i-1] <= dp1[i-1]) {
                bestPrev2 = dp0[i-1];
            } else {
                bestPrev2 = dp1[i-1];
            }
            // if previous kept value > future we must change previous
            if (lastVal0[i-1] > a[i]) bestPrev2 = dp1[i-1];
            dp1[i] = c[i] + bestPrev2;
            lastVal1[i] = a[i];         // arbitrary, only for consistency
        }
        
        ll ans = min(dp0[n], dp1[n]);
        cout << ans << '\n';
    }
    return 0;
}
// WA CF