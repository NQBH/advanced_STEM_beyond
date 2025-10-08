#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, W;
	cin >> n >> W;
	vector<int> w(n), v(n);
	for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];
	vector<int> dp(W, 0);
	for (int i = 0; i < n; ++i)
		for (int j = W; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	cout << dp[W] << '\n';
}