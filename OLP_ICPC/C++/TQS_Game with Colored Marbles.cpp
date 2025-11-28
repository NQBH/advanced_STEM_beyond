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
        map<int, int> a;
        for (ll i = 0; i < n; ++i)
        {
            ll s;
            cin >> s;
            a[s]++;
        }
        ll d = 0;
        ll k = 0;
        for (auto i : a)
        {
            if (i.second == 1) d++;
            else k++;
        }
        if (d != 0)
        {
            if (d % 2 != 0) d = d / 2 + 1;
            else d = d / 2;
        }

        ll ans = d * 2 + k;
        cout << ans << "\n";
    }
}
