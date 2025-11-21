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
        string s;
        cin >> s;
        ll ans = 0;
        set<ll> a;
        for (ll i = 0; i < n; ++i) {
            a.insert(s[i]);
            ans += a.size();
        }
        cout << ans << "\n";
    }
}
