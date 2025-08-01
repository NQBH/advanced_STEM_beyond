#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, mod = 1e9 + 7;
	cin >> n >> m;
	vector<int> dp(n + 1, 0), a(m);
	for (int i = 0; i < m; ++i) cin >> a[i];
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m && a[j] <= i; ++j) (dp[i] += dp[i - a[j]]) %= mod;
	cout << dp[n];
}