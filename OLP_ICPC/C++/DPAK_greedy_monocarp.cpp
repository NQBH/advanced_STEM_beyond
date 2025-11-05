#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1); 
        int total = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total += a[i];
        }
        int diff = total - k;
        int ans = 0;
        if (diff == 0) {
//            ans = 0;
        }
        else if (diff > 0) {
            int cur = 0;
            sort(a.begin() + 1, a.end(), greater<int>());
//            int i;
            ans = 1e9 + 7;
            for (int i = 1; i <= n; i++) {
                if (cur + a[i] > k) break;
                cur += a[i];
                ans = min(ans, k - cur);
            }
        }
        else {
            ans = k - total;
        }
        cout << ans << endl;
    
    }
    return 0;
}