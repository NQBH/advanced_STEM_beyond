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
        ll f = 1;
        ll g = 1;
        for (ll i = 0; i < k; ++i)
        {
            for (ll i = k - g; i < n; i += k)
            {
                a[i] = f;
                f++;
            }
            g++;
        }
        for (ll i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}
