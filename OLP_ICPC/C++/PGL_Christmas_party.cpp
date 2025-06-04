#include <iostream>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;
ll fac[1000001];
ll pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll inv(ll x) {
    return pow(x, mod - 2);
}
ll ncr(ll a, ll b) {
    return fac[a] * inv(fac[b] * fac[a - b] % mod) % mod;
}
int main() {
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ll n; cin >> n;
    ll add;
    ll count = 0;
    for (int i = 1; i <= n; i++) {
        add = ncr(n, i) * fac[n - i] % mod;
        if (i % 2 == 0) add = -add;
        count += add;
    }
    ll ans = ((fac[n] - count) % mod + mod) % mod;
    cout << ans << "\n";
}