#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 53;

int n, k;
ll dp[maxN]; // dp[i] là số cách ghép mảnh ghép thành bức tranh.

ll POW(int base, int cnt)
{
    if(cnt == 0) return 1;
    if(cnt == 1) return base;
    long long tmp = POW(base, cnt / 2);
    if(cnt % 2) return tmp * tmp * base;
    return tmp * tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0; i <= n; ++i) dp[i] = 0;
        dp[0] = 1;

        for(int i  = 1; i <= n; ++i)
        {
            if(i <= k) dp[i] = POW(2, i -1);
            else for(int j = 1; j <= k; ++j) dp[i] += dp[i - j];
        }
        cout << dp[n] << endl;
    }
    return 0;
}
