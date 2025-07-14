#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main() {
	int m, n, k, x, y;
	cin >> m >> n >> k;
	// bool a[m][n] = {true};
	int dp[m + 1][n + 1] = {0};
	dp[0][0] = 1;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j];
		cout << "\n";
	}
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		dp[x - 1][y - 1] = -1; // forbidden
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j];
		cout << "\n";
	}


	for (int i = 0; i < m; ++i) {
		if (i != 0 && dp[i][0] != -1) dp[i][0] = ++dp[i - 1][0];
		for (int j = 0; j < n; ++j) {
			if (j != 0 && dp[0][j] != -1) dp[0][j] = ++dp[0][j - 1];
			if (dp[i][j] != -1)
				dp[i][j] = (dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]) + (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1]);
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << dp[i][j];
		cout << "\n";
	}
	cout << dp[m][n];
}