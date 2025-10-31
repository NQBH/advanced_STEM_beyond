#include "bits/stdc++.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int64_t a[n], c[n], dp[n];
		for (int64_t &i : a) cin >> i;
        for (int64_t &i : c) cin >> i;
        for (int i = 0; i < n; ++i) dp[i] = c[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
            	if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + c[i]);
           cout << accumulate(c, c + n, 0LL) - *max_element(dp, dp + n) << '\n';
	}
}