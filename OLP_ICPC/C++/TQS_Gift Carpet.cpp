#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string a[n], b = "vika";
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll c = 0;
        for (ll i = 0; i < m; ++i)
        {
            bool check = false;
            for (ll j = 0; j < n; ++j)
            {
                if (a[j][i] == b[c])
                {
                    check = true;
                    break;
                }
            }
            if (check)
            {
                c++;
                if (c == 4) break;
            }
        }
        if (c == 4)
        {
            cout << "YES" << "\n";
        }
        else cout << "NO" << "\n";
    }
}
