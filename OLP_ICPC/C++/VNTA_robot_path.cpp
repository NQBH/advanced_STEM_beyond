#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9 + 7;
const int MAX = 200005;

ll fact[MAX], inv_fact[MAX];

//(a^b) % MOD
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b = b / 2;
    }
    return res;
}

void preprocess() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = power(fact[i], MOD - 2); // Fermat inverse
    }
}

ll nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

ll ways(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    if (dx < 0 || dy < 0) return 0;
    return nCk(dx + dy, dx);
}

int main() {
    preprocess();

    int m, n, k;
    cin >> m >> n >> k;

    vector<pair<int, int>>p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    p.push_back({m, n});
    sort(p.begin(), p.end());

    int sz = k + 1;
    vector<ll>dp(sz);
    //dp[i]: so cach tu (1,1) den p[i] ma khong di qua o cam truoc do

    for (int i = 0; i < sz; ++i) {
        int xi = p[i].first, yi = p[i].second;
        dp[i] = ways(1, 1, xi, yi); // tat ca duong tu (1,1) den p[i]

        for (int j = 0; j < i; ++j) {
            int xj = p[j].first, yj = p[j].second;
            ll sub = dp[j] * ways(xj, yj, xi, yi) % MOD;
            dp[i] = (dp[i] - sub + MOD) % MOD;
        }
    }

    cout << dp[sz - 1];
    return 0;
}