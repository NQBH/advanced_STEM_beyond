#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int>a(n + 1);
        vector<int> cnt(2e5 + 5, 0), freq(2e5 + 5, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        /*
        có k multiset -> mỗi multiset final có freq[a[i]] / k số
        */
       int l = 1;
       bool check = true;

        for (int i = 1; i <= n; i++) {
            if (freq[a[i]] % k != 0) {
                check = false;
                break;
            }
        }
        if (check == false) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for (int r = 1; r <= n; r++) {
            cnt[a[r]]++;
            while(cnt[a[r]] > freq[a[r]] / k) {
                --cnt[a[l++]];
            }
            //cout << "(" << l << ", "<<r<<") ";
            ans += r - l + 1;
        }
        cout << ans << endl;    
    }
}