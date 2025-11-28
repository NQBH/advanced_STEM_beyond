#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(n));
        ll m = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        vector<ll> b;
        for (ll i = 0; i < n; ++i)
        {
            b.push_back(a[0][i]);
            m += a[0][i];
        }
        for (ll i = 1; i < n; ++i)
        {
            b.push_back(a[i][n - 1]);
            m += a[i][n - 1];
        }
        cout << (n * 2)*(1 + n * 2) / 2 - m << " ";
        for (ll i : b) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
