#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        ll ans = 0;
        ll n = a.size();
        for (ll i = 0; i<n; i++)
        {
            if (a[i]=='0')
            {
                ans++;
                while (a[i]=='0')
                {
                    i++;
                }
            }
        }
        if (ans > 2) ans = 2;
        cout << ans << "\n";
    }
}
