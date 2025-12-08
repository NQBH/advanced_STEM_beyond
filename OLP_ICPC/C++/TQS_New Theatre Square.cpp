#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<ll> r(n, 0);
        ll ans = 0;
        y = min(y, 2 * x);
        for (ll i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            ll j = 0;
            while (j < m)
            {
                if (s[j] == '*')
                {
                    j++;
                    continue;
                }
                ll k = j;
                while (k + 1 < m and s[k + 1] == '.')
                {
                    k++;
                }
                ll len = k - j + 1;
                ans += len % 2 * x + len / 2 * y;
                j = k + 1;
            }
        }
        cout << ans << "\n";

    }
}
