#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; // frog can jump 1, 2,.., or m stones
	vector<int> height(n);
	for (int i = 0; i < n; ++i) cin >> height[i];
	// dp[i] is the minimum cost to get to the i-th stone
	vector<int> dp(n, INT_MAX);
	dp[0] = 0; // base case since we are already at the 1st stone
	for (int i = 1; i < n; ++i) // for each state, calculate the states it leads to
		for (int j = 1; j <= m; ++j)
			if (i >= j) dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j])); // jump j stone
	cout << dp[n - 1];
}