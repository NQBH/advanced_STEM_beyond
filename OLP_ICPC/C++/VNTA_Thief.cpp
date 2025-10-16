#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long solve(int N, ll W, int H, const vector<ll>&w, const vector<ll>&c) {
    vector<pair<ll, ll>> dp;
    // dp[k]: (w,v) -> co the dat tong weight=w va tong value=v
    // khong ton tai (w1,v1),(w2,v2) trong dp sao cho w1<=w2 va v1>=v2
    dp.push_back({0, 0});
    for (int i = 0; i < N; ++i) {
        if (i == H) continue; // cam tay
        vector<pair<ll, ll>> u = dp; // u: thu them mon i vao cac trang thai trong dp
        for (auto [cW, cV] : dp) {
            ll nW = cW + w[i];
            if (nW <= W) u.push_back({nW, cV + c[i]});
        }
        sort(u.begin(), u.end());
        vector<pair<ll, ll>> ndp;
        ll best = -1;
        for (auto [x, y] : u) {
            if (y > best) {
                ndp.push_back({x, y});
                best = y;
            }
        }
        dp.swap(ndp);
    }
    ll res = 0;
    for (auto [tW, tV] : dp) res = max(res, tV);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; ll W, H;
    cin >> N >> W >> H;
    vector<ll> w(N), c(N);
    for (int i = 0; i < N; ++i) cin >> w[i] >> c[i];

    ll res = solve(N, W, -1, w, c);
    for (int i = 0; i < N; ++i) {
        if (w[i] <= H) {
            ll temp = solve(N, W, i, w, c) + c[i];
            res = max(res, temp);
        }
    }
    cout << res;
    return 0;
}
