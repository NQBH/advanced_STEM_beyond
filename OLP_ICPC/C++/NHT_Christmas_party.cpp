#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
int n;
ll dp[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	dp[2] = 1;
	for (int i = 3; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod * (i - 1) % mod;
	cout << dp[n] << '\n';
	return 0;
}