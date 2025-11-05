#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		vector<int> dp(n, 0); // dp[i] = max possible score when considering up to a[i] & color a[i] red
		dp[0] = a[0];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j <= i - 2; ++j) {
				dp[i] = max(dp[i], dp[j] )
			}
		}
	}
}