#include <iostream>
using namespace std;
#define ll long long
ll dp[10000005][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, mod = 1e9 + 7;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		dp[1][0] = 1; dp[1][1] = 1;
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = (4 * dp[i - 1][0] + dp[i - 1][1]) % mod;
			dp[i][1] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % mod;
		}
		cout << (dp[n][0] + dp[n][1]) % mod << '\n';
	}
}