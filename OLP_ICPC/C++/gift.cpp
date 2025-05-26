#include <bits/stdc++.h>
using namespace std;
#define N 10000
#define inf int(1e9)
int a[N + 2], dp[N + 2];
int n, k;
int main() {
	int t;
	cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        	cin >> a[i];
    	a[0] = -inf; // a[0] = -10^9
    	a[n + 1] = inf; // a[n + 1] = 10^9
    	dp[0] = 1;
    	for (int i = 1; i <= n + 1; ++i)
    		for (int j = 0; j < i; ++j)
    			if (a[j] + k <= a[i])
    				dp[i] = max(dp[i], dp[j] + 1);

    	cout << dp[n + 1] - 2;
    }
}