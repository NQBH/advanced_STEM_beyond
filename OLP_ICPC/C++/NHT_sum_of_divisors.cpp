#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;

ll inverse(ll i) {
    if (i == 1) return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

ll POW(ll a, ll b)
{
    ll ans = 1;
    for ( ; b ; b >>= 1) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        ans += ((n / i) * i) % MOD;
        ans %= MOD;
    }

    ll l = sqrt(n);
    for (ll i = sqrt(n); i >= 1; i--)
    {
        ll r = n / i;
        ll sum = 0;
        sum += ((((r % MOD) * ((r + 1) % MOD)) % MOD) * inverse(2)) % MOD;
        sum %= MOD;
        sum -= ((((l % MOD) * ((l + 1) % MOD)) % MOD) * inverse(2)) % MOD;
        sum = (sum + MOD) % MOD;
        sum = (sum * i) % MOD;
        l = r;
        ans = (ans + sum) % MOD;
    }
    cout << ans;
    return 0;
}