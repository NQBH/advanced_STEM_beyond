#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        
        int n; cin >> n;
        vector<int> a(n + 1), f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = f[i - 1] ^ a[i];
        }
        string s;        
        cin >> s;
        s = " " + s;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') ans ^= a[i];
        }

        int q; cin >> q;
        while (q--) {
            int type; cin >> type;
            if (type == 1) { // flip
                int l, r; cin >> l >> r;
                ans ^= f[r] ^ f[l - 1];
            }
            else {
                int g; cin >> g;
                cout << (g == 0 ? ans : ans ^ f[n]) << " ";
            }
        }
        cout << endl;
    }
}