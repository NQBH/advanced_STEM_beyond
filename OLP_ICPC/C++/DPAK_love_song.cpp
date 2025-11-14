#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t = 1; //cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s; s = " " + s;

        vector<vector<int>> freq(n + 1, vector<int>(26, 0));

//       cout << "HI";
        freq[1][s[1] - 'a']++;
        for (int i = 2; i <= n; i++) {
            freq[i] = freq[i - 1];
            freq[i][s[i] - 'a']++;
        }
//       cout << "HI";

        while (q--) {
            int l, r; cin >> l >> r;
            vector<int> cur = freq[r];
            for (int i = 0; i < 26; i++) cur[i] -= freq[l - 1][i];
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                ans += cur[i] * (i + 1);
            }
            cout << ans << endl;
        }
    }
    return 0;
}