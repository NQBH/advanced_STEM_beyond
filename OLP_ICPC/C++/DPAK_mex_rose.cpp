#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >>  n >> k;
        vector<int>a(n + 1);
        vector<int> num(n + 1, 0);
        for (int i =1 ; i <= n; i++) {
            cin >> a[i];
            num[a[i]]++;
        }
        int ans = 0;
        int miss = 0;
        for (int i = 0; i < k; i++) {
            if (num[i] == 0) miss++; 
        } 
        ans += max(miss, num[k]);
        cout << ans << endl;
            
    }
}
