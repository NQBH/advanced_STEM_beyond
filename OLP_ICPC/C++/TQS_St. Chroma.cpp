#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        if (x >= n)
        {
            for (ll i = 0; i < n; i++)
            {
                cout << i << " ";
            }
            cout <<  "\n";
        }
        else
        {
            for (ll i = 0; i < x; i++)
            {
                cout << i << " ";
            }
            for (ll i = x + 1; i < n; i++)
            {
                cout << i << " ";
            }
            cout << x << "\n";
        }
    }
}
