#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, mod = 1e9 + 7;
	cin >> n >> m;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m && j <= i; ++j) (dp[i] += dp[i - j]) %= mod;
	cout << dp[n];
}