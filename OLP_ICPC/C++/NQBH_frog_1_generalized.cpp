#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; // frog can jump s[0], s[1],.., or s[m - 1] stones
	vector<int> height(n), step(m);
	for (int i = 0; i < n; ++i) cin >> height[i];
	for (int i = 0; i < m; ++i) cin >> step[i];
	// dp[i] is the minimum cost to get to the i-th stone
	vector<int> dp(n, INT_MAX);
	dp[0] = 0; // base case since we are already at the 1st stone
	for (int i = 1; i < n; ++i) // for each state, calculate the states it leads to
		for (int j = 0; j < m; ++j) // jump s[j] stone
			if (i >= step[j]) dp[i] = min(dp[i], dp[i - step[j]] + abs(height[i] - height[i - step[j]]));
	cout << dp[n - 1];
}