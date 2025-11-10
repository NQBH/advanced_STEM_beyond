#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> g(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> g[i];
        }
        ll gold = 0;
        ll ans = 0;
        for (ll i = 0; i < n; ++i)
        {
            if (g[i] >= k)
            {
                gold += g[i];
            }
            else if (g[i] == 0)
            {
                if (gold >= 1)
                {
                    ans++;
                    gold--;
                }
            }
        }
        cout << ans << "\n";
    }
}
