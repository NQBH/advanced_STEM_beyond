#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int nmax = 1e5;
const int inf = 2e9;
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        ll a[nmax + 5], dp[nmax + 5]; //dp[i] = tổng năng lượng ít nhất khi nhảy từ ô 1 đến ô i
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];

        dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = inf;
            for (int j = max(1, i - k); j < i; ++j)
                dp[i] = min(dp[i], dp[j] + abs(a[j] - a[i]));
        }
        cout << dp[n] << endl;
    }

    return 0;
}