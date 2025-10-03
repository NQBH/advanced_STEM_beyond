// #include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
	// Input
	int N;
	cin >> N;
	vector<int> h(N + 1);
	for (int i = 1; i <= N; ++i) cin >> h[i];

	// DP
	vector<int> dp(N + 1, INT_MAX); // dp[i] =  the minimum possible total cost to the ith stone
	dp[1] = 0, dp[2] = abs(h[2] - h[1]); // base case
	for (int i = 3; i <= N; ++i) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	}
	cout << dp[N];
}