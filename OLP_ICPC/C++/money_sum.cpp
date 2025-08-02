#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int max_sum = 1000 * n;
	vector<int> x(n);
	for (int& v : x) cin >> v;
	vector<vector<bool>> dp(n + 1, vector<bool>(max_sum + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= max_sum; ++j) {
			dp[i][j] = dp[i - 1][j];
			int left = j - x[i - 1];
			if (left >= 0 && dp[i - 1][left]) dp[i][j] = true;
		}
	vector<int> possible;
	for (int i = 1; i <= max_sum; ++i)
		if (dp[n][i]) possible.push_back(i);
	cout << possible.size() << '\n';
	for (int v : possible) cout << v << ' ';
}