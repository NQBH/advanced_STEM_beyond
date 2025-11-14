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
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        ll dp[n] = {0};
        for (ll i = 0 ; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                dp[i + 1] = dp[i] + 1;
                i++;
            }
            dp[i + 1] = dp[i];
        }
        cout << dp[n - 1] << "\n";
    }
}
