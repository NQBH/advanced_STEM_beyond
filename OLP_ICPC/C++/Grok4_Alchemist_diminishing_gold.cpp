#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll mod_pow(ll b, ll e, ll m) {
    ll res = 1;
    b %= m;
    while (e > 0) {
        if (e & 1) res = res * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return res;
}

map<ll, int> get_factors(ll n) {
    map<ll, int> f;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            cnt++;
            n /= 2;
        }
        f[2] = cnt;
    }
    for (ll d = 3; d * d <= n; d += 2) {
        if (n % d == 0) {
            int cnt = 0;
            while (n % d == 0) {
                cnt++;
                n /= d;
            }
            f[d] = cnt;
        }
    }
    if (n > 1) f[n] = 1;
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    auto factors = get_factors(n);
    ll ans = 1;
    for (auto& pr : factors) {
        ll pp = pr.first;
        int aa = pr.second;
        vector<vector<ll>> dp(aa + 1, vector<ll>(k + 1, 0));
        for (int e = 0; e <= aa; e++) {
            dp[e][0] = mod_pow(pp, e, MOD);
        }
        for (int t = 1; t <= k; t++) {
            vector<ll> prefix(aa + 2, 0);
            for (int e = 0; e <= aa; e++) {
                prefix[e + 1] = (prefix[e] + dp[e][t - 1]) % MOD;
            }
            for (int e = 0; e <= aa; e++) {
                ll sumv = prefix[e + 1];
                ll den = e + 1;
                ll invd = mod_pow(den, MOD - 2, MOD);
                dp[e][t] = sumv * invd % MOD;
            }
        }
        ll contrib = dp[aa][k];
        ans = ans * contrib % MOD;
    }
    cout << ans << '\n';
    return 0;
}