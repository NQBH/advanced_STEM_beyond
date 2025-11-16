#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll modpow(ll b, ll e, ll mod = MOD) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        vector<int> cnt(n + 1, 0);
        for (int x : a) ++cnt[x];
        
        int maxf = 0;
        for (int i = 1; i <= n; ++i)
            maxf = max(maxf, cnt[i]);
        
        vector<vector<int>> freq(maxf + 1);
        for (int v = 1; v <= n; ++v)
            if (cnt[v]) freq[cnt[v]].push_back(v);
        
        int m = freq[maxf].size(); // number of special values
        
        const int MAXG = m + 10;
        vector<ll> dp(MAXG, 0), next_dp(MAXG);
        dp[0] = 1;
        int max_groups = 0;
        
        // Process in increasing order of frequency
        for (int f = 1; f <= maxf; ++f) {
            bool is_special = (f == maxf);
            int values_in_freq = freq[f].size();
            
            for (int v_idx = 0; v_idx < values_in_freq; ++v_idx) {
                int v = freq[f][v_idx];
                int c = cnt[v]; // = f
                next_dp.assign(MAXG, 0);
                
                for (int j = 0; j <= max_groups; ++j) {
                    if (!dp[j]) continue;
                    
                    if (is_special) {
                        // Option 1: add to existing group
                        if (j >= 1) {
                            next_dp[j] = (next_dp[j] + dp[j] * j) % MOD;
                        }
                        // Option 2: create new group
                        if (j + 1 < MAXG) {
                            next_dp[j + 1] = (next_dp[j + 1] + dp[j]) % MOD;
                        }
                    } else {
                        // Must distribute all c copies into existing j groups
                        if (j >= 1) {
                            ll ways = modpow(j, c);
                            next_dp[j] = (next_dp[j] + dp[j] * ways) % MOD;
                        }
                        // else: impossible, dp[j] remains 0
                    }
                }
                dp = next_dp;
            }
            if (is_special) {
                max_groups += values_in_freq;
            }
        }
        
        // Precompute binomial coefficients C(n + k - 1, k - 1)
        int max_binom = max_groups + m + 5;
        vector<ll> fact(max_binom, 1), invfact(max_binom);
        for (int i = 1; i < max_binom; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        if (max_binom > 0) {
            invfact[max_binom - 1] = modpow(fact[max_binom - 1], MOD - 2);
            for (int i = max_binom - 2; i >= 0; --i)
                invfact[i] = invfact[i + 1] * (i + 1) % MOD;
        }
        
        auto binom = [&](int n, int k) -> ll {
            if (k < 0 || k > n) return 0;
            return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
        };
        
        ll answer = 0;
        for (int j = 0; j < MAXG; ++j) {
            if (!dp[j]) continue;
            ll multis = (m == 0) ? 1LL : binom(j + m - 1, m - 1);
            answer = (answer + dp[j] * multis) % MOD;
        }
        cout << answer << '\n';
    }
    return 0;
}