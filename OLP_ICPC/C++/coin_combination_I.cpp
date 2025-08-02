#include <iostream>
#include <vector>
using namespace std;

int main() {
	int mod = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	vector<int> c(n), dp(x + 1, 0);
	for (int& v : c) cin >> v;
	dp[0] = 1;
	for (int i = 1; i <= x; ++i)
		for (int j = 0; j < n; ++j)
			if (c[j] <= i) (dp[i] += dp[i - c[j]]) %= mod;
	cout << dp[x];
}