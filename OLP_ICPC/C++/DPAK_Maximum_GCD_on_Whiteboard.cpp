#include <bits/stdc++.h>
#define int long long
using namespace std;
int MAXN = 2e5;
signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        MAXN = *max_element(a.begin() + 1, a.end()) * 4;
        vector<int> cnt(MAXN + 1, 0);
        
        for (int i = 1; i <= n; i++) cnt[a[i]]++;
        
        vector<int>f(MAXN + 1, 0);
        for (int i = 1; i <= MAXN; i++) {
            f[i] = f[i - 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 1; i <= MAXN / 4; i++) {
            int g = i;
            int count = cnt[g] + cnt[2 * g] + cnt[3 * g] + (f[MAXN] - f[4 * g - 1]);
            if (count >= n - k) {
                ans = g;
            }
        }
        cout << ans << endl;
    }
}
