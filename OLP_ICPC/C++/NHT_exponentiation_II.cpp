#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int n, a, b, c;

ll Power(ll a, ll b, int MOD)
{
    ll ans(1);
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << Power(a, Power(b, c, MOD - 1), MOD) << '\n';
    }
    return 0;
}