#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;
int qpow(int base, int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    int temp = qpow(base, exp / 2);
    temp %= MOD;
    if (exp % 2 == 0) return temp * temp % MOD;
    return temp * temp % MOD * base % MOD;
} 

signed main() {
    vector<int> f(MAXN + 5, 1), dp(MAXN);
    vector<int> inv_f(3, 0);
    for (int i = 1; i <= MAXN; i++) {
        // (2n)! / 2
        f[i] = f[i - 1] * i % MOD;
    }
    inv_f[2] = qpow(f[2], MOD - 2);
    for (int i = 1; i <= MAXN; i++) {
        dp[i] = f[i] * inv_f[2] % MOD;
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = dp[2 * n];
        cout << ans << endl;
    }
}
