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
        ll ans = 0;
        if (n == 1)
        {
            cout << "NO" << "\n";
            continue;
        }
        if (n >= k)
        {
            ans += (n - (n - k + 1) + 1) * (n - k + 1 + n) / 2;
        }
        else
        {
            for (ll i = 1; i <= n; ++i)
            {
                ans += n * (1 + n) / 2;
            }
        }
        if (ans & 1) cout << "NO" << "\n";
        else cout << "YES" << "\n";

    }
}
