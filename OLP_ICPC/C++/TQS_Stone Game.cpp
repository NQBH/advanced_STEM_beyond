#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll b = max_element(a.begin(), a.end()) - a.begin();
        ll c = min_element(a.begin(), a.end()) - a.begin();
        ll ans = min({ max(c, b) + 1 , n - 1 - b + c + 2 , (n - 1) - min(b, c) + 1 , n - 1 - c + b + 2});
        cout << ans << "\n";
    }
}
