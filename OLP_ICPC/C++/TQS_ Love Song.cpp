#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, q;
    cin >> n >> q;
    char a[n + 1];
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    ll b[n + 1] = {0};
    for (ll i = 1; i <= n; i++)
    {
        b[i] += b[i - 1] + (ll)a[i] - 96;
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = b[r] - b[l - 1] ;
        cout << ans << "\n";
    }
}
