#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int addmod(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        // Count frequencies
        vector<int> cnt(n+1,0);
        for(int x : a) cnt[x]++;

        vector<int> f;
        for(int i=1;i<=n;i++){
            if(cnt[i]>0) f.push_back(cnt[i]);
        }

        sort(f.rbegin(), f.rend());
        int m = f.size();

        // dp[i][j]: considering values 1..i (sorted by freq desc),
        // s_i = j (0..f[i]), and s_1 >= s_2 >= ... >= s_i.
        // We only store two rows to save memory.
        vector<int> prev_dp(n+1, 0), cur_dp(n+1, 0);

        // Initialize dp for i = 1
        for(int j=0; j<=f[0]; j++)
            prev_dp[j] = 1;

        // Iterate values
        for(int i=2; i<=m; i++){
            int fi = f[i-1];
            // prefix sums of prev_dp
            vector<int> pref(n+1, 0);
            pref[0] = prev_dp[0];
            for(int k=1; k<=n; k++) pref[k] = addmod(pref[k-1], prev_dp[k]);

            for(int j=0; j<=fi; j++){
                // s_i = j; so s_{i-1} ≥ j
                cur_dp[j] = pref[n] - (j>0 ? pref[j-1] : 0);
                if(cur_dp[j] < 0) cur_dp[j] += MOD;
            }

            // swap
            prev_dp = cur_dp;
            fill(cur_dp.begin(), cur_dp.end(), 0);
        }

        // sum all dp[m][s_m], but exclude the all-zero case
        int ans = 0;
        for(int j=0; j<=f[m-1]; j++){
            ans = addmod(ans, prev_dp[j]);
        }

        // subtract empty multiset (all s_i = 0)
        ans = (ans - 1 + MOD) % MOD;

        cout << ans << "\n";
    }
    return 0;
}
