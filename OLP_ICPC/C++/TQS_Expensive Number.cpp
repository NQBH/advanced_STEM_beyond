#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        if (n == 1) cout << 0 << "\n";
        else
        {
            ll nt;
            ll kq = 0;
            for (ll i = n - 1; i >= 0 ; i--)
            {
                if (s[i] != '0')
                {
                    nt = i;
                    break;
                }
            }
            kq += n - nt;
            for (ll i = 0; i < nt; ++i)
            {
                if (s[i] != '0')
                {
                    kq++;
                }
            }
            cout << kq - 1 << "\n";
        }
    }
}
