#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        set<ll> a;
        ll k;
        for (ll i = 0; i < n; ++i)
        {
            cin >> k;
            a.insert(k);
        }
        n = a.size();
        vector<ll> dp(n, 1);
        ll idx = 0;
        for (auto i = a.begin(); i != a.end(); ++i, ++idx)
        {
            auto j = i;
            int jdx = idx;
            while (j != a.begin())
            {
                --j;
                --jdx;
                if (*i - *j > 1)
                {
                    dp[idx] = max(dp[idx], dp[jdx] + 1);
                    break;
                }
            }
        }
        ll ans = *max_element(dp.begin(), dp.end());
        cout << ans << "\n";
    }
}
