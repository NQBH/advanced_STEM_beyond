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
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        if (k != 4)
        {
            ll ans = k;
            for (ll i = 0; i < n; ++i)
            {
                if (a[i] % k == 0)
                {
                    ans = 0;
                    break;
                }
                ans = min(ans, k - a[i] % k);
            }
            cout << ans << "\n";
        }
        else
        {
            ll cnt = 0;
            if (n == 1)
            {
                ll ans = min(ans, k - a[0] % k);
                cout << ans << "\n";
            }
            else
            {
                ll ans = 2;
                for (ll i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 0) cnt++;
                    if (a[i] % k == 0)
                    {
                        ans = 0;
                        break;
                    }
                    ans = min(ans, k - a[i] % k);
                }
                if (cnt >= 2) ans = 0;
                else ans = min(ans, 2 - cnt);
                cout << ans << "\n";
            }
        }
    }
}
