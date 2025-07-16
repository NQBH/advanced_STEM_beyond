#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	int m, n, k, x, y;
	cin >> m >> n >> k;
	vector<vector<int>> dp(m, vector<int> (n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		dp[x - 1][y - 1] = -1; // forbidden: cannot go there
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j] << " ";
		cout << "\n";
	}

	// dynamic programming sol
	for (int i = 1; i < m; ++i)
		if (dp[i - 1][0] != -1) dp[i][0] = 1;
		else dp[i][0] = 0;
	for (int j = 1; j < n; ++j)
		if (dp[0][j - 1] != -1) dp[0][j] = 1;
		else dp[0][j] = 0;

	for (int i = 1; i < m; ++i) {		
		for (int j = 1; j < n; ++j) {
			if (dp[i][j] != -1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else dp[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	cout << dp[m - 1][n - 1] % mod;
}