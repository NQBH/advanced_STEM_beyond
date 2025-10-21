#include <bits/stdc++.h>
#define int long long
const int oo = 1e18 + 7;
using namespace std;

struct item {
    int w, v;
};

signed main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w, h; cin >> n >> w >> h;
    vector<item> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].v;
    }
    int MAXV = 100000;
    vector<vector<int>> dp(MAXV + 1, vector<int>(2, oo));
    vector<vector<int>> newdp(MAXV + 1, vector<int>(2, oo));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXV; j++) newdp[j][0] = newdp[j][1] = oo;
        for (int j = 0; j <= MAXV; j++) {
            newdp[j][0] = min(newdp[j][0], dp[j][0]);
            newdp[j][1] = min(newdp[j][1], dp[j][1]);

            if (j - a[i].v >= 0) {
                newdp[j][0] = min(newdp[j][0], dp[j - a[i].v][0] + a[i].w);
                if (a[i].w <= h) newdp[j][1] = min(newdp[j][1], dp[j - a[i].v][0]);
                newdp[j][1] = min(newdp[j][1], dp[j - a[i].v][1] + a[i].w);
            }
        }
        swap(dp, newdp);
    }

    int ans = 0;
    for (int j = 0; j <= MAXV; j++) {
        int minw = min(dp[j][0], dp[j][1]);
        if (minw <= w)
            ans = j;
    }
    cout << ans;
}