#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> a(3);
        cin >> a[0] >> a[1] >> a[2];
        sort(a.begin(), a.end(), greater<ll>());
        if (a[0] == a[1] + a[2])
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            if (a[0] == a[1])
            {
                if (a[2] % 2 == 0)
                {
                    cout << "YES\n";
                    continue;
                }
            }
            else if (a[1] == a[2])
            {
                if (a[0] % 2 == 0)
                {
                    cout << "YES\n";
                    continue;
                }
            }
        }
        cout << "NO\n";
    }
}
