#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n, ll x, ll t)
{
    if (t < x) cout << 0 << '\n';
    else if (t == x) cout << n - 1 << "\n";
    else
    {
        ll k = max((long long) 0, n - (t / x));
        cout << k*(t / x) + (n - k - 1)*(n - k) / 2 << "\n";
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        solve(n, x, t);
    }
}
