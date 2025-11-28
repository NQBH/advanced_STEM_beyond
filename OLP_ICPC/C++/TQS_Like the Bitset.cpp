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
        ll cnt = n;
        bool ans = true;
        string s;
        cin >> s;
        for (ll i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                ll j = i;
                while (j < n - 1 and s[j + 1] == '1') j++;
                if (j - i + 1 >= k)
                {
                    ans = false;
                    break;
                }
                i = j;
            }
        }
        if (!ans) cout << "NO" << "\n";
        else
        {
            cout << "YES" << "\n";
            ll cnt = 1;
            vector<ll> a(n);
            for (ll i = 0; i < n; ++i)
            {
                if (s[i] == '1')
                {
                    a[i] = cnt;
                    cnt++;
                }
            }
            for (ll i = 0; i < n; ++i)
            {
                if (s[i] == '0')
                {
                    a[i] = cnt;
                    cnt++;
                }
            }
            for (ll i = 0; i < n; i++) cout << a[i] << " ";
            cout << "\n";
        }
    }
}
