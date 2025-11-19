#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, v;
	cin >> n >> v;
	if (v >= n - 1) cout << n - 1;
	else {
		vector<vector<int>> dp(n, vector<int>(v + 1, INT_MAX));
		for (int i = 0; i <= v; ++i) dp[1][i] = i;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= v; ++j)
				if (i - j > 0) dp[i] = min(dp[i], dp[i - j] + j * (i - j));
		}
		cout << dp[n];
	}
}