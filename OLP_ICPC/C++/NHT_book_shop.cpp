#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, x;
int h[1000001], s[1000001];
ll dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];
    
    for(int i = 0; i < n; ++i)
        for(int j = x; j > 0; --j)
            {
                if(h[i] > j) continue;
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
            }
    cout << dp[x] << endl;

    return 0;
}