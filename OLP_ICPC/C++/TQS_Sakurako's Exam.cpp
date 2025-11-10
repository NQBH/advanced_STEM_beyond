#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a % 2 != 0)
            cout << "NO" << "\n";
        else {
            if (b % 2 == 0) cout << "YES" << "\n";
            else {
                if (a >= 2) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
        }
    }
}
