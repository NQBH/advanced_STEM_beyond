#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool check = true;
        for (ll i = 0; i < n; i++)
        {
            if (a[i] == b[i] and b[i] == '1') {
                check = false;
                break;
            }
        }
        if (check) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
