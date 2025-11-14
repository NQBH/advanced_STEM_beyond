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
        char a[n + 1];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        ll dp[n + 1] = {0};

        for (ll i = 2; i <= n; ++i)
        {
            if (a[i] == '@') dp[i] = max(dp[i - 1] + 1, dp[i - 2] + 1);
            else {
                if (a[i] == '*' and a[i - 1] == '*') {
                    dp[n] = dp[i - 2];
                    break;
                }
                dp[i] = max(dp[i - 1], dp[i - 2]);
            }
        }
        cout << dp[n] << "\n";

    }

}
