#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    if (a[0] == 0)
    {
        cout << "NO";
        return 0;
    }
    if (a[s - 1] == 0)
    {
        if (b[s - 1] == 0) {
            cout << "NO";
            return 0;
        }
        for (ll i = s; i < n; ++i)
        {
            if (a[i] == 1 and b[i] == 1) {
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    else cout << "YES";
}
