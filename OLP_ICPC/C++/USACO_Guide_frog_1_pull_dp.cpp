#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> height(n);
	for (int i = 0; i < n; ++i) cin >> height[i];
	// dp[i] is the minimum cost to get to the i-th stone
	vector<int> dp(n, INT_MAX);
	dp[0] = 0; // base case since we are already at the 1st stone
	for (int i = 1; i < n; ++i) { // for each state, calculate the states it leads to
		if (i >= 1) dp[i] = min(dp[i], dp[i - 1] + abs(height[i] - height[i - 1])); // jump 1 stone
		if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + abs(height[i] - height[i - 2])); // jump 2 stones
	}
	cout << dp[n - 1];
}