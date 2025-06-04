#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>dp(n + 1);
	dp[0] = 1; dp[1] = 0; dp[2] = 1;
	for (int i = 3; i <= n; i++) dp[i] = ((i - 1LL) * (dp[i - 1] + dp[i - 2])) % MOD;
	cout << dp[n];
}