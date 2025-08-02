#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> c(n), dp(x + 1, 1e9);
	for (int& v : c) cin >> v;
	dp[0]= 0;
	for (int i = 1; i <= x; ++i)
		for (int j = 0; j < n; ++j)
			if (i >= c[j]) dp[i] = min(dp[i], dp[i - c[j]] + 1);
	cout << (dp[x] == 1e9 ? -1 : dp[x]);
}