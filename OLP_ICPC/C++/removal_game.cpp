#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	ll sum = 0;
	for (int& v : x) {
		cin >> v;
		sum += v;
	}
	vector<vector<ll>> dp(n, vector<ll>(n));
	for (int l = n - 1; l >= 0; --l)
		for (int r = l; r < n; ++r)
			if (l == r) dp[l][r] = x[l];
			else dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
	cout << (sum + dp[0][n - 1]) / 2;
}